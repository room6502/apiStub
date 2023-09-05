/**
 * @file libdcmpf_diag_secaccs_s.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese セキュリティアクセス機能モジュール(構造体定義)
 * @brief \~english Security Access feature module (structure definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_SECACCS_S_H
#define LIBDCMPF_DIAG_SECACCS_S_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/libdcmpf_diag_c.h>
#include <dcmpf/diag/libdcmpf_diag_s.h>
#include <dcmpf/diag/secaccs/libdcmpf_diag_secaccs_c.h>

/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_secaccs セキュリティアクセス機能モジュール
 * \~english  @addtogroup dcmpf_diag_secaccs Security Access feature module
 * \~ @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese Seed生成リクエスト関数型の定義
 * 
 * @param [in] handle               要求時に指定したコンテキストハンドル
 * @param [in] order_no             オーダーNo
 * @param [in] sid                  受信したSID
 * @param [in] data                 受信したデータ（SID部分を除く）
 * @param [in] data_length          dataの長さ
 *
 * @brief \~english Create seed request function definition
 *
 * @param [in] handle               Context handle specified on request
 * @param [in] order_no             Order No
 * @param [in] sid                  Received ID
 * @param [in] data                 Received data (excluding the SID part)
 * @param [in] data_length          Length of data
 */
typedef void (*dcmpf_diag_secaccs_request_create_seed_cb_t)(
    dcmpf_handle_t handle,
    uint8_t order_no,
    uint8_t sid,
    const uint8_t* data,
    uint32_t data_length
);

/**
 * @brief \~japanese Key確認リクエスト関数型の定義
 * 
 * @param [in] handle               要求時に指定したコンテキストハンドル
 * @param [in] order_no             オーダーNo
 * @param [in] sid                  受信したSID
 * @param [in] data                 受信したデータ（SID部分を除く）
 * @param [in] data_length          dataの長さ
 *
 * @brief \~english Compare key request function definition
 *
 * @param [in] handle               Context handle specified on request
 * @param [in] order_no             Order No
 * @param [in] sid                  Received ID
 * @param [in] data                 Received data (excluding the SID part)
 * @param [in] data_length          Length of data
 */
typedef void (*dcmpf_diag_secaccs_request_compare_key_cb_t)(
    dcmpf_handle_t handle,
    uint8_t order_no,
    uint8_t sid,
    const uint8_t* data,
    uint32_t data_length
);

/**
 * @brief \~japanese Key演算結果通知コールバック関数型の定義
 * 
 * @param [in] handle               要求時に指定したコンテキストハンドル
 * @param [in] result               結果
 * @param [in] calculated_key       演算したKey
 * @param [in] key_length           Keyの長さ
 *
 * @brief \~english Defining the Key Result Notification Callback Function Type
 *
 * @param [in] handle               Context handle specified on request
 * @param [in] result               Result
 * @param [in] calculated_key       Calculated key
 * @param [in] key_length           Length of calculated_key
 */
typedef void (*dcmpf_diag_secaccs_notify_calculate_key_cb_t)(
    dcmpf_handle_t handle,
    dcmpf_result_t result,
    const uint8_t* calculated_key,
    uint32_t key_length
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_SECACCS_S_H */
