/**
 * @file libdcmpf_diag_dtc_s.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese DTC機能モジュール(構造体定義)
 * @brief \~english Diagnostic Trouble Code feature module (structure definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_DTC_S_H
#define LIBDCMPF_DIAG_DTC_S_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/libdcmpf_diag_c.h>
#include <dcmpf/diag/libdcmpf_diag_s.h>
#include <dcmpf/diag/dtc/libdcmpf_diag_dtc_c.h>

/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_dtc DTC機能モジュール
 * \~english  @addtogroup dcmpf_diag_dtc Diagnostic Trouble Code feature module
 * \~ @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese DTCの状態
 * 
 * 以下の値の論理和で表現される。
 * 
 * @li @ref DCMPF_DIAG_DTC_STATUS_TEST_FAILED
 * @li @ref DCMPF_DIAG_DTC_STATUS_TEST_FAILED_THIS_OPERATION_CYCLE
 * @li @ref DCMPF_DIAG_DTC_STATUS_PENDING_DTC
 * @li @ref DCMPF_DIAG_DTC_STATUS_CONFIRMED_DTC
 * @li @ref DCMPF_DIAG_DTC_STATUS_TEST_NOT_COMPLETED_SINCE_LAST_CLEAR
 * @li @ref DCMPF_DIAG_DTC_STATUS_TEST_FAILED_SINCE_LAST_CLEAR
 * @li @ref DCMPF_DIAG_DTC_STATUS_TEST_NOT_COMPLETED_THIS_OPERATION_CYCLE
 * @li @ref DCMPF_DIAG_DTC_STATUS_WARNING_INDICATOR_REQUESTED
 * 
 * @brief \~english Status of DTC
 * 
 * It is expressed as a logical OR of the following values.
 *
 * @li @ref DCMPF_DIAG_DTC_STATUS_TEST_FAILED
 * @li @ref DCMPF_DIAG_DTC_STATUS_TEST_FAILED_THIS_OPERATION_CYCLE
 * @li @ref DCMPF_DIAG_DTC_STATUS_PENDING_DTC
 * @li @ref DCMPF_DIAG_DTC_STATUS_CONFIRMED_DTC
 * @li @ref DCMPF_DIAG_DTC_STATUS_TEST_NOT_COMPLETED_SINCE_LAST_CLEAR
 * @li @ref DCMPF_DIAG_DTC_STATUS_TEST_FAILED_SINCE_LAST_CLEAR
 * @li @ref DCMPF_DIAG_DTC_STATUS_TEST_NOT_COMPLETED_THIS_OPERATION_CYCLE
 * @li @ref DCMPF_DIAG_DTC_STATUS_WARNING_INDICATOR_REQUESTED
 */
typedef uint8_t dcmpf_diag_dtc_status_t;

/**
 * @brief \~japanese SSR収集リクエスト関数型の定義
 * 
 * @param [in] handle               要求時に指定したコンテキストハンドル
 * @param [in] order_no             オーダーNo
 * @param [in] did                  収集するDID
 *
 * @brief \~english SSR collection request function definition
 *
 * @param [in] handle               Context handle specified on request
 * @param [in] order_no             Order No
 * @param [in] did                  DID to collect
 */
typedef void (*dcmpf_diag_dtc_request_ssr_collect_cb_t)(
    dcmpf_handle_t handle,
    uint8_t order_no,
    uint16_t did
);

/**
 * @brief \~japanese マスクに一致したDTC取得結果コールバック関数型の定義
 * 
 * @param [in] handle               要求時に指定したコンテキストハンドル
 * @param [in] result               結果
 * @param [in] dtcs                 一致したDTCリストへの参照
 * @param [in] count                一致したDTC数
 *
 * @brief \~english Defining a DTC Retrieval Result Callback Function Type that Matches a Mask
 *
 * @param [in] handle               Context handle specified on request
 * @param [in] result               Result
 * @param [in] dtcs                 Reference to Matched DTC List
 * @param [in] count                Number of matched DTC
 */
typedef void (*dcmpf_diag_dtc_query_masked_dtc_cb_t)(
    dcmpf_handle_t handle,
    dcmpf_result_t result,
    const dcmpf_diag_dtc_code_t* dtcs,
    uint8_t count
);

/**
 * @brief \~japanese 確定した要因の通知コールバック関数型の定義
 * 
 * @param [in] handle               要求時に指定したコンテキストハンドル
 * @param [in] factor               確定した要因(RoB,作動要因)
 *
 * @brief \~english Defining a Notification Callback Function Type for Confirmed Factors
 *
 * @param [in] handle               Context handle specified on request
 * @param [in] factor               Confirmed factor(RoB,Operation factor)
 */
typedef void (*dcmpf_diag_dtc_notify_confirmed_factor_cb_t)(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_user_def_code_t factor
);

/**
 * @brief \~japanese DCM異常の通知コールバック関数型の定義
 * 
 * @param [in] handle   要求時に指定したコンテキストハンドル
 * @param [in] state    状態
 *
 * @brief \~english Defining a DCM Malfunction Notification Callback Function Type
 *
 * @param [in] handle   Context handle specified on request
 * @param [in] state    status
 */
typedef void (*dcmpf_diag_dtc_notify_dcm_malfunction_state_cb_t)(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_dcm_malfunction_state_t state
);

/**
 * @brief \~japanese DCM異常（保存データ異常）の通知コールバック関数型の定義
 * 
 * @param [in] handle   要求時に指定したコンテキストハンドル
 * @param [in] state    状態
 *
 * @brief \~english Defining a DCM Malfunction Notification (storage data error) Callback Function Type
 *
 * @param [in] handle   Context handle specified on request
 * @param [in] state    status
 */
typedef void (*dcmpf_diag_dtc_notify_storage_data_error_state_cb_t)(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_dcm_malfunction_state_t state
);

/**
 * @brief \~japanese DCM異常（内部Gセンサ異常）の通知コールバック関数型の定義
 * 
 * @param [in] handle   要求時に指定したコンテキストハンドル
 * @param [in] state    状態
 *
 * @brief \~english Defining a DCM Malfunction Notification (IMU error) Callback Function Type
 *
 * @param [in] handle   Context handle specified on request
 * @param [in] state    status
 */
typedef void (*dcmpf_diag_dtc_notify_imu_error_state_cb_t)(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_dcm_malfunction_state_t state
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_DTC_S_H */
