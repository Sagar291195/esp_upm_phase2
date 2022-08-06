/***********************************************************************************************************************
 * Includes <System Includes>
 ***********************************************************************************************************************/
#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "../custom/custom.h"
/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * static variables
 ***********************************************************************************************************************/
static lv_obj_t *hourcontainerlabel;
static lv_obj_t *houralertlabel;
static lv_obj_t *houralertonofflabel;
static lv_obj_t *hourinlabel;
static lv_obj_t *hourreminderlabel;
static lv_obj_t *hourbeforealertlabel;
static lv_obj_t *houractionlabel;
static lv_obj_t *houractiontxtlabel;
static lv_obj_t *datecontainerlabel;
static lv_obj_t *datealertlabel;
static lv_obj_t *datealertonofflabel;
static lv_obj_t *dateinlabel;
static lv_obj_t *datereminderlabel;
static lv_obj_t *datebeforealertlabel;
static lv_obj_t *dateactionlabel;
static lv_obj_t *dateactiontxtlabel;
static lv_obj_t *volumecontainerlabel;
static lv_obj_t *volumealertlabel;
static lv_obj_t *volumealertonofflabel;
static lv_obj_t *volumeinlabel;
static lv_obj_t *volumereminderlabel;
static lv_obj_t *volumebeforealertlabel;
static lv_obj_t *volumeactionlabel;
static lv_obj_t *volumeactiontxtlabel;
static lv_obj_t *filtercontainerlabel;
static lv_obj_t *filteralertlabel;
static lv_obj_t *filteralertonofflabel;
static lv_obj_t *filterinlabel;
static lv_obj_t *filterreminderlabel;
static lv_obj_t *filterbeforealertlabel;
static lv_obj_t *filteractionlabel;
static lv_obj_t *filteractiontxtlabel;

/***********************************************************************************************************************
 * static prototype
 ***********************************************************************************************************************/
static void screen_dropdown_event_cb(lv_event_t * e);

/***********************************************************************************************************************
 * static functions
 ***********************************************************************************************************************/
static void screen_dropdown_event_cb(lv_event_t * e)
{
	lv_obj_t * obj = lv_event_get_target(e);

	//Write style state: LV_STATE_DEFAULT for style_screen_ddlist_1_extra_list_selected_default
	static lv_style_t style_screen_ddlist_1_extra_list_selected_default;
	if (style_screen_ddlist_1_extra_list_selected_default.prop_cnt > 1)
		lv_style_reset(&style_screen_ddlist_1_extra_list_selected_default);
	else
		lv_style_init(&style_screen_ddlist_1_extra_list_selected_default);
	lv_style_set_radius(&style_screen_ddlist_1_extra_list_selected_default, 3);
	lv_style_set_bg_color(&style_screen_ddlist_1_extra_list_selected_default, ESPUPM_COLOR_GREY);
	lv_style_set_bg_grad_color(&style_screen_ddlist_1_extra_list_selected_default, ESPUPM_COLOR_GREY);
	lv_style_set_bg_grad_dir(&style_screen_ddlist_1_extra_list_selected_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_ddlist_1_extra_list_selected_default, 255);
	lv_style_set_border_color(&style_screen_ddlist_1_extra_list_selected_default, ESPUPM_COLOR_GREY);
	lv_style_set_border_width(&style_screen_ddlist_1_extra_list_selected_default, 0);
	lv_style_set_text_color(&style_screen_ddlist_1_extra_list_selected_default, ESPUPM_COLOR_WHITE);
	lv_style_set_text_font(&style_screen_ddlist_1_extra_list_selected_default, &lv_font_montserrat_15_semibold);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_screen_ddlist_1_extra_list_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_screen_ddlist_1_extra_list_main_default
	static lv_style_t style_screen_ddlist_1_extra_list_main_default;
	if (style_screen_ddlist_1_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_ddlist_1_extra_list_main_default);
	else
		lv_style_init(&style_screen_ddlist_1_extra_list_main_default);
	lv_style_set_radius(&style_screen_ddlist_1_extra_list_main_default, 3);
	lv_style_set_bg_color(&style_screen_ddlist_1_extra_list_main_default, ESPUPM_COLOR_GREY);
	lv_style_set_bg_grad_color(&style_screen_ddlist_1_extra_list_main_default,ESPUPM_COLOR_GREY);
	lv_style_set_bg_grad_dir(&style_screen_ddlist_1_extra_list_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_ddlist_1_extra_list_main_default, 255);
	lv_style_set_border_color(&style_screen_ddlist_1_extra_list_main_default, ESPUPM_COLOR_GREY);
	lv_style_set_border_width(&style_screen_ddlist_1_extra_list_main_default, 0);
	lv_style_set_text_color(&style_screen_ddlist_1_extra_list_main_default, ESPUPM_COLOR_WHITE);
	lv_style_set_text_font(&style_screen_ddlist_1_extra_list_main_default, &lv_font_montserrat_15_semibold);
	lv_style_set_max_height(&style_screen_ddlist_1_extra_list_main_default, 90);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_screen_ddlist_1_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_screen_ddlist_1_extra_list_scrollbar_default
	static lv_style_t style_screen_ddlist_1_extra_list_scrollbar_default;
	if (style_screen_ddlist_1_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_screen_ddlist_1_extra_list_scrollbar_default);
	else
		lv_style_init(&style_screen_ddlist_1_extra_list_scrollbar_default);
	lv_style_set_radius(&style_screen_ddlist_1_extra_list_scrollbar_default, 3);
	lv_style_set_bg_color(&style_screen_ddlist_1_extra_list_scrollbar_default,ESPUPM_COLOR_GREY);
	lv_style_set_bg_grad_color(&style_screen_ddlist_1_extra_list_scrollbar_default, ESPUPM_COLOR_GREY);
	lv_style_set_bg_grad_dir(&style_screen_ddlist_1_extra_list_scrollbar_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_ddlist_1_extra_list_scrollbar_default, 0);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_screen_ddlist_1_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
}

