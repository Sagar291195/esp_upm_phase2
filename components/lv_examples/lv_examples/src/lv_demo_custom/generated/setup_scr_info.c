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

/***********************************************************************************************************************
 * static functions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * global functions 
 ***********************************************************************************************************************/
/*
 * Function to draw info screen
 */
void setup_scr_info(lv_ui *ui){
	//Info Screen main object
	ui->info = lv_obj_create(NULL);
	static lv_style_t style_info_default;
	if (style_info_default.prop_cnt > 1)
		lv_style_reset(&style_info_default);
	else
		lv_style_init(&style_info_default);
	lv_style_set_bg_color(&style_info_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_info_default, SCREEN_MIN_OPACITY);
	lv_obj_add_style(ui->info, &style_info_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	/**************************************************
	 *
	 *Info Screen design Start
	 *
	 ***************************************************/
	//Info Screen Background
	ui->info_background = lv_obj_create(ui->info);
	lv_obj_set_align(ui->info_background, LV_ALIGN_CENTER);
	lv_obj_set_size(ui->info_background, SCREEN_WIDTH, SCREEN_HEIGHT);
	static lv_style_t style_info_background_default;
	if (style_info_background_default.prop_cnt > 1)
		lv_style_reset(&style_info_background_default);
	else
		lv_style_init(&style_info_background_default);
	lv_style_set_radius(&style_info_background_default, 0);
	lv_style_set_bg_color(&style_info_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_color(&style_info_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_bg_grad_dir(&style_info_background_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_info_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_border_color(&style_info_background_default, ESPUPM_BACKGROUND_COLOR);
	lv_style_set_border_width(&style_info_background_default, 0);
	lv_style_set_border_opa(&style_info_background_default, SCREEN_MAX_OPACITY);
	lv_style_set_pad_left(&style_info_background_default, 0);
	lv_style_set_pad_right(&style_info_background_default, 0);
	lv_style_set_pad_top(&style_info_background_default, 0);
	lv_style_set_pad_bottom(&style_info_background_default, 0);
	lv_obj_add_style(ui->info_background, &style_info_background_default, LV_PART_MAIN|LV_STATE_DEFAULT);


	//Info Screen Header
	setup_draw_header(ui, ui->info_background);


	//Parameter Screen object for left arrow, parameter text and menu symbol
	setup_draw_title(ui, ui->info_background, "INFO", NULL, ESPUPM_BACKGROUND_COLOR);

	/******************************************************************
	 * QRCode container Start
	 ******************************************************************/

	//container object for qr code
	ui->info_qrcodecontainer = lv_obj_create(ui->info_background);
	lv_obj_clear_flag(ui->info_qrcodecontainer, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_align_to(ui->info_qrcodecontainer, ui->title_container, LV_ALIGN_OUT_BOTTOM_LEFT, 10, 0);
	lv_obj_set_size(ui->info_qrcodecontainer, SCREEN_WIDTH-20, 370);
	lv_obj_set_style_bg_color(ui->info_qrcodecontainer, ESPUPM_COLOR_DARK_GREY, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->info_qrcodecontainer, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->info_qrcodecontainer, LV_OPA_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->info_qrcodecontainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Device number label
	ui->info_devicenumberlabel = lv_label_create(ui->info_qrcodecontainer);
	lv_obj_align_to(ui->info_devicenumberlabel, ui->info_qrcodecontainer, LV_ALIGN_TOP_LEFT, 5, 5);
	lv_obj_set_style_text_color(ui->info_devicenumberlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->info_devicenumberlabel, &lv_font_montserrat_16_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->info_devicenumberlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->info_devicenumberlabel, "DEVICE NUMBER :");

	//Lab name label
	ui->info_labnamelabel = lv_label_create(ui->info_qrcodecontainer);
	lv_obj_align_to(ui->info_labnamelabel, ui->info_devicenumberlabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
	lv_obj_set_style_text_color(ui->info_labnamelabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->info_labnamelabel, &lv_font_montserrat_16_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->info_labnamelabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->info_labnamelabel, "LAB. NAME :");

	//Device number value label
	ui->info_devicenumberlabelvalue = lv_label_create(ui->info_qrcodecontainer);
	lv_obj_align_to(ui->info_devicenumberlabelvalue, ui->info_qrcodecontainer, LV_ALIGN_TOP_RIGHT, -30, 5);
	lv_obj_set_style_text_color(ui->info_devicenumberlabelvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->info_devicenumberlabelvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->info_devicenumberlabelvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->info_devicenumberlabelvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->info_devicenumberlabelvalue, "68-356");

	//Lab name value label
	ui->info_labnamelabelvalue = lv_label_create(ui->info_qrcodecontainer);
	lv_obj_align_to(ui->info_labnamelabelvalue, ui->info_devicenumberlabelvalue, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 5);
	lv_obj_set_style_text_color(ui->info_labnamelabelvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->info_labnamelabelvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->info_labnamelabelvalue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->info_labnamelabelvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->info_labnamelabelvalue, "1356");

	//QR code image
	ui->info_qrcodeimage = lv_img_create(ui->info_qrcodecontainer);
	lv_img_set_src(ui->info_qrcodeimage, &QRcode_logo);
	lv_img_set_zoom(ui->info_qrcodeimage,300);
	lv_obj_center(ui->info_qrcodeimage);

	//Device id label
	ui->info_deviceidlabel = lv_label_create(ui->info_qrcodecontainer);
	lv_obj_set_width(ui->info_deviceidlabel, 170);
	lv_obj_align_to(ui->info_deviceidlabel, ui->info_qrcodecontainer, LV_ALIGN_BOTTOM_LEFT, -10, -5);
	lv_obj_set_style_text_color(ui->info_deviceidlabel, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->info_deviceidlabel, &lv_font_montserrat_16_medium, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->info_deviceidlabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->info_deviceidlabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->info_deviceidlabel, "DEVICE ID :");

	//Device id value label
	ui->info_deviceidlabelvalue = lv_label_create(ui->info_qrcodecontainer);
	lv_obj_align_to(ui->info_deviceidlabelvalue, ui->info_deviceidlabel, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_text_color(ui->info_deviceidlabelvalue, ESPUPM_COLOR_WHITE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->info_deviceidlabelvalue, &lv_font_montserrat_14_regular, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->info_deviceidlabelvalue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->info_deviceidlabelvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(ui->info_deviceidlabelvalue, "1356");
	/******************************************************************
	 * QRCode container End
	 ******************************************************************/
	/**************************************************
	 *
	 *   Info Screen design End
	 *
	 ***************************************************/

	/*******Events Initialization************/
	events_init_info(ui);
}

/***********************************************************************************************************************
 * End of file
 ***********************************************************************************************************************/
