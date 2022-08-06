
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
static void mask_event_cb(lv_event_t * e);

/***********************************************************************************************************************
 * static functions
 ***********************************************************************************************************************/
static void mask_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);

    static int16_t mask_top_id = -1;
    static int16_t mask_bottom_id = -1;

    if (code == LV_EVENT_COVER_CHECK) {
        lv_event_set_cover_res(e, LV_COVER_RES_MASKED);

    } else if (code == LV_EVENT_DRAW_MAIN_BEGIN) {
        /* add mask */
        const lv_font_t * font = lv_obj_get_style_text_font(obj, LV_PART_MAIN);
        lv_coord_t line_space = lv_obj_get_style_text_line_space(obj, LV_PART_MAIN);
        lv_coord_t font_h = lv_font_get_line_height(font);

        lv_area_t roller_coords;
        lv_obj_get_coords(obj, &roller_coords);

        lv_area_t rect_area;
        rect_area.x1 = roller_coords.x1;
        rect_area.x2 = roller_coords.x2;
        rect_area.y1 = roller_coords.y1;
        rect_area.y2 = roller_coords.y1 + (lv_obj_get_height(obj) - font_h - line_space) / 2;

        lv_draw_mask_fade_param_t * fade_mask_top = lv_mem_buf_get(sizeof(lv_draw_mask_fade_param_t));
        lv_draw_mask_fade_init(fade_mask_top, &rect_area, LV_OPA_TRANSP, rect_area.y1, LV_OPA_COVER, rect_area.y2);
        mask_top_id = lv_draw_mask_add(fade_mask_top, NULL);

        rect_area.y1 = rect_area.y2 + font_h + line_space - 1;
        rect_area.y2 = roller_coords.y2;

        lv_draw_mask_fade_param_t * fade_mask_bottom =lv_mem_buf_get(sizeof(lv_draw_mask_fade_param_t));
        lv_draw_mask_fade_init(fade_mask_bottom, &rect_area, LV_OPA_COVER, rect_area.y1, LV_OPA_TRANSP, rect_area.y2);
        mask_bottom_id = lv_draw_mask_add(fade_mask_bottom, NULL);

    } else if (code == LV_EVENT_DRAW_POST_END) {
        lv_draw_mask_fade_param_t * fade_mask_top = lv_draw_mask_remove_id(mask_top_id);
        lv_draw_mask_fade_param_t * fade_mask_bottom = lv_draw_mask_remove_id(mask_bottom_id);
        lv_draw_mask_free_param(fade_mask_top);
        lv_draw_mask_free_param(fade_mask_bottom);
        lv_mem_buf_release(fade_mask_top);
        lv_mem_buf_release(fade_mask_bottom);
        mask_top_id = -1;
        mask_bottom_id = -1;
    }
}


/***********************************************************************************************************************
 * global functions
 ***********************************************************************************************************************/


/*
 * Function to draw preset sequence screen
 */
