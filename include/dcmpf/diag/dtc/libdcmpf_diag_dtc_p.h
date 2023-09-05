/**
 * @file libdcmpf_diag_dtc_p.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 * @brief \~japanese DTC機能モジュール(プロトタイプ宣言)
 * @brief \~english Diagnostic Trouble Code feature module (prototype definition)
 *
 */
#ifndef LIBDCMPF_DIAG_DTC_P_H
#define LIBDCMPF_DIAG_DTC_P_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/dtc/libdcmpf_diag_dtc_c.h>
#include <dcmpf/diag/dtc/libdcmpf_diag_dtc_s.h>

/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_dtc DTC機能モジュール
 * \~english  @addtogroup dcmpf_diag_dtc Diagnostic Trouble Code feature module
 * \~ @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese SSR収集リクエスト関数を登録する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] did          収集するSSRのDID
 * @param [in] callback     SSR収集時に呼び出されるコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に登録できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 did が不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    指定コンテキストハンドルからの非同期API呼び出し数が規定数を超えた場合
 * @retval DCMPF_API_STATUS_FAILED           コールバック関数の登録に失敗した場合
 *
 * @details
 * SSR収集リクエスト関数を登録する。 @n
 * @n
 * 登録を解除する場合は、 dcmpf_diag_dtc_unregister_ssr_collect() を呼び出し解除する。 @n
 * 既に指定されたコールバック関数への通知が開始している状態でこのAPIを呼び出した場合 @ref DCMPF_API_STATUS_SUCCESS を返す。 @n
 *
 *
 * @brief \~english Register the SSR collection request function.
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] did          DID of the SSR to be collected
 * @param [in] callback     Callback function called during SSR collection @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the registration is successful
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid
 *                                           If the argument did is invalid
 *                                           If the argument callback is NULL
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the number of asynchronous API calls from the specified context handle exceeds the specified number
 * @retval DCMPF_API_STATUS_FAILED           If the registration is failed
 *
 * @details
 * Register the SSR collection request function. @n
 * @n
 * If it want to cancel the registration, you can cancel the call to dcmpf_diag_dtc_unregister_ssr_collect() . @n
 * If this API is called while notification to the specified callback function has already started, @ref DCMPF_API_STATUS_SUCCESS is returned. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_dtc_register_ssr_collect(
    dcmpf_handle_t handle,
    uint16_t did,
    dcmpf_diag_dtc_request_ssr_collect_cb_t callback
);

/**
 * @brief \~japanese SSR収集リクエスト関数を解除する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] did          収集するSSRのDID
 * @param [in] callback     登録解除するコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に解除できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 did が不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_NO_SUCH          @ref dcmpf_diag_dtc_register_ssr_collect() によりコールバック関数が登録されていない場合
 * @retval DCMPF_API_STATUS_FAILED           解除に失敗した場合
 *
 * @details
 * SSR収集リクエスト関数を解除する。 @n
 * @n
 *
 *
 * @brief \~english Unregister the SSR collection request function.
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] did          DID of the SSR to be collected
 * @param [in] callback     Unregister Callback Function @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @retval DCMPF_API_STATUS_SUCCESS          If the registration was successful
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid
 *                                           If the argument did is invalid
 *                                           If the argument callback is NULL
 * @retval DCMPF_API_STATUS_NO_SUCH          If the callback function is not registered using @ref dcmpf_diag_dtc_register_ssr_collect()
 * @retval DCMPF_API_STATUS_FAILED           If registration fails
 *
 * @details
 * Unregister the SSR collection request function. @n
 * @n
 *
 */
extern dcmpf_api_status_t dcmpf_diag_dtc_unregister_ssr_collect(
    dcmpf_handle_t handle,
    uint16_t did,
    dcmpf_diag_dtc_request_ssr_collect_cb_t callback
);

