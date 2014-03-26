#define true	1
#define false	0

class CfgPatches {
	class tmr_optics {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.60;
		requiredAddons[] = {A3_Weapons_F, A3_Weapons_F_beta, A3_Weapons_F_gamma, A3_Weapons_F_Acc, A3_Weapons_F_Beta_Acc, A3_Characters_F, tmr_core};
		version = 0.1;
		author[] = {"Taosenai"};
		authorUrl = "http://www.ryanschultz.org/tmr/";
	};
};

class CfgMods {
	class tmr_optics {
		dir = "tmr_optics";
		name = "TMR: Optics Module";
		picture = "";
		hidePicture = "true";
		hideName = "true";
		actionName = "Website";
		action = "http://www.ryanschultz.org/tmr/";
	};
};

class Extended_PostInit_EventHandlers {
	class tmr_optics {
		clientInit = "call compile preProcessFileLineNumbers '\tmr_optics\init.sqf'";
	};
};

class Extended_FiredBIS_EventHandlers {
	class CAManBase {
		class tmr_optics {
			clientFiredBIS = "_this call tmr_optics_fnc_scopeRecoil_firedEH;";
		};
	};
};

class CfgOpticsEffect {
	class TMR_OpticsRadBlur1 {
		type = "radialblur";
		params[] = {0.019, 0.019, 0.16, 0.70};
		priority = 950;
	};
};

class CfgWeapons {
	class ItemCore;
	class InventoryItem_Base_F;
	class InventoryMuzzleItem_Base_F;
	class InventoryOpticsItem_Base_F;

	class optic_Hamr : ItemCore {
		displayName = "HAMR 4x";
		descriptionShort = "High Accuracy Multi-Range Optic<br />Magnification: 4x<br />Reticle: CM-RW 6.5mm";
		scope = 2;
		weaponInfoType = "RscWeaponTMR";

		tmr_optics_enhanced = 1;
		tmr_optics_reticle = "\tmr_optics\data\hamr\hamr-reticle65_ca.paa";
		tmr_optics_reticleIllum = "\tmr_optics\data\hamr\hamr-reticle65Illum_ca.paa";
		tmr_optics_body = "\tmr_optics\data\hamr\hamr-body_ca.paa";
		tmr_optics_bodyNight = "\tmr_optics\data\hamr\hamr-bodyNight_ca.paa";

		model = "\A3\weapons_f\acc\acco_hamr_F";
		
		class ItemInfo : InventoryOpticsItem_Base_F {
			mass = 4;
			optics = 1;
			optictype = 1;
			rmbhint = "HAMR";

			class OpticsModes {	
				class Hamr2Collimator {
					tmr_optics_enhanced = 0;
					opticsID = 1;
					useModelOptics = 0;
					opticsPPEffects[] = {""};
					opticsFlare = false;
					opticsDisablePeripherialVision = false;
					opticsZoomMin = 0.375;
					opticsZoomMax = 1;
					opticsZoomInit = 0.75;
					memoryPointCamera = "eye";
					visionMode[] = {};
					distanceZoomMin = 300;
					distanceZoomMax = 300;
				};
				
				class Hamr2Scope {
					cameradir = "";
					distanceZoomMin = 300;
					distanceZoomMax = 300;
					memorypointcamera = "opticView";
					opticsdisableperipherialvision = 0;
					opticsdisplayname = "IHAMR";
					opticsflare = 1;
					opticsid = 2;
					opticsppeffects[] = {"OpticsCHAbera2", "OpticsBlur1", "TMR_OpticsRadBlur1"};
					opticszoominit = 0.0872664626;
					opticszoommax = 0.0872664626;
					opticszoommin = 0.0872664626;
					discretefov[] = {0.0872664626};
					discreteinitindex = 0;
					usemodeloptics = 1;
					modeloptics = "\tmr_optics\data\tmr_optics_reticle80.p3d";
					visionmode[] = {"Normal"};
				};
			};
		};
	};

	class optic_Arco : ItemCore {
		descriptionshort = "Advanced Rifle Combat Optic<br />Magnification: 4x<br />Reticle: SpecterDR 6.5mm";
		displayname = "ARCO 4x";
		picture = "\A3\weapons_F\Data\UI\gear_acco_Arco_CA.paa";
		scope = 2;
		weaponInfoType = "RscWeaponTMR";

		model = "\A3\weapons_f\acc\acco_Arco_F";

		tmr_optics_enhanced = 1;
		tmr_optics_reticle = "\tmr_optics\data\arco\arco-reticle65_ca.paa";
		tmr_optics_reticleIllum = "\tmr_optics\data\arco\arco-reticle65Illum_ca.paa";
		tmr_optics_body = "\tmr_optics\data\arco\arco-body_ca.paa";
		tmr_optics_bodyNight = "\tmr_optics\data\arco\arco-bodyNight_ca.paa";

		class ItemInfo: InventoryOpticsItem_Base_F {
			mass = 4;
			optics = 1;
			optictype = 1;
			rmbhint = "ARCO";

