
/*
 * setup_src_dashboard.c
 *
 *  Created on: 20-Jun-2022
 *      Author: sagar
 */

/***********************************************************************************************************************
 * Pragma directive
 ***********************************************************************************************************************/

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
 * Function to draw parameter screen
 */
void setup_scr_parameter(lv_ui *ui){

	//parameter Screen main object
	ui->parameter = lv_obj_create(NULL);
	static lv_style_t style_parameter_default;
	if (style_parameter_default.prop_cnt > 1)
		lv_style_reset(&style_parameter_default);
	else
		lv_style_init(&style_parameter_default);
	lv_style_set_bg_color(&style_parameter_default, ESPUPM_COLOR_WHITE);
	lv_style_set_bg_opa(&style_parameter_default, SCREEN_MIN_OPACITY);
	lv_obj_add_style(ui->parameter, &style_parameter_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	/*******************************************************************
	 *
	 * Parameter Screen main container code start
	 *
	 *******************************************************************/
	//parameter Screen Background
	ui->parameter_background = lv_obj_create(ui->parameter);
	lv_obj_set_align(ui->parameter_background, LV_ALIGN_CENTER);
	lv_obj_set_size(ui->parameter_background, SCREEN_WIDTH, SCREEN_HEIGHT);
	lv_obj_set_scrollbar_mode(ui->parameter_background, LV_SCROLLBAR_MODE_OFF);
	static lv_style_t style_parameter_background_default;
	if (style_parameter_background_default.prop_cnt > 1)
		lv_style_reset(&style_parameter_background_default);
	else
		lv_style_init(&style_parameter_background_default);
	lv_style_set_radius(&style_parameter_background_default, 0);
	lv_style_set_bg_color(&style_parameter_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_color(&style_parameter_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_dir(&style_parameter_background_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_parameter_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_border_color(&style_parameter_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_border_width(&style_parameter_background_default, 0);
	lv_style_set_border_opa(&style_parameter_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_pad_left(&style_parameter_background_default, 0);
	lv_style_set_pad_right(&style_parameter_background_default, 0);
	lv_style_set_pad_top(&style_parameter_background_default, 0);
	lv_style_set_pad_bottom(&style_parameter_background_default, 0);
	lv_obj_add_style(ui->parameter_background, &style_parameter_background_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Parameter Screen Header
	setup_draw_header(ui, ui->parameter_background);


	//Parameter Screen object for left arrow, parameter text and menu symbol
	setup_draw_title(ui, ui->parameter_background, "PARAMETER", &parameter_icon, ESPUPM_BACKGROUND_COLOR);
	/*******************************Title Container End**************************************/

	/******************************************
	 * Settings Container Start
	 * **************************************/
	//Container with background color
	ui->parameter_settingscontainer = lv_obj_create(ui->parameter_background);
	lv_obj_clear_flag(ui->parameter_settingscontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_align_to(ui->parameter_settingscontainer, ui->title_container, LV_ALIGN_OUT_BOTTOM_LEFT, 10, 0);
	lv_obj_set_size(ui->parameter_settingscontainer, SCREEN_WIDTH-20, 600);
	lv_obj_set_style_bg_color(ui->parameter_settingscontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->parameter_settingscontainer, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->parameter_settingscontainer, LV_OPA_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->parameter_settingscontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->parameter_settingscontainer, 5, LV_PART_MAIN|LV_STATE_DEFAULT);


	/*************************************
	 * Buzzer Container Start
	 * ***********************************/
	static lv_obj_t *buzzersymbol;
	static lv_obj_t *buzzerlabel;
	static lv_obj_t *buzzeronofflabel;
	//Buzzer Container design code
	ui->parameter_buzzercontainer = lv_obj_create(ui->parameter_settingscontainer);
	lv_obj_clear_flag(ui->parameter_buzzercontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->parameter_buzzercontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align(ui->parameter_buzzercontainer, LV_ALIGN_TOP_MID, 0, 10);
	lv_obj_set_size(ui->parameter_buzzercontainer, 300, 50);
	lv_obj_set_style_bg_color(ui->parameter_buzzercontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->parameter_buzzercontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->parameter_buzzercontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->parameter_buzzercontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Buzzer symbol design code
	buzzersymbol = lv_label_create(ui->parameter_buzzercontainer);
	lv_obj_set_size(buzzersymbol, 36, 36);
	lv_obj_align(buzzersymbol, LV_ALIGN_LEFT_MID, 10, 0);
	lv_obj_set_style_text_color(buzzersymbol, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(buzzersymbol, &lv_font_montserrat_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(buzzersymbol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(buzzersymbol, LV_SYMBOL_VOLUME_MAX);
	//Buzzer label design code
	buzzerlabel = lv_label_create(ui->parameter_buzzercontainer);
	lv_obj_align_to(buzzerlabel, ui->parameter_buzzercontainer, LV_ALIGN_TOP_LEFT, 60, 5);
	lv_obj_set_style_text_color(buzzerlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(buzzerlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(buzzerlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(buzzerlabel, "BUZZER");
	//Buzzer ON/OFF label design code
	buzzeronofflabel = lv_label_create(ui->parameter_buzzercontainer);
	lv_obj_align_to(buzzeronofflabel, ui->parameter_buzzercontainer, LV_ALIGN_BOTTOM_LEFT, 70, -5);
	lv_obj_set_style_text_color(buzzeronofflabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(buzzeronofflabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(buzzeronofflabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(buzzeronofflabel, "ON/OFF");
	//Buzzer switch design code
	ui->parameter_buzzerswitch = lv_switch_create(ui->parameter_buzzercontainer);
	lv_obj_align_to(ui->parameter_buzzerswitch, ui->parameter_buzzercontainer, LV_ALIGN_RIGHT_MID, -10, 0);
	lv_obj_set_size(ui->parameter_buzzerswitch, 50, 25);
	lv_obj_set_style_bg_color(ui->parameter_buzzerswitch, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->parameter_buzzerswitch, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->parameter_buzzerswitch, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->parameter_buzzerswitch, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->parameter_buzzerswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->parameter_buzzerswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	/*************************************
	 * Buzzer Container End
	 * ***********************************/


	lv_obj_t * hor_line = lv_line_create(ui->parameter_settingscontainer);
	static lv_point_t p[] = {{-20, 5}, {238, 5}};
	lv_line_set_points(hor_line, p, 2);
	lv_obj_align_to(hor_line,ui->parameter_buzzercontainer, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
	static lv_style_t style_hor_line;
	lv_style_init(&style_hor_line);
	lv_style_set_line_color(&style_hor_line, ESPUPM_COLOR_GREY);
	lv_style_set_line_width(&style_hor_line, 3);
	lv_style_set_line_rounded(&style_hor_line, true);
	lv_obj_add_style(hor_line, &style_hor_line, LV_PART_MAIN);

	/*************************************
	 * LED Container Start
	 * ***********************************/
	//LED Container design code
	static lv_obj_t *ledsymbol;
	static lv_obj_t *ledlabel;
	static lv_obj_t *ledonofflabel;
	ui->parameter_ledcontainer = lv_obj_create(ui->parameter_settingscontainer);
	lv_obj_clear_flag(ui->parameter_ledcontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->parameter_ledcontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(ui->parameter_ledcontainer, ui->parameter_buzzercontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_size(ui->parameter_ledcontainer, 300, 50);
	lv_obj_set_style_bg_color(ui->parameter_ledcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->parameter_ledcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->parameter_ledcontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->parameter_ledcontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//LED symbol design code
	ledsymbol = lv_img_create(ui->parameter_ledcontainer);
	lv_img_set_src(ledsymbol, &led_icon);
	lv_obj_align(ledsymbol, LV_ALIGN_LEFT_MID, 10, 0);
	lv_obj_set_style_img_recolor_opa(ledsymbol, LV_OPA_MAX, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ledsymbol, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ledsymbol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//LED label design code
	ledlabel = lv_label_create(ui->parameter_ledcontainer);
	lv_obj_align_to(ledlabel, ui->parameter_ledcontainer, LV_ALIGN_TOP_LEFT, 60, 5);
	lv_obj_set_style_text_color(ledlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ledlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ledlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ledlabel, "LED");
	//LED ON/OFF label design code
	ledonofflabel = lv_label_create(ui->parameter_ledcontainer);
	lv_obj_align_to(ledonofflabel, ui->parameter_ledcontainer, LV_ALIGN_BOTTOM_LEFT, 70, -5);
	lv_obj_set_style_text_color(ledonofflabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ledonofflabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ledonofflabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ledonofflabel, "ON/OFF");
	//LED switch design code
	ui->parameter_ledswitch = lv_switch_create(ui->parameter_ledcontainer);
	lv_obj_align_to(ui->parameter_ledswitch, ui->parameter_ledcontainer, LV_ALIGN_RIGHT_MID, -10, 0);
	lv_obj_set_size(ui->parameter_ledswitch, 50, 25);
	lv_obj_set_style_bg_color(ui->parameter_ledswitch, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->parameter_ledswitch, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->parameter_ledswitch, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->parameter_ledswitch, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->parameter_ledswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->parameter_ledswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	/*************************************
	 * LED Container End
	 * ***********************************/

	// horizaontal line
	hor_line = lv_line_create(ui->parameter_settingscontainer);
	lv_line_set_points(hor_line, p, 2);
	lv_obj_align_to(hor_line,ui->parameter_ledcontainer, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
	lv_obj_add_style(hor_line, &style_hor_line, LV_PART_MAIN);


	/*************************************
	 * Wifi Container start
	 * ***********************************/
    //Wifi Container design code
	static lv_obj_t *wifisymbol;
	static lv_obj_t *wifilabel;
	static lv_obj_t *wifionofflabel;
	ui->parameter_wificontainer = lv_obj_create(ui->parameter_settingscontainer);
	lv_obj_clear_flag(ui->parameter_wificontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->parameter_wificontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(ui->parameter_wificontainer, ui->parameter_ledcontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_size(ui->parameter_wificontainer, 300, 50);
	lv_obj_set_style_bg_color(ui->parameter_wificontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->parameter_wificontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->parameter_wificontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->parameter_wificontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Wifi symbol design code
	wifisymbol = lv_img_create(ui->parameter_wificontainer);
	lv_img_set_src(wifisymbol, &wifi_icon);
	lv_obj_align(wifisymbol, LV_ALIGN_LEFT_MID, 10, 0);
	lv_obj_set_style_img_recolor_opa(wifisymbol, LV_OPA_MAX, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(wifisymbol, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(wifisymbol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Wifi label design code
	wifilabel = lv_label_create(ui->parameter_wificontainer);
	lv_obj_align_to(wifilabel, ui->parameter_wificontainer, LV_ALIGN_TOP_LEFT, 60, 5);
	lv_obj_set_style_text_color(wifilabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(wifilabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(wifilabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(wifilabel, "WIFI");
	//WiFi ON/OFF label design code
	wifionofflabel = lv_label_create(ui->parameter_wificontainer);
	lv_obj_align_to(wifionofflabel, ui->parameter_wificontainer, LV_ALIGN_BOTTOM_LEFT, 70, -5);
	lv_obj_set_style_text_color(wifionofflabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(wifionofflabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(wifionofflabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(wifionofflabel, "ON/OFF");
	//Wifi switch design code
	ui->parameter_wifiswitch = lv_switch_create(ui->parameter_wificontainer);
	lv_obj_align_to(ui->parameter_wifiswitch, ui->parameter_wificontainer, LV_ALIGN_RIGHT_MID, -10, 0);
	lv_obj_set_size(ui->parameter_wifiswitch, 50, 25);
	lv_obj_set_style_bg_color(ui->parameter_wifiswitch, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->parameter_wifiswitch, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->parameter_wifiswitch, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->parameter_wifiswitch, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->parameter_wifiswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->parameter_wifiswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	 /*************************************
	 * Wifi Container end
	 * ***********************************/

    //horizontal line
	hor_line = lv_line_create(ui->parameter_settingscontainer);
	lv_line_set_points(hor_line, p, 2);
	lv_obj_align_to(hor_line,ui->parameter_wificontainer, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
	lv_obj_add_style(hor_line, &style_hor_line, LV_PART_MAIN);


	/*************************************
	 * External FAN Container start
	 * ***********************************/
	//fan Container design code
	static lv_obj_t *fansymbol;
	static lv_obj_t *fanlabel;
	static lv_obj_t *fanonofflabel;
	ui->parameter_fancontainer = lv_obj_create(ui->parameter_settingscontainer);
	lv_obj_clear_flag(ui->parameter_fancontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->parameter_fancontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(ui->parameter_fancontainer, ui->parameter_wificontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_size(ui->parameter_fancontainer, 300, 50);
	lv_obj_set_style_bg_color(ui->parameter_fancontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->parameter_fancontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->parameter_fancontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->parameter_fancontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//FAN symbol design code
	fansymbol = lv_img_create(ui->parameter_fancontainer);
	lv_img_set_src(fansymbol, &fan_icon);
	lv_obj_align(fansymbol, LV_ALIGN_LEFT_MID, 10, 0);
	lv_obj_set_style_img_recolor_opa(fansymbol, LV_OPA_MAX, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(fansymbol, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(fansymbol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//FAN label design code
	fanlabel = lv_label_create(ui->parameter_fancontainer);
	lv_obj_align_to(fanlabel, ui->parameter_fancontainer, LV_ALIGN_TOP_LEFT, 60, 5);
	lv_obj_set_style_text_color(fanlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(fanlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(fanlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(fanlabel, "EXTERNAL FAN");
	//FAN ON/OFF label design code
	fanonofflabel = lv_label_create(ui->parameter_fancontainer);
	lv_obj_align_to(fanonofflabel, ui->parameter_fancontainer, LV_ALIGN_BOTTOM_LEFT, 70, -5);
	lv_obj_set_style_text_color(fanonofflabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(fanonofflabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(fanonofflabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(fanonofflabel, "ON/OFF");
	//Wifi switch design code
	ui->parameter_fanswitch = lv_switch_create(ui->parameter_fancontainer);
	lv_obj_align_to(ui->parameter_fanswitch, ui->parameter_fancontainer, LV_ALIGN_RIGHT_MID, -10, 0);
	lv_obj_set_size(ui->parameter_fanswitch, 50, 25);
	lv_obj_set_style_bg_color(ui->parameter_fanswitch, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->parameter_fanswitch, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->parameter_fanswitch, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->parameter_fanswitch, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->parameter_fanswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->parameter_fanswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	 /*************************************
	 * FAN Container end
	 * ***********************************/

	//horizontal line
	hor_line = lv_line_create(ui->parameter_settingscontainer);
	lv_line_set_points(hor_line, p, 2);
	lv_obj_align_to(hor_line,ui->parameter_fancontainer, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
	lv_obj_add_style(hor_line, &style_hor_line, LV_PART_MAIN);


	/*************************************
	 * Sleep Container start
	 * ***********************************/
	//Sleep Container design code
	static lv_obj_t *sleepsymbol;
	static lv_obj_t *sleeplabel;
	static lv_obj_t *sleeponofflabel;
	ui->parameter_sleepcontainer = lv_obj_create(ui->parameter_settingscontainer);
	lv_obj_clear_flag(ui->parameter_sleepcontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->parameter_sleepcontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(ui->parameter_sleepcontainer, ui->parameter_fancontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_size(ui->parameter_sleepcontainer, 300, 50);
	lv_obj_set_style_bg_color(ui->parameter_sleepcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->parameter_sleepcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->parameter_sleepcontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->parameter_sleepcontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Sleep symbol design code
	sleepsymbol = lv_img_create(ui->parameter_sleepcontainer);
	lv_img_set_src(sleepsymbol, &sleep_icon);
	lv_obj_align(sleepsymbol, LV_ALIGN_LEFT_MID, 10, 0);
	lv_obj_set_style_img_recolor_opa(sleepsymbol, LV_OPA_MAX, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(sleepsymbol, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(sleepsymbol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Sleep label design code
	sleeplabel = lv_label_create(ui->parameter_sleepcontainer);
	lv_obj_align_to(sleeplabel, ui->parameter_sleepcontainer, LV_ALIGN_TOP_LEFT, 60, 5);
	lv_obj_set_style_text_color(sleeplabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(sleeplabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(sleeplabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(sleeplabel, "SLEEP");
	//Sleep ON/OFF label design code
	sleeponofflabel = lv_label_create(ui->parameter_sleepcontainer);
	lv_obj_align_to(sleeponofflabel, ui->parameter_sleepcontainer, LV_ALIGN_BOTTOM_LEFT, 70, -5);
	lv_obj_set_style_text_color(sleeponofflabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(sleeponofflabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(sleeponofflabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(sleeponofflabel, "ON/OFF");
	//Sleep switch design code
	ui->parameter_sleepswitch = lv_switch_create(ui->parameter_sleepcontainer);
	lv_obj_align_to(ui->parameter_sleepswitch, ui->parameter_sleepcontainer, LV_ALIGN_RIGHT_MID, -10, 0);
	lv_obj_set_size(ui->parameter_sleepswitch, 50, 25);
	lv_obj_set_style_bg_color(ui->parameter_sleepswitch, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->parameter_sleepswitch, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->parameter_sleepswitch, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->parameter_sleepswitch, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->parameter_sleepswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->parameter_sleepswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	 /*************************************
	 * Sleep Container end
	 * ***********************************/

	//horizontal line
	hor_line = lv_line_create(ui->parameter_settingscontainer);
	lv_line_set_points(hor_line, p, 2);
	lv_obj_align_to(hor_line,ui->parameter_sleepcontainer, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
	lv_obj_add_style(hor_line, &style_hor_line, LV_PART_MAIN);

	/*************************************
	 * Language Container start
	 * ***********************************/
	//Language Container design code
	static lv_obj_t *languagesymbol;
	static lv_obj_t *languagelabel;
	static lv_obj_t *languagespeaklabel;
	ui->parameter_languagecontainer = lv_obj_create(ui->parameter_settingscontainer);
	lv_obj_clear_flag(ui->parameter_languagecontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->parameter_languagecontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(ui->parameter_languagecontainer, ui->parameter_sleepcontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_size(ui->parameter_languagecontainer, 300, 50);
	lv_obj_set_style_bg_color(ui->parameter_languagecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->parameter_languagecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->parameter_languagecontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->parameter_languagecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Language symbol design code
	languagesymbol = lv_img_create(ui->parameter_languagecontainer);
	lv_img_set_src(languagesymbol, &language_icon);
	lv_obj_align(languagesymbol, LV_ALIGN_LEFT_MID, 10, 0);
	lv_obj_set_style_img_recolor_opa(languagesymbol, LV_OPA_MAX, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(languagesymbol, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(languagesymbol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Language label design code
	languagelabel = lv_label_create(ui->parameter_languagecontainer);
	lv_obj_align_to(languagelabel, ui->parameter_languagecontainer, LV_ALIGN_TOP_LEFT, 60, 5);
	lv_obj_set_style_text_color(languagelabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(languagelabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(languagelabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(languagelabel, "LANGUAGE");
	//Language ON/OFF label design code
	languagespeaklabel = lv_label_create(ui->parameter_languagecontainer);
	lv_obj_align_to(languagespeaklabel, ui->parameter_languagecontainer, LV_ALIGN_BOTTOM_LEFT, 65, -5);
	lv_obj_set_style_text_color(languagespeaklabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(languagespeaklabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(languagespeaklabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(languagespeaklabel, "SPEAK LANGUAGE");
	//Language dropdown design code
	ui->parameter_languagedropdown = lv_dropdown_create(ui->parameter_settingscontainer);
	lv_dropdown_set_options(ui->parameter_languagedropdown,
					 "English\n"
					 "French\n"
					 "Italian"
					 );
	lv_obj_align_to(ui->parameter_languagedropdown, ui->parameter_languagecontainer, LV_ALIGN_RIGHT_MID, 15, 0);
	lv_obj_set_size(ui->parameter_languagedropdown, 100, 30);
	lv_obj_add_event_cb(ui->parameter_languagedropdown, screen_dropdown_event_cb, LV_EVENT_READY, NULL);
	lv_obj_set_style_bg_color(ui->parameter_languagedropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->parameter_languagedropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->parameter_languagedropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->parameter_languagedropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->parameter_languagedropdown, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->parameter_languagedropdown, &lv_font_montserrat_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->parameter_languagedropdown, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->parameter_languagedropdown, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->parameter_languagedropdown, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	 /*************************************
	 * Language Container end
	 * ***********************************/

	//horizontal line
	hor_line = lv_line_create(ui->parameter_settingscontainer);
	lv_line_set_points(hor_line, p, 2);
	lv_obj_align_to(hor_line,ui->parameter_languagecontainer, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
	lv_obj_add_style(hor_line, &style_hor_line, LV_PART_MAIN);


	/*************************************
	 * Sleep timer Container start
	 * ***********************************/
	//Sleep timer Container design code
	static lv_obj_t *sleeptimersymbol;
	static lv_obj_t *sleeptimerlabel;
	static lv_obj_t *sleeptimeradjustlabel;
	ui->parameter_sleeptimercontainer = lv_obj_create(ui->parameter_settingscontainer);
	lv_obj_clear_flag(ui->parameter_sleeptimercontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->parameter_sleeptimercontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(ui->parameter_sleeptimercontainer, ui->parameter_languagecontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_size(ui->parameter_sleeptimercontainer, 300, 50);
	lv_obj_set_style_bg_color(ui->parameter_sleeptimercontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->parameter_sleeptimercontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->parameter_sleeptimercontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->parameter_sleeptimercontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Sleeptimer symbol design code
	sleeptimersymbol = lv_img_create(ui->parameter_sleeptimercontainer);
	lv_img_set_src(sleeptimersymbol, &timer_icon);
	lv_obj_align(sleeptimersymbol, LV_ALIGN_LEFT_MID, 10, 0);
	lv_obj_set_style_img_recolor_opa(sleeptimersymbol, LV_OPA_MAX, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(sleeptimersymbol, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(sleeptimersymbol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Sleeptimer label design code
	sleeptimerlabel = lv_label_create(ui->parameter_sleeptimercontainer);
	lv_obj_align_to(sleeptimerlabel, ui->parameter_sleeptimercontainer, LV_ALIGN_TOP_LEFT, 60, 5);
	lv_obj_set_style_text_color(sleeptimerlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(sleeptimerlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(sleeptimerlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(sleeptimerlabel, "SLEEP TIMER");
	//Sleep timer dropdown label design code
	sleeptimeradjustlabel = lv_label_create(ui->parameter_sleeptimercontainer);
	lv_obj_align_to(sleeptimeradjustlabel, ui->parameter_sleeptimercontainer, LV_ALIGN_BOTTOM_LEFT, 65, -5);
	lv_obj_set_style_text_color(sleeptimeradjustlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(sleeptimeradjustlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(sleeptimeradjustlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(sleeptimeradjustlabel, "ADJUST TIMER");
	//Sleep dropdown design code
	ui->parameter_sleeptimerdropdown = lv_dropdown_create(ui->parameter_sleeptimercontainer);
	lv_dropdown_set_options(ui->parameter_sleeptimerdropdown,
					 "1 Min\n"
					 "30 Min\n"
					 "60 Min"
					 );
	lv_obj_align_to(ui->parameter_sleeptimerdropdown, ui->parameter_sleeptimercontainer, LV_ALIGN_RIGHT_MID, 15, 0);
	lv_obj_set_size(ui->parameter_sleeptimerdropdown, 100, 30);
	lv_obj_add_event_cb(ui->parameter_sleeptimerdropdown, screen_dropdown_event_cb, LV_EVENT_READY, NULL);
	lv_obj_set_style_bg_color(ui->parameter_sleeptimerdropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->parameter_sleeptimerdropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->parameter_sleeptimerdropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->parameter_sleeptimerdropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->parameter_sleeptimerdropdown, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->parameter_sleeptimerdropdown, &lv_font_montserrat_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->parameter_sleeptimerdropdown, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->parameter_sleeptimerdropdown, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->parameter_sleeptimerdropdown, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	 /*************************************
	 * Sleep timer Container end
	 * ***********************************/

    //horizontal line
	hor_line = lv_line_create(ui->parameter_settingscontainer);
	lv_line_set_points(hor_line, p, 2);
	lv_obj_align_to(hor_line,ui->parameter_sleeptimercontainer, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
	lv_obj_add_style(hor_line, &style_hor_line, LV_PART_MAIN);


	/*************************************
	 * Luminosity timer Container start
	 * ***********************************/
	//Luminosity timer Container design code
	static lv_obj_t *luminositysymbol;
	static lv_obj_t *luminositylabel;
	static lv_obj_t *adjustscreenluminositylabel;
	ui->parameter_luminositycontainer = lv_obj_create(ui->parameter_settingscontainer);
	lv_obj_clear_flag(ui->parameter_luminositycontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->parameter_luminositycontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(ui->parameter_luminositycontainer, ui->parameter_sleeptimercontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_size(ui->parameter_luminositycontainer, 300, 50);
	lv_obj_set_style_bg_color(ui->parameter_luminositycontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->parameter_luminositycontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->parameter_luminositycontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->parameter_luminositycontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Luminosity symbol design code
	luminositysymbol = lv_img_create(ui->parameter_luminositycontainer);
	lv_img_set_src(luminositysymbol, &luminosity_icon);
	lv_obj_align(luminositysymbol, LV_ALIGN_LEFT_MID, 10, 0);
	lv_obj_set_style_img_recolor_opa(luminositysymbol, LV_OPA_MAX, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(luminositysymbol, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(luminositysymbol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Luminosity label design code
	luminositylabel = lv_label_create(ui->parameter_luminositycontainer);
	lv_obj_align_to(luminositylabel, ui->parameter_luminositycontainer, LV_ALIGN_TOP_LEFT, 60, 5);
	lv_obj_set_style_text_color(luminositylabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(luminositylabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(luminositylabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(luminositylabel, "LUMINOSITY");
	//Luminosity text design code
	adjustscreenluminositylabel = lv_label_create(ui->parameter_luminositycontainer);
	lv_obj_align_to(adjustscreenluminositylabel, ui->parameter_luminositycontainer, LV_ALIGN_BOTTOM_LEFT, 65, -5);
	lv_obj_set_width(adjustscreenluminositylabel, 100);
	lv_obj_set_style_text_color(adjustscreenluminositylabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(adjustscreenluminositylabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(adjustscreenluminositylabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_long_mode(adjustscreenluminositylabel, LV_LABEL_LONG_WRAP);
	lv_label_set_text(adjustscreenluminositylabel, "ADJUST SCREEM LUMINOSITY");
	//Luminosity bar
	ui->parameter_luminosityslider = lv_slider_create(ui->parameter_luminositycontainer);
	lv_obj_set_width(ui->parameter_luminosityslider, 90);
	lv_obj_align_to(ui->parameter_luminosityslider, ui->parameter_luminositycontainer, LV_ALIGN_RIGHT_MID, -20, 0);
	lv_obj_set_style_bg_color(ui->parameter_luminosityslider, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->parameter_luminosityslider, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->parameter_luminosityslider, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->parameter_luminosityslider, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->parameter_luminosityslider, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->parameter_luminosityslider, ESPUPM_COLOR_BLUE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->parameter_luminosityslider, ESPUPM_COLOR_WHITE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->parameter_luminosityslider, ESPUPM_COLOR_WHITE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->parameter_luminosityslider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->parameter_luminosityslider, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->parameter_luminosityslider,0, 100);
	lv_slider_set_value(ui->parameter_luminosityslider,50,false);
	 /*************************************
	 * Luminosity timer Container end
	 * ***********************************/
     //horizontal line
	hor_line = lv_line_create(ui->parameter_settingscontainer);
	lv_line_set_points(hor_line, p, 2);
	lv_obj_align_to(hor_line,ui->parameter_luminositycontainer, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
	lv_obj_add_style(hor_line, &style_hor_line, LV_PART_MAIN);

	/*************************************
	 * Contrast timer Container start
	 * ***********************************/
	//COntrast Container design code
	static lv_obj_t *contrastsymbol;
	static lv_obj_t *contrastlabel;
	static lv_obj_t *adjustscreencontrastlabel;
	ui->parameter_contrastcontainer = lv_obj_create(ui->parameter_settingscontainer);
	lv_obj_clear_flag(ui->parameter_contrastcontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->parameter_contrastcontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(ui->parameter_contrastcontainer, ui->parameter_luminositycontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_size(ui->parameter_contrastcontainer, 300, 50);
	lv_obj_set_style_bg_color(ui->parameter_contrastcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->parameter_contrastcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->parameter_contrastcontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->parameter_contrastcontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Contrast symbol design code
	contrastsymbol = lv_img_create(ui->parameter_contrastcontainer);
	lv_img_set_src(contrastsymbol, &contrast_icon);
	lv_obj_align(contrastsymbol, LV_ALIGN_LEFT_MID, 10, 0);
	lv_obj_set_style_img_recolor_opa(contrastsymbol, LV_OPA_MAX, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(contrastsymbol, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(contrastsymbol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Contrast label design code
	contrastlabel = lv_label_create(ui->parameter_contrastcontainer);
	lv_obj_align_to(contrastlabel, ui->parameter_contrastcontainer, LV_ALIGN_TOP_LEFT, 60, 5);
	lv_obj_set_style_text_color(contrastlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(contrastlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(contrastlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(contrastlabel, "CONTRAST");
	//Contrast text design code
	adjustscreencontrastlabel = lv_label_create(ui->parameter_contrastcontainer);
	lv_obj_align_to(adjustscreencontrastlabel, ui->parameter_contrastcontainer, LV_ALIGN_BOTTOM_LEFT, 65, -5);
	lv_obj_set_width(adjustscreencontrastlabel, 100);
	lv_obj_set_style_text_color(adjustscreencontrastlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(adjustscreencontrastlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(adjustscreencontrastlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_long_mode(adjustscreencontrastlabel, LV_LABEL_LONG_WRAP);
	lv_label_set_text(adjustscreencontrastlabel, "ADJUST SCREEM CONTRAST");
	//Contrast Slider
	ui->parameter_contrastslider = lv_slider_create(ui->parameter_contrastcontainer);
	lv_obj_set_width(ui->parameter_contrastslider, 90);
	lv_obj_align_to(ui->parameter_contrastslider, ui->parameter_contrastcontainer, LV_ALIGN_RIGHT_MID, -20, 0);
	lv_obj_set_style_bg_color(ui->parameter_contrastslider, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->parameter_contrastslider, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->parameter_contrastslider, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->parameter_contrastslider, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->parameter_contrastslider, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->parameter_contrastslider, ESPUPM_COLOR_BLUE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->parameter_contrastslider, ESPUPM_COLOR_WHITE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->parameter_contrastslider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->parameter_contrastslider, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->parameter_contrastslider, ESPUPM_COLOR_WHITE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->parameter_contrastslider,0, 100);
	lv_slider_set_value(ui->parameter_contrastslider,50,false);
	 /*************************************
	 * Contrast Container end
	 * ***********************************/

	/******************************************************
	 *
	 * Settings Container End
	 *
	 * ****************************************************/


	/******Events Initialization****************/
	events_init_parameter(ui);
}


/***********************************************************************************************************************
 * End of file
 ***********************************************************************************************************************/
