#ifndef __TUYA_DP_PROCESS_H__
#define __TUYA_DP_PROCESS_H__

#include "tuya_cloud_com_defs.h"
#include "tuya_cloud_types.h"

/* DP define */
typedef UINT8_T XY_DP_T;
#define DP_ID_X_AXIS 101
#define DP_ID_Y_AXIS 102
#define DP_ID_KEY    103

#define KEY_RELEASED    0
#define KEY_PRESSED     1

typedef struct  {
    XY_DP_T dp_id_x_axis;
    XY_DP_T dp_id_y_axis;
    XY_DP_T dp_id_key;

    INT16_T x_value;
    INT16_T y_value;
    UINT8_T key_state; 
}XY_STATE_T;

extern XY_STATE_T xy_state;

VOID_T hw_report_all_dp_status(VOID_T);
VOID_T deal_dp_proc(IN CONST TY_OBJ_DP_S *root);

#endif /* __TUYA_DP_PROCESS */