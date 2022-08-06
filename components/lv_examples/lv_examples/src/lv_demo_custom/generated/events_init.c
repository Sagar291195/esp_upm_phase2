/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "../custom/custom.h"

void events_init(lv_ui *ui)
{
}

/***********************************************************
 *
 * Dashboard Screen Related Object Event Handling Start
 *
 ***********************************************************/

static void screen_dashboard_menubutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_dashboard_menu_buttonreleased();
			break;
		default:
			break;
	}
}

static void screen_dashboard_stopbutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_dashboard_startstop_buttonreleased();
			break;
		default:
			break;
	}
}

static void screen_dashboard_servicebutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_dashboard_service_buttonreleased();
			break;
		default:
			break;
	}
}

static void screen_dashboard_infobutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_dashboard_info_buttonreleased();
			break;
		default:
			break;
	}
}


static void screen_dashboard_archivbutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_dashboard_archiv_buttonreleased();
			break;
		default:
			break;
	}
}


static void screen_dashboard_metrologybutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_dashboard_metrology_buttonreleased();
			break;
		default:
			break;
	}
}


static void screen_dashboard_parameterbutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_dashboard_parameter_buttonreleased();
			break;
		default:
			break;
	}
}


void events_init_dashboard(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->dashboard_menubutton, screen_dashboard_menubutton_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->dashboard_stopbutton, screen_dashboard_stopbutton_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->dashboard_menuviewservicebutton, screen_dashboard_servicebutton_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->dashboard_menuviewinfobutton, screen_dashboard_infobutton_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->dashboard_menuviewarchievebutton, screen_dashboard_archivbutton_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->dashboard_menuviewmetrologybutton, screen_dashboard_metrologybutton_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->dashboard_menuviewparameterbutton, screen_dashboard_parameterbutton_eventhandler, LV_EVENT_ALL, NULL);
}
/***********************************************************
 *
 * Dashboard Screen Related Object Event Handling End
 *
 ***********************************************************/


/***********************************************************
 *
 * Password Screen Related Object Event Handling Start
 *
 ***********************************************************/
static void event_handler_password_enter(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
	{
		case LV_EVENT_RELEASED:
			on_passwordscreen_passwordkey_btnreleased(e);
			break;
		default:
			break;
	}
}

void events_init_password(lv_ui *ui){
	for(uint8_t i = 0; i < 12; i++)
	{
		lv_obj_add_event_cb(ui->password_keyboard_digit[i], event_handler_password_enter, LV_EVENT_ALL, NULL);
	}
}
/***********************************************************
 *
 * Password Screen Related Object Event Handling End
 *
 ***********************************************************/

/***********************************************************
 *
 *Parameter Screen Related Object Event Handling Start
 *
 ***********************************************************/
static void event_handler_parameter_backbutton(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
	{
		case LV_EVENT_RELEASED:
			on_parameter_backbutton_released();
			break;
		default:
			break;
	}
}

static void event_handler_parameter_buzzerswitch(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_parameter_buzzer_valuechanged();
			break;
		default:
			break;
	}
}


static void event_handler_parameter_ledswitch(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_parameter_led_valuechanged();
			break;
		default:
			break;
	}
}



static void event_handler_parameter_wifiswitch(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_parameter_wifi_valuechanged();
			break;
		default:
			break;
	}
}



static void event_handler_parameter_fanswitch(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_parameter_externalfan_valuechanged();
			break;
		default:
			break;
	}
}



static void event_handler_parameter_sleepswitch(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_parameter_sleep_valuechanged();
			break;
		default:
			break;
	}
}



static void event_handler_parameter_languagedropdown_(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_parameter_language_valuechanged();
			break;
		default:
			break;
	}
}



static void event_handler_parameter_sleeptimerdropdown(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_parameter_sleeptimer_valuechanged();
			break;
		default:
			break;
	}
}



static void event_handler_parameter_luminosityslider(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_parameter_luminosity_valuechanged();
			break;
		default:
			break;
	}
}



