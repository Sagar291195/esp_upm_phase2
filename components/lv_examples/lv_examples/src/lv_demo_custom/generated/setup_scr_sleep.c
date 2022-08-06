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

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * static variables
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * static prototype
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * static functions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * global functions 
 ***********************************************************************************************************************/

void setup_scr_sleep(lv_ui *ui){

	//Sleep Screen Main container
	ui->sleep = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_sleep_main_main_default
	static lv_style_t style_sleep_main_main_default;
	lv_style_reset(&style_sleep_main_main_default);
	lv_style_set_bg_color(&style_sleep_main_main_default, ESPUPM_COLOR_BLACK);
	lv_style_set_bg_opa(&style_sleep_main_main_default, 0);
	lv_obj_add_style(ui->sleep, &style_sleep_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Sleep screen background
    ui->sleep_background = lv_obj_create(ui->sleep);
	lv_obj_set_align(ui->sleep_background, LV_ALIGN_CENTER);
	lv_obj_set_size(ui->sleep_background, SCREEN_WIDTH, SCREEN_HEIGHT);
	static lv_style_t style_sleep_background_default;
	if (style_sleep_background_default.prop_cnt > 1)
		lv_style_reset(&style_sleep_background_default);
	else
		lv_style_init(&style_sleep_background_default);
	lv_style_set_radius(&style_sleep_background_default, 0);
	lv_style_set_bg_color(&style_sleep_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_color(&style_sleep_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_dir(&style_sleep_background_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_sleep_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_border_color(&style_sleep_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_border_width(&style_sleep_background_default, 0);
	lv_style_set_border_opa(&style_sleep_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_pad_left(&style_sleep_background_default, 0);
	lv_style_set_pad_right(&style_sleep_background_default, 0);
	lv_style_set_pad_top(&style_sleep_background_default, 0);
	lv_style_set_pad_bottom(&style_sleep_background_default, 0);
	lv_obj_add_style(ui->sleep_background, &style_sleep_background_default, LV_PART_MAIN|LV_STATE_DEFAULT);


	events_init_sleep(ui);
}

/***********************************************************************************************************************
 * End of file
 ***********************************************************************************************************************/
