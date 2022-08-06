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
#define BUTTON_SIZE 66
/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * static variables
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * static prototype
 ***********************************************************************************************************************/
static void create_password_digit(uint8_t index, lv_obj_t *par, lv_coord_t x, lv_coord_t y, char *str, lv_style_t *style_btn);


/***********************************************************************************************************************
 * static functions
 ***********************************************************************************************************************/
static void create_password_digit(uint8_t index, lv_obj_t *par, lv_coord_t x, lv_coord_t y, char *str, lv_style_t *style_btn)
{
    guider_ui.metrology_calibration_keyboard_digit[index] = lv_btn_create(par);
    lv_obj_set_size(guider_ui.metrology_calibration_keyboard_digit[index], BUTTON_SIZE, BUTTON_SIZE);
    lv_obj_align(guider_ui.metrology_calibration_keyboard_digit[index], LV_ALIGN_LEFT_MID, x, y);
    lv_obj_add_style(guider_ui.metrology_calibration_keyboard_digit[index], style_btn, LV_STATE_DEFAULT);
    lv_obj_t * label = lv_label_create(guider_ui.metrology_calibration_keyboard_digit[index]);
    lv_label_set_text(label, str);
    lv_obj_set_style_text_font (label, &lv_font_montserrat_28, 0);
    lv_obj_center(label);
}


/***********************************************************************************************************************
 * global functions
 ***********************************************************************************************************************/

/*
 * Function to draw metrology calibration screen
 */
