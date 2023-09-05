/**
 * @file libdcmpf_diag_dtcclr_s.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese DTCクリア機能モジュール(構造体定義)
 * @brief \~english DTC Clear feature module (structure definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_DTCCLR_S_H
#define LIBDCMPF_DIAG_DTCCLR_S_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/libdcmpf_diag_c.h>
#include <dcmpf/diag/libdcmpf_diag_s.h>
#include <dcmpf/diag/dtcclr/libdcmpf_diag_dtcclr_c.h>

/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_dtcclr DTCクリア機能モジュール
 * \~english  @addtogroup dcmpf_diag_dtcclr DTC Clear feature module
 * \~ @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese 前提条件確認リクエスト関数型の定義
 * 
 * @param [in] handle               要求時に指定したコンテキストハンドル
 * @param [in] order_no             オーダーNo
 * @param [in] sid                  受信したSID
 * @param [in] data                 受信したデータ（SID部分を除く）
 * @param [in] data_length          dataの長さ
 *
 * @brief \~english Precondition check request function definition
 *
 * @param [in] handle               Context handle specified on request
 * @param [in] order_no             Order No
 * @param [in] sid                  Received ID
 * @param [in] data                 Received data (excluding the SID part)
 * @param [in] data_length          Length of data
 */
typedef void (*dcmpf_diag_dtcclr_request_check_precondition_cb_t)(
    dcmpf_handle_t handle,
    uint8_t order_no,
    uint8_t sid,
    uint8_t *const data,
    uint32_t data_length
);

/**
 * @brief \~japanese 消去完了通知コールバック関数型の定義
 * 
 * @param [in] handle               要求時に指定したコンテキストハンドル
 * @param [in] result               結果
 * @param [in] memory_selection_exist memorySelectionの有無
 * @param [in] memory_selection     消去対象のmemorySelection(memory_selection_exist=trueの時のみ有効値を格納)
 *
 * @brief \~english Clear completion notification callback function definition
 *
 * @param [in] handle               Context handle specified on request
 * @param [in] result               Result
 * @param [in] memory_selection_exist presence or absence of memorySelection
 * @param [in] memory_selection     memorySelection to be erased(When memory_selection_exist is true, valid values are stored)
 */
typedef void (*dcmpf_diag_dtcclr_notify_complete_cb_t)(
    dcmpf_handle_t handle,
    dcmpf_result_t result,
    bool memory_selection_exist,
    uint8_t memory_selection
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_DTCCLR_S_H */