static void event_handler_parameter_contrastslider(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_parameter_contrast_valuechanged();
			break;
		default:
			break;
	}
}

void events_init_parameter(lv_ui *ui){
	lv_obj_add_event_cb(ui->title_leftarrow, event_handler_parameter_backbutton, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->parameter_buzzerswitch, event_handler_parameter_buzzerswitch, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->parameter_ledswitch, event_handler_parameter_ledswitch, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->parameter_wifiswitch, event_handler_parameter_wifiswitch, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->parameter_fanswitch, event_handler_parameter_fanswitch, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->parameter_sleepswitch, event_handler_parameter_sleepswitch, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->parameter_languagedropdown, event_handler_parameter_languagedropdown_, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->parameter_sleeptimerdropdown, event_handler_parameter_sleeptimerdropdown, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->parameter_luminosityslider, event_handler_parameter_luminosityslider, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->parameter_contrastslider, event_handler_parameter_contrastslider, LV_EVENT_ALL, NULL);
}
/***********************************************************
 *
 * Parameter Screen Related Object Event Handling End
 *
 ***********************************************************/

/***********************************************************
 *
 * Summary Start Screen Related Object Event Handling Start
 *
 ***********************************************************/
static void event_handler_summary_start_back_btn(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_summarystart_back_buttonreleased();
			break;
		default:
			break;
	}
}

static void event_handler_summary_start_job_btn(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_summarystart_startjob_buttonreleased();
			break;
		default:
			break;
	}
}

void events_init_summary_start(lv_ui *ui){
	lv_obj_add_event_cb(ui->title_leftarrow, event_handler_summary_start_back_btn, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->summary_btn_startjob, event_handler_summary_start_job_btn, LV_EVENT_ALL, NULL);
}
/***********************************************************
 *
 * Summary Start Screen Related Object Event Handling End
 *
 ***********************************************************/

/***********************************************************
 *
 * Summary End Screen Related Object Event Handling Start
 *
 ***********************************************************/
static void event_handler_summaryend_back_btn(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_summaryend_back_buttonreleased();
			break;
		default:
			break;
	}
}

static void event_handler_summaryend_exportusb_btn(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_summaryend_exportusb_buttonreleased();
			break;
		default:
			break;
	}
}

static void event_handler_summaryend_next_btn(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_summaryend_next_buttonreleased();
			break;
		default:
			break;
	}
}


static void event_handler_summaryend_previous_btn(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_summaryend_previous_buttonreleased();
			break;
		default:
			break;
	}
}

static void event_handler_summaryend_sequencewidget1_btn(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_summaryend_sequencewidget2_buttonreleased();
			break;
		default:
			break;
	}
}


static void event_handler_summaryend_sequencewidget2_btn(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_summaryend_sequencewidget1_buttonreleased();
			break;
		default:
			break;
	}
}

static void event_handler_summaryend_quit_btn(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_summaryend_quit_buttonreleased();
			break;
		default:
			break;
	}
}

void events_init_summary_end(lv_ui *ui){
	lv_obj_add_event_cb(ui->title_leftarrow, event_handler_summaryend_back_btn, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->summaryend_exportusb, event_handler_summaryend_exportusb_btn, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->summaryend_nextbutton, event_handler_summaryend_next_btn, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->summaryend_previousbutton, event_handler_summaryend_previous_btn, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->summaryend_sequencewidgetcontainer1_button, event_handler_summaryend_sequencewidget1_btn, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->summaryend_sequencewidgetcontainer2_button, event_handler_summaryend_sequencewidget2_btn, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->summaryend_quit, event_handler_summaryend_quit_btn, LV_EVENT_ALL, NULL);
}
/***********************************************************
 *
 * Summary Screen Related Object Event Handling End
 *
 ***********************************************************/

/***********************************************************
 *
 * Init Screen Related Object Event Handling Start
 *
 ***********************************************************/
