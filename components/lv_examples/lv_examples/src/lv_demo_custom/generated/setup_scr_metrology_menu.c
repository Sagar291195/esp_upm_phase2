/*
 * setup_src_dashboard.c
 *
 *  Created on: 20-Jun-2022
 *      Author: sagar
 */

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
 * Function to draw Metrology menu screen
 */
void setup_scr_metrology_menu(lv_ui *ui){

	// Metrology Screen Main object
	ui->metrology_menu = lv_obj_create(NULL);
	static lv_style_t style_metrology_menu_default;
	if (style_metrology_menu_default.prop_cnt > 1)
		lv_style_reset(&style_metrology_menu_default);
	else
		lv_style_init(&style_metrology_menu_default);
	lv_style_set_bg_color(&style_metrology_menu_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_metrology_menu_default, SCREEN_MIN_OPACITY);
	lv_obj_add_style(ui->metrology_menu, &style_metrology_menu_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	/***********************************************************
	 *
	 * Metroloy Menu background container design start
	 *
	 ***********************************************************/
	ui->metrology_menu_background = lv_obj_create(ui->metrology_menu);
	lv_obj_set_align(ui->metrology_menu_background, LV_ALIGN_CENTER);
	lv_obj_set_size(ui->metrology_menu_background, SCREEN_WIDTH, SCREEN_HEIGHT);
	static lv_style_t style_metrology_menu_background_default;
	if (style_metrology_menu_background_default.prop_cnt > 1)
		lv_style_reset(&style_metrology_menu_background_default);
	else
		lv_style_init(&style_metrology_menu_background_default);
	lv_style_set_radius(&style_metrology_menu_background_default, 0);
	lv_style_set_bg_color(&style_metrology_menu_background_default, ESPUPM_COLOR_BLUE);
	lv_style_set_bg_grad_color(&style_metrology_menu_background_default, ESPUPM_COLOR_BLUE);
	lv_style_set_bg_grad_dir(&style_metrology_menu_background_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_metrology_menu_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_border_color(&style_metrology_menu_background_default, ESPUPM_COLOR_BLUE);
	lv_style_set_border_width(&style_metrology_menu_background_default, 0);
	lv_style_set_border_opa(&style_metrology_menu_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_pad_left(&style_metrology_menu_background_default, 0);
	lv_style_set_pad_right(&style_metrology_menu_background_default, 0);
	lv_style_set_pad_top(&style_metrology_menu_background_default, 0);
	lv_style_set_pad_bottom(&style_metrology_menu_background_default, 0);
	lv_obj_add_style(ui->metrology_menu_background, &style_metrology_menu_background_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Metroloy Menu Screen Header
	setup_draw_header(ui, ui->metrology_menu_background);


	//Metroloy Menu Screen object for left arrow, parameter text and menu symbol
	setup_draw_title(ui, ui->metrology_menu_background, "Metrology", &metrology_icon, ESPUPM_COLOR_BLUE);

	/********************************************
	 * Metrology Menu Buttons Container Start
	 * ******************************************/

	//Create object as a container
	ui->metrology_menu_buttoncontainer = lv_obj_create(ui->metrology_menu_background);
	lv_obj_clear_flag(ui->metrology_menu_buttoncontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->metrology_menu_buttoncontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(ui->metrology_menu_buttoncontainer, ui->title_container, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
	lv_obj_set_size(ui->metrology_menu_buttoncontainer, SCREEN_WIDTH, 240);
	lv_obj_set_style_bg_color(ui->metrology_menu_buttoncontainer, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_menu_buttoncontainer, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_menu_buttoncontainer, LV_OPA_0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_menu_buttoncontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_menu_buttoncontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_t *buttonlabel;

	// Change Password button
	ui->metrology_menu_changepassword = lv_btn_create(ui->metrology_menu_buttoncontainer);
	lv_obj_align(ui->metrology_menu_changepassword, LV_ALIGN_TOP_MID, 0, 10);
	lv_obj_set_size(ui->metrology_menu_changepassword, SCREEN_WIDTH-20, 44);
	lv_obj_set_style_bg_color(ui->metrology_menu_changepassword, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->metrology_menu_changepassword, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_menu_changepassword, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_menu_changepassword, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	buttonlabel = lv_label_create(ui->metrology_menu_changepassword);
	lv_obj_clear_flag(buttonlabel, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_center(buttonlabel);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(buttonlabel, &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "CHANGE PASSWORD");

	//Set Service button
	ui->metrology_menu_setservice = lv_btn_create(ui->metrology_menu_buttoncontainer);
	lv_obj_align(ui->metrology_menu_setservice, LV_ALIGN_TOP_MID, 0, 70);
	lv_obj_set_size(ui->metrology_menu_setservice, SCREEN_WIDTH-20, 44);
	lv_obj_set_style_bg_color(ui->metrology_menu_setservice, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->metrology_menu_setservice, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_menu_setservice, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_menu_setservice, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	buttonlabel = lv_label_create(ui->metrology_menu_setservice);
	lv_obj_clear_flag(buttonlabel, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_center(buttonlabel);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(buttonlabel, &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "SET SERVICE");

	//Calibration button
	ui->metrology_menu_calibration = lv_btn_create(ui->metrology_menu_buttoncontainer);
	lv_obj_align(ui->metrology_menu_calibration, LV_ALIGN_TOP_MID, 0, 130);
	lv_obj_set_size(ui->metrology_menu_calibration, SCREEN_WIDTH-20, 44);
	lv_obj_set_style_bg_color(ui->metrology_menu_calibration, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->metrology_menu_calibration, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_menu_calibration, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_menu_calibration, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	buttonlabel = lv_label_create(ui->metrology_menu_calibration);
	lv_obj_clear_flag(buttonlabel, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_center(buttonlabel);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(buttonlabel, &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "CALIBRATION");

	//New Validation Test button
	ui->metrology_menu_newvalidationtest = lv_btn_create(ui->metrology_menu_buttoncontainer);
	lv_obj_align(ui->metrology_menu_newvalidationtest, LV_ALIGN_TOP_MID, 0, 190);
	lv_obj_set_size(ui->metrology_menu_newvalidationtest, SCREEN_WIDTH-20, 44);
	lv_obj_set_style_bg_color(ui->metrology_menu_newvalidationtest, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->metrology_menu_newvalidationtest, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_menu_newvalidationtest, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_menu_newvalidationtest, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	buttonlabel = lv_label_create(ui->metrology_menu_newvalidationtest);
	lv_obj_clear_flag(buttonlabel, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_center(buttonlabel);
	lv_obj_set_style_text_color(buttonlabel, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(buttonlabel, &lv_font_montserrat_15_semibold, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(buttonlabel, "NEW VALIDATION TEST");

	/********************************************
	 * Metrology Menu Buttons Container End
	 * ******************************************/

	/***********************************************************
	 *
	 * Metroloy Menu background container design End
	 *
	 ***********************************************************/


	/***********************************************************
	 *
	 * Metroloy Menu Sequence widget design start
	 *
	 ***********************************************************/
	//Container to draw sequence widget
	ui->metrology_menu_sequencecontainer = lv_obj_create(ui->metrology_menu_background);
	lv_obj_clear_flag(ui->metrology_menu_sequencecontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_clear_flag(ui->metrology_menu_sequencecontainer, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(ui->metrology_menu_sequencecontainer, ui->metrology_menu_buttoncontainer, LV_ALIGN_OUT_BOTTOM_LEFT, 10, 10);
	lv_obj_set_size(ui->metrology_menu_sequencecontainer, SCREEN_WIDTH-20, 84);
	lv_obj_set_style_bg_color(ui->metrology_menu_sequencecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->metrology_menu_sequencecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->metrology_menu_sequencecontainer, LV_OPA_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->metrology_menu_sequencecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->metrology_menu_sequencecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->metrology_menu_sequencecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Function to draw sequence widget
	setup_draw_sequence_widget(&ui->metrology_menu_sequencecontainer, &ui->metrology_menu_sequencecontainer_label, &ui->metrology_menu_sequencecontainer_flowsetpointvalue,
					&ui->metrology_menu_sequencecontainer_durationvalue, &ui->metrology_menu_sequencecontainer_problemvalue, &ui->metrology_menu_sequencecontainer_button);
	/***********************************************************
	 *
	 * Metroloy Menu Sequence widget design End
	 *
	 ***********************************************************/


	//Metrology Menu Screen events initialization
	events_init_metrology_menu(ui);
}

/***********************************************************************************************************************
 * End of file
 ***********************************************************************************************************************/


