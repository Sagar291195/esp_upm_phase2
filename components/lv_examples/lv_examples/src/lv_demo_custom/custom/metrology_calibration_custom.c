/*
 * metrology_calibration_custom.c
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
void custom_metrologycalibration_screen_setup(screen_id_e screenid){
	switch(screenid){
	case SCR_METROLOGY_CALIBRATION_FLOW:
		lv_obj_clear_flag(guider_ui.metrology_calibration_countlabel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.metrology_calibration_countvalue, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.metrology_calibration_pointvalue, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.metrology_calibration_correction, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.title_label, "FLOW");
		lv_img_set_src(guider_ui.title_symbol, &fan_icon);
		lv_obj_align_to(guider_ui.metrology_calibration_pointlabel, guider_ui.title_container, LV_ALIGN_BOTTOM_LEFT, 10, 20);
		lv_label_set_text(guider_ui.metrology_calibration_pointlabel, "POINT :");
		break;
	case SCR_METROLOGY_CALIBRATION_PRESSURE:
		lv_obj_clear_flag(guider_ui.metrology_calibration_countlabel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.metrology_calibration_countvalue, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.metrology_calibration_pointvalue, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.metrology_calibration_correction, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.title_label, "External Pressure");
		lv_img_set_src(guider_ui.title_symbol, &temperature);
		lv_obj_align_to(guider_ui.metrology_calibration_pointlabel, guider_ui.title_container, LV_ALIGN_BOTTOM_LEFT, 10, 20);
		lv_label_set_text(guider_ui.metrology_calibration_pointlabel, "POINT :");
		break;
	case SCR_METROLOGY_CALIBRATION_TEMPERATURE:
		lv_obj_clear_flag(guider_ui.metrology_calibration_countlabel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.metrology_calibration_countvalue, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.metrology_calibration_pointvalue, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.metrology_calibration_correction, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.title_label, "External Temperature");
		lv_img_set_src(guider_ui.title_symbol, &temperature);
		lv_obj_align_to(guider_ui.metrology_calibration_pointlabel, guider_ui.title_container, LV_ALIGN_BOTTOM_LEFT, 10, 20);
		lv_label_set_text(guider_ui.metrology_calibration_pointlabel, "POINT :");
		break;
	case SCR_METROLOGY_CALIBRATION_HUMIDITY:
		lv_obj_clear_flag(guider_ui.metrology_calibration_countlabel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.metrology_calibration_countvalue, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.metrology_calibration_pointvalue, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.metrology_calibration_correction, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.title_label, "External Humidity");
		lv_img_set_src(guider_ui.title_symbol, &temperature);
		lv_obj_align_to(guider_ui.metrology_calibration_pointlabel, guider_ui.title_container, LV_ALIGN_BOTTOM_LEFT, 10, 20);
		lv_label_set_text(guider_ui.metrology_calibration_pointlabel, "POINT :");
		break;

	case SCR_METROLOGY_CALIBRATE_SETPOINT_FLOW:
		lv_obj_add_flag(guider_ui.metrology_calibration_countlabel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.metrology_calibration_countvalue, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.metrology_calibration_pointvalue, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.metrology_calibration_correction, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.title_label, "FLOW");
		lv_img_set_src(guider_ui.title_symbol, &fan_icon);
		lv_obj_align_to(guider_ui.metrology_calibration_pointlabel, guider_ui.title_container, LV_ALIGN_BOTTOM_MID, -50, 20);
		lv_label_set_text(guider_ui.metrology_calibration_pointlabel, "CALIBRATE SETPOINT 1");
		break;

	default:
		break;
	}
}

void on_metrologycal_valid_buttonreleased(void){

}

void on_metrologycal_keyboard_buttonreleased(lv_obj_t *e){

    uint8_t num;
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_t * label = lv_obj_get_child(obj, NULL);
    const char * txt = lv_label_get_text(label);
    num = *txt;
    if(num == 239)     //backspace
    {
        lv_textarea_del_char(guider_ui.metrology_calibration_keypadtxtarea);
    }
    else if(num == 44)    //,
    {

    }
    else
    {
        lv_textarea_add_char(guider_ui.metrology_calibration_keypadtxtarea, num);
        //add valid checking here
    }
}

/**
 * Function to Set metrology calibration point value
 * @param str  pointer to a metrology calibration point label
 *
 */
void setter_metrology_calibration_pointlabel(char *str){
    lv_label_set_text(guider_ui.metrology_calibration_pointlabel, str);
}

/**
 * Function to Set metrology calibration count value
 * @param str  pointer to a metrology calibration count label
 *
 */
void setter_metrology_calibration_countlabel(char *str){
    lv_label_set_text(guider_ui.metrology_calibration_countlabel, str);
}

/**
 * Function to Set metrology calibration point value
 * @param str  pointer to a metrology calibration point value label
 *
 */
void setter_metrology_calibration_pointvalue(int val){
    lv_label_set_text_fmt(guider_ui.metrology_calibration_pointvalue, "%d", val);
}

/**
 * Function to Set metrology calibration count value
 * @param str  pointer to a metrology calibration count value label
 *
 */
void setter_metrology_calibration_countvalue(char *str){
    lv_label_set_text(guider_ui.metrology_calibration_countvalue, str);
}
/******************************************************************************
 *      END OF FILE
 *****************************************************************************/



