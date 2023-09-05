/**
 * @file libdcmpf_diag_roe_s.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese Response On Event機能モジュール(構造体定義)
 * @brief \~english Response On Event feature module (structure definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_ROE_S_H
#define LIBDCMPF_DIAG_ROE_S_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/libdcmpf_diag_c.h>
#include <dcmpf/diag/libdcmpf_diag_s.h>
#include <dcmpf/diag/roe/libdcmpf_diag_roe_c.h>

/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_roe Response On Event機能モジュール
 * \~english  @addtogroup dcmpf_diag_roe Response On Event feature module
 * \~ @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese DID監視対象追加リクエスト関数型の定義
 * 
 * @param [in] handle               要求時に指定したコンテキストハンドル
 * @param [in] order_no             オーダーNo
 * @param [in] did                  監視対象に追加するDID
 *
 * @brief \~english Defining DID Monitored Additional Request Function Types
 *
 * @param [in] handle               Context handle specified on request
 * @param [in] order_no             Order No
 * @param [in] did                  DID to be added to the monitoring target
 */
typedef void (*dcmpf_diag_roe_request_monitor_check_did_cb_t)(
    dcmpf_handle_t handle,
    uint8_t order_no,
    uint16_t did
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_ROE_S_H */
