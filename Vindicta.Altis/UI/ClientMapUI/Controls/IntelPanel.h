#include "..\..\Resources\UIProfileColors.h"
#include "..\ClientMapUI_Macros.h"

class CMUI_INTEL_LISTBOX_BG : MUI_BASE {

	IDC = -1;
	x = safeZoneX + safeZoneW * 0.763; 
	y = safeZoneY + safeZoneH * 0.098; 
	w = safeZoneW * 0.230; 
	h = safeZoneH * 0.353;  
	colorBackground[] = MUIC_BLACK;
	colorText[] = MUIC_TRANSPARENT;
    text = ""; 

};

class CMUI_INTEL_LISTBOX : MUI_LISTNBOX {

	IDC = -1; 
	x = safeZoneX + safeZoneW * 0.763; 
	y = safeZoneY + safeZoneH * 0.098; 
	w = safeZoneW * 0.230; 
	h = safeZoneH * 0.353; 
	colorBackground[] = MUIC_BLACK; 
	font = "PuristaSemibold";
	//columns[] = {0,0.2,0.8};
};

class CMUI_INTEL_HEADLINE : MUI_HEADLINE {

	IDC = -1; 
	x = safeZoneX + safeZoneW * 0.763; 
	y = safeZoneY + safeZoneH * 0.043; 
	w = safeZoneW * 0.230;
	text = "INTEL"; 
	colorText[] = MUIC_BLACK; 
	colorBackground[] = MUIC_MISSION; 
};

class CMUI_INTEL_ACTIVE : MUI_BUTTON_TXT_CHECKBOX_LIKE {

	IDC = -1; 
	x = safeZoneX + safeZoneW * 0.763; 
	y = safeZoneY + safeZoneH * 0.454; 
	w = safeZoneW * 0.230; 
	h = safeZoneH * 0.029;
	text = "SHOW ACTIVE ACTIONS"; 

};

class CMUI_INTEL_INACTIVE : MUI_BUTTON_TXT_CHECKBOX_LIKE {

	IDC = -1; 
	x = safeZoneX + safeZoneW * 0.763; 
	y = safeZoneY + safeZoneH * 0.485;  
	w = safeZoneW * 0.230; 
	h = safeZoneH * 0.029; 
	text = "SHOW INACTIVE ACTIONS"; 

};

class CMUI_INTEL_ENDED : MUI_BUTTON_TXT_CHECKBOX_LIKE {

	IDC = -1; 
	x = safeZoneX + safeZoneW * 0.763; 
	y = safeZoneY + safeZoneH * 0.515; 
	w = safeZoneW * 0.230; 
	h = safeZoneH * 0.029; 
	text = "SHOW ENDED ACTIONS"; 

};

class CMUI_BUTTON_NOTIF : MUI_BUTTON_TXT {

	IDC = -1; 
	x = safeZoneX + safeZoneW * 0.580; 
	y = safeZoneY + safeZoneH * 0.002; 
	w = safeZoneW * 0.118; 
	h = safeZoneH * 0.028; 
	text = "CLEAR NOTIFICATIONS"; 

};

class CMUI_BUTTON_INTELP : MUI_BUTTON_TXT_CHECKBOX_LIKE {

	IDC = -1; 
	x = safeZoneX + safeZoneW * 0.459; 
	y = safeZoneY + safeZoneH * 0.002; 
	w = safeZoneW * 0.118; 
	h = safeZoneH * 0.028; 
	text = "SHOW INTEL PANEL"; 

};

class CMUI_HINTS_BG : RscPicture {

	IDC = -1; 
	x = safeZoneX + safeZoneW * 0.184; 
	y = safeZoneY + safeZoneH * 0.043; 
	w = safeZoneW * 0.58; 
	h = safeZoneH * 0.026;
	text = "UI\Images\gradient_2way.paa";
	colorBackground[] = {0.2,0.2,0.2,0.6};
	colorText[] = {0.1, 0.1, 0.1, 1};

};

class CMUI_HINTS : MUI_BG_TRANSPARENT {

	IDC = -1; 
	x = safeZoneX + safeZoneW * 0.184; 
	y = safeZoneY + safeZoneH * 0.043; 
	w = safeZoneW * 0.58; 
	h = safeZoneH * 0.026;
	text = "testestest"; // Don't really need hints any more I think? 
	font = "RobotoCondensed";
};

class CMUI_BUTTON_LOC : MUI_BUTTON_TXT_CHECKBOX_LIKE {

	IDC = -1; 
	x = safeZoneX + safeZoneW * 0.338; 
	y = safeZoneY + safeZoneH * 0.002; 
	w = safeZoneW * 0.118; 
	h = safeZoneH * 0.028; 
	text = "SHOW LOCATIONS"; 

};

class CMUI_BUTTON_PLAYERS : MUI_BUTTON_TXT_CHECKBOX_LIKE {

	IDC = -1; 
	x = safeZoneX + safeZoneW * 0.218; 
	y = safeZoneY + safeZoneH * 0.002; 
	w = safeZoneW * 0.118; 
	h = safeZoneH * 0.028; 
	text = "SHOW PLAYERS"; 

};

class CMUI_BUTTON_RESPAWN : MUI_BUTTON_TXT 
{
    IDC = -1; 
    x = safeZoneX + safeZoneW * 0.353; 
    y = safeZoneY + safeZoneH * 0.822; 
    w = safeZoneW * 0.3; 
    h = safeZoneH * 0.065; 

	font = "PuristaLight";
    text = "RESPAWN"; 
	sizeEx = 0.06;
	shadow = 1;

	colorBackground[] = MUIC_BTN_GREEN;
	colorBackgroundActive[] = MUIC_WHITE;
	colorBackgroundDisabled[] = MUIC_BTN_RED;
};

class CMUI_STATIC_RESPAWN : MUI_BG_BLACKSOLID
{
	IDC = -1;
	x = safeZoneX + safeZoneW * 0.353; 
    y = safeZoneY + safeZoneH * 0.889; 
    w = safeZoneW * 0.3; 
    h = safeZoneH * 0.035; 
    text = "Respawn hint text";
    font = "RobotoCondensed";
};

class CMUI_INTEL_BTNGRP : MUI_GROUP {

	IDC = IDC_LOCP_LISTNBOX_BUTTONS_GROUP;
	x = safeZoneX + safeZoneW * 0.763; 
	y = safeZoneY + safeZoneH * 0.069; 
	w = safeZoneW * 0.230; 
	h = safeZoneH * 0.028; 

};


