// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/*
 * custom.h
 *
 *  Created on: July 29, 2020
 *      Author: nxf53801
 */

#ifndef __CUSTOM_H_
#define __CUSTOM_H_

#include "../generated/gui_guider.h"

/*********************
 *      DEFINES
 *********************/
#define SCREEN_WIDTH			320
#define SCREEN_HEIGHT			480
#define SCREEN_MAX_OPACITY		255
#define SCREEN_MIN_OPACITY		0
#define SCREEN_HEADER_HEIGHT	50
#define SCREEN_MENU_BUTTON_HEIGHT	44
#define SCREEN_MENU_BUTTON_WIDTH	44

#define ESPUPM_SYMBOL_SIGNAL 	"\xEF\x80\x92"

#define ESPUPM_BACKGROUND_COLOR			lv_color_make(0x5D, 0x5D, 0x5D)
#define ESPUPM_COLOR_WHITE				lv_color_make(0xFF, 0xFF, 0xFF)
#define ESPUPM_COLOR_BLACK				lv_color_make(0x00, 0x00, 0x00)
#define ESPUPM_COLOR_LIGHT_BLUE		    lv_color_make(0x35, 0x9F, 0xE2)
#define ESPUPM_COLOR_BLUE				lv_color_make(0x39, 0x89, 0xBD)
#define ESPUPM_COLOR_DARK_GREY			lv_color_make(0x38, 0x38, 0x38)
#define ESPUPM_COLOR_MILKY				lv_color_make(0xB2, 0xB2, 0xB2)
#define ESPUPM_COLOR_GREEN				lv_color_make(0x56, 0xA7, 0x3D)
#define ESPUPM_COLOR_GREY				lv_color_make(0x70, 0x70, 0x70)
#define ESPUPM_COLOR_PURPLE				lv_color_make(0xA5, 0x5E, 0xEA)
#define ESPUPM_COLOR_LIGHT_PURPLE		lv_color_make(0xD3, 0x83, 0xFF)
#define ESPUPM_COLOR_YELLOW				lv_color_make(0xFE, 0xD3, 0x2F)
#define ESPUPM_COLOR_RED				lv_color_make(0xEB, 0x3B, 0x5A)
#define ESPUPM_COLOR_DARK_BLUE			lv_color_make(0x17, 0x27, 0x47)
#define ESPUPM_COLOR_ORANGE				lv_color_make(0xFA, 0x82, 0x23)
#define ESPUPM_COLOR_BLUE_RESUMEINFO	lv_color_make(0x38, 0x67, 0xD6)

LV_FONT_DECLARE(signal_icon_16);
LV_IMG_DECLARE(navier_logo);
LV_IMG_DECLARE(service_icon);
LV_IMG_DECLARE(archiv_icon);
LV_IMG_DECLARE(metrology_icon);
LV_IMG_DECLARE(parameter_icon);
LV_IMG_DECLARE(info_icon);
LV_IMG_DECLARE(left_arrow_icon);
LV_IMG_DECLARE(logo);
LV_IMG_DECLARE(logo_custom);
LV_IMG_DECLARE(led_icon);
LV_IMG_DECLARE(QRcode_logo);
LV_IMG_DECLARE(fan_icon);
LV_IMG_DECLARE(ok_icon);
LV_IMG_DECLARE(cross_icon);
LV_IMG_DECLARE(wifi_icon);
LV_IMG_DECLARE(sleep_icon);
LV_IMG_DECLARE(language_icon);
LV_IMG_DECLARE(timer_icon);
LV_IMG_DECLARE(luminosity_icon);
LV_IMG_DECLARE(contrast_icon);
LV_IMG_DECLARE(uparrow);
LV_IMG_DECLARE(downarrow);
LV_IMG_DECLARE(rightalert);
LV_IMG_DECLARE(wrongalert);
LV_IMG_DECLARE(envparameter);
LV_IMG_DECLARE(statics);
LV_IMG_DECLARE(temperature);
LV_IMG_DECLARE(icon_menu);
LV_IMG_DECLARE(research_icon);
LV_IMG_DECLARE(battery_icon);
/**********************
 *      TYPEDEFS
 **********************/
