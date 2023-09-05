/**
 * @file libdcmpf_diag_roe_p.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese Response On Event機能モジュール(プロトタイプ宣言)
 * @brief \~english Response On Event feature module (prototype definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_ROE_P_H
#define LIBDCMPF_DIAG_ROE_P_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/roe/libdcmpf_diag_roe_c.h>
#include <dcmpf/diag/roe/libdcmpf_diag_roe_s.h>

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
 * @brief \~japanese DID確認機能を登録する
 * 
 * @param [in] handle          @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] check_did       監視対象確認時に呼び出されるコールバック関数 @n
 *                             [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                             @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に登録できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 check_did がNULLの場合 @n
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    指定コンテキストハンドルからの非同期API呼び出し数が規定数を超えた場合
 * @retval DCMPF_API_STATUS_FAILED           コールバック関数の登録に失敗した場合
 *
 * @details
 * DID確認機能を登録する。 @n
 * @n
 * 登録を解除する場合は、 dcmpf_diag_roe_unregister_check_did() を呼び出し解除する。 @n
 * 既に指定されたコールバック関数への通知が開始している状態でこのAPIを呼び出した場合 @ref DCMPF_API_STATUS_SUCCESS を返す。 @n
 *
 *
 * @brief \~english Register the DID check function.
 *
 * @param [in] handle          Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] check_did       Callback function called when check a monitored target @n
 *                             As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                             specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the registration is successful
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid
 *                                           If the argument did_add is NULL
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the number of asynchronous API calls from the specified context handle exceeds the specified number
 * @retval DCMPF_API_STATUS_FAILED           If the registration is failed
 *
 * @details
 * Register the DID check function. @n
 * @n
 * If it want to cancel the registration, you can cancel the call to dcmpf_diag_roe_unregister_check_did() . @n
 * If this API is called while notification to the specified callback function has already started, @ref DCMPF_API_STATUS_SUCCESS is returned. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_roe_register_check_did(
    dcmpf_handle_t handle,
    dcmpf_diag_roe_request_monitor_check_did_cb_t check_did
);

/**
 * @brief \~japanese DID確認機能を登録解除する
 * 
 * @param [in] handle          @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] check_did       監視対象確認時に呼び出されるコールバック関数 @n
 *                             [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                             @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に解除できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 check_did がNULLの場合 @n
 * @retval DCMPF_API_STATUS_NO_SUCH          @ref dcmpf_diag_roe_register_check_did() によりコールバック関数が登録されていない場合
 * @retval DCMPF_API_STATUS_FAILED           解除に失敗した場合
 *
 * @details
 * DID確認機能を登録解除する。 @n
 * @n
 *
 *
 * @brief \~english Unregister the DID check function.
 *
 * @param [in] handle          Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] check_did       Callback function called when check a monitored target @n
 *                             As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                             specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the unregistration was successful normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid
 *                                           If the argument check_did is NULL
 * @retval DCMPF_API_STATUS_NO_SUCH          If the callback function is not registered using @ref dcmpf_diag_roe_register_check_did()
 * @retval DCMPF_API_STATUS_FAILED           If the unregistration fails
 *
 * @details
 * Unregister the DID check function. @n
 * @n
 * 
 *
 */
extern dcmpf_api_status_t dcmpf_diag_roe_unregister_check_did(
    dcmpf_handle_t handle,
    dcmpf_diag_roe_request_monitor_check_did_cb_t check_did
);

/**
 * @brief \~japanese 監視対象のDID確認結果を応答する
 * 
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] order_no     要求時に受け取った order_no を設定する
 * @param [in] result       DID確認結果
 * @param [in] error_code   結果が失敗の時に通知するネガティブレスポンスコード
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に結果を受け取った場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 order_no が不正の場合 @n
 *                                           引数 result が不正の場合 @n
 *                                           引数 error_code が不正の場合 @n
 * @retval DCMPF_API_STATUS_FAILED           その他の理由で結果が受け取れなかった場合
 *
 * @details
 * 監視対象のDID確認結果を応答する。 @n
 * @n
 * DID確認要求時に生成したorder_noと、渡されたorder_noが一致した時、正常な応答として処理を行う。 @n
 * 結果が成功の場合、受信した要求を継続する。 @n
 * 結果が失敗の場合、指定された error_code で応答する。 @n
 * @n
 *
 * @brief \~english Respond with the DID check result of the monitoring target
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] order_no     Sets the "order_no" received on request
 * @param [in] result       DID check result
 * @param [in] error_code   Negative response code to notify when results fail
 * @retval DCMPF_API_STATUS_SUCCESS          Upon successful receipt of the result normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument order_no is invalid @n
 *                                           If the argument result is invalid @n
 *                                           If the argument error_code is invalid @n
 * @retval DCMPF_API_STATUS_FAILED           Failure to receive results for any other reason
 *
 * @details
 * Respond with the DID check result of the monitoring target. @n
 * @n
 * When the order_no generated at the time of the DID check request and the passed order_no match, processing is performed as a normal response. @n
 * If the result is successful, the received request is continued. @n
 * If the result is a failure, respond with the specified error_code. @n
 * @n
 *
 */
extern dcmpf_api_status_t dcmpf_diag_roe_report_monitor_check_did (
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_result_t result,
    dcmpf_diag_nrc_t error_code
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_ROE_P_H */
