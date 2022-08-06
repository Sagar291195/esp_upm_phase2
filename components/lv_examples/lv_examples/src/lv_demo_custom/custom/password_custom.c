/*
 * info_custom.c
 *
 *  Created on: 28-Jun-2022
 *      Author: SAGAR
 */
/******************************************************************************
 *      INCLUDES
 *****************************************************************************/
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "custom.h"

/******************************************************************************
 *      DEFINES
 *****************************************************************************/
#define MAX_BUTTON_COUNT	12
#define MAX_PASWORD_LABEL	4
/******************************************************************************
 *      TYPEDEF
 *****************************************************************************/

typedef struct _PSWD_PAR{
    uint8_t index;
    uint8_t pswd_kb_num;
    char enterNum[4];
}PSWD_PAR;
PSWD_PAR pswdPar;

typedef enum{
	INTIAL_STATE_GRAY,
	INTIAL_STATE_BLUE,
	ENTER_METROLOGY_CODE,
	METROLOGY_ENTER_NEW_CODE,
	METROLOGY_CONFIRM_CODE,
	USER_ENTER_NEW_CODE,
	USER_CONFIRM_CODE,
	CORRECT_CODE,
	WRONG_CODE,
};

/******************************************************************************
 *      STATIC VARIABLES
 *****************************************************************************/
const uint8_t systemPassword[10]={"1234"};
static uint32_t user_data;

/******************************************************************************
 *      STATIC PROTOTYPE
 *****************************************************************************/
static void update_passwordscreenstate(uint8_t state);

/******************************************************************************
 *      STATIC FUNCTIONS
 *****************************************************************************/

