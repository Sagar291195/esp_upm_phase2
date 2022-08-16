/*
 * summarysample_custom.c
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
void custom_summarysample_screen_setup(screen_id_e screenid){
	switch(screenid){
	case SCR_SUMMARY_SAMPLE_SEQUENCE_01_02:
		lv_label_set_text(guider_ui.summary_sample_label, "Sequence 01 #3598E2 /02#");
		lv_obj_add_flag(guider_ui.summary_sample_previousbutton, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.summary_sample_nextbutton, LV_OBJ_FLAG_HIDDEN);
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.summary_sample_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.summary_sample_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;
	case SCR_SUMMARY_SAMPLE_SEQUENCE_02_02:
		lv_label_set_text(guider_ui.summary_sample_label, "Sequence 02 #3598E2 /02#");
		lv_obj_clear_flag(guider_ui.summary_sample_previousbutton, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.summary_sample_nextbutton, LV_OBJ_FLAG_HIDDEN);
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.summary_sample_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.summary_sample_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;
	case SCR_SUMMARY_SAMPLE_SEQUENCE_01_01:
		lv_label_set_text(guider_ui.summary_sample_label, "Sequence 01 #3598E2 /01#");
		lv_obj_add_flag(guider_ui.summary_sample_previousbutton, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.summary_sample_nextbutton, LV_OBJ_FLAG_HIDDEN);
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.summary_sample_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.summary_sample_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;
	case SCR_SUMMARY_SAMPLE_SEQUENCE_01_01_BLUE:
		lv_label_set_text(guider_ui.summary_sample_label, "Sequence 01 #3598E2 /01#");
		lv_obj_add_flag(guider_ui.summary_sample_previousbutton, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.summary_sample_nextbutton, LV_OBJ_FLAG_HIDDEN);
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.summary_sample_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.summary_sample_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;
	case SCR_SUMMARY_SAMPLE_SEQUENCE_01_02_BLUE:
		lv_label_set_text(guider_ui.summary_sample_label, "Sequence 01 #3598E2 /02#");
		lv_obj_add_flag(guider_ui.summary_sample_previousbutton, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.summary_sample_nextbutton, LV_OBJ_FLAG_HIDDEN);
		lv_obj_set_style_border_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.title_container, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.summary_sample_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.summary_sample_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;
	default:
		break;
	}
}

void on_summarysample_quit_btnreleased(void){

}

void on_summarysample_back_btnreleased(void){

}

void on_summarysample_next_btnreleased(void){

}

void on_summarysample_prev_btnreleased(void){

}

/**
 * Function to Set summary sample currant and maximum sequence value
 * @param cur_seq  value of a current Sequence number
 * @param max_seq  value of a maximum Sequence number
 *
 */
void setter_summary_sample_label(uint8_t cur_seq, uint8_t max_seq){
    lv_label_set_text_fmt(guider_ui.summary_sample_label, "Sequence %02d #3989BD /%02d#", cur_seq, max_seq);
}

/**
 * Function to Set summary sample date start
 * @param str  pointer to a summary sample date start label
 *
 */
void setter_summary_sample_datestartvalue(char *str){
   lv_label_set_text(guider_ui.summary_sample_datestartvalue, str);
}

/**
 * Function to Set summary sample date stop value
 * @param str  pointer to a summary sample date stop value label
 *
 */
void setter_summary_sample_datestopvalue(char *str){
   lv_label_set_text(guider_ui.summary_sample_datestopvalue, str);
}

/**
 * Function to Set summary sample volume start value
 * @param val  value of a summary sample volume start value
 *
 */
void setter_summary_sample_volumestartvalue(uint32_t val){
    lv_label_set_text_fmt(guider_ui.summary_sample_volumestartvalue, "%u L", val);
}

/**
 * Function to Set summary sample volume stop value
 * @param val  value of a summary sample volume stop value
 *
 */
void setter_summary_sample_volumestopvalue(uint32_t val){
    lv_label_set_text_fmt(guider_ui.summary_sample_volumestopvalue, "%u L", val);
}

/**
 * Function to Set summary sample volume target value
 * @param val  value of a summary sample volume target value
 *
 */
