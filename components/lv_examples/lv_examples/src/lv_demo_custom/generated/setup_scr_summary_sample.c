
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
static void draw_meanmax_widget(lv_obj_t **parentobject, lv_obj_t **titleobject, char *titletext, char *lefttext,
				lv_obj_t **setpointvalueobject, lv_obj_t **meanvalueobject, lv_obj_t **maxvalueobject, lv_obj_t **maxwrrowobject,
				lv_obj_t **minvalueobject, lv_obj_t **minwrrowobject, lv_obj_t **variationvalueobject);


/***********************************************************************************************************************
 * static functions
 ***********************************************************************************************************************/
static void draw_meanmax_widget(lv_obj_t **parentobject, lv_obj_t **titleobject, char *titletext, char *lefttext,
				lv_obj_t **setpointvalueobject, lv_obj_t **meanvalueobject, lv_obj_t **maxvalueobject, lv_obj_t **maxwrrowobject,
				lv_obj_t **minvalueobject, lv_obj_t **minwrrowobject, lv_obj_t **variationvalueobject){
	static lv_obj_t *leftlabel;
	static lv_obj_t *meanlabel;
	static lv_obj_t *maxlabel;
	static lv_obj_t *minlabel;
	static lv_obj_t *variationlabel;

	*titleobject = lv_label_create(*parentobject);
	lv_obj_align_to(*titleobject, *parentobject, LV_ALIGN_TOP_LEFT, 5, 5);
	lv_obj_set_style_text_color(*titleobject, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(*titleobject, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(*titleobject, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(*titleobject, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(*titleobject, titletext);


	leftlabel = lv_label_create(*parentobject);
	lv_obj_align_to(leftlabel, *parentobject, LV_ALIGN_TOP_LEFT, 5, 30);
	lv_obj_set_style_text_color(leftlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(leftlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(leftlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(leftlabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(leftlabel, lefttext);

	*setpointvalueobject = lv_label_create(*parentobject);
	lv_obj_align_to(*setpointvalueobject, leftlabel, LV_ALIGN_OUT_RIGHT_TOP, 10, -2);
	lv_obj_set_style_text_color(*setpointvalueobject, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(*setpointvalueobject, &lv_font_montserrat_16_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(*setpointvalueobject, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(*setpointvalueobject, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(*setpointvalueobject, "3,00");

	meanlabel = lv_label_create(*parentobject);
	lv_obj_align_to(meanlabel, *parentobject, LV_ALIGN_TOP_MID,20, 30);
	lv_obj_set_style_text_color(meanlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(meanlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(meanlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(meanlabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(meanlabel, "MEAN :");

	*meanvalueobject = lv_label_create(*parentobject);
	lv_obj_align_to(*meanvalueobject, meanlabel, LV_ALIGN_OUT_RIGHT_TOP, 10, -2);
	lv_obj_set_style_text_color(*meanvalueobject, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(*meanvalueobject, &lv_font_montserrat_16_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(*meanvalueobject, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(*meanvalueobject, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(*meanvalueobject, "9,00");

	maxlabel = lv_label_create(*parentobject);
	lv_obj_align(maxlabel, LV_ALIGN_BOTTOM_LEFT, 0, -5);
	lv_obj_set_style_text_color(maxlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(maxlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_hor(maxlabel, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(maxlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(maxlabel, "MAX VALUE");
	*maxwrrowobject = lv_img_create(*parentobject);
	lv_obj_align_to(*maxwrrowobject, maxlabel, LV_ALIGN_OUT_LEFT_TOP, -3, -30);
	lv_obj_set_size(*maxwrrowobject, 30 ,30);
	lv_img_set_src(*maxwrrowobject, &uparrow);
	*maxvalueobject = lv_label_create(*parentobject);
	lv_obj_align_to(*maxvalueobject, *maxwrrowobject, LV_ALIGN_OUT_RIGHT_MID, -5, 0);
	lv_obj_set_style_text_color(*maxvalueobject, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(*maxvalueobject, &lv_font_montserrat_16_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(*maxvalueobject, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(*maxvalueobject, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(*maxvalueobject, "+0,02");


	minlabel = lv_label_create(*parentobject);
	lv_obj_align(minlabel, LV_ALIGN_BOTTOM_MID , 0, -5);
	lv_obj_set_style_text_color(minlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(minlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(minlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(minlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(minlabel, "MIN VALUE");
	*minwrrowobject = lv_img_create(*parentobject);
	lv_obj_align_to(*minwrrowobject, minlabel, LV_ALIGN_OUT_LEFT_TOP, -10, -30);
	lv_obj_set_size(*minwrrowobject, 30 ,30);
	lv_img_set_src(*minwrrowobject, &downarrow);
	*minvalueobject = lv_label_create(*parentobject);
	lv_obj_align_to(*minvalueobject, *minwrrowobject, LV_ALIGN_OUT_RIGHT_MID, -5, 0);
	lv_obj_set_style_text_color(*minvalueobject, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(*minvalueobject, &lv_font_montserrat_16_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(*minvalueobject, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(*minvalueobject, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(*minvalueobject, "-0,02");


	variationlabel = lv_label_create(*parentobject);
	lv_obj_align(variationlabel,LV_ALIGN_BOTTOM_RIGHT ,-5, -5);
	lv_obj_set_style_text_color(variationlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(variationlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(variationlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(variationlabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(variationlabel, "VARIATION");
	*variationvalueobject = lv_label_create(*parentobject);
	lv_obj_align_to(*variationvalueobject, variationlabel, LV_ALIGN_OUT_TOP_MID, 0, -5);
	lv_obj_set_style_text_color(*variationvalueobject, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(*variationvalueobject, &lv_font_montserrat_16_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(*variationvalueobject, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(*variationvalueobject, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(*variationvalueobject, "1.08%");
}

/***********************************************************************************************************************
 * global functions
 ***********************************************************************************************************************/
void setup_scr_summary_sample(lv_ui *ui){

	//Main object of summary sample screen
	ui->summary_sample = lv_obj_create(NULL);

	static lv_style_t style_summary_sample_main_default;
	lv_style_reset(&style_summary_sample_main_default);
	lv_style_set_bg_color(&style_summary_sample_main_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_opa(&style_summary_sample_main_default, 0);
	lv_obj_add_style(ui->summary_sample, &style_summary_sample_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Backgorund for summary sample screen
	ui->summary_sample_background = lv_obj_create(ui->summary_sample);
	lv_obj_set_pos(ui->summary_sample_background, 0, 0);
	lv_obj_set_size(ui->summary_sample_background, SCREEN_WIDTH, SCREEN_HEIGHT);
	lv_obj_set_scrollbar_mode(ui->summary_sample_background, LV_SCROLLBAR_MODE_OFF);
	static lv_style_t style_end_container_main_default;
	lv_style_reset(&style_end_container_main_default);
	lv_style_set_radius(&style_end_container_main_default, 0);
	lv_style_set_bg_color(&style_end_container_main_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_color(&style_end_container_main_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_dir(&style_end_container_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_end_container_main_default, SCREEN_MAX_OPACITY);
	lv_style_set_border_color(&style_end_container_main_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_border_width(&style_end_container_main_default, 0);
	lv_style_set_border_opa(&style_end_container_main_default, SCREEN_MAX_OPACITY);
	lv_style_set_pad_left(&style_end_container_main_default, 0);
	lv_style_set_pad_right(&style_end_container_main_default, 0);
	lv_style_set_pad_top(&style_end_container_main_default, 0);
	lv_style_set_pad_bottom(&style_end_container_main_default, 0);
	lv_obj_add_style(ui->summary_sample_background, &style_end_container_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Draw header
	setup_draw_header(ui, ui->summary_sample_background);

	//Draw page title
	setup_draw_title(ui, ui->summary_sample_background, "Sample N° 1356", NULL, ESPUPM_BACKGROUND_COLOR);

	 //Next previos container
	ui->summary_sample_previousnext_buttoncontainer = lv_obj_create(ui->summary_sample_background);
	lv_obj_align_to(ui->summary_sample_previousnext_buttoncontainer, ui->title_container, LV_ALIGN_OUT_BOTTOM_LEFT, 10, 5);
	lv_obj_clear_flag(ui->summary_sample_previousnext_buttoncontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(ui->summary_sample_previousnext_buttoncontainer, SCREEN_WIDTH-20, 60);
	lv_obj_set_style_bg_color(ui->summary_sample_previousnext_buttoncontainer, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->summary_sample_previousnext_buttoncontainer, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->summary_sample_previousnext_buttoncontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->summary_sample_previousnext_buttoncontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->summary_sample_previousnext_buttoncontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_sample_previousnext_buttoncontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Page title Previous button
	ui->summary_sample_previousbutton = lv_label_create(ui->summary_sample_previousnext_buttoncontainer);
	lv_obj_set_size(ui->summary_sample_previousbutton, 64,60);
	lv_obj_align_to(ui->summary_sample_previousbutton, ui->title_container, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
	lv_obj_set_style_text_color(ui->summary_sample_previousbutton, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summary_sample_previousbutton, &lv_font_montserrat_34, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->summary_sample_previousbutton, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->summary_sample_previousbutton, ESPUPM_COLOR_BLACK, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->summary_sample_previousbutton, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_sample_previousbutton, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_sample_previousbutton, LV_SYMBOL_PREV);

	//Next button
	ui->summary_sample_nextbutton = lv_label_create(ui->summary_sample_previousnext_buttoncontainer);
	lv_obj_set_size(ui->summary_sample_nextbutton, 64,60);
	lv_obj_align_to(ui->summary_sample_nextbutton, ui->title_container, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 5);
	lv_obj_set_style_text_color(ui->summary_sample_nextbutton, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summary_sample_nextbutton, &lv_font_montserrat_34, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->summary_sample_nextbutton, ESPUPM_COLOR_BLACK, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->summary_sample_nextbutton, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->summary_sample_nextbutton, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_sample_nextbutton, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_sample_nextbutton, LV_SYMBOL_NEXT);

	//Page tile
	ui->summary_sample_label = lv_label_create(ui->summary_sample_previousnext_buttoncontainer);
	lv_obj_set_size(ui->summary_sample_label, 120,44);
	lv_obj_align_to(ui->summary_sample_label, ui->title_container, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
	lv_obj_set_style_text_color(ui->summary_sample_label, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summary_sample_label, &lv_font_montserrat_20_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_sample_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->summary_sample_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_sample_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_recolor(ui->summary_sample_label, true);
	lv_label_set_text(ui->summary_sample_label, "Sequence 01 #3989BD /02#");
	lv_label_set_long_mode(ui->summary_sample_label, LV_LABEL_LONG_WRAP);

	ui->summary_sample_sequencesummary_container = lv_obj_create(ui->summary_sample_background);
	lv_obj_align_to(ui->summary_sample_sequencesummary_container, ui->summary_sample_previousnext_buttoncontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
	lv_obj_clear_flag(ui->summary_sample_sequencesummary_container, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(ui->summary_sample_sequencesummary_container, SCREEN_WIDTH-20, 320);
	lv_obj_set_style_bg_color(ui->summary_sample_sequencesummary_container, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->summary_sample_sequencesummary_container, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->summary_sample_sequencesummary_container, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->summary_sample_sequencesummary_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->summary_sample_sequencesummary_container, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_sample_sequencesummary_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Sequence summary label
	static lv_obj_t *sequencesummarylabel;
	sequencesummarylabel = lv_label_create(ui->summary_sample_sequencesummary_container);
	lv_obj_align(sequencesummarylabel, LV_ALIGN_TOP_LEFT, 5, 5);
	lv_label_set_text(sequencesummarylabel, "SEQUENCE SUMMARY:");
	lv_obj_set_style_text_font (sequencesummarylabel, &lv_font_montserrat_14_bold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(sequencesummarylabel, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);

	//status symbol write or wrong
	ui->summary_sample_statussymbol = lv_img_create(ui->summary_sample_sequencesummary_container);
	lv_img_set_src(ui->summary_sample_statussymbol, &cross_icon);
	lv_obj_align(ui->summary_sample_statussymbol, LV_ALIGN_TOP_RIGHT, 0, 0);

	static lv_obj_t *startlabel;
	static lv_obj_t *stoplabel;

	//Start label sample info
	startlabel = lv_label_create(ui->summary_sample_sequencesummary_container);
	lv_obj_align_to(startlabel, ui->summary_sample_sequencesummary_container, LV_ALIGN_TOP_LEFT, 5, 40);
	lv_obj_set_style_text_color(startlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(startlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(startlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(startlabel, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(startlabel, "START:");

	//stop label sample info
	stoplabel = lv_label_create(ui->summary_sample_sequencesummary_container);
	lv_obj_align_to(stoplabel, ui->summary_sample_sequencesummary_container, LV_ALIGN_TOP_RIGHT, -90, 40);
	lv_obj_set_style_text_color(stoplabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(stoplabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(stoplabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(stoplabel, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(stoplabel, "STOP:");

	//Start Date
	ui->summary_sample_datestartvalue = lv_label_create(ui->summary_sample_sequencesummary_container);
	lv_obj_align_to(ui->summary_sample_datestartvalue, startlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
	lv_obj_set_style_text_color(ui->summary_sample_datestartvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summary_sample_datestartvalue, &lv_font_montserrat_22_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_sample_datestartvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_sample_datestartvalue, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_sample_datestartvalue, "24/12/2019");


	//Stop Date
	ui->summary_sample_datestopvalue = lv_label_create(ui->summary_sample_sequencesummary_container);
	lv_obj_align_to(ui->summary_sample_datestopvalue, stoplabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
	lv_obj_set_style_text_color(ui->summary_sample_datestopvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summary_sample_datestopvalue, &lv_font_montserrat_22_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_sample_datestopvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_sample_datestopvalue, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_sample_datestopvalue, "24/12/2019");

	/********************************************************
	 * Volume counter container start
	 ********************************************************/
	static lv_obj_t *volumecountercontainer;
	static lv_obj_t *volumecounterlabel;
	static lv_obj_t *volumestartlabel;
	static lv_obj_t *volumestoplabel;
	static lv_obj_t *volumetargetlabel;
	static lv_obj_t *volumeeffectivelabel;
	static lv_obj_t *volumevariationlabel;

	//Volume counter container
	volumecountercontainer = lv_obj_create(ui->summary_sample_sequencesummary_container);
	lv_obj_align_to(volumecountercontainer, ui->summary_sample_sequencesummary_container, LV_ALIGN_TOP_LEFT, 0, 90);
	lv_obj_clear_flag(volumecountercontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(volumecountercontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(volumecountercontainer, SCREEN_WIDTH-20, 120);
	lv_obj_set_style_border_opa(volumecountercontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(volumecountercontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(volumecountercontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(volumecountercontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Volume counter label
	volumecounterlabel = lv_label_create(volumecountercontainer);
	lv_obj_set_width(volumecounterlabel, 300);
	lv_obj_align_to(volumecounterlabel, volumecountercontainer, LV_ALIGN_TOP_LEFT, 0, 5);
	lv_obj_set_style_text_color(volumecounterlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(volumecounterlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(volumecounterlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumecounterlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumecounterlabel, "VOLUME COUNTER:");

	//Volume start label
	volumestartlabel = lv_label_create(volumecountercontainer);
	lv_obj_align_to(volumestartlabel, volumecounterlabel, LV_ALIGN_TOP_LEFT, 0, 30);
	lv_obj_set_style_text_color(volumestartlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(volumestartlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(volumestartlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumestartlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumestartlabel, "START:");
	//Volume Start Value
	ui->summary_sample_volumestartvalue = lv_label_create(volumecountercontainer);
	lv_obj_align_to(ui->summary_sample_volumestartvalue, volumestartlabel, LV_ALIGN_OUT_RIGHT_TOP, 5, -2);
	lv_obj_set_style_text_color(ui->summary_sample_volumestartvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summary_sample_volumestartvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_sample_volumestartvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_sample_volumestartvalue, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_sample_volumestartvalue, "123478,65 L");

	//Volume Stop label
	volumestoplabel = lv_label_create(volumecountercontainer);
	lv_obj_align_to(volumestoplabel, volumecounterlabel, LV_ALIGN_TOP_RIGHT, -100, 30);
	lv_obj_set_style_text_color(volumestoplabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(volumestoplabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(volumestoplabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumestoplabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumestoplabel, "STOP:");
	//Volume Stop Value
	ui->summary_sample_volumestopvalue = lv_label_create(volumecountercontainer);
	lv_obj_align_to(ui->summary_sample_volumestopvalue, volumestoplabel, LV_ALIGN_OUT_RIGHT_TOP, 5, -2);
	lv_obj_set_style_text_color(ui->summary_sample_volumestopvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summary_sample_volumestopvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_sample_volumestopvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_sample_volumestopvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_sample_volumestopvalue, "123478,65 L");

	//Volume Target label
	volumetargetlabel = lv_label_create(volumecountercontainer);
	lv_obj_align_to(volumetargetlabel, volumecountercontainer, LV_ALIGN_BOTTOM_LEFT, 10, -20);
	lv_obj_set_style_text_color(volumetargetlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(volumetargetlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(volumetargetlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumetargetlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumetargetlabel, "TARGET");
	//Volume Target value
	ui->summary_sample_volumetargetvalue = lv_label_create(volumecountercontainer);
	lv_obj_align_to(ui->summary_sample_volumetargetvalue, volumetargetlabel, LV_ALIGN_OUT_TOP_LEFT, -10, -5);
	lv_obj_set_style_text_color(ui->summary_sample_volumetargetvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summary_sample_volumetargetvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_sample_volumetargetvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_sample_volumetargetvalue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_sample_volumetargetvalue, "3080,00 L");

	//Volume Effective label
	volumeeffectivelabel = lv_label_create(volumecountercontainer);
	lv_obj_align_to(volumeeffectivelabel, volumecountercontainer, LV_ALIGN_BOTTOM_MID, -10, -20);
	lv_obj_set_style_text_color(volumeeffectivelabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(volumeeffectivelabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(volumeeffectivelabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumeeffectivelabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumeeffectivelabel, "EFFECTIVE");
	//Volume Effective value
	ui->summary_sample_volumeeffectivevalue = lv_label_create(volumecountercontainer);
	lv_obj_align_to(ui->summary_sample_volumeeffectivevalue, volumeeffectivelabel, LV_ALIGN_OUT_TOP_LEFT, 0, -5);
	lv_obj_set_style_text_color(ui->summary_sample_volumeeffectivevalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summary_sample_volumeeffectivevalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_sample_volumeeffectivevalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_sample_volumeeffectivevalue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_sample_volumeeffectivevalue, "3073,65 L");

	//Volume variation label
	volumevariationlabel = lv_label_create(volumecountercontainer);
	lv_obj_align_to(volumevariationlabel, volumecountercontainer, LV_ALIGN_BOTTOM_RIGHT, -35, -20);
	lv_obj_set_style_text_color(volumevariationlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(volumevariationlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(volumevariationlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumevariationlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumevariationlabel, "VARIATION");
	//Volume variation value
	ui->summary_sample_volumevariationvalue = lv_label_create(volumecountercontainer);
	lv_obj_align_to(ui->summary_sample_volumevariationvalue, volumevariationlabel, LV_ALIGN_OUT_TOP_LEFT, 15, -5);
	lv_obj_set_style_text_color(ui->summary_sample_volumevariationvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summary_sample_volumevariationvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_sample_volumevariationvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_sample_volumevariationvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_sample_volumevariationvalue, "3.65%");
	/********************************************************
	 * Volume counter container End
	 ********************************************************/

	/*Create style*/
	static lv_point_t line_points[] = { {20, 200}, {270, 200}};
	static lv_style_t style_line;
	lv_style_init(&style_line);
	lv_style_set_line_width(&style_line, 1);
	lv_style_set_line_color(&style_line, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_line_rounded(&style_line, true);
	lv_obj_t * line1;
	line1 = lv_line_create(ui->summary_sample_sequencesummary_container);
	lv_line_set_points(line1, line_points, 2);     /*Set the points*/
	lv_obj_add_style(line1, &style_line, 0);

    	/********************************************************
	 * HOUR counter container End
	 ********************************************************/

	static lv_obj_t *hourcountercontainer;
	static lv_obj_t *hourcounterlabel;
	static lv_obj_t *hourstartlabel;
	static lv_obj_t *hourstoplabel;
	static lv_obj_t *hourtargetlabel;
	static lv_obj_t *houreffectivelabel;
	static lv_obj_t *hourvariationlabel;

	//container object
	hourcountercontainer = lv_obj_create(ui->summary_sample_sequencesummary_container);
	lv_obj_align_to(hourcountercontainer, volumecountercontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
	lv_obj_clear_flag(hourcountercontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(hourcountercontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(hourcountercontainer, SCREEN_WIDTH-20, 120);
	lv_obj_set_style_border_opa(hourcountercontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(hourcountercontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(hourcountercontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(hourcountercontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//hour counter label
	hourcounterlabel = lv_label_create(hourcountercontainer);
	lv_obj_set_width(hourcounterlabel, 300);
	lv_obj_align_to(hourcounterlabel, hourcountercontainer, LV_ALIGN_TOP_LEFT, 0, 10);
	lv_obj_set_style_text_color(hourcounterlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(hourcounterlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(hourcounterlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(hourcounterlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(hourcounterlabel, "HOUR COUNTER:");

	//hour start label
	hourstartlabel = lv_label_create(hourcountercontainer);
	lv_obj_align_to(hourstartlabel, hourcounterlabel, LV_ALIGN_TOP_LEFT, 0, 30);
	lv_obj_set_style_text_color(hourstartlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(hourstartlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(hourstartlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(hourstartlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(hourstartlabel, "START:");
	//hour start value
	ui->summary_sample_hourstartvalue = lv_label_create(hourcountercontainer);
	lv_obj_align_to(ui->summary_sample_hourstartvalue, hourstartlabel, LV_ALIGN_OUT_RIGHT_TOP, 5, -2);
	lv_obj_set_style_text_color(ui->summary_sample_hourstartvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summary_sample_hourstartvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_sample_hourstartvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_sample_hourstartvalue, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_sample_hourstartvalue, "1238,65 H");

	//hour stop label
	hourstoplabel = lv_label_create(hourcountercontainer);
	lv_obj_align_to(hourstoplabel, hourcounterlabel, LV_ALIGN_TOP_RIGHT, -90, 30);
	lv_obj_set_style_text_color(hourstoplabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(hourstoplabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(volumestoplabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(hourstoplabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(hourstoplabel, "STOP:");
	//hour stop value
	ui->summary_sample_hourstopvalue = lv_label_create(hourcountercontainer);
	lv_obj_align_to(ui->summary_sample_hourstopvalue, hourstoplabel, LV_ALIGN_OUT_RIGHT_TOP, 5, -2);
	lv_obj_set_style_text_color(ui->summary_sample_hourstopvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summary_sample_hourstopvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_sample_hourstopvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_sample_hourstopvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_sample_hourstopvalue, "1268,65 H");

	//hour target label
	hourtargetlabel = lv_label_create(hourcountercontainer);
	lv_obj_align_to(hourtargetlabel, hourcountercontainer, LV_ALIGN_BOTTOM_LEFT, 5, -10);
	lv_obj_set_style_text_color(hourtargetlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(hourtargetlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(hourtargetlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(hourtargetlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(hourtargetlabel, "TARGET");
	//hour target value
	ui->summary_sample_hourtargetvalue = lv_label_create(hourcountercontainer);
	lv_obj_align_to(ui->summary_sample_hourtargetvalue, hourtargetlabel, LV_ALIGN_OUT_TOP_LEFT, -5, -5);
	lv_obj_set_style_text_color(ui->summary_sample_hourtargetvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summary_sample_hourtargetvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_sample_hourtargetvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_sample_hourtargetvalue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_sample_hourtargetvalue, "30,00 H");

	//hour effective label
	houreffectivelabel = lv_label_create(hourcountercontainer);
	lv_obj_align_to(houreffectivelabel, hourcountercontainer, LV_ALIGN_BOTTOM_MID, -10, -10);
	lv_obj_set_style_text_color(houreffectivelabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(houreffectivelabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(houreffectivelabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(houreffectivelabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(houreffectivelabel, "EFFECTIVE");
	//hour effective value
	ui->summary_sample_houreffectivevalue = lv_label_create(hourcountercontainer);
	lv_obj_align_to(ui->summary_sample_houreffectivevalue, houreffectivelabel, LV_ALIGN_OUT_TOP_LEFT, 5, -5);
	lv_obj_set_style_text_color(ui->summary_sample_houreffectivevalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summary_sample_houreffectivevalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_sample_houreffectivevalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_sample_houreffectivevalue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_sample_houreffectivevalue, "29,99 H");

	//hour variation label
	hourvariationlabel = lv_label_create(hourcountercontainer);
	lv_obj_align_to(hourvariationlabel, hourcountercontainer, LV_ALIGN_BOTTOM_RIGHT, -35, -10);
	lv_obj_set_style_text_color(hourvariationlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(hourvariationlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(hourvariationlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(hourvariationlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(hourvariationlabel, "VARIATION");
	//hour variation value
	ui->summary_sample_hourvariationvalue = lv_label_create(hourcountercontainer);
	lv_obj_align_to(ui->summary_sample_hourvariationvalue, hourvariationlabel, LV_ALIGN_OUT_TOP_LEFT, 15, -5);
	lv_obj_set_style_text_color(ui->summary_sample_hourvariationvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summary_sample_hourvariationvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summary_sample_hourvariationvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summary_sample_hourvariationvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summary_sample_hourvariationvalue, "0.05%");
	/********************************************************
	 * Hour counter container end
	 *******************************************************/

	//AIR Flow container
	static lv_obj_t *airflowcontainer;
	airflowcontainer = lv_obj_create(ui->summary_sample_background);
	lv_obj_align_to(airflowcontainer, ui->summary_sample_sequencesummary_container, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_clear_flag(airflowcontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(airflowcontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(airflowcontainer, SCREEN_WIDTH-20, 100);
	lv_obj_set_style_border_opa(airflowcontainer, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(airflowcontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(airflowcontainer, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(airflowcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(airflowcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(airflowcontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    draw_meanmax_widget(&airflowcontainer, &ui->summary_sample_airflow_namevalue, "AIRFLOW VOLUMETRIC L/Min", "SETPOINT:",
    		&ui->summary_sample_airflow_setpointvalue, &ui->summary_sample_airflow_meanvalue, &ui->summary_sample_airflow_maxvalue,
			&ui->summary_sample_airflow_maxvaluearrow, &ui->summary_sample_airflow_minvalue, &ui->summary_sample_airflow_minvaluearrow,
			&ui->summary_sample_airflow_variationvalue);

    //Ambient Temperature container
	static lv_obj_t *ambienttemperaturecontainer;
	ambienttemperaturecontainer = lv_obj_create(ui->summary_sample_background);
	lv_obj_align_to(ambienttemperaturecontainer, airflowcontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_clear_flag(ambienttemperaturecontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ambienttemperaturecontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(ambienttemperaturecontainer, SCREEN_WIDTH-20, 100);
	lv_obj_set_style_border_opa(ambienttemperaturecontainer, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ambienttemperaturecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ambienttemperaturecontainer, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ambienttemperaturecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ambienttemperaturecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ambienttemperaturecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    draw_meanmax_widget(&ambienttemperaturecontainer, &ui->summary_sample_ambienttemperature_namevalue, "AMBIENT TEMPERATURE ° Celsius", "LIMIT:",
    		&ui->summary_sample_ambienttemperature_limitvalue, &ui->summary_sample_ambienttemperature_meanvalue, &ui->summary_sample_ambienttemperature_maxvalue,
			&ui->summary_sample_ambienttemperature_maxvaluearrow, &ui->summary_sample_ambienttemperature_minvalue, &ui->summary_sample_ambienttemperature_minvaluearrow,
			&ui->summary_sample_ambienttemperature_variationvalue);


    //Ambient Pressure container
	static lv_obj_t *ambientpressurecontainer;
	ambientpressurecontainer = lv_obj_create(ui->summary_sample_background);
	lv_obj_align_to(ambientpressurecontainer, ambienttemperaturecontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_clear_flag(ambientpressurecontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ambientpressurecontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(ambientpressurecontainer, SCREEN_WIDTH-20, 100);
	lv_obj_set_style_border_opa(ambientpressurecontainer, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ambientpressurecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ambientpressurecontainer, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ambientpressurecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ambientpressurecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ambientpressurecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    draw_meanmax_widget(&ambientpressurecontainer, &ui->summary_sample_ambientpressure_namevalue, "AMBIENT PRESSURE ° hPa", "LIMIT:",
    		&ui->summary_sample_ambientpressure_limitvalue, &ui->summary_sample_ambientpressure_meanvalue, &ui->summary_sample_ambientpressure_maxvalue,
			&ui->summary_sample_ambientpressure_maxvaluearrow, &ui->summary_sample_ambientpressure_minvalue, &ui->summary_sample_ambientpressure_minvaluearrow,
			&ui->summary_sample_ambientpressure_variationvalue);

    //Ambient Humidity container
	static lv_obj_t *ambienthumiditycontainer;
	ambienthumiditycontainer = lv_obj_create(ui->summary_sample_background);
	lv_obj_align_to(ambienthumiditycontainer, ambientpressurecontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_clear_flag(ambienthumiditycontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ambienthumiditycontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(ambienthumiditycontainer, SCREEN_WIDTH-20, 100);
	lv_obj_set_style_border_opa(ambienthumiditycontainer, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ambienthumiditycontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ambienthumiditycontainer, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ambienthumiditycontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ambienthumiditycontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ambienthumiditycontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	draw_meanmax_widget(&ambienthumiditycontainer, &ui->summary_sample_ambienthumidity_namevalue, "AMBIENT HUMIDITY %", "LIMIT:",
			&ui->summary_sample_ambienthumidity_limitvalue, &ui->summary_sample_ambienthumidity_meanvalue, &ui->summary_sample_ambienthumidity_maxvalue,
			&ui->summary_sample_ambienthumidity_maxvaluearrow, &ui->summary_sample_ambienthumidity_minvalue, &ui->summary_sample_ambienthumidity_minvaluearrow,
			&ui->summary_sample_ambienthumidity_variationvalue);


    //Ambient Humidity container
	static lv_obj_t *headlosscontainer;
	headlosscontainer = lv_obj_create(ui->summary_sample_background);
	lv_obj_align_to(headlosscontainer, ambienthumiditycontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_clear_flag(headlosscontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(headlosscontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(headlosscontainer, SCREEN_WIDTH-20, 100);
	lv_obj_set_style_border_opa(headlosscontainer, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(headlosscontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(headlosscontainer, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(headlosscontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(headlosscontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(headlosscontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	draw_meanmax_widget(&headlosscontainer, &ui->summary_sample_headloss_namevalue, "HEAD LOSS mbar", "LIMIT:",
			&ui->summary_sample_headloss_namevalue, &ui->summary_sample_headloss_meanvalue, &ui->summary_sample_headloss_maxvalue,
			&ui->summary_sample_headloss_maxvaluearrow, &ui->summary_sample_headloss_minvalue, &ui->summary_sample_headloss_minvaluearrow,
			&ui->summary_sample_headloss_variationvalue);


	//QUIT button
	static lv_style_t style_quitbutton;
	if (style_quitbutton.prop_cnt > 1)
		lv_style_reset(&style_quitbutton);
	else
		lv_style_init(&style_quitbutton);
	lv_style_set_bg_color(&style_quitbutton, ESPUPM_COLOR_GREEN);
	lv_style_set_bg_opa(&style_quitbutton, LV_OPA_MAX);
	lv_style_set_border_opa(&style_quitbutton, LV_OPA_MIN);
	lv_style_set_border_width(&style_quitbutton, 0);
	lv_style_set_shadow_width(&style_quitbutton, 0);
	lv_style_set_radius(&style_quitbutton, 5);

	ui->summary_sample_quitbutton = lv_btn_create(ui->summary_sample_background);
	lv_obj_align_to(ui->summary_sample_quitbutton, headlosscontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_size(ui->summary_sample_quitbutton, 300, 44);
	lv_obj_add_style(ui->summary_sample_quitbutton, &style_quitbutton, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->summary_sample_quitbutton, &style_quitbutton, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->summary_sample_quitbutton, &style_quitbutton, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_t *buttonlabel = lv_label_create(ui->summary_sample_quitbutton);
	lv_obj_center(buttonlabel);
	lv_obj_set_style_text_font(buttonlabel, &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(buttonlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(buttonlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "QUIT");

    /********Events Initialization************/
    events_init_summary_sample(ui);
}

/***********************************************************************************************************************
 * End of file
 ***********************************************************************************************************************/
