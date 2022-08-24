/*
 * metrology_service_custom.c
 *
 *  Created on: 03-Jul-2022
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
void on_metrology_service_backbutton_released(void){

}

void on_metrology_service_hourservice_alertswitch_valuechanged(void){

}

void on_metrology_service_hourservice_inbutton_released(void){

}


void on_metrology_service_hourservice_alertdropdown_valuechanged(void){

}

void on_metrology_service_hourservice_actionswitch_valuechanged(void){

}


void on_metrology_service_dateservice_alertswitch_valuechanged(void){

}

void on_metrology_service_dateservice_inbutton_released(void){

}


void on_metrology_service_dateservice_alertdropdown_valuechanged(void){

}

void on_metrology_service_dateservice_actionswitch_valuechanged(void){

}


void on_metrology_service_volumeservice_alertswitch_valuechanged(void){

}

void on_metrology_service_volumeservice_inbutton_released(void){

}


void on_metrology_service_volumeservice_alertdropdown_valuechanged(void){

}

void on_metrology_service_volumeservice_actionswitch_valuechanged(void){

}

void on_metrology_service_filterservice_alertswitch_valuechanged(void){

}

void on_metrology_service_filterservice_inbutton_released(void){

}

void on_metrology_service_filterservice_alertdropdown_valuechanged(void){

}

void on_metrology_service_filterservice_actionswitch_valuechanged(void){

}


void on_metrology_service_filtertest_buttonreleased(void){

}


/**
 * Function to Set metrology service hour service alert switch status
 * @param switch_status  enable/disable metrology service hour service alert switch status
 *
 */
void setter_metrology_service_hourservicealertswitch(bool switch_status){
    if(switch_status)
        lv_obj_add_state(guider_ui.metrology_service_hourservicealertswitch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(guider_ui.metrology_service_hourservicealertswitch, LV_STATE_CHECKED);
}

/**
 * Function to Set metrology service hour service invalue
 * @param val  value of a metrology service hour service invalue
 *
 */
void setter_metrology_service_hourserviceinvalue(int val){
    lv_label_set_text_fmt(guider_ui.metrology_service_hourserviceinvalue, "%d Hours", val);
}

/**
 * Function to Set metrology service hour service alert dropdown value
 * @param num  value of a metrology service hour service alert dropdown
 *
 */
void setter_metrology_service_hourserivealertdropdown(uint16_t num){
    lv_dropdown_set_selected(guider_ui.metrology_service_hourserivealertdropdown, num);
}

/**
 * Function to Set metrology service hour service action switch status
 * @param switch_status  enable/disable metrology service hour service action switch status
 *
 */
void setter_metrology_service_hourseriveactionswitch(bool switch_status){
    if(switch_status)
        lv_obj_add_state(guider_ui.metrology_service_hourseriveactionswitch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(guider_ui.metrology_service_hourseriveactionswitch, LV_STATE_CHECKED);
}

/**
 * Function to Set metrology service date service alert switch status
 * @param switch_status  enable/disable metrology service date service alert switch status
 *
 */
void setter_metrology_service_dateservicealertswitch(bool switch_status){
    if(switch_status)
        lv_obj_add_state(guider_ui.metrology_service_dateservicealertswitch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(guider_ui.metrology_service_dateservicealertswitch, LV_STATE_CHECKED);
}

/**
 * Function to Set metrology service date service invalue
 * @param str  pointer to a metrology service date service invalue
 *
 */
void setter_metrology_service_dateserviceinvalue(char *str){
    lv_label_set_text(guider_ui.metrology_service_dateserviceinvalue, str);
}

/**
 * Function to Set metrology service date service dropdown value
 * @param num  value of a metrology service date service dropdown
 *
 */
void setter_metrology_service_dateservicealertdropdown(uint16_t num){
    lv_dropdown_set_selected(guider_ui.metrology_service_dateservicealertdropdown, num);
}

/**
 * Function to Set metrology service date service action switch status
 * @param switch_status  enable/disable metrology service date service action switch status
 *
 */
void setter_metrology_service_dateserviceactionswitch(bool switch_status){
    if(switch_status)
        lv_obj_add_state(guider_ui.metrology_service_dateserviceactionswitch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(guider_ui.metrology_service_dateserviceactionswitch, LV_STATE_CHECKED);
}

/**
 * Function to Set metrology service volume service alert switch status
 * @param switch_status  enable/disable metrology service volume service alert switch status
 *
 */
void setter_metrology_service_volumeservicealertswitch(bool switch_status){
    if(switch_status)
        lv_obj_add_state(guider_ui.metrology_service_volumeservicealertswitch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(guider_ui.metrology_service_volumeservicealertswitch, LV_STATE_CHECKED);
}

/**
 * Function to Set metrology service volume service invalues
 * @param val  value of a metrology service volume service invalues
 *
 */
void setter_metrology_service_volumeserviceinvalue(uint32_t val){
    lv_label_set_text_fmt(guider_ui.metrology_service_volumeserviceinvalue, "%u Litres", val);
}

/**
 * Function to Set metrology service volume service alert dropdown value
 * @param num  value of a metrology service volume service alert dropdown
 *
 */
void setter_metrology_service_volumeservicealertdropdown(uint16_t num){
    lv_dropdown_set_selected(guider_ui.metrology_service_volumeservicealertdropdown, num);
}

/**
 * Function to Set metrology service volume service action switch status
 * @param switch_status  enable/disable metrology service volume service action switch status
 *
 */
void setter_metrology_service_volumeserviceactionswitch(bool switch_status){
    if(switch_status)
        lv_obj_add_state(guider_ui.metrology_service_volumeserviceactionswitch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(guider_ui.metrology_service_volumeserviceactionswitch, LV_STATE_CHECKED);
}

/**
 * Function to Set metrology service filter service alert switch status
 * @param switch_status  enable/disable metrology service filter service alert switch status
 *
 */
void setter_metrology_service_filterservicealertswitch(bool switch_status){
    if(switch_status)
        lv_obj_add_state(guider_ui.metrology_service_filterservicealertswitch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(guider_ui.metrology_service_filterservicealertswitch, LV_STATE_CHECKED);
}

/**
 * Function to Set metrology service filter service invalue value
 * @param val  value of a metrology service filter service invalue
 *
 */
void setter_metrology_service_filterserviceinvalue(uint8_t val){
    lv_label_set_text_fmt(guider_ui.metrology_service_filterserviceinvalue, "%d %%", val);
}

/**
 * Function to Set metrology service filter service alert dropdown value
 * @param num  value of a metrology service filter service alert dropdown
 *
 */
void setter_metrology_service_filterserivealertdropdown(uint16_t num){
    lv_dropdown_set_selected(guider_ui.metrology_service_filterserivealertdropdown, num);
}

/**
 * Function to Set metrology service filter service action switch status
 * @param switch_status  enable/disable metrology service filter service action switch status
 *
 */
void setter_metrology_service_filterserviceactionswitch(bool switch_status){
    if(switch_status)
        lv_obj_add_state(guider_ui.metrology_service_filterserviceactionswitch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(guider_ui.metrology_service_filterserviceactionswitch, LV_STATE_CHECKED);
}
/******************************************************************************
 *      END OF FILE
 *****************************************************************************/
