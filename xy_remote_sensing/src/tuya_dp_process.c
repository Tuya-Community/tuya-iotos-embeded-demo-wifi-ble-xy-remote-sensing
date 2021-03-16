#include "uni_log.h"
#include "tuya_iot_com_api.h"
#include "tuya_cloud_wifi_defs.h"
#include "tuya_dp_process.h"

XY_STATE_T xy_state = {
    .dp_id_x_axis = DP_ID_X_AXIS,
    .dp_id_y_axis = DP_ID_Y_AXIS,
    .dp_id_key = DP_ID_KEY,
    .x_value = 0,
    .y_value = 0,
    .key_state = KEY_RELEASED,
};

VOID_T deal_dp_proc(IN CONST TY_OBJ_DP_S *root)
{

}

VOID_T hw_report_all_dp_status(VOID_T)
{

    OPERATE_RET op_ret = OPRT_OK;

    INT_T dp_cnt = 0;
    dp_cnt = 3;
    
    /* 没有连接到路由器，退出 */
    GW_WIFI_NW_STAT_E wifi_state = STAT_LOW_POWER;
    get_wf_gw_nw_status(&wifi_state);
    if (wifi_state <= STAT_AP_STA_DISC || wifi_state == STAT_STA_DISC) {
        return;
    }

    TY_OBJ_DP_S *dp_arr = (TY_OBJ_DP_S *)Malloc(dp_cnt*SIZEOF(TY_OBJ_DP_S));
    if(NULL == dp_arr) {
        PR_ERR("malloc failed");
        return;
    }

    memset(dp_arr, 0, dp_cnt*SIZEOF(TY_OBJ_DP_S));

    /* x 轴 */
    dp_arr[0].dpid = xy_state.dp_id_x_axis;
    dp_arr[0].type = PROP_VALUE;
    dp_arr[0].time_stamp = 0;
    dp_arr[0].value.dp_value = xy_state.x_value;

    /* y 轴 */ 
    dp_arr[1].dpid = xy_state.dp_id_y_axis;
    dp_arr[1].type = PROP_VALUE;
    dp_arr[1].time_stamp = 0;
    dp_arr[1].value.dp_value = xy_state.y_value;

    /* key */ 
    dp_arr[2].dpid = xy_state.dp_id_key;
    dp_arr[2].type = PROP_ENUM;
    dp_arr[2].time_stamp = 0;
    dp_arr[2].value.dp_enum = xy_state.key_state;

    op_ret = dev_report_dp_json_async(NULL , dp_arr, dp_cnt);
    Free(dp_arr);
    dp_arr = NULL;
    if(OPRT_OK != op_ret) {
        PR_ERR("dev_report_dp_json_async relay_config data error,err_num",op_ret);
    }

    PR_DEBUG("dp_query report_all_dp_data");
    
    return;
}

