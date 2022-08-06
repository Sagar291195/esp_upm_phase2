/*
 * metrology_menu_custom.c
 *
 *  Created on: 28-Jun-2022
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
void on_metrologymenu_changepassword_btnreleased(void){
}

void on_metrologymenu_back_btnreleased(void){
}

void on_metrologymenu_newvalidation_btnreleased(void){
}

void on_metrologymenu_calibration_btnreleased(void){
}

void on_metrologymenu_setservice_btnreleased(void){
}

void on_metrologymenu_sequencewidget_btnreleased(void){

}

/**
 * Function to Set metrology menu sequence container flow set point value
 * @param val  value of a metrology menu sequence container flow set point
 *
 */
void setter_metrology_menu_sequencecontainer_flowsetpointvalue(int val){
    lv_label_set_text_fmt(guider_ui.metrology_menu_sequencecontainer_flowsetpointvalue, "%d L/Min", val);
}

/**
 * Function to Set metrology menu sequence container duration value
 * @param val  value of a metrology menu sequence container duration value
 *
 */
void setter_metrology_menu_sequencecontainer_durationvalue(int val){
    lv_label_set_text_fmt(guider_ui.metrology_menu_sequencecontainer_durationvalue, "%d H", val);
}

/**
 * Function to Set metrology menu sequence container problem value
 * @param str  pointer to a metrology menu sequence container problem value label
 *
 */
void setter_metrology_menu_sequencecontainer_problemvalue(char *str){
    lv_label_set_text(guider_ui.metrology_menu_sequencecontainer_problemvalue, "NONE");
}
/******************************************************************************
 *      END OF FILE
 *****************************************************************************/