typedef enum{
    SCR_SLEEP,
    SCR_LOGO,
    SCR_DASHBOARD,
	SCR_DASHBOARD_BLUE,
    SCR_PASSWORD,
    SCR_PASSWORD_BLUE,
	SCR_PASSWORD_METROLOGY_CODE,
	SCR_PRESET_SCENARIO,
	SCR_PRESET_SCENARIO_BLUE,
	SCR_PRESET_SEQUENCE,
	SCR_PRESET_SEQUENCE_BLUE,
	SCR_SUMMARY_START,
	SCR_SUMMARY_START_BLUE,
	SCR_SUMMARY_END,
	SCR_SUMMARY_END_BLUE,
	SCR_SUMMARY_END_SINGLEWIDGET,
	SCR_SUMMARY_END_SINGLEWIDGET_BLUE,
	SCR_SUMMARY_ARCHIV,
	SCR_SUMMARY_ARCHIV_BLUE,
	SCR_SUMMARY_ARCHIV_SINGLEWIDGET,
	SCR_SUMMARY_ARCHIV_SINGLEWIDGET_BLUE,
	SCR_SUMMARY_SAMPLE_SEQUENCE_01_02,
	SCR_SUMMARY_SAMPLE_SEQUENCE_02_02,
	SCR_SUMMARY_SAMPLE_SEQUENCE_01_01,
	SCR_SUMMARY_SAMPLE_SEQUENCE_01_01_BLUE,
	SCR_SUMMARY_SAMPLE_SEQUENCE_01_02_BLUE,
	SCR_PARAMETER,
	SCR_INFO,
	SCR_FLOW_PARAMETER,
	SCR_METROLOGY_MENU,
	SCR_METROLOGY_CALIBRATION_FLOW,
	SCR_METROLOGY_CALIBRATION_PRESSURE,
	SCR_METROLOGY_CALIBRATION_TEMPERATURE,
	SCR_METROLOGY_CALIBRATION_HUMIDITY,
	SCR_METROLOGY_SETTINGS_FLOW,
	SCR_METROLOGY_SETTINGS_PRESSURE,
	SCR_METROLOGY_SETTINGS_TEMPERATURE,
	SCR_METROLOGY_SETTINGS_HUMIDITY,
	SCR_METROLOGY_SERVICE,
	SCR_ALERT_MESSAGE_STABLIZATION,
	SCR_ALERT_MESSAGE_CALIBRATION_SUCCESS,
	SCR_ALERT_MESSAGE_CALIBRATION_FAIL,
	SCR_ALERT_MESSAGE_PASSWORD_MODIFIED_SUCCESS,
	SCR_ALERT_MESSAGE_WRONG_PASSWORD,
	SCR_ALERT_MESSAGE_UNPLUG_FILTER,
	SCR_METROLOGY_CALIBRATE_SETPOINT_FLOW,
	SCR_TEST,
}screen_id_e;

typedef enum{
	WORK_IN_PROGRESS = 0,
	JOB_FINISHED = 1,
	READY = 2,
	WAIT_IN_PROGRESS = 3,
	METROLOGY_NEEDED = 4,
	ALERT_SERVICE = 5,
	EXPORT_DATA = 6,
	METROLOGY_INPROGRESS = 7,
}resumeinfoStat_e;
/**********************
 *      GLOBAL FUNCTIONS
 **********************/
void custom_init(lv_ui *ui);
void guider_load_screen(int scr_id);
void setup_draw_header(lv_ui *ui, lv_obj_t *screenobject);
void setup_draw_title(lv_ui *ui, lv_obj_t *parentscreen, char *txtlabel, const void *imgdata, lv_color_t bgcolor);
void setup_draw_sequence_widget(lv_obj_t **parentobject, lv_obj_t **labelobject, lv_obj_t **flowsetpointvalue, lv_obj_t **durationvalue,
				lv_obj_t **problemvalue, lv_obj_t **buttonobject);

/**password screen**/
void custom_passwordscreen_setup(screen_id_e screenid);
void on_passwordscreen_passwordkey_btnreleased(lv_obj_t *e);