			class OpticsModes {
				class ARCO2collimator {
					tmr_optics_enhanced = 0;
					cameradir = "";
					distancezoommax = 300;
					distancezoommin = 300;
					memorypointcamera = "eye";
					opticsdisableperipherialvision = 0;
					opticsdisplayname = "CQB";
					opticsflare = 0;
					opticsid = 1;
					opticsppeffects[] = {""};
					opticszoominit = 0.75;
					opticszoommax = 1.1;
					opticszoommin = 0.375;
					usemodeloptics = 0;
					visionmode[] = {};
				};
				class ARCO2scope: ARCO2collimator {
					cameradir = "";
					distanceZoomMin = 300;
					distanceZoomMax = 300;
					memorypointcamera = "opticView";
					opticsdisableperipherialvision = 0;
					opticsdisplayname = "ARCO";
					opticsflare = 1;
					opticsid = 2;
					opticsppeffects[] = {"OpticsCHAbera2", "OpticsBlur1", "TMR_OpticsRadBlur1"};
					opticszoominit = 0.0872664626; // 0.0872664626 rad = 5 degrees
					opticszoommax = 0.0872664626; // SpecterDR 4x is 6 degrees
					opticszoommin = 0.0872664626; // Scope graphic in game covers 1 degree
					discretefov[] = {0.0872664626};
					discreteinitindex = 0;
					usemodeloptics = 1;
					modeloptics = "\tmr_optics\data\tmr_optics_reticle80.p3d";
					visionmode[] = {"Normal"};
				};
			};
		};
	};

	class optic_MRCO : ItemCore {
		displayName = "MRCO 1x/4x";
		descriptionShort = "Medium Range Combat Optic<br />Magnification: 1x/4x<br />Reticle: Pitbull Gen II 5.56mm";
		scope = 2;
		weaponInfoType = "RscWeaponTMR";

		tmr_optics_enhanced = 1;
		tmr_optics_reticle = "\tmr_optics\data\mrco\mrco-reticle556_ca.paa";
		tmr_optics_reticleIllum = "\tmr_optics\data\mrco\mrco-reticle556Illum_ca.paa";
		tmr_optics_body = "\tmr_optics\data\mrco\mrco-body_ca.paa";
		tmr_optics_bodyNight = "\tmr_optics\data\mrco\mrco-bodyNight_ca.paa";
		
		class ItemInfo : InventoryOpticsItem_Base_F {
			opticType = 1;
			mass = 4;
			optics = true;
			modelOptics = "\A3\Weapons_f_beta\acc\reticle_MRCO_F";

			class OpticsModes {
				class MRCOcq {
					tmr_optics_enhanced = 0;
					opticsID = 1;
					useModelOptics = 0;
					opticsPPEffects[] = {""};
					opticsFlare = false;
					opticsDisablePeripherialVision = false;
					opticsZoomMin = 0.375;
					opticsZoomMax = 1;
					opticsZoomInit = 0.75;
					memoryPointCamera = "eye";
					visionMode[] = {};
					distanceZoomMin = 100;
					distanceZoomMax = 100;
				};
				
				class MRCOscope {
					cameradir = "";
					distanceZoomMin = 300;
					distanceZoomMax = 300;
					memorypointcamera = "eye";
					opticsdisableperipherialvision = 0;
					opticsdisplayname = "MRCO";
					opticsflare = 1;
					opticsid = 2;
					opticsppeffects[] = {"OpticsCHAbera2", "OpticsBlur2", "TMR_OpticsRadBlur1"};
					opticszoominit = 0.0872664626;
					opticszoommax = 0.0872664626;
					opticszoommin = 0.0872664626;
					discretefov[] = {0.0872664626};
					discreteinitindex = 0;
					usemodeloptics = 1;
					modeloptics = "\tmr_optics\data\tmr_optics_reticle80.p3d";
					visionmode[] = {"Normal"};
				};
			};
		};
	};

	class optic_SOS: ItemCore {
		descriptionshort = "Sniper Optical Sight<br />Magnification: 5.5-22x";
		displayname = "SOS 5.5-22x";
		weaponinfotype = "RscWeaponTMR";

		tmr_optics_enhanced = 1;
		tmr_optics_reticle = "\tmr_optics\data\sos\sos-reticleMLR_ca.paa";
		tmr_optics_reticleIllum = "\tmr_optics\data\sos\sos-reticleMLRIllum_ca.paa";
		tmr_optics_body = "\tmr_optics\data\sos\sos-body_ca.paa";
		tmr_optics_bodyNight = "\tmr_optics\data\sos\sos-bodyNight_ca.paa";

		class ItemInfo: InventoryOpticsItem_Base_F {
			modeloptics = "\tmr_optics\data\tmr_optics_reticle80.p3d";
			weaponinfotype = "RscWeaponRangeZeroingFOV";
			opticType = 2; // Sniper optics

