/**
 * @file libdcmpf_diag_didrd_s.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese DID読出し機能モジュール(構造体定義)
 * @brief \~english Read DID feature module (structure definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_DIDRD_S_H
#define LIBDCMPF_DIAG_DIDRD_S_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/libdcmpf_diag_c.h>
#include <dcmpf/diag/libdcmpf_diag_s.h>
#include <dcmpf/diag/didrd/libdcmpf_diag_didrd_c.h>

/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_didrd DID読出し機能モジュール
 * \~english  @addtogroup dcmpf_diag_didrd Read DID feature module
 * \~ @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese DIDが読出し可能かを確認するリクエスト関数型の定義
 * 
 * @param [in] handle               要求時に指定したコンテキストハンドル
 * @param [in] order_no             オーダーNo
 * @param [in] did                  受信したDID
 *
 * @brief \~english Defining a Request Function Type to Check if a DID Is Readable
 *
 * @param [in] handle               Context handle specified on request
 * @param [in] order_no             Order No
 * @param [in] did                  Received DID
 */
typedef void (*dcmpf_diag_didrd_request_check_readable_cb_t)(
    dcmpf_handle_t handle,
    uint8_t order_no,
    uint16_t did
);

/**
 * @brief \~japanese DID読出しリクエスト関数型の定義
 * 
 * @param [in] handle               要求時に指定したコンテキストハンドル
 * @param [in] order_no             オーダーNo
 * @param [in] did                  読み出すDID
 *
 * @brief \~english Defining DID Read Request Function Types
 *
 * @param [in] handle               Context handle specified on request
 * @param [in] order_no             Order No
 * @param [in] did                  DID to read
 */
typedef void (*dcmpf_diag_didrd_request_read_data_cb_t)(
    dcmpf_handle_t handle,
    uint8_t order_no,
    uint16_t did
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_DIDRD_S_H */