void setup_scr_preset_sequence(lv_ui *ui){

	//Preset sequence Screen main object
	ui->preset_sequence = lv_obj_create(NULL);
	static lv_style_t style_preset_sequence_default;
	if (style_preset_sequence_default.prop_cnt > 1)
		lv_style_reset(&style_preset_sequence_default);
	else
		lv_style_init(&style_preset_sequence_default);
	lv_style_set_bg_color(&style_preset_sequence_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_preset_sequence_default, SCREEN_MIN_OPACITY);
	lv_obj_add_style(ui->preset_sequence, &style_preset_sequence_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	/**************************************************************
	 *
	 * Preset Sequence Screen design Start
	 *
	 * **********************************************************/
	//preset Sequence Screen Background
	ui->preset_sequence_background = lv_obj_create(ui->preset_sequence);
	lv_obj_set_align(ui->preset_sequence_background, LV_ALIGN_CENTER);
	lv_obj_set_size(ui->preset_sequence_background, SCREEN_WIDTH, SCREEN_HEIGHT);
	lv_obj_set_scrollbar_mode(ui->preset_sequence_background, LV_SCROLLBAR_MODE_OFF);
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
	lv_obj_add_style(ui->preset_sequence_background, &style_preset_scenario_background_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Preset Sequence Screen Header
	setup_draw_header(ui, ui->preset_sequence_background);

	//preset Sequence Screen object for left arrow, parameter text and menu symbol
	setup_draw_title(ui, ui->preset_sequence_background, "SEQUENCE 1", NULL, ESPUPM_BACKGROUND_COLOR);

	lv_obj_t *calendercontainer = lv_obj_create(ui->preset_sequence_background);
	lv_obj_clear_flag(calendercontainer, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_size(calendercontainer, 300, 300);
	lv_obj_align_to(calendercontainer,ui->title_container, LV_ALIGN_OUT_BOTTOM_LEFT, 10, 10);
	lv_obj_set_style_bg_color(calendercontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(calendercontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(calendercontainer, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(calendercontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(calendercontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	ui->preset_sequence_calender = lv_calendar_create(calendercontainer);
	lv_obj_set_size(ui->preset_sequence_calender, 300, 270);
	lv_obj_align(ui->preset_sequence_calender, LV_ALIGN_CENTER, 0, 30);
   	lv_obj_set_style_bg_color(ui->preset_sequence_calender, lv_color_make(0x38, 0x38, 0x38), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->preset_sequence_calender, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->preset_sequence_calender, ESPUPM_COLOR_WHITE, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->preset_sequence_calender, 5, LV_PART_ITEMS);
	lv_obj_set_style_radius(ui->preset_sequence_calender, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->preset_sequence_calender, 0, LV_PART_ITEMS);
	lv_obj_set_style_border_width(ui->preset_sequence_calender, 0, LV_PART_MAIN);
	lv_obj_set_style_bg_color(ui->preset_sequence_calender, lv_color_make(0x70, 0x70, 0x70), LV_PART_ITEMS);
	lv_obj_set_style_bg_opa(ui->preset_sequence_calender, LV_OPA_0, LV_PART_ITEMS);
	lv_obj_set_style_bg_opa(ui->preset_sequence_calender, LV_OPA_100, LV_PART_MAIN);

    lv_calendar_header_arrow_create(ui->preset_sequence_background, ui->preset_sequence_calender, 25);
	lv_calendar_set_today_date(ui->preset_sequence_calender, 2022, 02, 23);
	lv_calendar_set_showed_date(ui->preset_sequence_calender, 2022, 04);



	/*****************************************************************
	 * Start Container Start
	 ****************************************************************/
	//Start container object
	static lv_obj_t *startcontainer;
	static lv_obj_t *startlabel;
	static lv_obj_t *timeidentifierlabel;

	startcontainer = lv_obj_create(ui->preset_sequence_background);
	lv_obj_clear_flag(startcontainer, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_size(startcontainer, 300, 80);
	lv_obj_align_to(startcontainer,ui->preset_sequence_calender, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
	lv_obj_set_style_bg_color(startcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(startcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(startcontainer, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(startcontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(startcontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Start label
	startlabel = lv_label_create(startcontainer);
	lv_obj_set_width(startlabel, 150);
	lv_obj_align(startlabel, LV_ALIGN_TOP_LEFT, 0, 10);
	lv_obj_set_style_text_font(startlabel, &lv_font_montserrat_14_bold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(startlabel, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(startlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(startlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(startlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(startlabel, "START :");

	//Selected date label
	ui->preset_sequence_dateselectedlabel = lv_label_create(startcontainer);
	lv_obj_set_width(ui->preset_sequence_dateselectedlabel, 150);
	lv_obj_align(ui->preset_sequence_dateselectedlabel, LV_ALIGN_BOTTOM_LEFT, 0, -15);
	lv_obj_set_style_text_font(ui->preset_sequence_dateselectedlabel, &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->preset_sequence_dateselectedlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->preset_sequence_dateselectedlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->preset_sequence_dateselectedlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->preset_sequence_dateselectedlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->preset_sequence_dateselectedlabel, "Wednesday\n 2 JUNE 2022");

	//Hour roller for start container
	ui->preset_sequence_starthourroller = lv_roller_create(startcontainer);
	lv_obj_align_to(ui->preset_sequence_starthourroller, startcontainer, LV_ALIGN_TOP_MID, 60, -10);
	lv_obj_set_height(ui->preset_sequence_starthourroller, 80);
	lv_obj_set_width(ui->preset_sequence_starthourroller, 40);
	lv_obj_set_style_bg_color(ui->preset_sequence_starthourroller, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->preset_sequence_starthourroller, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->preset_sequence_starthourroller, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->preset_sequence_starthourroller, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->preset_sequence_starthourroller, &lv_font_montserrat_14_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->preset_sequence_starthourroller, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->preset_sequence_starthourroller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->preset_sequence_starthourroller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->preset_sequence_starthourroller, ESPUPM_COLOR_DARK_GREY, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->preset_sequence_starthourroller, LV_OPA_100, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->preset_sequence_starthourroller, ESPUPM_BACKGROUND_COLOR, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->preset_sequence_starthourroller, &lv_font_montserrat_20_semibold, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->preset_sequence_starthourroller, LV_OPA_0, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->preset_sequence_starthourroller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->preset_sequence_starthourroller, 0, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_options(ui->preset_sequence_starthourroller,
	                        "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23",
							LV_ROLLER_MODE_NORMAL);
	lv_roller_set_visible_row_count(ui->preset_sequence_starthourroller, 3);
	lv_obj_add_event_cb(ui->preset_sequence_starthourroller, mask_event_cb, LV_EVENT_ALL, NULL);

	//":" label
	timeidentifierlabel = lv_label_create(startcontainer);
	lv_obj_set_width(timeidentifierlabel, 20);
	lv_obj_align_to(timeidentifierlabel, ui->preset_sequence_starthourroller, LV_ALIGN_RIGHT_MID, 20, 7);
	lv_obj_set_style_text_font(timeidentifierlabel, &lv_font_montserrat_14_bold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(timeidentifierlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(timeidentifierlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(timeidentifierlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(timeidentifierlabel, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(timeidentifierlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(timeidentifierlabel, ":");

	//Minute Roller for start container
	ui->preset_sequence_startminuteroller = lv_roller_create(startcontainer);
	lv_obj_align_to(ui->preset_sequence_startminuteroller, ui->preset_sequence_starthourroller, LV_ALIGN_OUT_RIGHT_TOP, 20, 0);
	lv_obj_set_height(ui->preset_sequence_startminuteroller, 80);
	lv_obj_set_width(ui->preset_sequence_startminuteroller, 40);
	lv_obj_set_style_bg_color(ui->preset_sequence_startminuteroller, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->preset_sequence_startminuteroller, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->preset_sequence_startminuteroller, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->preset_sequence_startminuteroller, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->preset_sequence_startminuteroller, &lv_font_montserrat_14_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->preset_sequence_startminuteroller, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->preset_sequence_startminuteroller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->preset_sequence_startminuteroller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	lv_obj_set_style_text_font(ui->preset_sequence_startminuteroller, &lv_font_montserrat_20_semibold, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->preset_sequence_startminuteroller, ESPUPM_COLOR_DARK_GREY, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->preset_sequence_startminuteroller, LV_OPA_100, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->preset_sequence_startminuteroller, ESPUPM_BACKGROUND_COLOR, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->preset_sequence_startminuteroller, LV_OPA_0, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->preset_sequence_startminuteroller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->preset_sequence_startminuteroller, 0, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_options(ui->preset_sequence_startminuteroller,
							"5\n10\n15\n20\n25\n30\n35\n40\n45\n50\n55",
							LV_ROLLER_MODE_NORMAL);
	lv_roller_set_visible_row_count(ui->preset_sequence_startminuteroller, 3);
	lv_obj_add_event_cb(ui->preset_sequence_startminuteroller, mask_event_cb, LV_EVENT_ALL, NULL);
	/*****************************************************************
	 * Start Container end
	 ****************************************************************/

	/*****************************************************************
	 * Duration Container start
	 ****************************************************************/
	//Duration Container object
	static lv_obj_t *durationcontainer;
	static lv_obj_t *durationlabel;
	static lv_obj_t *hlabel;
	static lv_obj_t *minlabel;

	durationcontainer = lv_obj_create(ui->preset_sequence_background);
	lv_obj_clear_flag(durationcontainer, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_size(durationcontainer, 300, 80);
	lv_obj_align_to(durationcontainer, startcontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_bg_color(durationcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(durationcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(durationcontainer, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(durationcontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(durationcontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Duration label


	durationlabel = lv_label_create(durationcontainer);
	lv_obj_set_size(durationlabel, 150, 80);
	lv_obj_align(durationlabel, LV_ALIGN_OUT_TOP_LEFT, 0, 30);
	lv_obj_set_style_text_font(durationlabel, &lv_font_montserrat_14_bold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(durationlabel, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(durationlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(durationlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(durationlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(durationlabel, "DURATION");

	//Hour roller for duration
	ui->preset_sequence_durationhourroller = lv_roller_create(durationcontainer);
	lv_obj_align_to(ui->preset_sequence_durationhourroller, durationcontainer, LV_ALIGN_TOP_MID, 60, -10);
	lv_obj_set_height(ui->preset_sequence_durationhourroller, 80);
	lv_obj_set_width(ui->preset_sequence_durationhourroller, 40);
	lv_obj_set_style_bg_color(ui->preset_sequence_durationhourroller, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->preset_sequence_durationhourroller, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->preset_sequence_durationhourroller, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->preset_sequence_durationhourroller, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->preset_sequence_durationhourroller, &lv_font_montserrat_14_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->preset_sequence_durationhourroller, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->preset_sequence_durationhourroller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->preset_sequence_durationhourroller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->preset_sequence_durationhourroller, &lv_font_montserrat_20_semibold, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->preset_sequence_durationhourroller, ESPUPM_COLOR_DARK_GREY, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->preset_sequence_durationhourroller, LV_OPA_100, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->preset_sequence_durationhourroller, ESPUPM_COLOR_DARK_GREY, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->preset_sequence_durationhourroller, LV_OPA_0, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->preset_sequence_durationhourroller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->preset_sequence_durationhourroller, 0, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_options(ui->preset_sequence_durationhourroller,
	                        "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23",
							LV_ROLLER_MODE_NORMAL);
	lv_roller_set_visible_row_count(ui->preset_sequence_durationhourroller, 3);
	lv_obj_add_event_cb(ui->preset_sequence_durationhourroller, mask_event_cb, LV_EVENT_ALL, NULL);

	//"H" label
	hlabel = lv_label_create(durationcontainer);
	lv_obj_set_width(hlabel, 20);
	lv_obj_align_to(hlabel, ui->preset_sequence_durationhourroller, LV_ALIGN_RIGHT_MID, 20, 7);
	lv_obj_set_style_text_font(hlabel, &lv_font_montserrat_14_bold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(hlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(hlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(hlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(hlabel, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(hlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(hlabel, "H");

	//Minute roller for duration
	ui->preset_sequence_durationminuteroller = lv_roller_create(durationcontainer);
	lv_obj_align_to(ui->preset_sequence_durationminuteroller, ui->preset_sequence_durationhourroller, LV_ALIGN_OUT_RIGHT_TOP, 20, 0);
	lv_obj_set_height(ui->preset_sequence_durationminuteroller, 80);
	lv_obj_set_width(ui->preset_sequence_durationminuteroller, 40);
	lv_obj_set_style_bg_color(ui->preset_sequence_durationminuteroller, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->preset_sequence_durationminuteroller, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->preset_sequence_durationminuteroller, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->preset_sequence_durationminuteroller, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->preset_sequence_durationminuteroller, &lv_font_montserrat_14_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->preset_sequence_durationminuteroller, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->preset_sequence_durationminuteroller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->preset_sequence_durationminuteroller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->preset_sequence_durationminuteroller, &lv_font_montserrat_20_semibold, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->preset_sequence_durationminuteroller, ESPUPM_COLOR_DARK_GREY, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->preset_sequence_durationminuteroller, LV_OPA_100, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->preset_sequence_durationminuteroller, ESPUPM_COLOR_DARK_GREY, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->preset_sequence_durationminuteroller, LV_OPA_0, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->preset_sequence_durationminuteroller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->preset_sequence_durationminuteroller, 0, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_options(ui->preset_sequence_durationminuteroller,
			"1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n\35\36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n\57\n58\n59",
			LV_ROLLER_MODE_NORMAL);
	lv_roller_set_visible_row_count(ui->preset_sequence_durationminuteroller, 3);
	lv_obj_add_event_cb(ui->preset_sequence_durationminuteroller, mask_event_cb, LV_EVENT_ALL, NULL);

	//"Min" label
	minlabel = lv_label_create(durationcontainer);
	lv_obj_set_width(minlabel, 30);
	lv_obj_align_to(minlabel, ui->preset_sequence_durationminuteroller, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
	lv_obj_set_style_text_font(minlabel, &lv_font_montserrat_14_bold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(minlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(minlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(minlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(minlabel, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(minlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(minlabel, "Min");
	/*****************************************************************
	 * Duration Container end
	 ****************************************************************/

	/*****************************************************************
	 * Setpoint Container start
	 ****************************************************************/
	//Setpoint Container object
	static lv_obj_t *setpointcontainer;
	static lv_obj_t *setpointlabel;
	static lv_obj_t *setpointunitlabel;

	setpointcontainer = lv_obj_create(ui->preset_sequence_background);
	lv_obj_clear_flag(setpointcontainer, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_size(setpointcontainer, 300, 80);
	lv_obj_align_to(setpointcontainer, durationcontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_style_bg_color(setpointcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(setpointcontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(setpointcontainer, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(setpointcontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(setpointcontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set point label
	setpointlabel = lv_label_create(setpointcontainer);
	lv_obj_set_size(setpointlabel, 150, 80);
	lv_obj_align(setpointlabel, LV_ALIGN_OUT_TOP_LEFT, 0, 30);
	lv_obj_set_style_text_font(setpointlabel, &lv_font_montserrat_14_bold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(setpointlabel, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(setpointlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(setpointlabel, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(setpointlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(setpointlabel, "SETPOINT");

	//Setpoint roller
	ui->preset_sequence_setpointroller = lv_roller_create(setpointcontainer);
	lv_obj_align_to(ui->preset_sequence_setpointroller, setpointcontainer, LV_ALIGN_TOP_MID, 60, -10);
	lv_obj_set_height(ui->preset_sequence_setpointroller, 80);
	lv_obj_set_width(ui->preset_sequence_setpointroller, 50);
	lv_obj_set_style_bg_color(ui->preset_sequence_setpointroller, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->preset_sequence_setpointroller, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->preset_sequence_setpointroller, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->preset_sequence_setpointroller, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->preset_sequence_setpointroller, &lv_font_montserrat_14_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->preset_sequence_setpointroller, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->preset_sequence_setpointroller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->preset_sequence_setpointroller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->preset_sequence_setpointroller, &lv_font_montserrat_20_semibold, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->preset_sequence_setpointroller, ESPUPM_COLOR_DARK_GREY, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->preset_sequence_setpointroller, LV_OPA_100, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->preset_sequence_setpointroller, ESPUPM_COLOR_DARK_GREY, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->preset_sequence_setpointroller, LV_OPA_0, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->preset_sequence_setpointroller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->preset_sequence_setpointroller, 0, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_options(ui->preset_sequence_setpointroller,
							"600\n601\n602\n603\n604\n605\n606\n607\n608\n609\n610\n611\n612\n613\n614\n615\n616\n617\n618\n619\n620",
							LV_ROLLER_MODE_NORMAL);
	lv_roller_set_visible_row_count(ui->preset_sequence_setpointroller, 3);
	lv_obj_add_event_cb(ui->preset_sequence_setpointroller, mask_event_cb, LV_EVENT_ALL, NULL);

	//"L/Min" label
	setpointunitlabel = lv_label_create(setpointcontainer);
	lv_obj_set_width(setpointunitlabel, 50);
	lv_obj_align_to(setpointunitlabel, ui->preset_sequence_setpointroller, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
	lv_obj_set_style_text_font(setpointunitlabel, &lv_font_montserrat_14_bold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(setpointunitlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(setpointunitlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(setpointunitlabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(setpointunitlabel, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(setpointunitlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(setpointunitlabel, "L/Min");
	/*****************************************************************
	 * Setpoint Container End
	 ****************************************************************/

	ui->preset_sequence_validbutton = lv_btn_create(ui->preset_sequence_background);
	lv_obj_align_to(ui->preset_sequence_validbutton, setpointcontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
	lv_obj_set_size(ui->preset_sequence_validbutton, 140, 44);
	lv_obj_set_style_border_width(ui->preset_sequence_validbutton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->preset_sequence_validbutton, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->preset_sequence_validbutton, ESPUPM_COLOR_GREEN, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_t *btnlabel = lv_label_create(ui->preset_sequence_validbutton);
	lv_obj_center(btnlabel);
	lv_obj_set_style_text_font(btnlabel, &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(btnlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(btnlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(btnlabel, ESPUPM_COLOR_GREEN, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(btnlabel, "VALID");

	ui->preset_sequence_addbutton = lv_btn_create(ui->preset_sequence_background);
	lv_obj_align_to(ui->preset_sequence_addbutton, ui->preset_sequence_validbutton, LV_ALIGN_OUT_RIGHT_TOP, 20, 0);
	lv_obj_set_size(ui->preset_sequence_addbutton, 140, 44);
	lv_obj_set_style_border_width(ui->preset_sequence_addbutton, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->preset_sequence_addbutton, ESPUPM_COLOR_LIGHT_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->preset_sequence_addbutton, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->preset_sequence_addbutton, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->preset_sequence_addbutton, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_t *btnlabel2 = lv_label_create(ui->preset_sequence_addbutton);
	lv_obj_center(btnlabel2);
	lv_obj_set_style_text_font(btnlabel2, &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(btnlabel2, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(btnlabel2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(btnlabel2, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(btnlabel2, "ADD");

	/**************************************************************
	 *
	 * Preset Sequence Screen design End
	 *
	 * **********************************************************/

	/************************Events Initialization*******************/
	events_init_preset_sequence(ui);
}


/***********************************************************************************************************************
 * End of file
 ***********************************************************************************************************************/