void setup_scr_metrology_calibration(lv_ui *ui){
	//metrology calibration Screen main object
	ui->metrology_calibration = lv_obj_create(NULL);
	static lv_style_t style_metrology_calibration_default;
	if (style_metrology_calibration_default.prop_cnt > 1)
		lv_style_reset(&style_metrology_calibration_default);
	else
		lv_style_init(&style_metrology_calibration_default);
	lv_style_set_bg_color(&style_metrology_calibration_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_metrology_calibration_default, SCREEN_MIN_OPACITY);
	lv_obj_add_style(ui->metrology_calibration, &style_metrology_calibration_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	/********************************************************
	 *
	 * Metrology calibration Screen design Start
	 *
	 * *******************************************************/
	//Metrology calibration Screen Background
	ui->metrology_calibration_background = lv_obj_create(ui->metrology_calibration);
	lv_obj_set_align(ui->metrology_calibration_background, LV_ALIGN_CENTER);
	lv_obj_set_size(ui->metrology_calibration_background, SCREEN_WIDTH, SCREEN_HEIGHT);
	static lv_style_t style_metrology_calibration_background_default;
	if (style_metrology_calibration_background_default.prop_cnt > 1)
		lv_style_reset(&style_metrology_calibration_background_default);
	else
		lv_style_init(&style_metrology_calibration_background_default);
	lv_style_set_radius(&style_metrology_calibration_background_default, 0);
	lv_style_set_bg_color(&style_metrology_calibration_background_default, ESPUPM_COLOR_BLUE);
	lv_style_set_bg_grad_color(&style_metrology_calibration_background_default, ESPUPM_COLOR_BLUE);
	lv_style_set_bg_grad_dir(&style_metrology_calibration_background_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_metrology_calibration_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_border_color(&style_metrology_calibration_background_default, ESPUPM_COLOR_BLUE);
	lv_style_set_border_width(&style_metrology_calibration_background_default, 0);
	lv_style_set_border_opa(&style_metrology_calibration_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_pad_left(&style_metrology_calibration_background_default, 0);
	lv_style_set_pad_right(&style_metrology_calibration_background_default, 0);
	lv_style_set_pad_top(&style_metrology_calibration_background_default, 0);
	lv_style_set_pad_bottom(&style_metrology_calibration_background_default, 0);
	lv_obj_add_style(ui->metrology_calibration_background, &style_metrology_calibration_background_default, LV_PART_MAIN|LV_STATE_DEFAULT);


	//Metrology calibration Screen Header
	setup_draw_header(ui, ui->metrology_calibration_background);

	//Metrology calibration Screen object for left arrow, parameter text and menu symbol
	setup_draw_title(ui, ui->metrology_calibration_background, "External Temperature", &fan_icon, ESPUPM_COLOR_BLUE);

	//Point label
	ui->metrology_calibration_pointlabel = lv_label_create(ui->metrology_calibration_background);
	lv_obj_align_to(ui->metrology_calibration_pointlabel, ui->title_container, LV_ALIGN_BOTTOM_LEFT, 10, 20);
	lv_obj_set_style_text_font(ui->metrology_calibration_pointlabel, &lv_font_montserrat_14_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->metrology_calibration_pointlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->metrology_calibration_pointlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_calibration_pointlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->metrology_calibration_pointlabel, "POINT :");

	//Factory value label
	ui->metrology_calibration_countlabel = lv_label_create(ui->metrology_calibration_background);
	lv_obj_align_to(ui->metrology_calibration_countlabel, ui->metrology_calibration_pointlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_text_font(ui->metrology_calibration_countlabel, &lv_font_montserrat_14_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->metrology_calibration_countlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->metrology_calibration_countlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_calibration_countlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->metrology_calibration_countlabel, "FACTORY VALUE :");

	//Point value
	ui->metrology_calibration_pointvalue = lv_label_create(ui->metrology_calibration_background);
	lv_obj_align_to(ui->metrology_calibration_pointvalue, ui->title_container, LV_ALIGN_BOTTOM_MID, 20, 18);
	lv_obj_set_style_text_font(ui->metrology_calibration_pointvalue, &lv_font_montserrat_18_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->metrology_calibration_pointvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->metrology_calibration_pointvalue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_calibration_pointvalue, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->metrology_calibration_pointvalue, "1");

	//Factory value
	ui->metrology_calibration_countvalue = lv_label_create(ui->metrology_calibration_background);
	lv_obj_align_to(ui->metrology_calibration_countvalue, ui->metrology_calibration_pointvalue, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
	lv_obj_set_style_text_font(ui->metrology_calibration_countvalue, &lv_font_montserrat_18_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->metrology_calibration_countvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->metrology_calibration_countvalue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_calibration_countvalue, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->metrology_calibration_countvalue, "24,67");

	//Keypad text area for password
	ui->metrology_calibration_keypadtxtarea = lv_textarea_create(ui->metrology_calibration_background);
	lv_obj_align_to(ui->metrology_calibration_keypadtxtarea, ui->metrology_calibration_countlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_size(ui->metrology_calibration_keypadtxtarea, 210, 50);
	lv_textarea_set_align(ui->metrology_calibration_keypadtxtarea, LV_ALIGN_CENTER);
	lv_textarea_set_cursor_click_pos(ui->metrology_calibration_keypadtxtarea, false);
	lv_textarea_set_text(ui->metrology_calibration_keypadtxtarea, "");
	lv_obj_set_style_text_font(ui->metrology_calibration_keypadtxtarea, &lv_font_montserrat_22_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->metrology_calibration_keypadtxtarea, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_calibration_keypadtxtarea, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->metrology_calibration_keypadtxtarea, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->metrology_calibration_keypadtxtarea, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_calibration_keypadtxtarea, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Valid button
	ui->metrology_calibration_validbutton = lv_btn_create(ui->metrology_calibration_background);
	lv_obj_align_to(ui->metrology_calibration_validbutton, ui->metrology_calibration_keypadtxtarea, LV_ALIGN_OUT_RIGHT_TOP, -5, 0);
	lv_obj_set_size(ui->metrology_calibration_validbutton, 90, 50);
	lv_obj_set_style_border_width(ui->metrology_calibration_validbutton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->metrology_calibration_validbutton, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_calibration_validbutton, ESPUPM_COLOR_GREEN, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_t *btnlabel = lv_label_create(ui->metrology_calibration_validbutton);
	lv_obj_center(btnlabel);
	lv_obj_set_style_text_font(btnlabel, &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(btnlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(btnlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(btnlabel, ESPUPM_COLOR_GREEN, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(btnlabel, "VALID");

	///calibration correction text
	ui->metrology_calibration_correction = lv_label_create(ui->metrology_calibration_background);
	lv_obj_align_to(ui->metrology_calibration_correction, ui->metrology_calibration_keypadtxtarea,LV_ALIGN_OUT_BOTTOM_LEFT, 70, 10);
	lv_obj_set_style_text_font(ui->metrology_calibration_correction, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->metrology_calibration_correction, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->metrology_calibration_correction, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->metrology_calibration_correction, ESPUPM_COLOR_GREEN, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_recolor(ui->metrology_calibration_correction, true);
	lv_label_set_text(ui->metrology_calibration_correction, "CORRECTION :  #5DAF48 __,__%#");

	 //Keypad design
	static lv_style_t style_btn;
	lv_style_reset(&style_btn);
	lv_style_set_radius(&style_btn, BUTTON_SIZE/2);
	lv_style_set_bg_color(&style_btn, ESPUPM_COLOR_BLUE);
	lv_style_set_border_color(&style_btn, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_btn, 2);
	lv_style_set_border_opa(&style_btn, 255);
	lv_style_set_shadow_width(&style_btn, 0);

	create_password_digit(0, ui->metrology_calibration_background, 10, 40, "1", &style_btn);
	create_password_digit(1, ui->metrology_calibration_background, 88, 40, "2", &style_btn);
	create_password_digit(2, ui->metrology_calibration_background, 166, 40, "3", &style_btn);
	create_password_digit(3, ui->metrology_calibration_background, 244, 40, LV_SYMBOL_BACKSPACE, &style_btn);
	create_password_digit(4, ui->metrology_calibration_background, 10, 115, "4", &style_btn);
	create_password_digit(5, ui->metrology_calibration_background, 88, 115, "5", &style_btn);
	create_password_digit(6, ui->metrology_calibration_background, 166, 115, "6", &style_btn);
	create_password_digit(7, ui->metrology_calibration_background, 244, 115, ",", &style_btn);
	create_password_digit(8, ui->metrology_calibration_background, 10, 190, "7", &style_btn);
	create_password_digit(9, ui->metrology_calibration_background, 88, 190, "8", &style_btn);
	create_password_digit(10, ui->metrology_calibration_background, 166, 190, "9", &style_btn);
	create_password_digit(11, ui->metrology_calibration_background, 244, 190, "0", &style_btn);
	/********************************************************
	 *
	 * Metrology calibration Screen design End
	 *
	 * *******************************************************/

	/********Events initialization***********/
	events_init_metrology_calibration(ui);
}

/***********************************************************************************************************************
 * End of file
 ***********************************************************************************************************************/
