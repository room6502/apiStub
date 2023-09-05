/**
 * @file libdcmpf_diag_nmdiag_s.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese 通信NMダイアグ機能モジュール(構造体定義)
 * @brief \~english Communication NM Diagnostics feature module (structure definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_NMDIAG_S_H
#define LIBDCMPF_DIAG_NMDIAG_S_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/libdcmpf_diag_c.h>
#include <dcmpf/diag/libdcmpf_diag_s.h>
#include <dcmpf/diag/nmdiag/libdcmpf_diag_nmdiag_c.h>

/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_nmdiag 通信NMダイアグ機能モジュール
 * \~english  @addtogroup dcmpf_diag_nmdiag Communication NM Diagnostics feature module
 * \~ @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese 過剰ウェイクアップ検出（自ECU内の異常検出）通知コールバック関数型の定義
 * 
 * @param [in] handle                       要求時に指定したコンテキストハンドル
 * @param [in] did_data                     DIDデータ(ID AC00)
 * @param [in] did_data_size                DIDデータのサイズ
 *
 * @brief \~english Definition of excessive wake-up detection (fault detection in own ECU) notification callback function type
 *
 * @param [in] handle                       Context handle specified on request
 * @param [in] did_data                     DID data(ID AC00)
 * @param [in] did_data_size                DID data size
 */
typedef void (*dcmpf_diag_nmdiag_notify_detect_excessive_wakeup_itself_cb_t)(
    dcmpf_handle_t handle,
    const uint8_t* did_data,
    uint8_t did_data_size
);

/**
 * @brief \~japanese スリープNG継続検出（自ECU内の異常検出）通知コールバック関数型の定義
 * 
 * @param [in] handle                       要求時に指定したコンテキストハンドル
 * @param [in] did_data                     DIDデータ(ID AC01)
 * @param [in] did_data_size                DIDデータのサイズ
 *
 * @brief \~english Definition of Sleep NG Continuation Detection (fault detection in own ECU) notification callback function type
 *
 * @param [in] handle                       Context handle specified on request
 * @param [in] did_data                     DID data(ID AC01)
 * @param [in] did_data_size                DID data size
 */
typedef void (*dcmpf_diag_nmdiag_notify_detect_sleep_ng_continuation_itself_cb_t)(
    dcmpf_handle_t handle,
    const uint8_t* did_data,
    uint8_t did_data_size
);

/**
 * @brief \~japanese 過剰ウェイクアップ検出（ETHERNET通信ネットワーク上の異常ECUの検出）通知コールバック関数型の定義
 * 
 * @param [in] handle                       要求時に指定したコンテキストハンドル
 * @param [in] did_data                     DIDデータ(ID AC0E)
 * @param [in] did_data_size                DIDデータのサイズ
 *
 * @brief \~english Definition of excessive wake-up detection (Detection of abnormal ECU on ETHERNET communication network) notification callback function type
 *
 * @param [in] handle                       Context handle specified on request
 * @param [in] did_data                     DID data(ID AC0E)
 * @param [in] did_data_size                DID data size
 */
typedef void (*dcmpf_diag_nmdiag_notify_detect_excessive_wakeup_ethernet_cb_t)(
    dcmpf_handle_t handle,
    const uint8_t* did_data,
    uint8_t did_data_size
);

/**
 * @brief \~japanese スリープNG継続検出（自ECU内の異常検出）通知コールバック関数型の定義
 * 
 * @param [in] handle                       要求時に指定したコンテキストハンドル
 * @param [in] did_data                     DIDデータ(ID AC0F)
 * @param [in] did_data_size                DIDデータのサイズ
 *
 * @brief \~english Definition of Sleep NG Continuation Detection (Detection of abnormal ECU on ETHERNET communication network) notification callback function type
 *
 * @param [in] handle                       Context handle specified on request
 * @param [in] did_data                     DID data(ID AC0F)
 * @param [in] did_data_size                DID data size
 */
typedef void (*dcmpf_diag_nmdiag_notify_detect_sleep_ng_continuation_ethernet_cb_t)(
    dcmpf_handle_t handle,
    const uint8_t* did_data,
    uint8_t did_data_size
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_NMDIAG_S_H */
