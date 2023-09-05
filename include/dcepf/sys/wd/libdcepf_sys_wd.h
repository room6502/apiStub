/**
 * @file libdcepf_sys_wd.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 */
#ifndef LIBDCEPF_SYS_WD_H
#define LIBDCEPF_SYS_WD_H

#include <unistd.h>
#include <dcepf/common/libdcepf_type.h>
#include <dcepf/common/libdcepf_error.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*
 *********************************************************
 * DATA DEFINITION
 *********************************************************
 */
#define DCEPF_SYS_WD_STARTUP_WATCHDOGTIME_SEC   30
#define DCEPF_SYS_WD_REGULAR_WATCHDOGTIME_SEC   60

/**
 * @brief Device state.
 */
typedef enum {
    /**
     * @brief Normal state.
     */
    DCEPF_SYS_WD_DEVICE_STATE_NORMAL,
    /**
     * @brief Abnormal state. 
     * @details This state is a temporary state and may become normal state with device reset.
     */
    DCEPF_SYS_WD_DEVICE_STATE_ABNORMAL,
    /**
     * @brief Failure state. 
     * @details This state is permanent state and does not become normal state with device reset.
     */
    DCEPF_SYS_WD_DEVICE_STATE_FAILURE,
} dcepf_sys_wd_device_state_t;

/**
 * @brief Device type.
 */
typedef enum {
    /**
     * @brief Devices related to Cellular Communication. (e.g. RFIC, Power AMP)
     */
    DCEPF_SYS_WD_DEVICE_CELLULAR,
    /**
     * @brief Devices related to Wireless LAN. (e.g. WLAN IC / WLAN PA)
     */
    DCEPF_SYS_WD_DEVICE_WIFI,
    /**
     * @brief Devices related to GNSS.  (e.g. RFIC, LNA)
     */
    DCEPF_SYS_WD_DEVICE_GNSS,
    /**
     * @brief Devices related to eSIM.
     */
    DCEPF_SYS_WD_DEVICE_EESIM,
} dcepf_sys_wd_device_t;

/**
 * @brief Device state list.
 */
typedef struct {
    /**
     * @brief eSIM state.
     */
    dcepf_sys_wd_device_state_t esim_state;
    /**
     * @brief Error code of eSIM
     */
    int32_t esim_error_code;
    /**
     * @brief Cellular RF state.
     */
    dcepf_sys_wd_device_state_t cellular_rf_state;
    /**
     * @brief Error code of Cellular RF
     */
    int32_t cellular_rf_error_code;
    /**
     * @brief Wireless LAN RF state.
     */
    dcepf_sys_wd_device_state_t wifi_rf_state;
    /**
     * @brief Error code of Wireless LAN RF
     */
    int32_t wifi_rf_error_code;
    /**
     * @brief GNSS state.
     */
    dcepf_sys_wd_device_state_t gnss_state;
    /**
     * @brief Error code of GNSS
     */
    int32_t gnss_error_code;
} dcepf_sys_wd_device_state_list_t;

/*
 *********************************************************
 * CALLBACK FUNCTION DEFINITION
 *********************************************************
 */
/**
 * @brief Device Abnormality Status Notification
 *
 * @param [in] handle       Context handle.
 * @param [in] device       Modified device.
 * @param [in] state        Device state after change.
 *
 * @details
 * Power State Change Notification.
 *
 */
typedef void (*dcepf_sys_wd_notify_device_abnormally_state_cb_t)(
    dcepf_handle_t handle,
    dcepf_sys_wd_device_t device,
    dcepf_sys_wd_device_state_t state
);

/*
 *********************************************************
 * DCE PF API DEFINITION
 *********************************************************
 */
dcepf_api_status_t dcepf_sys_wd_instruct_watchdog_clear(
    pid_t pid
);

/**
 * @brief Get Device Status
 *
 * @param [in] handle                       Context handle.
 * @param [out] state_list                  Device state list.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Notify DCE of current device status.
 *
 */
dcepf_api_status_t dcepf_sys_wd_get_device_state_list(
    dcepf_handle_t handle,
    dcepf_sys_wd_device_state_list_t *state_list
);

/**
 * @brief Device Abnormality Status Notification
 *
 * @param [in] handle                       Context handle.
 * @param [in] callback                     Callback function.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_BUSY            Busy.
 * @retval DCEPF_API_STATUS_OUT_OF_BOUNDS   Out of bounds.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * CB function registration for DCE PF to notify DCE of device information in abnormal state (temporal or permanent). @n
 * If notified abnormal state is permanent, DCE should not execute recover process (device reset, etc.). @n
 * @n
 * The value definition of Error code is depend on Tier1's hardware. This parameter is used for Tier1's analysis and DCE will not use (log recording only). @n
 * @n
 * The contents of the abnormality notification needs to be adjusted with DCM PF. @n
 * Possible Failure State: eSIM abnormality, RF abnormality, etc.
 *
 */
dcepf_api_status_t dcepf_sys_wd_start_device_abnormally_state_notify(
    dcepf_handle_t handle,
    dcepf_sys_wd_notify_device_abnormally_state_cb_t callback
);

/**
 * @brief Device Abnormality Status Notification
 *
 * @param [in] handle                       Context handle.
 * @param [in] callback                     Callback function.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_BUSY            Busy.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * CB function deregistration for DCM PF.
 *
 */
dcepf_api_status_t dcepf_sys_wd_stop_device_abnormally_state_notify(
    dcepf_handle_t handle,
    dcepf_sys_wd_notify_device_abnormally_state_cb_t callback
);

/**
 * @brief Soft Restart Request
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Request to reboot Linux (Software Restart). @n
 * If a service with a higher priority than DCE does not allow rebooting, the DCE PF should not Linux and return DCEPF_RESULT_BUSY.
 *
 */
dcepf_api_status_t dcepf_sys_wd_instruct_soft_restart(void);

#ifdef __cplusplus
}
#endif

#endif  /* LIBDCEPF_SYS_WD_H */
