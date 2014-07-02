// TMR: Small Arms - Recoil initialization and functions
// (C) 2013 Ryan Schultz. See LICENSE.

tmr_recoil = false;

// -------------------------------------------------------------------------------
// Fired EH for rifles.
// -------------------------------------------------------------------------------
tmr_smallarms_recoil_fnc_firedEH = {
	_unit = _this select 0;
	_weaponType = _this select 1;
	_ammoType = _this select 5;
	_round = _this select 6;

	if (!local _unit) exitwith {};
	if (!isPlayer _unit) exitwith {};
	if !(_unit == player) exitwith {};

	// Cam shake values for rifles and MGs
	if (_weaponType == primaryWeapon player) then {
		// Base camshake values.
		_basePower = 0.20;
		_baseTime = 0.19;
		_baseFreq = 13;

		// Modifiers.
		_powerMod = 0;
		_timeMod = 0;
		_freqMod = 0;

		_config = configFile >> "CfgWeapons" >> _weaponType;
		_powerMulti = getNumber (_config >> "tmr_smallarms_recoil_shakeMultiplier");

		// Reduce the camshake as the player drops into lower, supported stances.
		_detectStance = (player selectionPosition "Neck" select 2);
		if (_detectStance < 1.3) then {
			_powerMod = _powerMod - 0.10;
		};
		if (_detectStance < 0.7) then {
			_powerMod = _powerMod - 0.10;
		};

		// Reduce camshake if the player is rested (tmr_autorest).
		if (player getVariable ["tmr_autorest_rested", false] || player getVariable ["tmr_autorest_hardrested", false]) then {
			_powerMod = _powerMod - 0.13;
		};

		// Reduce camshake if the player is deployed (tmr_autorest).
		if (player getVariable ["tmr_autorest_deployed", false]) then {
			_powerMod = _powerMod - 0.21;
		};

		// Add cam shake. Make sure no values are negative.
		addcamshake [0 max (_basePower * _powerMulti + _powerMod), 0 max (_baseTime + _timeMod), 0 max (_baseFreq + _freqMod)];
	};

	// Track increasing dispersion with rate of fire
	_lastFired = _unit getVariable ["tmr_recoil_lastFired", time];
	_burst = _unit getVariable ["tmr_recoil_burst", 0];

	// Time between rounds
	
	if (time - _lastFired < 0.45) then {
		_burst = _burst + 1;
		_unit setVariable ["tmr_recoil_burst", _burst, false];

		// Start dispersing from this size of burst
		_startDisperse = 3;
		if (cameraView != "GUNNER") then { // Immediately begin to disperse when not using sights
			_startDisperse = 1;
		};

		if (_burst > _startDisperse) then { 
			_vel = velocity _round;
			_mag = _vel call BIS_fnc_magnitude;
			_vDir = vectorDir _round;

			// Convert bullet vector to angles (deg)
			_elevAngle = (_vDir select 0) atan2 (_vDir select 1);
			_travAngle = sqrt( (_vDir select 1)^2 + (_vDir select 0)^2 ) atan2 - (_vDir select 2);

			// Reset burst size for calcs
			_burst = _burst - _startDisperse;

			// Increase dispersion cap if player is not using sights
			_sightsBurst = 0;
			if (cameraView != "GUNNER") then {
				_sightsBurst = 30;
			};

			// Increase initial dispersion and cap if player is moving
			if (speed player > 0.5) then {
				_sightsBurst = 25;
				_burst = _burst + 15;
			};

			// Maximum possible dispersion (without _sightsBurst mod)
			_maxBurst = 50;

			// Decrease max dispersiion if the player is rested (tmr_autorest).
			if (player getVariable ["tmr_autorest_rested", false] || player getVariable ["tmr_autorest_hardrested", false]) then {
				_maxBurst = 25;
			};

			// Decrease max dispersion if the player is deployed (tmr_autorest).
			if (player getVariable ["tmr_autorest_deployed", false]) then {
				_maxBurst = 18;
			};

			// Cap the dispersion
			_burst = _burst + _sightsBurst;
			if (_burst > _maxBurst + _sightsBurst) then {
				_burst = _maxBurst + _sightsBurst;
			};

			// Add random variance
			_elevAngle = _elevAngle + ((_burst/300) - random (_burst/300)*2);
			_travAngle = _travAngle + ((_burst/260) - random (_burst/260)*2);

			// Calculate new vectors (math based on ace_sys_sightadjustment)
			_vDir = [sin(_travAngle) * sin(_elevAngle), sin(_travAngle) * cos(_elevAngle), -cos(_travAngle)];
			_vel = [(_vDir select 0) * _mag, (_vDir select 1) * _mag, (_vDir select 2) * _mag];

			// Bullet to correct orientations (needed for tracers)
			_x = _dir select 0;
			_y = _dir select 1;
			_z = _dir select 2;
			_upZ = sqrt (_x^2 + _y^2);
			_k = -_z / _upZ;
			_upX = _k * _x;
			_upY = _k * _y;

			_round setVectorDirAndUp [_vDir, [_upX,_upY,_upZ]];
			_round setVelocity _vel;
		};
	} else {
		// Long enough delay, reset burst
		if (_burst > 0) then {
			_unit setVariable ["tmr_recoil_burst", 0, false];
		};
	};

	_unit setVariable ["tmr_recoil_lastFired", time];
};

// Initialization complete.

tmr_recoil = true;