/**dashboard screen api**/
void custom_dashboardscreen_setup(screen_id_e screenid);
void on_dashboard_menu_buttonreleased(void);
void on_dashboard_service_buttonreleased(void);
void on_dashboard_info_buttonreleased(void);
void on_dashboard_archiv_buttonreleased(void);
void on_dashboard_metrology_buttonreleased(void);
void on_dashboard_startstop_buttonreleased(void);
void on_dashboard_parameter_buttonreleased(void);
void setter_dashboard_welcomelabel(char *str);
void setter_dashboard_datelabel(char *str);
void setter_dashboard_resumeinfo_currentstatus(char *str);
void setter_dashboard_resumeinfo_percentagetext(char *str, bool percentageymbolenable);
void setter_dashboard_resumeinfo_time_label(char *str);
void setter_dashboard_resumeinfo_sequence_label(char *str);
void setter_dashboard_resumeinfo_totalhourintlabel(uint32_t intval, int rem);
void setter_dashboard_resumeinfo_totalliterintlabel(uint32_t intval, int rem);
void setter_dashboard_chart(lv_coord_t *dashboard_chart_arr_val, uint8_t len);
void setter_dashboard_envparameter_temperature(float tempvalue);
void setter_dashboard_envparameter_pressure(float pressurevalue);
void setter_dashboard_envparameter_humidity(int humidityvalue);
void setter_dashboard_prochain_text(char *str);
void setter_dashboard_prochain_status(bool status);
void setter_dashboard_battery_text(char *str);
void setter_dashboard_battery_status(bool status);
void setter_dashboard_reseau_status(bool status);
void setter_dashboard_reseau_text(char *str);
void setter_dashboard_metrologies_text(char *str);
void setter_dashboard_metrology_status(bool status);
void setter_dashboard_statistic_text(char *str);
void setter_dashboard_statstics_status(bool status);
void update_resumeinfowidget(resumeinfoStat_e statid);

/****Preset scenario control API*****/
void custom_presetscenario_screen_setup(screen_id_e screenid);
void on_preset_scenario_back_buttonreleased(void);
void on_preset_scenario_plus_buttonreleased(void);
void on_preset_scenario_valid_buttonreleased(void);
void setter_preset_scenario_startnowHvalue_0(char *str);
void setter_preset_scenario_startnowHvalue_1(char *str);
void setter_preset_scenario_startnowHvalue_2(char *str);
void setter_preset_scenario_startnowLPMvalue_0(char *str);
void setter_preset_scenario_startnowLPMvalue_1(char *str);
void setter_preset_scenario_startnowLPMvalue_2(char *str);
void setter_preset_scenario_startlaterHvalue_0(char *str);
void setter_preset_scenario_startlaterHvalue_1(char *str);
void setter_preset_scenario_startlaterHvalue_2(char *str);
void setter_preset_scenario_startlaterLPMvalue_0(char *str);
void setter_preset_scenario_startlaterLPMvalue_1(char *str);
void setter_preset_scenario_startlaterLPMvalue_2(char *str);

/****Preset Sequence control API***/
void custom_presetsequence_screen_setup(screen_id_e screenid);
void on_preset_sequence_back_btnreleased(void);
void on_preset_sequence_calender_valuechanged(void);
void on_preset_sequence_starthour_valuechanged(void);
void on_preset_sequence_startminute_valuechanged(void);
void on_preset_sequence_durationhour_valuechanged(void);
void on_preset_sequence_durationminute_valuechanged(void);
void on_preset_sequence_setpoint_valuechanged(void);
void on_preset_sequence_valid_btnreleased(void);
void on_preset_sequence_add_btnreleased(void);
void setter_preset_sequence_calender_today_date(uint16_t year, uint8_t month, uint8_t day);
void setter_preset_sequence_calender_show_date(uint16_t year, uint8_t month);
void setter_preset_sequence_dateselectedlabel(char *str);
void setter_preset_sequence_starthourroller(uint16_t num);
void setter_preset_sequence_startminuteroller(uint16_t num);
void setter_preset_sequence_durationhourroller(uint16_t num);
void setter_preset_sequence_durationminuteroller(uint16_t num);
void setter_preset_sequence_setpointroller(uint16_t num);