void setter_summary_sample_volumetargetvalue(uint32_t val){
    lv_label_set_text_fmt(guider_ui.summary_sample_volumetargetvalue, "%u L", val);
}

/**
 * Function to Set summary sample volume effective value
 * @param val  value of a summary sample volume effective value
 *
 */
void setter_summary_sample_volumeeffectivevalue(uint32_t val){
    lv_label_set_text_fmt(guider_ui.summary_sample_volumeeffectivevalue, "%u L", val);
}

/**
 * Function to Set summary sample volume variation value
 * @param val  value of a summary sample volume variation value
 *
 */
void setter_summary_sample_volumevariationvalue(float val){
	char data[20];
	memset(data, 0x00, sizeof(data));
	sprintf("%f %%", val);
    lv_label_set_text(guider_ui.summary_sample_volumevariationvalue, data);
}

/**
 * Function to Set summary sample hour start value
 * @param str  pointer to a summary sample hour start value label
 *
 */
void setter_summary_sample_hourstartvalue(char *str){
    lv_label_set_text(guider_ui.summary_sample_hourstartvalue, str);
}

/**
 * Function to Set summary sample hour stop value
 * @param str  pointer to a summary sample hour stop value label
 *
 */
void setter_summary_sample_hourstopvalue(char *str){
    lv_label_set_text(guider_ui.summary_sample_hourstopvalue, str);
}

/**
 * Function to Set summary sample hour target value
 * @param str  pointer to a summary sample hour target value label
 *
 */
void setter_summary_sample_hourtargetvalue(char *str){
    lv_label_set_text(guider_ui.summary_sample_hourtargetvalue, str);
}

/**
 * Function to Set summary sample hour effective value
 * @param str  pointer to a summary sample hour effective value label
 *
 */
void setter_summary_sample_houreffectivevalue(char *str){
    lv_label_set_text(guider_ui.summary_sample_houreffectivevalue, str);
}

/**
 * Function to Set summary sample hour variation value
 * @param val  value of a summary sample hour variation value
 *
 */
void setter_summary_sample_hourvariationvalue(float val){
	char data[20];
	memset(data, 0x00, sizeof(data));
	sprintf("%f %%", val);
    lv_label_set_text(guider_ui.summary_sample_hourvariationvalue, data);
}

/**
 * Function to Set summary sample airflow volumetric container parameter
 * @param setpointval  value of a summary sample airflow volumetric container setpoint
 * @param meanvalue  value of a summary sample airflow volumetric container meanvalue
 * @param maxvalue  value of a summary sample airflow volumetric container maxvalue
 * @param maxarrow  value of a summary sample airflow volumetric container maxarrow symbol position
 * @param minvalue  value of a summary sample airflow volumetric container minvalue
 * @param minarrow  value of a summary sample airflow volumetric container minarrow symbol position
 * @param variationval  value of a summary sample airflow volumetric container variationval
 *
 */
void setter_summary_sample_airflow_volumetric_cont(uint32_t setpointval, uint32_t meanvalue, uint32_t maxvalue, bool maxarrow,
                                                   uint32_t minvalue, bool minarrow, float variationval)
{
    lv_label_set_text_fmt(guider_ui.summary_sample_airflow_setpointvalue, "%u", setpointval);
    lv_label_set_text_fmt(guider_ui.summary_sample_airflow_meanvalue, "%u", meanvalue);
    lv_label_set_text_fmt(guider_ui.summary_sample_airflow_maxvalue, "%u", maxvalue);
    lv_label_set_text_fmt(guider_ui.summary_sample_airflow_minvalue, "%u", minvalue);
    char data[20];
	memset(data, 0x00, sizeof(data));
	sprintf("%f %%", variationval);
    lv_label_set_text(guider_ui.summary_sample_airflow_variationvalue, data);

    if(maxarrow)
        lv_img_set_src(guider_ui.summary_sample_airflow_maxvaluearrow, &uparrow);
    else
        lv_img_set_src(guider_ui.summary_sample_airflow_maxvaluearrow, &downarrow);

    if(minarrow)
        lv_img_set_src(guider_ui.summary_sample_airflow_minvaluearrow, &uparrow);
    else
        lv_img_set_src(guider_ui.summary_sample_airflow_minvaluearrow, &downarrow);
}

