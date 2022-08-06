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


void on_parameter_backbutton_released(void){

}

void on_parameter_buzzer_valuechanged(void){

}

void on_parameter_led_valuechanged(void){

}

void on_parameter_wifi_valuechanged(void){

}

void on_parameter_externalfan_valuechanged(void){

}

void on_parameter_sleep_valuechanged(void){

}

void on_parameter_language_valuechanged(void){

}

void on_parameter_sleeptimer_valuechanged(void){

}

void on_parameter_luminosity_valuechanged(void){

}

void on_parameter_contrast_valuechanged(void){

}

/**
 * Function to Set parameter buzzer switch status
 * @param switch_status  enable/disable parameter buzzer switch status
 *
 */
void setter_parameter_buzzerswitch(bool switch_status){
    if(switch_status)
        lv_obj_add_state(guider_ui.parameter_buzzerswitch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(guider_ui.parameter_buzzerswitch, LV_STATE_CHECKED);
}

/**
 * Function to Set parameter led switch status
 * @param switch_status  enable/disable parameter led switch status
 *
 */
void setter_parameter_ledswitch(bool switch_status){
    if(switch_status)
        lv_obj_add_state(guider_ui.parameter_ledswitch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(guider_ui.parameter_ledswitch, LV_STATE_CHECKED);
}

/**
 * Function to Set parameter wifi switch status
 * @param switch_status  enable/disable parameter wifi switch status
 *
 */
void setter_parameter_wifiswitch(bool switch_status){
    if(switch_status)
        lv_obj_add_state(guider_ui.parameter_wifiswitch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(guider_ui.parameter_wifiswitch, LV_STATE_CHECKED);
}

/**
 * Function to Set parameter fan switch status
 * @param switch_status  enable/disable parameter fan switch status
 *
 */
void setter_parameter_fanswitch(bool switch_status){
    if(switch_status)
        lv_obj_add_state(guider_ui.parameter_fanswitch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(guider_ui.parameter_fanswitch, LV_STATE_CHECKED);
}

/**
 * Function to Set parameter sleep switch status
 * @param switch_status  enable/disable parameter sleep switch status
 *
 */
void setter_parameter_sleepswitch(bool switch_status){
    if(switch_status)
        lv_obj_add_state(guider_ui.parameter_sleepswitch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(guider_ui.parameter_sleepswitch, LV_STATE_CHECKED);
}

/**
 * Function to Set parameter language dropdown value
 * @param num  index of a parameter language dropdown
 *
 */
void setter_parameter_languagedropdown(uint16_t num){
    lv_dropdown_set_selected(guider_ui.parameter_languagedropdown, num);
}

/**
 * Function to Set parameter sleep timer dropdown value
 * @param num  index of a parameter sleep timer dropdown
 *
 */
void setter_parameter_sleeptimerdropdown(uint16_t num){
    lv_dropdown_set_selected(guider_ui.parameter_sleeptimerdropdown, num);
}

/**
 * Function to Set parameter luminosity slider value
 * @param val  value of a parameter luminosity slider value
 *
 */
void setter_parameter_luminosityslider(uint8_t val){
    lv_slider_set_value(guider_ui.parameter_luminosityslider, val, false);
}

/**
 * Function to Set parameter contrast slider value
 * @param val  value of a parameter contrast slider value
 *
 */
void setter_parameter_contrastslider(uint8_t val){
    lv_slider_set_value(guider_ui.parameter_contrastslider, val, false);
}
/******************************************************************************
 *      END OF FILE
 *****************************************************************************/