/****Summary start control APIs*****/
void custom_summarystart_screen_setup(screen_id_e screenid);
void on_summarystart_back_buttonreleased(void);
void on_summarystart_startjob_buttonreleased(void);
void setter_summary_start_startdatevalue(char *str);
void setter_summary_start_startdurationvalue(char *str);
void setter_summary_start_stopdatevalue(char *str);
void setter_summary_start_stopdurationvalue(char *str);
void setter_summary_start_samplelabel(char *str);
void setter_summary_start_flowsetpointvalue(int val);
void setter_summary_start_sequencenumbervalue(int val);
void setter_summary_start_durationvalue(int val);
void setter_summary_start_startpersonvalue(char *str);
void setter_summary_start_litercountervalue(uint32_t val);
void setter_summary_start_hourcountervalue(uint32_t val);


/****Summary end control APIs******/
void custom_summaryend_screen_setup(screen_id_e screenid);
void on_summaryend_previous_buttonreleased(void);
void on_summaryend_next_buttonreleased(void);
void on_summaryend_exportusb_buttonreleased(void);
void on_summaryend_quit_buttonreleased(void);
void on_summaryend_sequencewidget1_buttonreleased(void);
void on_summaryend_sequencewidget2_buttonreleased(void);
void on_summaryend_back_buttonreleased(void);
void setter_summaryend_samplelabel(char *str);
void setter_summaryend_datestart(char *str);
void setter_summaryend_startduration(char *str);
void setter_summaryend_containertitle(char *str);
void setter_summaryend_flowsetpointvalue(int val);
void setter_summaryend_sequencenumbervalue(int val);
void setter_summaryend_durationvalue(int val);
void setter_summaryend_startvalue(char *str);
void setter_summaryend_endbyvalue(char *str);
void setter_summaryend_startpersonvalue(char *str);
void setter_summaryend_endpersonvalue(char *str);
void setter_summaryend_problemvalue(char *str);
void setter_summaryend_volumestartvalue(uint32_t val);
void setter_summaryend_volumestopvalue(uint32_t val);
void setter_summaryend_volumetargetvalue(uint32_t val);
void setter_summaryend_volumeeffectivevalue(uint32_t val);
void setter_summaryend_volumevariationvalue(float val);
void setter_summaryend_hourstartvalue(char *str);
void setter_summaryend_hourstopvalue(char *str);
void setter_summaryend_hourtargetvalue(char *str);
void setter_summaryend_houreffectivevalue(char *str);
void setter_summaryend_hourvariationvalue(float val);
void setter_summaryend_sequencewidgetcontainer1_flowsetpoint(int val);
void setter_summaryend_sequencewidgetcontainer1_durationvalue(int val);
void setter_summaryend_sequencewidgetcontainer1_problemvalue(char *str);
void setter_summaryend_sequencewidgetcontainer2_flowsetpoint(int val);
void setter_summaryend_sequencewidgetcontainer2_durationvalue(int val);
void setter_summaryend_sequencewidgetcontainer2_problemvalue(char *str);

/****Summary sample control APIs*****/
void custom_summarysample_screen_setup(screen_id_e screenid);
void on_summarysample_quit_btnreleased(void);
void on_summarysample_back_btnreleased(void);
void on_summarysample_next_btnreleased(void);
void on_summarysample_prev_btnreleased(void);
void setter_summary_sample_label(uint8_t cur_seq, uint8_t max_seq);
void setter_summary_sample_datestartvalue(char *str);
void setter_summary_sample_datestopvalue(char *str);
void setter_summary_sample_volumestartvalue(uint32_t val);
void setter_summary_sample_volumestopvalue(uint32_t val);
void setter_summary_sample_volumetargetvalue(uint32_t val);
void setter_summary_sample_volumeeffectivevalue(uint32_t val);
void setter_summary_sample_volumevariationvalue(float val);
void setter_summary_sample_hourstartvalue(char *str);
void setter_summary_sample_hourstopvalue(char *str);
void setter_summary_sample_hourtargetvalue(char *str);
void setter_summary_sample_houreffectivevalue(char *str);
void setter_summary_sample_hourvariationvalue(float val);
void setter_summary_sample_airflow_volumetric_cont(uint32_t setpointval, uint32_t meanvalue, uint32_t maxvalue, bool maxarrow,
                                                   uint32_t minvalue, bool minarrow, float variationval);
