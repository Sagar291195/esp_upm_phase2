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
	lv_style_set_text_font(&style_screen_ddlist_1_extra_list_selected_default, &lv_font_montserrat_16_semibold);
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
	lv_style_set_text_font(&style_screen_ddlist_1_extra_list_main_default, &lv_font_montserrat_16_semibold);
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
 * Function to draw metrology settings screen
 */
void setup_scr_metrology_settings(lv_ui *ui){
	//metrology settings Screen main object
	ui->metrology_settings = lv_obj_create(NULL);
	static lv_style_t style_metrology_settings_default;
	if (style_metrology_settings_default.prop_cnt > 1)
		lv_style_reset(&style_metrology_settings_default);
	else
		lv_style_init(&style_metrology_settings_default);
	lv_style_set_bg_color(&style_metrology_settings_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_metrology_settings_default, SCREEN_MIN_OPACITY);
	lv_obj_add_style(ui->metrology_settings, &style_metrology_settings_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	/*********************************************
	 *
	 * Metrology settings Screen design Start
	 *
	 * ******************************************/
	//metrology settings Screen Background
	ui->metrology_settings_background = lv_obj_create(ui->metrology_settings);
	lv_obj_set_align(ui->metrology_settings_background, LV_ALIGN_CENTER);
	lv_obj_set_size(ui->metrology_settings_background, SCREEN_WIDTH, SCREEN_HEIGHT);
	static lv_style_t style_metrology_settings_background_default;
	if (style_metrology_settings_background_default.prop_cnt > 1)
		lv_style_reset(&style_metrology_settings_background_default);
	else
		lv_style_init(&style_metrology_settings_background_default);
	lv_style_set_radius(&style_metrology_settings_background_default, 0);
	lv_style_set_bg_color(&style_metrology_settings_background_default, ESPUPM_COLOR_BLUE);
	lv_style_set_bg_grad_color(&style_metrology_settings_background_default, ESPUPM_COLOR_BLUE);
	lv_style_set_bg_grad_dir(&style_metrology_settings_background_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_metrology_settings_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_border_color(&style_metrology_settings_background_default, ESPUPM_COLOR_BLUE);
	lv_style_set_border_width(&style_metrology_settings_background_default, 0);
	lv_style_set_border_opa(&style_metrology_settings_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_pad_left(&style_metrology_settings_background_default, 0);
	lv_style_set_pad_right(&style_metrology_settings_background_default, 0);
	lv_style_set_pad_top(&style_metrology_settings_background_default, 0);
	lv_style_set_pad_bottom(&style_metrology_settings_background_default, 0);
	lv_obj_add_style(ui->metrology_settings_background, &style_metrology_settings_background_default, LV_PART_MAIN|LV_STATE_DEFAULT);


	//metrology settings Screen Header
	setup_draw_header(ui, ui->metrology_settings_background);

	/*******************************Title Container Start**************************************/
	//metrology settings Screen object for left arrow, parameter text and menu symbol
	setup_draw_title(ui, ui->metrology_settings_background, "FLOW", &fan_icon, ESPUPM_COLOR_BLUE);

	/********************************************
	 * container for curve and unit object start
	 ********************************************/
	static lv_obj_t *curvelabeltext;
	static lv_obj_t *unitlabeltext;
	//container object for unit and curve
	ui->metrology_settings_curve_unitcontainer = lv_obj_create(ui->metrology_settings_background);
	lv_obj_clear_flag(ui->metrology_settings_curve_unitcontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->metrology_settings_curve_unitcontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(ui->metrology_settings_curve_unitcontainer, ui->title_container, LV_ALIGN_OUT_BOTTOM_LEFT, 10, 0);
	lv_obj_set_size(ui->metrology_settings_curve_unitcontainer, SCREEN_WIDTH-20, 100);
	lv_obj_set_style_bg_color(ui->metrology_settings_curve_unitcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_settings_curve_unitcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_settings_curve_unitcontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_settings_curve_unitcontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_settings_curve_unitcontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//curve label
	curvelabeltext = lv_label_create(ui->metrology_settings_curve_unitcontainer);
	lv_obj_align(curvelabeltext, LV_ALIGN_TOP_LEFT, 10, 20);
	lv_obj_set_style_text_font(curvelabeltext, &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(curvelabeltext, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(curvelabeltext, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(curvelabeltext, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(curvelabeltext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(curvelabeltext, "CURVE");
	//curve Dropdown
	ui->metrology_settings_curvedropdown = lv_dropdown_create(ui->metrology_settings_curve_unitcontainer);
	lv_dropdown_set_options(ui->metrology_settings_curvedropdown,
	                 "Linear4\n"
	                 "Linear5\n"
	                 "Linear6\n"
	                 "Linear7\n"
	                 "Linear8"
	                 );
	lv_obj_align(ui->metrology_settings_curvedropdown, LV_ALIGN_TOP_RIGHT, -10, 10);
	lv_obj_set_size(ui->metrology_settings_curvedropdown, 120, 30);
	lv_obj_add_event_cb(ui->metrology_settings_curvedropdown, screen_dropdown_event_cb, LV_EVENT_READY, NULL);
    lv_obj_set_style_bg_color(ui->metrology_settings_curvedropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->metrology_settings_curvedropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_settings_curvedropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_settings_curvedropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_settings_curvedropdown, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->metrology_settings_curvedropdown, &lv_font_montserrat_16_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->metrology_settings_curvedropdown, &lv_font_montserrat_16_semibold, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->metrology_settings_curvedropdown, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->metrology_settings_curvedropdown, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->metrology_settings_curvedropdown, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Unit label
	unitlabeltext = lv_label_create(ui->metrology_settings_curve_unitcontainer);
	lv_obj_align(unitlabeltext, LV_ALIGN_TOP_LEFT, 10, 60);
	lv_obj_set_style_text_font(unitlabeltext, &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(unitlabeltext, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(unitlabeltext, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(unitlabeltext, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(unitlabeltext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(unitlabeltext, "UNIT");
	//Dropdown for Unit
	ui->metrology_settings_unitdropdown = lv_dropdown_create(ui->metrology_settings_curve_unitcontainer);
	lv_dropdown_set_options(ui->metrology_settings_unitdropdown,
	                 "LPM\n"
	                 "LPH"
	                 );
	lv_obj_align(ui->metrology_settings_unitdropdown, LV_ALIGN_TOP_RIGHT, -10, 60);
	lv_obj_set_size(ui->metrology_settings_unitdropdown, 120, 30);
	lv_obj_add_event_cb(ui->metrology_settings_unitdropdown, screen_dropdown_event_cb, LV_EVENT_READY, NULL);
    lv_obj_set_style_bg_color(ui->metrology_settings_unitdropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->metrology_settings_unitdropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_settings_unitdropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_settings_unitdropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_settings_unitdropdown, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->metrology_settings_unitdropdown, &lv_font_montserrat_16_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->metrology_settings_unitdropdown, &lv_font_montserrat_16_semibold, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->metrology_settings_unitdropdown, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->metrology_settings_unitdropdown, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->metrology_settings_unitdropdown, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	/********************************************
	 * container for curve and unit object end
	 ********************************************/

	/********************************************
	 * container for Alert object start
	 ********************************************/
	static lv_obj_t *alerttextlabel;
	static lv_obj_t *alertonofflabel;
	static lv_obj_t *lowerlimitlabel;
	static lv_obj_t *higherlimitlabel;
	static lv_obj_t *actionlabel;
	static lv_obj_t *actiontextlabel;
	//Alert container for Alert switch, lower limit, higher limit and action
    ui->metrology_settings_alertcontainer = lv_obj_create(ui->metrology_settings_background);
	lv_obj_clear_flag(ui->metrology_settings_alertcontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->metrology_settings_alertcontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(ui->metrology_settings_alertcontainer, ui->metrology_settings_curve_unitcontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_size(ui->metrology_settings_alertcontainer, SCREEN_WIDTH-20, 210);
	lv_obj_set_style_bg_color(ui->metrology_settings_alertcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_settings_alertcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_settings_alertcontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_settings_alertcontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_settings_alertcontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Alert text
	alerttextlabel = lv_label_create(ui->metrology_settings_alertcontainer);
	lv_obj_align(alerttextlabel, LV_ALIGN_TOP_LEFT, 10, 10);
	lv_obj_set_style_text_font(alerttextlabel, &lv_font_montserrat_14_bold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(alerttextlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(alerttextlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(alerttextlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(alerttextlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(alerttextlabel, "ALERT FROM SET POINT");
	//Alert on-off text
	alertonofflabel = lv_label_create(ui->metrology_settings_alertcontainer);
	lv_obj_align_to(alertonofflabel, alerttextlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(alertonofflabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(alertonofflabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(alertonofflabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(alertonofflabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(alertonofflabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(alertonofflabel, "ON/OFF");
	//Alert switch
	ui->metrology_settings_alertcontainerswitch = lv_switch_create(ui->metrology_settings_alertcontainer);
	lv_obj_align_to(ui->metrology_settings_alertcontainerswitch, ui->metrology_settings_alertcontainer, LV_ALIGN_TOP_RIGHT, -10, 15);
	lv_obj_set_size(ui->metrology_settings_alertcontainerswitch, 50, 30);
	lv_obj_set_style_bg_color(ui->metrology_settings_alertcontainerswitch, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_settings_alertcontainerswitch, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->metrology_settings_alertcontainerswitch, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_settings_alertcontainerswitch, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_settings_alertcontainerswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_settings_alertcontainerswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Lower limit label
	lowerlimitlabel = lv_label_create(ui->metrology_settings_alertcontainer);
	lv_obj_align_to(lowerlimitlabel, alertonofflabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
	lv_obj_set_style_text_font(lowerlimitlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(lowerlimitlabel, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(lowerlimitlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(lowerlimitlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(lowerlimitlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(lowerlimitlabel, "LOWER LIMIT :");
	//Lower limit dropdown
	ui->metrology_settings_lowerlimitdropdown = lv_dropdown_create(ui->metrology_settings_alertcontainer);
	lv_dropdown_set_options(ui->metrology_settings_lowerlimitdropdown,
					 "-10%\n"
					 "-20%"
					 );
	lv_obj_align_to(ui->metrology_settings_lowerlimitdropdown, ui->metrology_settings_alertcontainerswitch, LV_ALIGN_TOP_RIGHT, 10, 45);
	lv_obj_set_size(ui->metrology_settings_lowerlimitdropdown, 120, 30);
	lv_obj_add_event_cb(ui->metrology_settings_lowerlimitdropdown, screen_dropdown_event_cb, LV_EVENT_READY, NULL);
	lv_obj_set_style_bg_color(ui->metrology_settings_lowerlimitdropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->metrology_settings_lowerlimitdropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_settings_lowerlimitdropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_settings_lowerlimitdropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_settings_lowerlimitdropdown, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->metrology_settings_lowerlimitdropdown, &lv_font_montserrat_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->metrology_settings_lowerlimitdropdown, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->metrology_settings_lowerlimitdropdown, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->metrology_settings_lowerlimitdropdown, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Higher Limit label
	higherlimitlabel = lv_label_create(ui->metrology_settings_alertcontainer);
	lv_obj_align_to(higherlimitlabel, lowerlimitlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 25);
	lv_obj_set_style_text_font(higherlimitlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(higherlimitlabel, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(higherlimitlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(higherlimitlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(higherlimitlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(higherlimitlabel, "HIGHER LIMIT :");
	//Higher Limit dropdown
	ui->metrology_settings_higherlimitdropdown = lv_dropdown_create(ui->metrology_settings_alertcontainer);
	lv_dropdown_set_options(ui->metrology_settings_higherlimitdropdown,
					 "10%\n"
					 "20%"
					 );
	lv_obj_align_to(ui->metrology_settings_higherlimitdropdown, ui->metrology_settings_lowerlimitdropdown, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 16);
	lv_obj_set_size(ui->metrology_settings_higherlimitdropdown, 120, 30);
	lv_obj_add_event_cb(ui->metrology_settings_higherlimitdropdown, screen_dropdown_event_cb, LV_EVENT_READY, NULL);
	lv_obj_set_style_bg_color(ui->metrology_settings_higherlimitdropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->metrology_settings_higherlimitdropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_settings_higherlimitdropdown, ESPUPM_COLOR_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_settings_higherlimitdropdown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_settings_higherlimitdropdown, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->metrology_settings_higherlimitdropdown, &lv_font_montserrat_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->metrology_settings_higherlimitdropdown, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->metrology_settings_higherlimitdropdown, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->metrology_settings_higherlimitdropdown, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Action label
	actionlabel = lv_label_create(ui->metrology_settings_alertcontainer);
	lv_obj_align_to(actionlabel, higherlimitlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 25);
	lv_obj_set_style_text_font(actionlabel, &lv_font_montserrat_14_bold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(actionlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(actionlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(actionlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(actionlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(actionlabel, "ACTION");
	//Action Disable Device after Reset label
	actiontextlabel = lv_label_create(ui->metrology_settings_alertcontainer);
	lv_obj_align_to(actiontextlabel, actionlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
	lv_obj_set_style_text_font(actiontextlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(actiontextlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(actiontextlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(actiontextlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(actiontextlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(actiontextlabel, "DISABLE DEVICE AFTER RESET");
	//Action switch
	ui->metrology_settings_actionswitch = lv_switch_create(ui->metrology_settings_alertcontainer);
	lv_obj_align_to(ui->metrology_settings_actionswitch, ui->metrology_settings_higherlimitdropdown, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 20);
	lv_obj_set_size(ui->metrology_settings_actionswitch, 50, 30);
	lv_obj_set_style_bg_color(ui->metrology_settings_actionswitch, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_settings_actionswitch, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->metrology_settings_actionswitch, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_settings_actionswitch, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_settings_actionswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_settings_actionswitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	/********************************************
	 * container for Alert object end
	 ********************************************/

	//Valid and Adjust button
	static lv_style_t style_validadjustbutton;
	if (style_validadjustbutton.prop_cnt > 1)
		lv_style_reset(&style_validadjustbutton);
	else
		lv_style_init(&style_validadjustbutton);
	lv_style_set_bg_color(&style_validadjustbutton, ESPUPM_COLOR_GREEN);
	lv_style_set_bg_opa(&style_validadjustbutton, LV_OPA_MAX);
	lv_style_set_border_opa(&style_validadjustbutton, LV_OPA_MIN);
	lv_style_set_border_width(&style_validadjustbutton, 0);
	lv_style_set_shadow_width(&style_validadjustbutton, 0);
	lv_style_set_radius(&style_validadjustbutton, 5);

	//Valid & Adjust button
	ui->metrology_settings_validadjustbutton = lv_btn_create(ui->metrology_settings_background);
	lv_obj_align(ui->metrology_settings_validadjustbutton, LV_ALIGN_BOTTOM_MID, 0, -10);
	lv_obj_set_size(ui->metrology_settings_validadjustbutton, 300, 44);
	lv_obj_add_style(ui->metrology_settings_validadjustbutton, &style_validadjustbutton, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->metrology_settings_validadjustbutton, &style_validadjustbutton, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->metrology_settings_validadjustbutton, &style_validadjustbutton, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_t *buttonlabel = lv_label_create(ui->metrology_settings_validadjustbutton);
	lv_obj_center(buttonlabel);
	lv_obj_set_style_text_font(buttonlabel, &lv_font_montserrat_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(buttonlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(buttonlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "VALID & ADJUST");

	/*********************************************
	 *
	 * Metrology settings Screen design End
	 *
	 * **********************************/

	/************Events Initialization***********/
	events_init_metrology_settings(ui);
}

/***********************************************************************************************************************
 * End of file
 ***********************************************************************************************************************/
