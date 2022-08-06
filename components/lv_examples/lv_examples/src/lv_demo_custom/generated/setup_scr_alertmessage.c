/*
 * setup_alertmessage.c
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
#include "gui_guider.h"
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

/**
 * @brief Function for static design of alert message screen
 *
 */
void setup_scr_alertmesage(lv_ui *ui)
{
	//Alertmessage Screen main object
	ui->alertmessage = lv_obj_create(NULL);
	static lv_style_t style_alertmessage_service_default;
	if (style_alertmessage_service_default.prop_cnt > 1)
		lv_style_reset(&style_alertmessage_service_default);
	else
		lv_style_init(&style_alertmessage_service_default);
	lv_style_set_bg_color(&style_alertmessage_service_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_alertmessage_service_default, SCREEN_MIN_OPACITY);
	lv_obj_add_style(ui->alertmessage, &style_alertmessage_service_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Alertmessage Screen Background
	ui->alertmessage_background = lv_obj_create(ui->alertmessage);
	lv_obj_set_align(ui->alertmessage_background, LV_ALIGN_CENTER);
	lv_obj_set_size(ui->alertmessage_background, SCREEN_WIDTH, SCREEN_HEIGHT);
	static lv_style_t style_alertmessage_service_background_default;
	if (style_alertmessage_service_background_default.prop_cnt > 1)
		lv_style_reset(&style_alertmessage_service_background_default);
	else
		lv_style_init(&style_alertmessage_service_background_default);
	lv_style_set_radius(&style_alertmessage_service_background_default, 0);
	lv_style_set_bg_color(&style_alertmessage_service_background_default, ESPUPM_COLOR_BLUE);
	lv_style_set_bg_grad_color(&style_alertmessage_service_background_default, ESPUPM_COLOR_BLUE);
	lv_style_set_bg_grad_dir(&style_alertmessage_service_background_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_alertmessage_service_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_border_color(&style_alertmessage_service_background_default, ESPUPM_COLOR_BLUE);
	lv_style_set_border_width(&style_alertmessage_service_background_default, 0);
	lv_style_set_border_opa(&style_alertmessage_service_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_pad_left(&style_alertmessage_service_background_default, 0);
	lv_style_set_pad_right(&style_alertmessage_service_background_default, 0);
	lv_style_set_pad_top(&style_alertmessage_service_background_default, 0);
	lv_style_set_pad_bottom(&style_alertmessage_service_background_default, 0);
	lv_obj_add_style(ui->alertmessage_background, &style_alertmessage_service_background_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Header draw battery, wifi and signal
	setup_draw_header(ui, ui->alertmessage_background);

	//Welcome message
	ui->alertmessage_titletext = lv_label_create(ui->alertmessage_background);
	lv_obj_align(ui->alertmessage_titletext, LV_ALIGN_TOP_RIGHT, -10, 40);
	lv_obj_set_style_text_font(ui->alertmessage_titletext, &lv_font_montserrat_22_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->alertmessage_titletext, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->alertmessage_titletext, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->alertmessage_titletext, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->alertmessage_titletext, "Welcome");

	/**********************************************
	 * Container design for alert message start
	 * *******************************************/
	//Container display various messges
	ui->alertmessage_container = lv_obj_create(ui->alertmessage_background);
	lv_obj_clear_flag(ui->alertmessage_container, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_align(ui->alertmessage_container,  LV_ALIGN_TOP_LEFT, 10, 100);
	lv_obj_set_size(ui->alertmessage_container, SCREEN_WIDTH-20, 300);
	lv_obj_set_style_bg_color(ui->alertmessage_container, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->alertmessage_container, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->alertmessage_container, LV_OPA_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->alertmessage_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Title text for alert message
	ui->alertmessage_container_title = lv_label_create(ui->alertmessage_container);
	lv_obj_set_width(ui->alertmessage_container_title, 250);
	lv_obj_align(ui->alertmessage_container_title, LV_ALIGN_TOP_MID, 0, 20);
	lv_obj_set_style_text_font(ui->alertmessage_container_title, &lv_font_montserrat_22_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->alertmessage_container_title, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->alertmessage_container_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->alertmessage_container_title, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->alertmessage_container_title, "Stabilization Phase");
	lv_label_set_long_mode(ui->alertmessage_container_title, LV_LABEL_LONG_WRAP);

	//Inner ring
	ui->alertmessage_container_ring = lv_arc_create(ui->alertmessage_container);
	lv_obj_clear_flag(ui->alertmessage_container_ring, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_align(ui->alertmessage_container_ring, LV_ALIGN_CENTER, 0, 30);
	lv_obj_set_size(ui->alertmessage_container_ring, 160, 160);
	lv_obj_set_style_bg_color(ui->alertmessage_container_ring, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->alertmessage_container_ring, LV_OPA_TRANSP, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->alertmessage_container_ring, ESPUPM_COLOR_GREEN, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->alertmessage_container_ring, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->alertmessage_container_ring, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->alertmessage_container_ring, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->alertmessage_container_ring, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->alertmessage_container_ring, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_remove_style(ui->alertmessage_container_ring, NULL, LV_PART_KNOB);
	lv_arc_set_bg_angles(ui->alertmessage_container_ring, 0, 360);
	lv_arc_set_angles(ui->alertmessage_container_ring, 0, 360);
	lv_arc_set_rotation(ui->alertmessage_container_ring, 0);

	//Outer ring
	ui->alertmessage_container_spinner = lv_arc_create(ui->alertmessage_container);
	lv_obj_clear_flag(ui->alertmessage_container_spinner, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_align(ui->alertmessage_container_spinner, LV_ALIGN_CENTER, 0, 30);
	lv_obj_set_size(ui->alertmessage_container_spinner, 190, 190);
	lv_obj_set_style_bg_color(ui->alertmessage_container_spinner, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->alertmessage_container_spinner, LV_OPA_TRANSP, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->alertmessage_container_spinner, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->alertmessage_container_spinner, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->alertmessage_container_spinner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->alertmessage_container_spinner, ESPUPM_COLOR_GREEN, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->alertmessage_container_spinner, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->alertmessage_container_spinner, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_remove_style(ui->alertmessage_container_spinner, NULL, LV_PART_KNOB);
	lv_arc_set_bg_angles(ui->alertmessage_container_spinner, 0, 360);
	lv_arc_set_angles(ui->alertmessage_container_spinner, 0, 270);
	lv_arc_set_rotation(ui->alertmessage_container_spinner, 0);

	//Label in arc
	ui->alertmessage_container_middlelabel = lv_label_create(ui->alertmessage_container);
	lv_obj_set_width(ui->alertmessage_container_middlelabel, 90);
	lv_obj_align(ui->alertmessage_container_middlelabel, LV_ALIGN_CENTER, 0, 30);
	lv_obj_set_style_text_font(ui->alertmessage_container_middlelabel, &lv_font_montserrat_22_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->alertmessage_container_middlelabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->alertmessage_container_middlelabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->alertmessage_container_middlelabel, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->alertmessage_container_middlelabel, "Please Wait 15 S");
	lv_label_set_long_mode(ui->alertmessage_container_middlelabel, LV_LABEL_LONG_WRAP);

	//Right and wrong symbol image display
	ui->alertmessage_container_symbol = lv_img_create(ui->alertmessage_container);
	lv_obj_align(ui->alertmessage_container_symbol, LV_ALIGN_CENTER, 0, 0);
	/**********************************************
	 * Container design for alert message End
	 * *******************************************/


	//hide widgets
	lv_obj_add_flag(ui->alertmessage_container_spinner, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->alertmessage_container_ring, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->alertmessage_container_middlelabel, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->alertmessage_container_symbol, LV_OBJ_FLAG_HIDDEN);

	/*************Events Initialization*********/
	//events_init_alertmessage(ui);

}


/***********************************************************************************************************************
 * End of file
 ***********************************************************************************************************************/
