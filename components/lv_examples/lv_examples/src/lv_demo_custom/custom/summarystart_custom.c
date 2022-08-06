/*
 * summartstart_custom.c
 *
 *  Created on: 30-Jun-2022
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
void custom_summarystart_screen_setup(screen_id_e screenid){
	if(screenid == SCR_SUMMARY_START){
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.summary_start_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.summary_start_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	}else if(screenid == SCR_SUMMARY_START_BLUE){
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.summary_start_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.summary_start_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	}
}


void on_summarystart_back_buttonreleased(void)
{

}

void on_summarystart_startjob_buttonreleased(void){

}

/**
 * Function to Set summary start start date value
 * @param str  pointer to a summary start start date value label
 *
 */
void setter_summary_start_startdatevalue(char *str){
   lv_label_set_text(guider_ui.summary_start_startdatevalue, str);
}

/**
 * Function to Set summary start start duration value
 * @param str  pointer to a summary start start duration value label
 *
 */
void setter_summary_start_startdurationvalue(char *str){
   lv_label_set_text(guider_ui.summary_start_startdurationvalue, str);
}

/**
 * Function to Set summary start stop date value
 * @param str  pointer to a summary start stop date value label
 *
 */
void setter_summary_start_stopdatevalue(char *str){
   lv_label_set_text(guider_ui.summary_start_stopdatevalue, str);
}

/**
 * Function to Set summary start stop duration value
 * @param str  pointer to a summary start stop duration value label
 *
 */
void setter_summary_start_stopdurationvalue(char *str){
   lv_label_set_text(guider_ui.summary_start_stopdurationvalue, str);
}

/**
 * Function to Set summary start sample label
 * @param str  pointer to a summary start sample label
 *
 */
void setter_summary_start_samplelabel(char *str){
   lv_label_set_text(guider_ui.summary_start_samplelabel, str);
}

/**
 * Function to Set summary start flow set point value
 * @param val  value of a summary start flow set point value label
 *
 */
void setter_summary_start_flowsetpointvalue(int val){
    lv_label_set_text_fmt(guider_ui.summary_start_flowsetpointvalue, "%d L/Min", val);
}

/**
 * Function to Set summary start sequence number value
 * @param val  value of a summary start sequence number value label
 *
 */
void setter_summary_start_sequencenumbervalue(int val){
    lv_label_set_text_fmt(guider_ui.summary_start_sequencenumbervalue, "%d", val);
}

/**
 * Function to Set summary start duration value
 * @param val  value of a summary start duration value label
 *
 */
void setter_summary_start_durationvalue(int val){
    lv_label_set_text_fmt(guider_ui.summary_start_durationvalue, "%d H", val);
}

/**
 * Function to Set summary start start person name
 * @param str  pointer to a summary start start person name label
 *
 */
void setter_summary_start_startpersonvalue(char *str){
   lv_label_set_text(guider_ui.summary_start_startpersonvalue, str);
}

/**
 * Function to Set summary start liter counter value
 * @param val  value of a summary start liter counter value label
 *
 */
void setter_summary_start_litercountervalue(uint32_t val){
   lv_label_set_text_fmt(guider_ui.summary_start_litercountervalue, "%u L", val);
}

/**
 * Function to Set summary start hour counter value
 * @param val  value of a summary start hour counter value label
 *
 */
void setter_summary_start_hourcountervalue(uint32_t val){
   lv_label_set_text_fmt(guider_ui.summary_start_hourcountervalue, "%u L", val);
}
/******************************************************************************
 *      END OF FILE
 *****************************************************************************/
