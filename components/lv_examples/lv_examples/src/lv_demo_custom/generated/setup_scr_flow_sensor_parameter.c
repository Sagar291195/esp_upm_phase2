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
static void draw_point_container(lv_obj_t *parent, uint8_t Num);
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


static void draw_point_container(lv_obj_t *parent, uint8_t Num)
{
    static lv_obj_t *labelPointNum;
    static lv_obj_t *labelPointFactoryVal;
    static lv_obj_t *labelPointCompVal;
    static lv_obj_t *labelPointAccuracy;

    //Point title label
    labelPointNum = lv_label_create(parent);
    lv_obj_align(labelPointNum, LV_ALIGN_TOP_LEFT, 5, 10);
    lv_label_set_text_fmt(labelPointNum, "POINT %d", Num+1);
    lv_obj_set_style_pad_all(labelPointNum, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_text_font (labelPointNum, &lv_font_montserrat_14_regular, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(labelPointNum, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);

    //Factory value label
    labelPointFactoryVal = lv_label_create(parent);
    lv_obj_set_width(labelPointFactoryVal, 150);
    lv_obj_align_to(labelPointFactoryVal, labelPointNum, LV_ALIGN_OUT_BOTTOM_LEFT, 5, 20);
    lv_obj_set_style_pad_all(labelPointFactoryVal, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_text_font (labelPointFactoryVal, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(labelPointFactoryVal, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
    lv_label_set_text(labelPointFactoryVal, "Factory Value");

    //Factory value  value
    guider_ui.flow_sensor_par_cont_point_factory_val[Num] = lv_label_create(parent);
    lv_obj_align_to(guider_ui.flow_sensor_par_cont_point_factory_val[Num], labelPointFactoryVal, LV_ALIGN_OUT_RIGHT_MID, 60, 0);
    lv_obj_set_style_text_font (guider_ui.flow_sensor_par_cont_point_factory_val[Num], &lv_font_montserrat_16_regular, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(guider_ui.flow_sensor_par_cont_point_factory_val[Num], ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(guider_ui.flow_sensor_par_cont_point_factory_val[Num], 0, LV_STATE_DEFAULT);
    lv_label_set_text(guider_ui.flow_sensor_par_cont_point_factory_val[Num], "2236");

    //Compensated value label
    labelPointCompVal = lv_label_create(parent);
    lv_obj_set_width(labelPointCompVal, 150);
    lv_obj_align_to(labelPointCompVal, labelPointFactoryVal, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
    lv_obj_set_style_text_font (labelPointCompVal, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(labelPointCompVal, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(labelPointCompVal, 0, LV_STATE_DEFAULT);
    lv_label_set_text(labelPointCompVal, "Compensated Value");

    //compansetaded value value
    guider_ui.flow_sensor_par_cont_point_comp_val[Num] = lv_label_create(parent);
    lv_obj_align_to(guider_ui.flow_sensor_par_cont_point_comp_val[Num], labelPointCompVal, LV_ALIGN_OUT_RIGHT_MID, 60, 0);
    lv_obj_set_style_text_font (guider_ui.flow_sensor_par_cont_point_comp_val[Num], &lv_font_montserrat_16_regular, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(guider_ui.flow_sensor_par_cont_point_comp_val[Num], ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(guider_ui.flow_sensor_par_cont_point_comp_val[Num], 0, LV_STATE_DEFAULT);
    lv_label_set_text(guider_ui.flow_sensor_par_cont_point_comp_val[Num], "2235");

    //Accuracy label
    labelPointAccuracy = lv_label_create(parent);
    lv_obj_set_width(labelPointAccuracy, 150);
    lv_obj_align_to(labelPointAccuracy, labelPointCompVal, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
    lv_obj_set_style_text_font (labelPointAccuracy, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(labelPointAccuracy, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(labelPointAccuracy, 0, LV_STATE_DEFAULT);
    lv_label_set_text(labelPointAccuracy, "Accuracy");

    //Accuracy value label
    guider_ui.flow_sensor_par_cont_point_accuracy[Num] = lv_label_create(parent);
    lv_obj_align_to(guider_ui.flow_sensor_par_cont_point_accuracy[Num], labelPointAccuracy, LV_ALIGN_OUT_RIGHT_MID, 60, 0);
    lv_obj_set_style_text_font (guider_ui.flow_sensor_par_cont_point_accuracy[Num], &lv_font_montserrat_16_regular, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(guider_ui.flow_sensor_par_cont_point_accuracy[Num], ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(guider_ui.flow_sensor_par_cont_point_accuracy[Num], 0, LV_STATE_DEFAULT);
    lv_label_set_text(guider_ui.flow_sensor_par_cont_point_accuracy[Num], "10.6%");

    //Status symbol
    guider_ui.flow_sensor_par_cont_point_ok_icon[Num] = lv_img_create(parent);
    lv_img_set_src(guider_ui.flow_sensor_par_cont_point_ok_icon[Num], &ok_icon);
    lv_img_set_zoom(guider_ui.flow_sensor_par_cont_point_ok_icon[Num], 200);
    lv_obj_align(guider_ui.flow_sensor_par_cont_point_ok_icon[Num], LV_ALIGN_TOP_RIGHT, -10, 5);
}

void setup_scr_flow_sensor_parameter(lv_ui *ui){

	//Flow sensor parameter main object
	ui->flow_sensor_par = lv_obj_create(NULL);
	static lv_style_t style_flow_sensor_par_main_default;
	lv_style_reset(&style_flow_sensor_par_main_default);
	lv_style_set_bg_color(&style_flow_sensor_par_main_default, ESPUPM_COLOR_WHITE);
	lv_style_set_bg_opa(&style_flow_sensor_par_main_default, 0);
	lv_obj_add_style(ui->flow_sensor_par, &style_flow_sensor_par_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Flow sensor screen background
	ui->flow_sensor_par_background = lv_obj_create(ui->flow_sensor_par);
	lv_obj_set_align(ui->flow_sensor_par_background, LV_ALIGN_CENTER);
	lv_obj_set_size(ui->flow_sensor_par_background, SCREEN_WIDTH, SCREEN_HEIGHT);
	lv_obj_set_scrollbar_mode(ui->flow_sensor_par_background, LV_SCROLLBAR_MODE_OFF);
	//Write style state: LV_STATE_DEFAULT for style_flow_sensor_par_cont_main_default
	static lv_style_t style_flow_sensor_par_cont_main_default;
	lv_style_reset(&style_flow_sensor_par_cont_main_default);
	lv_style_set_radius(&style_flow_sensor_par_cont_main_default, 0);
	lv_style_set_bg_color(&style_flow_sensor_par_cont_main_default, ESPUPM_COLOR_BLUE);
	lv_style_set_bg_grad_color(&style_flow_sensor_par_cont_main_default, ESPUPM_COLOR_BLUE);
	lv_style_set_bg_grad_dir(&style_flow_sensor_par_cont_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_flow_sensor_par_cont_main_default, SCREEN_MAX_OPACITY);
	lv_style_set_border_color(&style_flow_sensor_par_cont_main_default, ESPUPM_COLOR_BLUE);
	lv_style_set_border_width(&style_flow_sensor_par_cont_main_default, 0);
	lv_style_set_border_opa(&style_flow_sensor_par_cont_main_default, SCREEN_MAX_OPACITY);
	lv_style_set_pad_left(&style_flow_sensor_par_cont_main_default, 0);
	lv_style_set_pad_right(&style_flow_sensor_par_cont_main_default, 0);
	lv_style_set_pad_top(&style_flow_sensor_par_cont_main_default, 0);
	lv_style_set_pad_bottom(&style_flow_sensor_par_cont_main_default, 0);
	lv_obj_add_style(ui->flow_sensor_par_background, &style_flow_sensor_par_cont_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Header draw for battery, wifi and signal
	setup_draw_header(ui, ui->flow_sensor_par_background);

	//flow sensor Screen object for left arrow, parameter text and menu symbol
	setup_draw_title(ui, ui->flow_sensor_par_background, "Flow Sensor Parameter", &fan_icon, ESPUPM_COLOR_BLUE);

	/********************************************************
	 * container to display parameters start
	 ********************************************************/
	//Container for data parameter display
	ui->flow_sensor_par_cont_data = lv_obj_create(ui->flow_sensor_par_background);
	lv_obj_align_to(ui->flow_sensor_par_cont_data, ui->title_container, LV_ALIGN_OUT_BOTTOM_LEFT, 10 ,10);
	lv_obj_set_size(ui->flow_sensor_par_cont_data, (SCREEN_WIDTH-20), 350);
	static lv_style_t style_flow_sensor_par_cont_data_default;
	lv_style_reset(&style_flow_sensor_par_cont_data_default);
	lv_style_set_radius(&style_flow_sensor_par_cont_data_default, 5);
	lv_style_set_bg_color(&style_flow_sensor_par_cont_data_default, ESPUPM_COLOR_DARK_GREY);
	lv_style_set_border_width(&style_flow_sensor_par_cont_data_default, 0);
	lv_style_set_border_opa(&style_flow_sensor_par_cont_data_default, LV_OPA_100);
	lv_style_set_pad_left(&style_flow_sensor_par_cont_data_default, 0);
	lv_style_set_pad_right(&style_flow_sensor_par_cont_data_default, 0);
	lv_style_set_pad_top(&style_flow_sensor_par_cont_data_default, 0);
	lv_style_set_pad_bottom(&style_flow_sensor_par_cont_data_default, 0);
	lv_obj_add_style(ui->flow_sensor_par_cont_data, &style_flow_sensor_par_cont_data_default, LV_PART_MAIN|LV_STATE_DEFAULT);


    //inner container data
    static lv_obj_t *startLabel;
    // Create Label for Start  text
    startLabel = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_align(startLabel, LV_ALIGN_TOP_LEFT, 5, 20);
    lv_label_set_text(startLabel, "DATE:");
    lv_obj_set_style_pad_all(startLabel, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_text_font (startLabel, &lv_font_montserrat_13_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(startLabel, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);

    // Create Label for start Date
    ui->flow_sensor_par_startdate_value = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_align(ui->flow_sensor_par_startdate_value, LV_ALIGN_TOP_LEFT, 5, 40);
    lv_label_set_text(ui->flow_sensor_par_startdate_value, "23/12/2021");
    lv_obj_set_style_pad_all(ui->flow_sensor_par_startdate_value, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_text_font (ui->flow_sensor_par_startdate_value, &lv_font_montserrat_22_semibold, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->flow_sensor_par_startdate_value, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);

    // Create Label for start Date
    ui->flow_sensor_par_duration_value = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_align( ui->flow_sensor_par_duration_value , LV_ALIGN_TOP_LEFT, 65, 65);
    lv_label_set_text( ui->flow_sensor_par_duration_value , "15H39M");
    lv_obj_set_style_pad_all( ui->flow_sensor_par_duration_value , 0, LV_STATE_DEFAULT);
    lv_obj_set_style_text_font ( ui->flow_sensor_par_duration_value , &lv_font_montserrat_14_bold, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color( ui->flow_sensor_par_duration_value , ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);

    static lv_obj_t *pointNumLabel;
    static lv_obj_t *globalAccuracyLabel;
    static lv_obj_t *hourCounterLabel;
    static lv_obj_t *volumeCounterLabel;
    static lv_obj_t *curveLabel;
    static lv_obj_t *unitLabel;
    static lv_obj_t *higherLimitLabel;
    static lv_obj_t *limitAlertLabel;
    static lv_obj_t *lowerLimitLabel;
    static lv_obj_t *afterLimitAlertLabel;
    //Point Number label
    pointNumLabel = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_align_to(pointNumLabel, ui->flow_sensor_par_cont_data, LV_ALIGN_TOP_LEFT, 5, 100);
    lv_label_set_text(pointNumLabel, "POINT NUMBER:");
    lv_obj_set_style_text_font (pointNumLabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
    lv_obj_set_style_text_align (pointNumLabel, LV_TEXT_ALIGN_LEFT, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(pointNumLabel, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(pointNumLabel, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
    //point number value
    ui->flow_sensor_par_label_point_number = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_set_width(ui->flow_sensor_par_label_point_number, 130);
    lv_obj_align_to(ui->flow_sensor_par_label_point_number, pointNumLabel, LV_ALIGN_OUT_RIGHT_MID, 35, 0);
    lv_obj_set_style_text_align (ui->flow_sensor_par_label_point_number, LV_TEXT_ALIGN_RIGHT, LV_STATE_DEFAULT);
    lv_obj_set_style_text_font (ui->flow_sensor_par_label_point_number, &lv_font_montserrat_14_regular, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->flow_sensor_par_label_point_number, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
    lv_label_set_text(ui->flow_sensor_par_label_point_number, "02");

    //Global Accuracy label
    globalAccuracyLabel = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_align_to(globalAccuracyLabel, pointNumLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
    lv_obj_set_style_text_font (globalAccuracyLabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
    lv_obj_set_style_text_align (pointNumLabel, LV_TEXT_ALIGN_LEFT, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(pointNumLabel, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(globalAccuracyLabel, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
    lv_label_set_text(globalAccuracyLabel, "GLOBAL ACCURACY:");
    //Global accuracy value
    ui->flow_sensor_par_label_global_accuracy = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_set_width(ui->flow_sensor_par_label_global_accuracy, 130);
    lv_obj_align_to(ui->flow_sensor_par_label_global_accuracy, ui->flow_sensor_par_label_point_number, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 8);
    lv_obj_set_style_text_align (ui->flow_sensor_par_label_global_accuracy, LV_TEXT_ALIGN_RIGHT, LV_STATE_DEFAULT);
    lv_obj_set_style_text_font (ui->flow_sensor_par_label_global_accuracy, &lv_font_montserrat_14_regular, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->flow_sensor_par_label_global_accuracy, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->flow_sensor_par_label_global_accuracy, 0, LV_STATE_DEFAULT);
    lv_label_set_text(ui->flow_sensor_par_label_global_accuracy, "20.9%");

	//Hour Counter Label
    hourCounterLabel = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_align_to(hourCounterLabel, globalAccuracyLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
    lv_obj_set_style_text_align (pointNumLabel, LV_TEXT_ALIGN_LEFT, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(pointNumLabel, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_text_font (hourCounterLabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(hourCounterLabel, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
    lv_label_set_text(hourCounterLabel, "HOUR COUNTER:");
    //hour counter value
    ui->flow_sensor_par_label_hour_counter = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_set_width(ui->flow_sensor_par_label_hour_counter, 130);
    lv_obj_align_to(ui->flow_sensor_par_label_hour_counter, ui->flow_sensor_par_label_global_accuracy, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 8);
    lv_obj_set_style_text_align (ui->flow_sensor_par_label_hour_counter, LV_TEXT_ALIGN_RIGHT, LV_STATE_DEFAULT);
    lv_obj_set_style_text_font (ui->flow_sensor_par_label_hour_counter, &lv_font_montserrat_14_regular, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->flow_sensor_par_label_hour_counter, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->flow_sensor_par_label_hour_counter, 0, LV_STATE_DEFAULT);
    lv_label_set_text(ui->flow_sensor_par_label_hour_counter, "56677 H");

    //Volume Counter Label
    volumeCounterLabel = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_align_to(volumeCounterLabel, hourCounterLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_text_align (volumeCounterLabel, LV_TEXT_ALIGN_LEFT, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(volumeCounterLabel, 0, LV_STATE_DEFAULT);
	lv_obj_set_style_text_font (volumeCounterLabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(volumeCounterLabel, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
	lv_label_set_text(volumeCounterLabel, "VOLUME COUNTER:");
	//volume counter value
    ui->flow_sensor_par_label_volume_counter = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_set_width(ui->flow_sensor_par_label_volume_counter, 130);
    lv_obj_align_to(ui->flow_sensor_par_label_volume_counter, ui->flow_sensor_par_label_hour_counter, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 8);
    lv_obj_set_style_text_align (ui->flow_sensor_par_label_volume_counter, LV_TEXT_ALIGN_RIGHT, LV_STATE_DEFAULT);
    lv_obj_set_style_text_font (ui->flow_sensor_par_label_volume_counter, &lv_font_montserrat_14_regular, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->flow_sensor_par_label_volume_counter, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->flow_sensor_par_label_volume_counter, 0, LV_STATE_DEFAULT);
    lv_label_set_text(ui->flow_sensor_par_label_volume_counter, "234567 H");

    //Curve Label
    curveLabel = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_align_to(curveLabel, volumeCounterLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
   	lv_obj_set_style_text_align (curveLabel, LV_TEXT_ALIGN_LEFT, LV_STATE_DEFAULT);
   	lv_obj_set_style_pad_all(curveLabel, 0, LV_STATE_DEFAULT);
   	lv_obj_set_style_text_font (curveLabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
   	lv_obj_set_style_text_color(curveLabel, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
   	lv_label_set_text(curveLabel, "CURVE:");
   	//curve value
    ui->flow_sensor_par_label_curve = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_set_width(ui->flow_sensor_par_label_curve, 130);
	lv_obj_align_to(ui->flow_sensor_par_label_curve, ui->flow_sensor_par_label_volume_counter, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 7);
	lv_obj_set_style_text_align (ui->flow_sensor_par_label_curve, LV_TEXT_ALIGN_RIGHT, LV_STATE_DEFAULT);
	lv_obj_set_style_text_font (ui->flow_sensor_par_label_curve, &lv_font_montserrat_14_regular, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->flow_sensor_par_label_curve, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->flow_sensor_par_label_curve, 0, LV_STATE_DEFAULT);
	lv_label_set_text(ui->flow_sensor_par_label_curve, "LINEAR 3");

    //Unit Label
    unitLabel = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_align_to(unitLabel, curveLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_text_align (unitLabel, LV_TEXT_ALIGN_LEFT, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(unitLabel, 0, LV_STATE_DEFAULT);
	lv_obj_set_style_text_font (unitLabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(unitLabel, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
	lv_label_set_text(unitLabel, "UNIT:");
	//unit value
    ui->flow_sensor_par_label_unit = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_set_width(ui->flow_sensor_par_label_unit, 130);
	lv_obj_align_to(ui->flow_sensor_par_label_unit, ui->flow_sensor_par_label_curve, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 8);
	lv_obj_set_style_text_align (ui->flow_sensor_par_label_unit, LV_TEXT_ALIGN_RIGHT, LV_STATE_DEFAULT);
	lv_obj_set_style_text_font (ui->flow_sensor_par_label_unit, &lv_font_montserrat_14_regular, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->flow_sensor_par_label_unit, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->flow_sensor_par_label_unit, 0, LV_STATE_DEFAULT);
	lv_label_set_text(ui->flow_sensor_par_label_unit, "JACK");

    //Lower Limit Label
    lowerLimitLabel = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_align_to(lowerLimitLabel, unitLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
   	lv_obj_set_style_text_align (lowerLimitLabel, LV_TEXT_ALIGN_LEFT, LV_STATE_DEFAULT);
   	lv_obj_set_style_pad_all(lowerLimitLabel, 0, LV_STATE_DEFAULT);
   	lv_obj_set_style_text_font (lowerLimitLabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
   	lv_obj_set_style_text_color(lowerLimitLabel, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
   	lv_label_set_text(lowerLimitLabel, "LOWER LIMIT:");
   	//lower limit value
    ui->flow_sensor_par_label_lower_limit = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_set_width(ui->flow_sensor_par_label_lower_limit, 130);
   	lv_obj_align_to(ui->flow_sensor_par_label_lower_limit, ui->flow_sensor_par_label_unit, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 8);
   	lv_obj_set_style_text_align (ui->flow_sensor_par_label_lower_limit, LV_TEXT_ALIGN_RIGHT, LV_STATE_DEFAULT);
   	lv_obj_set_style_text_font (ui->flow_sensor_par_label_lower_limit, &lv_font_montserrat_14_regular, LV_STATE_DEFAULT);
   	lv_obj_set_style_text_color(ui->flow_sensor_par_label_lower_limit, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
   	lv_obj_set_style_pad_all(ui->flow_sensor_par_label_lower_limit, 0, LV_STATE_DEFAULT);
   	lv_label_set_text(ui->flow_sensor_par_label_lower_limit, "NONE");

	//Higher Limit Label
    higherLimitLabel = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_align_to(higherLimitLabel, lowerLimitLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_text_align (higherLimitLabel, LV_TEXT_ALIGN_LEFT, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(higherLimitLabel, 0, LV_STATE_DEFAULT);
	lv_obj_set_style_text_font (higherLimitLabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(higherLimitLabel, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
	lv_label_set_text(higherLimitLabel, "HIGHER LIMIT:");
	//Higher limit value
    ui->flow_sensor_par_label_higher_limit = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_set_width(ui->flow_sensor_par_label_higher_limit, 130);
	lv_obj_align_to(ui->flow_sensor_par_label_higher_limit, ui->flow_sensor_par_label_lower_limit, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 8);
	lv_obj_set_style_text_align (ui->flow_sensor_par_label_higher_limit, LV_TEXT_ALIGN_RIGHT, LV_STATE_DEFAULT);
	lv_obj_set_style_text_font (ui->flow_sensor_par_label_higher_limit, &lv_font_montserrat_14_regular, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->flow_sensor_par_label_higher_limit, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->flow_sensor_par_label_higher_limit, 0, LV_STATE_DEFAULT);
	lv_label_set_text(ui->flow_sensor_par_label_higher_limit, "NONE");

    //Limit Alert Label
    limitAlertLabel = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_align_to(limitAlertLabel, higherLimitLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_text_align (limitAlertLabel, LV_TEXT_ALIGN_LEFT, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(limitAlertLabel, 0, LV_STATE_DEFAULT);
	lv_obj_set_style_text_font (limitAlertLabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(limitAlertLabel, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
	lv_label_set_text(limitAlertLabel, "LIMIT ALERT:");
	//Limit Alert value
    ui->flow_sensor_par_label_limit_alert = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_set_width(ui->flow_sensor_par_label_limit_alert, 130);
	lv_obj_align_to(ui->flow_sensor_par_label_limit_alert, ui->flow_sensor_par_label_higher_limit, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 8);
	lv_obj_set_style_text_align (ui->flow_sensor_par_label_limit_alert, LV_TEXT_ALIGN_RIGHT, LV_STATE_DEFAULT);
	lv_obj_set_style_text_font (ui->flow_sensor_par_label_limit_alert, &lv_font_montserrat_14_regular, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->flow_sensor_par_label_limit_alert, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->flow_sensor_par_label_limit_alert, 0, LV_STATE_DEFAULT);
	lv_label_set_text(ui->flow_sensor_par_label_limit_alert, "-10 to +10%");

    //After Limit Alert Label
    afterLimitAlertLabel = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_align_to(afterLimitAlertLabel, limitAlertLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
   	lv_obj_set_style_text_align (afterLimitAlertLabel, LV_TEXT_ALIGN_LEFT, LV_STATE_DEFAULT);
   	lv_obj_set_style_pad_all(afterLimitAlertLabel, 0, LV_STATE_DEFAULT);
   	lv_obj_set_style_text_font (afterLimitAlertLabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
   	lv_obj_set_style_text_color(afterLimitAlertLabel, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
   	lv_label_set_text(afterLimitAlertLabel, "AFTER LIMIT ALERT:");
   	//After Limit Alert value
    ui->flow_sensor_par_label_after_limit_alert = lv_label_create(ui->flow_sensor_par_cont_data);
    lv_obj_set_width(ui->flow_sensor_par_label_after_limit_alert, 130);
	lv_obj_align_to(ui->flow_sensor_par_label_after_limit_alert, ui->flow_sensor_par_label_limit_alert, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 8);
	lv_obj_set_style_text_align (ui->flow_sensor_par_label_after_limit_alert, LV_TEXT_ALIGN_RIGHT, LV_STATE_DEFAULT);
	lv_obj_set_style_text_font (ui->flow_sensor_par_label_after_limit_alert, &lv_font_montserrat_14_regular, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->flow_sensor_par_label_after_limit_alert, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->flow_sensor_par_label_after_limit_alert, 0, LV_STATE_DEFAULT);
	lv_label_set_text(ui->flow_sensor_par_label_after_limit_alert, "ENABLE");
	/********************************************************
	 * container to display parameters end
	 ********************************************************/

	/********************************************************
	 * container to display points start
	 ********************************************************/
    //Create Point Container and its style
    //Write style state: LV_STATE_DEFAULT for style_flow_sensor_par_point_cont
	static lv_style_t style_flow_sensor_par_point_cont;
	lv_style_reset(&style_flow_sensor_par_point_cont);
	lv_style_set_radius(&style_flow_sensor_par_point_cont, 5);
	lv_style_set_bg_color(&style_flow_sensor_par_point_cont, ESPUPM_COLOR_DARK_GREY);
	lv_style_set_border_width(&style_flow_sensor_par_point_cont, 0);
	lv_style_set_border_opa(&style_flow_sensor_par_point_cont, LV_OPA_100);
	lv_style_set_pad_left(&style_flow_sensor_par_point_cont, 0);
	lv_style_set_pad_right(&style_flow_sensor_par_point_cont, 0);
	lv_style_set_pad_top(&style_flow_sensor_par_point_cont, 0);
	lv_style_set_pad_bottom(&style_flow_sensor_par_point_cont, 0);

	static lv_obj_t *pointcontainer1;
	static lv_obj_t *pointcontainer2;
	static lv_obj_t *pointcontainer3;
	static lv_obj_t *pointcontainer4;
	pointcontainer1 = lv_obj_create(ui->flow_sensor_par_background);
	lv_obj_align_to(pointcontainer1, ui->flow_sensor_par_cont_data, LV_ALIGN_OUT_BOTTOM_LEFT,  0, 10);
	lv_obj_set_size(pointcontainer1, 300, 130);
	lv_obj_add_style(pointcontainer1, &style_flow_sensor_par_point_cont, LV_PART_MAIN|LV_STATE_DEFAULT);

	pointcontainer2 = lv_obj_create(ui->flow_sensor_par_background);
	lv_obj_align_to(pointcontainer2, pointcontainer1, LV_ALIGN_OUT_BOTTOM_LEFT,  0, 10);
	lv_obj_set_size(pointcontainer2, 300, 120);
	lv_obj_add_style(pointcontainer2, &style_flow_sensor_par_point_cont, LV_PART_MAIN|LV_STATE_DEFAULT);

	pointcontainer3 = lv_obj_create(ui->flow_sensor_par_background);
	lv_obj_align_to(pointcontainer3, pointcontainer2, LV_ALIGN_OUT_BOTTOM_LEFT,  0, 10);
	lv_obj_set_size(pointcontainer3, 300, 120);
	lv_obj_add_style(pointcontainer3, &style_flow_sensor_par_point_cont, LV_PART_MAIN|LV_STATE_DEFAULT);

	pointcontainer4 = lv_obj_create(ui->flow_sensor_par_background);
	lv_obj_align_to(pointcontainer4, pointcontainer3, LV_ALIGN_OUT_BOTTOM_LEFT,  0, 10);
	lv_obj_set_size(pointcontainer4, 300, 120);
	lv_obj_add_style(pointcontainer4, &style_flow_sensor_par_point_cont, LV_PART_MAIN|LV_STATE_DEFAULT);

	draw_point_container(pointcontainer1, 0);
	draw_point_container(pointcontainer2, 1);
	draw_point_container(pointcontainer3, 2);
	draw_point_container(pointcontainer4, 3);

	/********************************************************
	 * container to display points end
	 ********************************************************/


	/********************************************************
	 * container to chart start
	 ********************************************************/
    ui->flow_sensor_par_cont_chart = lv_obj_create(ui->flow_sensor_par_background);
	lv_obj_align_to(ui->flow_sensor_par_cont_chart, pointcontainer4, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_size(ui->flow_sensor_par_cont_chart, 300, 330);
	lv_obj_add_style(ui->flow_sensor_par_cont_chart, &style_flow_sensor_par_point_cont, LV_PART_MAIN|LV_STATE_DEFAULT);

    static lv_obj_t *labelCalibratedVsFactoryVal;
    static lv_obj_t *equationlabel;
	static lv_obj_t *regressionfactorlabel;
    labelCalibratedVsFactoryVal = lv_label_create(ui->flow_sensor_par_cont_chart);
    lv_obj_align(labelCalibratedVsFactoryVal, LV_ALIGN_TOP_MID, 0, 10);
    lv_obj_set_style_pad_all(labelCalibratedVsFactoryVal, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_text_align (labelCalibratedVsFactoryVal, LV_TEXT_ALIGN_LEFT, LV_STATE_DEFAULT);
    lv_obj_set_style_text_font (labelCalibratedVsFactoryVal, &lv_font_montserrat_16, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(labelCalibratedVsFactoryVal, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
    lv_label_set_text(labelCalibratedVsFactoryVal, "FACTORY VS COMPENSATE");

    ui->flow_sensor_par_chart = lv_chart_create(ui->flow_sensor_par_cont_chart);
    lv_obj_set_size(ui->flow_sensor_par_chart, 300, 300);
    lv_obj_align(ui->flow_sensor_par_chart, LV_ALIGN_TOP_MID, 0, 30);
    lv_obj_set_style_bg_color(ui->flow_sensor_par_chart, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->flow_sensor_par_chart, LV_OPA_0, LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->flow_sensor_par_chart, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->flow_sensor_par_chart, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->flow_sensor_par_chart, 0, LV_STATE_DEFAULT);
    lv_chart_set_div_line_count(ui->flow_sensor_par_chart, 0, 0);
    lv_chart_set_type(ui->flow_sensor_par_chart, LV_CHART_TYPE_LINE);
    lv_obj_add_event_cb(ui->flow_sensor_par_chart, draw_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);
    lv_chart_set_update_mode(ui->flow_sensor_par_chart, LV_CHART_UPDATE_MODE_SHIFT);

    ui->flow_sensor_par_ser = lv_chart_add_series(ui->flow_sensor_par_chart, lv_palette_main(LV_PALETTE_BLUE), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_set_point_count(ui->flow_sensor_par_chart, 60);
	for(uint8_t i = 0; i < 60; i++) {
	  lv_chart_set_next_value(ui->flow_sensor_par_chart, ui->flow_sensor_par_ser , lv_rand(20, 90));
	}

	equationlabel = lv_label_create(ui->flow_sensor_par_cont_chart);
    lv_obj_align(equationlabel, LV_ALIGN_BOTTOM_LEFT, 5, -50);
    lv_obj_set_style_pad_all(equationlabel, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_text_align (equationlabel, LV_TEXT_ALIGN_LEFT, LV_STATE_DEFAULT);
    lv_obj_set_style_text_font (equationlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(equationlabel, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
    lv_label_set_text(equationlabel, "EQUATION");

    ui->flow_sensor_equationvalue = lv_label_create(ui->flow_sensor_par_cont_chart);
	lv_obj_align_to(ui->flow_sensor_equationvalue, equationlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
	lv_obj_set_style_pad_all(ui->flow_sensor_equationvalue, 0, LV_STATE_DEFAULT);
	lv_obj_set_style_text_align (ui->flow_sensor_equationvalue, LV_TEXT_ALIGN_LEFT, LV_STATE_DEFAULT);
	lv_obj_set_style_text_font (ui->flow_sensor_equationvalue, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->flow_sensor_equationvalue, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_label_set_text(ui->flow_sensor_equationvalue, "2234X2 +34,456 X + 46,538");

	regressionfactorlabel = lv_label_create(ui->flow_sensor_par_cont_chart);
	lv_obj_align_to(regressionfactorlabel, ui->flow_sensor_equationvalue, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
	lv_obj_set_style_pad_all(regressionfactorlabel, 0, LV_STATE_DEFAULT);
	lv_obj_set_style_text_align (regressionfactorlabel, LV_TEXT_ALIGN_LEFT, LV_STATE_DEFAULT);
	lv_obj_set_style_text_font (regressionfactorlabel, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(regressionfactorlabel, ESPUPM_COLOR_BLUE, LV_STATE_DEFAULT);
	lv_label_set_text(regressionfactorlabel, "REGRESSION FACTOR");

	ui->flow_sensor_regression_factorvalue = lv_label_create(ui->flow_sensor_par_cont_chart);
	lv_obj_align_to(ui->flow_sensor_regression_factorvalue, regressionfactorlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
	lv_obj_set_style_pad_all(ui->flow_sensor_regression_factorvalue, 0, LV_STATE_DEFAULT);
	lv_obj_set_style_text_align (ui->flow_sensor_regression_factorvalue, LV_TEXT_ALIGN_LEFT, LV_STATE_DEFAULT);
	lv_obj_set_style_text_font (ui->flow_sensor_regression_factorvalue, &lv_font_montserrat_13_semibold, LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->flow_sensor_regression_factorvalue, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
	lv_label_set_text(ui->flow_sensor_regression_factorvalue, "0,98764253");

	/********************************************************
	 * container to chart end
	 ********************************************************/

	//create button and its style
	static lv_style_t style_btn_valid;
	lv_style_reset(&style_btn_valid);
	lv_style_set_radius(&style_btn_valid, 3);
	lv_style_set_border_color(&style_btn_valid, lv_color_make(0xeb, 0x3b, 0x5a));
	lv_style_set_border_width(&style_btn_valid, 0);
	lv_style_set_border_opa(&style_btn_valid, 255);
	lv_style_set_shadow_width(&style_btn_valid, 0);
    lv_style_set_bg_color(&style_btn_valid, lv_color_make(0xeb, 0x3b, 0x5a));

    ui->flow_sensor_par_cont_btn_erase = lv_btn_create(ui->flow_sensor_par_background);
    lv_obj_set_size(ui->flow_sensor_par_cont_btn_erase, 300, 50);
    lv_obj_align_to(ui->flow_sensor_par_cont_btn_erase, ui->flow_sensor_par_cont_chart, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
    lv_obj_t *label= lv_label_create(ui->flow_sensor_par_cont_btn_erase);
    lv_obj_set_style_text_font (label, &lv_font_montserrat_16_semibold, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label, ESPUPM_COLOR_WHITE, LV_STATE_DEFAULT);
    lv_obj_add_style(ui->flow_sensor_par_cont_btn_erase, &style_btn_valid, LV_STATE_DEFAULT);
    lv_label_set_text(label, "ERASE AND START NEW");
    lv_obj_center(label);

    /**********Events Initialization****************/
    events_init_flow_sensor_parameter(ui);
}

/***********************************************************************************************************************
 * End of file
 ***********************************************************************************************************************/
