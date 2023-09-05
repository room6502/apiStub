/**
 * @file libdcepf_dev_euicc.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 */
#ifndef LIBDCEPF_DEV_EUICC_H
#define LIBDCEPF_DEV_EUICC_H

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
 * @brief ICCID data length.(Including terminating null character)
 */
#define DCEPF_DEV_EUICC_ICCID_DATA_LENGTH   (21)
/**
 * @brief IMSI data length.(Including terminating null character)
 */
#define DCEPF_DEV_EUICC_IMSI_DATA_LENGTH    (16)
/**
 * @brief MSISDN data length.(Including terminating null character)
 */
#define DCEPF_DEV_EUICC_MSISDN_DATA_LENGTH  (16)
/**
 * @brief eUICCID data length.(Including terminating null character)
 */
#define DCEPF_DEV_EUICC_EUICCID_DATA_LENGTH (33)

/*
 *********************************************************
 * DCE PF API DEFINITION
 *********************************************************
 */
/**
 * @brief SIM ID Information Acquisition Request
 *
 * @param [in] handle                                       Context handle.
 * @param [out] iccid[DCEPF_DEV_EUICC_ICCID_DATA_LENGTH]    ICCID data. Null-terminated string.
 * @param [out] imsi[DCEPF_DEV_EUICC_IMSI_DATA_LENGTH]      IMSI data. Null-terminated string.
 * @param [out] msisdn[DCEPF_DEV_EUICC_MSISDN_DATA_LENGTH]  MSISDN data. Null-terminated string.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_NOT_READY       Not ready to use.
 * @retval DCEPF_API_STATUS_NO_RESPONSE     No response of target.
 * @retval DCEPF_API_STATUS_BUSY            Busy.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Notify DCE of the ICCID and IMSI MSISDN of the SIM profile currently enabled.
 *
 */
dcepf_api_status_t dcepf_dev_euicc_get_sim_info(
    dcepf_handle_t handle,
    char iccid[DCEPF_DEV_EUICC_ICCID_DATA_LENGTH],
    char imsi[DCEPF_DEV_EUICC_IMSI_DATA_LENGTH],
    char msisdn[DCEPF_DEV_EUICC_MSISDN_DATA_LENGTH]
);

/**
 * @brief Time eUICC ID Notification
 *
 * @param [in] handle           Context handle.
 * @param [out] euiccid[DCEPF_DEV_EUICC_EUICCID_DATA_LENGTH]    eUICCID data. Null-terminated string.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_NOT_READY       Not ready to use.
 * @retval DCEPF_API_STATUS_NO_RESPONSE     No response of target.
 * @retval DCEPF_API_STATUS_BUSY            Busy.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Notify DCE of the eUICC ID.
 *
 */
dcepf_api_status_t dcepf_dev_euicc_get_euicc_info(
    dcepf_handle_t handle,
    char euiccid[DCEPF_DEV_EUICC_EUICCID_DATA_LENGTH]
);

#ifdef __cplusplus
}
#endif

#endif  /* LIBDCEPF_DEV_EUICC_H */
