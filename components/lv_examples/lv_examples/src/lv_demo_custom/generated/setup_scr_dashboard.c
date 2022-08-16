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
static void draw_chart_widget(lv_ui *ui, lv_obj_t **parentobject);
static void draw_dashboard_resumeinfo_widget(lv_ui *ui, lv_obj_t *parentobject);
static void draw_dashboard_parameter_widget(lv_obj_t *parentobject, char *labeltext, char *icon, int zoom, int angle,
                                            lv_obj_t *objectstatus, char *lowertext);
static void draw_event_cb(lv_event_t * e);
/***********************************************************************************************************************
 * static functions
 ***********************************************************************************************************************/
static void draw_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);

    /*Add the faded area before the lines are drawn*/
    lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);
    if(dsc->part == LV_PART_ITEMS) {
    	if(!dsc->p1 || !dsc->p2) return;

		/*Add a line mask that keeps the area below the line*/
		lv_draw_mask_line_param_t line_mask_param;
		lv_draw_mask_line_points_init(&line_mask_param, dsc->p1->x, dsc->p1->y, dsc->p2->x, dsc->p2->y, LV_DRAW_MASK_LINE_SIDE_BOTTOM);
		int16_t line_mask_id = lv_draw_mask_add(&line_mask_param, NULL);

		/*Add a fade effect: transparent bottom covering top*/
		lv_coord_t h = lv_obj_get_height(obj);
		lv_draw_mask_fade_param_t fade_mask_param;
		lv_draw_mask_fade_init(&fade_mask_param, &obj->coords, LV_OPA_COVER, obj->coords.y1 + h / 8, LV_OPA_TRANSP,obj->coords.y2);
		int16_t fade_mask_id = lv_draw_mask_add(&fade_mask_param, NULL);

		/*Draw a rectangle that will be affected by the mask*/
		lv_draw_rect_dsc_t draw_rect_dsc;
		lv_draw_rect_dsc_init(&draw_rect_dsc);
		draw_rect_dsc.bg_opa = LV_OPA_20;
		draw_rect_dsc.bg_color = dsc->line_dsc->color;

		lv_area_t a;
		a.x1 = dsc->p1->x;
		a.x2 = dsc->p2->x - 1;
		a.y1 = LV_MIN(dsc->p1->y, dsc->p2->y);
		a.y2 = obj->coords.y2;
		lv_draw_rect(&a, dsc->clip_area, &draw_rect_dsc);

		/*Remove the masks*/
		lv_draw_mask_free_param(&line_mask_param);
		lv_draw_mask_free_param(&fade_mask_param);
		lv_draw_mask_remove_id(line_mask_id);
		lv_draw_mask_remove_id(fade_mask_id);
	}
	/*Hook the division lines too*/
	else if(dsc->part == LV_PART_MAIN) {
		if(dsc->line_dsc == NULL || dsc->p1 == NULL || dsc->p2 == NULL) return;

		/*Vertical line*/
		if(dsc->p1->x == dsc->p2->x) {
		dsc->line_dsc->color  = lv_palette_lighten(LV_PALETTE_GREY, 1);
		if(dsc->id == 3) {
			dsc->line_dsc->width  = 2;
			dsc->line_dsc->dash_gap  = 0;
			dsc->line_dsc->dash_width  = 0;
		}
		else {
			dsc->line_dsc->width = 1;
			dsc->line_dsc->dash_gap  = 6;
			dsc->line_dsc->dash_width  = 6;
		}
	}
	/*Horizontal line*/
	else {
			if(dsc->id == 2) {
				dsc->line_dsc->width  = 2;
				dsc->line_dsc->dash_gap  = 0;
				dsc->line_dsc->dash_width  = 0;
			}
			else {
				dsc->line_dsc->width = 2;
				dsc->line_dsc->dash_gap  = 6;
				dsc->line_dsc->dash_width  = 6;
			}

			if(dsc->id == 1  || dsc->id == 3) {
				dsc->line_dsc->color  = lv_palette_main(LV_PALETTE_GREEN);
			} else {
				dsc->line_dsc->color  = lv_palette_lighten(LV_PALETTE_GREY, 1);
			}
		}
	}
}

