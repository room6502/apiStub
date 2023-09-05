/**
 * @file libdcmpf_diag_comctrl_s.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese コミュニケーションコントロール機能モジュール(構造体定義)
 * @brief \~english Communication Control feature module (structure definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_COMCTRL_S_H
#define LIBDCMPF_DIAG_COMCTRL_S_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/libdcmpf_diag_c.h>
#include <dcmpf/diag/libdcmpf_diag_s.h>
#include <dcmpf/diag/comctrl/libdcmpf_diag_comctrl_c.h>

/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_comctrl コミュニケーションコントロール機能モジュール
 * \~english  @addtogroup dcmpf_diag_comctrl Communication Control feature module
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
typedef void (*dcmpf_diag_comctrl_request_check_precondition_cb_t)(
    dcmpf_handle_t handle,
    uint8_t order_no,
    uint8_t sid,
    const uint8_t* data,
    uint32_t data_length
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_COMCTRL_S_H */