/**
 * @brief \~japanese SSR収集結果を応答する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] order_no     要求時に受け取った order_no を設定する
 * @param [in] result       収集結果
 * @param [in] ssr          収集したSSRへの参照
 * @param [in] ssr_length   SSR長
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に結果を受け取った場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 order_no が不正の場合 @n
 *                                           引数 result が不正の場合 @n
 *                                           引数 ssr がNULLの場合 @n
 *                                           引数 ssr_length が不正の場合 @n
 * @retval DCMPF_API_STATUS_FAILED           その他の理由で結果が受け取れなかった場合
 *
 * @details
 * SSR収集結果を応答する。 @n
 * @n
 * SSR収集時に生成したorder_noと、渡されたorder_noが一致した時、正常な応答として処理を行う。 @n
 * 結果が成功の場合、受信した要求を継続する。 @n
 * 結果が失敗の場合、指定された error_code で応答する。 @n
 *
 * @brief \~english Respond to SSR collection results
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] order_no     Sets the "order_no" received on request
 * @param [in] result       Collection result
 * @param [in] ssr          References to Collected SSRs
 * @param [in] ssr_length   Length of SSR
 * @retval DCMPF_API_STATUS_SUCCESS          Upon successful receipt of the result normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument order_no is invalid @n
 *                                           If the argument result is invalid @n
 *                                           If the argument ssr is NULL @n
 *                                           If the argument ssr_length is invalid @n
 * @retval DCMPF_API_STATUS_FAILED           Failure to receive results for any other reason
 *
 * @details
 * Respond to SSR collection results. @n
 * @n
 * When the order_no generated at the SSR collection matches the order_no passed, processing is performed as a normal response. @n
 * If the result is  successful, the received request is continued. @n
 * If the result is a failure, respond with the specified error_code. @n
 */
extern dcmpf_api_status_t dcmpf_diag_dtc_report_ssr_collect(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_result_t result,
    const uint8_t* ssr,
    uint32_t ssr_length
);