			class OpticsModes {
				// Based on Nightforce NXS 5.5-22 scope
				class Snip {
					cameradir = "";
					discretedistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300};
					discretedistanceinitindex = 0;
					discreteinitindex = 0;
					distancezoommax = 2300;
					distancezoommin = 100;
					memorypointcamera = "opticView";
					modeloptics = "\tmr_optics\data\tmr_optics_reticle80.p3d";
					opticsdisableperipherialvision = 1;
					opticsdisplayname = "SOS";
					opticsflare = 1;
					opticsid = 1;
					opticsppeffects[] = {"OpticsCHAbera1", "OpticsBlur1", "TMR_OpticsRadBlur1"};
					// How to determine opticszoom
					// First do the basic math based on the listed FOV of the scope to 
					// get a baseline FOV
					// 0.1 meter at 100 meters = 1 mrad
					//
					// 5.5x FOV -- 5.3 m at 100 m = 53 mrad
					// = 0.053 rad = 3.037 deg FOV

					// 22x FOV -- 1.4 m at 100m = 14 mrad
					// = 0.014 rad = 0.802 deg

					// The FOV you give the engine is based on a rather larger scope outline, so we
					// have to do this extra work ourselves.

					// At 1680x1050
					// The width of a TMR optic viewfield is 864px
					// The engine viewport width (which is what the below FOV is based on) is 980
					// (864/980) = (FOV to give engine / true FOV of optic)
					// 864/980 * 0.053 = 0.04673
					// 864/980 * 0.014 = 0.01234

					// Measured experimentally, these values seem quite right.
					// Certainly they're close enough after you account for pixel density, etc.

					opticszoominit = 0.01234; 
					opticszoommax = 0.04673;
					opticszoommin = 0.01234;
					discretefov[] = {};
					usemodeloptics = 1;
					visionmode[] = {"Normal"};
				};
				class Iron: Snip {
					discretefov[] = {};
					memorypointcamera = "eye";
					opticsdisableperipherialvision = 0;
					opticsdisplayname = "";
					opticsflare = 0;
					opticsid = 2;
					opticszoominit = 0.75;
					opticszoommax = 1.1;
					opticszoommin = 0.375;
					usemodeloptics = 0;
					visionmode[] = {};
					opticsppeffects[] = {};
				};
			};
		};
	};
};

class RscControlsGroup;
class RscOpticsText;
class RscOpticsValue;
class RscInGameUI {
	class RscUnitInfo;
	class RscWeaponZeroing;
	class RscWeaponTMR : RscWeaponZeroing {
		idd = -1;
		controls[] = {"CA_Zeroing",  "CA_FOVMode"};

		onLoad ="with uiNameSpace do { TMR_OpticsIGUI = _this select 0 }";
		
		class CA_FOVMode : RscOpticsValue {
			idc = 154;
			style = 2;
			colorText[] = {0, 0, 0, 0};
			x = 0;
			y = 0;
			w = 0;
			h = 0;
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

class RscTitles {
	class TMR_Optics_Scope {
		idd = -1;
		onLoad = "with uiNameSpace do { TMR_Optics_Scope = _this select 0 };";
		onUnload = "";
		movingEnable = 1;
		duration = 10000;
		controls[] = {"Reticle", "ReticleNight", "BodyNight", "Body"};

		class Reticle : TMR_RscPicture {
			idc = 1;
			movingEnable = 1;
			colorBackground[] = {0, 0, 0, 0};
			colorText[] = {1,1,1,1};
			fade = 0;
			text = "";
			x = (SafeZoneXAbs + SafeZoneWAbs/2 - (SafeZoneWAbs / ((getResolution select 0) / (getResolution select 1)))/2);
			y = SafeZoneY;
			w = SafeZoneWAbs / ((getResolution select 0) / (getResolution select 1));
			h = SafeZoneH;
		};

		class ReticleNight : Reticle {
			idc = 2;
			text = "";
		};

		class BodyNight : Reticle {
			idc = 5;
			text = "";
			x = (SafeZoneXAbs + SafeZoneWAbs/2 - (SafeZoneWAbs / ((getResolution select 0) / (getResolution select 1))));
			y = SafeZoneY - (SafeZoneH/2);
			w = SafeZoneWAbs / ((getResolution select 0) / (getResolution select 1)) * 2;
			h = SafeZoneH * 2;
		};

		class Body : BodyNight {
			idc = 6;
			text = "";
		};
	};
};

class PreloadTextures {
	class CfgWeapons {
		class optic_hamr {
			tmr_optics_body= "*";
			tmr_optics_bodyNight = "*";
			tmr_optics_reticle = "*";
			tmr_optics_reticleIllum = "*";
		};
		class optic_arco {
			tmr_optics_body= "*";
			tmr_optics_bodyNight = "*";
			tmr_optics_reticle = "*";
			tmr_optics_reticleIllum = "*";
		};
		class optic_mrco {
			tmr_optics_body= "*";
			tmr_optics_bodyNight = "*";
			tmr_optics_reticle = "*";
			tmr_optics_reticleIllum = "*";
		};
		class optic_SOS {
			tmr_optics_body= "*";
			tmr_optics_bodyNight = "*";
			tmr_optics_reticle = "*";
			tmr_optics_reticleIllum = "*";
		};
	};
};