static void update_passwordscreenstate(uint8_t state){
	switch(state){
	case INTIAL_STATE_GRAY:
		for(uint8_t i = 0; i < MAX_PASWORD_LABEL; i++){
			lv_obj_set_style_bg_color(guider_ui.password_enter_num_label[i],  ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_label_set_text(guider_ui.password_enter_num_label[i], "");
		}
		for(uint8_t i = 0; i < MAX_BUTTON_COUNT; i++){
			lv_obj_set_style_bg_color(guider_ui.password_keyboard_digit[i],  ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_bg_color(guider_ui.password_keyboard_digit[i],  ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_FOCUSED);
			lv_obj_set_style_bg_color(guider_ui.password_keyboard_digit[i],  ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_PRESSED);
		}
		lv_obj_align(guider_ui.password_label, LV_ALIGN_TOP_MID, 0, 25);
		lv_label_set_text(guider_ui.password_label, "Enter code");
		lv_obj_set_style_bg_color(guider_ui.password_background, ESPUPM_BACKGROUND_COLOR, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;

	case INTIAL_STATE_BLUE:
		for(uint8_t i = 0; i < MAX_PASWORD_LABEL; i++){
			lv_obj_set_style_bg_color(guider_ui.password_enter_num_label[i],  ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_label_set_text(guider_ui.password_enter_num_label[i], "");
		}
		for(uint8_t i = 0; i < MAX_BUTTON_COUNT; i++){
			lv_obj_set_style_bg_color(guider_ui.password_keyboard_digit[i],  ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_bg_color(guider_ui.password_keyboard_digit[i],  ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_FOCUSED);
			lv_obj_set_style_bg_color(guider_ui.password_keyboard_digit[i],  ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_PRESSED);
		}
		lv_obj_align(guider_ui.password_label, LV_ALIGN_TOP_MID, 0, 20);
		lv_label_set_text(guider_ui.password_label, "Enter code");
		lv_obj_set_style_bg_color(guider_ui.password_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;

	case ENTER_METROLOGY_CODE:
		for(uint8_t i = 0; i < MAX_PASWORD_LABEL; i++){
			lv_obj_set_style_bg_color(guider_ui.password_enter_num_label[i],  ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_label_set_text(guider_ui.password_enter_num_label[i], "");
		}
		for(uint8_t i = 0; i < MAX_BUTTON_COUNT; i++){
			lv_obj_set_style_bg_color(guider_ui.password_keyboard_digit[i],  ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_bg_color(guider_ui.password_keyboard_digit[i],  ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_FOCUSED);
			lv_obj_set_style_bg_color(guider_ui.password_keyboard_digit[i],  ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_PRESSED);
		}
		lv_obj_align(guider_ui.password_label, LV_ALIGN_TOP_MID, 0, 20);
		lv_label_set_text(guider_ui.password_label, "Enter metrology code");
		lv_obj_set_style_bg_color(guider_ui.password_background, ESPUPM_COLOR_BLUE, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;

	case METROLOGY_ENTER_NEW_CODE:
		for(uint8_t i = 0; i < MAX_PASWORD_LABEL; i++){
			lv_label_set_text(guider_ui.password_enter_num_label[i], "");
		}
		lv_obj_align(guider_ui.password_label, LV_ALIGN_TOP_MID, 0, 20);
		lv_label_set_text(guider_ui.password_label, "Enter new metrology code");
		break;

	case METROLOGY_CONFIRM_CODE:
		for(uint8_t i = 0; i < MAX_PASWORD_LABEL; i++){
			lv_label_set_text(guider_ui.password_enter_num_label[i], "");
		}
		lv_obj_align(guider_ui.password_label, LV_ALIGN_TOP_MID, 0, 20);
		lv_label_set_text(guider_ui.password_label, "Confirm new metrology code");
		break;

	case USER_ENTER_NEW_CODE:
		for(uint8_t i = 0; i < MAX_PASWORD_LABEL; i++){
			lv_label_set_text(guider_ui.password_enter_num_label[i], "");
		}
		lv_obj_align(guider_ui.password_label, LV_ALIGN_TOP_MID, 0, 20);
		lv_label_set_text(guider_ui.password_label, "Enter new user code");
		break;

	case USER_CONFIRM_CODE:
		for(uint8_t i = 0; i < MAX_PASWORD_LABEL; i++){
			lv_label_set_text(guider_ui.password_enter_num_label[i], "");
		}
		lv_obj_align(guider_ui.password_label, LV_ALIGN_TOP_MID, 0, 20);
		lv_label_set_text(guider_ui.password_label, "Confirm new user code");
		break;

	case CORRECT_CODE:
		lv_label_set_text(guider_ui.password_label, "Correct code");
		lv_obj_clear_flag(guider_ui.password_status_symbol, LV_OBJ_FLAG_HIDDEN);
		lv_img_set_src(guider_ui.password_status_symbol, (char *)&ok_icon);
		break;

	case WRONG_CODE:
		lv_label_set_text(guider_ui.password_label, "Wrong code");
		lv_obj_clear_flag(guider_ui.password_status_symbol, LV_OBJ_FLAG_HIDDEN);
		lv_img_set_src(guider_ui.password_status_symbol, (char *)&cross_icon);
		break;

	default:
		break;
	}
}
/******************************************************************************
 *      GLOBAL FUNCTIONS
 *****************************************************************************/
/*
 *
 */
void custom_passwordscreen_setup(screen_id_e screenid){
	 memset(&pswdPar.index, 0, sizeof(pswdPar));

	 lv_obj_add_flag(guider_ui.password_status_symbol, LV_OBJ_FLAG_HIDDEN);

	 if(screenid == SCR_PASSWORD){
		 update_passwordscreenstate(INTIAL_STATE_GRAY);
	 }else if(screenid == SCR_PASSWORD_BLUE){
		 update_passwordscreenstate(INTIAL_STATE_BLUE);
	 }else if(screenid == SCR_PASSWORD_METROLOGY_CODE){
		 update_passwordscreenstate(ENTER_METROLOGY_CODE);
	 }
}


void on_passwordscreen_passwordkey_btnreleased(lv_obj_t *e){

    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_t * label = lv_obj_get_child(obj, NULL);
    const char * txt = lv_label_get_text(label);
    pswdPar.pswd_kb_num = *txt;
    if(pswdPar.pswd_kb_num == 239)     //backspace
    {
        if(pswdPar.index)
        {
            pswdPar.index--;
            lv_label_set_text(guider_ui.password_enter_num_label[pswdPar.index], "");
        }
    }
    else if(pswdPar.pswd_kb_num == 35)    //#
    {

    }
    else
    {
        pswdPar.enterNum[pswdPar.index] = *txt;
        lv_label_set_text(guider_ui.password_enter_num_label[pswdPar.index], "*");
        pswdPar.index++;
        if(pswdPar.index>=4)
        {
            if(!strncmp((char *)&systemPassword, pswdPar.enterNum, 4))
            {
            	update_passwordscreenstate(CORRECT_CODE);
            }
            else
            {
            	update_passwordscreenstate(WRONG_CODE);
            }
            pswdPar.index=0;
        }
    }
}


/******************************************************************************
 *      END OF FILE
 *****************************************************************************/
