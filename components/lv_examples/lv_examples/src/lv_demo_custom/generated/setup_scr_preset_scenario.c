/*
 * setup_scr_preset_scenario.c
 *
 *  Created on: 04-Jul-2022
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
static void draw_start_widget(lv_obj_t **parent, char *label, lv_obj_t **hourvalueobject, lv_obj_t **lpmvalueobject);
/***********************************************************************************************************************
 * static functions
 ***********************************************************************************************************************/
static void draw_start_widget(lv_obj_t **parent, char *label, lv_obj_t **hourvalueobject, lv_obj_t **lpmvalueobject){
	static lv_obj_t *mainlabel;
	static lv_obj_t *hourunitlabel;
	static lv_obj_t *lpmunitlabel;

	//Main label
	mainlabel = lv_label_create(*parent);
	lv_obj_align(mainlabel, LV_ALIGN_TOP_MID, 0, 10);
	lv_obj_set_style_text_font(mainlabel, &lv_font_montserrat_14_bold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(mainlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(mainlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(mainlabel, ESPUPM_COLOR_GREEN, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(mainlabel, label);

	//hour object
	*hourvalueobject = lv_label_create(*parent);
	lv_obj_align(*hourvalueobject, LV_ALIGN_BOTTOM_LEFT, 10, -5);
	lv_obj_set_style_text_font(*hourvalueobject, &lv_font_montserrat_22_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(*hourvalueobject, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(*hourvalueobject, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(*hourvalueobject, ESPUPM_COLOR_GREEN, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(*hourvalueobject, "3X8");
	hourunitlabel = lv_label_create(*parent);
	lv_obj_align_to(hourunitlabel, *hourvalueobject, LV_ALIGN_OUT_RIGHT_BOTTOM, 5, 0);
	lv_obj_set_style_text_font(hourunitlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(hourunitlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(hourunitlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(hourunitlabel, ESPUPM_COLOR_GREEN, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(hourunitlabel, "H");

	//LPM value object
	*lpmvalueobject = lv_label_create(*parent);
	lv_obj_align(*lpmvalueobject, LV_ALIGN_BOTTOM_MID, 20, -5);
	lv_obj_set_style_text_font(*lpmvalueobject, &lv_font_montserrat_22_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(*lpmvalueobject, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(*lpmvalueobject, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(*lpmvalueobject, ESPUPM_COLOR_GREEN, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(*lpmvalueobject, "7");
	lpmunitlabel = lv_label_create(*parent);
	lv_obj_align_to(lpmunitlabel, *lpmvalueobject, LV_ALIGN_OUT_RIGHT_BOTTOM, 5, 0);
	lv_obj_set_style_text_font(lpmunitlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(lpmunitlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(lpmunitlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(lpmunitlabel, ESPUPM_COLOR_GREEN, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(lpmunitlabel, "LPM");
}

/***********************************************************************************************************************
 * global functions
 ***********************************************************************************************************************/
/*
 * Function to draw preset scenario screen
 */
void setup_scr_preset_scenario(lv_ui *ui){

	//Preset scenario Screen main object
	ui->preset_scenario = lv_obj_create(NULL);
	static lv_style_t style_preset_scenario_default;
	if (style_preset_scenario_default.prop_cnt > 1)
		lv_style_reset(&style_preset_scenario_default);
	else
		lv_style_init(&style_preset_scenario_default);
	lv_style_set_bg_color(&style_preset_scenario_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_preset_scenario_default, SCREEN_MIN_OPACITY);
	lv_obj_add_style(ui->preset_scenario, &style_preset_scenario_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	/**************************************************************
	 *
	 * Preset Scenario Screen design Start
	 *
	 * **********************************************************/
	//preset scenario Screen Background
	ui->preset_scenario_background = lv_obj_create(ui->preset_scenario);
	lv_obj_set_align(ui->preset_scenario_background, LV_ALIGN_CENTER);
	lv_obj_set_size(ui->preset_scenario_background, SCREEN_WIDTH, SCREEN_HEIGHT);
	static lv_style_t style_preset_scenario_background_default;
	if (style_preset_scenario_background_default.prop_cnt > 1)
		lv_style_reset(&style_preset_scenario_background_default);
	else
		lv_style_init(&style_preset_scenario_background_default);
	lv_style_set_radius(&style_preset_scenario_background_default, 0);
	lv_style_set_bg_color(&style_preset_scenario_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_color(&style_preset_scenario_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_dir(&style_preset_scenario_background_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_preset_scenario_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_border_color(&style_preset_scenario_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_border_width(&style_preset_scenario_background_default, 0);
	lv_style_set_border_opa(&style_preset_scenario_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_pad_left(&style_preset_scenario_background_default, 0);
	lv_style_set_pad_right(&style_preset_scenario_background_default, 0);
	lv_style_set_pad_top(&style_preset_scenario_background_default, 0);
	lv_style_set_pad_bottom(&style_preset_scenario_background_default, 0);
	lv_obj_add_style(ui->preset_scenario_background, &style_preset_scenario_background_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Preset scenario Screen Header
	setup_draw_header(ui, ui->preset_scenario_background);

	//preset scenario Screen object for left arrow, parameter text and menu symbol
	setup_draw_title(ui, ui->preset_scenario_background, "SCENARIO", NULL, ESPUPM_BACKGROUND_COLOR);

	//Plus symbol in preset scenario
	ui->title_symbol = lv_btn_create(ui->title_container);
	lv_obj_align(ui->title_symbol, LV_ALIGN_RIGHT_MID, -5 , 0);
	lv_obj_set_size(ui->title_symbol, 54, 44);
	lv_obj_set_style_bg_color(ui->title_symbol, ESPUPM_COLOR_BLACK, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->title_symbol, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->title_symbol, ESPUPM_COLOR_BLACK, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->title_symbol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->title_symbol, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_t *buttonlabel = lv_label_create(ui->title_symbol);
	lv_obj_center(buttonlabel);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(buttonlabel, &lv_font_montserrat_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(buttonlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(buttonlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, LV_SYMBOL_PLUS);


	static lv_obj_t *startnow1;
	static lv_obj_t *startnow2;
	static lv_obj_t *startnow3;
	static lv_obj_t *startlater1;
	static lv_obj_t *startlater2;
	static lv_obj_t *startlater3;

	//START now 1
	startnow1 = lv_obj_create(ui->preset_scenario_background);
	lv_obj_clear_flag(startnow1, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_size(startnow1, 145, 90);
	lv_obj_align_to(startnow1, ui->title_container, LV_ALIGN_OUT_BOTTOM_LEFT, 10, 20);
	lv_obj_set_style_bg_color(startnow1, ESPUPM_COLOR_MILKY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(startnow1, ESPUPM_COLOR_MILKY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(startnow1, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(startnow1, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(startnow1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//START now 2
	startnow2 = lv_obj_create(ui->preset_scenario_background);
	lv_obj_clear_flag(startnow2, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_size(startnow2, 145, 90);
	lv_obj_align_to(startnow2, startnow1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_bg_color(startnow2, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(startnow2, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(startnow2, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(startnow2, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(startnow2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//START now 3
	startnow3 = lv_obj_create(ui->preset_scenario_background);
	lv_obj_clear_flag(startnow3, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_size(startnow3, 145, 90);
	lv_obj_align_to(startnow3, startnow2, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_bg_color(startnow3, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(startnow3, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(startnow3, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(startnow3, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(startnow3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//START LATER 1
	startlater1 = lv_obj_create(ui->preset_scenario_background);
	lv_obj_clear_flag(startlater1, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_size(startlater1, 145, 90);
	lv_obj_align_to(startlater1, ui->title_container, LV_ALIGN_OUT_BOTTOM_MID, 80, 20);
	lv_obj_set_style_bg_color(startlater1, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(startlater1, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(startlater1, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(startlater1, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(startlater1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//START LATER 2
	startlater2 = lv_obj_create(ui->preset_scenario_background);
	lv_obj_clear_flag(startlater2, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_size(startlater2, 145, 90);
	lv_obj_align_to(startlater2, startlater1, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
	lv_obj_set_style_bg_color(startlater2, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(startlater2, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(startlater2, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(startlater2, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(startlater2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//START LATER 3
	startlater3 = lv_obj_create(ui->preset_scenario_background);
	lv_obj_clear_flag(startlater3, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_size(startlater3, 145, 90);
	lv_obj_align_to(startlater3, startlater2, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
	lv_obj_set_style_bg_color(startlater3, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(startlater3, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(startlater3, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(startlater3, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(startlater3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Valid button
	ui->preset_scenario_validbutton = lv_btn_create(ui->preset_scenario_background);
	lv_obj_set_size(ui->preset_scenario_validbutton, 300, 44);
	lv_obj_align_to(ui->preset_scenario_validbutton, ui->preset_sequence_validbutton, LV_ALIGN_BOTTOM_LEFT, 10, -10);
	lv_obj_set_style_border_width(ui->preset_scenario_validbutton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->preset_scenario_validbutton, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->preset_scenario_validbutton, ESPUPM_COLOR_GREEN, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_t *btnlabel2 = lv_label_create(ui->preset_scenario_validbutton);
	lv_obj_center(btnlabel2);
	lv_obj_set_style_text_font(btnlabel2, &lv_font_montserrat_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(btnlabel2, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(btnlabel2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(btnlabel2, ESPUPM_COLOR_GREEN, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(btnlabel2, "VALID");

	/**************************************************************
	 *
	 * Preset Scenario Screen design End
	 *
	 * **********************************************************/

	draw_start_widget(&startnow1, "START NOW", &ui->preset_scenario_startnowHvalue[0], &ui->preset_scenario_startnowLPMvalue[0]);
	draw_start_widget(&startnow2, "START NOW", &ui->preset_scenario_startnowHvalue[1], &ui->preset_scenario_startnowLPMvalue[1]);
	draw_start_widget(&startnow3, "START NOW", &ui->preset_scenario_startnowHvalue[2], &ui->preset_scenario_startnowLPMvalue[2]);
	draw_start_widget(&startlater1, "START LATER", &ui->preset_scenario_startlaterHvalue[0], &ui->preset_scenario_startlaterLPMvalue[0]);
	draw_start_widget(&startlater2, "START LATER", &ui->preset_scenario_startlaterHvalue[1], &ui->preset_scenario_startlaterLPMvalue[1]);
	draw_start_widget(&startlater3, "START LATER", &ui->preset_scenario_startlaterHvalue[2], &ui->preset_scenario_startlaterLPMvalue[2]);

	/**********Event Initialization*********/
	events_init_preset_scenario(ui);

}

/***********************************************************************************************************************
 * End of file
 ***********************************************************************************************************************/




