/*
 * metrology_settings_custom.c
 *
 *  Created on: 29-Jun-2022
 *      Author: SAGAR
 */
/******************************************************************************
 *      INCLUDES
 *****************************************************************************/
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "custom.h"
#include "../generated/gui_guider.h"

/******************************************************************************
 *      DEFINES
 *****************************************************************************/

/******************************************************************************
 *      TYPEDEF
 *****************************************************************************/

/******************************************************************************
 *      STATIC VARIABLES
 *****************************************************************************/

/******************************************************************************
 *      STATIC PROTOTYPE
 *****************************************************************************/

/******************************************************************************
 *      STATIC FUNCTIONS
 *****************************************************************************/

/******************************************************************************
 *      GLOBAL FUNCTIONS
 *****************************************************************************/
void custom_metrologysettings_screen_setup(screen_id_e screenid){
	switch(screenid){
	case SCR_METROLOGY_SETTINGS_FLOW:
		lv_label_set_text(guider_ui.title_label, "FLOW");
		lv_img_set_src(guider_ui.title_symbol, &fan_icon);
		lv_dropdown_set_options(guider_ui.metrology_settings_unitdropdown,
			                 "LPM\n"
			                 "LPH"
			                 );
		lv_dropdown_set_options(guider_ui.metrology_settings_lowerlimitdropdown,
							 "-10%\n"
							 "-20%"
							 );
		lv_dropdown_set_options(guider_ui.metrology_settings_higherlimitdropdown,
							 "10%\n"
							 "20%"
							 );
		break;
	case SCR_METROLOGY_SETTINGS_PRESSURE:
		lv_label_set_text(guider_ui.title_label, "External Pressure");
		lv_img_set_src(guider_ui.title_symbol, &temperature);
		lv_dropdown_set_options(guider_ui.metrology_settings_unitdropdown,
							 "hPA"
							 );
		lv_dropdown_set_options(guider_ui.metrology_settings_lowerlimitdropdown,
							 "-300\n"
							 "-400"
							 );
		lv_dropdown_set_options(guider_ui.metrology_settings_higherlimitdropdown,
							 "700\n"
							 "800"
							 );
		break;
	case SCR_METROLOGY_SETTINGS_TEMPERATURE:
		lv_label_set_text(guider_ui.title_label, "External Temperature");
		lv_img_set_src(guider_ui.title_symbol, &temperature);
		lv_dropdown_set_options(guider_ui.metrology_settings_unitdropdown,
							 "°C\n"
							 "°F"
							 );
		lv_dropdown_set_options(guider_ui.metrology_settings_lowerlimitdropdown,
							 "-10\n"
							 "-20"
							 );
		lv_dropdown_set_options(guider_ui.metrology_settings_higherlimitdropdown,
							 "40\n"
							 "50"
							 );
		break;
	case SCR_METROLOGY_SETTINGS_HUMIDITY:
		lv_label_set_text(guider_ui.title_label, "External Humidity");
		lv_img_set_src(guider_ui.title_symbol, &temperature);
		lv_dropdown_set_options(guider_ui.metrology_settings_unitdropdown,
							 "%\n"
							 ""
							 );
		lv_dropdown_set_options(guider_ui.metrology_settings_lowerlimitdropdown,
							 "0%\n"
							 "1%"
							 );
		lv_dropdown_set_options(guider_ui.metrology_settings_higherlimitdropdown,
							 "90%\n"
							 "100%"
							 );
		break;

	default:
		break;
	}
}

void on_metrologysettings_back_buttonreleased(void){

}

void on_metrologysettings_curved_valuechanged(void){

}


void on_metrologysettings_unit_valuechanged(void){

}


void on_metrologysettings_alertsetpoint_valuechanged(void){

}


void on_metrologysettings_lowerlimit_valuechanged(void){

}


void on_metrologysettings_higherlimit_valuechanged(void){

}

void on_metrologysettings_actoinswitch_valuechanged(void){


}


void on_metrologysettings_validadjust_btnreleased(void){

}

/**
 * Function to Set metrology setting curve dropdown value
 * @param num  index of a metrology setting curve dropdown
 *
 */
void setter_metrology_settings_curvedropdown(uint16_t num){
    lv_dropdown_set_selected(guider_ui.metrology_settings_curvedropdown, num);
}

/**
 * Function to Set metrology setting unit dropdown value
 * @param num  index of a metrology setting unit dropdown
 *
 */
 void setter_metrology_settings_unitdropdown(uint16_t num){
    lv_dropdown_set_selected(guider_ui.metrology_settings_unitdropdown, num);
}

/**
 * Function to Set metrology setting alert container switch status
 * @param switch_status  enable/disable metrology setting alert container switch status
 *
 */
void setter_metrology_settings_alertcontainerswitch(bool switch_status){
    if(switch_status)
        lv_obj_add_state(guider_ui.metrology_settings_alertcontainerswitch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(guider_ui.metrology_settings_alertcontainerswitch, LV_STATE_CHECKED);
}

/**
 * Function to Set metrology setting lower limit dropdown value
 * @param num  index of a metrology setting lower limit dropdown
 *
 */
void setter_metrology_settings_lowerlimitdropdown(uint16_t num){
    lv_dropdown_set_selected(guider_ui.metrology_settings_lowerlimitdropdown, num);
}

/**
 * Function to Set metrology setting higher limit dropdown value
 * @param num  index of a metrology setting higher limit dropdown
 *
 */
void setter_metrology_settings_higherlimitdropdown(uint16_t num){
    lv_dropdown_set_selected(guider_ui.metrology_settings_higherlimitdropdown, num);
}

/**
 * Function to Set metrology setting action switch status
 * @param switch_status  enable/disable metrology setting action switch status
 *
 */
void setter_metrology_settings_actionswitch(bool switch_status){
    if(switch_status)
        lv_obj_add_state(guider_ui.metrology_settings_actionswitch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(guider_ui.metrology_settings_actionswitch, LV_STATE_CHECKED);
}

/******************************************************************************
 *      END OF FILE
 *****************************************************************************/
