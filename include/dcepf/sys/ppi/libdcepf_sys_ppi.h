/**
 * @file libdcepf_sys_ppi.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 */
#ifndef LIBDCEPF_SYS_PPI_H
#define LIBDCEPF_SYS_PPI_H

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
 * @brief Information Control Key data length.(Including terminating null character)
 */
#define DCEPF_SYS_PPI_INFO_CTRL_KEY_DATA_LENGTH     (11)

/*
 *********************************************************
 * DCE PF API DEFINITION
 *********************************************************
 */
/**
 * @brief Information Control Key Notification
 *
 * @param [in] handle                                           Context handle.
 * @param [out] key[DCEPF_SYS_PPI_INFO_CTRL_KEY_DATA_LENGTH]    Information Control Key data.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Notify the Information Control Key specified in "6-DCF-06-01 24DCM TSC Communication Protocol Specification APPENDIX A".
 *
 */
dcepf_api_status_t dcepf_sys_ppi_get_info_ctrl_key(
    dcepf_handle_t handle,
    char key[DCEPF_SYS_PPI_INFO_CTRL_KEY_DATA_LENGTH]
);

#ifdef __cplusplus
}
#endif

#endif  /* LIBDCEPF_SYS_PPI_H */
