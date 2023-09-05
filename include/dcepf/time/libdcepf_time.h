/**
 * @file libdcepf_time.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 */
#ifndef LIBDCEPF_TIME_H
#define LIBDCEPF_TIME_H

#include <dcepf/common/libdcepf_type.h>
#include <dcepf/common/libdcepf_error.h>
#include <dcepf/time/cmn/libdcepf_time_cmn.h>

#ifdef __cplusplus
extern "C"
{
#endif
/*
 *********************************************************
 * DCE PF API DEFINITION
 *********************************************************
 */
/**
 * @brief Create a context handle for using the time feature client
 *
 * @param [out] handle      Context handle.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_OUT_OF_BOUNDS   Out of bounds.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Create a context handle for using the time feature client. @n
 * @n
 * This API create a new context handle each time it is called. @n
 * The application should create a context handle by this API and specify it in the argument of each time feature API. @n
 * The context handle does not need to create / release for each API call, it only need to create once when the application is started. @n
 * @n
 * If the return value is other than DCEPF_API_STATUS_SUCCESS, the context handle will contain NULL.
 *
 */
dcepf_api_status_t dcepf_time_control_context_create(
    dcepf_handle_t *handle
);

/**
 * @brief Release the context handle used by the time feature client
 *
 * @param [in] handle       Context handle.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Release the context handle used by the time feature client. @n
 * @n
 * The context handle may release when the time feature is no longer need, such as when the application is closed.@n
 * @n
 * If it want to use the time feature again after releasing it, use dcepf_time_control_context_create() to create a context handle.
 *
 */
dcepf_api_status_t dcepf_time_control_context_release(
    dcepf_handle_t handle
);

#ifdef __cplusplus
}
#endif

#endif  /* LIBDCEPF_TIME_H */
