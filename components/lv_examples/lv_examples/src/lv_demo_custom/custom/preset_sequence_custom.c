/*
 * parameter_custom.c
 *
 *  Created on: 02-Jul-2022
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

void custom_presetsequence_screen_setup(screen_id_e screenid){
	if(screenid == SCR_PRESET_SEQUENCE){
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.preset_sequence_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.preset_sequence_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	}else if(screenid == SCR_PRESET_SEQUENCE_BLUE){
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.preset_sequence_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.preset_sequence_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	}
}


void on_preset_sequence_back_btnreleased(void){

}


void on_preset_sequence_calender_valuechanged(void){

}

void on_preset_sequence_starthour_valuechanged(void){

}

void on_preset_sequence_startminute_valuechanged(void){

}

void on_preset_sequence_durationhour_valuechanged(void){

}

void on_preset_sequence_durationminute_valuechanged(void){

}

void on_preset_sequence_setpoint_valuechanged(void){

}

void on_preset_sequence_valid_btnreleased(void){

}

void on_preset_sequence_add_btnreleased(void){

}

/**
 * Function to preset sequence calender date
 * @param year  year to be set
 * @param month  month to be set
 * @param day  date to be set
 *
 */
void setter_preset_sequence_calender_today_date(uint16_t year, uint8_t month, uint8_t day){
    lv_calendar_set_today_date(guider_ui.preset_sequence_calender, year, month, day);
}

/**
 * Function to preset sequence show today date
 * @param year  year to be set
 * @param month  month to be set
 *
 */
void setter_preset_sequence_calender_show_date(uint16_t year, uint8_t month){
    lv_calendar_set_showed_date(guider_ui.preset_sequence_calender, year, month);
}

/**
 * Function to Set preset sequence date select
 * @param str  pointer to a preset sequence date select label
 *
 */
void setter_preset_sequence_dateselectedlabel(char *str){
    lv_label_set_text(guider_ui.preset_sequence_dateselectedlabel, str);
}

/**
 * Function to Set preset sequence start hour roller
 * @param num  index of a preset sequence start hour roller
 *
 */
void setter_preset_sequence_starthourroller(uint16_t num){
    lv_roller_set_selected(guider_ui.preset_sequence_starthourroller, num, LV_ANIM_OFF);
}

/**
 * Function to Set preset sequence start minute roller
 * @param num  index of a preset sequence start minute roller
 *
 */
void setter_preset_sequence_startminuteroller(uint16_t num){
    lv_roller_set_selected(guider_ui.preset_sequence_startminuteroller, num, LV_ANIM_OFF);
}

/**
 * Function to Set preset sequence duration hour roller
 * @param num  index of a preset sequence duration hour roller
 *
 */
void setter_preset_sequence_durationhourroller(uint16_t num){
    lv_roller_set_selected(guider_ui.preset_sequence_durationhourroller, num, LV_ANIM_OFF);
}

/**
 * Function to Set preset sequence duration minute roller
 * @param num  index of a preset sequence duration minute roller
 *
 */
void setter_preset_sequence_durationminuteroller(uint16_t num){
    lv_roller_set_selected(guider_ui.preset_sequence_durationminuteroller, num, LV_ANIM_OFF);
}

/**
 * Function to Set preset sequence set point roller
 * @param num  index of a preset sequence set point roller
 *
 */
void setter_preset_sequence_setpointroller(uint16_t num){
    lv_roller_set_selected(guider_ui.preset_sequence_setpointroller, num, LV_ANIM_OFF);
}


/******************************************************************************
 *      END OF FILE
 *****************************************************************************/
