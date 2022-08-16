// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/**
 * @file custom.c
 *
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
static screen_id_e screenid = SCR_TEST;
static int header_hour_value = 11;
static int header_minute_value = 25;
static int header_seconds_value = 50;

/******************************************************************************
 *      STATIC PROTOTYPE
 *****************************************************************************/
static lv_obj_t **get_scr_by_id(int scr_id);
static void header_clock_timer(lv_timer_t *timer);
static volatile resumeinfoStat_e resumeInfostat = WORK_IN_PROGRESS;
/******************************************************************************
 *      STATIC FUNCTIONS
 *****************************************************************************/
static lv_obj_t **get_scr_by_id(int scr_id)
{
	switch(scr_id){
	case SCR_SLEEP:
		return &guider_ui.sleep;
	case SCR_LOGO:
		return &guider_ui.screen_logo;
	case SCR_DASHBOARD_BLUE:
	case SCR_DASHBOARD:
		return &guider_ui.dashboard;
	case SCR_PASSWORD:
	case SCR_PASSWORD_BLUE:
	case SCR_PASSWORD_METROLOGY_CODE:
		return &guider_ui.password;
	case SCR_PRESET_SCENARIO:
	case SCR_PRESET_SCENARIO_BLUE:
		return &guider_ui.preset_scenario;
	case SCR_PRESET_SEQUENCE:
	case SCR_PRESET_SEQUENCE_BLUE:
		return &guider_ui.preset_sequence;
	case SCR_SUMMARY_START:
	case SCR_SUMMARY_START_BLUE:
		return &guider_ui.summary_start;
	case SCR_SUMMARY_END:
	case SCR_SUMMARY_END_BLUE:
	case SCR_SUMMARY_END_SINGLEWIDGET:
	case SCR_SUMMARY_END_SINGLEWIDGET_BLUE:
	case SCR_SUMMARY_ARCHIV:
	case SCR_SUMMARY_ARCHIV_BLUE:
	case SCR_SUMMARY_ARCHIV_SINGLEWIDGET:
	case SCR_SUMMARY_ARCHIV_SINGLEWIDGET_BLUE:
		return &guider_ui.summaryend;
	case SCR_SUMMARY_SAMPLE_SEQUENCE_01_02:
	case SCR_SUMMARY_SAMPLE_SEQUENCE_02_02:
	case SCR_SUMMARY_SAMPLE_SEQUENCE_01_01:
	case SCR_SUMMARY_SAMPLE_SEQUENCE_01_01_BLUE:
	case SCR_SUMMARY_SAMPLE_SEQUENCE_01_02_BLUE:
		return &guider_ui.summary_sample;
	case SCR_METROLOGY_MENU:
		return &guider_ui.metrology_menu;
	case SCR_METROLOGY_CALIBRATION_PRESSURE:
	case SCR_METROLOGY_CALIBRATION_TEMPERATURE:
	case SCR_METROLOGY_CALIBRATION_HUMIDITY:
	case SCR_METROLOGY_CALIBRATION_FLOW:
	case SCR_METROLOGY_CALIBRATE_SETPOINT_FLOW:
		return &guider_ui.metrology_calibration;
	case SCR_METROLOGY_SETTINGS_PRESSURE:
	case SCR_METROLOGY_SETTINGS_TEMPERATURE:
	case SCR_METROLOGY_SETTINGS_HUMIDITY:
	case SCR_METROLOGY_SETTINGS_FLOW:
		return &guider_ui.metrology_settings;
	case SCR_METROLOGY_SERVICE:
		return &guider_ui.metrology_service;
	case SCR_FLOW_PARAMETER:
		return &guider_ui.flow_sensor_par;
	case SCR_INFO:
		return &guider_ui.info;
	case SCR_ALERT_MESSAGE_STABLIZATION:
    case SCR_ALERT_MESSAGE_CALIBRATION_SUCCESS:
    case SCR_ALERT_MESSAGE_CALIBRATION_FAIL:
    case SCR_ALERT_MESSAGE_PASSWORD_MODIFIED_SUCCESS:
    case SCR_ALERT_MESSAGE_WRONG_PASSWORD:
    case SCR_ALERT_MESSAGE_UNPLUG_FILTER:
		return &guider_ui.alertmessage;
	case SCR_TEST:
		return &guider_ui.test;
	default:
		return NULL;
	}
    return NULL;
}

