#define true	1
#define false	0

class CfgPatches {
	class tmr_autorest {
		units[] = {};
		weapons[] = {"TMR_acc_bipod"};
		requiredVersion = 0.60;
		requiredAddons[] = {"A3_Weapons_F", "A3_Data_F", "A3_Characters_F", "A3_UI_F", tmr_core}; // asdg_jointrails
		version = 0.1;
		author[] = {"Taosenai"};
		authorUrl = "http://www.ryanschultz.org/tmr/";
	};
};

class Extended_PostInit_EventHandlers {
	class tmr_autorest {
		clientInit = "call compile preProcessFileLineNumbers '\tmr_autorest\init.sqf'";
		disableModuload = true;
	};
};

class CfgVehicles {
	class EAST_Box_Base;
	class Box_EAST_Support_F: EAST_Box_Base {
		class TransportItems {
			class _xx_TMR_acc_bipod {
				count = 2;
				name = "TMR_acc_bipod";
			};
		};
	};

	class NATO_Box_Base;
	class Box_NATO_Support_F: NATO_Box_Base {
		class TransportItems {
			class _xx_TMR_acc_bipod {
				count = 2;
				name = "TMR_acc_bipod";
			};
		};
	};

	class IND_Box_Base;
	class Box_IND_Support_F: IND_Box_Base {
		class TransportItems {
			class _xx_TMR_acc_bipod {
				count = 2;
				name = "TMR_acc_bipod";
			};
		};
	};
};

#define TMR_SWAY_DEPLOY 0.065
#define TMR_SWAY_DEPLOYPRONE 0.032
#define TMR_SWAY_RESTED 0.27
#define TMR_SWAY_RESTEDPRONE 0.07
#define TMR_DEPLOY_TURNSPEED 0.1

// Arma 3 doesn't respect turnSpeed.

class CfgMovesBasic {
	class Default;

	class Actions {
		class RifleStandActions;
		class RifleStandActions_tmr_deploy : RifleStandActions {
			stop =    "AmovPercMstpSrasWrflDnon_tmr_deploy";
			default = "AmovPercMstpSrasWrflDnon_tmr_deploy";
			turnL = "AmovPercMstpSrasWrflDnon_tmr_deploy";
			turnR = "AmovPercMstpSrasWrflDnon_tmr_deploy";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustLStandActions;
		class RifleAdjustLStandActions_tmr_deploy : RifleAdjustLStandActions {
			stop =    "AadjPercMstpSrasWrflDleft_tmr_deploy";
			default = "AadjPercMstpSrasWrflDleft_tmr_deploy";
			AdjustL = "AadjPercMstpSrasWrflDleft_tmr_deploy";
			turnL = "AadjPercMstpSrasWrflDleft_tmr_deploy";
			turnR = "AadjPercMstpSrasWrflDleft_tmr_deploy";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustRStandActions;
		class RifleAdjustRStandActions_tmr_deploy : RifleAdjustRStandActions {
			stop =    "AadjPercMstpSrasWrflDright_tmr_deploy";
			default = "AadjPercMstpSrasWrflDright_tmr_deploy";
			AdjustRight = "AadjPercMstpSrasWrflDright_tmr_deploy";
			turnL = "AadjPercMstpSrasWrflDright_tmr_deploy";
			turnR = "AadjPercMstpSrasWrflDright_tmr_deploy";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustFStandActions;
		class RifleAdjustFStandActions_tmr_deploy : RifleAdjustFStandActions {
			stop =    "AadjPercMstpSrasWrflDup_tmr_deploy";
			default = "AadjPercMstpSrasWrflDup_tmr_deploy";
			AdjustF = "AadjPercMstpSrasWrflDup_tmr_deploy";
			turnL = "AadjPercMstpSrasWrflDup_tmr_deploy";
			turnR = "AadjPercMstpSrasWrflDup_tmr_deploy";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustBStandActions;
		class RifleAdjustBStandActions_tmr_deploy : RifleAdjustBStandActions {
			stop =    "AadjPercMstpSrasWrflDdown_tmr_deploy";
			default = "AadjPercMstpSrasWrflDdown_tmr_deploy";
			AdjustB = "AadjPercMstpSrasWrflDdown_tmr_deploy";
			turnR = "AadjPercMstpSrasWrflDdown_tmr_deploy";
			turnL = "AadjPercMstpSrasWrflDdown_tmr_deploy";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustLKneelActions;
		class RifleAdjustLKneelActions_tmr_deploy : RifleAdjustLKneelActions {
			stop =    "AadjPknlMstpSrasWrflDleft_tmr_deploy";
			default = "AadjPknlMstpSrasWrflDleft_tmr_deploy";
			turnL = "AadjPknlMstpSrasWrflDleft_tmr_deploy";
			turnR = "AadjPknlMstpSrasWrflDleft_tmr_deploy";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustRKneelActions;
		class RifleAdjustRKneelActions_tmr_deploy : RifleAdjustRKneelActions {
			stop =    "AadjPknlMstpSrasWrflDright_tmr_deploy";
			default = "AadjPknlMstpSrasWrflDright_tmr_deploy";
			turnL = "AadjPknlMstpSrasWrflDright_tmr_deploy";
			turnR = "AadjPknlMstpSrasWrflDright_tmr_deploy";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustFKneelActions;
		class RifleAdjustFKneelActions_tmr_deploy : RifleAdjustFKneelActions {
			stop =    "AadjPknlMstpSrasWrflDup_tmr_deploy";
			default = "AadjPknlMstpSrasWrflDup_tmr_deploy";
			turnL = "AadjPknlMstpSrasWrflDup_tmr_deploy";
			turnR = "AadjPknlMstpSrasWrflDup_tmr_deploy";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustBKneelActions;
		class RifleAdjustBKneelActions_tmr_deploy : RifleAdjustBKneelActions {
			stop =    "AadjPknlMstpSrasWrflDdown_tmr_deploy";
			default = "AadjPknlMstpSrasWrflDdown_tmr_deploy";
			turnL = "AadjPknlMstpSrasWrflDdown_tmr_deploy";
			turnR = "AadjPknlMstpSrasWrflDdown_tmr_deploy";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleKneelActions;
		class RifleKneelActions_tmr_deploy : RifleKneelActions {
			stop = "AmovPknlMstpSrasWrflDnon_tmr_deploy";
			default = "AmovPknlMstpSrasWrflDnon_tmr_deploy";
			crouch = "AmovPknlMstpSrasWrflDnon_tmr_deploy";
			turnL = "AmovPknlMstpSrasWrflDnon_tmr_deploy";
			turnR = "AmovPknlMstpSrasWrflDnon_tmr_deploy";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleProneActions;
		class RifleProneActions_tmr_deploy : RifleProneActions {
			stop = "AmovPpneMstpSrasWrflDnon_tmr_deploy";
			default = "AmovPpneMstpSrasWrflDnon_tmr_deploy";
			turnL = "AmovPpneMstpSrasWrflDnon_tmr_deploy";
			turnR = "AmovPpneMstpSrasWrflDnon_tmr_deploy";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustFProneActions;
		class RifleAdjustFProneActions_tmr_deploy : RifleAdjustFProneActions {
			stop = "aadjppnemstpsraswrfldup_tmr_deploy";
			default = "aadjppnemstpsraswrfldup_tmr_deploy";
			turnL = "aadjppnemstpsraswrfldup_tmr_deploy";
			turnR = "aadjppnemstpsraswrfldup_tmr_deploy";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		//////////////////////////////////////////////////////////////////////

