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
/*
*	Function to update initial parameters for alert message screen
*/
void custom_alertmessage_screen_setup(screen_id_e screenid){
	switch(screenid){
	case SCR_ALERT_MESSAGE_STABLIZATION: //Stabilization phase display inner ring, outer ring and textmessage, Hide symbol
		lv_obj_clear_flag(guider_ui.alertmessage_titletext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.alertmessage_container_spinner, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.alertmessage_container_ring, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.alertmessage_container_middlelabel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.alertmessage_container_symbol, LV_OBJ_FLAG_HIDDEN);
		lv_obj_set_style_arc_color(guider_ui.alertmessage_container_ring, ESPUPM_COLOR_PURPLE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_obj_set_style_arc_color(guider_ui.alertmessage_container_spinner, ESPUPM_COLOR_PURPLE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_label_set_text(guider_ui.alertmessage_container_middlelabel, "Please Wait 15 S");
		lv_label_set_text(guider_ui.alertmessage_container_title, "Stabilization Phase");
		break;

	case SCR_ALERT_MESSAGE_CALIBRATION_SUCCESS: //Calibration Successfull Display symbol and hide other objects
		lv_obj_add_flag(guider_ui.alertmessage_titletext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.alertmessage_container_spinner, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.alertmessage_container_ring, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.alertmessage_container_middlelabel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.alertmessage_container_symbol, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.alertmessage_container_title, "Calibration Successfully");
		lv_img_set_src(guider_ui.alertmessage_container_symbol, &rightalert);
		break;

	case SCR_ALERT_MESSAGE_CALIBRATION_FAIL:	//Calibration Fail Display symbol and hide other objects
		lv_obj_add_flag(guider_ui.alertmessage_titletext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.alertmessage_container_spinner, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.alertmessage_container_ring, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.alertmessage_container_middlelabel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.alertmessage_container_symbol, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.alertmessage_container_title, "Calibration Fail");
		lv_img_set_src(guider_ui.alertmessage_container_symbol, &wrongalert);
		break;

	case SCR_ALERT_MESSAGE_UNPLUG_FILTER: //Unplug all filter hide symbol and display other objects
		lv_obj_add_flag(guider_ui.alertmessage_titletext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.alertmessage_container_spinner, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.alertmessage_container_ring, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.alertmessage_container_middlelabel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.alertmessage_container_symbol, LV_OBJ_FLAG_HIDDEN);
		lv_obj_set_style_arc_color(guider_ui.alertmessage_container_ring, ESPUPM_COLOR_YELLOW, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_obj_set_style_arc_color(guider_ui.alertmessage_container_spinner, ESPUPM_COLOR_YELLOW, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_label_set_text(guider_ui.alertmessage_container_middlelabel, "Filter Test In Progress");
		lv_label_set_text(guider_ui.alertmessage_container_title, "Unplug all the outside Filter");
		break;

	case SCR_ALERT_MESSAGE_WRONG_PASSWORD: //Wrong password Display symbol and hide other objects
		lv_obj_add_flag(guider_ui.alertmessage_titletext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.alertmessage_container_spinner, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.alertmessage_container_ring, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.alertmessage_container_middlelabel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.alertmessage_container_symbol, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.alertmessage_container_title, "Wrong Password");
		lv_img_set_src(guider_ui.alertmessage_container_symbol, &wrongalert);
		break;

	case SCR_ALERT_MESSAGE_PASSWORD_MODIFIED_SUCCESS:	//Password modified success Display symbol and hide other objects
		lv_obj_add_flag(guider_ui.alertmessage_titletext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.alertmessage_container_spinner, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.alertmessage_container_ring, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.alertmessage_container_middlelabel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.alertmessage_container_symbol, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.alertmessage_container_title, "Password Modified Successfully");
		lv_img_set_src(guider_ui.alertmessage_container_symbol, &rightalert);
		break;

	default:
		break;
	}
}

/**
 * Function to Set alert message container title label
 * @param str  pointer to a string alert message container title label
 *
 */
void setter_alertmessage_container_title(char *str){
    lv_label_set_text(guider_ui.alertmessage_container_title, str);
}

/**
 * Function to Set alert message container title label
 * @param str  pointer to a string alert message middle label
 *
 */
void setter_alertmessage_container_middlelabel(char *str){
    lv_label_set_text(guider_ui.alertmessage_container_middlelabel, str);
}

/**
 * Function to Set alert message container title text label
 * @param str  pointer to a string alert message title label
 *
 */
void setter_alertmessage_titletext(char *str){
    lv_label_set_text(guider_ui.alertmessage_titletext, str);
}
/******************************************************************************
 *      END OF FILE
 *****************************************************************************/
