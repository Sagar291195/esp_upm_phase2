/*
 * preset_scenario_custom.c
 *
 *  Created on: 04-Jul-2022
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
void custom_presetscenario_screen_setup(screen_id_e screenid){
	if(screenid == SCR_PRESET_SCENARIO){
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.preset_scenario_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.preset_scenario_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	}else if(screenid == SCR_PRESET_SCENARIO_BLUE){
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.preset_scenario_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.preset_scenario_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	}
}

void on_preset_scenario_back_buttonreleased(void){

}

void on_preset_scenario_plus_buttonreleased(void){

}

void on_preset_scenario_valid_buttonreleased(void){

}

/**
 * Function to Set preset scenario start now Hvalue 0 value
 * @param str  pointer to a preset scenario start now Hvalue 0 value label
 *
 */
void setter_preset_scenario_startnowHvalue_0(char *str){
    lv_label_set_text(guider_ui.preset_scenario_startnowHvalue[0], str);
}

/**
 * Function to Set preset scenario start now Hvalue 1 value
 * @param str  pointer to a preset scenario start now Hvalue 1 value label
 *
 */
void setter_preset_scenario_startnowHvalue_1(char *str){
    lv_label_set_text(guider_ui.preset_scenario_startnowHvalue[1], str);
}

/**
 * Function to Set preset scenario start now Hvalue 2 value
 * @param str  pointer to a preset scenario start now Hvalue 2 value label
 *
 */
void setter_preset_scenario_startnowHvalue_2(char *str){
    lv_label_set_text(guider_ui.preset_scenario_startnowHvalue[2], str);
}

/**
 * Function to Set preset scenario start now LPMvalue 0 value
 * @param str  pointer to a preset scenario start now LPMvalue 0 value label
 *
 */
void setter_preset_scenario_startnowLPMvalue_0(char *str){
    lv_label_set_text(guider_ui.preset_scenario_startnowLPMvalue[0], str);
}

/**
 * Function to Set preset scenario start now LPMvalue 1 value
 * @param str  pointer to a preset scenario start now LPMvalue 1 value label
 *
 */
void setter_preset_scenario_startnowLPMvalue_1(char *str){
    lv_label_set_text(guider_ui.preset_scenario_startnowLPMvalue[1], str);
}

/**
 * Function to Set preset scenario start now LPMvalue 2 value
 * @param str  pointer to a preset scenario start now LPMvalue 2 value label
 *
 */
void setter_preset_scenario_startnowLPMvalue_2(char *str){
    lv_label_set_text(guider_ui.preset_scenario_startnowLPMvalue[2], str);
}

/**
 * Function to Set preset scenario start later Hvalue 0 value
 * @param str  pointer to a preset scenario start later Hvalue 0 value label
 *
 */
void setter_preset_scenario_startlaterHvalue_0(char *str){
    lv_label_set_text(guider_ui.preset_scenario_startlaterHvalue[0], str);
}

/**
 * Function to Set preset scenario start later Hvalue 1 value
 * @param str  pointer to a preset scenario start later Hvalue 1 value label
 *
 */
void setter_preset_scenario_startlaterHvalue_1(char *str){
    lv_label_set_text(guider_ui.preset_scenario_startlaterHvalue[1], str);
}

/**
 * Function to Set preset scenario start later Hvalue 2 value
 * @param str  pointer to a preset scenario start later Hvalue 2 value label
 *
 */
void setter_preset_scenario_startlaterHvalue_2(char *str){
    lv_label_set_text(guider_ui.preset_scenario_startlaterHvalue[2], str);
}

/**
 * Function to Set preset scenario start later LPMvalue 0 value
 * @param str  pointer to a preset scenario start later LPMvalue 0 value label
 *
 */
void setter_preset_scenario_startlaterLPMvalue_0(char *str){
    lv_label_set_text(guider_ui.preset_scenario_startlaterLPMvalue[0], str);
}

/**
 * Function to Set preset scenario start later LPMvalue 1 value
 * @param str  pointer to a preset scenario start later LPMvalue 1 value label
 *
 */
void setter_preset_scenario_startlaterLPMvalue_1(char *str){
    lv_label_set_text(guider_ui.preset_scenario_startlaterLPMvalue[1], str);
}

/**
 * Function to Set preset scenario start later LPMvalue 2 value
 * @param str  pointer to a preset scenario start later LPMvalue 2 value label
 *
 */
void setter_preset_scenario_startlaterLPMvalue_2(char *str){
    lv_label_set_text(guider_ui.preset_scenario_startlaterLPMvalue[2], str);
}
/******************************************************************************
 *      END OF FILE
 *****************************************************************************/