/**
 * Function to Set summary sample ambient temperature container parameter
 * @param limitvaluestr  pointer to a summary sample ambient temperature container limitvaluestr
 * @param meanvalue  value of a summary sample ambient temperature container meanvalue
 * @param maxvalue  value of a summary sample ambient temperature container maxvalue
 * @param maxarrow  value of a summary sample ambient temperature container maxarrow symbol position
 * @param minvalue  value of a summary sample ambient temperature container minvalue
 * @param minarrow  value of a summary sample ambient temperature container minarrow symbol position
 * @param variationval  value of a summary sample ambient temperature container variationval
 *
 */
void setter_summary_sample_ambient_temp_cont(char * limitvaluestr, uint32_t meanvalue, uint32_t maxvalue, bool maxarrow,
                                                   uint32_t minvalue, bool minarrow, float variationval)
{
    lv_label_set_text(guider_ui.summary_sample_ambienttemperature_limitvalue, limitvaluestr);
    lv_label_set_text_fmt(guider_ui.summary_sample_ambienttemperature_meanvalue, "%u", meanvalue);
    lv_label_set_text_fmt(guider_ui.summary_sample_ambienttemperature_maxvalue, "%u", maxvalue);
    lv_label_set_text_fmt(guider_ui.summary_sample_ambienttemperature_minvalue, "%u", minvalue);
    char data[20];
	memset(data, 0x00, sizeof(data));
	sprintf("%f %%", variationval);
    lv_label_set_text(guider_ui.summary_sample_ambienttemperature_variationvalue, data);

    if(maxarrow)
        lv_img_set_src(guider_ui.summary_sample_ambienttemperature_maxvaluearrow, &uparrow);
    else
        lv_img_set_src(guider_ui.summary_sample_ambienttemperature_maxvaluearrow, &downarrow);

    if(minarrow)
        lv_img_set_src(guider_ui.summary_sample_ambienttemperature_minvaluearrow, &uparrow);
    else
        lv_img_set_src(guider_ui.summary_sample_ambienttemperature_minvaluearrow, &downarrow);
}

/**
 * Function to Set summary sample ambient pressure container parameter
 * @param limitvaluestr  pointer to a summary sample ambient pressure container limitvaluestr
 * @param meanvalue  value of a summary sample ambient pressure container meanvalue
 * @param maxvalue  value of a summary sample ambient pressure container maxvalue
 * @param maxarrow  value of a summary sample ambient pressure container maxarrow symbol position
 * @param minvalue  value of a summary sample ambient pressure container minvalue
 * @param minarrow  value of a summary sample ambient pressure container minarrow symbol position
 * @param variationval  value of a summary sample ambient pressure container variationval
 *
 */
void setter_summary_sample_ambient_pressure_cont(char * limitvaluestr, uint32_t meanvalue, uint32_t maxvalue, bool maxarrow,
                                                   uint32_t minvalue, bool minarrow, float variationval)
{
    lv_label_set_text(guider_ui.summary_sample_ambientpressure_limitvalue, limitvaluestr);
    lv_label_set_text_fmt(guider_ui.summary_sample_ambientpressure_meanvalue, "%u", meanvalue);
    lv_label_set_text_fmt(guider_ui.summary_sample_ambientpressure_maxvalue, "%u", maxvalue);
    lv_label_set_text_fmt(guider_ui.summary_sample_ambientpressure_minvalue, "%u", minvalue);
    char data[20];
	memset(data, 0x00, sizeof(data));
	sprintf("%f %%", variationval);
    lv_label_set_text(guider_ui.summary_sample_ambientpressure_variationvalue, data);

    if(maxarrow)
        lv_img_set_src(guider_ui.summary_sample_ambientpressure_maxvaluearrow, &uparrow);
    else
        lv_img_set_src(guider_ui.summary_sample_ambientpressure_maxvaluearrow, &downarrow);

    if(minarrow)
        lv_img_set_src(guider_ui.summary_sample_ambientpressure_minvaluearrow, &uparrow);
    else
        lv_img_set_src(guider_ui.summary_sample_ambientpressure_minvaluearrow, &downarrow);
}