void events_init_logo(lv_ui *ui){
}
/***********************************************************
 *
 * Init Screen Related Object Event Handling End
 *
 ***********************************************************/
/***********************************************************
 *
 * Sleep Screen Related Object Event Handling Start
 *
 ***********************************************************/
void events_init_sleep(lv_ui *ui){
}
/***********************************************************
 *
 * Sleep Screen Related Object Event Handling end
 *
 ***********************************************************/

/***********************************************************
 *
 * Metrology calibration Screen Related Object Event Handling Start
 *
 ***********************************************************/
static void event_handler_metrology_calibration_digit_enter(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_metrologycal_keyboard_buttonreleased(e);
			break;
		default:
			break;
	}
}

static void event_handler_metrology_calibration_validbutton_enter(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_metrologycal_valid_buttonreleased();
			break;
		default:
			break;
	}
}


void events_init_metrology_calibration(lv_ui *ui){
	lv_obj_add_event_cb(ui->metrology_calibration_validbutton, event_handler_metrology_calibration_validbutton_enter, LV_EVENT_ALL, NULL);
	for(uint8_t i=0; i<=11; i++)
    {
        lv_obj_add_event_cb(ui->metrology_calibration_keyboard_digit[i], event_handler_metrology_calibration_digit_enter, LV_EVENT_ALL, NULL);
    }
}
/***********************************************************
 *
 * Metrology calibration Screen Related Object Event Handling end
 *
 ***********************************************************/

/***********************************************************
 *
 * Metrology Menu Screen Related Object Event Handling Start
 *
 ***********************************************************/
static void screen_metrology_menu_changepassword_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_metrologymenu_changepassword_btnreleased();
			break;
		default:
			break;
	}
}

static void screen_metrology_menu_calibration_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_metrologymenu_calibration_btnreleased();
			break;
		default:
			break;
	}
}

static void screen_metrology_menu_newvalidationtest_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_metrologymenu_newvalidation_btnreleased();
			break;
		default:
			break;
	}
}

static void screen_metrology_menu_setservice_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_metrologymenu_setservice_btnreleased();
			break;
		default:
			break;
	}
}

static void screen_metrology_menu_title_backbutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_metrologymenu_back_btnreleased();
			break;
		default:
			break;
	}
}

static void screen_metrology_menu_sequence_widget_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_metrologymenu_sequencewidget_btnreleased();
			break;
		default:
			break;
	}
}

void events_init_metrology_menu(lv_ui *ui){
	lv_obj_add_event_cb(ui->metrology_menu_changepassword, screen_metrology_menu_changepassword_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_menu_calibration, screen_metrology_menu_calibration_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_menu_newvalidationtest, screen_metrology_menu_newvalidationtest_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_menu_setservice, screen_metrology_menu_setservice_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->title_leftarrow, screen_metrology_menu_title_backbutton_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_menu_sequencecontainer_button, screen_metrology_menu_sequence_widget_eventhandler, LV_EVENT_ALL, NULL);
}
/***********************************************************
 *
 * Metrology Menu Screen Related Object Event Handling End
 *
 ***********************************************************/


/***********************************************************
 *
 * Metrology Settings Screen Related Object Event Handling Start
 *
 ***********************************************************/
static void screen_metrology_settings_backarrow_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_metrologysettings_back_buttonreleased();
			break;
		default:
			break;
	}
}


static void screen_metrology_settings_curvedropdown_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrologysettings_curved_valuechanged();
			break;
		default:
			break;
	}
}

static void screen_metrology_settings_unitdropdown_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrologysettings_unit_valuechanged();
			break;
		default:
			break;
	}
}

static void screen_metrology_settings_alertswitch_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrologysettings_alertsetpoint_valuechanged();
			break;
		default:
			break;
	}
}

static void screen_metrology_settings_lowerlimit_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrologysettings_lowerlimit_valuechanged();
			break;
		default:
			break;
	}
}

static void screen_metrology_settings_higherlimit_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrologysettings_higherlimit_valuechanged();
			break;
		default:
			break;
	}
}