		class RifleStandActions_tmr_rested : RifleStandActions {
			stop =    "AmovPercMstpSrasWrflDnon_tmr_rested";
			default = "AmovPercMstpSrasWrflDnon_tmr_rested";
			turnL = "AmovPercMstpSrasWrflDnon_tmr_rested";
			turnR = "AmovPercMstpSrasWrflDnon_tmr_rested";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustLStandActions_tmr_rested : RifleAdjustLStandActions {
			stop =    "AadjPercMstpSrasWrflDleft_tmr_rested";
			default = "AadjPercMstpSrasWrflDleft_tmr_rested";
			AdjustL = "AadjPercMstpSrasWrflDleft_tmr_rested";
			turnL = "AadjPercMstpSrasWrflDleft_tmr_rested";
			turnR = "AadjPercMstpSrasWrflDleft_tmr_rested";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustRStandActions_tmr_rested : RifleAdjustRStandActions {
			stop =    "AadjPercMstpSrasWrflDright_tmr_rested";
			default = "AadjPercMstpSrasWrflDright_tmr_rested";
			AdjustRight = "AadjPercMstpSrasWrflDright_tmr_rested";
			turnL = "AadjPercMstpSrasWrflDright_tmr_rested";
			turnR = "AadjPercMstpSrasWrflDright_tmr_rested";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustFStandActions_tmr_rested : RifleAdjustFStandActions {
			stop =    "AadjPercMstpSrasWrflDup_tmr_rested";
			default = "AadjPercMstpSrasWrflDup_tmr_rested";
			AdjustF = "AadjPercMstpSrasWrflDup_tmr_rested";
			turnL = "AadjPercMstpSrasWrflDup_tmr_rested";
			turnR = "AadjPercMstpSrasWrflDup_tmr_rested";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustBStandActions_tmr_rested : RifleAdjustBStandActions {
			stop =    "AadjPercMstpSrasWrflDdown_tmr_rested";
			default = "AadjPercMstpSrasWrflDdown_tmr_rested";
			AdjustB = "AadjPercMstpSrasWrflDdown_tmr_rested";
			turnR = "AadjPercMstpSrasWrflDdown_tmr_rested";
			turnL = "AadjPercMstpSrasWrflDdown_tmr_rested";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustLKneelActions_tmr_rested : RifleAdjustLKneelActions {
			stop =    "AadjPknlMstpSrasWrflDleft_tmr_rested";
			default = "AadjPknlMstpSrasWrflDleft_tmr_rested";
			turnL = "AadjPknlMstpSrasWrflDleft_tmr_rested";
			turnR = "AadjPknlMstpSrasWrflDleft_tmr_rested";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustRKneelActions_tmr_rested : RifleAdjustRKneelActions {
			stop =    "AadjPknlMstpSrasWrflDright_tmr_rested";
			default = "AadjPknlMstpSrasWrflDright_tmr_rested";
			turnL = "AadjPknlMstpSrasWrflDright_tmr_rested";
			turnR = "AadjPknlMstpSrasWrflDright_tmr_rested";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustFKneelActions_tmr_rested : RifleAdjustFKneelActions {
			stop =    "AadjPknlMstpSrasWrflDup_tmr_rested";
			default = "AadjPknlMstpSrasWrflDup_tmr_rested";
			turnL = "AadjPknlMstpSrasWrflDup_tmr_rested";
			turnR = "AadjPknlMstpSrasWrflDup_tmr_rested";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustBKneelActions_tmr_rested : RifleAdjustBKneelActions {
			stop =    "AadjPknlMstpSrasWrflDdown_tmr_rested";
			default = "AadjPknlMstpSrasWrflDdown_tmr_rested";
			turnL = "AadjPknlMstpSrasWrflDdown_tmr_rested";
			turnR = "AadjPknlMstpSrasWrflDdown_tmr_rested";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleKneelActions_tmr_rested : RifleKneelActions {
			stop = "AmovPknlMstpSrasWrflDnon_tmr_rested";
			default = "AmovPknlMstpSrasWrflDnon_tmr_rested";
			crouch = "AmovPknlMstpSrasWrflDnon_tmr_rested";
			turnL = "AmovPknlMstpSrasWrflDnon_tmr_rested";
			turnR = "AmovPknlMstpSrasWrflDnon_tmr_rested";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleProneActions_tmr_rested : RifleProneActions {
			stop = "AmovPpneMstpSrasWrflDnon_tmr_rested";
			default = "AmovPpneMstpSrasWrflDnon_tmr_rested";
			turnL = "AmovPpneMstpSrasWrflDnon_tmr_rested";
			turnR = "AmovPpneMstpSrasWrflDnon_tmr_rested";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};

		class RifleAdjustFProneActions_tmr_rested : RifleAdjustFProneActions {
			stop = "aadjppnemstpsraswrfldup_tmr_rested";
			default = "aadjppnemstpsraswrfldup_tmr_rested";
			turnL = "aadjppnemstpsraswrfldup_tmr_rested";
			turnR = "aadjppnemstpsraswrfldup_tmr_rested";
			turnSpeed = TMR_DEPLOY_TURNSPEED;
			limitFast = 1;
		};
	};
};

class CfgMovesMaleSdr : CfgMovesBasic {	
	class States {
		class AmovPercMstpSrasWrflDnon;
		class AmovPercMstpSrasWrflDnon_tmr_deploy : AmovPercMstpSrasWrflDnon {
			aimPrecision = TMR_SWAY_DEPLOY;
			actions = "RifleStandActions_tmr_deploy";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"AmovPercMstpSrasWrflDnon_tmr_deploy", 0.02};
			ConnectFrom[] = {"AmovPercMstpSrasWrflDnon_tmr_deploy", 0.02};
			InterpolateFrom[] = {"AmovPercMstpSrasWrflDnon", 0.02};
			InterpolateTo[] = {"AmovPercMstpSrasWrflDnon", 0.02};
		};

		class aadjpercmstpsraswrfldup;
		class aadjpercmstpsraswrfldup_tmr_deploy : aadjpercmstpsraswrfldup {
			aimPrecision = TMR_SWAY_DEPLOY;
			actions = "RifleAdjustFStandActions_tmr_deploy";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjpercmstpsraswrfldup_tmr_deploy", 0.02};
			ConnectFrom[] = {"aadjpercmstpsraswrfldup_tmr_deploy", 0.02};
			InterpolateFrom[] = {"aadjpercmstpsraswrfldup", 0.02};
			InterpolateTo[] = {"aadjpercmstpsraswrfldup", 0.02};
		};

		class aadjpercmstpsraswrflddown;
		class aadjpercmstpsraswrflddown_tmr_deploy : aadjpercmstpsraswrflddown {
			aimPrecision = TMR_SWAY_DEPLOY;
			actions = "RifleAdjustBStandActions_tmr_deploy";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjpercmstpsraswrflddown_tmr_deploy", 0.02};
			ConnectFrom[] = {"aadjpercmstpsraswrflddown_tmr_deploy", 0.02};
			InterpolateFrom[] = {"aadjpercmstpsraswrflddown", 0.02};
			InterpolateTo[] = {"aadjpercmstpsraswrflddown", 0.02};
		};

		class aadjpercmstpsraswrfldright;
		class aadjpercmstpsraswrfldright_tmr_deploy : aadjpercmstpsraswrfldright {
			aimPrecision = TMR_SWAY_DEPLOY;
			actions = "RifleAdjustRStandActions_tmr_deploy";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjpercmstpsraswrfldright_tmr_deploy", 0.02};
			ConnectFrom[] = {"aadjpercmstpsraswrfldright_tmr_deploy", 0.02};
			InterpolateFrom[] = {"aadjpercmstpsraswrfldright", 0.02};
			InterpolateTo[] = {"aadjpercmstpsraswrfldright", 0.02};
		};

		class aadjpercmstpsraswrfldleft;
		class aadjpercmstpsraswrfldleft_tmr_deploy : aadjpercmstpsraswrfldleft {
			aimPrecision = TMR_SWAY_DEPLOY;
			actions = "RifleAdjustLStandActions_tmr_deploy";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjpercmstpsraswrfldleft_tmr_deploy", 0.02};
			ConnectFrom[] = {"aadjpercmstpsraswrfldleft_tmr_deploy", 0.02};
			InterpolateFrom[] = {"aadjpercmstpsraswrfldleft", 0.02};
			InterpolateTo[] = {"aadjpercmstpsraswrfldleft", 0.02};
		};

		class aadjpknlmstpsraswrfldup;
		class aadjpknlmstpsraswrfldup_tmr_deploy : aadjpknlmstpsraswrfldup {
			aimPrecision = TMR_SWAY_DEPLOY;
			actions = "RifleAdjustFKneelActions_tmr_deploy";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjpknlmstpsraswrfldup_tmr_deploy", 0.02};
			ConnectFrom[] = {"aadjpknlmstpsraswrfldup_tmr_deploy", 0.02};
			InterpolateFrom[] = {"aadjpknlmstpsraswrfldup", 0.02};
			InterpolateTo[] = {"aadjpknlmstpsraswrfldup", 0.02};
		};

		class amovpknlmstpsraswrfldnon;
		class amovpknlmstpsraswrfldnon_tmr_deploy : amovpknlmstpsraswrfldnon {
			aimPrecision = TMR_SWAY_DEPLOY;
			actions = "RifleKneelActions_tmr_deploy";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"amovpknlmstpsraswrfldnon_tmr_deploy", 0.02};
			ConnectFrom[] = {"amovpknlmstpsraswrfldnon_tmr_deploy", 0.02};
			InterpolateFrom[] = {"amovpknlmstpsraswrfldnon", 0.02};
			InterpolateTo[] = {"amovpknlmstpsraswrfldnon", 0.02};
		};

		class aadjpknlmstpsraswrflddown;
		class aadjpknlmstpsraswrflddown_tmr_deploy : aadjpknlmstpsraswrflddown {
			aimPrecision = TMR_SWAY_DEPLOY;
			actions = "RifleAdjustBKneelActions_tmr_deploy";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjpknlmstpsraswrflddown_tmr_deploy", 0.02};
			ConnectFrom[] = {"aadjpknlmstpsraswrflddown_tmr_deploy", 0.02};
			InterpolateFrom[] = {"aaadjpknlmstpsraswrflddown", 0.02};
			InterpolateTo[] = {"aadjpknlmstpsraswrflddown", 0.02};
		};

		class aadjpknlmstpsraswrfldleft;
		class aadjpknlmstpsraswrfldleft_tmr_deploy : aadjpknlmstpsraswrfldleft {
			aimPrecision = TMR_SWAY_DEPLOY;
			actions = "RifleAdjustLKneelActions_tmr_deploy";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjpknlmstpsraswrfldleft_tmr_deploy", 0.02};
			ConnectFrom[] = {"aadjpknlmstpsraswrfldleft_tmr_deploy", 0.02};
			InterpolateFrom[] = {"aadjpknlmstpsraswrfldleft", 0.02};
			InterpolateTo[] = {"aadjpknlmstpsraswrfldleft", 0.02};
		};

		class aadjpknlmstpsraswrfldright;
		class aadjpknlmstpsraswrfldright_tmr_deploy : aadjpknlmstpsraswrfldright {
			aimPrecision = TMR_SWAY_DEPLOY;
			actions = "RifleAdjustRKneelActions_tmr_deploy";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjpknlmstpsraswrfldright_tmr_deploy", 0.02};
			ConnectFrom[] = {"aadjpknlmstpsraswrfldright_tmr_deploy", 0.02};
			InterpolateFrom[] = {"aadjpknlmstpsraswrfldright", 0.02};
			InterpolateTo[] = {"aadjpknlmstpsraswrfldright", 0.02};
		};

		class aadjppnemstpsraswrfldup;
		class aadjppnemstpsraswrfldup_tmr_deploy : aadjppnemstpsraswrfldup {
			aimPrecision = TMR_SWAY_DEPLOYPRONE;
			actions = "RifleAdjustFProneActions_tmr_deploy";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjppnemstpsraswrfldup_tmr_deploy", 0.02};
			ConnectFrom[] = {"aadjppnemstpsraswrfldup_tmr_deploy", 0.02};
			InterpolateFrom[] = {"aadjppnemstpsraswrfldup", 0.02};
			InterpolateTo[] = {"aadjppnemstpsraswrfldup", 0.02};
		};

		class amovppnemstpsraswrfldnon;
		class amovppnemstpsraswrfldnon_tmr_deploy : amovppnemstpsraswrfldnon {
			aimPrecision = TMR_SWAY_DEPLOYPRONE;
			actions = "RifleProneActions_tmr_deploy";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"amovppnemstpsraswrfldnon_tmr_deploy", 0.02};
			ConnectFrom[] = {"amovppnemstpsraswrfldnon_tmr_deploy", 0.02};
			InterpolateFrom[] = {"amovppnemstpsraswrfldnon", 0.02};
			InterpolateTo[] = {"amovppnemstpsraswrfldnon", 0.02};
		};

		/////////////////////////////////////////////////////////////////////////////

				class AmovPercMstpSrasWrflDnon_tmr_rested : AmovPercMstpSrasWrflDnon {
			aimPrecision = TMR_SWAY_RESTED;
			actions = "RifleStandActions_tmr_rested";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"AmovPercMstpSrasWrflDnon_tmr_rested", 0.02};
			ConnectFrom[] = {"AmovPercMstpSrasWrflDnon_tmr_rested", 0.02};
			InterpolateFrom[] = {"AmovPercMstpSrasWrflDnon", 0.02};
			InterpolateTo[] = {"AmovPercMstpSrasWrflDnon", 0.02};
		};

		class aadjpercmstpsraswrfldup_tmr_rested : aadjpercmstpsraswrfldup {
			aimPrecision = TMR_SWAY_RESTED;
			actions = "RifleAdjustFStandActions_tmr_rested";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjpercmstpsraswrfldup_tmr_rested", 0.02};
			ConnectFrom[] = {"aadjpercmstpsraswrfldup_tmr_rested", 0.02};
			InterpolateFrom[] = {"aadjpercmstpsraswrfldup", 0.02};
			InterpolateTo[] = {"aadjpercmstpsraswrfldup", 0.02};
		};

		class aadjpercmstpsraswrflddown_tmr_rested : aadjpercmstpsraswrflddown {
			aimPrecision = TMR_SWAY_RESTED;
			actions = "RifleAdjustBStandActions_tmr_rested";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjpercmstpsraswrflddown_tmr_rested", 0.02};
			ConnectFrom[] = {"aadjpercmstpsraswrflddown_tmr_rested", 0.02};
			InterpolateFrom[] = {"aadjpercmstpsraswrflddown", 0.02};
			InterpolateTo[] = {"aadjpercmstpsraswrflddown", 0.02};
		};

		class aadjpercmstpsraswrfldright_tmr_rested : aadjpercmstpsraswrfldright {
			aimPrecision = TMR_SWAY_RESTED;
			actions = "RifleAdjustRStandActions_tmr_rested";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjpercmstpsraswrfldright_tmr_rested", 0.02};
			ConnectFrom[] = {"aadjpercmstpsraswrfldright_tmr_rested", 0.02};
			InterpolateFrom[] = {"aadjpercmstpsraswrfldright", 0.02};
			InterpolateTo[] = {"aadjpercmstpsraswrfldright", 0.02};
		};

		class aadjpercmstpsraswrfldleft_tmr_rested : aadjpercmstpsraswrfldleft {
			aimPrecision = TMR_SWAY_RESTED;
			actions = "RifleAdjustLStandActions_tmr_rested";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjpercmstpsraswrfldleft_tmr_rested", 0.02};
			ConnectFrom[] = {"aadjpercmstpsraswrfldleft_tmr_rested", 0.02};
			InterpolateFrom[] = {"aadjpercmstpsraswrfldleft", 0.02};
			InterpolateTo[] = {"aadjpercmstpsraswrfldleft", 0.02};
		};

		class aadjpknlmstpsraswrfldup_tmr_rested : aadjpknlmstpsraswrfldup {
			aimPrecision = TMR_SWAY_RESTED;
			actions = "RifleAdjustFKneelActions_tmr_rested";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjpknlmstpsraswrfldup_tmr_rested", 0.02};
			ConnectFrom[] = {"aadjpknlmstpsraswrfldup_tmr_rested", 0.02};
			InterpolateFrom[] = {"aadjpknlmstpsraswrfldup", 0.02};
			InterpolateTo[] = {"aadjpknlmstpsraswrfldup", 0.02};
		};

		class amovpknlmstpsraswrfldnon_tmr_rested : amovpknlmstpsraswrfldnon {
			aimPrecision = TMR_SWAY_RESTED;
			actions = "RifleKneelActions_tmr_rested";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"amovpknlmstpsraswrfldnon_tmr_rested", 0.02};
			ConnectFrom[] = {"amovpknlmstpsraswrfldnon_tmr_rested", 0.02};
			InterpolateFrom[] = {"amovpknlmstpsraswrfldnon", 0.02};
			InterpolateTo[] = {"amovpknlmstpsraswrfldnon", 0.02};
		};

		class aadjpknlmstpsraswrflddown_tmr_rested : aadjpknlmstpsraswrflddown {
			aimPrecision = TMR_SWAY_RESTED;
			actions = "RifleAdjustBKneelActions_tmr_rested";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjpknlmstpsraswrflddown_tmr_rested", 0.02};
			ConnectFrom[] = {"aadjpknlmstpsraswrflddown_tmr_rested", 0.02};
			InterpolateFrom[] = {"aaadjpknlmstpsraswrflddown", 0.02};
			InterpolateTo[] = {"aadjpknlmstpsraswrflddown", 0.02};
		};

		class aadjpknlmstpsraswrfldleft_tmr_rested : aadjpknlmstpsraswrfldleft {
			aimPrecision = TMR_SWAY_RESTED;
			actions = "RifleAdjustLKneelActions_tmr_rested";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjpknlmstpsraswrfldleft_tmr_rested", 0.02};
			ConnectFrom[] = {"aadjpknlmstpsraswrfldleft_tmr_rested", 0.02};
			InterpolateFrom[] = {"aadjpknlmstpsraswrfldleft", 0.02};
			InterpolateTo[] = {"aadjpknlmstpsraswrfldleft", 0.02};
		};

		class aadjpknlmstpsraswrfldright_tmr_rested : aadjpknlmstpsraswrfldright {
			aimPrecision = TMR_SWAY_RESTED;
			actions = "RifleAdjustRKneelActions_tmr_rested";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjpknlmstpsraswrfldright_tmr_rested", 0.02};
			ConnectFrom[] = {"aadjpknlmstpsraswrfldright_tmr_rested", 0.02};
			InterpolateFrom[] = {"aadjpknlmstpsraswrfldright", 0.02};
			InterpolateTo[] = {"aadjpknlmstpsraswrfldright", 0.02};
		};

		class aadjppnemstpsraswrfldup_tmr_rested : aadjppnemstpsraswrfldup {
			aimPrecision = TMR_SWAY_RESTEDPRONE;
			actions = "RifleAdjustFProneActions_tmr_rested";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"aadjppnemstpsraswrfldup_tmr_rested", 0.02};
			ConnectFrom[] = {"aadjppnemstpsraswrfldup_tmr_rested", 0.02};
			InterpolateFrom[] = {"aadjppnemstpsraswrfldup", 0.02};
			InterpolateTo[] = {"aadjppnemstpsraswrfldup", 0.02};
		};

		class amovppnemstpsraswrfldnon_tmr_rested : amovppnemstpsraswrfldnon {
			aimPrecision = TMR_SWAY_RESTEDPRONE;
			actions = "RifleProneActions_tmr_rested";
			aiming = "aimingLying";
			speed = 0.01;
			onLandEnd = true;
			onLandBeg = true;

			ConnectTo[] = {"amovppnemstpsraswrfldnon_tmr_rested", 0.02};
			ConnectFrom[] = {"amovppnemstpsraswrfldnon_tmr_rested", 0.02};
			InterpolateFrom[] = {"amovppnemstpsraswrfldnon", 0.02};
			InterpolateTo[] = {"amovppnemstpsraswrfldnon", 0.02};
		};
	};
};

class Mode_SemiAuto;
class Mode_FullAuto;

// Bipod config.
// Add bipod accessory to all weapons config.
// !! Only works if ASDG_JointRails is available !!
// For weapons with a bipod in the 3D model:
// Add     tmr_autorest_deployable = 1;

class asdg_SlotInfo;

class asdg_FrontSideRail : asdg_SlotInfo {
	class compatibleItems {
		TMR_acc_bipod = 1;
	};
};

class CfgWeapons {
	class Rifle;
	class Rifle_Base_F : Rifle {
		class WeaponSlotsInfo;
	};
	
	class Rifle_Long_Base_F;

	class ItemCore;
	class InventoryItem_Base_F;
	class InventoryMuzzleItem_Base_F;
	class InventoryFlashLightItem_Base_F;

	class TMR_acc_bipod : ItemCore {
		scope = 2;
		displayName = "Bipod";
		picture = "\tmr_autorest\data\gear_acc_bipod_ca.paa";
		model = "";

		descriptionUse = "Mount bipod";
		descriptionShort = "Rifle bipod suitable for most rail systems.";
		
		class ItemInfo : InventoryFlashLightItem_Base_F {
			mass = 8;
			
			class Pointer {};
			
			class FlashLight {};
		};
	};

	////////////////////////////////////////////////
	// Define this value for weapons with a pre-modeled bipod.
	// tmr_autorest_deployable = 1;
	////////////////////////////////////////////////

	class arifle_MX_Base_F : Rifle_Base_F {
		class WeaponSlotsInfo;
	};

	class arifle_MX_SW_F : arifle_MX_Base_F {
		tmr_autorest_deployable = 1;
	};

	class arifle_MXM_F : arifle_MX_Base_F {
		tmr_autorest_deployable = 1;
	};


	////////////////////////////////////////////////

	class LMG_Mk200_F : Rifle_Long_Base_F {
		tmr_autorest_deployable = 1;
	};

	class LMG_Zafir_F: Rifle_Long_Base_F {
		tmr_autorest_deployable = 1;
	};

	class LRR_base_F : Rifle_Long_Base_F {
		tmr_autorest_deployable = 1;
	};

	class GM6_base_F : Rifle_Long_Base_F {
		tmr_autorest_deployable = 1;
	};

	///////////////////////////////////////////////////
	// Disable the TMR bipod accessory for models with grenade launchers
	// or no forward rails.
	///////////////////////////////////////////////////

	// MX
	class arifle_MX_GL_F : arifle_MX_Base_F {
		class WeaponSlotsInfo : WeaponSlotsInfo {
			class asdg_FrontSideRail_MX : asdg_FrontSideRail {
				class compatibleItems : compatibleItems {
					TMR_acc_bipod = 0;
				};
			};
		};
	};

	class arifle_MXC_F : arifle_MX_Base_F {
		class WeaponSlotsInfo : WeaponSlotsInfo {
			class asdg_FrontSideRail_MX : asdg_FrontSideRail {
				class compatibleItems : compatibleItems {
					TMR_acc_bipod = 0;
				};
			};
		};
	};

	// Katiba
	class arifle_Katiba_Base_F : Rifle_Base_F {
		class WeaponSlotsInfo;
	};
	class arifle_Katiba_GL_F : arifle_Katiba_Base_F {
		class WeaponSlotsInfo : WeaponSlotsInfo {
			class asdg_FrontSideRail_Katiba : asdg_FrontSideRail {
				class compatibleItems : compatibleItems {
					TMR_acc_bipod = 0;
				};
			};
		};
	};
	class arifle_Katiba_C_F : arifle_Katiba_Base_F {
		class WeaponSlotsInfo : WeaponSlotsInfo {
			class asdg_FrontSideRail_Katiba : asdg_FrontSideRail {
				class compatibleItems : compatibleItems {
					TMR_acc_bipod = 0;
				};
			};
		};
	};

	// Tavor
	class Tavor_base_F;
	class arifle_TRG21_F : Tavor_base_F {
		class WeaponSlotsInfo;
	};

	class arifle_TRG21_GL_F : arifle_TRG21_F {
		class WeaponSlotsInfo : WeaponSlotsInfo {
			class asdg_FrontSideRail_Tavor : asdg_FrontSideRail {
				class compatibleItems : compatibleItems {
					TMR_acc_bipod = 0;
				};
			};
		};
	};

	// Mk20
	class mk20_base_F : Rifle_Base_F {
		class WeaponSlotsInfo;
	};
	class arifle_Mk20_GL_F : mk20_base_F {
		class WeaponSlotsInfo : WeaponSlotsInfo {
			class asdg_FrontSideRail_MK20 : asdg_FrontSideRail {
				class compatibleItems : compatibleItems {
					TMR_acc_bipod = 0;
				};
			};
		};
	};
};

class TMR_RscPicture {
   type = 0;
   style = 48;
   idc = -1;
   colorBackground[] = {1, 1, 1, 1};
   colorText[] = {1, 1, 1, 1};
   font = "PuristaMedium";
   size = 0;
   sizeEx = 1;
   lineSpacing = 1.0; 
};

#define ICON_WIDTH 0.09

class RscTitles {
	class TMR_Autorest_Rested {
		idd = -1;
		onLoad = "with uiNameSpace do { TMR_Autorest_Rested = _this select 0 };";
		onUnload = "";
		movingEnable = 1;
		duration = 10000;
		controls[] = {"TMR_Autorest_Icon"};

		class TMR_Autorest_Icon : TMR_RscPicture {
			idc = 1;
			movingEnable = 1;
			colorBackground[] = {0, 0, 0, 0};
			text = "\tmr_autorest\data\restedWeapon_ca.paa";
			colorText[] = {1,1,1,1};
			x = (SafeZoneX + SafeZoneW/2) - (ICON_WIDTH * 3/4)/2;
			y = SafeZoneY + (SafeZoneH * 0.75);
			w = ICON_WIDTH * 3/4;
			h = ICON_WIDTH;
		};
	};
	class TMR_Autorest_Deployed {
		idd = -1;
		onLoad = "with uiNameSpace do { TMR_Autorest_Deployed = _this select 0 };";
		onUnload = "";
		movingEnable = 1;
		duration = 10000;
		controls[] = {"TMR_Autorest_DeployedIcon"};

		class TMR_Autorest_DeployedIcon : TMR_RscPicture {
			idc = 1;
			movingEnable = 1;
			colorBackground[] = {0, 0, 0, 0};
			text = "\tmr_autorest\data\deployWeapon_ca.paa";
			colorText[] = {1,1,1,1};
			x = (SafeZoneX + SafeZoneW/2) - (ICON_WIDTH * 3/4)/2;
			y = SafeZoneY + (SafeZoneH * 0.75);
			w = ICON_WIDTH * 3/4;
			h = ICON_WIDTH;
		};
	};
};

class CfgSounds {
	class tmr_autorest_bipodOpen {
		name = "tmr_autorest_bipodOpen";
		sound[] = {"\tmr_autorest\data\tmr_autorest_bipodopen.wss", db-0, 1};
		titles[] = {};
	};
	class tmr_autorest_bipodClose {
		name = "tmr_autorest_bipodClose";
		sound[] = {"tmr_autorest\data\tmr_autorest_bipodclose.wss", db-0, 1};
		titles[] = {};
	};
	class tmr_autorest_hardrest {
		name = "tmr_autorest_hardrest";
		sound[] = {"tmr_autorest\data\tmr_autorest_hardrest.wss", db-0, 1};
		titles[] = {};
	};
};

// class CfgMissions {
// 	class Missions {
// 		class TMRTraining {
// 			class Autorest {
// 				briefingName = "Weapon Resting & Bipods";
// 				// It's critical that this not begin with '\' !!
// 				directory = "tmr_autorest\TMR_RestingTraining.Stratis";
// 			};
// 		};
// 	};
// };

// class CfgHints {
// 	class TMR {
// 		displayName = "TMR Tutorials";
// 		class AutorestInit {
// 			arguments[] = {};
// 			description = "TMR Autorest adds the ability for your weapons to rest on objects and allows you to deploy bipods on weapons which feature one.<br/><br/>Weapon resting happens automatically when your weapon is on an appropriate surface.<br/>%1%2Move up to wall ahead of you, crouch, and rest your weapon on the wall.<br/>";
// 			displayName = "Weapon Resting";
// 			image = "";
// 			tip = "";
// 		};
// 		class AutorestBipods {
// 			arguments[] = {};
// 			description = "The icon in the lower center of your screen indicates that the weapon is rested. Muzzle climb will be reduced when firing. Use stance adjustments to rest on a variety of surfaces and objects!<br/><br/>Some weapons may be equipped with a bipod. While prone or when on a surface where the bipod could be deployed, press the 'Rest/deploy weapon' key (default Tab) to deploy it. Check the Configure Addons page under Controls if you'd like to change this.";
// 			displayName = "Bipods";
// 			image = "";
// 			tip = "When prone, don't lift the bipod too far from the ground.<br/>";
// 		};
// 		class AutorestGoodWork {
// 			arguments[] = {};
// 			description = "Good work. You've mastered weapon resting!<br/><br/>You can leave the mission when you're ready.";
// 			displayName = "Good Work";
// 			image = "";
// 			tip = "Always rest your weapon when possible!<br/>";
// 		};
// 	};
// };


class CfgHints {
	class TMR {
		displayName = "TMR Info";
		class Autorest {
			arguments[] = {};
			description = "TMR Autorest adds the ability for your weapons to rest on objects and allows you to deploy bipods on weapons which feature one.<br/><br/>Weapon resting happens automatically when placed on an appropriate surface. An icon will appear in the lower center of your screen when the weapon is rested. Muzzle climb will be reduced when firing. Use stance adjustments to rest on a variety of surfaces and objects!<br/><br/>When the weapon is rested, you can press the 'Rest/deploy weapon' key to reduce aim sway. If your weapon is equipped with a bipod, this will also attempt to deploy it.<br/><br/>Note that a weapon can be rested on objects to its sides, but a bipod can only be deployed on surfaces under it.";
			displayName = "Weapon Resting";
			image = "\a3\ui_f\data\gui\cfg\hints\rifle_ca.paa";
			tip = "Click 'Configure Addons' in the Controls configuration dialog if you'd like to change the keybinding.<br/><br/>tmr_autorest.pbo";
		};
	};
};