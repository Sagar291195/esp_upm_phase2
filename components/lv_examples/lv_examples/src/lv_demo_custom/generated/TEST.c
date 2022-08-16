/*
 * TEST.c
 *
 *  Created on: 06-Jul-2022
 *      Author: SAGAR
 */
#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "../custom/custom.h"

static void dashboard_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			guider_load_screen(SCR_DASHBOARD);
			break;
		default:
			break;
	}
}

static void flowsensor_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			guider_load_screen(SCR_FLOW_PARAMETER);
			break;
		default:
			break;
	}
}

static void presetsequence_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			guider_load_screen(SCR_PRESET_SEQUENCE_BLUE);
			break;
		default:
			break;
	}
}

static void logoscreen_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			guider_load_screen(SCR_LOGO);
			break;
		default:
			break;
	}
}

static void sleepscreen_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			guider_load_screen(SCR_SLEEP);
			break;
		default:
			break;
	}
}

static void passwordscreen_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			guider_load_screen(SCR_PASSWORD_METROLOGY_CODE);
			break;
		default:
			break;
	}
}

static void summarystartscreen_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			guider_load_screen(SCR_SUMMARY_START_BLUE);
			break;
		default:
			break;
	}
}


static void summaryendscreen_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			guider_load_screen(SCR_SUMMARY_ARCHIV_SINGLEWIDGET_BLUE);
			break;
		default:
			break;
	}
}

static void summarysamplescreen_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			guider_load_screen(SCR_SUMMARY_SAMPLE_SEQUENCE_01_01_BLUE);
			break;
		default:
			break;
	}
}

static void parameterscreen_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			guider_load_screen(SCR_PARAMETER);
			break;
		default:
			break;
	}
}

static void infoscreen_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			guider_load_screen(SCR_INFO);
			break;
		default:
			break;
	}
}

static void metrologymenuscreen_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			guider_load_screen(SCR_METROLOGY_MENU);
			break;
		default:
			break;
	}
}


static void metrologysettingsscreen_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			guider_load_screen(SCR_METROLOGY_SETTINGS_TEMPERATURE);
			break;
		default:
			break;
	}
}

static void metrologycalibrationscreen_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			guider_load_screen(SCR_METROLOGY_CALIBRATION_HUMIDITY);
			break;
		default:
			break;
	}
}

static void metrologyservicescreen_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			guider_load_screen(SCR_METROLOGY_SERVICE);
			break;
		default:
			break;
	}
}

static void alertmessagescreen_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			guider_load_screen(SCR_ALERT_MESSAGE_WRONG_PASSWORD);
			break;
		default:
			break;
	}
}

static void presetscenarioscreen_button_eventhandler(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
		case LV_EVENT_RELEASED:
			guider_load_screen(SCR_PRESET_SCENARIO);
			break;
		default:
			break;
	}
}