static void screen_metrology_settings_actionswitch_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrologysettings_actoinswitch_valuechanged();
			break;
		default:
			break;
	}
}

static void screen_metrology_settings_validadjust_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_metrologysettings_validadjust_btnreleased();
			break;
		default:
			break;
	}
}

void events_init_metrology_settings(lv_ui *ui){
	lv_obj_add_event_cb(ui->metrology_settings_curvedropdown, screen_metrology_settings_curvedropdown_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_settings_unitdropdown, screen_metrology_settings_unitdropdown_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->title_leftarrow, screen_metrology_settings_backarrow_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_settings_alertcontainerswitch, screen_metrology_settings_alertswitch_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_settings_lowerlimitdropdown, screen_metrology_settings_lowerlimit_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_settings_higherlimitdropdown, screen_metrology_settings_higherlimit_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_settings_actionswitch, screen_metrology_settings_actionswitch_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_settings_validadjustbutton, screen_metrology_settings_validadjust_eventhandler, LV_EVENT_ALL, NULL);
}
/***********************************************************
 *
 * Metrology Settings Screen Related Object Event Handling End
 *
 ***********************************************************/

/***********************************************************
 *
 * Metrology service Screen Related Object Event Handling Start
 *
 ***********************************************************/
static void screen_metrology_service_backbutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_metrology_service_backbutton_released();
			break;
		default:
			break;
	}
}

static void screen_metrology_service_hourservices_alertswitch_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrology_service_hourservice_alertswitch_valuechanged();
			break;
		default:
			break;
	}
}

static void screen_metrology_service_hourservices_inbutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_metrology_service_hourservice_inbutton_released();
			break;
		default:
			break;
	}
}

static void screen_metrology_service_hourservices_alertdropdown_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrology_service_hourservice_alertdropdown_valuechanged();
			break;
		default:
			break;
	}
}


static void screen_metrology_service_hourservices_actionswitch_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrology_service_hourservice_actionswitch_valuechanged();
			break;
		default:
			break;
	}
}

static void screen_metrology_service_dateservices_alertswitch_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrology_service_dateservice_alertswitch_valuechanged();
			break;
		default:
			break;
	}
}

static void screen_metrology_service_dateservices_inbutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_metrology_service_dateservice_inbutton_released();
			break;
		default:
			break;
	}
}

static void screen_metrology_service_dateservices_alertdropdown_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrology_service_dateservice_alertdropdown_valuechanged();
			break;
		default:
			break;
	}
}


static void screen_metrology_service_dateservices_actionswitch_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrology_service_dateservice_actionswitch_valuechanged();
			break;
		default:
			break;
	}
}

static void screen_metrology_service_volumeservices_alertswitch_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrology_service_volumeservice_alertswitch_valuechanged();
			break;
		default:
			break;
	}
}

static void screen_metrology_service_volumeservices_inbutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_metrology_service_volumeservice_inbutton_released();
			break;
		default:
			break;
	}
}

static void screen_metrology_service_volumeservices_alertdropdown_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrology_service_volumeservice_alertdropdown_valuechanged();
			break;
		default:
			break;
	}
}


static void screen_metrology_service_volumeservices_actionswitch_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrology_service_volumeservice_actionswitch_valuechanged();
			break;
		default:
			break;
	}
}

static void screen_metrology_service_filterservices_alertswitch_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrology_service_filterservice_alertswitch_valuechanged();
			break;
		default:
			break;
	}
}

static void screen_metrology_service_filterservices_inbutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_metrology_service_filterservice_inbutton_released();
			break;
		default:
			break;
	}
}

static void screen_metrology_service_filterservices_alertdropdown_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrology_service_filterservice_alertdropdown_valuechanged();
			break;
		default:
			break;
	}
}


static void screen_metrology_service_filterservices_actionswitch_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrology_service_filterservice_actionswitch_valuechanged();
			break;
		default:
			break;
	}
}


