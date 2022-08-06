/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
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

#define BUTTON_SIZE     64
/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * static variables
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * static prototype
 ***********************************************************************************************************************/
static void create_password_digit(uint8_t index, lv_obj_t *par, lv_coord_t x, lv_coord_t y, char *str, lv_style_t *style_btn);
static void create_password_num(uint8_t index, lv_coord_t x, lv_coord_t y);

/***********************************************************************************************************************
 * static functions
 ***********************************************************************************************************************/
static void create_password_digit(uint8_t index, lv_obj_t *par, lv_coord_t x, lv_coord_t y, char *str, lv_style_t *style_btn)
{
    guider_ui.password_keyboard_digit[index] = lv_btn_create(par);
    lv_obj_set_size(guider_ui.password_keyboard_digit[index], BUTTON_SIZE, BUTTON_SIZE);
    lv_obj_align(guider_ui.password_keyboard_digit[index], LV_ALIGN_LEFT_MID, x, y);
    lv_obj_add_style(guider_ui.password_keyboard_digit[index], style_btn, LV_STATE_DEFAULT);
    lv_obj_t * label = lv_label_create(guider_ui.password_keyboard_digit[index]);
    lv_label_set_text(label, str);
    lv_obj_set_style_text_font (label, &lv_font_montserrat_28, 0);
    lv_obj_center(label);
}

static void create_password_num(uint8_t index, lv_coord_t x, lv_coord_t y)
{
	guider_ui.password_enter_num_label[index] = lv_label_create(guider_ui.password_background);
    lv_obj_set_size(guider_ui.password_enter_num_label[index], 30, 30);
    lv_obj_align(guider_ui.password_enter_num_label[index], LV_ALIGN_TOP_MID, x, y);
    lv_obj_set_style_bg_color(guider_ui.password_enter_num_label[index], ESPUPM_COLOR_GREEN, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(guider_ui.password_enter_num_label[index], LV_OPA_100, LV_PART_MAIN);
    lv_obj_set_style_border_color(guider_ui.password_enter_num_label[index], ESPUPM_COLOR_WHITE, LV_PART_MAIN);
    lv_obj_set_style_border_opa(guider_ui.password_enter_num_label[index], LV_OPA_100, LV_PART_MAIN);
    lv_obj_set_style_border_width(guider_ui.password_enter_num_label[index], 2, LV_PART_MAIN);
    lv_obj_set_style_border_side(guider_ui.password_enter_num_label[index], LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN);
    lv_obj_set_style_pad_all(guider_ui.password_enter_num_label[index], 0, LV_PART_MAIN);
    //lv_label_set_text(guider_ui.password_enter_num_label[index], "H");
    lv_obj_set_style_text_font(guider_ui.password_enter_num_label[index], &lv_font_montserrat_24_medium, LV_PART_MAIN);
    lv_obj_set_style_text_color(guider_ui.password_enter_num_label[index], ESPUPM_COLOR_WHITE, LV_PART_MAIN);
    lv_obj_set_style_text_align(guider_ui.password_enter_num_label[index], LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
}

/***********************************************************************************************************************
 * global functions
 ***********************************************************************************************************************/
void setup_scr_password(lv_ui *ui){

	//Main object of password screen
	ui->password = lv_obj_create(NULL);
	static lv_style_t style_password_main_main_default;
	lv_style_reset(&style_password_main_main_default);
	lv_style_set_bg_color(&style_password_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_password_main_main_default, 0);
	lv_obj_add_style(ui->password, &style_password_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Password background
	ui->password_background = lv_obj_create(ui->password);
	lv_obj_set_pos(ui->password_background, 0, 0);
	lv_obj_set_size(ui->password_background, SCREEN_WIDTH, SCREEN_HEIGHT);
	static lv_style_t style_password_container_main_default;
	lv_style_reset(&style_password_container_main_default);
	lv_style_set_radius(&style_password_container_main_default, 0);
	lv_style_set_bg_color(&style_password_container_main_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_opa(&style_password_container_main_default, 255);
	lv_style_set_border_color(&style_password_container_main_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_border_width(&style_password_container_main_default, 0);
	lv_style_set_border_opa(&style_password_container_main_default, 255);
	lv_style_set_pad_left(&style_password_container_main_default, 0);
	lv_style_set_pad_right(&style_password_container_main_default, 0);
	lv_style_set_pad_top(&style_password_container_main_default, 0);
	lv_style_set_pad_bottom(&style_password_container_main_default, 0);
	lv_obj_add_style(ui->password_background, &style_password_container_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Enter Code label
	ui->password_label = lv_label_create(ui->password_background);
   // lv_label_set_text(ui->password_label, "Enter code");
    lv_label_set_long_mode(ui->password_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_width(ui->password_label, 160);
    lv_obj_set_style_text_font(ui->password_label, &lv_font_montserrat_18_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->password_label, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->password_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_align(ui->password_label, LV_ALIGN_TOP_MID, 0, 35);

    //Button creation
	static lv_style_t style_btn;
	lv_style_reset(&style_btn);
	lv_style_set_radius(&style_btn, BUTTON_SIZE/2);
//	lv_style_set_bg_color(&style_btn, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_border_color(&style_btn, ESPUPM_COLOR_WHITE);
	lv_style_set_border_width(&style_btn, 2);
	lv_style_set_border_opa(&style_btn, 255);
	lv_style_set_shadow_width(&style_btn, 0);

    create_password_digit(0, ui->password_background, 40, -80, "1", &style_btn);
    create_password_digit(1, ui->password_background, 130, -80, "2", &style_btn);
    create_password_digit(2, ui->password_background, 220, -80, "3", &style_btn);
    create_password_digit(3, ui->password_background, 40, 5, "4", &style_btn);
    create_password_digit(4, ui->password_background, 130, 5, "5", &style_btn);
    create_password_digit(5, ui->password_background, 220, 5, "6", &style_btn);
    create_password_digit(6, ui->password_background, 40, 90, "7", &style_btn);
    create_password_digit(7, ui->password_background, 130, 90, "8", &style_btn);
    create_password_digit(8, ui->password_background, 220, 90, "9", &style_btn);
    create_password_digit(9, ui->password_background, 40, 175, LV_SYMBOL_BACKSPACE, &style_btn);
    create_password_digit(10, ui->password_background, 130, 175, "0", &style_btn);
    create_password_digit(11, ui->password_background, 220, 175, "#", &style_btn);


    //label to display password
    create_password_num(0, -50, 60);
    create_password_num(1, -15, 60);
    create_password_num(2, 20, 60);
    create_password_num(3, 55, 60);

    //Password ok symbol
    ui->password_status_symbol = lv_img_create(ui->password_background);
    lv_obj_align_to(ui->password_status_symbol, ui->password_enter_num_label[3], LV_ALIGN_OUT_RIGHT_TOP, 10, 0);
    lv_obj_set_style_img_opa(ui->password_status_symbol, LV_OPA_MAX, LV_PART_MAIN);
    lv_obj_set_style_bg_img_opa(ui->password_status_symbol, LV_OPA_MIN, LV_PART_MAIN);
    lv_obj_set_style_img_recolor(ui->password_status_symbol, ESPUPM_COLOR_WHITE, LV_PART_MAIN);
   // lv_img_set_src(ui->password_status_symbol, (char *)&ok_icon);
    lv_obj_add_flag(ui->password_status_symbol, LV_OBJ_FLAG_HIDDEN);

    /***********Event init password**************/
    events_init_password(ui);
}

/***********************************************************************************************************************
 * End of file
 ***********************************************************************************************************************/

