/**
 * @file libdcepf_pwr.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 */
#ifndef LIBDCEPF_PWR_H
#define LIBDCEPF_PWR_H

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
/**
 * @brief Power state.
 */
typedef enum {
    /**
     * @brief IG-ON state.
     */
    DCEPF_PWR_POWER_STATE_IGON,
    /**
     * @brief ECO state.
     */
    DCEPF_PWR_POWER_STATE_ECO,
    /**
     * @brief LIMITED state.
     */
    DCEPF_PWR_POWER_STATE_LIMITED,
    /**
     * @brief STANDBY state.
     */
    DCEPF_PWR_POWER_STATE_STANDBY,
    /**
     * @brief STOP state.
     */
    DCEPF_PWR_POWER_STATE_STOP,
    /**
     * @brief BUB state.
     */
    DCEPF_PWR_POWER_STATE_BUB,
} dcepf_pwr_power_state_t;

typedef enum {
    DCEPF_PWR_WAKELOCK_ENABLE,
    DCEPF_PWR_WAKELOCK_DISABLE
} dcepf_pwr_wakelock_mode_t;

/*
 *********************************************************
 * CALLBACK FUNCTION DEFINITION
 *********************************************************
 */
/**
 * @brief Power State Change Notification
 *
 * @param [in] handle       Context handle.
 * @param [in] state        Power state after change.
 *
 * @details
 * Power State Change Notification.
 *
 */
typedef void (*dcepf_pwr_notify_power_state_cb_t)(
    dcepf_handle_t handle,
    dcepf_pwr_power_state_t state
);

/*
 *********************************************************
 * DCE PF API DEFINITION
 *********************************************************
 */
/**
 * @brief Create a context handle for using the power feature client.
 *
 * @param [out] handle      Context handle.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_OUT_OF_BOUNDS   Out of bounds.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Create a context handle for using the common feature client. @n
 * @n
 * This API create a new context handle each time it is called. @n
 * The application should create a context handle by this API and specify it in the argument of each common feature API. @n
 * The context handle does not need to create / release for each API call, it only need to create once when the application is started. @n
 * @n
 * If the return value is other than DCEPF_API_STATUS_SUCCESS, the context handle will contain NULL.
 *
 */
dcepf_api_status_t dcepf_pwr_control_context_create(
    dcepf_handle_t *handle
);

/**
 * @brief Release the context handle used by the power feature client.
 *
 * @param [in] handle       Context handle.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Release the context handle used by the power feature client. @n
 * @n
 * The context handle may release when the power feature is no longer need, such as when the application is closed. @n
 * @n
 * If it want to use the power feature again after releasing it, use dcepf_power_control_context_create() to create a context handle.
 *
 */
dcepf_api_status_t dcepf_pwr_control_context_release(
    dcepf_handle_t handle
);

/**
 * @brief Power State Change Notification
 *
 * @param [in] handle       Context handle.
 * @param [in] callback     Callback function.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_OUT_OF_BOUNDS   Out of bounds.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Register call-back function for power state notification, and start to notify by call-back function. @n
 * Each power state corresponds to operation mode as specified in specification 4-DCM-02-00 : 24DCM Common Requirement Specification. @n
 * @n
 * When DCE PF changes its power state to IG-ON, ECO, LIMITED or BUB IG-ON or ECO, DCE PF notifies DCE by call-back function.
 *
 */
dcepf_api_status_t dcepf_pwr_start_power_state_notify(
    dcepf_handle_t handle,
    dcepf_pwr_notify_power_state_cb_t callback
);

/**
 * @brief Power State Change Notification
 *
 * @param [in] handle       Context handle.
 * @param [in] callback     Callback function.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Unregister call-back function and stop notifying.
 *
 */
dcepf_api_status_t dcepf_pwr_stop_power_state_notify(
    dcepf_handle_t handle,
    dcepf_pwr_notify_power_state_cb_t callback
);

/**
 * @brief Power State Acquisition
 *
 * @param [in] handle       Context handle.
 * @param [out] state       Power state.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Get power status.
 *
 */
dcepf_api_status_t dcepf_pwr_get_power_state(
    dcepf_handle_t handle,
    dcepf_pwr_power_state_t *state
);

dcepf_api_status_t dcepf_pwr_set_wakelock(
    dcepf_handle_t handle,
    dcepf_pwr_wakelock_mode_t operation_mode
);

dcepf_api_status_t dcepf_pwr_get_wakelock(
    dcepf_handle_t handle,
    dcepf_pwr_wakelock_mode_t *operation_mode
);

#ifdef __cplusplus
}
#endif

#endif  /* LIBDCEPF_PWR_H */
