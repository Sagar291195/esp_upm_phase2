/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */


#ifndef EVENTS_INIT_H_
#define EVENTS_INIT_H_
#include "gui_guider.h"

void events_init(lv_ui *ui);
void events_init_dashboard(lv_ui *ui);
void events_init_parameter(lv_ui *ui);
void events_init_password(lv_ui *ui);
void events_init_summary_start(lv_ui *ui);
void events_init_logo(lv_ui *ui);
void events_init_sleep(lv_ui *ui);
void events_init_metrology_calibration(lv_ui *ui);
void events_init_metrology_menu(lv_ui *ui);
void events_init_metrology_settings(lv_ui *ui);
void events_init_summary_end(lv_ui *ui);
void events_init_metrology_service(lv_ui *ui);
void events_init_alertmessage(lv_ui *ui);
void events_init_info(lv_ui *ui);
void events_init_summary_sample(lv_ui *ui);
void events_init_preset_scenario(lv_ui *ui);
void events_init_flow_sensor_parameter(lv_ui *ui);
void events_init_preset_sequence(lv_ui *ui);
#endif /* EVENT_CB_H_ */
