# Tuya IoTOS Embeded Demo WiFi & BLE XY-Remote-Sensing

[English](./README.md) | [中文](./README_zh.md) 

## Introduction 

This Demo implements an XY remote sensing through Tuya Smart Cloud Platform, Tuya Smart APP, IoTOS Embeded WiFi &Ble SDK, using Tuya WiFi/WiFi+BLE series modules to achieve data reporting.

Implemented functions.

+ Real-time reporting of XY telemetry data, X-axis AD value, Y-axis AD value, whether the button is pressed or not.




## Quick start 

### Compile & Burn 
+ Download [Tuya IoTOS Embeded WiFi & BLE sdk](https://github.com/tuya/tuya-iotos-embeded-sdk-wifi-ble-bk7231t) 

+ Download the demo to the apps directory of the SDK 

  ```bash
  $ cd apps
  $ git clone https://github.com/Tuya-Community/tuya-iotos-embeded-demo-wifi-ble-xy-remote-sensing.git
  ```
  
+ Execute the following command in the SDK root directory to start compiling.

  ```bash
  sh build_app.sh apps/xy_remote_sensing xy_remote_sensing 1.0.0 
  ```

+ Firmware burn-in license information please refer to: [Wi-Fi + BLE series module burn-in license](https://developer.tuya.com/cn/docs/iot/device-development/burn-and-authorization/burn-and-authorize-wifi-ble-modules/burn-and-authorize-wb-series-modules?id=Ka78f4pttsytd) 

 

 ### File introduction 

```
├── include
│ ├── app_adc.h
│ ├── soc
│ │ ├── soc_adc.h
│ ├── tuya_device.h
│ ├── tuya_dp_process.h
│ └── tuya_xy.h
└── src
    ├─ app_adc.c
    ├─ soc
    │ └── soc_adc.c
    ├── tuya_device.c 		// application entry file
    ├── tuya_dp_process.c 	//DP point processing file
    └── tuya_xy.c
```



 ### Demo information 

| Product ID | 4aycsbgdpulbp0ma |
| :------: | :--------------------------------------------------------: |
| Chip Platform | BK7231T |
| Compiler Environment | ty_iot_wf_bt_sdk_bk_bk7231t_1.0.2 (Tuya IOT Platform SDK 1.0.2) |

  

### Demo entry

Entry file: tuya_device.c

Important functions: device_init()

+ Call tuya_iot_wf_soc_dev_init_param() interface to initialize the SDK, configure the operating mode, the mating mode, and register various callback functions and store the firmware key and PID.

+ Calling the tuya_iot_reg_get_wf_nw_stat_cb() interface to register the device network status callback functions.


 

### DP point related

+ Report dp point interface: dev_report_dp_json_async()

| function name | OPERATE_RET dev_report_dp_json_async(IN CONST CHAR_T *dev_id,IN CONST TY_OBJ_DP_S *dp_data,IN CONST UINT_T cnt) |
| ------- | ------------------------------------------------------------ |
| devid | device id (if gateway, MCU, SOC class device then devid = NULL; if sub-device, then devid = sub-device_id) |
| dp_data | dp structure array name |
| cnt | Number of elements of the dp structure array |
| return | OPRT_OK: Success Other: Failure |

 

### I/O List 

| XY remote sensing pins | corresponding connected wb3s pins |
| :--------: | :----------------: |
| +5V | +5V |
| GND | GND |
| VRx | ADC1 |
| VRy | ADC2 |
| SW | PWM2 |

 

## Related Documents

Tuya Demo Center: https://developer.tuya.com/en/demo/



## Technical Support

You can get support for Tuya by using the following methods:

- Developer Center: https://developer.tuya.com
- Help Center: https://support.tuya.com/en/help
- Technical Support Work Order Center: https://service.console.tuya.com
