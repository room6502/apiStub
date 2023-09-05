/**
 * @file libdcmpf_diag_ecudiag_s.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese ECUスリープダイアグ機能モジュール(構造体定義)
 * @brief \~english ECU Sleep Diagnostics feature module (structure definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_ECUDIAG_S_H
#define LIBDCMPF_DIAG_ECUDIAG_S_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/libdcmpf_diag_c.h>
#include <dcmpf/diag/libdcmpf_diag_s.h>
#include <dcmpf/diag/ecudiag/libdcmpf_diag_ecudiag_c.h>

/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_ecudiag ECUスリープダイアグ機能モジュール
 * \~english  @addtogroup dcmpf_diag_ecudiag ECU Sleep Diagnostics feature module
 * \~ @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese 過剰ウェイクアップ検出通知コールバック関数型の定義
 * 
 * @param [in] handle                       要求時に指定したコンテキストハンドル
 * @param [in] did_data                     DIDデータ(ID AC20)
 * @param [in] did_data_size                DIDデータのサイズ
 *
 * @brief \~english Definition of excessive wake-up detection notification callback function type
 *
 * @param [in] handle                       Context handle specified on request
 * @param [in] did_data                     DID data(ID AC20)
 * @param [in] did_data_size                DID data size
 */
typedef void (*dcmpf_diag_ecudiag_notify_detect_excessive_wakeup_cb_t)(
    dcmpf_handle_t handle,
    const uint8_t* did_data,
    uint8_t did_data_size
);

/**
 * @brief \~japanese スリープNG継続検出通知コールバック関数型の定義
 * 
 * @param [in] handle                       要求時に指定したコンテキストハンドル
 * @param [in] did_data                     DIDデータ(ID AC21)
 * @param [in] did_data_size                DIDデータのサイズ
 *
 * @brief \~english Definition of Sleep NG Continuation Detection notification callback function type
 *
 * @param [in] handle                       Context handle specified on request
 * @param [in] did_data                     DID data(ID AC21)
 * @param [in] did_data_size                DID data size
 */
typedef void (*dcmpf_diag_ecudiag_notify_detect_sleep_ng_continuation_cb_t)(
    dcmpf_handle_t handle,
    const uint8_t* did_data,
    uint8_t did_data_size
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_ECUDIAG_S_H */