void setup_test(lv_ui *ui){
	ui->test = lv_obj_create(NULL);
	static lv_style_t style_alertmessage_service_default;
	if (style_alertmessage_service_default.prop_cnt > 1)
		lv_style_reset(&style_alertmessage_service_default);
	else
		lv_style_init(&style_alertmessage_service_default);
	lv_style_set_bg_color(&style_alertmessage_service_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_alertmessage_service_default, SCREEN_MIN_OPACITY);
	lv_obj_add_style(ui->test, &style_alertmessage_service_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	lv_obj_t *dashboardbutton = lv_btn_create(ui->test);
	lv_obj_set_size(dashboardbutton, 200, 50);
	lv_obj_align(dashboardbutton, LV_ALIGN_TOP_MID, 0, 10);
	static lv_style_t btn1;
	lv_style_reset(&btn1);
	lv_style_set_radius(&btn1, 5);
	lv_style_set_border_color(&btn1, ESPUPM_COLOR_DARK_GREY);
	lv_style_set_border_width(&btn1, 0);
	lv_style_set_border_opa(&btn1, 255);
	lv_style_set_shadow_width(&btn1, 0);
	lv_style_set_bg_color(&btn1, ESPUPM_COLOR_BLUE);
	lv_obj_t *buttonlabel = lv_label_create(dashboardbutton);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &btn1, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "DASHBOARD");
	lv_obj_center(buttonlabel);
	lv_obj_add_event_cb(dashboardbutton, dashboard_button_eventhandler, LV_EVENT_ALL, NULL);

	lv_obj_t *presetsequencebutton = lv_btn_create(ui->test);
	lv_obj_set_size(presetsequencebutton, 200, 50);
	lv_obj_align_to(presetsequencebutton, dashboardbutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	buttonlabel = lv_label_create(presetsequencebutton);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &btn1, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "PRESET SEQUENCE");
	lv_obj_center(buttonlabel);
	lv_obj_add_event_cb(presetsequencebutton, presetsequence_button_eventhandler, LV_EVENT_ALL, NULL);


	lv_obj_t *flowsensorbutton = lv_btn_create(ui->test);
	lv_obj_set_size(flowsensorbutton, 200, 50);
	lv_obj_align_to(flowsensorbutton, presetsequencebutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	buttonlabel = lv_label_create(flowsensorbutton);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &btn1, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "FLOW SENSOR");
	lv_obj_center(buttonlabel);
	lv_obj_add_event_cb(flowsensorbutton, flowsensor_button_eventhandler, LV_EVENT_ALL, NULL);


	lv_obj_t *logoscreenbutton = lv_btn_create(ui->test);
	lv_obj_set_size(logoscreenbutton, 200, 50);
	lv_obj_align_to(logoscreenbutton, flowsensorbutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	buttonlabel = lv_label_create(logoscreenbutton);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &btn1, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "LOGO");
	lv_obj_center(buttonlabel);
	lv_obj_add_event_cb(logoscreenbutton, logoscreen_button_eventhandler, LV_EVENT_ALL, NULL);


	lv_obj_t *passwordscreenbutton = lv_btn_create(ui->test);
	lv_obj_set_size(passwordscreenbutton, 200, 50);
	lv_obj_align_to(passwordscreenbutton, logoscreenbutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	buttonlabel = lv_label_create(passwordscreenbutton);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &btn1, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "PASSWORD");
	lv_obj_center(buttonlabel);
	lv_obj_add_event_cb(passwordscreenbutton, passwordscreen_button_eventhandler, LV_EVENT_ALL, NULL);


	lv_obj_t *sleepscreenbutton = lv_btn_create(ui->test);
	lv_obj_set_size(sleepscreenbutton, 200, 50);
	lv_obj_align_to(sleepscreenbutton, passwordscreenbutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	buttonlabel = lv_label_create(sleepscreenbutton);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &btn1, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "SLEEP");
	lv_obj_center(buttonlabel);
	lv_obj_add_event_cb(sleepscreenbutton, sleepscreen_button_eventhandler, LV_EVENT_ALL, NULL);

	lv_obj_t *summarystartscreenbutton = lv_btn_create(ui->test);
	lv_obj_set_size(summarystartscreenbutton, 200, 50);
	lv_obj_align_to(summarystartscreenbutton, sleepscreenbutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	buttonlabel = lv_label_create(summarystartscreenbutton);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &btn1, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "SUMMARY START");
	lv_obj_center(buttonlabel);
	lv_obj_add_event_cb(summarystartscreenbutton, summarystartscreen_button_eventhandler, LV_EVENT_ALL, NULL);


	lv_obj_t *summaryendbutton = lv_btn_create(ui->test);
	lv_obj_set_size(summaryendbutton, 200, 50);
	lv_obj_align_to(summaryendbutton, summarystartscreenbutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	buttonlabel = lv_label_create(summaryendbutton);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &btn1, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "SUMMARY END");
	lv_obj_center(buttonlabel);
	lv_obj_add_event_cb(summaryendbutton, summaryendscreen_button_eventhandler, LV_EVENT_ALL, NULL);


	lv_obj_t *summarysamplescreenbuttton = lv_btn_create(ui->test);
	lv_obj_set_size(summarysamplescreenbuttton, 200, 50);
	lv_obj_align_to(summarysamplescreenbuttton, summaryendbutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	buttonlabel = lv_label_create(summarysamplescreenbuttton);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &btn1, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "SUMMARY SAMPLE");
	lv_obj_center(buttonlabel);
	lv_obj_add_event_cb(summarysamplescreenbuttton, summarysamplescreen_button_eventhandler, LV_EVENT_ALL, NULL);

	lv_obj_t *parameterscreenbuttton = lv_btn_create(ui->test);
	lv_obj_set_size(parameterscreenbuttton, 200, 50);
	lv_obj_align_to(parameterscreenbuttton, summarysamplescreenbuttton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	buttonlabel = lv_label_create(parameterscreenbuttton);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &btn1, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "PARAMETER");
	lv_obj_center(buttonlabel);
	lv_obj_add_event_cb(parameterscreenbuttton, parameterscreen_button_eventhandler, LV_EVENT_ALL, NULL);

	lv_obj_t *infoscreenbuttton = lv_btn_create(ui->test);
	lv_obj_set_size(infoscreenbuttton, 200, 50);
	lv_obj_align_to(infoscreenbuttton, parameterscreenbuttton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	buttonlabel = lv_label_create(infoscreenbuttton);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &btn1, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "INFO SCREEN");
	lv_obj_center(buttonlabel);
	lv_obj_add_event_cb(infoscreenbuttton, infoscreen_button_eventhandler, LV_EVENT_ALL, NULL);

	lv_obj_t *metrologymenuscreenbuttton = lv_btn_create(ui->test);
	lv_obj_set_size(metrologymenuscreenbuttton, 200, 50);
	lv_obj_align_to(metrologymenuscreenbuttton, infoscreenbuttton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	buttonlabel = lv_label_create(metrologymenuscreenbuttton);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &btn1, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "METROLOGY MENU");
	lv_obj_center(buttonlabel);
	lv_obj_add_event_cb(metrologymenuscreenbuttton, metrologymenuscreen_button_eventhandler, LV_EVENT_ALL, NULL);


	lv_obj_t *metroloysettingsbutton = lv_btn_create(ui->test);
	lv_obj_set_size(metroloysettingsbutton, 200, 50);
	lv_obj_align_to(metroloysettingsbutton, metrologymenuscreenbuttton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	buttonlabel = lv_label_create(metroloysettingsbutton);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &btn1, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "METROLOGY SETTINGS");
	lv_obj_center(buttonlabel);
	lv_obj_add_event_cb(metroloysettingsbutton, metrologysettingsscreen_button_eventhandler, LV_EVENT_ALL, NULL);

	lv_obj_t *metroloycalibrationbutton = lv_btn_create(ui->test);
	lv_obj_set_size(metroloycalibrationbutton, 200, 50);
	lv_obj_align_to(metroloycalibrationbutton, metroloysettingsbutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	buttonlabel = lv_label_create(metroloycalibrationbutton);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &btn1, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "METROLOGY CALIBRATION");
	lv_obj_center(buttonlabel);
	lv_obj_add_event_cb(metroloycalibrationbutton, metrologycalibrationscreen_button_eventhandler, LV_EVENT_ALL, NULL);

	lv_obj_t *metroloyservicebutton = lv_btn_create(ui->test);
	lv_obj_set_size(metroloyservicebutton, 200, 50);
	lv_obj_align_to(metroloyservicebutton, metroloycalibrationbutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	buttonlabel = lv_label_create(metroloyservicebutton);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &btn1, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "METROLOGY SERVICE");
	lv_obj_center(buttonlabel);
	lv_obj_add_event_cb(metroloyservicebutton, metrologyservicescreen_button_eventhandler, LV_EVENT_ALL, NULL);

	lv_obj_t *alertmessagebutton = lv_btn_create(ui->test);
	lv_obj_set_size(alertmessagebutton, 200, 50);
	lv_obj_align_to(alertmessagebutton, metroloyservicebutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	buttonlabel = lv_label_create(alertmessagebutton);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &btn1, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "ALERT MESSAGE");
	lv_obj_center(buttonlabel);
	lv_obj_add_event_cb(alertmessagebutton, alertmessagescreen_button_eventhandler, LV_EVENT_ALL, NULL);

	lv_obj_t *presetscenariobutton = lv_btn_create(ui->test);
	lv_obj_set_size(presetscenariobutton, 200, 50);
	lv_obj_align_to(presetscenariobutton, alertmessagebutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	buttonlabel = lv_label_create(presetscenariobutton);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &btn1, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "PRESET SCENARIO");
	lv_obj_center(buttonlabel);
	lv_obj_add_event_cb(presetscenariobutton, presetscenarioscreen_button_eventhandler, LV_EVENT_ALL, NULL);



	lv_scr_load(ui->test);

}