void setter_summary_sample_ambient_temp_cont(char * limitvaluestr, uint32_t meanvalue, uint32_t maxvalue, bool maxarrow,
                                                   uint32_t minvalue, bool minarrow, float variationval);
void setter_summary_sample_ambient_pressure_cont(char * limitvaluestr, uint32_t meanvalue, uint32_t maxvalue, bool maxarrow,
                                                   uint32_t minvalue, bool minarrow, float variationval);
void setter_summary_sample_ambient_humidity_cont(char * limitvaluestr, uint32_t meanvalue, uint32_t maxvalue, bool maxarrow,
                                                   uint32_t minvalue, bool minarrow, float variationval);
void setter_summary_sample_head_loss_cont(char * limitvaluestr, uint32_t meanvalue, uint32_t maxvalue, bool maxarrow,
                                                   uint32_t minvalue, bool minarrow, float variationval);

/****Flow sensor parameter screen control API***/
void on_flowsensor_par_back_buttonreleased(void);
void on_flowsensor_par_erasebuttonreleased(void);
void setter_flow_sensor_duration(char *str);
void setter_flow_sensor_par_startdate(char *str);
void setter_flow_sensor_par_label_point_number(int val);
void setter_flow_sensor_par_label_global_accuracy(float val);
void setter_flow_sensor_par_label_hour_counter(uint32_t val);
void setter_flow_sensor_par_label_volume_counter(uint32_t val);
void setter_flow_sensor_par_label_curve(int val);
void setter_flow_sensor_par_label_unit(char *str);
void setter_flow_sensor_par_label_lower_limit(char *str);
void setter_flow_sensor_par_label_point_higher_limit(char *str);
void setter_flow_sensor_par_label_limit_alert(char *str);
void setter_flow_sensor_par_label_after_limit_alert(char *str);
void setter_flowsensor_par_chart(lv_coord_t *dashboard_chart_arr_val, uint8_t len);
void setter_flow_sensor_par_cont_point_factory_val(uint8_t point_num, uint32_t val);
void setter_flow_sensor_par_cont_point_comp_val(uint8_t point_num, uint32_t val);
void setter_flow_sensor_par_cont_point_accuracy(uint8_t point_num, float val);

/**Metrology calibration screen control API**/
void custom_metrologycalibration_screen_setup(screen_id_e screenid);
void on_metrologycal_keyboard_buttonreleased(lv_obj_t *e);
void on_metrologycal_valid_buttonreleased(void);
void setter_metrology_calibration_pointlabel(char *str);
void setter_metrology_calibration_countlabel(char *str);
void setter_metrology_calibration_pointvalue(int val);
void setter_metrology_calibration_countvalue(char *str);

/****Metroloy Menu control APIs*****/
void on_metrologymenu_changepassword_btnreleased(void);
void on_metrologymenu_newvalidation_btnreleased(void);
void on_metrologymenu_calibration_btnreleased(void);
void on_metrologymenu_setservice_btnreleased(void);
void on_metrologymenu_back_btnreleased(void);
void on_metrologymenu_sequencewidget_btnreleased(void);
void setter_metrology_menu_sequencecontainer_flowsetpointvalue(int val);
void setter_metrology_menu_sequencecontainer_durationvalue(int val);
void setter_metrology_menu_sequencecontainer_problemvalue(char *str);

/*****Info Screen Control API*****/
void on_infoscreen_back_buttonreleased(void);