static void screen_metrology_service_filtertest_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_metrology_service_filtertest_buttonreleased();
			break;
		default:
			break;
	}
}


void events_init_metrology_service(lv_ui *ui){
	lv_obj_add_event_cb(ui->title_leftarrow, screen_metrology_service_backbutton_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_service_hourservicealertswitch, screen_metrology_service_hourservices_alertswitch_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_service_hourserviceinbutton, screen_metrology_service_hourservices_inbutton_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_service_hourserivealertdropdown, screen_metrology_service_hourservices_alertdropdown_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_service_hourseriveactionswitch, screen_metrology_service_hourservices_actionswitch_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_service_dateservicealertswitch, screen_metrology_service_dateservices_alertswitch_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_service_dateserviceinbutton, screen_metrology_service_dateservices_inbutton_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_service_dateservicealertdropdown, screen_metrology_service_dateservices_alertdropdown_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_service_dateserviceactionswitch, screen_metrology_service_dateservices_actionswitch_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_service_volumeservicealertswitch, screen_metrology_service_volumeservices_alertswitch_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_service_volumeserviceinbutton, screen_metrology_service_volumeservices_inbutton_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_service_volumeservicealertdropdown, screen_metrology_service_volumeservices_alertdropdown_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_service_volumeserviceactionswitch, screen_metrology_service_volumeservices_actionswitch_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_service_filterservicealertswitch, screen_metrology_service_filterservices_alertswitch_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_service_filterserviceinbutton, screen_metrology_service_filterservices_inbutton_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_service_filterserivealertdropdown, screen_metrology_service_filterservices_alertdropdown_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_service_filterserviceactionswitch, screen_metrology_service_filterservices_actionswitch_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->metrology_service_filterservicetestbutton, screen_metrology_service_filtertest_eventhandler, LV_EVENT_ALL, NULL);
}
/***********************************************************
 *
 * Metrology service Screen Related Object Event Handling End
 *
 ***********************************************************/

/***********************************************************
 *
 * Info Screen Related Object Event Handling Start
 *
 ***********************************************************/
static void screen_info_title_backbutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_infoscreen_back_buttonreleased();
			break;
		default:
			break;
	}
}


void events_init_info(lv_ui *ui){
	lv_obj_add_event_cb(ui->title_leftarrow, screen_info_title_backbutton_eventhandler, LV_EVENT_ALL, NULL);
}
/***********************************************************
 *
 * Info Screen Related Object Event Handling End
 *
 ***********************************************************/

/***********************************************************
 *
 * Alert message Screen Related Object Event Handling Start
 *
 ***********************************************************/
void events_init_alertmessage(lv_ui *ui){
}
/***********************************************************
 *
 * Alert message Screen Related Object Event Handling End
 *
 ***********************************************************/


/***********************************************************
 *
 * Summary Sample Screen Related Object Event Handling Start
 *
 ***********************************************************/
static void screen_sample_back_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_summarysample_back_btnreleased();
			break;
		default:
			break;
	}
}

static void screen_sample_next_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_summarysample_next_btnreleased();
			break;
		default:
			break;
	}
}


static void screen_sample_prev_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_summarysample_prev_btnreleased();
			break;
		default:
			break;
	}
}

static void screen_sample_quit_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_summarysample_quit_btnreleased();
			break;
		default:
			break;
	}
}

void  events_init_summary_sample(lv_ui *ui){
	lv_obj_add_event_cb(ui->summary_sample_quitbutton, screen_sample_quit_button_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->title_leftarrow, screen_sample_back_button_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->summary_sample_previousbutton, screen_sample_prev_button_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->summary_sample_nextbutton, screen_sample_next_button_eventhandler, LV_EVENT_ALL, NULL);
}
/***********************************************************
 *
 * Summary sample Screen Related Object Event Handling end
 *
 ***********************************************************/



/***********************************************************
 *
 * Preset Scenario Screen Related Object Event Handling Start
 *
 ***********************************************************/
