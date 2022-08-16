/*
 * customdashboard.c
 *
 *  Created on: 21-Jun-2022
 *      Author: sagar
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
 *      EXTERN VARIABLES
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
/**
 * Function to Intialize dashboard screen with custom parameter
 * @param screenid id of screen to be loaded
 *
 */
void custom_dashboardscreen_setup(screen_id_e screenid){
	 if(screenid == SCR_DASHBOARD){
		lv_obj_set_style_bg_color(guider_ui.dashboard_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.dashboard_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.dashboard_menuview,  lv_color_make(0x50, 0x50, 0x50), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.dashboard_menuview, lv_color_make(0x50, 0x50, 0x50), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_add_flag(guider_ui.dashboard_menuviewservicebutton, LV_OBJ_FLAG_HIDDEN);
		lv_obj_set_style_bg_color(guider_ui.dashboard_menuviewinfobutton, ESPUPM_COLOR_BLACK, LV_PART_MAIN);
		lv_obj_set_style_bg_color(guider_ui.dashboard_menuviewarchievebutton, ESPUPM_COLOR_BLACK, LV_PART_MAIN);
		lv_obj_set_style_bg_color(guider_ui.dashboard_menuviewmetrologybutton, ESPUPM_COLOR_BLACK, LV_PART_MAIN);
		lv_obj_set_style_bg_color(guider_ui.dashboard_menuviewparameterbutton, ESPUPM_COLOR_BLACK, LV_PART_MAIN);
		lv_obj_align_to(guider_ui.dashboard_menuviewinfobutton, guider_ui.dashboard_menuviewservicebutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.dashboard_menuviewarchievebutton, guider_ui.dashboard_menuviewinfobutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.dashboard_menuviewmetrologybutton, guider_ui.dashboard_menuviewarchievebutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.dashboard_menuviewparameterbutton, guider_ui.dashboard_menuviewmetrologybutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
	 }else if(screenid == SCR_DASHBOARD_BLUE){
		lv_obj_set_style_bg_color(guider_ui.dashboard_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_grad_color(guider_ui.dashboard_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.dashboard_menuview,  ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN);
		lv_obj_set_style_bg_grad_color(guider_ui.dashboard_menuview, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN);
		lv_obj_clear_flag(guider_ui.dashboard_menuviewservicebutton, LV_OBJ_FLAG_HIDDEN);
		lv_obj_set_style_bg_color(guider_ui.dashboard_menuviewinfobutton, ESPUPM_COLOR_DARK_BLUE, LV_PART_MAIN);
		lv_obj_set_style_bg_color(guider_ui.dashboard_menuviewarchievebutton, ESPUPM_COLOR_DARK_BLUE, LV_PART_MAIN);
		lv_obj_set_style_bg_color(guider_ui.dashboard_menuviewmetrologybutton, ESPUPM_COLOR_DARK_BLUE, LV_PART_MAIN);
		lv_obj_set_style_bg_color(guider_ui.dashboard_menuviewparameterbutton, ESPUPM_COLOR_DARK_BLUE, LV_PART_MAIN);
		lv_obj_set_style_bg_color(guider_ui.dashboard_menuviewservicebutton, ESPUPM_COLOR_DARK_BLUE, LV_PART_MAIN);
		lv_obj_align_to(guider_ui.dashboard_menuviewarchievebutton, guider_ui.dashboard_menuviewservicebutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.dashboard_menuviewmetrologybutton, guider_ui.dashboard_menuviewarchievebutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.dashboard_menuviewparameterbutton, guider_ui.dashboard_menuviewmetrologybutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
		lv_obj_align_to(guider_ui.dashboard_menuviewinfobutton, guider_ui.dashboard_menuviewparameterbutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
	 }
}


void update_resumeinfowidget(resumeinfoStat_e statid){
	static resumeinfoStat_e previousState = 0xFF;

	if(previousState != statid){
		if(previousState == METROLOGY_INPROGRESS)
			custom_dashboardscreen_setup(SCR_DASHBOARD);
		if(statid == METROLOGY_INPROGRESS)
			custom_dashboardscreen_setup(SCR_DASHBOARD_BLUE);
		previousState = statid;
	}
	switch(statid){
	case WORK_IN_PROGRESS:
		lv_label_set_text(guider_ui.dashboard_resumeinfo_currentstatus, "Work in progress");
		lv_obj_set_style_arc_color(guider_ui.dashboard_resumeinfo_arcinner, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_obj_set_style_arc_color(guider_ui.dashboard_resumeinfo_arcouter, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_label_set_text_fmt(guider_ui.dashboard_resumeinfo_percentagetext, "%d", 76);
		lv_label_set_text(guider_ui.dashboard_resumeinfo_time_label,  "1h 23min");
		lv_label_set_text(guider_ui.dashboard_resumeinfo_sequence_label,  "01 / 01");
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_messagelabel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.dashboard_resumeinfo_percentageymboltext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.dashboard_resumeinfo_percentagetext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.dashboard_resumeinfo_time_label, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.dashboard_resumeinfo_sequence_label, LV_OBJ_FLAG_HIDDEN);
		break;

	case JOB_FINISHED:
		lv_label_set_text(guider_ui.dashboard_resumeinfo_currentstatus, "job finished");
		lv_obj_set_style_arc_color(guider_ui.dashboard_resumeinfo_arcinner, ESPUPM_COLOR_BLUE_RESUMEINFO, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_obj_set_style_arc_color(guider_ui.dashboard_resumeinfo_arcouter, ESPUPM_COLOR_BLUE_RESUMEINFO, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_percentagetext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_percentageymboltext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_time_label, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_sequence_label, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.dashboard_resumeinfo_messagelabel, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.dashboard_resumeinfo_messagelabel, "Finished\n Successfully");
		break;

	case READY:
		lv_label_set_text(guider_ui.dashboard_resumeinfo_currentstatus, "Ready");
		lv_obj_set_style_arc_color(guider_ui.dashboard_resumeinfo_arcinner, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_obj_set_style_arc_color(guider_ui.dashboard_resumeinfo_arcouter, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_percentagetext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_percentageymboltext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_time_label, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_sequence_label, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.dashboard_resumeinfo_messagelabel, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.dashboard_resumeinfo_messagelabel, "Let's\n Start");
		break;

	case WAIT_IN_PROGRESS:
		lv_label_set_text(guider_ui.dashboard_resumeinfo_currentstatus, "Wait in progress");
		lv_obj_set_style_arc_color(guider_ui.dashboard_resumeinfo_arcinner, ESPUPM_COLOR_YELLOW, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_obj_set_style_arc_color(guider_ui.dashboard_resumeinfo_arcouter, ESPUPM_COLOR_YELLOW, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_percentagetext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_percentageymboltext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_time_label, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_sequence_label, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.dashboard_resumeinfo_messagelabel, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.dashboard_resumeinfo_messagelabel, "Start in\n 1 h 23 min");
		break;

	case METROLOGY_NEEDED:
		lv_label_set_text(guider_ui.dashboard_resumeinfo_currentstatus, "Metrology needed");
		lv_obj_set_style_arc_color(guider_ui.dashboard_resumeinfo_arcinner, ESPUPM_COLOR_ORANGE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_obj_set_style_arc_color(guider_ui.dashboard_resumeinfo_arcouter, ESPUPM_COLOR_ORANGE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_percentagetext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_percentageymboltext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_time_label, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_sequence_label, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.dashboard_resumeinfo_messagelabel, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.dashboard_resumeinfo_messagelabel, "Metrology\n in\n 23 Days");
		break;

	case ALERT_SERVICE:
		lv_label_set_text(guider_ui.dashboard_resumeinfo_currentstatus, "Alert service");
		lv_obj_set_style_arc_color(guider_ui.dashboard_resumeinfo_arcinner, ESPUPM_COLOR_RED, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_obj_set_style_arc_color(guider_ui.dashboard_resumeinfo_arcouter, ESPUPM_COLOR_RED, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_percentagetext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_percentageymboltext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_time_label, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_sequence_label, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.dashboard_resumeinfo_messagelabel, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.dashboard_resumeinfo_messagelabel, "Alert\n Service\n Allowed");
		break;

	case METROLOGY_INPROGRESS:
		lv_label_set_text(guider_ui.dashboard_resumeinfo_currentstatus, "Metrology in progress");
		lv_obj_set_style_arc_color(guider_ui.dashboard_resumeinfo_arcinner, ESPUPM_COLOR_LIGHT_PURPLE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_obj_set_style_arc_color(guider_ui.dashboard_resumeinfo_arcouter, ESPUPM_COLOR_LIGHT_PURPLE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_label_set_text_fmt(guider_ui.dashboard_resumeinfo_percentagetext, "%d", 76);
		lv_label_set_text(guider_ui.dashboard_resumeinfo_time_label,  "1h 23min");
		lv_label_set_text(guider_ui.dashboard_resumeinfo_sequence_label,  "01 / 01");
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_messagelabel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.dashboard_resumeinfo_percentageymboltext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.dashboard_resumeinfo_percentagetext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.dashboard_resumeinfo_time_label, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.dashboard_resumeinfo_sequence_label, LV_OBJ_FLAG_HIDDEN);
		break;

	case EXPORT_DATA:
		lv_label_set_text(guider_ui.dashboard_resumeinfo_currentstatus, "Export data");
		lv_obj_set_style_arc_color(guider_ui.dashboard_resumeinfo_arcinner, ESPUPM_COLOR_PURPLE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_obj_set_style_arc_color(guider_ui.dashboard_resumeinfo_arcouter, ESPUPM_COLOR_PURPLE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_percentagetext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_percentageymboltext, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_time_label, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.dashboard_resumeinfo_sequence_label, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.dashboard_resumeinfo_messagelabel, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.dashboard_resumeinfo_messagelabel, "Export in\nprogress");
		break;


	default:
		break;
	}

}


/**
 * Callback function for dashboard menu button events
 */
void on_dashboard_menu_buttonreleased(void){
	static bool islistviewenabled = false;
	if(islistviewenabled == false ){
		islistviewenabled = true;
		lv_obj_align(guider_ui.dashboard_menuview, LV_ALIGN_LEFT_MID, 0,0);
		lv_obj_align(guider_ui.dashboard_background, LV_ALIGN_TOP_RIGHT, 250,0);
		lv_obj_clear_flag(guider_ui.dashboard_menuview, LV_OBJ_FLAG_HIDDEN);
	}else{
		islistviewenabled = false;
		lv_obj_align(guider_ui.dashboard_menuview, LV_ALIGN_TOP_LEFT, 0,0);
		lv_obj_align(guider_ui.dashboard_background, LV_ALIGN_CENTER, 0,0);
		lv_obj_add_flag(guider_ui.dashboard_menuview, LV_OBJ_FLAG_HIDDEN);
	}
}


/**
 * Callback function for start stop button events
 */
void on_dashboard_startstop_buttonreleased(void){

}


/**
 * Callback function for dashboard menu service button eventes
 */
void on_dashboard_service_buttonreleased(void){


}



/**
 * Callback function for dashboard menu info button events
 */
void on_dashboard_info_buttonreleased(void){

}



/**
 * Callback function for dashboard menu archiv button events
 */
void on_dashboard_archiv_buttonreleased(void){

}


/**
 * Callback function for dashboard menu metrology button events
 */
void on_dashboard_metrology_buttonreleased(void){

}


/**
 * Callback function for dashboard menu parameter button events
 */
void on_dashboard_parameter_buttonreleased(void){

}

/**
 * Function to Set dashboard char value
 * @param dashboard_chart_arr_val  pointer to a chart value
 * @param len  length of chart value pointer array
 *
 */
void setter_dashboard_chart(lv_coord_t *dashboard_chart_arr_val, uint8_t len){
    for(uint8_t i=0; i<len; i++)
        guider_ui.dashboard_ser->y_points[i]=dashboard_chart_arr_val[i];

    lv_chart_refresh(guider_ui.dashboard_chart);
}

/**
 * Function to Set dashboard welcome label
 * @param str  pointer to a dashboard welcome label
 *
 */
void setter_dashboard_welcomelabel(char *str){
    lv_label_set_text(guider_ui.dashboard_welcomelabel, str);
}

/**
 * Function to Set dashboard date label
 * @param str  pointer to a dashboard date label
 *
 */
void setter_dashboard_datelabel(char *str){
    lv_label_set_text(guider_ui.dashboard_datelabel, str);
}

/**
 * Function to Set dashboard resume info current status label
 * @param str  pointer to a dashboard resume info current status label
 *
 */
void setter_dashboard_resumeinfo_currentstatus(char *str){
    lv_label_set_text(guider_ui.dashboard_resumeinfo_currentstatus, str);
}

/**
 * Function to Set dashboard resume info percentage text
 * @param str  pointer to a dashboard resume info percentage value
 * @param percentageymbolenable to display percentage symbol or not
 *
 */
void setter_dashboard_resumeinfo_percentagetext(char *str, bool percentageymbolenable){
    lv_label_set_text(guider_ui.dashboard_resumeinfo_percentagetext,  str);
    if(percentageymbolenable==true)
        lv_label_set_text(guider_ui.dashboard_resumeinfo_percentageymboltext,  "%");
    else
        lv_label_set_text(guider_ui.dashboard_resumeinfo_percentageymboltext,  " ");
}

/**
 * Function to Set dashboard resume info time label
 * @param str  pointer to a dashboard resume info time label
 *
 */
void setter_dashboard_resumeinfo_time_label(char *str){
    lv_label_set_text(guider_ui.dashboard_resumeinfo_time_label, str);
}

/**
 * Function to Set dashboard resume info sequence label
 * @param str  pointer to a dashboard resume info sequence label
 *
 */
void setter_dashboard_resumeinfo_sequence_label(char *str){
    lv_label_set_text(guider_ui.dashboard_resumeinfo_sequence_label, str);
}

/**
 * Function to Set dashboard resume info total hour integer label
 * @param intval  integer value of total hour
 * @param rem  float value of total hour
 *
 */
void setter_dashboard_resumeinfo_totalhourintlabel(uint32_t intval, int rem){
    lv_label_set_text_fmt(guider_ui.dashboard_resumeinfo_totalhourintlabel, "%d.", intval);
    lv_label_set_text_fmt(guider_ui.dashboard_resumeinfo_totalhourfloatlabel, "%02d H", rem);
}

/**
 * Function to Set dashboard resume info total liter integer label
 * @param intval  integer value of total liter
 * @param rem  float value of total liter
 *
 */
void setter_dashboard_resumeinfo_totalliterintlabel(uint32_t intval, int rem){
    lv_label_set_text_fmt(guider_ui.dashboard_resumeinfo_totalliterintlabel, "%d.", intval);
    lv_label_set_text_fmt(guider_ui.dashboard_resumeinfo_totalliterfloatlabel, "%02d L", rem);
}

/**
 * Function to Set dashboard environment parameter container value
 * @param str  pointer to a dashboard environment parameter temperature value
 *
 */
void setter_dashboard_envparameter_temperature(float tempvalue){
	char data[20];
	sprintf(data, "%.1f ° C", tempvalue);
	lv_label_set_text(guider_ui.dashboard_envparameter_temperature, data);
}

/**
 * Function to Set dashboard environment parameter container value
 * @param str  pointer to a dashboard environment parameter pressure value
 *
 */
void setter_dashboard_envparameter_pressure(float pressurevalue){
	char data[20];
	sprintf(data, "%.2f HPA", pressurevalue);
	lv_label_set_text(guider_ui.dashboard_envparameter_pressure, data);
}


/**
 * Function to Set dashboard environment parameter container value
 * @param str  pointer to a dashboard environment parameter humidity value
 *
 */
void setter_dashboard_envparameter_humidity(int humidityvalue){
	char data[20];
	sprintf(data, "%d %%", humidityvalue);
	lv_label_set_text(guider_ui.dashboard_envparameter_humidity, data);
}

/**
 * Function to Set dashboard environment parameter container value
 * @param str  pointer to a dashboard environment parameter status value
 *
 */
void setter_dashboard_envparameter_status(bool status){
	if(status == true){
		lv_img_set_src(guider_ui.dashboard_envparameter_status, &ok_icon);
	}else{
		lv_img_set_src(guider_ui.dashboard_envparameter_status, &cross_icon);
	}
}

/**
 * Function to Set dashboard prochain container value
 * @param str  pointer to a dashboard prochain container value
 *
 */
void setter_dashboard_prochain_text(char *str){
	lv_label_set_text(guider_ui.dashboard_prochain_status_filter, str);
}

/**
 * Function to Set dashboard prochain parameter container value
 * @param str  pointer to a dashboard prochain parameter status value
 *
 */
void setter_dashboard_prochain_status(bool status){
	if(status == true){
		lv_img_set_src(guider_ui.dashboard_prochain_status, &ok_icon);
	}else{
		lv_img_set_src(guider_ui.dashboard_prochain_status, &cross_icon);
	}
}
/**
 * Function to Set dashboard battery container value
 * @param str  pointer to a dashboard battery container value
 *
 */
void setter_dashboard_battery_text(char *str){
	lv_label_set_text(guider_ui.dashboard_statofbattery_parameter, str);
}

/**
 * Function to Set dashboard battery parameter container value
 * @param str  pointer to a dashboard battery parameter status value
 *
 */
void setter_dashboard_battery_status(bool status){
	if(status == true){
		lv_img_set_src(guider_ui.dashboard_statofbattery_status, &ok_icon);
	}else{
		lv_img_set_src(guider_ui.dashboard_statofbattery_status, &cross_icon);
	}
}

/**
 * Function to Set reseau network container value
 * @param str  pointer to a reseau network container value
 *
 */
void setter_dashboard_reseau_text(char *str){
	lv_label_set_text(guider_ui.dashboard_reserach_status_parameter, str);
}

/**
 * Function to Set dashboard reseau container value
 * @param str  pointer to a reseau network container status
 *
 */
void setter_dashboard_reseau_status(bool status){
	if(status == true){
		lv_img_set_src(guider_ui.dashboard_reserach_status, &ok_icon);
	}else{
		lv_img_set_src(guider_ui.dashboard_reserach_status, &cross_icon);
	}
}

/**
 * Function to Set dashboard metrologies container value
 * @param str  pointer to a dashboard metrologies value
 *
 */
void setter_dashboard_metrologies_text(char *str){
	lv_label_set_text(guider_ui.dashboard_metrologies_status_parameter, str);
}

/**
 * Function to Set dashboard metrology container value
 * @param str  pointer to a reseau metrology container status
 *
 */
void setter_dashboard_metrology_status(bool status){
	if(status == true){
		lv_img_set_src(guider_ui.dashboard_metrogies_status, &ok_icon);
	}else{
		lv_img_set_src(guider_ui.dashboard_metrogies_status, &cross_icon);
	}
}

/**
 * Function to Set  dashboard statistic container value
 * @param str  pointer to a dashboard statistic value
 *
 */
void setter_dashboard_statistic_text(char *str){
	lv_label_set_text(guider_ui.dashboard_stastics_status_parameter, str);
}

/**
 * Function to Set dashboard stastics container value
 * @param str  pointer to a stastics container status
 *
 */
void setter_dashboard_statstics_status(bool status){
	if(status == true){
		lv_img_set_src(guider_ui.dashboard_stastics_status, &ok_icon);
	}else{
		lv_img_set_src(guider_ui.dashboard_stastics_status, &cross_icon);
	}
}
/******************************************************************************
 *      END OF FILE
 *****************************************************************************/
