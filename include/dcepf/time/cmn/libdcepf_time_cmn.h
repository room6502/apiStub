/**
 * @file libdcepf_time_cmn.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 */
#ifndef LIBDCEPF_TIME_CMN_H
#define LIBDCEPF_TIME_CMN_H

#include <time.h>
#include <dcepf/common/libdcepf_type.h>
#include <dcepf/common/libdcepf_error.h>

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
 * @brief Time Acquisition Request
 *
 * @param [in] handle           Context handle.
 * @param [out] current_time    Current time.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Notify DCE of the current time. @n
 * @n
 * Time information handled by this API should comply with the provisions for time information described in the specification 1-SYS-04-00 : 24DCM System Design Policy Specification.
 *
 */
dcepf_api_status_t dcepf_time_cmn_get_current_time(
    dcepf_handle_t handle,
    time_t *current_time
);

/**
 * @brief Time Acquisition Request
 *
 * @param [in] handle           Context handle.
 * @param [in] format_len       Length of format string.
 * @param [in] format           Format string. @n
 *                              null-terminated string.
 * @param [in] current_time_len Length of formatted current time string.
 * @param [out] current_time    Formatted current time string. @n
 *                              null-terminated string.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Notify DCE of the current time as a string in the specified format. @n
 * The format is specified in the standard Linux date format. @n
 * @n
 * Time information handled by this API should comply with the provisions for time information described in the specification 1-SYS-04-00 : 24DCM System Design Policy Specification.
 *
 */
dcepf_api_status_t dcepf_time_cmn_get_formatted_current_time(
    dcepf_handle_t handle,
    size_t format_len,
    char *format,
    size_t current_time_len,
    char *current_time
);

#ifdef __cplusplus
}
#endif

#endif  /* LIBDCEPF_TIME_CMN_H */
