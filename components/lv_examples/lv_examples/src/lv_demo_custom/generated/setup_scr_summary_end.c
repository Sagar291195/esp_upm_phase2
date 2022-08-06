/*
 * setup_scr_summaryend.c
 *
 *  Created on: 28-Jun-2022
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


/***********************************************************************************************************************
 * static functions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * global functions
 ***********************************************************************************************************************/
/*
 * Function to draw summery end screen
 */
void setup_scr_summary_end(lv_ui *ui){

	//Summary End Screen main object
	ui->summaryend = lv_obj_create(NULL);
	static lv_style_t style_summaryend_default;
	if (style_summaryend_default.prop_cnt > 1)
		lv_style_reset(&style_summaryend_default);
	else
		lv_style_init(&style_summaryend_default);
	lv_style_set_bg_color(&style_summaryend_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_summaryend_default, SCREEN_MIN_OPACITY);
	lv_obj_add_style(ui->summaryend, &style_summaryend_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	/*****************************************************
	 *
	 * Suammry End Screen design Start
	 *
	 * **************************************************/
	//Summary end Screen Background
	ui->summaryend_background = lv_obj_create(ui->summaryend);
	lv_obj_clear_flag(ui->summaryend_background, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_scrollbar_mode(ui->summaryend_background, LV_SCROLLBAR_MODE_OFF);
	lv_obj_set_align(ui->summaryend_background, LV_ALIGN_TOP_MID);
	lv_obj_set_size(ui->summaryend_background, SCREEN_WIDTH, SCREEN_HEIGHT);
	static lv_style_t style_summaryend_background_default;
	if (style_summaryend_background_default.prop_cnt > 1)
		lv_style_reset(&style_summaryend_background_default);
	else
		lv_style_init(&style_summaryend_background_default);
	lv_style_set_radius(&style_summaryend_background_default, 0);
	lv_style_set_bg_color(&style_summaryend_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_color(&style_summaryend_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_dir(&style_summaryend_background_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_summaryend_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_border_color(&style_summaryend_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_border_width(&style_summaryend_background_default, 0);
	lv_style_set_border_opa(&style_summaryend_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_pad_left(&style_summaryend_background_default, 0);
	lv_style_set_pad_right(&style_summaryend_background_default, 0);
	lv_style_set_pad_top(&style_summaryend_background_default, 0);
	lv_style_set_pad_bottom(&style_summaryend_background_default, 0);
	lv_obj_add_style(ui->summaryend_background, &style_summaryend_background_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Summary end Screen Header
	setup_draw_header(ui, ui->summaryend_background);

	//Summary end Screen object for left arrow, parameter text and menu symbol
	setup_draw_title(ui, ui->summaryend_background, "SUMMARY", &archiv_icon, ESPUPM_BACKGROUND_COLOR);

    //Next previos container
	ui->summaryend_previousnext_buttoncontainer = lv_obj_create(ui->summaryend_background);
	lv_obj_align_to(ui->summaryend_previousnext_buttoncontainer, ui->title_container, LV_ALIGN_OUT_BOTTOM_LEFT, 10, 5);
	lv_obj_clear_flag(ui->summaryend_previousnext_buttoncontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(ui->summaryend_previousnext_buttoncontainer, SCREEN_WIDTH-20, 60);
	lv_obj_set_style_bg_color(ui->summaryend_previousnext_buttoncontainer, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->summaryend_previousnext_buttoncontainer, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->summaryend_previousnext_buttoncontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->summaryend_previousnext_buttoncontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->summaryend_previousnext_buttoncontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_previousnext_buttoncontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Page title Previous button
	ui->summaryend_previousbutton = lv_label_create(ui->summaryend_previousnext_buttoncontainer);
	lv_obj_set_size(ui->summaryend_previousbutton, 64,60);
	lv_obj_align_to(ui->summaryend_previousbutton, ui->title_container, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
	lv_obj_set_style_text_color(ui->summaryend_previousbutton, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_previousbutton, &lv_font_montserrat_34, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->summaryend_previousbutton, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->summaryend_previousbutton, ESPUPM_COLOR_BLACK, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->summaryend_previousbutton, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_previousbutton, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_previousbutton, LV_SYMBOL_PREV);

	//Next button
	ui->summaryend_nextbutton = lv_label_create(ui->summaryend_previousnext_buttoncontainer);
	lv_obj_set_size(ui->summaryend_nextbutton, 64,60);
	lv_obj_align_to(ui->summaryend_nextbutton, ui->title_container, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 5);
	lv_obj_set_style_text_color(ui->summaryend_nextbutton, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_nextbutton, &lv_font_montserrat_34, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->summaryend_nextbutton, ESPUPM_COLOR_BLACK, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->summaryend_nextbutton, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->summaryend_nextbutton, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_nextbutton, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_nextbutton, LV_SYMBOL_NEXT);

	//Page tile
	ui->summaryend_samplelabel = lv_label_create(ui->summaryend_previousnext_buttoncontainer);
	lv_obj_set_size(ui->summaryend_samplelabel, 100,44);
	lv_obj_align_to(ui->summaryend_samplelabel, ui->title_container, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
	lv_obj_set_style_text_color(ui->summaryend_samplelabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_samplelabel, &lv_font_montserrat_20_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_samplelabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_samplelabel, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_samplelabel, "Sample N° 1356");
	lv_label_set_long_mode(ui->summaryend_samplelabel, LV_LABEL_LONG_WRAP);

	/********************************************************
	 * Summary Sample info container start
	 ********************************************************/
	//Summary Sample container
	ui->summaryend_samplecontainer = lv_obj_create(ui->summaryend_background);
	lv_obj_align_to(ui->summaryend_samplecontainer, ui->summaryend_previousnext_buttoncontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_clear_flag(ui->summaryend_samplecontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->summaryend_samplecontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(ui->summaryend_samplecontainer, SCREEN_WIDTH-20, 620);
	lv_obj_set_style_bg_color(ui->summaryend_samplecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->summaryend_samplecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->summaryend_samplecontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->summaryend_samplecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->summaryend_samplecontainer, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_samplecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	static lv_obj_t *sampleinfocontainer;
	static lv_obj_t *startlabel;
	static lv_obj_t *stoplabel;
	//Sample info container
	sampleinfocontainer = lv_obj_create(ui->summaryend_samplecontainer);
	lv_obj_align(sampleinfocontainer, LV_ALIGN_TOP_LEFT, 0, 10);
	lv_obj_clear_flag(sampleinfocontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(sampleinfocontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(sampleinfocontainer, SCREEN_WIDTH-20, 350);
	lv_obj_set_style_border_opa(sampleinfocontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(sampleinfocontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(sampleinfocontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(sampleinfocontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//status symbol write or wrong
	ui->summaryend_statussymbol = lv_img_create(sampleinfocontainer);
	lv_img_set_src(ui->summaryend_statussymbol, &cross_icon);
	lv_obj_align(ui->summaryend_statussymbol, LV_ALIGN_TOP_RIGHT, 0, 0);

	//Start label sample info
	startlabel = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(startlabel, sampleinfocontainer, LV_ALIGN_TOP_LEFT, 0, 30);
	lv_obj_set_style_text_color(startlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(startlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(startlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(startlabel, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(startlabel, "START:");

	//stop label sample info
	stoplabel = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(stoplabel, sampleinfocontainer, LV_ALIGN_TOP_RIGHT, -90, 30);
	lv_obj_set_style_text_color(stoplabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(stoplabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(stoplabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(stoplabel, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(stoplabel, "STOP:");

	//Start Date
	ui->summaryend_datestart = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(ui->summaryend_datestart, startlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
	lv_obj_set_style_text_color(ui->summaryend_datestart, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_datestart, &lv_font_montserrat_22_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_datestart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_datestart, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_datestart, "24/12/2019");

	//Start Duration
	ui->summaryend_startduration = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(ui->summaryend_startduration, ui->summaryend_datestart, LV_ALIGN_OUT_BOTTOM_RIGHT, -20, 0);
	lv_obj_set_style_text_color(ui->summaryend_startduration, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_startduration, &lv_font_montserrat_14_bold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_startduration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_startduration, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_startduration, "15H35");

	//Stop Date
	ui->summaryend_datestop = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(ui->summaryend_datestop, stoplabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
	lv_obj_set_style_text_color(ui->summaryend_datestop, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_datestop, &lv_font_montserrat_22_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_datestop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_datestop, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_datestop, "24/12/2019");

	//Stop Duration
	ui->summaryend_stopduration = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(ui->summaryend_stopduration, ui->summaryend_datestop, LV_ALIGN_OUT_BOTTOM_RIGHT, -15, 0);
	lv_obj_set_style_text_color(ui->summaryend_stopduration, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_stopduration, &lv_font_montserrat_14_bold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_stopduration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_stopduration, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_stopduration, "15H35");

	//Container Title
    ui->summaryend_containertitle = lv_label_create(sampleinfocontainer);
    lv_obj_set_size(ui->summaryend_containertitle, 300, 30);
	lv_obj_align_to(ui->summaryend_containertitle, ui->summaryend_datestart, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 30);
	lv_obj_set_style_text_color(ui->summaryend_containertitle, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_containertitle, &lv_font_montserrat_16_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_containertitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_containertitle, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_containertitle, "Sample N° 1356");

	static lv_obj_t *flowsetpointlabel;
	static lv_obj_t *sequencenumberlabel;
	static lv_obj_t *durationlabel;
	static lv_obj_t *startbluelabel;
	static lv_obj_t *endbylabel;
	static lv_obj_t *startpersonlabel;
	static lv_obj_t *stoppersonlabel;
	static lv_obj_t *problemlabel;

	//Flow set point label
	flowsetpointlabel = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(flowsetpointlabel, ui->summaryend_containertitle, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_text_color(flowsetpointlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(flowsetpointlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(flowsetpointlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(flowsetpointlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(flowsetpointlabel, "FLOW SET POINT:");
	//Flow set point value
	ui->summaryend_flowsetpointvalue = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(ui->summaryend_flowsetpointvalue, ui->summaryend_containertitle, LV_ALIGN_OUT_BOTTOM_MID, 0, 9);
	lv_obj_set_width(ui->summaryend_flowsetpointvalue, 150);
	lv_obj_set_style_text_color(ui->summaryend_flowsetpointvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_flowsetpointvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_flowsetpointvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_flowsetpointvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_flowsetpointvalue, "7 L/Min");

	//sequence number label
	sequencenumberlabel = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(sequencenumberlabel, flowsetpointlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_text_color(sequencenumberlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(sequencenumberlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(sequencenumberlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(sequencenumberlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(sequencenumberlabel, "SEQUENCE NUMBER:");
	//sequence number value
	ui->summaryend_sequencenumbervalue = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(ui->summaryend_sequencenumbervalue, ui->summaryend_flowsetpointvalue, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 9);
	lv_obj_set_width(ui->summaryend_sequencenumbervalue, 150);
	lv_obj_set_style_text_color(ui->summaryend_sequencenumbervalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_sequencenumbervalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_sequencenumbervalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_sequencenumbervalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_sequencenumbervalue, "02");

	//Duration label
	durationlabel = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(durationlabel, sequencenumberlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_text_color(durationlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(durationlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(durationlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(durationlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(durationlabel, "DURATION:");
	//Duration value
	ui->summaryend_durationvalue = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(ui->summaryend_durationvalue, ui->summaryend_sequencenumbervalue, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 8);
	lv_obj_set_width(ui->summaryend_durationvalue, 150);
	lv_obj_set_style_text_color(ui->summaryend_durationvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_durationvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_durationvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_durationvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_durationvalue, "2 h");

	//Start label in sample info
	startbluelabel = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(startbluelabel, durationlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_text_color(startbluelabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(startbluelabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(startbluelabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(startbluelabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(startbluelabel, "START:");
	//Start label null for space management
	ui->summaryend_startvalue = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(ui->summaryend_startvalue, ui->summaryend_durationvalue, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 8);
	lv_obj_set_width(ui->summaryend_startvalue, 150);
	lv_obj_set_style_text_color(ui->summaryend_startvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_startvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_startvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_startvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_startvalue, "");

	//Endby label
	endbylabel = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(endbylabel, startbluelabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_text_color(endbylabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(endbylabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(endbylabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(endbylabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(endbylabel, "END BY:");
	//Endby value
	ui->summaryend_endbyvalue = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(ui->summaryend_endbyvalue, ui->summaryend_startvalue, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 7);
	lv_obj_set_width(ui->summaryend_endbyvalue, 150);
	lv_obj_set_style_text_color(ui->summaryend_endbyvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_endbyvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_endbyvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_endbyvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_endbyvalue, "TIME FINISHED");

	//Start person label
	startpersonlabel = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(startpersonlabel, endbylabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_text_color(startpersonlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(startpersonlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(startpersonlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(startpersonlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(startpersonlabel, "START PERSON:");
	//Start person value
	ui->summaryend_startpersonvalue = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(ui->summaryend_startpersonvalue, ui->summaryend_endbyvalue, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 7);
	lv_obj_set_width(ui->summaryend_startpersonvalue, 150);
	lv_obj_set_style_text_color(ui->summaryend_startpersonvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_startpersonvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_startpersonvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_startpersonvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_startpersonvalue, "MARK");

	//Stop person label
	stoppersonlabel = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(stoppersonlabel, startpersonlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_text_color(stoppersonlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(stoppersonlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(stoppersonlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(stoppersonlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(stoppersonlabel, "STOP PERSON:");
	//stop person value
	ui->summaryend_endpersonvalue = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(ui->summaryend_endpersonvalue, ui->summaryend_startpersonvalue, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 7);
	lv_obj_set_width(ui->summaryend_endpersonvalue, 150);
	lv_obj_set_style_text_color(ui->summaryend_endpersonvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_endpersonvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_endpersonvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_endpersonvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_endpersonvalue, "JOHN");

	//problem label
	problemlabel = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(problemlabel, stoppersonlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_text_color(problemlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(problemlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(problemlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(problemlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(problemlabel, "PROBLEM:");
	//Problem value string
	ui->summaryend_problemvalue = lv_label_create(sampleinfocontainer);
	lv_obj_align_to(ui->summaryend_problemvalue, ui->summaryend_endpersonvalue, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 7);
	lv_obj_set_width(ui->summaryend_problemvalue, 150);
	lv_obj_set_style_text_color(ui->summaryend_problemvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_problemvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_problemvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_problemvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_problemvalue, "NONE");
	/********************************************************
	 * Summary Sample container End
	 ********************************************************/


	//Horizontal line
	lv_obj_t * hor_line = lv_line_create(sampleinfocontainer);
	static lv_point_t p[] = {{-20, 5}, {238, 5}};
	lv_line_set_points(hor_line, p, 2);
	lv_obj_align_to(hor_line, sampleinfocontainer, LV_ALIGN_BOTTOM_MID, 0, -10);
	static lv_style_t style_hor_line;
	lv_style_init(&style_hor_line);
	lv_style_set_line_color(&style_hor_line, ESPUPM_COLOR_GREY);
	lv_style_set_line_width(&style_hor_line, 3);
	lv_style_set_line_rounded(&style_hor_line, true);
	lv_obj_add_style(hor_line, &style_hor_line, LV_PART_MAIN);


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
	volumecountercontainer = lv_obj_create(ui->summaryend_samplecontainer);
	lv_obj_align_to(volumecountercontainer, sampleinfocontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
	lv_obj_clear_flag(volumecountercontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(volumecountercontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(volumecountercontainer, SCREEN_WIDTH-20, 140);
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
	ui->summaryend_volumestartvalue = lv_label_create(volumecountercontainer);
	lv_obj_align_to(ui->summaryend_volumestartvalue, volumestartlabel, LV_ALIGN_OUT_RIGHT_TOP, 5, -2);
	lv_obj_set_style_text_color(ui->summaryend_volumestartvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_volumestartvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_volumestartvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_volumestartvalue, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_volumestartvalue, "123478,65 L");

	//Volume Stop label
	volumestoplabel = lv_label_create(volumecountercontainer);
	lv_obj_align_to(volumestoplabel, volumecounterlabel, LV_ALIGN_TOP_RIGHT, -100, 30);
	lv_obj_set_style_text_color(volumestoplabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(volumestoplabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(volumestoplabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumestoplabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumestoplabel, "STOP:");
	//Volume Stop Value
	ui->summaryend_volumestopvalue = lv_label_create(volumecountercontainer);
	lv_obj_align_to(ui->summaryend_volumestopvalue, volumestoplabel, LV_ALIGN_OUT_RIGHT_TOP, 5, -2);
	lv_obj_set_style_text_color(ui->summaryend_volumestopvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_volumestopvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_volumestopvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_volumestopvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_volumestopvalue, "123478,65 L");

	//Volume Target label
	volumetargetlabel = lv_label_create(volumecountercontainer);
	lv_obj_align_to(volumetargetlabel, volumecountercontainer, LV_ALIGN_BOTTOM_LEFT, 10, -20);
	lv_obj_set_style_text_color(volumetargetlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(volumetargetlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(volumetargetlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumetargetlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumetargetlabel, "TARGET");
	//Volume Target value
	ui->summaryend_volumetargetvalue = lv_label_create(volumecountercontainer);
	lv_obj_align_to(ui->summaryend_volumetargetvalue, volumetargetlabel, LV_ALIGN_OUT_TOP_LEFT, -10, -5);
	lv_obj_set_style_text_color(ui->summaryend_volumetargetvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_volumetargetvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_volumetargetvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_volumetargetvalue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_volumetargetvalue, "3080,00 L");

	//Volume Effective label
	volumeeffectivelabel = lv_label_create(volumecountercontainer);
	lv_obj_align_to(volumeeffectivelabel, volumecountercontainer, LV_ALIGN_BOTTOM_MID, -10, -20);
	lv_obj_set_style_text_color(volumeeffectivelabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(volumeeffectivelabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(volumeeffectivelabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumeeffectivelabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumeeffectivelabel, "EFFECTIVE");
	//Volume Effective value
	ui->summaryend_volumeeffectivevalue = lv_label_create(volumecountercontainer);
	lv_obj_align_to(ui->summaryend_volumeeffectivevalue, volumeeffectivelabel, LV_ALIGN_OUT_TOP_LEFT, 0, -5);
	lv_obj_set_style_text_color(ui->summaryend_volumeeffectivevalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_volumeeffectivevalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_volumeeffectivevalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_volumeeffectivevalue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_volumeeffectivevalue, "3073,65 L");

	//Volume variation label
	volumevariationlabel = lv_label_create(volumecountercontainer);
	lv_obj_align_to(volumevariationlabel, volumecountercontainer, LV_ALIGN_BOTTOM_RIGHT, -40, -20);
	lv_obj_set_style_text_color(volumevariationlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(volumevariationlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(volumevariationlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(volumevariationlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(volumevariationlabel, "VARIATION");
	//Volume variation value
	ui->summaryend_volumevariationvalue = lv_label_create(volumecountercontainer);
	lv_obj_align_to(ui->summaryend_volumevariationvalue, volumevariationlabel, LV_ALIGN_OUT_TOP_LEFT, 15, -5);
	lv_obj_set_style_text_color(ui->summaryend_volumevariationvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_volumevariationvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_volumevariationvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_volumevariationvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_volumevariationvalue, "3.65%");
	/********************************************************
	 * Volume counter container End
	 ********************************************************/

	//Horizotal line
	hor_line = lv_line_create(volumecountercontainer);
	lv_line_set_points(hor_line, p, 2);
	lv_obj_align_to(hor_line, volumecountercontainer, LV_ALIGN_BOTTOM_MID, 0, -5);
	lv_obj_add_style(hor_line, &style_hor_line, LV_PART_MAIN);

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
	hourcountercontainer = lv_obj_create(ui->summaryend_samplecontainer);
	lv_obj_align_to(hourcountercontainer, volumecountercontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
	lv_obj_clear_flag(hourcountercontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(hourcountercontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(hourcountercontainer, SCREEN_WIDTH-20, 130);
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
	ui->summaryend_hourstartvalue = lv_label_create(hourcountercontainer);
	lv_obj_align_to(ui->summaryend_hourstartvalue, hourstartlabel, LV_ALIGN_OUT_RIGHT_TOP, 5, -2);
	lv_obj_set_style_text_color(ui->summaryend_hourstartvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_hourstartvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_hourstartvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_hourstartvalue, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_hourstartvalue, "1238,65 H");

	//hour stop label
	hourstoplabel = lv_label_create(hourcountercontainer);
	lv_obj_align_to(hourstoplabel, hourcounterlabel, LV_ALIGN_TOP_RIGHT, -90, 30);
	lv_obj_set_style_text_color(hourstoplabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(hourstoplabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(volumestoplabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(hourstoplabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(hourstoplabel, "STOP:");
	//hour stop value
	ui->summaryend_hourstopvalue = lv_label_create(hourcountercontainer);
	lv_obj_align_to(ui->summaryend_hourstopvalue, hourstoplabel, LV_ALIGN_OUT_RIGHT_TOP, 5, -2);
	lv_obj_set_style_text_color(ui->summaryend_hourstopvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_hourstopvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_hourstopvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_hourstopvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_hourstopvalue, "1268,65 H");

	//hour target label
	hourtargetlabel = lv_label_create(hourcountercontainer);
	lv_obj_align_to(hourtargetlabel, hourcountercontainer, LV_ALIGN_BOTTOM_LEFT, 5, -10);
	lv_obj_set_style_text_color(hourtargetlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(hourtargetlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(hourtargetlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(hourtargetlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(hourtargetlabel, "TARGET");
	//hour target value
	ui->summaryend_hourtargetvalue = lv_label_create(hourcountercontainer);
	lv_obj_align_to(ui->summaryend_hourtargetvalue, hourtargetlabel, LV_ALIGN_OUT_TOP_LEFT, -5, -5);
	lv_obj_set_style_text_color(ui->summaryend_hourtargetvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_hourtargetvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_hourtargetvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_hourtargetvalue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_hourtargetvalue, "30,00 H");

	//hour effective label
	houreffectivelabel = lv_label_create(hourcountercontainer);
	lv_obj_align_to(houreffectivelabel, hourcountercontainer, LV_ALIGN_BOTTOM_MID, -10, -10);
	lv_obj_set_style_text_color(houreffectivelabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(houreffectivelabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(houreffectivelabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(houreffectivelabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(houreffectivelabel, "EFFECTIVE");
	//hour effective value
	ui->summaryend_houreffectivevalue = lv_label_create(hourcountercontainer);
	lv_obj_align_to(ui->summaryend_houreffectivevalue, houreffectivelabel, LV_ALIGN_OUT_TOP_LEFT, 5, -5);
	lv_obj_set_style_text_color(ui->summaryend_houreffectivevalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_houreffectivevalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_houreffectivevalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_houreffectivevalue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_houreffectivevalue, "29,99 H");

	///hour variation label
	hourvariationlabel = lv_label_create(hourcountercontainer);
	lv_obj_align_to(hourvariationlabel, hourcountercontainer, LV_ALIGN_BOTTOM_RIGHT, -40, -10);
	lv_obj_set_style_text_color(hourvariationlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(hourvariationlabel, &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(hourvariationlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(hourvariationlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(hourvariationlabel, "VARIATION");
	//hour variation value
	ui->summaryend_hourvariationvalue = lv_label_create(hourcountercontainer);
	lv_obj_align_to(ui->summaryend_hourvariationvalue, hourvariationlabel, LV_ALIGN_OUT_TOP_LEFT, 15, -5);
	lv_obj_set_style_text_color(ui->summaryend_hourvariationvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->summaryend_hourvariationvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_hourvariationvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->summaryend_hourvariationvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->summaryend_hourvariationvalue, "0.05%");
	/********************************************************
	 * Summary Sample container End
	 ********************************************************/

	//horizontal line
	ui->summaryend_horizantalline = lv_line_create(ui->summaryend_background);
	lv_line_set_points(ui->summaryend_horizantalline, p, 2);
	lv_obj_align_to(ui->summaryend_horizantalline, ui->summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
	lv_obj_add_style(ui->summaryend_horizantalline, &style_hor_line, LV_PART_MAIN);

	//container to design sequence container1
	ui->summaryend_sequencewidgetcontainer1 = lv_obj_create(ui->summaryend_background);
	lv_obj_clear_flag(ui->summaryend_sequencewidgetcontainer1, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->summaryend_sequencewidgetcontainer1, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_clear_flag(ui->summaryend_background, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
	lv_obj_align_to(ui->summaryend_sequencewidgetcontainer1, ui->summaryend_samplecontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
	lv_obj_set_size(ui->summaryend_sequencewidgetcontainer1, SCREEN_WIDTH-20, 100);
	lv_obj_set_style_bg_color(ui->summaryend_sequencewidgetcontainer1, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->summaryend_sequencewidgetcontainer1, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->summaryend_sequencewidgetcontainer1, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->summaryend_sequencewidgetcontainer1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->summaryend_sequencewidgetcontainer1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_sequencewidgetcontainer1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Draw Sequence widget
	setup_draw_sequence_widget(&ui->summaryend_sequencewidgetcontainer1, &ui->summaryend_sequencewidgetcontainer1_label, &ui->summaryend_sequencewidgetcontainer1_flowsetpoint,
					&ui->summaryend_sequencewidgetcontainer1_durationvalue, &ui->summaryend_sequencewidgetcontainer1_problemvalue, &ui->summaryend_sequencewidgetcontainer1_button);

	//container to design sequence container2
	ui->summaryend_sequencewidgetcontainer2 = lv_obj_create(ui->summaryend_background);
	lv_obj_clear_flag(ui->summaryend_sequencewidgetcontainer2, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->summaryend_sequencewidgetcontainer2, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_clear_flag(ui->summaryend_background, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
	lv_obj_align_to(ui->summaryend_sequencewidgetcontainer2, ui->summaryend_sequencewidgetcontainer1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
	lv_obj_set_size(ui->summaryend_sequencewidgetcontainer2, SCREEN_WIDTH-20, 100);
	lv_obj_set_style_bg_color(ui->summaryend_sequencewidgetcontainer2, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->summaryend_sequencewidgetcontainer2, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->summaryend_sequencewidgetcontainer2, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->summaryend_sequencewidgetcontainer2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->summaryend_sequencewidgetcontainer2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->summaryend_sequencewidgetcontainer2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Draw Sequence widget
	setup_draw_sequence_widget(&ui->summaryend_sequencewidgetcontainer2, &ui->summaryend_sequencewidgetcontainer2_label, &ui->summaryend_sequencewidgetcontainer2_flowsetpoint,
					&ui->summaryend_sequencewidgetcontainer2_durationvalue, &ui->summaryend_sequencewidgetcontainer2_problemvalue, &ui->summaryend_sequencewidgetcontainer2_button);

	//Design Export USB button
	static lv_style_t style_exportusbbutton;
	if (style_exportusbbutton.prop_cnt > 1)
		lv_style_reset(&style_exportusbbutton);
	else
		lv_style_init(&style_exportusbbutton);
	lv_style_set_bg_color(&style_exportusbbutton, ESPUPM_COLOR_BLUE);
	lv_style_set_bg_opa(&style_exportusbbutton, LV_OPA_MAX);
	lv_style_set_border_color(&style_exportusbbutton, ESPUPM_COLOR_LIGHT_BLUE);
	lv_style_set_border_opa(&style_exportusbbutton, LV_OPA_100);
	lv_style_set_border_width(&style_exportusbbutton, 2);
	lv_style_set_shadow_width(&style_exportusbbutton, 0);
	lv_style_set_radius(&style_exportusbbutton, 5);

	ui->summaryend_exportusb = lv_btn_create(ui->summaryend_background);
	lv_obj_align_to(ui->summaryend_exportusb, ui->summaryend_sequencewidgetcontainer2, LV_ALIGN_OUT_BOTTOM_LEFT, 10, 10);
	lv_obj_set_size(ui->summaryend_exportusb, 130, 44);
	lv_obj_add_style(ui->summaryend_exportusb, &style_exportusbbutton, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->summaryend_exportusb, &style_exportusbbutton, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->summaryend_exportusb, &style_exportusbbutton, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_t *buttonlabel = lv_label_create(ui->summaryend_exportusb);
	lv_obj_center(buttonlabel);
	lv_obj_set_style_text_font(buttonlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(buttonlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(buttonlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "EXPORT USB");

	//Design QUIT button
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

	//QUIT button
	ui->summaryend_quit = lv_btn_create(ui->summaryend_background);
	lv_obj_align_to(ui->summaryend_quit, ui->summaryend_sequencewidgetcontainer2, LV_ALIGN_OUT_BOTTOM_RIGHT, -110, 10);
	lv_obj_set_size(ui->summaryend_quit, 130, 44);
	lv_obj_add_style(ui->summaryend_quit, &style_quitbutton, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->summaryend_quit, &style_quitbutton, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->summaryend_quit, &style_quitbutton, LV_PART_MAIN|LV_STATE_PRESSED);
	buttonlabel = lv_label_create(ui->summaryend_quit);
	lv_obj_center(buttonlabel);
	lv_obj_set_style_text_font(buttonlabel, &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(buttonlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(buttonlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "QUIT");

	//Make screen scrollable
	lv_obj_add_flag(ui->summaryend_background, LV_OBJ_FLAG_SCROLLABLE);

	/********Events Initialization******************/
}

/***********************************************************************************************************************
 * End of file
 ***********************************************************************************************************************/
