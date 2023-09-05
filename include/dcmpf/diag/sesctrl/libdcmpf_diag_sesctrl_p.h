/**
 * @file libdcmpf_diag_sesctrl_p.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 * @brief \~japanese セッションコントロール機能モジュール(プロトタイプ宣言)
 * @brief \~english Session Control feature module (prototype definition)
 *
 */
#ifndef LIBDCMPF_DIAG_SESCTRL_P_H
#define LIBDCMPF_DIAG_SESCTRL_P_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/sesctrl/libdcmpf_diag_sesctrl_c.h>
#include <dcmpf/diag/sesctrl/libdcmpf_diag_sesctrl_s.h>

/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_sesctrl セッションコントロール機能モジュール
 * \~english  @addtogroup dcmpf_diag_sesctrl Session Control feature module
 * \~ @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese 前提条件確認関数を登録する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] callback     前提条件確認時に呼び出されるコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に登録できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    指定コンテキストハンドルからの非同期API呼び出し数が規定数を超えた場合
 * @retval DCMPF_API_STATUS_FAILED           コールバック関数の登録に失敗した場合
 *
 * @details
 * 前提条件確認関数を登録する。 @n
 * ダイアグツールからの要求を受信すると、コールバック関数が呼び出される。 @n
 * コールバック関数を呼び出す際、order_noを生成して呼び出す。 @n
 * @n
 * 登録を解除する場合は、 dcmpf_diag_sesctrl_unregister_check_precondition() を呼び出し解除する。 @n
 * 既に指定されたコールバック関数への通知が開始している状態でこのAPIを呼び出した場合 @ref DCMPF_API_STATUS_SUCCESS を返す。 @n
 *
 *
 * @brief \~english Register the precondition check function.
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] callback     Callback function called during precondition checking @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the registration is successful
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid
 *                                           If the argument callback is NULL
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the number of asynchronous API calls from the specified context handle exceeds the specified number
 * @retval DCMPF_API_STATUS_FAILED           If the registration is failed
 *
 * @details
 * Register the precondition check function. @n
 * The callback function is called when a request from the diagnostic tool is received. @n
 * When calling the callback function, generate and call order_no. @n
 * @n
 * If it want to cancel the registration, you can cancel the call to dcmpf_diag_sesctrl_unregister_check_precondition() . @n
 * If this API is called while notification to the specified callback function has already started, @ref DCMPF_API_STATUS_SUCCESS is returned. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_sesctrl_register_check_precondition(
    dcmpf_handle_t handle,
    dcmpf_diag_sesctrl_request_check_precondition_cb_t callback
);

/**
 * @brief \~japanese 前提条件確認関数を登録解除する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] callback     登録解除するコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に解除できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_NO_SUCH          @ref dcmpf_diag_sesctrl_register_check_precondition() によりコールバック関数が登録されていない場合
 * @retval DCMPF_API_STATUS_FAILED           解除に失敗した場合
 *
 * @details
 * 前提条件確認関数を登録解除する。 @n
 * @n
 * @n
 *
 * @brief \~english Unegister the precondition check function.
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] callback     Unregister Callback Function @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @retval DCMPF_API_STATUS_SUCCESS          If the unregistration was successful normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid
 *                                           If the argument callback is NULL
 * @retval DCMPF_API_STATUS_NO_SUCH          If the callback function is not registered using @ref dcmpf_diag_sesctrl_register_check_precondition()
 * @retval DCMPF_API_STATUS_FAILED           If the unregistration fails
 *
 * @details
 * Unregister the precondition check function. @n
 * @n
 * @n
 *
 */
extern dcmpf_api_status_t dcmpf_diag_sesctrl_unregister_check_precondition(
    dcmpf_handle_t handle,
    dcmpf_diag_sesctrl_request_check_precondition_cb_t callback
);

/**
 * @brief \~japanese 前提条件確認結果を応答する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] order_no     要求時に受け取った order_no を設定する
 * @param [in] result       確認結果
 * @param [in] error_code   確認結果が未成立の時に通知するネガティブレスポンスコード
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に結果を受け取った場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 order_no が不正の場合 @n
 *                                           引数 result が不正の場合 @n
 *                                           引数 error_code が不正の場合 @n
 * @retval DCMPF_API_STATUS_FAILED           その他の理由で結果が受け取れなかった場合
 *
 * @details
 * 前提条件確認結果を応答する。 @n
 * @n
 * 前提条件確認時に生成したorder_noと、渡されたorder_noが一致した時、正常な応答として処理を行う。 @n
 * 結果が成功の場合、受信した要求を継続する。 @n
 * 結果が失敗の場合、指定された error_code で応答する。 @n
 * @n
 *
 * @brief \~english Respond to the precondition check results.
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] order_no     Sets the "order_no" received on request
 * @param [in] result       Check result
 * @param [in] error_code   Negative response code to notify when check result is not satisfied
 * @retval DCMPF_API_STATUS_SUCCESS          Upon successful receipt of the result normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument order_no is invalid @n
 *                                           If the argument result is invalid @n
 *                                           If the argument error_code is invalid @n
 * @retval DCMPF_API_STATUS_FAILED           Failure to receive results for any other reason
 *
 * @details
 * Respond to the precondition check results. @n
 * @n
 * When the order_no generated at the pre-condition check matches the order_no passed, processing is performed as a normal response. @n
 * If the result is successful, the received request is continued. @n
 * If the result is a failure, respond with the specified error_code. @n
 * @n
 *
 */