static void header_clock_timer(lv_timer_t *timer)
{
	clock_count_24(&header_hour_value, &header_minute_value, &header_seconds_value);
	if (lv_obj_is_valid(guider_ui.header_timelabel))
	{
		lv_label_set_text_fmt(guider_ui.header_timelabel, "%02d:%02d:%02d", header_hour_value, header_minute_value, header_seconds_value);
	}
}

/******************************************************************************
 *      GLOBAL FUNCTIONS
 *****************************************************************************/
void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

screen_id_e getcurrentscreenid(void){
    return screenid;
}

void guider_load_screen(int scr_id){
    lv_obj_t **scr = NULL;
    lv_obj_t **old_scr = NULL;
    bool deleteoldscreen = false;

	switch(scr_id)
    {
    case SCR_SLEEP:
        if(!guider_ui.sleep){
            scr = &guider_ui.sleep;
            setup_scr_sleep(&guider_ui);
            deleteoldscreen = true;
        }
        break;

    case SCR_LOGO:
        if(!guider_ui.screen_logo){
            scr = &guider_ui.screen_logo;
            setup_scr_logo(&guider_ui);
            deleteoldscreen = true;
        }
        break;

    case SCR_DASHBOARD_BLUE:
    case SCR_DASHBOARD:
        if(!guider_ui.dashboard){
            scr = &guider_ui.dashboard;
            setup_scr_dashboard(&guider_ui);
            deleteoldscreen = true;
        }
        update_resumeinfowidget(resumeInfostat);
        break;

	case SCR_PASSWORD:
	case SCR_PASSWORD_BLUE:
	case SCR_PASSWORD_METROLOGY_CODE:
		if(!guider_ui.password){
			scr = &guider_ui.password;
			setup_scr_password(&guider_ui);
			deleteoldscreen = true;
		}
		custom_passwordscreen_setup(scr_id);
		break;

	case SCR_PRESET_SCENARIO_BLUE:
    case SCR_PRESET_SCENARIO:
    	if(!guider_ui.preset_scenario){
    		scr = &guider_ui.preset_scenario;
			setup_scr_preset_scenario(&guider_ui);
			deleteoldscreen = true;
    	}
    	custom_presetscenario_screen_setup(scr_id);
    	break;

    case SCR_PRESET_SEQUENCE:
	case SCR_PRESET_SEQUENCE_BLUE:
		if(!guider_ui.preset_sequence){
			scr = &guider_ui.preset_sequence;
			setup_scr_preset_sequence(&guider_ui);
			deleteoldscreen = true;
		}
		custom_presetsequence_screen_setup(scr_id);
		break;

    case SCR_SUMMARY_START:
    case SCR_SUMMARY_START_BLUE:
		if(!guider_ui.summary_start){
			scr = &guider_ui.summary_start;
			setup_scr_summary_start(&guider_ui);
			deleteoldscreen = true;
		}
		custom_summarystart_screen_setup(scr_id);
		break;

    case SCR_SUMMARY_END:
    case SCR_SUMMARY_END_BLUE:
    case SCR_SUMMARY_END_SINGLEWIDGET:
    case SCR_SUMMARY_END_SINGLEWIDGET_BLUE:
    case SCR_SUMMARY_ARCHIV:
    case SCR_SUMMARY_ARCHIV_BLUE:
    case SCR_SUMMARY_ARCHIV_SINGLEWIDGET:
    case SCR_SUMMARY_ARCHIV_SINGLEWIDGET_BLUE:
   		if(!guider_ui.summaryend){
   			scr = &guider_ui.summaryend;
   			setup_scr_summary_end(&guider_ui);
   			deleteoldscreen = true;
   		}
   		custom_summaryend_screen_setup(scr_id);
   		break;

    case SCR_SUMMARY_SAMPLE_SEQUENCE_01_02:
    case SCR_SUMMARY_SAMPLE_SEQUENCE_02_02:
    case SCR_SUMMARY_SAMPLE_SEQUENCE_01_01:
    case SCR_SUMMARY_SAMPLE_SEQUENCE_01_01_BLUE:
    case SCR_SUMMARY_SAMPLE_SEQUENCE_01_02_BLUE:
    	if(!guider_ui.summary_sample){
			scr = &guider_ui.summary_sample;
			setup_scr_summary_sample(&guider_ui);
			deleteoldscreen = true;
		}
    	custom_summarysample_screen_setup(scr_id);
    	break;


    case SCR_PARAMETER:
        if(!guider_ui.parameter){
            scr = &guider_ui.parameter;
            setup_scr_parameter(&guider_ui);
            deleteoldscreen = true;
        }
        break;

    case SCR_FLOW_PARAMETER:
       	if(!guider_ui.flow_sensor_par){
   			scr = &guider_ui.flow_sensor_par;
   			setup_scr_flow_sensor_parameter(&guider_ui);
   			deleteoldscreen = true;
   		}
       	break;

    case SCR_INFO:
		if(!guider_ui.info){
			scr = &guider_ui.info;
			setup_scr_info(&guider_ui);
			deleteoldscreen = true;
		}
		break;

    case SCR_METROLOGY_MENU:
    	if(!guider_ui.metrology_menu){
			scr = &guider_ui.metrology_menu;
			setup_scr_metrology_menu(&guider_ui);
			deleteoldscreen = true;
		}
    	break;

    case SCR_METROLOGY_CALIBRATION_FLOW:
    case SCR_METROLOGY_CALIBRATION_PRESSURE:
    case SCR_METROLOGY_CALIBRATION_TEMPERATURE:
    case SCR_METROLOGY_CALIBRATION_HUMIDITY:
    case SCR_METROLOGY_CALIBRATE_SETPOINT_FLOW:
       	if(!guider_ui.metrology_calibration){
   			scr = &guider_ui.metrology_calibration;
   			setup_scr_metrology_calibration(&guider_ui);
   			deleteoldscreen = true;
   		}
       	custom_metrologycalibration_screen_setup(scr_id);
       	break;

    case SCR_METROLOGY_SETTINGS_FLOW:
    case SCR_METROLOGY_SETTINGS_PRESSURE:
    case SCR_METROLOGY_SETTINGS_TEMPERATURE:
    case SCR_METROLOGY_SETTINGS_HUMIDITY:
    	if(!guider_ui.metrology_settings){
			scr = &guider_ui.metrology_settings;
			setup_scr_metrology_settings(&guider_ui);
			deleteoldscreen = true;
		}
    	custom_metrologysettings_screen_setup(scr_id);
    	break;

    case SCR_METROLOGY_SERVICE:
    	if(!guider_ui.metrology_service){
			scr = &guider_ui.metrology_service;
			setup_scr_metrology_service(&guider_ui);
			deleteoldscreen = true;
		}
    	break;



    case SCR_ALERT_MESSAGE_STABLIZATION:
    case SCR_ALERT_MESSAGE_CALIBRATION_SUCCESS:
    case SCR_ALERT_MESSAGE_CALIBRATION_FAIL:
    case SCR_ALERT_MESSAGE_PASSWORD_MODIFIED_SUCCESS:
    case SCR_ALERT_MESSAGE_WRONG_PASSWORD:
    case SCR_ALERT_MESSAGE_UNPLUG_FILTER:
    	if(!guider_ui.alertmessage){
    		scr = &guider_ui.alertmessage;
			setup_scr_alertmesage(&guider_ui);

    		deleteoldscreen = true;
    	}
    	custom_alertmessage_screen_setup(scr_id);
    	break;

    default:
        break;
    }
    if(deleteoldscreen == true){
        lv_scr_load(*scr);
        old_scr = get_scr_by_id(screenid);
        lv_obj_clean(*old_scr);
        lv_obj_del(*old_scr);
         *old_scr = NULL;
    }
    screenid = scr_id;
}

