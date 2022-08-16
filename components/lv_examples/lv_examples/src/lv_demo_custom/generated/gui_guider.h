/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "guider_fonts/guider_fonts.h"

typedef struct
{
	lv_obj_t *header_timelabel;
	lv_obj_t *header_battery;
	lv_obj_t *header_wifi;
	lv_obj_t *header_signal;
	lv_obj_t *title_container;
	lv_obj_t *title_leftarrow;
	lv_obj_t *title_label;
	lv_obj_t *title_symbol;

	lv_obj_t *sleep;
	lv_obj_t *sleep_background;

	lv_obj_t *screen_logo;
	lv_obj_t *logo_mainimage;
	lv_obj_t *logo_customerimage;

	lv_obj_t *password;
	lv_obj_t *password_background;
	lv_obj_t *password_label;
	lv_obj_t *password_keyboard_digit[12];
	lv_obj_t *password_enter_num_label[4];
	lv_obj_t *password_status_symbol;

	lv_obj_t *dashboard;
	lv_obj_t *dashboard_background;
	lv_obj_t *dashboard_menubutton;
	lv_obj_t *dashboard_menubuttonlabel;
	lv_obj_t *dashboard_welcomelabel;
	lv_obj_t *dashboard_datelabel;
	lv_obj_t *dashboard_stopbutton;
	lv_obj_t *dashboard_resumeinfo_currentstatus;
	lv_obj_t *dashboard_resumeinfo_arcinner;
	lv_obj_t *dashboard_resumeinfo_arcouter;
	lv_obj_t *dashboard_resumeinfo_percentagetext;
	lv_obj_t *dashboard_resumeinfo_time_label;
	lv_obj_t *dashboard_resumeinfo_sequence_label;
	lv_obj_t *dashboard_resumeinfo_messagelabel;
	lv_obj_t *dashboard_resumeinfo_percentageymboltext;
	lv_obj_t *dashboard_resumeinfo_totalliterintlabel;
	lv_obj_t *dashboard_resumeinfo_totalliterfloatlabel;
	lv_obj_t *dashboard_resumeinfo_totalhourintlabel;
	lv_obj_t *dashboard_resumeinfo_totalhourfloatlabel;
	lv_obj_t *dashboard_menuview;
	lv_obj_t *dashboard_menuviewnavierlogo;
	lv_obj_t *dashboard_menuviewservicebutton;
	lv_obj_t *dashboard_menuviewinfobutton;
	lv_obj_t *dashboard_menuviewarchievebutton;
	lv_obj_t *dashboard_menuviewmetrologybutton;
	lv_obj_t *dashboard_menuviewparameterbutton;
	lv_obj_t *dashboard_chartwidget;
	lv_obj_t *dashboard_chart;
	lv_chart_series_t *dashboard_ser;
	lv_obj_t *dashboard_envparameter_status;
	lv_obj_t *dashboard_envparameter_temperature;
	lv_obj_t *dashboard_envparameter_pressure;
	lv_obj_t *dashboard_envparameter_humidity;
	lv_obj_t *dashboard_prochain_status;
	lv_obj_t *dashboard_prochain_status_filter;
	lv_obj_t *dashboard_statofbattery_status;
	lv_obj_t *dashboard_statofbattery_parameter;
	lv_obj_t *dashboard_reserach_status;
	lv_obj_t *dashboard_reserach_status_parameter;
	lv_obj_t *dashboard_metrogies_status;
	lv_obj_t *dashboard_metrologies_status_parameter;
	lv_obj_t *dashboard_stastics_status;
	lv_obj_t *dashboard_stastics_status_parameter;

	lv_obj_t *summary_start;
	lv_obj_t *summary_start_background;
	lv_obj_t *summary_start_container;
	lv_obj_t *summary_start_startdatevalue;
	lv_obj_t *summary_start_startdurationvalue;
	lv_obj_t *summary_start_stopdatevalue;
	lv_obj_t *summary_start_stopdurationvalue;
	lv_obj_t *summary_start_samplelabel;
	lv_obj_t *summary_start_flowsetpointvalue;
	lv_obj_t *summary_start_sequencenumbervalue;
	lv_obj_t *summary_start_durationvalue;
	lv_obj_t *summary_start_startpersonvalue;
	lv_obj_t *summary_start_litercountervalue;
	lv_obj_t *summary_start_hourcountervalue;
	lv_obj_t *summary_btn_startjob;

	lv_obj_t *summaryend;
	lv_obj_t *summaryend_background;
	lv_obj_t *summaryend_previousnext_buttoncontainer;
	lv_obj_t *summaryend_nextbutton;
	lv_obj_t *summaryend_previousbutton;
	lv_obj_t *summaryend_samplelabel;
	lv_obj_t *summaryend_statussymbol;
	lv_obj_t *summaryend_samplecontainer;
	lv_obj_t *summaryend_datestart;
	lv_obj_t *summaryend_startduration;
	lv_obj_t *summaryend_datestop;
	lv_obj_t *summaryend_stopduration;
	lv_obj_t *summaryend_containertitle;
	lv_obj_t *summaryend_flowsetpointvalue;
	lv_obj_t *summaryend_sequencenumbervalue;
	lv_obj_t *summaryend_durationvalue;
	lv_obj_t *summaryend_startvalue;
	lv_obj_t *summaryend_endbyvalue;
	lv_obj_t *summaryend_startpersonvalue;
	lv_obj_t *summaryend_endpersonvalue;
	lv_obj_t *summaryend_problemvalue;
	lv_obj_t *summaryend_volumestartvalue;
	lv_obj_t *summaryend_volumestopvalue;
	lv_obj_t *summaryend_volumetargetvalue;
	lv_obj_t *summaryend_volumeeffectivevalue;
	lv_obj_t *summaryend_volumevariationvalue;
	lv_obj_t *summaryend_hourstartvalue;
	lv_obj_t *summaryend_hourstopvalue;
	lv_obj_t *summaryend_hourtargetvalue;
	lv_obj_t *summaryend_houreffectivevalue;
	lv_obj_t *summaryend_hourvariationvalue;
	lv_obj_t *summaryend_horizantalline;
	lv_obj_t *summaryend_sequencewidgetcontainer1;
	lv_obj_t *summaryend_sequencewidgetcontainer1_label;
	lv_obj_t *summaryend_sequencewidgetcontainer1_flowsetpoint;
	lv_obj_t *summaryend_sequencewidgetcontainer1_durationvalue;
	lv_obj_t *summaryend_sequencewidgetcontainer1_problemvalue;
	lv_obj_t *summaryend_sequencewidgetcontainer1_button;
	lv_obj_t *summaryend_sequencewidgetcontainer2;
	lv_obj_t *summaryend_sequencewidgetcontainer2_label;
	lv_obj_t *summaryend_sequencewidgetcontainer2_flowsetpoint;
	lv_obj_t *summaryend_sequencewidgetcontainer2_durationvalue;
	lv_obj_t *summaryend_sequencewidgetcontainer2_problemvalue;
	lv_obj_t *summaryend_sequencewidgetcontainer2_button;
	lv_obj_t *summaryend_exportusb;
	lv_obj_t *summaryend_quit;

	lv_obj_t *summary_sample;
	lv_obj_t *summary_sample_background;
	lv_obj_t *summary_sample_previousnext_buttoncontainer;
	lv_obj_t *summary_sample_nextbutton;
	lv_obj_t *summary_sample_previousbutton;
	lv_obj_t *summary_sample_label;
	lv_obj_t *summary_sample_sequencesummary_container;
	lv_obj_t *summary_sample_statussymbol;
	lv_obj_t *summary_sample_datestartvalue;
	lv_obj_t *summary_sample_datestopvalue;
	lv_obj_t *summary_sample_volumestartvalue;
	lv_obj_t *summary_sample_volumestopvalue;
	lv_obj_t *summary_sample_volumetargetvalue;
	lv_obj_t *summary_sample_volumeeffectivevalue;
	lv_obj_t *summary_sample_volumevariationvalue;
	lv_obj_t *summary_sample_hourstartvalue;
	lv_obj_t *summary_sample_hourstopvalue;
	lv_obj_t *summary_sample_hourtargetvalue;
	lv_obj_t *summary_sample_houreffectivevalue;
	lv_obj_t *summary_sample_hourvariationvalue;
	lv_obj_t *summary_sample_airflow_namevalue;
	lv_obj_t *summary_sample_airflow_setpointvalue;
	lv_obj_t *summary_sample_airflow_meanvalue;
	lv_obj_t *summary_sample_airflow_maxvalue;
	lv_obj_t *summary_sample_airflow_maxvaluearrow;
	lv_obj_t *summary_sample_airflow_minvalue;
	lv_obj_t *summary_sample_airflow_minvaluearrow;
	lv_obj_t *summary_sample_airflow_variationvalue;
	lv_obj_t *summary_sample_ambienttemperature_namevalue;
	lv_obj_t *summary_sample_ambienttemperature_limitvalue;
	lv_obj_t *summary_sample_ambienttemperature_meanvalue;
	lv_obj_t *summary_sample_ambienttemperature_maxvalue;
	lv_obj_t *summary_sample_ambienttemperature_maxvaluearrow;
	lv_obj_t *summary_sample_ambienttemperature_minvalue;
	lv_obj_t *summary_sample_ambienttemperature_minvaluearrow;
	lv_obj_t *summary_sample_ambienttemperature_variationvalue;
	lv_obj_t *summary_sample_ambientpressure_namevalue;
	lv_obj_t *summary_sample_ambientpressure_limitvalue;
	lv_obj_t *summary_sample_ambientpressure_meanvalue;
	lv_obj_t *summary_sample_ambientpressure_maxvalue;
	lv_obj_t *summary_sample_ambientpressure_maxvaluearrow;
	lv_obj_t *summary_sample_ambientpressure_minvalue;
	lv_obj_t *summary_sample_ambientpressure_minvaluearrow;
	lv_obj_t *summary_sample_ambientpressure_variationvalue;
	lv_obj_t *summary_sample_ambienthumidity_namevalue;
	lv_obj_t *summary_sample_ambienthumidity_limitvalue;
	lv_obj_t *summary_sample_ambienthumidity_meanvalue;
	lv_obj_t *summary_sample_ambienthumidity_maxvalue;
	lv_obj_t *summary_sample_ambienthumidity_maxvaluearrow;
	lv_obj_t *summary_sample_ambienthumidity_minvalue;
	lv_obj_t *summary_sample_ambienthumidity_minvaluearrow;
	lv_obj_t *summary_sample_ambienthumidity_variationvalue;
	lv_obj_t *summary_sample_headloss_namevalue;
	lv_obj_t *summary_sample_headloss_limitvalue;
	lv_obj_t *summary_sample_headloss_meanvalue;
	lv_obj_t *summary_sample_headloss_maxvalue;
	lv_obj_t *summary_sample_headloss_maxvaluearrow;
	lv_obj_t *summary_sample_headloss_minvalue;
	lv_obj_t *summary_sample_headloss_minvaluearrow;
	lv_obj_t *summary_sample_headloss_variationvalue;
	lv_obj_t *summary_sample_quitbutton;


	lv_obj_t *parameter;
	lv_obj_t *parameter_background;
	lv_obj_t *parameter_settingscontainer;
	lv_obj_t *parameter_buzzercontainer;
	lv_obj_t *parameter_buzzerswitch;
	lv_obj_t *parameter_ledcontainer;
	lv_obj_t *parameter_ledswitch;
	lv_obj_t *parameter_wificontainer;
	lv_obj_t *parameter_wifiswitch;
	lv_obj_t *parameter_fancontainer;
	lv_obj_t *parameter_fanswitch;
	lv_obj_t *parameter_sleepcontainer;
	lv_obj_t *parameter_sleepswitch;
	lv_obj_t *parameter_languagecontainer;
	lv_obj_t *parameter_languagedropdown;
	lv_obj_t *parameter_sleeptimercontainer;
	lv_obj_t *parameter_sleeptimerdropdown;
	lv_obj_t *parameter_luminositycontainer;
	lv_obj_t *parameter_luminosityslider;
	lv_obj_t *parameter_contrastcontainer;
	lv_obj_t *parameter_contrastslider;

	lv_obj_t *flow_sensor_par;
	lv_obj_t *flow_sensor_par_background;
	lv_obj_t *flow_sensor_par_cont_data;
	lv_obj_t *flow_sensor_par_startdate_value;
	lv_obj_t *flow_sensor_par_duration_value;
	lv_obj_t *flow_sensor_par_label_point_number;
	lv_obj_t *flow_sensor_par_label_global_accuracy;
	lv_obj_t *flow_sensor_par_label_hour_counter;
	lv_obj_t *flow_sensor_par_label_volume_counter;
	lv_obj_t *flow_sensor_par_label_curve;
	lv_obj_t *flow_sensor_par_label_unit;
	lv_obj_t *flow_sensor_par_label_lower_limit;
	lv_obj_t *flow_sensor_par_label_higher_limit;
	lv_obj_t *flow_sensor_par_label_limit_alert;
	lv_obj_t *flow_sensor_par_label_after_limit_alert;
	lv_obj_t *flow_sensor_par_cont_point_factory_val[4];
	lv_obj_t *flow_sensor_par_cont_point_comp_val[4];
	lv_obj_t *flow_sensor_par_cont_point_accuracy[4];
	lv_obj_t *flow_sensor_par_cont_point_ok_icon[4];
	lv_obj_t *flow_sensor_par_cont_point_cancle_icon[4];
	lv_obj_t *flow_sensor_par_cont_btn_erase;
	lv_obj_t *flow_sensor_par_cont_chart;
	lv_obj_t *flow_sensor_par_chart;
	lv_obj_t *flow_sensor_equationvalue;
	lv_obj_t *flow_sensor_regression_factorvalue;
	lv_chart_series_t * flow_sensor_par_ser;


	lv_obj_t *info;
	lv_obj_t *info_background;
	lv_obj_t *info_qrcodecontainer;
	lv_obj_t *info_devicenumberlabel;
	lv_obj_t *info_devicenumberlabelvalue;
	lv_obj_t *info_labnamelabel;
	lv_obj_t *info_labnamelabelvalue;
	lv_obj_t *info_deviceidlabel;
	lv_obj_t *info_deviceidlabelvalue;
	lv_obj_t *info_qrcodeimage;

	lv_obj_t *metrology_menu;
	lv_obj_t *metrology_menu_background;
	lv_obj_t *metrology_menu_buttoncontainer;
	lv_obj_t *metrology_menu_changepassword;
	lv_obj_t *metrology_menu_setservice;
	lv_obj_t *metrology_menu_calibration;
	lv_obj_t *metrology_menu_newvalidationtest;
	lv_obj_t *metrology_menu_sequencecontainer;
	lv_obj_t *metrology_menu_sequencecontainer_label;
	lv_obj_t *metrology_menu_sequencecontainer_flowsetpointvalue;
	lv_obj_t *metrology_menu_sequencecontainer_durationvalue;
	lv_obj_t *metrology_menu_sequencecontainer_problemvalue;
	lv_obj_t *metrology_menu_sequencecontainer_button;


	lv_obj_t *metrology_settings;
	lv_obj_t *metrology_settings_background;
	lv_obj_t *metrology_settings_curve_unitcontainer;
	lv_obj_t *metrology_settings_curvedropdown;
	lv_obj_t *metrology_settings_unitdropdown;
	lv_obj_t *metrology_settings_alertcontainer;
	lv_obj_t *metrology_settings_alertcontainerswitch;
	lv_obj_t *metrology_settings_lowerlimitdropdown;
	lv_obj_t *metrology_settings_higherlimitdropdown;
	lv_obj_t *metrology_settings_actionswitch;
	lv_obj_t *metrology_settings_validadjustbutton;

	lv_obj_t *metrology_calibration;
	lv_obj_t *metrology_calibration_background;
	lv_obj_t *metrology_calibration_pointlabel;
	lv_obj_t *metrology_calibration_pointvalue;
	lv_obj_t *metrology_calibration_countlabel;
	lv_obj_t *metrology_calibration_countvalue;
	lv_obj_t *metrology_calibration_keypadtxtarea;
	lv_obj_t *metrology_calibration_validbutton;
	lv_obj_t *metrology_calibration_correction;
	lv_obj_t *metrology_calibration_keyboard_digit[12];

	lv_obj_t *metrology_service;
	lv_obj_t *metrology_service_background;
	lv_obj_t *metrology_service_hourservicecontainer;
	lv_obj_t *metrology_service_hourservicealertswitch;
	lv_obj_t *metrology_service_hourserviceinvalue;
	lv_obj_t *metrology_service_hourserviceinbutton;
	lv_obj_t *metrology_service_hourserivealertdropdown;
	lv_obj_t *metrology_service_hourseriveactionswitch;
	lv_obj_t *metrology_service_dateservicecontainer;
	lv_obj_t *metrology_service_dateservicealertswitch;
	lv_obj_t *metrology_service_dateserviceinvalue;
	lv_obj_t *metrology_service_dateserviceinbutton;
	lv_obj_t *metrology_service_dateservicealertdropdown;
	lv_obj_t *metrology_service_dateserviceactionswitch;
	lv_obj_t *metrology_service_volumeservicecontainer;
	lv_obj_t *metrology_service_volumeservicealertswitch;
	lv_obj_t *metrology_service_volumeserviceinvalue;
	lv_obj_t *metrology_service_volumeserviceinbutton;
	lv_obj_t *metrology_service_volumeservicealertdropdown;
	lv_obj_t *metrology_service_volumeserviceactionswitch;
	lv_obj_t *metrology_service_filterservicecontainer;
	lv_obj_t *metrology_service_filterservicealertswitch;
	lv_obj_t *metrology_service_filterserviceinvalue;
	lv_obj_t *metrology_service_filterserviceinbutton;
	lv_obj_t *metrology_service_filterserivealertdropdown;
	lv_obj_t *metrology_service_filterserviceactionswitch;
	lv_obj_t *metrology_service_filterservicetestbutton;

	lv_obj_t *alertmessage;
	lv_obj_t *alertmessage_background;
	lv_obj_t *alertmessage_titletext;
	lv_obj_t *alertmessage_container;
	lv_obj_t *alertmessage_container_title;
	lv_obj_t *alertmessage_container_ring;
	lv_obj_t *alertmessage_container_spinner;
	lv_obj_t *alertmessage_container_middlelabel;
	lv_obj_t *alertmessage_container_symbol;


	lv_obj_t *preset_scenario;
	lv_obj_t *preset_scenario_background;
	lv_obj_t *preset_scenario_startnowHvalue[3];
	lv_obj_t *preset_scenario_startnowLPMvalue[3];
	lv_obj_t *preset_scenario_startlaterHvalue[3];
	lv_obj_t *preset_scenario_startlaterLPMvalue[3];
	lv_obj_t *preset_scenario_validbutton;

	lv_obj_t *preset_sequence;
	lv_obj_t *preset_sequence_background;
	lv_obj_t *preset_sequence_calender;
	lv_obj_t *preset_sequence_dateselectedlabel;
	lv_obj_t *preset_sequence_starthourroller;
	lv_obj_t *preset_sequence_startminuteroller;
	lv_obj_t *preset_sequence_durationhourroller;
	lv_obj_t *preset_sequence_durationminuteroller;
	lv_obj_t *preset_sequence_setpointroller;
	lv_obj_t *preset_sequence_validbutton;
	lv_obj_t *preset_sequence_addbutton;

    lv_obj_t *test;
}lv_ui;

void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;

void setup_scr_sleep(lv_ui *ui);
void setup_scr_dashboard(lv_ui *ui);
void setup_scr_password(lv_ui *ui);
void setup_scr_summary_start(lv_ui *ui);
void setup_scr_logo(lv_ui *ui);
void setup_scr_parameter(lv_ui *ui);
void setup_scr_metrology_menu(lv_ui *ui);
void setup_scr_metrology_settings(lv_ui *ui);
void setup_scr_metrology_calibration(lv_ui *ui);
void setup_scr_info(lv_ui *ui);
void setup_scr_summary_end(lv_ui *ui);
void setup_scr_metrology_service(lv_ui *ui);
void setup_scr_alertmesage(lv_ui *ui);
void setup_scr_summary_sample(lv_ui *ui);
void setup_scr_preset_scenario(lv_ui *ui);
void setup_scr_preset_sequence(lv_ui *ui);
void setup_scr_flow_sensor_parameter(lv_ui *ui);

void clock_count_12(int *hour, int *min, int *sec, char *meridiem);
void clock_count_24(int *hour, int *min, int *sec);


void setup_test(lv_ui *ui);
#ifdef __cplusplus
}
#endif
#endif
