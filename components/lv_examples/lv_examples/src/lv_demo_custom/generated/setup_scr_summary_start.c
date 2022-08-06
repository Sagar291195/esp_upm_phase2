
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
/*
 *Function to draw summary start screen
 *
 */
void setup_scr_summary_start(lv_ui *ui){

	//Main object summary start
	ui->summary_start = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_password_main_default
	static lv_style_t style_password_main_default;
	lv_style_reset(&style_password_main_default);
	lv_style_set_bg_color(&style_password_main_default, ESPUPM_COLOR_WHITE);
	lv_style_set_bg_opa(&style_password_main_default, 0);
	lv_obj_add_style(ui->summary_start, &style_password_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	/**************************************************
	 *
	 * Create Summary Start container start
	 *
	 ***************************************************/
	//summary screen star background
	ui->summary_start_background = lv_obj_create(ui->summary_start);
	lv_obj_set_pos(ui->summary_start_background, 0, 0);
	lv_obj_set_size(ui->summary_start_background, SCREEN_WIDTH, SCREEN_HEIGHT);

	//Write style state: LV_STATE_DEFAULT for style_password_container_main_default
	static lv_style_t style_password_container_main_default;
	lv_style_reset(&style_password_container_main_default);
	lv_style_set_radius(&style_password_container_main_default, 0);
	lv_style_set_bg_color(&style_password_container_main_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_color(&style_password_container_main_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_dir(&style_password_container_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_password_container_main_default, SCREEN_MAX_OPACITY);
	lv_style_set_border_color(&style_password_container_main_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_border_width(&style_password_container_main_default, 0);
	lv_style_set_border_opa(&style_password_container_main_default, SCREEN_MAX_OPACITY);
	lv_style_set_pad_left(&style_password_container_main_default, 0);
	lv_style_set_pad_right(&style_password_container_main_default, 0);
	lv_style_set_pad_top(&style_password_container_main_default, 0);
	lv_style_set_pad_bottom(&style_password_container_main_default, 0);
	lv_obj_add_style(ui->summary_start_background, &style_password_container_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Create Header in summary Screen
	setup_draw_header(ui, ui->summary_start_background);


	//title bar
	setup_draw_title(ui, ui->summary_start_background, "SUMMARY START", NULL, ESPUPM_BACKGROUND_COLOR);


	/*********************************************
	*Container for parameters start
	**********************************************/
	//Write codes summary_container_data
	ui->summary_start_container = lv_obj_create(ui->summary_start_background);
	lv_obj_align_to(ui->summary_start_container, ui->title_container, LV_ALIGN_OUT_BOTTOM_LEFT, 10, 10);
	lv_obj_set_size(ui->summary_start_container, 300, 300);
	static lv_style_t style_summary_container_data_default;
	lv_style_reset(&style_summary_container_data_default);
	lv_style_set_radius(&style_summary_container_data_default, 5);
	lv_style_set_bg_color(&style_summary_container_data_default, ESPUPM_COLOR_DARK_GREY);
	lv_style_set_border_width(&style_summary_container_data_default, 0);
	lv_style_set_border_opa(&style_summary_container_data_default, 255);
	lv_style_set_pad_left(&style_summary_container_data_default, 0);
	lv_style_set_pad_right(&style_summary_container_data_default, 0);
	lv_style_set_pad_top(&style_summary_container_data_default, 0);
	lv_style_set_pad_bottom(&style_summary_container_data_default, 0);
	lv_obj_add_style(ui->summary_start_container, &style_summary_container_data_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//inner container data
	static lv_obj_t *startlabel;
	static lv_obj_t *stoplabel;
	static lv_obj_t *flowsetpointlabel;
	static lv_obj_t *sequencenumberlabel;
	static lv_obj_t *durationlabel;
	static lv_obj_t *startpersonlabel;
	static lv_obj_t *litercounterlabel;
	static lv_obj_t *hourcounterlabel;
	// Create Label for Start  text
	startlabel = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(startlabel, ui->summary_start_container, LV_ALIGN_TOP_LEFT, 10, 20);
	lv_obj_set_style_text_font(startlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(startlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(startlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(startlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(startlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(startlabel, "START :");
	// Create Label for start Date
	ui->summary_start_startdatevalue = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(ui->summary_start_startdatevalue, startlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
	lv_obj_set_style_text_font (ui->summary_start_startdatevalue, &lv_font_montserrat_22_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->summary_start_startdatevalue, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_start_startdatevalue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->summary_start_startdatevalue, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_start_startdatevalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_start_startdatevalue, "23/12/2021");
	// Create Label for start Date
	ui->summary_start_startdurationvalue = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(ui->summary_start_startdurationvalue, ui->summary_start_startdatevalue, LV_ALIGN_BOTTOM_RIGHT, -30, 15);
	lv_obj_set_style_text_font (ui->summary_start_startdurationvalue, &lv_font_montserrat_14_bold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->summary_start_startdurationvalue, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_start_startdurationvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->summary_start_startdurationvalue, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_start_startdurationvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_start_startdurationvalue, "15H39M");


	// Create Label for Stop  text
	stoplabel = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(stoplabel, ui->summary_start_container, LV_ALIGN_TOP_MID, 30, 20);
	lv_obj_set_style_text_font (stoplabel, &lv_font_montserrat_11_regular, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(stoplabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(stoplabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(stoplabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(stoplabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(stoplabel, "STOP:");
	// Create Label for start Date
	ui->summary_start_stopdatevalue = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(ui->summary_start_stopdatevalue, stoplabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
	lv_obj_set_style_text_font (ui->summary_start_stopdatevalue, &lv_font_montserrat_22_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->summary_start_stopdatevalue, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_start_stopdatevalue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->summary_start_stopdatevalue, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_start_stopdatevalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_start_stopdatevalue, "23/12/2021");
	ui->summary_start_stopdurationvalue = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(ui->summary_start_stopdurationvalue, ui->summary_start_stopdatevalue, LV_ALIGN_BOTTOM_RIGHT, -30, 15);
	lv_obj_set_style_text_font (ui->summary_start_stopdurationvalue, &lv_font_montserrat_14_bold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->summary_start_stopdurationvalue, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_start_stopdurationvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->summary_start_stopdurationvalue, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_start_stopdurationvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_start_stopdurationvalue, "15H39M");

	// Create Label for sample num
	ui->summary_start_samplelabel = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(ui->summary_start_samplelabel, startlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 60);
	lv_obj_set_style_text_font (ui->summary_start_samplelabel, &lv_font_montserrat_16_medium, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->summary_start_samplelabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_start_samplelabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->summary_start_samplelabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_start_samplelabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_start_samplelabel, "SAMPLE N° 1345");

	// Create Label for flow set point
	flowsetpointlabel = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(flowsetpointlabel, ui->summary_start_samplelabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(flowsetpointlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(flowsetpointlabel, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(flowsetpointlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(flowsetpointlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(flowsetpointlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(flowsetpointlabel, "FLOW SET POINT:");
	//Flow set point value
	ui->summary_start_flowsetpointvalue = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(ui->summary_start_flowsetpointvalue, flowsetpointlabel, LV_ALIGN_OUT_RIGHT_MID, 30, 0);
	lv_obj_set_width(ui->summary_start_flowsetpointvalue, 130);
	lv_obj_set_style_text_font(ui->summary_start_flowsetpointvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->summary_start_flowsetpointvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_start_flowsetpointvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->summary_start_flowsetpointvalue, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_start_flowsetpointvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_start_flowsetpointvalue, "7 L/Min");

	//Sequence number label
	sequencenumberlabel = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(sequencenumberlabel, flowsetpointlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(sequencenumberlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(sequencenumberlabel, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(sequencenumberlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(sequencenumberlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(sequencenumberlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(sequencenumberlabel, "SEQUENCE NUMBER:");
	//sequence number value
	ui->summary_start_sequencenumbervalue = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(ui->summary_start_sequencenumbervalue, ui->summary_start_flowsetpointvalue, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 13);
	lv_obj_set_width(ui->summary_start_sequencenumbervalue, 130);
	lv_obj_set_style_text_font(ui->summary_start_sequencenumbervalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->summary_start_sequencenumbervalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_start_sequencenumbervalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->summary_start_sequencenumbervalue, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_start_sequencenumbervalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_start_sequencenumbervalue, "02");

	//Duration label
	durationlabel = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(durationlabel, sequencenumberlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(durationlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(durationlabel, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(durationlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(durationlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(durationlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(durationlabel, "DURATION:");
	//Duration value
	ui->summary_start_durationvalue = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(ui->summary_start_durationvalue, ui->summary_start_sequencenumbervalue, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 13);
	lv_obj_set_width(ui->summary_start_durationvalue, 130);
	lv_obj_set_style_text_font(ui->summary_start_durationvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->summary_start_durationvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_start_durationvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->summary_start_durationvalue, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_start_durationvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_start_durationvalue, "24 H");

	//Start person label
	startpersonlabel = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(startpersonlabel, durationlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(startpersonlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(startpersonlabel, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(startpersonlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(startpersonlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(startpersonlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(startpersonlabel, "START PERSON:");
	//Start Person value
	ui->summary_start_startpersonvalue = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(ui->summary_start_startpersonvalue, ui->summary_start_durationvalue, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 13);
	lv_obj_set_width(ui->summary_start_startpersonvalue, 130);
	lv_obj_set_style_text_font(ui->summary_start_startpersonvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->summary_start_startpersonvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_start_startpersonvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->summary_start_startpersonvalue, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_start_startpersonvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_start_startpersonvalue, "MARK");

	//Liter counter label
	litercounterlabel = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(litercounterlabel, startpersonlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(litercounterlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(litercounterlabel, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(litercounterlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(litercounterlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(litercounterlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(litercounterlabel, "LITER COUNTER:");
	//Liter counter value
	ui->summary_start_litercountervalue = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(ui->summary_start_litercountervalue, ui->summary_start_startpersonvalue, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 13);
	lv_obj_set_width(ui->summary_start_litercountervalue, 130);
	lv_obj_set_style_text_font(ui->summary_start_litercountervalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->summary_start_litercountervalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_start_litercountervalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->summary_start_litercountervalue, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_start_litercountervalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_start_litercountervalue, "102802,00 L");

	//Hour Counter label
	hourcounterlabel = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(hourcounterlabel, litercounterlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
	lv_obj_set_style_text_font(hourcounterlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(hourcounterlabel, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(hourcounterlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(hourcounterlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(hourcounterlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(hourcounterlabel, "HOUR COUNTER:");
	//Hour Counter value
	ui->summary_start_hourcountervalue = lv_label_create(ui->summary_start_container);
	lv_obj_align_to(ui->summary_start_hourcountervalue, ui->summary_start_litercountervalue, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 13);
	lv_obj_set_width(ui->summary_start_hourcountervalue, 130);
	lv_obj_set_style_text_font(ui->summary_start_hourcountervalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->summary_start_hourcountervalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_start_hourcountervalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->summary_start_hourcountervalue, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_start_hourcountervalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_start_hourcountervalue, "2300,13 L");
	/*********************************************
	*Container for parameters End
	**********************************************/

	//create start job button
	ui->summary_btn_startjob = lv_btn_create(ui->summary_start_background);
	lv_obj_set_size(ui->summary_btn_startjob, 300, 50);
	lv_obj_align(ui->summary_btn_startjob, LV_ALIGN_BOTTOM_MID, 0, -13);
	static lv_style_t style_btn_startjob;
	lv_style_reset(&style_btn_startjob);
	lv_style_set_radius(&style_btn_startjob, 5);
	lv_style_set_border_color(&style_btn_startjob, ESPUPM_COLOR_LIGHT_BLUE);
	lv_style_set_border_width(&style_btn_startjob, 0);
	lv_style_set_border_opa(&style_btn_startjob, 255);
	lv_style_set_shadow_width(&style_btn_startjob, 0);
	lv_style_set_bg_color(&style_btn_startjob, ESPUPM_COLOR_BLUE);
	lv_obj_t *buttonlabel = lv_label_create(ui->summary_btn_startjob);
	lv_obj_set_style_text_font (buttonlabel, &lv_font_montserrat_22, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_add_style(buttonlabel, &style_btn_startjob, LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "START JOB");
	lv_obj_center(buttonlabel);
	/**************************************************
	 *
	 * Create Summary Start container end
	 *
	 ***************************************************/

	/**********Events for summary start screen************/
	events_init_summary_start(ui);
}

/***********************************************************************************************************************
 * End of file
 ***********************************************************************************************************************/