/**
 * Function to  draw header portion for each screen
 * @param ui  pointer to a strcture of all objects
 * @param screenobject pointer to the object of parent screen
 *
 */
void setup_draw_header(lv_ui *ui, lv_obj_t *screenobject){
	/******************************
	 * Header Design start
	 *****************************/
	//Time label in header
	ui->header_timelabel = lv_label_create(screenobject);
	lv_obj_align(ui->header_timelabel, LV_ALIGN_TOP_LEFT, 10, 4);
	static lv_style_t style_header_timelabel_default;
	if (style_header_timelabel_default.prop_cnt > 1)
		lv_style_reset(&style_header_timelabel_default);
	else
		lv_style_init(&style_header_timelabel_default);
	lv_style_set_radius(&style_header_timelabel_default, 0);
	lv_style_set_bg_color(&style_header_timelabel_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_color(&style_header_timelabel_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_dir(&style_header_timelabel_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_header_timelabel_default, 0);
	lv_style_set_text_color(&style_header_timelabel_default, ESPUPM_COLOR_WHITE);
	lv_style_set_text_font(&style_header_timelabel_default, &lv_font_montserrat_20_semibold);
	lv_style_set_text_letter_space(&style_header_timelabel_default, 0);
	lv_style_set_pad_left(&style_header_timelabel_default, 0);
	lv_style_set_pad_right(&style_header_timelabel_default, 0);
	lv_style_set_pad_top(&style_header_timelabel_default, 0);
	lv_style_set_pad_bottom(&style_header_timelabel_default, 0);
	lv_obj_add_style(ui->header_timelabel, &style_header_timelabel_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text_fmt(ui->header_timelabel, "%02d:%02d:%02d", header_hour_value, header_minute_value, header_seconds_value);
	static bool screen_clock_timer_enabled = false;
	if (!screen_clock_timer_enabled) {
		lv_timer_create(header_clock_timer, 1000, NULL);
		screen_clock_timer_enabled = true;
	}

	//Battery icon in header
	ui->header_battery = lv_label_create(screenobject);
	static lv_style_t style_header_symbol_battery;
	if (style_header_symbol_battery.prop_cnt > 1)
		lv_style_reset(&style_header_symbol_battery);
	else
		lv_style_init(&style_header_symbol_battery);
	lv_style_init(&style_header_symbol_battery);
	lv_style_set_text_font(&style_header_symbol_battery, &lv_font_montserrat_24);
	lv_style_set_text_color(&style_header_symbol_battery, ESPUPM_COLOR_WHITE);
	lv_obj_align(ui->header_battery, LV_ALIGN_TOP_RIGHT, -10, 5);
	lv_obj_add_style(ui->header_battery, &style_header_symbol_battery, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->header_battery, LV_SYMBOL_BATTERY_FULL);

	//WiFi icon in header
	ui->header_wifi = lv_label_create(screenobject);
	lv_obj_align_to(ui->header_wifi, ui->header_battery, LV_ALIGN_TOP_LEFT, -30, 3);
	static lv_style_t style_header_symbol_wifi;
	if (style_header_symbol_wifi.prop_cnt > 1)
		lv_style_reset(&style_header_symbol_wifi);
	else
		lv_style_init(&style_header_symbol_wifi);
	lv_style_init(&style_header_symbol_wifi);
	lv_style_set_text_font(&style_header_symbol_wifi, &lv_font_montserrat_20);
	lv_style_set_text_color(&style_header_symbol_wifi, ESPUPM_COLOR_WHITE);
	lv_obj_add_style(ui->header_wifi, &style_header_symbol_wifi, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->header_wifi, LV_SYMBOL_WIFI);

	//Signal icon in header
	ui->header_signal = lv_label_create(screenobject);
	lv_obj_align_to(ui->header_signal, ui->header_wifi, LV_ALIGN_TOP_LEFT, -25, 2);
	static lv_style_t style_header_symbol_signal;
	if (style_header_symbol_signal.prop_cnt > 1)
		lv_style_reset(&style_header_symbol_signal);
	else
		lv_style_init(&style_header_symbol_signal);
	lv_style_init(&style_header_symbol_signal);
	lv_style_set_text_color(&style_header_symbol_signal, ESPUPM_COLOR_WHITE);
	lv_style_set_text_font(&style_header_symbol_signal, &signal_icon_16);
	lv_obj_add_style(ui->header_signal, &style_header_symbol_signal, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->header_signal, ESPUPM_SYMBOL_SIGNAL);
		/******************************
	 * Header Design End
	 *****************************/
}

/**
 * Function to  draw title for each screen
 * @param ui  pointer to a strcture of all objects
 * @param parentscreen pointer to the object of parent screen
 * @param txtlabel Name of screen
 * @param imgdata Image data pointer to display on right corner
 * @param bgcolor background coloer  of container to match with background of parentscreen
 */
void setup_draw_title(lv_ui *ui, lv_obj_t *parentscreen, char *txtlabel, const void *imgdata, lv_color_t bgcolor){
	//container for objects
	ui->title_container = lv_obj_create(parentscreen);
	lv_obj_clear_flag(ui->title_container, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_move_background(ui->title_container);
	lv_obj_align_to(ui->title_container, parentscreen, LV_ALIGN_TOP_LEFT, 0, 25);
	lv_obj_set_size(ui->title_container, SCREEN_WIDTH, 70);
	lv_obj_set_style_bg_color(ui->title_container, bgcolor, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->title_container, bgcolor, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->title_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Leftarrow button as a child of parametert_title object
	ui->title_leftarrow = lv_img_create(ui->title_container);
	lv_obj_set_size(ui->title_leftarrow, left_arrow_icon.header.w, left_arrow_icon.header.h);
	lv_img_set_src(ui->title_leftarrow, &left_arrow_icon);
	lv_obj_align_to(ui->title_leftarrow, ui->title_container, LV_ALIGN_LEFT_MID, 10 , 0);
	lv_obj_set_style_img_recolor_opa(ui->title_leftarrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->title_leftarrow, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);

	if(txtlabel != NULL){
		//Parameter text as a child of parametert_title object
		ui->title_label = lv_label_create(ui->title_container);
		lv_obj_center(ui->title_label);
		lv_obj_set_width(ui->title_label, 200);
		lv_obj_set_style_text_font(ui->title_label, &lv_font_montserrat_22_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_text_color(ui->title_label, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_text_align(ui->title_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(ui->title_label, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_label_set_text(ui->title_label, txtlabel);
		lv_label_set_long_mode(ui->title_label, LV_LABEL_LONG_WRAP);
	}

	if(imgdata != NULL){
		//Menusymbol as a child of parametert_title object
		ui->title_symbol = lv_img_create(ui->title_container);
		lv_img_set_src(ui->title_symbol, imgdata);
		lv_obj_align_to(ui->title_symbol, ui->title_container, LV_ALIGN_TOP_RIGHT, -10 , 15);
		lv_obj_set_style_img_recolor_opa(ui->title_symbol, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_recolor(ui->title_symbol, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	}
}

/**
 * Function to  draw sequence widget
 * @param parentobject pointer to parent object in which sequence widget to draw
 * @param labelobject pointer to label object to update sequence widget title
 * @param flowsetpointvalue pointer to label object to flow setpoint value
 * @param durationvalue  pointer to label object to duration value
 * @param problemvalue  pointer to label object to probelm value
 * @param buttonobject  pointer to button object
 */
void setup_draw_sequence_widget(lv_obj_t **parentobject, lv_obj_t **labelobject, lv_obj_t **flowsetpointvalue, lv_obj_t **durationvalue,
				lv_obj_t **problemvalue, lv_obj_t **buttonobject){
	static lv_obj_t *flowsetpointlabel;
	static lv_obj_t *durationlabel;
	static lv_obj_t *problemlabel;

	//title text for sequence widget
	*labelobject = lv_label_create(*parentobject);
	lv_obj_align_to(*labelobject, *parentobject, LV_ALIGN_TOP_LEFT, 5, 5);
	lv_obj_set_style_text_font(*labelobject, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(*labelobject, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(*labelobject, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(*labelobject, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(*labelobject, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(*labelobject, "SEQUENCE");

	//flowsetpoint text label
	flowsetpointlabel = lv_label_create(*parentobject);
	lv_obj_align_to(flowsetpointlabel, *parentobject, LV_ALIGN_TOP_LEFT, 15, 30);
	lv_obj_set_style_text_font(flowsetpointlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(flowsetpointlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(flowsetpointlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(flowsetpointlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(flowsetpointlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(flowsetpointlabel, "Flow Set Point:");

	//duration text label
	durationlabel = lv_label_create(*parentobject);
	lv_obj_align_to(durationlabel, flowsetpointlabel, LV_ALIGN_BOTTOM_LEFT, 0, 20);
	lv_obj_set_style_text_font(durationlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(durationlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(durationlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(durationlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(durationlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(durationlabel, "Duration:");

	//problem text label
	problemlabel = lv_label_create(*parentobject);
	lv_obj_align_to(problemlabel, durationlabel, LV_ALIGN_BOTTOM_LEFT, 0, 20);
	lv_obj_set_style_text_font(problemlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(problemlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(problemlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(problemlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(problemlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(problemlabel, "Problem:");

	//Label for flow setpoint value
	*flowsetpointvalue = lv_label_create(*parentobject);
	lv_obj_align_to(*flowsetpointvalue, *parentobject, LV_ALIGN_TOP_MID, 40, 30);
	lv_obj_set_style_text_font(*flowsetpointvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(*flowsetpointvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(*flowsetpointvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(*flowsetpointvalue, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(*flowsetpointvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(*flowsetpointvalue, "7 L/Min");

	//Label for duration value
	*durationvalue = lv_label_create(*parentobject);
	lv_obj_align_to(*durationvalue, *flowsetpointvalue, LV_ALIGN_BOTTOM_LEFT, 0, 20);
	lv_obj_set_style_text_font(*durationvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(*durationvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(*durationvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(*durationvalue, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(*durationvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(*durationvalue, "2 H");

	//Label for problem value
	*problemvalue = lv_label_create(*parentobject);
	lv_obj_align_to(*problemvalue, *durationvalue, LV_ALIGN_BOTTOM_LEFT, 0, 20);
	lv_obj_set_style_text_font(*problemvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(*problemvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(*problemvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(*problemvalue, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(*problemvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(*problemvalue, "None");

	//Design for button obect
	static lv_style_t style_sequencewidgetbutton;
	if (style_sequencewidgetbutton.prop_cnt > 1)
		lv_style_reset(&style_sequencewidgetbutton);
	else
		lv_style_init(&style_sequencewidgetbutton);
	lv_style_set_bg_color(&style_sequencewidgetbutton, ESPUPM_COLOR_GREEN);
	lv_style_set_bg_opa(&style_sequencewidgetbutton, LV_OPA_MAX);
	lv_style_set_border_opa(&style_sequencewidgetbutton, LV_OPA_MIN);
	lv_style_set_border_width(&style_sequencewidgetbutton, 0);
	lv_style_set_shadow_width(&style_sequencewidgetbutton, 0);
	lv_style_set_radius(&style_sequencewidgetbutton, 5);

	*buttonobject = lv_btn_create(*parentobject);
	lv_obj_align_to(*buttonobject, *parentobject, LV_ALIGN_TOP_RIGHT, -20, 0);
	lv_obj_set_size(*buttonobject, 50, 100);
	lv_obj_add_style(*buttonobject, &style_sequencewidgetbutton, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(*buttonobject, &style_sequencewidgetbutton, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(*buttonobject, &style_sequencewidgetbutton, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_t *buttonlabel = lv_label_create(*buttonobject);
	lv_obj_center(buttonlabel);
	lv_obj_set_style_text_font(buttonlabel, &lv_font_montserrat_40, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(buttonlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(buttonlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, LV_SYMBOL_NEXT);

}
/******************************************************************************
 *      END OF FILE
 *****************************************************************************/
