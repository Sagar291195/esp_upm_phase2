if(ESP_PLATFORM)

    file(GLOB_RECURSE SOURCES src/*.c)

    idf_build_get_property(LV_MICROPYTHON LV_MICROPYTHON)

    if (LV_MICROPYTHON)
        idf_component_register(SRCS ${SOURCES}
                               INCLUDE_DIRS . src ../
                               REQUIRES main)
    else()
        idf_component_register(SRCS ${SOURCES}
                               INCLUDE_DIRS . src ../)
    endif()

    target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLV_CONF_INCLUDE_SIMPLE")

    if (CONFIG_LV_MEM_CUSTOM)
        if (CONFIG_LV_MEM_CUSTOM_ALLOC)
            target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLV_MEM_CUSTOM_ALLOC=${CONFIG_LV_MEM_CUSTOM_ALLOC}")
        endif()

        if (CONFIG_LV_MEM_CUSTOM_FREE)
            target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLV_MEM_CUSTOM_FREE=${CONFIG_LV_MEM_CUSTOM_FREE}")
        endif()
    endif()

    if (CONFIG_LV_TICK_CUSTOM)
        if (CONFIG_LV_TICK_CUSTOM_SYS_TIME_EXPR)
            target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLV_TICK_CUSTOM_SYS_TIME_EXPR=${CONFIG_LV_TICK_CUSTOM_SYS_TIME_EXPR}")
        endif()
    endif()

    if (CONFIG_LV_USER_DATA_FREE)
        target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLV_USER_DATA_FREE=${CONFIG_LV_USER_DATA_FREE}")
    endif()

    if (CONFIG_LV_ATTRIBUTE_FAST_MEM_USE_IRAM)
        target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLV_ATTRIBUTE_FAST_MEM=IRAM_ATTR")
    endif()

elseif(ZEPHYR_BASE)

    if(CONFIG_LVGL)

        zephyr_include_directories(${ZEPHYR_BASE}/lib/gui/lvgl)

        target_include_directories(lvgl INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

        zephyr_compile_definitions(LV_CONF_KCONFIG_EXTERNAL_INCLUDE=<autoconf.h>)

        zephyr_compile_definitions_ifdef(CONFIG_LV_MEM_CUSTOM
            LV_MEM_CUSTOM_ALLOC=${CONFIG_LV_MEM_CUSTOM_ALLOC}
            )
        zephyr_compile_definitions_ifdef(CONFIG_LV_MEM_CUSTOM
            LV_MEM_CUSTOM_FREE=${CONFIG_LV_MEM_CUSTOM_FREE}
            )
        zephyr_compile_definitions_ifdef(CONFIG_LV_TICK_CUSTOM
            LV_TICK_CUSTOM_SYS_TIME_EXPR=${CONFIG_LV_TICK_CUSTOM_SYS_TIME_EXPR}
            )

        zephyr_library()

        file(GLOB_RECURSE SOURCES src/*.c)
        zephyr_library_sources(${SOURCES})

    endif(CONFIG_LVGL)

else()

    file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*.c)
    file(GLOB_RECURSE EXAMPLE_SOURCES ${CMAKE_CURRENT_LIST_DIR}/examples/*.c)

    if(MICROPY_DIR)
        # with micropython, build lvgl as interface library
        # link chain is: lvgl_interface [lvgl] → usermod_lvgl_bindings [lv_bindings] → usermod [micropython] → firmware [micropython]
        add_library(lvgl_interface INTERFACE)
        # ${SOURCES} must NOT be given to add_library directly for some reason (won't be built)
        target_sources(lvgl_interface INTERFACE ${SOURCES})
        # Micropython builds with -Werror; we need to suppress some warnings, such as:
        #
        # /home/test/build/lv_micropython/ports/rp2/build-PICO/lv_mp.c:29316:16: error: 'lv_style_transition_dsc_t_path_xcb_callback' defined but not used [-Werror=unused-function]
        # 29316 | STATIC int32_t lv_style_transition_dsc_t_path_xcb_callback(const struct _lv_anim_t * arg0)
        #       |                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        target_compile_options(lvgl_interface INTERFACE -Wno-unused-function)
    else(MICROPY_DIR)
        # without micropython, build lvgl and examples libs normally
        add_library(lvgl STATIC ${SOURCES})
        add_library(lvgl_examples STATIC ${EXAMPLE_SOURCES})
    endif(MICROPY_DIR)

endif()