/**
 * Function to Set summary sample ambient humidity container parameter
 * @param limitvaluestr  pointer to a summary sample ambient humidity container limitvaluestr
 * @param meanvalue  value of a summary sample ambient humidity container meanvalue
 * @param maxvalue  value of a summary sample ambient humidity container maxvalue
 * @param maxarrow  value of a summary sample ambient humidity container maxarrow symbol position
 * @param minvalue  value of a summary sample ambient humidity container minvalue
 * @param minarrow  value of a summary sample ambient humidity container minarrow symbol position
 * @param variationval  value of a summary sample ambient humidity container variationval
 *
 */
void setter_summary_sample_ambient_humidity_cont(char * limitvaluestr, uint32_t meanvalue, uint32_t maxvalue, bool maxarrow,
                                                   uint32_t minvalue, bool minarrow, float variationval)
{
    lv_label_set_text(guider_ui.summary_sample_ambienthumidity_limitvalue, limitvaluestr);
    lv_label_set_text_fmt(guider_ui.summary_sample_ambienthumidity_meanvalue, "%u", meanvalue);
    lv_label_set_text_fmt(guider_ui.summary_sample_ambienthumidity_maxvalue, "%u", maxvalue);
    lv_label_set_text_fmt(guider_ui.summary_sample_ambienthumidity_minvalue, "%u", minvalue);
    char data[20];
	memset(data, 0x00, sizeof(data));
	sprintf("%f %%", variationval);
    lv_label_set_text(guider_ui.summary_sample_ambienthumidity_variationvalue, data);

    if(maxarrow)
        lv_img_set_src(guider_ui.summary_sample_ambienthumidity_maxvaluearrow, &uparrow);
    else
        lv_img_set_src(guider_ui.summary_sample_ambienthumidity_maxvaluearrow, &downarrow);

    if(minarrow)
        lv_img_set_src(guider_ui.summary_sample_ambienthumidity_minvaluearrow, &uparrow);
    else
        lv_img_set_src(guider_ui.summary_sample_ambienthumidity_minvaluearrow, &downarrow);
}

/**
 * Function to Set summary sample head loss container parameter
 * @param limitvaluestr  pointer to a summary sample head loss container limitvaluestr
 * @param meanvalue  value of a summary sample head loss container meanvalue
 * @param maxvalue  value of a summary sample head loss container maxvalue
 * @param maxarrow  value of a summary sample head loss container maxarrow symbol position
 * @param minvalue  value of a summary sample head loss container minvalue
 * @param minarrow  value of a summary sample head loss container minarrow symbol position
 * @param variationval  value of a summary sample head loss container variationval
 *
 */
void setter_summary_sample_head_loss_cont(char * limitvaluestr, uint32_t meanvalue, uint32_t maxvalue, bool maxarrow,
                                                   uint32_t minvalue, bool minarrow, float variationval)
{
    lv_label_set_text(guider_ui.summary_sample_headloss_limitvalue, limitvaluestr);
    lv_label_set_text_fmt(guider_ui.summary_sample_headloss_meanvalue, "%u", meanvalue);
    lv_label_set_text_fmt(guider_ui.summary_sample_headloss_maxvalue, "%u", maxvalue);
    lv_label_set_text_fmt(guider_ui.summary_sample_headloss_minvalue, "%u", minvalue);
    char data[20];
	memset(data, 0x00, sizeof(data));
	sprintf("%f %%", variationval);
    lv_label_set_text(guider_ui.summary_sample_headloss_variationvalue, data);

    if(maxarrow)
        lv_img_set_src(guider_ui.summary_sample_headloss_maxvaluearrow, &uparrow);
    else
        lv_img_set_src(guider_ui.summary_sample_headloss_maxvaluearrow, &downarrow);

    if(minarrow)
        lv_img_set_src(guider_ui.summary_sample_headloss_minvaluearrow, &uparrow);
    else
        lv_img_set_src(guider_ui.summary_sample_headloss_minvaluearrow, &downarrow);
}

/******************************************************************************
 *      END OF FILE
 *****************************************************************************/
