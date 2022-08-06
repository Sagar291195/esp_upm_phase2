
/**
 * @file lv_demo_custom.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "../../lv_examples.h"
#include "lv_demo_custom.h"
#include "generated/events_init.h"
#include "generated/gui_guider.h"
#include "custom/custom.h"
/*********************
 *      DEFINES
 *********************/

 /**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

 /**********************
 *   STATIC FUNCTIONS
 **********************/
lv_ui guider_ui;

void lv_demo_custom(void){
    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);
}