extern dcmpf_api_status_t dcmpf_diag_sesctrl_report_check_precondition(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_precondition_result_t result,
    dcmpf_diag_nrc_t error_code
);

/**
 * @brief \~japanese セッション変化通知を開始する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] callback     通知するコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に通知開始要求が受け付けられた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    指定コンテキストハンドルからの非同期API呼び出し数が規定数を超えた場合
 * @retval DCMPF_API_STATUS_FAILED           開始に失敗した場合
 *
 * @details
 * セッションが変化した場合に呼び出されるコールバック関数を登録し、セッションの変化通知を開始する。 @n
 * @n
 * 通知開始後、セッションが変化するとコールバック関数が呼び出される。 @n
 * 起動後、このAPIが呼び出されるまでの間、通知は行われない。 @n
 * 通知を停止する場合は、 dcmpf_diag_sesctrl_stop_session_notify() を呼び出し通知を停止する。 @n
 * 既に指定されたコールバック関数への通知が開始している状態でこのAPIを呼び出した場合 @ref DCMPF_API_STATUS_SUCCESS を返す。 @n
 *
 *
 * @brief \~english Start of Session state change notification
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] callback     Callback function pointer to notify the result @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the notification start request is successfully accepted
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument callback is NULL @n
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the number of asynchronous API calls from the specified context handle exceeds the specified number
 * @retval DCMPF_API_STATUS_FAILED           If it fails to start
 *
 * @details
 * Register callback function to notify session change, and start notification of change in the session to the registered callback function @n
 * @n
 * After the notification starts, the callback function is called every time the notify session changes. @n
 * After startup, the change notification is not performed until this API is called. @n
 * To stop the notification, call dcmpf_diag_sesctrl_stop_session_notify() to stop the notification. @n
 * If this API is called while notification to the specified callback function has already started, @ref DCMPF_API_STATUS_SUCCESS is returned. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_sesctrl_start_session_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_sesctrl_notify_session_cb_t callback
);

/**
 * @brief \~japanese セッション変化通知を停止する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] callback     解除するコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に通知停止要求が受け付けられた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_NO_SUCH          dcmpf_diag_sesctrl_start_session_notify() により、コールバック関数が登録されていない場合
 * @retval DCMPF_API_STATUS_FAILED           停止に失敗した場合
 *
 * @details
 * @ref dcmpf_diag_sesctrl_start_session_notify() により開始された変化通知コールバック関数への通知を停止する。 @n
 * @n
 * 登録済みコールバック関数の解除を行う。 @n
 *
 *
 * @brief \~english Stop the Sleep NG Continuation Detection (Detection of abnormal ECU on ETHERNET communication network) notification callback function
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] callback     Callback function pointer to notify the result @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the notification stop request is successfully accepted
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument callback is NULL @n
 * @retval DCMPF_API_STATUS_NO_SUCH          If the callback function is not registered using dcmpf_diag_sesctrl_start_session_notify()
 * @retval DCMPF_API_STATUS_FAILED           If it fails to stop
 *
 * @details
 * Stop the Sleep NG Continuation Detection (Detection of abnormal ECU on ETHERNET communication network) notification callback function. @n
 * @n
 * The registered callback functions are unregistered. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_sesctrl_stop_session_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_sesctrl_notify_session_cb_t callback
);

/**
 * @brief \~japanese 現在のセッションを取得する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [out] session     セッションの格納先への参照
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に取得できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 session がNULLの場合
 * @retval DCMPF_API_STATUS_FAILED           取得に失敗した場合
 *
 * @details
 * 現在のセッションを取得する。 @n
 * @n
 * 戻り値が DCMPF_API_STATUS_SUCCESS 以外の場合、 state の内容を参照しないこと。 @n
 *
 *
 * @brief \~english Get the current session
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [out] session     Reference to the current session
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If status is successfully obtained
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument session is NULL
 * @retval DCMPF_API_STATUS_FAILED           If acquisition fails
 *
 * @details
 * Get the current session. @n
 * @n
 * If the return value is other than DCMPF_API_STATUS_SUCCESS, do not refer to the contents of state. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_sesctrl_get_session (
    dcmpf_handle_t handle,
    uint8_t *session
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_SESCTRL_P_H */