/***********************************************************************************************************************
 * global functions 
 ***********************************************************************************************************************/
/*
 * Function to draw metrology service screen
 */
void setup_scr_metrology_service(lv_ui *ui){
	//metrology service Screen main object
	ui->metrology_service = lv_obj_create(NULL);
	static lv_style_t style_metrology_service_default;
	if (style_metrology_service_default.prop_cnt > 1)
		lv_style_reset(&style_metrology_service_default);
	else
		lv_style_init(&style_metrology_service_default);
	lv_style_set_bg_color(&style_metrology_service_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_metrology_service_default, SCREEN_MIN_OPACITY);
	lv_obj_add_style(ui->metrology_service, &style_metrology_service_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	/********************************************
	 *
	 * metrology service Screen design Start
	 *
	**********************************************/
	//metrology service Screen Background
	ui->metrology_service_background = lv_obj_create(ui->metrology_service);
	lv_obj_set_align(ui->metrology_service_background, LV_ALIGN_CENTER);
	lv_obj_set_scrollbar_mode(ui->metrology_service_background, LV_SCROLLBAR_MODE_OFF);
	lv_obj_set_size(ui->metrology_service_background, SCREEN_WIDTH, SCREEN_HEIGHT);
	static lv_style_t style_metrology_service_background_default;
	if (style_metrology_service_background_default.prop_cnt > 1)
		lv_style_reset(&style_metrology_service_background_default);
	else
		lv_style_init(&style_metrology_service_background_default);
	lv_style_set_radius(&style_metrology_service_background_default, 0);
	lv_style_set_bg_color(&style_metrology_service_background_default, ESPUPM_COLOR_BLUE);
	lv_style_set_bg_grad_color(&style_metrology_service_background_default, ESPUPM_COLOR_BLUE);
	lv_style_set_bg_grad_dir(&style_metrology_service_background_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_metrology_service_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_border_color(&style_metrology_service_background_default, ESPUPM_COLOR_BLUE);
	lv_style_set_border_width(&style_metrology_service_background_default, 0);
	lv_style_set_border_opa(&style_metrology_service_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_pad_left(&style_metrology_service_background_default, 0);
	lv_style_set_pad_right(&style_metrology_service_background_default, 0);
	lv_style_set_pad_top(&style_metrology_service_background_default, 0);
	lv_style_set_pad_bottom(&style_metrology_service_background_default, 0);
	lv_obj_add_style(ui->metrology_service_background, &style_metrology_service_background_default, LV_PART_MAIN|LV_STATE_DEFAULT);


	//metrology service Screen Header
	setup_draw_header(ui, ui->metrology_service_background);


	//metrology service Screen object for left arrow, parameter text and menu symbol
	setup_draw_title(ui, ui->metrology_service_background, "SERVICE", &service_icon, ESPUPM_COLOR_BLUE);

	/************************************************
	 * Hour Service Container Start
	 ************************************************/
	//Hour service container
	ui->metrology_service_hourservicecontainer = lv_obj_create(ui->metrology_service_background);
	lv_obj_clear_flag(ui->metrology_service_hourservicecontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->metrology_service_hourservicecontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(ui->metrology_service_hourservicecontainer, ui->title_container, LV_ALIGN_OUT_BOTTOM_LEFT, 10, 0);
	lv_obj_set_size(ui->metrology_service_hourservicecontainer, SCREEN_WIDTH-20, 220);
	lv_obj_set_style_bg_color(ui->metrology_service_hourservicecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_service_hourservicecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_service_hourservicecontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_service_hourservicecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_service_hourservicecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Hour Service label
	hourcontainerlabel = lv_label_create(ui->metrology_service_hourservicecontainer);
	lv_obj_align_to(hourcontainerlabel, ui->metrology_service_hourservicecontainer, LV_ALIGN_TOP_LEFT, 10, 10);
	lv_obj_set_style_text_font(hourcontainerlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(hourcontainerlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(hourcontainerlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(hourcontainerlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(hourcontainerlabel, "HOUR SERVICE");

	//Hour Alert label
	houralertlabel = lv_label_create(ui->metrology_service_hourservicecontainer);
	lv_obj_align_to(houralertlabel, hourcontainerlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_text_font(houralertlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(houralertlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(houralertlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(houralertlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(houralertlabel, "Alert");
	//ALert switch hour service
	ui->metrology_service_hourservicealertswitch = lv_switch_create(ui->metrology_service_hourservicecontainer);
	lv_obj_align_to(ui->metrology_service_hourservicealertswitch, ui->metrology_service_hourservicecontainer, LV_ALIGN_TOP_RIGHT, -5, 30);
	lv_obj_set_size(ui->metrology_service_hourservicealertswitch, 50, 25);
	lv_obj_set_style_bg_color(ui->metrology_service_hourservicealertswitch, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_service_hourservicealertswitch, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->metrology_service_hourservicealertswitch, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_service_hourservicealertswitch, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_service_hourservicealertswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_service_hourservicealertswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//on/off label
	houralertonofflabel = lv_label_create(ui->metrology_service_hourservicecontainer);
	lv_obj_align_to(houralertonofflabel, houralertlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 5, 5);
	lv_obj_set_style_text_font(houralertonofflabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(houralertonofflabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(houralertonofflabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(houralertonofflabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(houralertonofflabel, "ON/OFF");

	//In lable
	hourinlabel = lv_label_create(ui->metrology_service_hourservicecontainer);
	lv_obj_align_to(hourinlabel, houralertonofflabel, LV_ALIGN_OUT_BOTTOM_LEFT, -5, 15);
	lv_obj_set_style_text_font(hourinlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(hourinlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(hourinlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(hourinlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(hourinlabel, "In : ");

	//In value
	ui->metrology_service_hourserviceinvalue = lv_label_create(ui->metrology_service_hourservicecontainer);
	lv_obj_align_to(ui->metrology_service_hourserviceinvalue, hourinlabel, LV_ALIGN_OUT_RIGHT_MID, 5, 2);
	lv_obj_set_style_text_font(ui->metrology_service_hourserviceinvalue, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->metrology_service_hourserviceinvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->metrology_service_hourserviceinvalue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_service_hourserviceinvalue, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->metrology_service_hourserviceinvalue, "3500 Hours");

	//Button Custom for hour services
	ui->metrology_service_hourserviceinbutton = lv_btn_create(ui->metrology_service_hourservicecontainer);
	lv_obj_align_to(ui->metrology_service_hourserviceinbutton, ui->metrology_service_hourservicealertswitch, LV_ALIGN_OUT_BOTTOM_LEFT, -50, 15);
	lv_obj_set_size(ui->metrology_service_hourserviceinbutton, 100, 30);
	lv_obj_set_style_border_width(ui->metrology_service_hourserviceinbutton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->metrology_service_hourserviceinbutton, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_service_hourserviceinbutton, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_t *hourbtnlabel = lv_label_create(ui->metrology_service_hourserviceinbutton);
	lv_obj_center(hourbtnlabel);
	lv_obj_set_style_text_font(hourbtnlabel, &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(hourbtnlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(hourbtnlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(hourbtnlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(hourbtnlabel, "CUSTOM");

	//hour reminder label
	hourreminderlabel = lv_label_create(ui->metrology_service_hourservicecontainer);
	lv_obj_align_to(hourreminderlabel, hourinlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(hourreminderlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(hourreminderlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(hourreminderlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(hourreminderlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(hourreminderlabel, "Reminder");

	//Before alert label
	hourbeforealertlabel = lv_label_create(ui->metrology_service_hourservicecontainer);
	lv_obj_align_to(hourbeforealertlabel, hourreminderlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(hourbeforealertlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(hourbeforealertlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(hourbeforealertlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(hourbeforealertlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(hourbeforealertlabel, "Before Alert :");
	//Before Alert Dropdown
	ui->metrology_service_hourserivealertdropdown = lv_dropdown_create(ui->metrology_service_hourservicecontainer);
	lv_dropdown_set_options(ui->metrology_service_hourserivealertdropdown,
					 "100 HOUR\n"
					 "200 HOUR\n"
					 "300 HOUR"
					 );
	lv_obj_align_to(ui->metrology_service_hourserivealertdropdown, ui->metrology_service_hourserviceinbutton, LV_ALIGN_OUT_BOTTOM_LEFT, -20, 25);
	lv_obj_set_size(ui->metrology_service_hourserivealertdropdown, 120, 30);
	lv_obj_add_event_cb(ui->metrology_service_hourserivealertdropdown, screen_dropdown_event_cb, LV_EVENT_READY, NULL);
	lv_obj_set_style_bg_color(ui->metrology_service_hourserivealertdropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->metrology_service_hourserivealertdropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_service_hourserivealertdropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_service_hourserivealertdropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_service_hourserivealertdropdown, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->metrology_service_hourserivealertdropdown, &lv_font_montserrat_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->metrology_service_hourserivealertdropdown, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->metrology_service_hourserivealertdropdown, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->metrology_service_hourserivealertdropdown, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Action label
	houractionlabel = lv_label_create(ui->metrology_service_hourservicecontainer);
	lv_obj_align_to(houractionlabel, hourbeforealertlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(houractionlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(houractionlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(houractionlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(houractionlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(houractionlabel, "Action");
	//Action switch
	ui->metrology_service_hourseriveactionswitch = lv_switch_create(ui->metrology_service_hourservicecontainer);
	lv_obj_align_to(ui->metrology_service_hourseriveactionswitch, ui->metrology_service_hourservicecontainer, LV_ALIGN_BOTTOM_RIGHT, -5, -15);
	lv_obj_set_size(ui->metrology_service_hourseriveactionswitch, 50, 25);
	lv_obj_set_style_bg_color(ui->metrology_service_hourseriveactionswitch, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_service_hourseriveactionswitch, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->metrology_service_hourseriveactionswitch, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_service_hourseriveactionswitch, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_service_hourseriveactionswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_service_hourseriveactionswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Disable device after alert
	houractiontxtlabel = lv_label_create(ui->metrology_service_hourservicecontainer);
	lv_obj_align_to(houractiontxtlabel, houractionlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 5, 5);
	lv_obj_set_style_text_font(houractiontxtlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(houractiontxtlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(houractiontxtlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(houractiontxtlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(houractiontxtlabel, "DISABLE DEVICE AFTER ALERT");
	/************************************************
	 * Hour Service Container End
	 ************************************************/

	/************************************************
	 * Date Service Container Start
	 ************************************************/
	//Date service container
	ui->metrology_service_dateservicecontainer = lv_obj_create(ui->metrology_service_background);
	lv_obj_clear_flag(ui->metrology_service_dateservicecontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->metrology_service_dateservicecontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(ui->metrology_service_dateservicecontainer, ui->metrology_service_hourservicecontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_size(ui->metrology_service_dateservicecontainer, SCREEN_WIDTH-20, 220);
	lv_obj_set_style_bg_color(ui->metrology_service_dateservicecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_service_dateservicecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_service_dateservicecontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_service_dateservicecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_service_dateservicecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Date service label
	datecontainerlabel = lv_label_create(ui->metrology_service_dateservicecontainer);
	lv_obj_align_to(datecontainerlabel, ui->metrology_service_dateservicecontainer, LV_ALIGN_TOP_LEFT, 10, 10);
	lv_obj_set_style_text_font(datecontainerlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(datecontainerlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(datecontainerlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(datecontainerlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(datecontainerlabel, "DATE SERVICE");

	//Alert label
	datealertlabel = lv_label_create(ui->metrology_service_dateservicecontainer);
	lv_obj_align_to(datealertlabel, datecontainerlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_text_font(datealertlabel, &lv_font_montserrat_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(datealertlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(datealertlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(datealertlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(datealertlabel, "Alert");
	//Alert switch
	ui->metrology_service_dateservicealertswitch = lv_switch_create(ui->metrology_service_dateservicecontainer);
	lv_obj_align_to(ui->metrology_service_dateservicealertswitch, ui->metrology_service_dateservicecontainer, LV_ALIGN_TOP_RIGHT, -5, 30);
	lv_obj_set_size(ui->metrology_service_dateservicealertswitch, 50, 25);
	lv_obj_set_style_bg_color(ui->metrology_service_dateservicealertswitch, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_service_dateservicealertswitch, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->metrology_service_dateservicealertswitch, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_service_dateservicealertswitch, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_service_dateservicealertswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_service_dateservicealertswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//on/off label
	datealertonofflabel = lv_label_create(ui->metrology_service_dateservicecontainer);
	lv_obj_align_to(datealertonofflabel, datealertlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 5, 5);
	lv_obj_set_style_text_font(datealertonofflabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(datealertonofflabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(datealertonofflabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(datealertonofflabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(datealertonofflabel, "ON/OFF");

	//In label
	dateinlabel = lv_label_create(ui->metrology_service_dateservicecontainer);
	lv_obj_align_to(dateinlabel, datealertonofflabel, LV_ALIGN_OUT_BOTTOM_LEFT, -5, 15);
	lv_obj_set_style_text_font(dateinlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(dateinlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(dateinlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(dateinlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(dateinlabel, "In : ");
	//Custom button for date services
    ui->metrology_service_dateserviceinbutton = lv_btn_create(ui->metrology_service_dateservicecontainer);
	lv_obj_align_to(ui->metrology_service_dateserviceinbutton, ui->metrology_service_dateservicealertswitch, LV_ALIGN_OUT_BOTTOM_LEFT, -50, 15);
	lv_obj_set_size(ui->metrology_service_dateserviceinbutton, 100, 30);
	lv_obj_set_style_border_width(ui->metrology_service_dateserviceinbutton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->metrology_service_dateserviceinbutton, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_service_dateserviceinbutton, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_t *datebtnlabel = lv_label_create(ui->metrology_service_dateserviceinbutton);
	lv_obj_center(datebtnlabel);
	lv_obj_set_style_text_font(datebtnlabel, &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(datebtnlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(datebtnlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(datebtnlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(datebtnlabel, "CUSTOM");


	//Date service in label
	ui->metrology_service_dateserviceinvalue = lv_label_create(ui->metrology_service_dateservicecontainer);
	lv_obj_align_to(ui->metrology_service_dateserviceinvalue, dateinlabel, LV_ALIGN_OUT_RIGHT_MID, 5, 2);
	lv_obj_set_style_text_font(ui->metrology_service_dateserviceinvalue, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->metrology_service_dateserviceinvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->metrology_service_dateserviceinvalue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_service_dateserviceinvalue, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->metrology_service_dateserviceinvalue, "24 Dec, 2018");

	//Reminder label
	datereminderlabel = lv_label_create(ui->metrology_service_dateservicecontainer);
	lv_obj_align_to(datereminderlabel, dateinlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(datereminderlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(datereminderlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(datereminderlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(datereminderlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(datereminderlabel, "Reminder");

	//Before Alert label
	datebeforealertlabel = lv_label_create(ui->metrology_service_dateservicecontainer);
	lv_obj_align_to(datebeforealertlabel, datereminderlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(datebeforealertlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(datebeforealertlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(datebeforealertlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(datebeforealertlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(datebeforealertlabel, "Before Alert :");
	//Date services dropdown
	ui->metrology_service_dateservicealertdropdown = lv_dropdown_create(ui->metrology_service_dateservicecontainer);
	lv_dropdown_set_options(ui->metrology_service_dateservicealertdropdown,
					 "1 MONTH\n"
					 "2 MONTH\n"
					 "3 MONTH"
					 );
	lv_obj_align_to(ui->metrology_service_dateservicealertdropdown, ui->metrology_service_dateserviceinbutton, LV_ALIGN_OUT_BOTTOM_LEFT, -20, 25);
	lv_obj_set_size(ui->metrology_service_dateservicealertdropdown, 120, 30);
	lv_obj_add_event_cb(ui->metrology_service_dateservicealertdropdown, screen_dropdown_event_cb, LV_EVENT_READY, NULL);
	lv_obj_set_style_bg_color(ui->metrology_service_dateservicealertdropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->metrology_service_dateservicealertdropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_service_dateservicealertdropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_service_dateservicealertdropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_service_dateservicealertdropdown, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->metrology_service_dateservicealertdropdown, &lv_font_montserrat_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->metrology_service_dateservicealertdropdown, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->metrology_service_dateservicealertdropdown, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->metrology_service_dateservicealertdropdown, 2, LV_PART_MAIN|LV_STATE_DEFAULT);


	//Date Action label
	dateactionlabel = lv_label_create(ui->metrology_service_dateservicecontainer);
	lv_obj_align_to(dateactionlabel, datebeforealertlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(dateactionlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(dateactionlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(dateactionlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(dateactionlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(dateactionlabel, "Action");
	//Action switch
	ui->metrology_service_dateserviceactionswitch = lv_switch_create(ui->metrology_service_dateservicecontainer);
	lv_obj_align_to(ui->metrology_service_dateserviceactionswitch, ui->metrology_service_dateservicecontainer, LV_ALIGN_BOTTOM_RIGHT, -5, -15);
	lv_obj_set_size(ui->metrology_service_dateserviceactionswitch, 50, 25);
	lv_obj_set_style_bg_color(ui->metrology_service_dateserviceactionswitch, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_service_dateserviceactionswitch, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->metrology_service_dateserviceactionswitch, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_service_dateserviceactionswitch, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_service_dateserviceactionswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_service_dateserviceactionswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Disable device after alert
	dateactiontxtlabel = lv_label_create(ui->metrology_service_dateservicecontainer);
	lv_obj_align_to(dateactiontxtlabel, dateactionlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 5, 5);
	lv_obj_set_style_text_font(dateactiontxtlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(dateactiontxtlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(dateactiontxtlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(dateactiontxtlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(dateactiontxtlabel, "DISABLE DEVICE AFTER ALERT");

	/************************************************
	 * Date Service Container End
	 ************************************************/


	/************************************************
	 * Volume Service Container Start
	 ************************************************/

	ui->metrology_service_volumeservicecontainer = lv_obj_create(ui->metrology_service_background);
	lv_obj_clear_flag(ui->metrology_service_volumeservicecontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->metrology_service_volumeservicecontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(ui->metrology_service_volumeservicecontainer, ui->metrology_service_dateservicecontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_size(ui->metrology_service_volumeservicecontainer, SCREEN_WIDTH-20, 220);
	lv_obj_set_style_bg_color(ui->metrology_service_volumeservicecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_service_volumeservicecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_service_volumeservicecontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_service_volumeservicecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_service_volumeservicecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Volume service label
	volumecontainerlabel = lv_label_create(ui->metrology_service_volumeservicecontainer);
	lv_obj_align_to(volumecontainerlabel, ui->metrology_service_volumeservicecontainer, LV_ALIGN_TOP_LEFT, 10, 10);
	lv_obj_set_style_text_font(volumecontainerlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(volumecontainerlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumecontainerlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(volumecontainerlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumecontainerlabel, "VOLUME SERVICE");

	//Alert label
	volumealertlabel = lv_label_create(ui->metrology_service_volumeservicecontainer);
	lv_obj_align_to(volumealertlabel, volumecontainerlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_text_font(volumealertlabel, &lv_font_montserrat_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(volumealertlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumealertlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(volumealertlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumealertlabel, "Alert");
	//Alert switch
	ui->metrology_service_volumeservicealertswitch = lv_switch_create(ui->metrology_service_volumeservicecontainer);
	lv_obj_align_to(ui->metrology_service_volumeservicealertswitch, ui->metrology_service_volumeservicecontainer, LV_ALIGN_TOP_RIGHT, -5, 30);
	lv_obj_set_size(ui->metrology_service_volumeservicealertswitch, 50, 25);
	lv_obj_set_style_bg_color(ui->metrology_service_volumeservicealertswitch, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_service_volumeservicealertswitch, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->metrology_service_volumeservicealertswitch, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_service_volumeservicealertswitch, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_service_volumeservicealertswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_service_volumeservicealertswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//on/off label
	volumealertonofflabel = lv_label_create(ui->metrology_service_volumeservicecontainer);
	lv_obj_align_to(volumealertonofflabel, volumealertlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 5, 5);
	lv_obj_set_style_text_font(volumealertonofflabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(volumealertonofflabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumealertonofflabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(volumealertonofflabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumealertonofflabel, "ON/OFF");

	//in label
	volumeinlabel = lv_label_create(ui->metrology_service_volumeservicecontainer);
	lv_obj_align_to(volumeinlabel, volumealertonofflabel, LV_ALIGN_OUT_BOTTOM_LEFT, -5, 15);
	lv_obj_set_style_text_font(volumeinlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(volumeinlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumeinlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(volumeinlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumeinlabel, "In : ");

	//In value
	ui->metrology_service_volumeserviceinvalue = lv_label_create(ui->metrology_service_volumeservicecontainer);
	lv_obj_align_to(ui->metrology_service_volumeserviceinvalue, volumeinlabel, LV_ALIGN_OUT_RIGHT_MID, 5, 2);
	lv_obj_set_style_text_font(ui->metrology_service_volumeserviceinvalue, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->metrology_service_volumeserviceinvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->metrology_service_volumeserviceinvalue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_service_volumeserviceinvalue, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->metrology_service_volumeserviceinvalue, "75000 Liters");
	//Custom button
	ui->metrology_service_volumeserviceinbutton = lv_btn_create(ui->metrology_service_volumeservicecontainer);
	lv_obj_align_to(ui->metrology_service_volumeserviceinbutton, ui->metrology_service_volumeservicealertswitch, LV_ALIGN_OUT_BOTTOM_LEFT, -50, 15);
	lv_obj_set_size(ui->metrology_service_volumeserviceinbutton, 100, 30);
	lv_obj_set_style_border_width(ui->metrology_service_volumeserviceinbutton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->metrology_service_volumeserviceinbutton, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_service_volumeserviceinbutton, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_t *volumebtnlabel = lv_label_create(ui->metrology_service_volumeserviceinbutton);
	lv_obj_center(volumebtnlabel);
	lv_obj_set_style_text_font(volumebtnlabel, &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(volumebtnlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumebtnlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(volumebtnlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumebtnlabel, "CUSTOM");

	//Reminder label
	volumereminderlabel = lv_label_create(ui->metrology_service_volumeservicecontainer);
	lv_obj_align_to(volumereminderlabel, volumeinlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(volumereminderlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(volumereminderlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumereminderlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(volumereminderlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumereminderlabel, "Reminder");

	//Before Alert label
	volumebeforealertlabel = lv_label_create(ui->metrology_service_volumeservicecontainer);
	lv_obj_align_to(volumebeforealertlabel, volumereminderlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(volumebeforealertlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(volumebeforealertlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumebeforealertlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(volumebeforealertlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumebeforealertlabel, "Before Alert :");
	//Before Alert dropdown
	ui->metrology_service_volumeservicealertdropdown = lv_dropdown_create(ui->metrology_service_volumeservicecontainer);
	lv_dropdown_set_options(ui->metrology_service_volumeservicealertdropdown,
					 "1 LITER\n"
					 "2 LITER\n"
					 "3 LITER"
					 );
	lv_obj_align_to(ui->metrology_service_volumeservicealertdropdown, ui->metrology_service_volumeserviceinbutton, LV_ALIGN_OUT_BOTTOM_LEFT, -20, 25);
	lv_obj_set_size(ui->metrology_service_volumeservicealertdropdown, 120, 30);
	lv_obj_add_event_cb(ui->metrology_service_volumeservicealertdropdown, screen_dropdown_event_cb, LV_EVENT_READY, NULL);
	lv_obj_set_style_bg_color(ui->metrology_service_volumeservicealertdropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->metrology_service_volumeservicealertdropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_service_volumeservicealertdropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_service_volumeservicealertdropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_service_volumeservicealertdropdown, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->metrology_service_volumeservicealertdropdown, &lv_font_montserrat_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->metrology_service_volumeservicealertdropdown, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->metrology_service_volumeservicealertdropdown, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->metrology_service_volumeservicealertdropdown, 2, LV_PART_MAIN|LV_STATE_DEFAULT);


	//Action label
	volumeactionlabel = lv_label_create(ui->metrology_service_volumeservicecontainer);
	lv_obj_align_to(volumeactionlabel, volumebeforealertlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(volumeactionlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(volumeactionlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumeactionlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(volumeactionlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumeactionlabel, "Action");
	//Action switch
	ui->metrology_service_volumeserviceactionswitch = lv_switch_create(ui->metrology_service_volumeservicecontainer);
	lv_obj_align_to(ui->metrology_service_volumeserviceactionswitch, ui->metrology_service_volumeservicecontainer, LV_ALIGN_BOTTOM_RIGHT, -5, -15);
	lv_obj_set_size(ui->metrology_service_volumeserviceactionswitch, 50, 25);
	lv_obj_set_style_bg_color(ui->metrology_service_volumeserviceactionswitch, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_service_volumeserviceactionswitch, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->metrology_service_volumeserviceactionswitch, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_service_volumeserviceactionswitch, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_service_volumeserviceactionswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_service_volumeserviceactionswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Disable device after alert label
	volumeactiontxtlabel = lv_label_create(ui->metrology_service_volumeservicecontainer);
	lv_obj_align_to(volumeactiontxtlabel, volumeactionlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 5, 5);
	lv_obj_set_style_text_font(volumeactiontxtlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(volumeactiontxtlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumeactiontxtlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(volumeactiontxtlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumeactiontxtlabel, "DISABLE DEVICE AFTER ALERT");

	/************************************************
	 * Volume Service Container End
	 ************************************************/

	/************************************************
	 * Filter Service Container Start
	 ************************************************/
	ui->metrology_service_filterservicecontainer = lv_obj_create(ui->metrology_service_background);
	lv_obj_clear_flag(ui->metrology_service_filterservicecontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->metrology_service_filterservicecontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(ui->metrology_service_filterservicecontainer, ui->metrology_service_volumeservicecontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_size(ui->metrology_service_filterservicecontainer, SCREEN_WIDTH-20, 267);
	lv_obj_set_style_bg_color(ui->metrology_service_filterservicecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_service_filterservicecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_service_filterservicecontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_service_filterservicecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_service_filterservicecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Filter Test button
	ui->metrology_service_filterservicetestbutton = lv_btn_create(ui->metrology_service_filterservicecontainer);
	lv_obj_align_to(ui->metrology_service_filterservicetestbutton, ui->metrology_service_filterservicecontainer, LV_ALIGN_TOP_LEFT, 50, 5);
	lv_obj_set_size(ui->metrology_service_filterservicetestbutton, 200, 44);
	lv_obj_set_style_border_width(ui->metrology_service_filterservicetestbutton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->metrology_service_filterservicetestbutton, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_service_filterservicetestbutton, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_t *btnlabel = lv_label_create(ui->metrology_service_filterservicetestbutton);
	lv_obj_center(btnlabel);
	lv_obj_set_style_text_font(btnlabel, &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(btnlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(btnlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(btnlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(btnlabel, "FILTER TEST");

	//Filter service label
	filtercontainerlabel = lv_label_create(ui->metrology_service_filterservicecontainer);
	lv_obj_align_to(filtercontainerlabel, ui->metrology_service_filterservicetestbutton, LV_ALIGN_OUT_BOTTOM_LEFT, -40, 10);
	lv_obj_set_style_text_font(filtercontainerlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(filtercontainerlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(filtercontainerlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(filtercontainerlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(filtercontainerlabel, "FILTER SERVICE");

	//Alert label
	filteralertlabel = lv_label_create(ui->metrology_service_filterservicecontainer);
	lv_obj_align_to(filteralertlabel, filtercontainerlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_text_font(filteralertlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(filteralertlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(filteralertlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(filteralertlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(filteralertlabel, "Alert");
	//Alert switch
	ui->metrology_service_filterservicealertswitch = lv_switch_create(ui->metrology_service_filterservicecontainer);
	lv_obj_align_to(ui->metrology_service_filterservicealertswitch, ui->metrology_service_filterservicecontainer, LV_ALIGN_TOP_RIGHT, -5, 80);
	lv_obj_set_size(ui->metrology_service_filterservicealertswitch, 50, 25);
	lv_obj_set_style_bg_color(ui->metrology_service_filterservicealertswitch, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_service_filterservicealertswitch, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->metrology_service_filterservicealertswitch, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_service_filterservicealertswitch, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_service_filterservicealertswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_service_filterservicealertswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//on/off label
	filteralertonofflabel = lv_label_create(ui->metrology_service_filterservicecontainer);
	lv_obj_align_to(filteralertonofflabel, filteralertlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 5, 5);
	lv_obj_set_style_text_font(filteralertonofflabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(filteralertonofflabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(filteralertonofflabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(filteralertonofflabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(filteralertonofflabel, "ON/OFF");

	//in label
	filterinlabel = lv_label_create(ui->metrology_service_filterservicecontainer);
	lv_obj_align_to(filterinlabel, filteralertonofflabel, LV_ALIGN_OUT_BOTTOM_LEFT, -5, 15);
	lv_obj_set_style_text_font(filterinlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(filterinlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(filterinlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(filterinlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(filterinlabel, "In : ");

	//service in value
	ui->metrology_service_filterserviceinvalue = lv_label_create(ui->metrology_service_filterservicecontainer);
	lv_obj_align_to(ui->metrology_service_filterserviceinvalue, filterinlabel, LV_ALIGN_OUT_RIGHT_MID, 5, 2);
	lv_obj_set_style_text_font(ui->metrology_service_filterserviceinvalue, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->metrology_service_filterserviceinvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->metrology_service_filterserviceinvalue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_service_filterserviceinvalue, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->metrology_service_filterserviceinvalue, "90 %");
	//Filter service custom button
	ui->metrology_service_filterserviceinbutton = lv_btn_create(ui->metrology_service_filterservicecontainer);
	lv_obj_align_to(ui->metrology_service_filterserviceinbutton, ui->metrology_service_filterservicealertswitch, LV_ALIGN_OUT_BOTTOM_LEFT, -50, 15);
	lv_obj_set_size(ui->metrology_service_filterserviceinbutton, 100, 30);
	lv_obj_set_style_border_width(ui->metrology_service_filterserviceinbutton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->metrology_service_filterserviceinbutton, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_service_filterserviceinbutton, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_t *filterbtnlabel = lv_label_create(ui->metrology_service_filterserviceinbutton);
	lv_obj_center(filterbtnlabel);
	lv_obj_set_style_text_font(filterbtnlabel, &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(filterbtnlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(filterbtnlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(filterbtnlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(filterbtnlabel, "CUSTOM");


	//Reminder label
	filterreminderlabel = lv_label_create(ui->metrology_service_filterservicecontainer);
	lv_obj_align_to(filterreminderlabel, filterinlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(filterreminderlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(filterreminderlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(filterreminderlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(filterreminderlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(filterreminderlabel, "Reminder");

	//Before Alert
	filterbeforealertlabel = lv_label_create(ui->metrology_service_filterservicecontainer);
	lv_obj_align_to(filterbeforealertlabel, filterreminderlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(filterbeforealertlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(filterbeforealertlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(filterbeforealertlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(filterbeforealertlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(filterbeforealertlabel, "Before Alert :");
	//Before ALert dropdown
	ui->metrology_service_filterserivealertdropdown = lv_dropdown_create(ui->metrology_service_filterservicecontainer);
	lv_dropdown_set_options(ui->metrology_service_filterserivealertdropdown,
					 "80%\n"
					 "90%\n"
					 "100%"
					 );
	lv_obj_align_to(ui->metrology_service_filterserivealertdropdown, ui->metrology_service_filterserviceinbutton, LV_ALIGN_OUT_BOTTOM_LEFT, -20, 25);
	lv_obj_set_size(ui->metrology_service_filterserivealertdropdown, 120, 30);
	lv_obj_add_event_cb(ui->metrology_service_filterserivealertdropdown, screen_dropdown_event_cb, LV_EVENT_READY, NULL);
	lv_obj_set_style_bg_color(ui->metrology_service_filterserivealertdropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->metrology_service_filterserivealertdropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_service_filterserivealertdropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_service_filterserivealertdropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_service_filterserivealertdropdown, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->metrology_service_filterserivealertdropdown, &lv_font_montserrat_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->metrology_service_filterserivealertdropdown, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->metrology_service_filterserivealertdropdown, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->metrology_service_filterserivealertdropdown, 2, LV_PART_MAIN|LV_STATE_DEFAULT);


	//Action label
	filteractionlabel = lv_label_create(ui->metrology_service_filterservicecontainer);
	lv_obj_align_to(filteractionlabel, filterbeforealertlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(filteractionlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(filteractionlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(filteractionlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(filteractionlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(filteractionlabel, "Action");
	//Action switch
	ui->metrology_service_filterserviceactionswitch = lv_switch_create(ui->metrology_service_filterservicecontainer);
	lv_obj_align_to(ui->metrology_service_filterserviceactionswitch, ui->metrology_service_filterservicecontainer, LV_ALIGN_BOTTOM_RIGHT, -5, -15);
	lv_obj_set_size(ui->metrology_service_filterserviceactionswitch, 50, 25);
	lv_obj_set_style_bg_color(ui->metrology_service_filterserviceactionswitch, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_service_filterserviceactionswitch, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->metrology_service_filterserviceactionswitch, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_service_filterserviceactionswitch, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_service_filterserviceactionswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_service_filterserviceactionswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Disable device after alert
	filteractiontxtlabel = lv_label_create(ui->metrology_service_filterservicecontainer);
	lv_obj_align_to(filteractiontxtlabel, filteractionlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 5, 5);
	lv_obj_set_style_text_font(filteractiontxtlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(filteractiontxtlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(filteractiontxtlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(filteractiontxtlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(filteractiontxtlabel, "DISABLE DEVICE AFTER ALERT");
	/************************************************
	 * Filter Service Container end
	 ************************************************/

	/********************************************
	 *
	 * metrology service Screen design End
	 *
	**********************************************/

	/***************Events Initialization******************/
	events_init_metrology_service(ui);
}

/***********************************************************************************************************************
 * End of file
 ***********************************************************************************************************************/
