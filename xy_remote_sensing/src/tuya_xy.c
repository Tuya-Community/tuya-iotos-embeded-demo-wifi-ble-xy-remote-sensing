#include "uni_log.h"
#include "tuya_gpio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "uni_thread.h"

#include "app_adc.h"
#include "tuya_xy.h"
#include "tuya_dp_process.h"

#define XY_KEY_PORT TY_GPIOA_8

USHORT_T xy_x_value, xy_y_value;

VOID_T get_xy_key_value_task(VOID_T)
{
    while (1) {
        if (tuya_gpio_read(XY_KEY_PORT) == FALSE) {
            xy_state.key_state = KEY_PRESSED;
        } else {
            xy_state.key_state = KEY_RELEASED;
        }
        
        
        get_A1_adc_value(&xy_x_value);
        xy_state.x_value = ((xy_x_value*1.0/4096) * 100.0);
        //PR_NOTICE("xy_state.x_value:%d", xy_state.x_value);

        get_A2_adc_value(&xy_y_value);
        xy_state.y_value = ((xy_y_value*1.0/4096) * 100.0);
        //PR_NOTICE("xy_state.y_value:%d", xy_state.y_value);

        hw_report_all_dp_status();
        tuya_hal_system_sleep(500);
    }
}

VOID_T xy_init(VOID_T)
{
    adc_init();

    tuya_gpio_inout_set(XY_KEY_PORT, TRUE);

    tuya_hal_thread_create(NULL, "get value", 512 * 4, TRD_PRIO_2, get_xy_key_value_task, NULL);

}
