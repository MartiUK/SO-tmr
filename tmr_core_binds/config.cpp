#define true	1
#define false	0

class CfgPatches {
	class tmr_core_binds {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.60;
		requiredAddons[] = {A3_UI_F, CBA_XEH, CBA_MAIN, tmr_core_configwriter};
		version = 0.1;
		author[] = {"Taosenai"};
		authorUrl = "http://www.ryanschultz.org/tmr/";
	};
};

class Extended_PreInit_EventHandlers {
	class tmr_core_binds {
		clientInit = "call compile preProcessFileLineNumbers '\tmr_core_binds\init.sqf'";
	};
};

// Import needed base classes.
class RscText;
class RscVignette;
class RscControlsGroup {
	class VScrollbar;
	class HScrollbar;
};
class RscControlsGroupNoScrollbars;
class RscFrame;
class RscTitle;
class RscButtonMenu;
class RscButtonMenuCancel;
class RscButtonMenuOK;
class RscCombo;
class RscListBox;
class RscListNBox;
class RscListBoxKeys;

//////////////////////////////////////////////////////////////////////////////////////////////////////

// ADD CONFIGURE ADDONS BUTTON TO DEFAULT CONTROLS DIALOG ////////////////////////////////////////////

class RscDisplayConfigure {
	onLoad = "[""onLoad"",_this,""RscDisplayConfigure"",'GUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""; _this call compile preprocessfilelinenumbers ""tmr_core_binds\gui\initDisplay.sqf""";
	
	class controls {
		class TMR_ButtonConfigureAddons : RscButtonMenuOK {
			idc = 4302;
			text = "Configure Addons";
			onButtonClick = "0 = _this spawn (uiNamespace getVariable 'tmr_core_binds_fnc_guiOnButtonClick')";
			x = "20.15 * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX)";
			y = "23 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + safezoneH - (((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "12.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};

		class TMR_AddonsGroup : RscControlsGroup {
			class VScrollbar : VScrollbar {
				width = 0;
			};
			class HScrollbar : HScrollbar {
				height = 0;
			};
			idc = 4301;
			enableDisplay = 0;
			x = "1 * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX)";
			y = "3.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + safezoneH - 			(((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * (((safezoneW / safezoneH) min 1.2) / 40)";
			h = "19.6 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";

			class controls {
				class TMR_AddonsEmptyText : RscText {
					idc = -1;
					type = 0;
					x = "0 * (((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "1 * (((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					text = "";
				};
				class TMR_AddonsEmptyBackground : RscText {
					idc = -1;
					type = 0;
					text = "";
					colorBackground[] = {0,0,0,0.4};
					x = "0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
					y = "3.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "25 * (((safezoneW / safezoneH) min 1.2) / 40)";
					h = "15.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class TMR_AddonsCA_ControlsPageText : RscText {
					sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
					style = 1;
					idc = 2002;
					text = "Addon:";
					x = "0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "4 * (((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class TMR_AddonsCA_ControlsPage : RscCombo {
					idc = 208;
					linespacing = 1;
					text = "";

					onLBSelChanged = "0 = _this spawn (uiNamespace getVariable 'tmr_core_binds_fnc_guiOnComboChanged')";

					wholeHeight = "12 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					x = "4.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "21 * (((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class TMR_AddonsCA_ValueKeys : RscListNBox {
					idc = 202;
					columns[] = {0,0.44};
					drawSideArrows = false;
					idcLeft = -1;
					idcRight = -1;

					onLBDblClick = "0 = _this spawn (uiNamespace getVariable 'tmr_core_binds_fnc_guiOnLBDblClick')";

					rowHeight = 0.050;
					x = "0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
					y = "3.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "25 * (((safezoneW / safezoneH) min 1.2) / 40)";
					h = "15.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class TMR_AddonsTextAction : RscText {
					idc = 2003;
					text = "$STR_A3_RscDisplayConfigure_TextAction";
					x = "0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "11 * (((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[] = {0,0,0,1};
				};
				class TMR_AddonsTextAssignedKeys : RscText {
					idc = 2004;
					text = "$STR_A3_RscDisplayConfigure_TextAssignedKeys";
					x = "11.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "14 * (((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[] = {0,0,0,1};
				};
			};
		};
	};
};