/*****Metrology Settings Control APIS****/
void custom_metrologysettings_screen_setup(screen_id_e screenid);
void on_metrologysettings_back_buttonreleased(void);
void on_metrologysettings_curved_valuechanged(void);
void on_metrologysettings_unit_valuechanged(void);
void on_metrologysettings_alertsetpoint_valuechanged(void);
void on_metrologysettings_lowerlimit_valuechanged(void);
void on_metrologysettings_higherlimit_valuechanged(void);
void on_metrologysettings_actoinswitch_valuechanged(void);
void on_metrologysettings_validadjust_btnreleased(void);
void setter_metrology_settings_curvedropdown(uint16_t num);
void setter_metrology_settings_unitdropdown(uint16_t num);
void setter_metrology_settings_alertcontainerswitch(bool switch_status);
void setter_metrology_settings_lowerlimitdropdown(uint16_t num);
void setter_metrology_settings_higherlimitdropdown(uint16_t num);
void setter_metrology_settings_actionswitch(bool switch_status);




/****Parameter Screen control API*****/
void on_parameter_backbutton_released(void);
void on_parameter_buzzer_valuechanged(void);
void on_parameter_led_valuechanged(void);
void on_parameter_wifi_valuechanged(void);
void on_parameter_externalfan_valuechanged(void);
void on_parameter_sleep_valuechanged(void);
void on_parameter_language_valuechanged(void);
void on_parameter_sleeptimer_valuechanged(void);
void on_parameter_luminosity_valuechanged(void);
void on_parameter_contrast_valuechanged(void);
void setter_parameter_buzzerswitch(bool switch_status);
void setter_parameter_ledswitch(bool switch_status);
void setter_parameter_wifiswitch(bool switch_status);
void setter_parameter_fanswitch(bool switch_status);
void setter_parameter_sleepswitch(bool switch_status);
void setter_parameter_languagedropdown(uint16_t num);
void setter_parameter_sleeptimerdropdown(uint16_t num);
void setter_parameter_luminosityslider(uint8_t val);
void setter_parameter_contrastslider(uint8_t val);

/****Metrology service screen control API*****/
void on_metrology_service_backbutton_released(void);
void on_metrology_service_hourservice_alertswitch_valuechanged(void);
void on_metrology_service_hourservice_inbutton_released(void);
void on_metrology_service_hourservice_alertdropdown_valuechanged(void);
void on_metrology_service_hourservice_actionswitch_valuechanged(void);
void on_metrology_service_dateservice_alertswitch_valuechanged(void);
void on_metrology_service_dateservice_inbutton_released(void);
void on_metrology_service_dateservice_alertdropdown_valuechanged(void);
void on_metrology_service_dateservice_actionswitch_valuechanged(void);
void on_metrology_service_volumeservice_alertswitch_valuechanged(void);
void on_metrology_service_volumeservice_inbutton_released(void);
void on_metrology_service_volumeservice_alertdropdown_valuechanged(void);
void on_metrology_service_volumeservice_actionswitch_valuechanged(void);
void on_metrology_service_filterservice_alertswitch_valuechanged(void);
void on_metrology_service_filterservice_inbutton_released(void);
void on_metrology_service_filterservice_alertdropdown_valuechanged(void);
void on_metrology_service_filterservice_actionswitch_valuechanged(void);
void on_metrology_service_filtertest_buttonreleased(void);
void setter_metrology_service_hourservicealertswitch(bool switch_status);
void setter_metrology_service_hourserviceinvalue(int val);
void setter_metrology_service_hourserivealertdropdown(uint16_t num);
void setter_metrology_service_hourseriveactionswitch(bool switch_status);
void setter_metrology_service_dateservicealertswitch(bool switch_status);
void setter_metrology_service_dateserviceinvalue(char *str);
void setter_metrology_service_dateservicealertdropdown(uint16_t num);
void setter_metrology_service_dateserviceactionswitch(bool switch_status);
void setter_metrology_service_volumeservicealertswitch(bool switch_status);
void setter_metrology_service_volumeserviceinvalue(uint32_t val);
void setter_metrology_service_volumeservicealertdropdown(uint16_t num);
void setter_metrology_service_volumeserviceactionswitch(bool switch_status);
void setter_metrology_service_filterservicealertswitch(bool switch_status);
void setter_metrology_service_filterserviceinvalue(uint8_t val);
void setter_metrology_service_filterserivealertdropdown(uint16_t num);
void setter_metrology_service_filterserviceactionswitch(bool switch_status);

/*****ALert message control API*********/
void custom_alertmessage_screen_setup(screen_id_e screenid);


#endif /* EVENT_CB_H_ */
