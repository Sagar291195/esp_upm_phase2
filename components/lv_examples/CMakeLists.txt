if(ESP_PLATFORM)

file(GLOB_RECURSE SOURCES lv_examples/*.c)
file(GLOB_RECURSE INCLUDE lv_examples/lv_demo_custom/custom lv_examples/lv_demo_custom/generated lv_examples/lv_demo_custom) 

idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS .
                       REQUIRES lvgl)

else()
    message(FATAL_ERROR "LVGL LV examples: ESP_PLATFORM is not defined. Try reinstalling ESP-IDF.")
endif()