static void screen_preset_scenario_backbutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_preset_scenario_back_buttonreleased();
			break;
		default:
			break;
	}
}

static void screen_preset_scenario_addbutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_preset_scenario_plus_buttonreleased();
			break;
		default:
			break;
	}
}

static void screen_preset_scenario_validbutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_preset_scenario_valid_buttonreleased();
			break;
		default:
			break;
	}
}


void  events_init_preset_scenario(lv_ui *ui){
	lv_obj_add_event_cb(ui->title_leftarrow, screen_preset_scenario_backbutton_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->title_symbol, screen_preset_scenario_addbutton_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->preset_scenario_validbutton, screen_preset_scenario_validbutton_eventhandler, LV_EVENT_ALL, NULL);
}

/***********************************************************
 *
 * Preset Scenario Screen Related Object Event Handling End
 *
 ***********************************************************/


/***********************************************************
 *
 * Preset Sequence Screen Related Object Event Handling Start
 *
 ***********************************************************/
static void preset_sequence_backbutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_preset_sequence_back_btnreleased();
			break;
		default:
			break;
	}
}

static void preset_sequence_validbutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_preset_sequence_valid_btnreleased();
			break;
		default:
			break;
	}
}


static void preset_sequence_addbutton_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_preset_sequence_add_btnreleased();
			break;
		default:
			break;
	}
}

static void preset_sequence_calender_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_preset_sequence_calender_valuechanged();
			break;
		default:
			break;
	}
}


static void preset_sequence_starthour_roller_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_preset_sequence_starthour_valuechanged();
			break;
		default:
			break;
	}
}

static void preset_sequence_startminute_roller_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_preset_sequence_startminute_valuechanged();
			break;
		default:
			break;
	}
}


static void preset_sequence_durationhour_roller_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_preset_sequence_durationhour_valuechanged();
			break;
		default:
			break;
	}
}


static void preset_sequence_durationminute_roller_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_preset_sequence_durationminute_valuechanged();
			break;
		default:
			break;
	}
}


static void preset_sequence_setpoint_roller_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_VALUE_CHANGED:
			on_preset_sequence_setpoint_valuechanged();
			break;
		default:
			break;
	}
}

void events_init_preset_sequence(lv_ui *ui){
	lv_obj_add_event_cb(ui->preset_sequence_calender, preset_sequence_calender_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->preset_sequence_starthourroller, preset_sequence_starthour_roller_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->preset_sequence_startminuteroller, preset_sequence_startminute_roller_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->preset_sequence_durationhourroller, preset_sequence_durationhour_roller_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->preset_sequence_durationminuteroller, preset_sequence_durationminute_roller_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->preset_sequence_setpointroller, preset_sequence_setpoint_roller_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->preset_sequence_validbutton, preset_sequence_validbutton_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->preset_sequence_addbutton, preset_sequence_addbutton_eventhandler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->title_leftarrow, preset_sequence_backbutton_eventhandler, LV_EVENT_ALL, NULL);
}

/***********************************************************
 *
 * Preset Sequence Screen Related Object Event Handling End
 *
 ***********************************************************/


/***********************************************************
 *
 * Flow Sensor Parameter Screen Related Object Event Handling Start
 *
 ***********************************************************/
 static void event_handler_flow_sensor_par_back_btn(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_flowsensor_par_back_buttonreleased();
			break;
		default:
			break;
	}
}

static void event_handler_flow_sensor_par_erase_btn(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			on_flowsensor_par_erasebuttonreleased();
			break;
		default:
			break;
	}
}

void events_init_flow_sensor_parameter(lv_ui *ui){
    lv_obj_add_event_cb(ui->title_leftarrow, event_handler_flow_sensor_par_back_btn, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->flow_sensor_par_cont_btn_erase, event_handler_flow_sensor_par_erase_btn, LV_EVENT_ALL, NULL);
}

/***********************************************************
 *
 * Flow Sensor Parameter Related Object Event Handling End
 *
 ***********************************************************/
