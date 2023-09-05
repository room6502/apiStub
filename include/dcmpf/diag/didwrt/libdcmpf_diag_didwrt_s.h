/**
 * @file libdcmpf_diag_didwrt_s.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese DID書込み機能モジュール(構造体定義)
 * @brief \~english Write DID feature module (structure definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_DIDWRT_S_H
#define LIBDCMPF_DIAG_DIDWRT_S_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/libdcmpf_diag_c.h>
#include <dcmpf/diag/libdcmpf_diag_s.h>
#include <dcmpf/diag/didwrt/libdcmpf_diag_didwrt_c.h>

/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_didwrt DID書込み機能モジュール
 * \~english  @addtogroup dcmpf_diag_didwrt Write DID feature module
 * \~ @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese DIDが書込み可能かを確認するリクエスト関数型の定義
 * 
 * @param [in] handle               要求時に指定したコンテキストハンドル
 * @param [in] order_no             オーダーNo
 * @param [in] did                  受信したDID
 * @param [in] data                 受信したデータ
 * @param [in] data_length          受信したデータ長
 *
 * @brief \~english Defining a Request Function Type to Check if a DID Is Writable
 *
 * @param [in] handle               Context handle specified on request
 * @param [in] order_no             Order No
 * @param [in] did                  Received DID
 * @param [in] data                 Received data
 * @param [in] data_length          Data length
 */
typedef void (*dcmpf_diag_didwrt_request_check_writable_cb_t)(
    dcmpf_handle_t handle,
    uint8_t order_no,
    uint16_t did,
    const uint8_t* data,
    uint16_t data_length
);

/**
 * @brief \~japanese DID書込みリクエスト関数型の定義
 * 
 * @param [in] handle               要求時に指定したコンテキストハンドル
 * @param [in] order_no             オーダーNo
 * @param [in] did                  受信したDID
 * @param [in] data                 受信したデータ
 * @param [in] data_length          受信したデータ長
 *
 * @brief \~english Defining DID Write Request Function Types
 *
 * @param [in] handle               Context handle specified on request
 * @param [in] order_no             Order No
 * @param [in] did                  Received DID
 * @param [in] data                 Received data
 * @param [in] data_length          Data length
 */
typedef void (*dcmpf_diag_didwrt_request_write_data_cb_t)(
    dcmpf_handle_t handle,
    uint8_t order_no,
    uint16_t did,
    const uint8_t* data,
    uint16_t data_length);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_DIDWRT_S_H */