/**
 * @brief \~japanese DTCの状態を設定する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] dtc          対象となるDTC
 * @param [in] status       DTCの状態
 * @param [in] callback     設定結果を通知するコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に要求が受付できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 dtc が不正の場合 @n
 *                                           引数 status が不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    指定コンテキストハンドルからの非同期API呼び出し数が規定数を超えた場合
 * @retval DCMPF_API_STATUS_FAILED           要求の受付に失敗した場合
 *
 * @details
 * DTCの状態を設定する。 @n
 * @n
 * 本APIは非同期で実行するため、戻り値に DCMPF_API_STATUS_SUCCESS が返却された時点では完了していない。 @n
 * callback に指定したコールバック関数からの実行結果通知により成否を判断すること。 @n
 * 成否に応じて以下の結果コードが指定される。 @n
 * @li @ref DCMPF_RESULT_SUCCESS      成功した場合
 * @li @ref DCMPF_RESULT_FAILED       失敗した場合
 *
 *
 * @brief \~english Setting the DTC status
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] dtc          DTC
 * @param [in] status       Status of DTC
 * @param [in] callback     Callback function pointer to notify the result @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the request can be accepted normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument dtc is invalid @n
 *                                           If the argument status is invalid @n
 *                                           If the argument callback is NULL
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the number of asynchronous API calls from the specified context handle exceeds the specified number
 * @retval DCMPF_API_STATUS_FAILED           If the request is not accepted
 *
 * @details
 * Setting the DTC status. @n
 * @n
 * Since this API is executed asynchronously, it is not completed when @ref DCMPF_API_STATUS_SUCCESS is returned as the return value. @n
 * To determine the success or failure by a result notification from a callback function specified in callback. @n
 * The following result codes are designated according to the success or failure. @n
 * @li @ref DCMPF_RESULT_SUCCESS      If successful
 * @li @ref DCMPF_RESULT_FAILED       If fails
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_dtc_apply_dtc_update(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_code_t dtc,
    dcmpf_diag_dtc_status_t status,
    dcmpf_operation_result_cb_t callback
);

/**
 * @brief \~japanese UserDefMemoryDTCの状態を設定する
 *
 * @param [in] handle               @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] user_def_memory_dtc  対象となるDTC
 * @param [in] status               DTCの状態
 * @param [in] callback             設定結果を通知するコールバック関数 @n
 *                                  [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                                  @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に要求が受付できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 user_def_memory_dtc が不正の場合 @n
 *                                           引数 status が不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_FAILED           要求の受付に失敗した場合
 *
 * @details
 * UserDefMemoryDTCの状態を設定する。 @n
 * @n
 * 本APIは非同期で実行するため、戻り値に DCMPF_API_STATUS_SUCCESS が返却された時点では完了していない。 @n
 * callback に指定したコールバック関数からの実行結果通知により成否を判断すること。 @n
 * 成否に応じて以下の結果コードが指定される。 @n
 * @li @ref DCMPF_RESULT_SUCCESS      成功した場合
 * @li @ref DCMPF_RESULT_FAILED       失敗した場合
 *
 *
 * @brief \~english Setting the UserDefMemoryDTC status
 *
 * @param [in] handle               Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] user_def_memory_dtc  UserDefMemoryDTC
 * @param [in] status               Status of DTC
 * @param [in] callback             Callback function pointer to notify the result @n
 *                                  As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                                  specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the request can be accepted normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument user_def_memory_dtc is invalid @n
 *                                           If the argument status is invalid @n
 *                                           If the argument callback is NULL
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the number of asynchronous API calls from the specified context handle exceeds the specified number
 * @retval DCMPF_API_STATUS_FAILED           If the request is not accepted
 *
 * @details
 * Setting the UserDefMemoryDTC status @n
 * @n
 * Since this API is executed asynchronously, it is not completed when @ref DCMPF_API_STATUS_SUCCESS is returned as the return value. @n
 * To determine the success or failure by a result notification from a callback function specified in callback. @n
 * The following result codes are designated according to the success or failure. @n
 * @li @ref DCMPF_RESULT_SUCCESS      If successful
 * @li @ref DCMPF_RESULT_FAILED       If fails
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_dtc_apply_user_def_memory_dtc_update(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_user_def_code_t user_def_memory_dtc,
    dcmpf_diag_dtc_status_t status,
    dcmpf_operation_result_cb_t callback
);

/**
 * @brief \~japanese マスクに一致したDTCを取得する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] mask         取得するDTCの状態マスク値
 * @param [in] callback     取得結果を通知するコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に要求が受付できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 mask が不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    指定コンテキストハンドルからの非同期API呼び出し数が規定数を超えた場合
 * @retval DCMPF_API_STATUS_FAILED           要求の受付に失敗した場合
 *
 * @details
 * マスクに一致したDTCを取得する @n
 * @n
 * 引数maskで指定されたDTCステータスが全て成立しているDTCが収集される。 @n
 * 例：maskが0x28の場合、DTCのステータスが0x29のものは取得できるが、0x30のものは取得対象とならない。
 * 
 * 取得結果と取得データは callback 引数で指定されたコールバック関数により返却される。 @n
 * 成否に応じて以下の結果コードが指定される。 @n
 * @li @ref DCMPF_RESULT_SUCCESS    成功した場合
 * @li @ref DCMPF_RESULT_FAILED     失敗した場合
 *
 * 取得結果が @ref DCMPF_RESULT_SUCCESS の場合のみ取得データに取得結果が格納される。 @n
 * @ref DCMPF_RESULT_SUCCESS 以外の場合は取得データは参照しないこと。 @n
 *
 *
 * @brief \~english Get DTCs matching mask
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] mask         DTC state mask value to retrieve
 * @param [in] callback     Callback function pointer to notify the result @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the request is successfully accepted
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument mask is invalid @n
 *                                           If the argument callback is NULL @n
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the number of asynchronous API calls from the specified context handle exceeds the specified number
 * @retval DCMPF_API_STATUS_FAILED           If the request is not accepted
 *
 * @details
 * Get DTCs matching mask. @n
 * @n
 * The DTCs whose DTC status specified by the argument mask is all true are collected. @n
 * Example:In case that the mask is 0x28, DTC whose status is 0x29 can be obtained, @n
 * but DTC whose status is 0x30 can not be obtained by this API.
 *
 * The information acquisition result and acquired data shall be notified through callback function specified by callback argument. @n
 * The following result codes are designated according to the success or failure. @n
 * @li @ref DCMPF_RESULT_SUCCESS    If successful
 * @li @ref DCMPF_RESULT_FAILED     If fails
 *
 * The retrieved result is stored in acquired data only when the information acquisition result is @ref DCMPF_RESULT_SUCCESS @n
 * Do not refer to acquired data except for @ref DCMPF_RESULT_SUCCESS @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_dtc_query_masked_dtc(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_status_t mask,
    dcmpf_diag_dtc_query_masked_dtc_cb_t callback
);

/**
 * @brief \~japanese 確定した要因の通知を開始する
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
 * 確定した要因の通知を開始する。 @n
 * @n
 * 通知開始後、要因が確定するとコールバック関数が呼び出される。 @n
 * 起動後、このAPIが呼び出されるまでの間、通知は行われない。 @n
 * 通知を停止する場合は、 dcmpf_diag_dtc_stop_confirmed_factor_notify() を呼び出し通知を停止する。 @n
 * 既に指定されたコールバック関数への通知が開始している状態でこのAPIを呼び出した場合 @ref DCMPF_API_STATUS_SUCCESS を返す。 @n
 *
 *
 * @brief \~english Start notification of confirmed factors
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] callback     Callback function pointer to notify the result @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @retval DCMPF_API_STATUS_SUCCESS          If the notification start request is successfully accepted
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument callback is NULL @n
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the number of asynchronous API calls from the specified context handle exceeds the specified number
 * @retval DCMPF_API_STATUS_FAILED           If it fails to start
 *
 * @details
 * Start notification of confirmed factors. @n
 * @n
 * After the notification starts, the callback function is called every time the factor confirmes. @n
 * After startup, the change notification is not performed until this API is called. @n
 * To stop the notification, call dcmpf_diag_dtc_stop_confirmed_factor_notify() to stop the notification. @n
 * If this API is called while notification to the specified callback function has already started, @ref DCMPF_API_STATUS_SUCCESS is returned. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_dtc_start_confirmed_factor_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_notify_confirmed_factor_cb_t callback
);

/**
 * @brief \~japanese 確定した要因の通知を停止する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] callback     解除するコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に通知停止要求が受け付けられた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_NO_SUCH          dcmpf_diag_dtc_start_confirmed_factor_notify() により、コールバック関数が登録されていない場合
 * @retval DCMPF_API_STATUS_FAILED           停止に失敗した場合
 *
 * @details
 * 確定した要因の通知を停止する。 @n
 * @n
 * 登録済みコールバック関数の解除を行う。 @n
 *
 *
 * @brief \~english Stop notification of confirmed factors
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] callback     Callback function pointer to notify the result @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the notification stop request is successfully accepted
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument callback is NULL @n
 * @retval DCMPF_API_STATUS_NO_SUCH          If the callback function is not registered using dcmpf_diag_dtc_start_confirmed_factor_notify()
 * @retval DCMPF_API_STATUS_FAILED           If it fails to stop
 *
 * @details
 * Stop notification of confirmed factors. @n
 * @n
 * The registered callback functions are unregistered. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_dtc_stop_confirmed_factor_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_notify_confirmed_factor_cb_t callback
);

/**
 * @brief \~japanese DCM異常の通知を開始する
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
 * DCM異常の通知を開始する。 @n
 * @n
 * 通知開始後、DCM異常が発生するとコールバック関数が呼び出される。 @n
 * 起動後、このAPIが呼び出されるまでの間、通知は行われない。 @n
 * 通知を停止する場合は、 dcmpf_diag_dtc_stop_dcm_malfunction_state_notify() を呼び出し通知を停止する。 @n
 * 既に指定されたコールバック関数への通知が開始している状態でこのAPIを呼び出した場合 @ref DCMPF_API_STATUS_SUCCESS を返す。 @n
 *
 *
 * @brief \~english Start notification of DCM Malfunction
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] callback     Callback function pointer to notify the result @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @retval DCMPF_API_STATUS_SUCCESS          If the notification start request is successfully accepted
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument callback is NULL @n
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the number of asynchronous API calls from the specified context handle exceeds the specified number
 * @retval DCMPF_API_STATUS_FAILED           If it fails to start
 *
 * @details
 * Start notification of DCM Malfunction. @n
 * @n
 * After the notification starts, the callback function is called every time the DCM Malfunction occures. @n
 * After startup, the change notification is not performed until this API is called. @n
 * To stop the notification, call dcmpf_diag_dtc_stop_dcm_malfunction_state_notify() to stop the notification. @n
 * If this API is called while notification to the specified callback function has already started, @ref DCMPF_API_STATUS_SUCCESS is returned. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_dtc_start_dcm_malfunction_state_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_notify_dcm_malfunction_state_cb_t callback
);

/**
 * @brief \~japanese DCM異常の通知を停止する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] callback     解除するコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に通知停止要求が受け付けられた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_NO_SUCH          dcmpf_diag_dtc_start_dcm_malfunction_state_notify() により、コールバック関数が登録されていない場合
 * @retval DCMPF_API_STATUS_FAILED           停止に失敗した場合
 *
 * @details
 * DCM異常の通知を停止する。 @n
 * @n
 * 登録済みコールバック関数の解除を行う。 @n
 *
 *
 * @brief \~english Stop notification of DCM Malfunction
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] callback     Callback function pointer to notify the result @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the notification stop request is successfully accepted
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument callback is NULL @n
 * @retval DCMPF_API_STATUS_NO_SUCH          If the callback function is not registered using dcmpf_diag_dtc_start_dcm_malfunction_state_notify()
 * @retval DCMPF_API_STATUS_FAILED           If it fails to stop
 *
 * @details
 * Stop notification of DCM Malfunction. @n
 * @n
 * The registered callback functions are unregistered. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_dtc_stop_dcm_malfunction_state_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_notify_dcm_malfunction_state_cb_t callback
);

/**
 * @brief \~japanese DCM異常状態を取得する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [out] state       状態の格納先への参照
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に取得できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 state がNULLの場合
 * @retval DCMPF_API_STATUS_FAILED           取得に失敗した場合
 *
 * @details
 * DCM異常状態を取得する。 @n
 * @n
 * 戻り値が DCMPF_API_STATUS_SUCCESS 以外の場合、 state の内容を参照しないこと。 @n
 *
 *
 * @brief \~english Get the DCM Malfunction state
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [out] state       Reference to the DCM Malfunction state
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If status is successfully obtained
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument state is NULL
 * @retval DCMPF_API_STATUS_FAILED           If acquisition fails
 *
 * @details
 * Get the DCM Malfunction state. @n
 * @n
 * If the return value is other than DCMPF_API_STATUS_SUCCESS, do not refer to the contents of state. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_dtc_get_dcm_malfunction_state(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_dcm_malfunction_state_t* state
);

/**
 * @brief \~japanese DCM異常（保存データ異常）の通知を開始する
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
 * DCM異常（保存データ異常）の通知を開始する。 @n
 * @n
 * 通知開始後、DCM異常状態が変化するとコールバック関数が呼び出される。 @n
 * 起動後、このAPIが呼び出されるまでの間、通知は行われない。 @n
 * 通知を停止する場合は、 dcmpf_diag_dtc_stop_storage_data_error_state_notify() を呼び出し通知を停止する。 @n
 * 既に指定されたコールバック関数への通知が開始している状態でこのAPIを呼び出した場合 @ref DCMPF_API_STATUS_SUCCESS を返す。 @n
 *
 *
 * @brief \~english Start notification of DCM Malfunction (storage data error)
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] callback     Callback function pointer to notify the result @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @retval DCMPF_API_STATUS_SUCCESS          If the notification start request is successfully accepted
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument callback is NULL @n
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the number of asynchronous API calls from the specified context handle exceeds the specified number
 * @retval DCMPF_API_STATUS_FAILED           If it fails to start
 *
 * @details
 * Start notification of DCM Malfunction (storage data error). @n
 * @n
 * After the notification starts, the callback function is called every time the DCM Malfunction (storage data error) changes. @n
 * After startup, the change notification is not performed until this API is called. @n
 * To stop the notification, call dcmpf_diag_dtc_stop_storage_data_error_state_notify() to stop the notification. @n
 * If this API is called while notification to the specified callback function has already started, @ref DCMPF_API_STATUS_SUCCESS is returned. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_dtc_start_storage_data_error_state_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_notify_storage_data_error_state_cb_t callback
);

/**
 * @brief \~japanese DCM異常（保存データ異常）の通知を停止する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] callback     解除するコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に通知停止要求が受け付けられた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_NO_SUCH          dcmpf_diag_dtc_start_storage_data_error_state_notify() により、コールバック関数が登録されていない場合
 * @retval DCMPF_API_STATUS_FAILED           停止に失敗した場合
 *
 * @details
 * DCM異常（保存データ異常）の通知を停止する。 @n
 * @n
 * 登録済みコールバック関数の解除を行う。 @n
 *
 *
 * @brief \~english Stop notification of DCM Malfunction (storage data error)
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] callback     Callback function pointer to notify the result @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the notification stop request is successfully accepted
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument callback is NULL @n
 * @retval DCMPF_API_STATUS_NO_SUCH          If the callback function is not registered using dcmpf_diag_dtc_start_storage_data_error_state_notify()
 * @retval DCMPF_API_STATUS_FAILED           If it fails to stop
 *
 * @details
 * Stop notification of DCM Malfunction (storage data error). @n
 * @n
 * The registered callback functions are unregistered. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_dtc_stop_storage_data_error_state_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_notify_storage_data_error_state_cb_t callback
);

/**
 * @brief \~japanese DCM異常（保存データ異常）状態を取得する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [out] state       状態の格納先への参照
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に取得できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 state がNULLの場合
 * @retval DCMPF_API_STATUS_FAILED           取得に失敗した場合
 *
 * @details
 * DCM異常（保存データ異常）状態を取得する。 @n
 * @n
 * 戻り値が DCMPF_API_STATUS_SUCCESS 以外の場合、 state の内容を参照しないこと。 @n
 *
 *
 * @brief \~english Get the DCM Malfunction state (storage data error)
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [out] state       Reference to the DCM Malfunction state (storage data error)
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If status is successfully obtained
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument state is NULL
 * @retval DCMPF_API_STATUS_FAILED           If acquisition fails
 *
 * @details
 * Get the DCM Malfunction state (storage data error). @n
 * @n
 * If the return value is other than DCMPF_API_STATUS_SUCCESS, do not refer to the contents of state. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_dtc_get_storage_data_error_state(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_dcm_malfunction_state_t* state
);

/**
 * @brief \~japanese DCM異常（内部Gセンサ異常）の通知を開始する
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
 * DCM異常（内部Gセンサ異常）の通知を開始する。 @n
 * @n
 * 通知開始後、DCM異常（内部Gセンサ異常）が発生するとコールバック関数が呼び出される。 @n
 * 起動後、このAPIが呼び出されるまでの間、通知は行われない。 @n
 * 通知を停止する場合は、 dcmpf_diag_dtc_stop_imu_error_state_notify() を呼び出し通知を停止する。 @n
 * 既に指定されたコールバック関数への通知が開始している状態でこのAPIを呼び出した場合 @ref DCMPF_API_STATUS_SUCCESS を返す。 @n
 *
 *
 * @brief \~english Start notification of DCM Malfunction (IMU error)
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
 * Start notification of DCM Malfunction (IMU error). @n
 * @n
 * After the notification starts, the callback function is called every time the DCM Malfunction (IMU error) occures. @n
 * After startup, the change notification is not performed until this API is called. @n
 * To stop the notification, call dcmpf_diag_dtc_stop_imu_error_state_notify() to stop the notification. @n
 * If this API is called while notification to the specified callback function has already started, @ref DCMPF_API_STATUS_SUCCESS is returned. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_dtc_start_imu_error_state_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_notify_imu_error_state_cb_t callback
);

/**
 * @brief \~japanese DCM異常（内部Gセンサ異常）の通知を停止する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] callback     解除するコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に通知停止要求が受け付けられた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_NO_SUCH          dcmpf_diag_dtc_start_imu_error_state_notify() により、コールバック関数が登録されていない場合
 * @retval DCMPF_API_STATUS_FAILED           停止に失敗した場合
 *
 * @details
 * DCM異常（内部Gセンサ異常）の通知を停止する。 @n
 * @n
 * 登録済みコールバック関数の解除を行う。 @n
 *
 *
 * @brief \~english Stop notification of DCM Malfunction (IMU error)
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] callback     Callback function pointer to notify the result @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the notification stop request is successfully accepted
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument callback is NULL @n
 * @retval DCMPF_API_STATUS_NO_SUCH          If the callback function is not registered using dcmpf_diag_dtc_start_imu_error_state_notify()
 * @retval DCMPF_API_STATUS_FAILED           If it fails to stop
 *
 * @details
 * Stop notification of DCM Malfunction (IMU error). @n
 * @n
 * The registered callback functions are unregistered. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_dtc_stop_imu_error_state_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_notify_imu_error_state_cb_t callback
);

/**
 * @brief \~japanese DCM異常（内部Gセンサ異常）状態を取得する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [out] state       状態の格納先への参照
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に取得できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 state がNULLの場合
 * @retval DCMPF_API_STATUS_FAILED           取得に失敗した場合
 *
 * @details
 * DCM異常（内部Gセンサ異常）状態を取得する。 @n
 * @n
 * 戻り値が DCMPF_API_STATUS_SUCCESS 以外の場合、 state の内容を参照しないこと。 @n
 *
 *
 * @brief \~english Get the DCM Malfunction state (IMU error)
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [out] state       Reference to the DCM Malfunction state (IMU error)
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If status is successfully obtained
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument state is NULL
 * @retval DCMPF_API_STATUS_FAILED           If acquisition fails
 *
 * @details
 * Get the DCM Malfunction state (IMU error). @n
 * @n
 * If the return value is other than DCMPF_API_STATUS_SUCCESS, do not refer to the contents of state. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_dtc_get_imu_error_state(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_dcm_malfunction_state_t* state
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_DTC_P_H */
