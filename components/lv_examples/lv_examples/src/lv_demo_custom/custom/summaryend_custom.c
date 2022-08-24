/*
 * summaryend_custom.c
 *
 *  Created on: 01-Jul-2022
 *      Author: SAGAR
 */
/******************************************************************************
 *      INCLUDES
 *****************************************************************************/
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "custom.h"

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
void custom_summaryend_screen_setup(screen_id_e screenid){
	switch(screenid){
	case SCR_SUMMARY_END:
		lv_obj_add_flag(guider_ui.summaryend_previousnext_buttoncontainer, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.summaryend_sequencewidgetcontainer2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.title_symbol, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.title_label, "SUMMARY");
		lv_obj_align_to(guider_ui.summaryend_samplecontainer, guider_ui.title_container, LV_ALIGN_OUT_BOTTOM_LEFT, 10, 10);
		lv_obj_align_to(guider_ui.summaryend_horizantalline, guider_ui.summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
		lv_obj_align_to(guider_ui.summaryend_sequencewidgetcontainer1, guider_ui.summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.summaryend_sequencewidgetcontainer2, guider_ui.summaryend_sequencewidgetcontainer1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.summaryend_exportusb, guider_ui.summaryend_sequencewidgetcontainer2, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
		lv_obj_align_to(guider_ui.summaryend_quit, guider_ui.summaryend_sequencewidgetcontainer2, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 10);
		lv_obj_set_style_bg_color(guider_ui.summaryend_sequencewidgetcontainer1_button, ESPUPM_COLOR_RED, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.summaryend_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.summaryend_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;

	case SCR_SUMMARY_END_BLUE:
		lv_obj_add_flag(guider_ui.summaryend_previousnext_buttoncontainer, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.summaryend_sequencewidgetcontainer2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.title_symbol, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.title_label, "Metrology Summary");
		lv_obj_align_to(guider_ui.summaryend_samplecontainer, guider_ui.title_container, LV_ALIGN_OUT_BOTTOM_LEFT, 10, 10);
		lv_obj_align_to(guider_ui.summaryend_horizantalline, guider_ui.summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
		lv_obj_align_to(guider_ui.summaryend_sequencewidgetcontainer1, guider_ui.summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.summaryend_sequencewidgetcontainer2, guider_ui.summaryend_sequencewidgetcontainer1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.summaryend_exportusb, guider_ui.summaryend_sequencewidgetcontainer2, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
		lv_obj_align_to(guider_ui.summaryend_quit, guider_ui.summaryend_sequencewidgetcontainer2, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 10);
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.summaryend_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.summaryend_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;

	case SCR_SUMMARY_END_SINGLEWIDGET:
		lv_obj_add_flag(guider_ui.summaryend_previousnext_buttoncontainer, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.summaryend_sequencewidgetcontainer2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.title_symbol, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.title_label, "SUMMARY");
		lv_obj_align_to(guider_ui.summaryend_samplecontainer, guider_ui.title_container, LV_ALIGN_OUT_BOTTOM_LEFT, 10, 10);
		lv_obj_align_to(guider_ui.summaryend_horizantalline, guider_ui.summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
		lv_obj_align_to(guider_ui.summaryend_sequencewidgetcontainer1, guider_ui.summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.summaryend_exportusb, guider_ui.summaryend_sequencewidgetcontainer1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
		lv_obj_align_to(guider_ui.summaryend_quit, guider_ui.summaryend_sequencewidgetcontainer1, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 10);
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.summaryend_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.summaryend_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;

	case SCR_SUMMARY_END_SINGLEWIDGET_BLUE:
		lv_obj_add_flag(guider_ui.summaryend_previousnext_buttoncontainer, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.summaryend_sequencewidgetcontainer2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.title_symbol, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.title_label, "Metrology Summary");
		lv_obj_align_to(guider_ui.summaryend_samplecontainer, guider_ui.title_container, LV_ALIGN_OUT_BOTTOM_LEFT, 10, 10);
		lv_obj_align_to(guider_ui.summaryend_horizantalline, guider_ui.summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
		lv_obj_align_to(guider_ui.summaryend_sequencewidgetcontainer1, guider_ui.summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.summaryend_exportusb, guider_ui.summaryend_sequencewidgetcontainer1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
		lv_obj_align_to(guider_ui.summaryend_quit, guider_ui.summaryend_sequencewidgetcontainer1, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 10);
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.summaryend_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.summaryend_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;

	case SCR_SUMMARY_ARCHIV:
		lv_obj_clear_flag(guider_ui.summaryend_previousnext_buttoncontainer, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.summaryend_sequencewidgetcontainer2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.title_symbol, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.title_label, "ARCHIV");
		lv_obj_align_to(guider_ui.summaryend_samplecontainer, guider_ui.summaryend_previousnext_buttoncontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
		lv_obj_align_to(guider_ui.summaryend_horizantalline, guider_ui.summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
		lv_obj_align_to(guider_ui.summaryend_sequencewidgetcontainer1, guider_ui.summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.summaryend_sequencewidgetcontainer2, guider_ui.summaryend_sequencewidgetcontainer1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.summaryend_exportusb, guider_ui.summaryend_sequencewidgetcontainer2, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
		lv_obj_align_to(guider_ui.summaryend_quit, guider_ui.summaryend_sequencewidgetcontainer2, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 10);
		lv_obj_set_style_bg_color(guider_ui.summaryend_sequencewidgetcontainer1_button, ESPUPM_COLOR_RED, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.summaryend_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.summaryend_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;

	case SCR_SUMMARY_ARCHIV_BLUE:
		lv_obj_clear_flag(guider_ui.summaryend_previousnext_buttoncontainer, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.summaryend_sequencewidgetcontainer2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.title_symbol, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.title_label, "ARCHIV");
		lv_obj_align_to(guider_ui.summaryend_samplecontainer, guider_ui.summaryend_previousnext_buttoncontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
		lv_obj_align_to(guider_ui.summaryend_horizantalline, guider_ui.summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
		lv_obj_align_to(guider_ui.summaryend_sequencewidgetcontainer1, guider_ui.summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.summaryend_sequencewidgetcontainer2, guider_ui.summaryend_sequencewidgetcontainer1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.summaryend_exportusb, guider_ui.summaryend_sequencewidgetcontainer2, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
		lv_obj_align_to(guider_ui.summaryend_quit, guider_ui.summaryend_sequencewidgetcontainer2, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 10);
		lv_obj_set_style_bg_color(guider_ui.summaryend_sequencewidgetcontainer1_button, ESPUPM_COLOR_RED, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.summaryend_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.summaryend_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;

	case SCR_SUMMARY_ARCHIV_SINGLEWIDGET:
		lv_obj_clear_flag(guider_ui.summaryend_previousnext_buttoncontainer, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.summaryend_sequencewidgetcontainer2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.title_symbol, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.title_label, "ARCHIV");
		lv_obj_align_to(guider_ui.summaryend_samplecontainer, guider_ui.summaryend_previousnext_buttoncontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
		lv_obj_align_to(guider_ui.summaryend_horizantalline, guider_ui.summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
		lv_obj_align_to(guider_ui.summaryend_sequencewidgetcontainer1, guider_ui.summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.summaryend_exportusb, guider_ui.summaryend_sequencewidgetcontainer1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
		lv_obj_align_to(guider_ui.summaryend_quit, guider_ui.summaryend_sequencewidgetcontainer1, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 10);
		lv_obj_set_style_bg_color(guider_ui.summaryend_sequencewidgetcontainer1_button, ESPUPM_COLOR_RED, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.summaryend_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.summaryend_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;

	case SCR_SUMMARY_ARCHIV_SINGLEWIDGET_BLUE:
		lv_obj_clear_flag(guider_ui.summaryend_previousnext_buttoncontainer, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.summaryend_sequencewidgetcontainer2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.title_symbol, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.title_label, "ARCHIV");
		lv_obj_align_to(guider_ui.summaryend_samplecontainer, guider_ui.summaryend_previousnext_buttoncontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
		lv_obj_align_to(guider_ui.summaryend_horizantalline, guider_ui.summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
		lv_obj_align_to(guider_ui.summaryend_sequencewidgetcontainer1, guider_ui.summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.summaryend_exportusb, guider_ui.summaryend_sequencewidgetcontainer1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
		lv_obj_align_to(guider_ui.summaryend_quit, guider_ui.summaryend_sequencewidgetcontainer1, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 10);
		lv_obj_set_style_bg_color(guider_ui.summaryend_sequencewidgetcontainer1_button, ESPUPM_COLOR_RED, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.summaryend_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.summaryend_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;
	default:
		break;
	}
}
void on_summaryend_back_buttonreleased(void){

}

void on_summaryend_previous_buttonreleased(void){

}


void on_summaryend_next_buttonreleased(void){

}

void on_summaryend_exportusb_buttonreleased(void){

}

void on_summaryend_quit_buttonreleased(void){

}

void on_summaryend_sequencewidget1_buttonreleased(void){

}

void on_summaryend_sequencewidget2_buttonreleased(void){

}

/**
 * Function to Set summary end sample label
 * @param str  pointer to a summary end sample label
 *
 */
void setter_summaryend_samplelabel(char *str){
    lv_label_set_text(guider_ui.summaryend_samplelabel, str);
}

/**
 * Function to Set summary end date start label
 * @param str  pointer to a summary end date start label
 *
 */
void setter_summaryend_datestart(char *str){
    lv_label_set_text(guider_ui.summaryend_datestart, str);
}

/**
 * Function to Set summary end start duration
 * @param str  pointer to a summary end start duration
 *
 */
void setter_summaryend_startduration(char *str){
    lv_label_set_text(guider_ui.summaryend_startduration, str);
}

/**
 * Function to Set summary end container title label
 * @param str  pointer to a summary end container title label
 *
 */
void setter_summaryend_containertitle(char *str){
    lv_label_set_text(guider_ui.summaryend_containertitle, str);
}

/**
 * Function to Set summary end flow set point value
 * @param val  value of a summary end flow set point value
 *
 */
void setter_summaryend_flowsetpointvalue(int val){
    lv_label_set_text_fmt(guider_ui.summaryend_flowsetpointvalue, "%d L/Min", val);
}

/**
 * Function to Set summary end sequence number value
 * @param val  value of a summary end sequence number value
 *
 */
void setter_summaryend_sequencenumbervalue(int val){
    lv_label_set_text_fmt(guider_ui.summaryend_sequencenumbervalue, "%d", val);
}

/**
 * Function to Set summary end duration value
 * @param val  value of a summary end duration value
 *
 */
void setter_summaryend_durationvalue(int val){
    lv_label_set_text_fmt(guider_ui.summaryend_durationvalue, "%d h", val);
}

/**
 * Function to Set summary end start value
 * @param str  pointer to a summary end start value label
 *
 */
void setter_summaryend_startvalue(char *str){
    lv_label_set_text(guider_ui.summaryend_startvalue, str);
}

/**
 * Function to Set summary end endby value
 * @param str  pointer to a summary end endby value label
 *
 */
void setter_summaryend_endbyvalue(char *str){
    lv_label_set_text(guider_ui.summaryend_endbyvalue, str);
}

/**
 * Function to Set summary end start person value
 * @param str  pointer to a summary end start person label
 *
 */
void setter_summaryend_startpersonvalue(char *str){
    lv_label_set_text(guider_ui.summaryend_startpersonvalue, str);
}

/**
 * Function to Set summary end endperson value
 * @param str  pointer to a summary end endperson value label
 *
 */
void setter_summaryend_endpersonvalue(char *str){
    lv_label_set_text(guider_ui.summaryend_endpersonvalue, str);
}

/**
 * Function to Set summary end problem value
 * @param str  pointer to a summary end problem value label
 *
 */
void setter_summaryend_problemvalue(char *str){
    lv_label_set_text(guider_ui.summaryend_problemvalue, str);
}

/**
 * Function to Set summary end volume start value
 * @param val  value of a summary end volume start value label
 *
 */
void setter_summaryend_volumestartvalue(uint32_t val){
    lv_label_set_text_fmt(guider_ui.summaryend_volumestartvalue, "%u L", val);
}

/**
 * Function to Set summary end volume stop value
 * @param val  value of a summary end volume stop value label
 *
 */
void setter_summaryend_volumestopvalue(uint32_t val){
    lv_label_set_text_fmt(guider_ui.summaryend_volumestopvalue, "%u L", val);
}

/**
 * Function to Set summary end volume target value
 * @param val  value of a summary end volume target value label
 *
 */
void setter_summaryend_volumetargetvalue(uint32_t val){
    lv_label_set_text_fmt(guider_ui.summaryend_volumetargetvalue, "%u L", val);
}

/**
 * Function to Set summary end volume effective value
 * @param val  value of a summary end volume effective value label
 *
 */
void setter_summaryend_volumeeffectivevalue(uint32_t val){
    lv_label_set_text_fmt(guider_ui.summaryend_volumeeffectivevalue, "%u L", val);
}

/**
 * Function to Set summary end volume variation value
 * @param val  value of a summary end volume variation value label
 *
 */
void setter_summaryend_volumevariationvalue(float val){
	char data[20];
	memset(data, 0x00, sizeof(data));
	sprintf(data, "%f %%", val);
    lv_label_set_text(guider_ui.summaryend_volumevariationvalue, data);
}

/**
 * Function to Set summary end problem value
 * @param str  pointer to a summary end problem value label
 *
 */
void setter_summaryend_hourstartvalue(char *str){
    lv_label_set_text(guider_ui.summaryend_hourstartvalue, str);
}

/**
 * Function to Set summary end problem value
 * @param str  pointer to a summary end problem value label
 *
 */
void setter_summaryend_hourstopvalue(char *str){
    lv_label_set_text(guider_ui.summaryend_hourstopvalue, str);
}

/**
 * Function to Set summary end problem value
 * @param str  pointer to a summary end problem value label
 *
 */
void setter_summaryend_hourtargetvalue(char *str){
    lv_label_set_text(guider_ui.summaryend_hourtargetvalue, str);
}

/**
 * Function to Set summary end problem value
 * @param str  pointer to a summary end problem value label
 *
 */
void setter_summaryend_houreffectivevalue(char *str){
    lv_label_set_text(guider_ui.summaryend_houreffectivevalue, str);
}

/**
 * Function to Set summary end hour variation value
 * @param val  value of a summary end hour variation value label
 *
 */
void setter_summaryend_hourvariationvalue(float val){
	char data[20];
	memset(data, 0x00, sizeof(data));
	sprintf(data, "%f %%", val);
    lv_label_set_text(guider_ui.summaryend_hourvariationvalue, data);
}

/**
 * Function to Set summary end sequence widget container 1 flow set point value
 * @param value  value of a summary end sequence widget container 1 flow set point value label
 *
 */
void setter_summaryend_sequencewidgetcontainer1_flowsetpoint(int val){
    lv_label_set_text_fmt(guider_ui.summaryend_sequencewidgetcontainer1_flowsetpoint, "%d L/Min", val);
}

/**
 * Function to Set summary end sequence widget container 1 duration value
 * @param value  value of a summary end sequence widget container 1 duration value label
 *
 */
void setter_summaryend_sequencewidgetcontainer1_durationvalue(int val){
    lv_label_set_text_fmt(guider_ui.summaryend_sequencewidgetcontainer1_durationvalue, "%d H", val);
}

/**
 * Function to Set summary end sequence widget container 1 problem value
 * @param str  pointer to a summary end sequence widget container 1 problem value label
 *
 */
void setter_summaryend_sequencewidgetcontainer1_problemvalue(char *str){
    lv_label_set_text(guider_ui.summaryend_sequencewidgetcontainer1_problemvalue, "NONE");
}

/**
 * Function to Set summary end sequence widget container 2 flow set point value
 * @param value  value of a summary end sequence widget container 2 flow set point value label
 *
 */
void setter_summaryend_sequencewidgetcontainer2_flowsetpoint(int val){
    lv_label_set_text_fmt(guider_ui.summaryend_sequencewidgetcontainer2_flowsetpoint, "%d L/Min", val);
}

/**
 * Function to Set summary end sequence widget container 2 duration value
 * @param value  value of a summary end sequence widget container 2 duration value label
 *
 */
void setter_summaryend_sequencewidgetcontainer2_durationvalue(int val){
    lv_label_set_text_fmt(guider_ui.summaryend_sequencewidgetcontainer2_durationvalue, "%d H", val);
}

/**
 * Function to Set summary end sequence widget container 2 problem value
 * @param str  pointer to a summary end sequence widget container 2 problem value label
 *
 */
void setter_summaryend_sequencewidgetcontainer2_problemvalue(char *str){
    lv_label_set_text(guider_ui.summaryend_sequencewidgetcontainer2_problemvalue, "NONE");
}

/******************************************************************************
 *      END OF FILE
 *****************************************************************************/
