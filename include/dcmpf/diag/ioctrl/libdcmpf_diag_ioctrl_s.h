/**
 * @file libdcmpf_diag_ioctrl_s.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese IOコントロール機能モジュール(構造体定義)
 * @brief \~english IO Control feature module (structure definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_IOCTRL_S_H
#define LIBDCMPF_DIAG_IOCTRL_S_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/libdcmpf_diag_c.h>
#include <dcmpf/diag/libdcmpf_diag_s.h>
#include <dcmpf/diag/ioctrl/libdcmpf_diag_ioctrl_c.h>

/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_ioctrl IOコントロール機能モジュール
 * \~english  @addtogroup dcmpf_diag_ioctrl IO Control feature module
 * \~ @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese IOコントロールの調整リクエスト関数型の定義
 * 
 * @param [in] handle                       要求時に指定したコンテキストハンドル
 * @param [in] order_no                     オーダーNo
 * @param [in] did                          受信したDID
 * @param [in] control_state_info           受信したcontrolState
 * @param [in] control_state_info_length    control_state_infoの長さ
 * @param [in] control_mask                 受信したcontrolMask
 * @param [in] control_mask_length          control_maskの長さ
 *
 * @brief \~english Defining Tuning Request Function Types for IO Controls
 *
 * @param [in] handle                       Context handle specified on request
 * @param [in] order_no                     Order No
 * @param [in] did                          Received DID
 * @param [in] control_state_info           Received controlState
 * @param [in] control_state_info_length    Length of control_state_info
 * @param [in] control_mask                 Received controlMask
 * @param [in] control_mask_length          Length of control_mask
 */
typedef void (*dcmpf_diag_ioctrl_request_short_term_ajustment_cb_t)(
    dcmpf_handle_t handle,
    uint8_t order_no,
    uint16_t did,
    const uint8_t* control_state_info,
    uint8_t control_state_info_length,
    const uint8_t* control_mask,
    uint8_t control_mask_length
);

/**
 * @brief \~japanese IOコントロールの終了リクエスト関数型の定義
 * 
 * @param [in] handle                       要求時に指定したコンテキストハンドル
 * @param [in] order_no                     オーダーNo
 * @param [in] did                          受信したDID
 *
 * @brief \~english Defining the Exit Request Function Types for IO Controls
 *
 * @param [in] handle                       Context handle specified on request
 * @param [in] order_no                     Order No
 * @param [in] did                          Received DID
 */
typedef void (*dcmpf_diag_ioctrl_request_return_control_to_ecu_cb_t)(
    dcmpf_handle_t handle,
    uint8_t order_no,
    uint16_t did
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_IOCTRL_S_H */