static void draw_dashboard_parameter_widget(lv_obj_t *parentobject, char *labeltext, char *icon, int zoom, int angle, lv_obj_t *objectstatus, char *lowertext){

	static lv_obj_t *titlelabel;
	static lv_obj_t *titlesymbol;
	static lv_obj_t *lowerlebel;
	titlelabel = lv_label_create(parentobject);
	lv_obj_align_to(titlelabel, parentobject, LV_ALIGN_TOP_LEFT, 5, 5);
	lv_obj_set_style_text_align(titlelabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(titlelabel,  &lv_font_montserrat_13_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(titlelabel, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_long_mode(titlelabel, LV_LABEL_LONG_CLIP);
	lv_label_set_text(titlelabel, labeltext);


	titlesymbol = lv_img_create(parentobject);
	lv_obj_align(titlesymbol, LV_ALIGN_LEFT_MID, 5, 0);
	lv_obj_set_style_bg_img_recolor(titlesymbol, ESPUPM_COLOR_WHITE, LV_PART_MAIN);
	lv_img_set_src(titlesymbol, icon);

	objectstatus = lv_img_create(parentobject);
	lv_obj_align(objectstatus, LV_ALIGN_TOP_RIGHT, -5, 5);
	lv_obj_set_style_bg_img_recolor(objectstatus, ESPUPM_COLOR_WHITE, LV_PART_MAIN);
	lv_obj_set_style_bg_img_recolor_opa(objectstatus, LV_OPA_100, LV_PART_MAIN);
	lv_img_set_src(objectstatus, &ok_icon);
	lv_img_set_zoom(objectstatus, zoom);
	lv_img_set_angle(objectstatus, angle);
	lv_obj_set_style_text_color(objectstatus, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(objectstatus, &lv_font_montserrat_26, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(objectstatus, 0, LV_STATE_DEFAULT);


	lowerlebel = lv_label_create(parentobject);
	lv_obj_align(lowerlebel, LV_ALIGN_BOTTOM_RIGHT, -20, -5);
	lv_obj_set_style_text_align(lowerlebel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(lowerlebel,  &lv_font_montserrat_11_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(lowerlebel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_long_mode(lowerlebel, LV_LABEL_LONG_CLIP);
	lv_label_set_text(lowerlebel, lowertext);

}

static void draw_chart_widget(lv_ui *ui, lv_obj_t **parentobject){
	ui->dashboard_chart = lv_chart_create(*parentobject);
	lv_obj_set_size(ui->dashboard_chart, 300, 300);
	lv_obj_align(ui->dashboard_chart, LV_ALIGN_TOP_MID, 0, 30);
	lv_obj_set_style_bg_color(ui->dashboard_chart, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->dashboard_chart, LV_OPA_0, LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->dashboard_chart, 0, LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->dashboard_chart, 0, LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->dashboard_chart, 0, LV_STATE_DEFAULT);
	lv_chart_set_div_line_count(ui->dashboard_chart, 0, 0);
	lv_chart_set_type(ui->dashboard_chart, LV_CHART_TYPE_LINE);
	lv_obj_add_event_cb(ui->dashboard_chart, draw_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);
	lv_chart_set_update_mode(ui->dashboard_chart, LV_CHART_UPDATE_MODE_SHIFT);

	ui->dashboard_ser = lv_chart_add_series(ui->dashboard_chart, lv_palette_main(LV_PALETTE_BLUE), LV_CHART_AXIS_PRIMARY_Y);
	lv_chart_set_point_count(ui->dashboard_chart, 60);
	for(uint8_t i = 0; i < 60; i++) {
	  lv_chart_set_next_value(ui->dashboard_chart, ui->dashboard_ser , lv_rand(20, 90));
	}
}

/*
 * Function to draw resume info widget
 */
static void draw_dashboard_resumeinfo_widget(lv_ui *ui, lv_obj_t *parentobject){
	ui->dashboard_resumeinfo_currentstatus = lv_label_create(parentobject);
	lv_obj_set_width(ui->dashboard_resumeinfo_currentstatus, 250);
	lv_obj_align_to(ui->dashboard_resumeinfo_currentstatus, parentobject, LV_ALIGN_TOP_LEFT, 30, 5);
	lv_obj_set_style_text_align(ui->dashboard_resumeinfo_currentstatus, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_resumeinfo_currentstatus,  &lv_font_montserrat_22_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_resumeinfo_currentstatus, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_long_mode(ui->dashboard_resumeinfo_currentstatus, LV_LABEL_LONG_CLIP);
	lv_label_set_text(ui->dashboard_resumeinfo_currentstatus, "Ready");

	ui->dashboard_resumeinfo_arcinner = lv_arc_create(parentobject);
	lv_obj_clear_flag(ui->dashboard_resumeinfo_arcinner, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_align(ui->dashboard_resumeinfo_arcinner, LV_ALIGN_CENTER, 0, -20);
	lv_obj_set_size(ui->dashboard_resumeinfo_arcinner, 155, 155);
	lv_obj_set_style_bg_color(ui->dashboard_resumeinfo_arcinner, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->dashboard_resumeinfo_arcinner, LV_OPA_TRANSP, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->dashboard_resumeinfo_arcinner, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->dashboard_resumeinfo_arcinner, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->dashboard_resumeinfo_arcinner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->dashboard_resumeinfo_arcinner, ESPUPM_COLOR_PURPLE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->dashboard_resumeinfo_arcinner, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->dashboard_resumeinfo_arcinner, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_remove_style(ui->dashboard_resumeinfo_arcinner, NULL, LV_PART_KNOB);
	lv_arc_set_bg_angles(ui->dashboard_resumeinfo_arcinner, 0, 360);
	lv_arc_set_angles(ui->dashboard_resumeinfo_arcinner, 0, 360);
	lv_arc_set_rotation(ui->dashboard_resumeinfo_arcinner, 0);

	ui->dashboard_resumeinfo_arcouter = lv_arc_create(parentobject);
	lv_obj_clear_flag(ui->dashboard_resumeinfo_arcouter, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_align(ui->dashboard_resumeinfo_arcouter, LV_ALIGN_CENTER, 0, -20);
	lv_obj_set_size(ui->dashboard_resumeinfo_arcouter, 190, 190);
	lv_obj_set_style_bg_color(ui->dashboard_resumeinfo_arcouter, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->dashboard_resumeinfo_arcouter, LV_OPA_TRANSP, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->dashboard_resumeinfo_arcouter, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->dashboard_resumeinfo_arcouter, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->dashboard_resumeinfo_arcouter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->dashboard_resumeinfo_arcouter, ESPUPM_COLOR_PURPLE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->dashboard_resumeinfo_arcouter, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->dashboard_resumeinfo_arcouter, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_remove_style(ui->dashboard_resumeinfo_arcouter, NULL, LV_PART_KNOB);
	lv_arc_set_bg_angles(ui->dashboard_resumeinfo_arcouter, 0, 360);
	lv_arc_set_angles(ui->dashboard_resumeinfo_arcouter, 0, 270);
	lv_arc_set_rotation(ui->dashboard_resumeinfo_arcouter, 0);

	ui->dashboard_resumeinfo_percentagetext = lv_label_create(parentobject);
	lv_obj_align_to(ui->dashboard_resumeinfo_percentagetext, ui->dashboard_resumeinfo_arcinner, LV_ALIGN_TOP_MID, -15, 30);
	lv_label_set_text(ui->dashboard_resumeinfo_percentagetext,  "78");
	lv_obj_set_style_text_align(ui->dashboard_resumeinfo_percentagetext, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_resumeinfo_percentagetext,  &lv_font_montserrat_40, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_resumeinfo_percentagetext, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);


	ui->dashboard_resumeinfo_percentageymboltext = lv_label_create(parentobject);
	lv_obj_align_to(ui->dashboard_resumeinfo_percentageymboltext, ui->dashboard_resumeinfo_percentagetext, LV_ALIGN_OUT_RIGHT_BOTTOM, 0, -10);
	lv_label_set_text(ui->dashboard_resumeinfo_percentageymboltext,  "%");
	lv_obj_set_style_text_align(ui->dashboard_resumeinfo_percentageymboltext, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_resumeinfo_percentageymboltext,  &lv_font_montserrat_18_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_resumeinfo_percentageymboltext, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);

    ui->dashboard_resumeinfo_time_label = lv_label_create(parentobject);
	lv_obj_align(ui->dashboard_resumeinfo_time_label, LV_ALIGN_CENTER, 0, -10);
	lv_label_set_text(ui->dashboard_resumeinfo_time_label,  "1h 23min");
	lv_obj_set_style_text_align(ui->dashboard_resumeinfo_time_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_resumeinfo_time_label,  &lv_font_montserrat_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_resumeinfo_time_label, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);

    ui->dashboard_resumeinfo_sequence_label = lv_label_create(parentobject);
	lv_obj_align(ui->dashboard_resumeinfo_sequence_label, LV_ALIGN_CENTER, 0, 20);
	lv_label_set_text(ui->dashboard_resumeinfo_sequence_label,  "01 / 01");
	lv_obj_set_style_text_align(ui->dashboard_resumeinfo_sequence_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_resumeinfo_sequence_label,  &lv_font_montserrat_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_resumeinfo_sequence_label, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);

	ui->dashboard_resumeinfo_messagelabel = lv_label_create(parentobject);
	lv_obj_align(ui->dashboard_resumeinfo_messagelabel,  LV_ALIGN_CENTER, 0, -15);
	lv_label_set_text(ui->dashboard_resumeinfo_messagelabel,  "Let's Start");
	lv_obj_set_style_text_align(ui->dashboard_resumeinfo_messagelabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_resumeinfo_messagelabel,  &lv_font_montserrat_16_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_resumeinfo_messagelabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);

	lv_obj_t *hor_line = lv_line_create(parentobject);
	static lv_point_t p[] = {{0, 30}, {0, 80}};
	lv_line_set_points(hor_line, p, 2);
	lv_obj_align_to(hor_line, NULL, LV_ALIGN_BOTTOM_MID, 0, -5);
	static lv_style_t style_hor_line;
	lv_style_init(&style_hor_line);
	lv_style_set_line_color(&style_hor_line,  ESPUPM_COLOR_WHITE);
	lv_style_set_line_width(&style_hor_line,  3);
	lv_style_set_line_rounded(&style_hor_line, true);
	lv_obj_add_style(hor_line, &style_hor_line, LV_PART_MAIN);

	lv_obj_t *hour_Label = lv_label_create(parentobject);
	lv_obj_align_to(hour_Label, parentobject, LV_ALIGN_BOTTOM_RIGHT, -90, -40);
	lv_obj_set_style_text_font(hour_Label,  &lv_font_montserrat_14_bold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(hour_Label, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(hour_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(hour_Label, "TOTAL HOURS");

	ui->dashboard_resumeinfo_totalhourintlabel = lv_label_create(parentobject);
	lv_obj_align_to(ui->dashboard_resumeinfo_totalhourintlabel, hour_Label, LV_ALIGN_OUT_BOTTOM_MID, -40, 10);
	lv_label_set_text_fmt(ui->dashboard_resumeinfo_totalhourintlabel, "%d.", 10632);
	lv_obj_set_style_text_align(ui->dashboard_resumeinfo_totalhourintlabel, LV_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_resumeinfo_totalhourintlabel,  &lv_font_montserrat_24_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_resumeinfo_totalhourintlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);

	ui->dashboard_resumeinfo_totalhourfloatlabel = lv_label_create(parentobject);
	lv_obj_align_to(ui->dashboard_resumeinfo_totalhourfloatlabel, ui->dashboard_resumeinfo_totalhourintlabel, LV_ALIGN_OUT_RIGHT_BOTTOM, 0, 0);
	lv_obj_set_style_text_align(ui->dashboard_resumeinfo_totalhourfloatlabel, LV_ALIGN_TOP_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_resumeinfo_totalhourfloatlabel,  &lv_font_montserrat_13_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_resumeinfo_totalhourfloatlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->dashboard_resumeinfo_totalhourfloatlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text_fmt(ui->dashboard_resumeinfo_totalhourfloatlabel, "%02d H", 11);

	lv_obj_t *liters_Label = lv_label_create(parentobject);
	lv_obj_align_to(liters_Label, parentobject, LV_ALIGN_BOTTOM_LEFT, 20, -40);
	lv_obj_set_style_text_font(liters_Label,  &lv_font_montserrat_14_bold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(liters_Label, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(liters_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(liters_Label, "TOTAL LITERS");

	ui->dashboard_resumeinfo_totalliterintlabel = lv_label_create(parentobject);
	lv_obj_align_to(ui->dashboard_resumeinfo_totalliterintlabel, liters_Label, LV_ALIGN_OUT_BOTTOM_MID, -30, 10);
	lv_obj_set_style_text_align(ui->dashboard_resumeinfo_totalliterintlabel, LV_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_resumeinfo_totalliterintlabel,  &lv_font_montserrat_24_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_resumeinfo_totalliterintlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->dashboard_resumeinfo_totalliterintlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text_fmt(ui->dashboard_resumeinfo_totalliterintlabel, "%d.", 10632);

	ui->dashboard_resumeinfo_totalliterfloatlabel = lv_label_create(parentobject);
	lv_obj_align_to(ui->dashboard_resumeinfo_totalliterfloatlabel, ui->dashboard_resumeinfo_totalliterintlabel, LV_ALIGN_OUT_RIGHT_BOTTOM, 0, 0);
	lv_obj_set_style_text_align(ui->dashboard_resumeinfo_totalliterfloatlabel, LV_ALIGN_TOP_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_resumeinfo_totalliterfloatlabel,  &lv_font_montserrat_13_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_resumeinfo_totalliterfloatlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->dashboard_resumeinfo_totalliterfloatlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text_fmt(ui->dashboard_resumeinfo_totalliterfloatlabel, "%02d L", 11);
}
/***********************************************************************************************************************
 * global unctions
 ***********************************************************************************************************************/

/*
 * Function to draw dashboard screen
 */
void setup_scr_dashboard(lv_ui *ui){

	//Dashboard Screen main object
	ui->dashboard = lv_obj_create(NULL);
	static lv_style_t style_dashboard_default;
	if (style_dashboard_default.prop_cnt > 1)
		lv_style_reset(&style_dashboard_default);
	else
		lv_style_init(&style_dashboard_default);
	lv_style_set_bg_color(&style_dashboard_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_dashboard_default, SCREEN_MIN_OPACITY);
	lv_obj_set_scrollbar_mode(ui->dashboard, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_style(ui->dashboard, &style_dashboard_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	/*********************************************Dashboard Screen design Start**********************************/
	//Dashboard Screen Background
	ui->dashboard_background = lv_obj_create(ui->dashboard);
	lv_obj_set_align(ui->dashboard_background, LV_ALIGN_CENTER);
	lv_obj_set_size(ui->dashboard_background, SCREEN_WIDTH, SCREEN_HEIGHT);
	lv_obj_set_scrollbar_mode(ui->dashboard_background, LV_SCROLLBAR_MODE_OFF);
	static lv_style_t style_dashboard_background_default;
	if (style_dashboard_background_default.prop_cnt > 1)
		lv_style_reset(&style_dashboard_background_default);
	else
		lv_style_init(&style_dashboard_background_default);
	lv_style_set_radius(&style_dashboard_background_default, 0);
	lv_style_set_bg_color(&style_dashboard_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_color(&style_dashboard_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_dir(&style_dashboard_background_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_dashboard_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_border_color(&style_dashboard_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_border_width(&style_dashboard_background_default, 0);
	lv_style_set_border_opa(&style_dashboard_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_pad_left(&style_dashboard_background_default, 0);
	lv_style_set_pad_right(&style_dashboard_background_default, 0);
	lv_style_set_pad_top(&style_dashboard_background_default, 0);
	lv_style_set_pad_bottom(&style_dashboard_background_default, 0);
	lv_obj_add_style(ui->dashboard_background, &style_dashboard_background_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Dashboard Screen Header
	setup_draw_header(ui, ui->dashboard_background);

	//Dashboard Screen Menu Button
	ui->dashboard_menubutton = lv_btn_create(ui->dashboard_background);
	lv_obj_align_to(ui->dashboard_menubutton, ui->header_timelabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 7);
	lv_obj_set_size(ui->dashboard_menubutton, SCREEN_MENU_BUTTON_HEIGHT, SCREEN_MENU_BUTTON_WIDTH);
	static lv_style_t style_button_dashboard_menubutton;
	if (style_button_dashboard_menubutton.prop_cnt > 1)
		lv_style_reset(&style_button_dashboard_menubutton);
	else
		lv_style_init(&style_button_dashboard_menubutton);
	lv_style_set_radius(&style_button_dashboard_menubutton, 0);
	lv_style_set_bg_color(&style_button_dashboard_menubutton, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_opa(&style_button_dashboard_menubutton, LV_OPA_0);
	lv_style_set_shadow_color(&style_button_dashboard_menubutton, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_shadow_opa(&style_button_dashboard_menubutton, SCREEN_MIN_OPACITY);
	lv_style_set_shadow_width(&style_button_dashboard_menubutton, 0);
	lv_style_set_border_color(&style_button_dashboard_menubutton, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_border_width(&style_button_dashboard_menubutton, 0);
	lv_style_set_border_opa(&style_button_dashboard_menubutton, SCREEN_MIN_OPACITY);
	lv_obj_add_style(ui->dashboard_menubutton, &style_button_dashboard_menubutton, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->dashboard_menubuttonlabel = lv_label_create(ui->dashboard_menubutton);
	lv_obj_clear_flag(ui->dashboard_menubuttonlabel, LV_OBJ_FLAG_CLICKABLE);
	lv_label_set_text(ui->dashboard_menubuttonlabel, LV_SYMBOL_LIST);
	lv_obj_set_style_text_color(ui->dashboard_menubuttonlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_menubuttonlabel, &lv_font_montserrat_40, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->dashboard_menubutton, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->dashboard_menubuttonlabel, LV_ALIGN_TOP_LEFT, 0, 0);

	//Dashboard Screen Welcome Label
	ui->dashboard_welcomelabel = lv_label_create(ui->dashboard_background);
	lv_obj_align_to(ui->dashboard_welcomelabel, ui->header_battery, LV_ALIGN_BOTTOM_LEFT, -130, 20);
	static lv_style_t style_header_welcome_label;
	if (style_header_welcome_label.prop_cnt > 1)
		lv_style_reset(&style_header_welcome_label);
	else
		lv_style_init(&style_header_welcome_label);
	lv_style_init(&style_header_welcome_label);
	lv_style_set_text_font(&style_header_welcome_label, &lv_font_montserrat_22_semibold);
	lv_style_set_text_color(&style_header_welcome_label, ESPUPM_COLOR_WHITE);
	lv_obj_add_style(ui->dashboard_welcomelabel, &style_header_welcome_label, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->dashboard_welcomelabel, "Welcome");

	//Dashboard Screen Date label
	ui->dashboard_datelabel = lv_label_create(ui->dashboard_background);
	lv_obj_align_to(ui->dashboard_datelabel, ui->dashboard_welcomelabel, LV_ALIGN_BOTTOM_LEFT, 0, 20);
	static lv_style_t style_header_date_label;
	if (style_header_date_label.prop_cnt > 1)
		lv_style_reset(&style_header_date_label);
	else
		lv_style_init(&style_header_date_label);
	lv_style_init(&style_header_date_label);
	lv_style_set_text_font(&style_header_date_label, &lv_font_montserrat_14_bold);
	lv_style_set_text_color(&style_header_date_label, ESPUPM_COLOR_BLUE);
	lv_obj_add_style(ui->dashboard_datelabel, &style_header_date_label, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->dashboard_datelabel, "Today is 21, JUNE 2022");

	/*********************************************Menu Screen design Start**********************************/
	//Menu Screen Background Start
	ui->dashboard_menuview = lv_obj_create(ui->dashboard);
	lv_obj_align_to(ui->dashboard_menuview, ui->dashboard, LV_ALIGN_TOP_LEFT, 0, 0);
	lv_obj_set_scrollbar_mode(ui->dashboard_menuview, LV_SCROLLBAR_MODE_OFF);
	lv_obj_set_height(ui->dashboard_menuview, 480);
	lv_obj_set_width(ui->dashboard_menuview, 250);
	lv_obj_add_flag(ui->dashboard_menuview, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->dashboard_menuview, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_style_border_opa(ui->dashboard_menuview, LV_OPA_MIN,LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->dashboard_menuview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->dashboard_menuview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Menu Screen Background
	ui->dashboard_menuviewnavierlogo = lv_img_create(ui->dashboard_menuview);
	lv_obj_set_size(ui->dashboard_menuviewnavierlogo, navier_logo.header.w, navier_logo.header.h);
	lv_obj_align(ui->dashboard_menuviewnavierlogo, LV_ALIGN_TOP_MID, 0, 0);
	lv_obj_set_style_img_opa(ui->dashboard_menuviewnavierlogo, LV_OPA_MAX, LV_PART_MAIN);
	lv_obj_set_style_bg_img_opa(ui->dashboard_menuviewnavierlogo, LV_OPA_MIN, LV_PART_MAIN);
	lv_obj_set_style_img_recolor(ui->dashboard_menuviewnavierlogo, ESPUPM_COLOR_WHITE, LV_PART_MAIN);
	lv_img_set_zoom(ui->dashboard_menuviewnavierlogo, 200);
	lv_img_set_src(ui->dashboard_menuviewnavierlogo, (char *)&navier_logo);

	static lv_style_t style_dashboard_menuviewbutton;
	if (style_dashboard_menuviewbutton.prop_cnt > 1)
		lv_style_reset(&style_dashboard_menuviewbutton);
	else
		lv_style_init(&style_dashboard_menuviewbutton);
	lv_style_set_bg_opa(&style_dashboard_menuviewbutton, LV_OPA_MAX);
	lv_style_set_border_opa(&style_dashboard_menuviewbutton, LV_OPA_MIN);
	lv_style_set_border_width(&style_dashboard_menuviewbutton, 0);
	lv_style_set_shadow_width(&style_dashboard_menuviewbutton, 0);
	lv_style_set_radius(&style_dashboard_menuviewbutton, 5);

	lv_obj_t *buttonlabel;
	lv_obj_t *buttonimage;
	static lv_style_t style_menuview_label;
	if (style_menuview_label.prop_cnt > 1)
		lv_style_reset(&style_menuview_label);
	else
		lv_style_init(&style_menuview_label);
	lv_style_init(&style_menuview_label);
	lv_style_set_bg_color(&style_menuview_label, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_opa(&style_menuview_label, LV_OPA_MIN);
	lv_style_set_text_font(&style_menuview_label, &lv_font_montserrat_15_semibold);
	lv_style_set_text_color(&style_menuview_label, ESPUPM_COLOR_BLUE);

	//Menu Screen Service button
	ui->dashboard_menuviewservicebutton = lv_btn_create(ui->dashboard_menuview);
	lv_obj_set_size(ui->dashboard_menuviewservicebutton, 190, 44);
	lv_obj_align_to(ui->dashboard_menuviewservicebutton, ui->dashboard_menuview, LV_ALIGN_TOP_MID, 0, 100);
	lv_obj_add_style(ui->dashboard_menuviewservicebutton, &style_dashboard_menuviewbutton, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->dashboard_menuviewservicebutton, &style_dashboard_menuviewbutton, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->dashboard_menuviewservicebutton, &style_dashboard_menuviewbutton, LV_PART_MAIN|LV_STATE_PRESSED);
	buttonimage = lv_img_create(ui->dashboard_menuviewservicebutton);
	lv_obj_clear_flag(buttonimage, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_size(buttonimage, service_icon.header.w, service_icon.header.h);
	lv_obj_align(buttonimage, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_img_recolor(buttonimage, ESPUPM_COLOR_WHITE, LV_PART_MAIN);
	lv_img_set_zoom(buttonimage, 220);
	lv_img_set_src(buttonimage, &service_icon);
	buttonlabel = lv_label_create(ui->dashboard_menuviewservicebutton);
	lv_obj_clear_flag(buttonlabel, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_style(buttonlabel, &style_menuview_label, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_align_to(buttonlabel, buttonlabel, LV_ALIGN_OUT_RIGHT_MID, 10, 5);
	lv_label_set_text(buttonlabel, "SERVICE");


	//Menu screen Info Button
	ui->dashboard_menuviewinfobutton = lv_btn_create(ui->dashboard_menuview);
	lv_obj_set_size(ui->dashboard_menuviewinfobutton, 190, 44);
	lv_obj_align_to(ui->dashboard_menuviewinfobutton, ui->dashboard_menuviewservicebutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
	lv_obj_add_style(ui->dashboard_menuviewinfobutton, &style_dashboard_menuviewbutton, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->dashboard_menuviewinfobutton, &style_dashboard_menuviewbutton, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->dashboard_menuviewinfobutton, &style_dashboard_menuviewbutton, LV_PART_MAIN|LV_STATE_PRESSED);
	buttonimage = lv_img_create(ui->dashboard_menuviewinfobutton);
	lv_obj_clear_flag(buttonimage, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_size(buttonimage, info_icon.header.w, info_icon.header.h);
	lv_obj_align(buttonimage, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_img_recolor(buttonimage, ESPUPM_COLOR_WHITE, LV_PART_MAIN);
	lv_img_set_zoom(buttonimage, 220);
	lv_img_set_src(buttonimage, &info_icon);
	buttonlabel = lv_label_create(ui->dashboard_menuviewinfobutton);
	lv_obj_clear_flag(buttonlabel, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_style(buttonlabel, &style_menuview_label, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_align_to(buttonlabel, buttonlabel, LV_ALIGN_OUT_RIGHT_MID, 10, 5);
	lv_label_set_text(buttonlabel, "INFO");

	//Menu Screen Archiv Button
	ui->dashboard_menuviewarchievebutton = lv_btn_create(ui->dashboard_menuview);
	lv_obj_set_size(ui->dashboard_menuviewarchievebutton, 190, 44);
	lv_obj_align_to(ui->dashboard_menuviewarchievebutton, ui->dashboard_menuviewinfobutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
	lv_obj_add_style(ui->dashboard_menuviewarchievebutton, &style_dashboard_menuviewbutton, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->dashboard_menuviewarchievebutton, &style_dashboard_menuviewbutton, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->dashboard_menuviewarchievebutton, &style_dashboard_menuviewbutton, LV_PART_MAIN|LV_STATE_PRESSED);
	buttonimage = lv_img_create(ui->dashboard_menuviewarchievebutton);
	lv_obj_clear_flag(buttonimage, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_size(buttonimage, archiv_icon.header.w, archiv_icon.header.h);
	lv_obj_align(buttonimage, LV_ALIGN_LEFT_MID, 5, 0);
	lv_obj_set_style_img_recolor(buttonimage, ESPUPM_COLOR_WHITE, LV_PART_MAIN);
	lv_img_set_zoom(buttonimage, 200);
	lv_img_set_src(buttonimage, &archiv_icon);
	buttonlabel = lv_label_create(ui->dashboard_menuviewarchievebutton);
	lv_obj_clear_flag(buttonlabel, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_style(buttonlabel, &style_menuview_label, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_align_to(buttonlabel, buttonlabel, LV_ALIGN_OUT_RIGHT_MID, 10, 5);
	lv_label_set_text(buttonlabel, "ARCHIV");

	//Menu Screen Metrology Button
	ui->dashboard_menuviewmetrologybutton = lv_btn_create(ui->dashboard_menuview);
	lv_obj_set_size(ui->dashboard_menuviewmetrologybutton, 190, 44);
	lv_obj_align_to(ui->dashboard_menuviewmetrologybutton, ui->dashboard_menuviewarchievebutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
	lv_obj_add_style(ui->dashboard_menuviewmetrologybutton, &style_dashboard_menuviewbutton, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->dashboard_menuviewmetrologybutton, &style_dashboard_menuviewbutton, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->dashboard_menuviewmetrologybutton, &style_dashboard_menuviewbutton, LV_PART_MAIN|LV_STATE_PRESSED);
	buttonimage = lv_img_create(ui->dashboard_menuviewmetrologybutton);
	lv_obj_clear_flag(buttonimage, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_size(buttonimage, metrology_icon.header.w, metrology_icon.header.h);
	lv_obj_align(buttonimage, LV_ALIGN_LEFT_MID, 5, 0);
	lv_obj_set_style_img_recolor(buttonimage, ESPUPM_COLOR_WHITE, LV_PART_MAIN);
	lv_img_set_zoom(buttonimage, 200);
	lv_img_set_src(buttonimage, &metrology_icon);
	buttonlabel = lv_label_create(ui->dashboard_menuviewmetrologybutton);
	lv_obj_clear_flag(buttonlabel, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_style(buttonlabel, &style_menuview_label, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_align_to(buttonlabel, buttonlabel, LV_ALIGN_OUT_RIGHT_MID, 10, 5);
	lv_label_set_text(buttonlabel, "METROLOGY");

	//Menu Screen Parameter Button
	ui->dashboard_menuviewparameterbutton = lv_btn_create(ui->dashboard_menuview);
	lv_obj_set_size(ui->dashboard_menuviewparameterbutton, 190, 44);
	lv_obj_align_to(ui->dashboard_menuviewparameterbutton, ui->dashboard_menuviewmetrologybutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
	lv_obj_add_style(ui->dashboard_menuviewparameterbutton, &style_dashboard_menuviewbutton, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->dashboard_menuviewparameterbutton, &style_dashboard_menuviewbutton, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->dashboard_menuviewparameterbutton, &style_dashboard_menuviewbutton, LV_PART_MAIN|LV_STATE_PRESSED);
	buttonimage = lv_img_create(ui->dashboard_menuviewparameterbutton);
	lv_obj_clear_flag(buttonimage, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_size(buttonimage, parameter_icon.header.w, parameter_icon.header.h);
	lv_obj_align(buttonimage, LV_ALIGN_LEFT_MID, 5, 0);
	lv_obj_set_style_img_recolor(buttonimage, ESPUPM_COLOR_WHITE, LV_PART_MAIN);
	lv_img_set_zoom(buttonimage, 200);
	lv_img_set_src(buttonimage, &parameter_icon);
	buttonlabel = lv_label_create(ui->dashboard_menuviewparameterbutton);
	lv_obj_clear_flag(buttonlabel, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_style(buttonlabel, &style_menuview_label, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_align_to(buttonlabel, buttonlabel, LV_ALIGN_OUT_RIGHT_MID, 10, 5);
	lv_label_set_text(buttonlabel, "PARAMETER");
	/*********************************************Menu Screen design End**********************************/


	//Resume Info background
	static lv_obj_t *resumeinfowidget;
	resumeinfowidget = lv_obj_create(ui->dashboard_background);
	lv_obj_clear_flag(resumeinfowidget, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(resumeinfowidget, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(resumeinfowidget, ui->dashboard_menubutton, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
	lv_obj_set_size(resumeinfowidget, SCREEN_WIDTH-20, 320);
	lv_obj_set_style_bg_color(resumeinfowidget, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(resumeinfowidget, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(resumeinfowidget, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(resumeinfowidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(resumeinfowidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	draw_dashboard_resumeinfo_widget(ui, resumeinfowidget);
	/*********************************************
	 * Resume info design end
	 * ******************************************/



    //Dashboard Screen Stop-Start Button
	ui->dashboard_stopbutton = lv_btn_create(ui->dashboard_background);
	lv_obj_align(ui->dashboard_stopbutton, LV_ALIGN_BOTTOM_MID, 0, -10);
	lv_obj_set_size(ui->dashboard_stopbutton, 300, SCREEN_MENU_BUTTON_WIDTH);
	static lv_style_t style_button_dashboard_stopbutton;
	if (style_button_dashboard_stopbutton.prop_cnt > 1)
		lv_style_reset(&style_button_dashboard_stopbutton);
	else
		lv_style_init(&style_button_dashboard_stopbutton);
	lv_style_set_radius(&style_button_dashboard_stopbutton, 0);
	lv_style_set_bg_color(&style_button_dashboard_stopbutton, ESPUPM_COLOR_LIGHT_BLUE);
	lv_style_set_shadow_color(&style_button_dashboard_stopbutton, ESPUPM_COLOR_LIGHT_BLUE);
	lv_style_set_shadow_opa(&style_button_dashboard_stopbutton, SCREEN_MIN_OPACITY);
	lv_style_set_shadow_width(&style_button_dashboard_stopbutton, 0);
	lv_style_set_border_color(&style_button_dashboard_stopbutton, ESPUPM_COLOR_LIGHT_BLUE);
	lv_style_set_border_width(&style_button_dashboard_stopbutton, 0);
	lv_style_set_border_opa(&style_button_dashboard_stopbutton, SCREEN_MIN_OPACITY);
	lv_obj_add_style(ui->dashboard_stopbutton, &style_button_dashboard_stopbutton, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->dashboard_stopbutton, &style_button_dashboard_stopbutton, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->dashboard_stopbutton, &style_button_dashboard_stopbutton, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_t *btnlabel = lv_label_create(ui->dashboard_stopbutton);
	lv_obj_clear_flag(btnlabel, LV_OBJ_FLAG_CLICKABLE);
	lv_label_set_text(btnlabel, "START JOB");
	lv_obj_set_style_text_color(btnlabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(btnlabel, &lv_font_montserrat_15_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(btnlabel, 0, LV_STATE_DEFAULT);
	lv_obj_align(btnlabel, LV_ALIGN_CENTER, 0, 0);

	/*********************************************
	 * CHART design start
	 * ******************************************/
	ui->dashboard_chartwidget = lv_obj_create(ui->dashboard_background);
	lv_obj_clear_flag(ui->dashboard_chartwidget, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->dashboard_chartwidget, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(ui->dashboard_chartwidget, ui->dashboard_stopbutton, LV_ALIGN_OUT_BOTTOM_LEFT, 15, 20);
	lv_obj_set_size(ui->dashboard_chartwidget, SCREEN_WIDTH-50, 280);
	lv_obj_set_style_bg_color(ui->dashboard_chartwidget, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->dashboard_chartwidget, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->dashboard_chartwidget, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->dashboard_chartwidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->dashboard_chartwidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	draw_chart_widget(ui, &ui->dashboard_chartwidget);
	/*********************************************
	 * CHART design end
	 * ******************************************/

	/*********************************************
	 * Parameter design start
	 * ******************************************/
	static lv_obj_t *parametercontainer;
	static lv_obj_t *prochainentertaincontainer;
	static lv_obj_t *statofbatterycontainer;
	static lv_obj_t *researchcontainer;
	static lv_obj_t *metrologiescontainer;
	static lv_obj_t *statisticreportcontainer;
	//Environment parameter container
	parametercontainer = lv_obj_create(guider_ui.dashboard_background);
	lv_obj_clear_flag(parametercontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(parametercontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(parametercontainer, ui->dashboard_chartwidget, LV_ALIGN_OUT_BOTTOM_LEFT, -15, 10);
	lv_obj_set_size(parametercontainer, SCREEN_WIDTH-20, 120);
	lv_obj_set_style_bg_color(parametercontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(parametercontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(parametercontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(parametercontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(parametercontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Draw environment parameter widget
	draw_dashboard_parameter_widget(parametercontainer, "PARAMETRE ENVIRONNEMENTAUX", &envparameter, 256, 0, ui->dashboard_envparameter_status, "LA QUALITE DE L'AIR EST BONNE");

	//temperature value
	ui->dashboard_envparameter_temperature = lv_label_create(parametercontainer);
	lv_obj_align(ui->dashboard_envparameter_temperature, LV_ALIGN_TOP_MID, -10, 30);
	lv_obj_set_style_text_align(ui->dashboard_envparameter_temperature, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_envparameter_temperature,  &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_envparameter_temperature, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->dashboard_envparameter_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->dashboard_envparameter_temperature, "23.2° C");

	//humidity value
	ui->dashboard_envparameter_humidity = lv_label_create(parametercontainer);
	lv_obj_align(ui->dashboard_envparameter_humidity, LV_ALIGN_TOP_MID, 60, 30);
	lv_obj_set_style_text_align(ui->dashboard_envparameter_humidity, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_envparameter_humidity,  &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_envparameter_humidity, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->dashboard_envparameter_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->dashboard_envparameter_humidity, "34 %");

	//pressure value
	ui->dashboard_envparameter_pressure = lv_label_create(parametercontainer);
	lv_obj_align(ui->dashboard_envparameter_pressure, LV_ALIGN_TOP_MID, 15, 60);
	lv_obj_set_style_text_align(ui->dashboard_envparameter_pressure, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_envparameter_pressure,  &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_envparameter_pressure, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->dashboard_envparameter_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->dashboard_envparameter_pressure, "1013.24 HPA");

	//Prochain entertain container
	prochainentertaincontainer = lv_obj_create(guider_ui.dashboard_background);
	lv_obj_clear_flag(prochainentertaincontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(prochainentertaincontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(prochainentertaincontainer, parametercontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_size(prochainentertaincontainer, SCREEN_WIDTH-20, 120);
	lv_obj_set_style_bg_color(prochainentertaincontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(prochainentertaincontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(prochainentertaincontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(prochainentertaincontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(prochainentertaincontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//draw widget for prochain
	draw_dashboard_parameter_widget(prochainentertaincontainer, "PROCHAIN ENTRETIENT", &service_icon, 300, 0, ui->dashboard_prochain_status	, "L'ENTRETIENT EST A JOUR");

	//parameter for prochain
	ui->dashboard_prochain_status_filter = lv_label_create(prochainentertaincontainer);
	lv_obj_align(ui->dashboard_prochain_status_filter, LV_ALIGN_TOP_MID, 15, 40);
	lv_obj_set_style_text_align(ui->dashboard_prochain_status_filter, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_prochain_status_filter,  &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_prochain_status_filter, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->dashboard_prochain_status_filter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->dashboard_prochain_status_filter, "17 JUILLET 2020\nPRE-FILTRE 20%");

	//Status of battery container
	statofbatterycontainer = lv_obj_create(guider_ui.dashboard_background);
	lv_obj_clear_flag(statofbatterycontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(statofbatterycontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(statofbatterycontainer, prochainentertaincontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_size(statofbatterycontainer, SCREEN_WIDTH-20, 120);
	lv_obj_set_style_bg_color(statofbatterycontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(statofbatterycontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(statofbatterycontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(statofbatterycontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(statofbatterycontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//draw battery widget
	draw_dashboard_parameter_widget(statofbatterycontainer, "ETATS DE LA BATTERIE", &battery_icon, 256, 0, ui->dashboard_statofbattery_status	, "DEVRAIS FINIR LE TRAVAIL");

	//label for parameter
	ui->dashboard_statofbattery_parameter = lv_label_create(statofbatterycontainer);
	lv_obj_align(ui->dashboard_statofbattery_parameter, LV_ALIGN_TOP_MID, 15, 25);
	lv_obj_set_style_text_align(ui->dashboard_statofbattery_parameter, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_statofbattery_parameter,  &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_statofbattery_parameter, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->dashboard_statofbattery_parameter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->dashboard_statofbattery_parameter, "84%\n134,8 WH\n12.6 VOLT  0,127 MA");


	//reseau container
	researchcontainer = lv_obj_create(guider_ui.dashboard_background);
	lv_obj_clear_flag(researchcontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(researchcontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(researchcontainer, statofbatterycontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_size(researchcontainer, SCREEN_WIDTH-20, 120);
	lv_obj_set_style_bg_color(researchcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(researchcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(researchcontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(researchcontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(researchcontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Draw widget
	draw_dashboard_parameter_widget(researchcontainer, "RESEAU", &research_icon, 256, 0, ui->dashboard_reserach_status, "PAS DE MODULE GSM");

	//label for parameter
	ui->dashboard_reserach_status_parameter = lv_label_create(researchcontainer);
	lv_obj_align(ui->dashboard_reserach_status_parameter, LV_ALIGN_TOP_MID, 15, 40);
	lv_obj_set_style_text_align(ui->dashboard_reserach_status_parameter, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_reserach_status_parameter,  &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_reserach_status_parameter, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->dashboard_reserach_status_parameter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->dashboard_reserach_status_parameter, "GSM NON CONNECT\nWIFI BLUETOOTH ACTIVE");

	//metrologies container
	metrologiescontainer = lv_obj_create(guider_ui.dashboard_background);
	lv_obj_clear_flag(metrologiescontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(metrologiescontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(metrologiescontainer, researchcontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_size(metrologiescontainer, SCREEN_WIDTH-20, 120);
	lv_obj_set_style_bg_color(metrologiescontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(metrologiescontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(metrologiescontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(metrologiescontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(metrologiescontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//draw metrology widget
	draw_dashboard_parameter_widget(metrologiescontainer, "Metrologies", &metrology_icon, 200, 0, ui->dashboard_metrogies_status, "A JOUR JUSQU'AU 12 JUIN 2023");
	//label for parameter
	ui->dashboard_metrologies_status_parameter = lv_label_create(metrologiescontainer);
	lv_obj_align(ui->dashboard_metrologies_status_parameter, LV_ALIGN_TOP_MID, 15, 40);
	lv_obj_set_style_text_align(ui->dashboard_metrologies_status_parameter, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_metrologies_status_parameter,  &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_metrologies_status_parameter, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->dashboard_metrologies_status_parameter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->dashboard_metrologies_status_parameter, "METROLOGIE A JOUR\nSENSOR ETALONNEE");


	//stastics container
	statisticreportcontainer = lv_obj_create(guider_ui.dashboard_background);
	lv_obj_clear_flag(statisticreportcontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(statisticreportcontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(statisticreportcontainer, metrologiescontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_size(statisticreportcontainer, SCREEN_WIDTH-20, 120);
	lv_obj_set_style_bg_color(statisticreportcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(statisticreportcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(statisticreportcontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(statisticreportcontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(statisticreportcontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//stastics widget
	draw_dashboard_parameter_widget(statisticreportcontainer, "STATISTIC ET RAPPORT", &statics, 150, 0, ui->dashboard_stastics_status, "TAUX D'UTILIZATION 30 %");

	//label for parameter
	ui->dashboard_stastics_status_parameter = lv_label_create(statisticreportcontainer);
	lv_obj_align(ui->dashboard_stastics_status_parameter, LV_ALIGN_TOP_MID, 15, 40);
	lv_obj_set_style_text_align(ui->dashboard_stastics_status_parameter, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->dashboard_stastics_status_parameter,  &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->dashboard_stastics_status_parameter, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->dashboard_stastics_status_parameter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->dashboard_stastics_status_parameter, "PAS D'ALARTE\n98% DE REUSSITE");

	/*********************************************
	 * Parameter design end
	 * ******************************************/
	/****************************************Events Initialization************************************/
	events_init_dashboard(ui);
}


/***********************************************************************************************************************
 * End of file
 ***********************************************************************************************************************/
