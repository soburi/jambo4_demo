/*
 * Copyright (c) 2018 Jan Van Winkel <jan.van_winkel@dxplore.eu>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/display.h>
#include <zephyr/drivers/gpio.h>
#include <lvgl.h>
#include <stdio.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <lvgl_input_device.h>

#define LOG_LEVEL CONFIG_LOG_DEFAULT_LEVEL
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(app);

static uint32_t count;


int main(void)
{
	char count_str[11] = {0};
	const struct device *display_dev;
	lv_obj_t *hello_world_label;
	lv_obj_t *count_label;

	display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
	if (!device_is_ready(display_dev)) {
		LOG_ERR("Device not ready, aborting test");
		return 0;
	}
static lv_anim_t animation_template;
static lv_style_t label_style;
lv_anim_init(&animation_template);
lv_anim_set_delay(&animation_template, 1000); /*Wait 1 second to start ↪→the first scroll*/
lv_anim_set_repeat_delay(&animation_template, 3000); /*Repeat the scroll 3 seconds after the label␣ Initialize the label style with the animation template*/
lv_style_init(&label_style);
lv_style_set_bg_color(&label_style, lv_color_make(0x00, 0x00, 0x00));
lv_style_set_anim(&label_style, &animation_template);

	//lv_style_t blue_bg_style;
       	//lv_style_init(&blue_bg_style);
lv_obj_add_style(lv_scr_act(), &label_style, 0);
	

	//lv_task_handler();
	display_blanking_off(display_dev);

    lv_obj_t * label2 = lv_label_create(lv_scr_act());
    lv_label_set_long_mode(label2, LV_LABEL_LONG_SCROLL_CIRCULAR);     /*Circular scroll*/
    lv_obj_set_width(label2, 16);
    lv_label_set_text(label2, "Japan Technical Jamboree Episode-2 #4     ");
    lv_obj_align(label2, LV_ALIGN_CENTER, 0, 0);

	while (1) {
		lv_task_handler();
		k_sleep(K_MSEC(100));
	}
}
