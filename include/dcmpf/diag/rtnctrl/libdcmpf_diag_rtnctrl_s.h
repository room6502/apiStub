/**
 * @file libdcmpf_diag_rtnctrl_s.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese ルーチンコントロール機能モジュール(構造体定義)
 * @brief \~english Routine control feature module (structure definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_RTNCTRL_S_H
#define LIBDCMPF_DIAG_RTNCTRL_S_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/libdcmpf_diag_c.h>
#include <dcmpf/diag/libdcmpf_diag_s.h>
#include <dcmpf/diag/rtnctrl/libdcmpf_diag_rtnctrl_c.h>

/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_rtnctrl ルーチンコントロール機能モジュール
 * \~english  @addtogroup dcmpf_diag_rtnctrl Routine control feature module
 * \~ @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese ルーチンコントロール開始を要求するリクエスト関数型の定義
 * 
 * @param [in] handle               要求時に指定したコンテキストハンドル
 * @param [in] order_no             オーダーNo
 * @param [in] rid                  受信したRID
 * @param [in] data                 受信したデータ
 * @param [in] data_length          受信したデータ長
 *
 * @brief \~english Definition of the request function type that requests the start of routine control
 *
 * @param [in] handle               Context handle specified on request
 * @param [in] order_no             Order No
 * @param [in] rid                  Received RID
 * @param [in] data                 Received data
 * @param [in] data_length          Data length
 */
typedef void (*dcmpf_diag_rtnctrl_request_routine_start_cb_t)(
    dcmpf_handle_t handle,
    uint8_t order_no,
    uint16_t rid,
    const uint8_t* data,
    uint16_t data_length
);

/**
 * @brief \~japanese ルーチンコントロール停止を要求するリクエスト関数型の定義
 * 
 * @param [in] handle               要求時に指定したコンテキストハンドル
 * @param [in] order_no             オーダーNo
 * @param [in] rid                  受信したRID
 * @param [in] data                 受信したデータ
 * @param [in] data_length          受信したデータ長
 *
 * @brief \~english Definition of the request function type that requests the stop of routine control
 *
 * @param [in] handle               Context handle specified on request
 * @param [in] order_no             Order No
 * @param [in] rid                  Received RID
 * @param [in] data                 Received data
 * @param [in] data_length          Data length
 */
typedef void (*dcmpf_diag_rtnctrl_request_routine_stop_cb_t)(
    dcmpf_handle_t handle,
    uint8_t order_no,
    uint16_t rid,
    const uint8_t* data,
    uint16_t data_length
);

/**
 * @brief \~japanese ルーチン結果を要求するリクエスト関数型の定義
 * 
 * @param [in] handle               要求時に指定したコンテキストハンドル
 * @param [in] order_no             オーダーNo
 * @param [in] rid                  受信したRID
 * @param [in] data                 受信したデータ
 * @param [in] data_length          受信したデータ長
 *
 * @brief \~english Defining Request Function Types to Request Routine Results
 *
 * @param [in] handle               Context handle specified on request
 * @param [in] order_no             Order No
 * @param [in] rid                  Received RID
 * @param [in] data                 Received data
 * @param [in] data_length          Data length
 */
typedef void (*dcmpf_diag_rtnctrl_request_routine_result_cb_t)(
    dcmpf_handle_t handle,
    uint8_t order_no,
    uint16_t rid,
    const uint8_t* data,
    uint16_t data_length
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_RTNCTRL_S_H */
