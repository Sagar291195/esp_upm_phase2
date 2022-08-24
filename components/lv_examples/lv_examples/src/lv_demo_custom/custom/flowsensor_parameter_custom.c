/*
 * alertmessage_custom.c
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
void on_flowsensor_par_back_buttonreleased(void){

}

void on_flowsensor_par_erasebuttonreleased(void){

}

/**
 * Function to Set flow sensor start date value
 * @param str value of time
 *
 */
void setter_flow_sensor_par_startdate(char *str){
	lv_label_set_text(guider_ui.flow_sensor_par_startdate_value, str);
}

/**
 * Function to Set flow sensor parameter chart value
 * @param str value of time
 */
void setter_flow_sensor_duration(char *str){
	lv_label_set_text(guider_ui.flow_sensor_par_duration_value, str);
}

/**
 * Function to Set flow sensor parameter chart value
 * @param flow_par_chart_arr_val  pointer to a chart value
 * @param len  length of chart value pointer array
 *
 */
void setter_flowsensor_par_chart(lv_coord_t *flow_par_chart_arr_val, uint8_t len){

    uint8_t i;
    for(i=0; i<len; i++)
        guider_ui.flow_sensor_par_ser->y_points[i]=flow_par_chart_arr_val[i];

    lv_chart_refresh(guider_ui.flow_sensor_par_chart);
}

/**
 * Function to Set flow sensor parameter point number label
 * @param val  value of point number
 *
 */
void setter_flow_sensor_par_label_point_number(int val){
    lv_label_set_text_fmt(guider_ui.flow_sensor_par_label_point_number, "%d", val);
}

/**
 * Function to Set flow sensor parameter global accuracy label
 * @param val  value of global accuracy
 *
 */
void setter_flow_sensor_par_label_global_accuracy(float val){
	char data[20];
	memset(data, 0x00, sizeof(data));
	sprintf(data, "%f %%", val);
    lv_label_set_text(guider_ui.flow_sensor_par_label_global_accuracy, data);
}

/**
 * Function to Set flow sensor parameter hour counter label
 * @param val  value of hour counter
 *
 */
void setter_flow_sensor_par_label_hour_counter(uint32_t val){
    lv_label_set_text_fmt(guider_ui.flow_sensor_par_label_hour_counter, "%u H", val);
}

/**
 * Function to Set flow sensor parameter volume counter label
 * @param val  value of volume counter
 *
 */
void setter_flow_sensor_par_label_volume_counter(uint32_t val){
    lv_label_set_text_fmt(guider_ui.flow_sensor_par_label_volume_counter, "%u L", val);
}

/**
 * Function to Set flow sensor parameter curve label
 * @param val  value of curve
 *
 */
void setter_flow_sensor_par_label_curve(int val){
    lv_label_set_text_fmt(guider_ui.flow_sensor_par_label_curve, "LINEAR %d", val);
}

/**
 * Function to Set flow sensor parameter unit value
 * @param str  pointer to a flow sensor parameter unit label
 *
 */
void setter_flow_sensor_par_label_unit(char *str){
    lv_label_set_text(guider_ui.flow_sensor_par_label_unit, str);
}

/**
 * Function to Set flow sensor parameter lower limit value
 * @param str  pointer to a flow sensor parameter lower limit label
 *
 */
void setter_flow_sensor_par_label_lower_limit(char *str){
    lv_label_set_text_fmt(guider_ui.flow_sensor_par_label_lower_limit, str);
    lv_label_set_text(guider_ui.flow_sensor_par_label_lower_limit, str);
}

/**
 * Function to Set flow sensor parameter higher limit value
 * @param str  pointer to a flow sensor parameter higher limit label
 *
 */
void setter_flow_sensor_par_label_point_higher_limit(char *str){
    lv_label_set_text_fmt(guider_ui.flow_sensor_par_label_higher_limit, str);
    lv_label_set_text(guider_ui.flow_sensor_par_label_higher_limit, str);
}

/**
 * Function to Set flow sensor parameter limit alert value
 * @param str  pointer to a flow sensor parameter limit alert label
 *
 */
void setter_flow_sensor_par_label_limit_alert(char *str){
    lv_label_set_text_fmt(guider_ui.flow_sensor_par_label_limit_alert, str);
    lv_label_set_text(guider_ui.flow_sensor_par_label_limit_alert, str);
}

/**
 * Function to Set flow sensor parameter after limit alert value
 * @param str  pointer to a flow sensor parameter after limit alert label
 *
 */
void setter_flow_sensor_par_label_after_limit_alert(char *str){
    lv_label_set_text_fmt(guider_ui.flow_sensor_par_label_after_limit_alert, str);
    lv_label_set_text(guider_ui.flow_sensor_par_label_after_limit_alert, str);
}

/**
 * Function to flow sensor parameter container point factory value
 * @param point_num  value of point number
 * @param val  value of factory value
 *
 */
void setter_flow_sensor_par_cont_point_factory_val(uint8_t point_num, uint32_t val){
    lv_label_set_text_fmt(guider_ui.flow_sensor_par_cont_point_factory_val[point_num], "%u", val);
}

/**
 * Function to flow sensor parameter container point compensate value
 * @param point_num  value of point number
 * @param val  value of compensated value
 *
 */
void setter_flow_sensor_par_cont_point_comp_val(uint8_t point_num, uint32_t val){
    lv_label_set_text_fmt(guider_ui.flow_sensor_par_cont_point_comp_val[point_num], "%u", val);
}

/**
 * Function to flow sensor parameter container point accuracy value
 * @param point_num  value of point number
 * @param val  value of accuracy
 *
 */
void setter_flow_sensor_par_cont_point_accuracy(uint8_t point_num, float val){
	char data[20];
	memset(data, 0x00, sizeof(data));
	sprintf(data, "%f %%", val);
    lv_label_set_text(guider_ui.flow_sensor_par_cont_point_accuracy[point_num], data);
}
/******************************************************************************
 *      END OF FILE
 *****************************************************************************/

