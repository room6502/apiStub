/**
 * @file libdcmpf_diag_ecudiag_p.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 * @brief \~japanese ECUスリープダイアグ機能モジュール(プロトタイプ宣言)
 * @brief \~english ECU Sleep Diagnostics feature module (prototype definition)
 *
 */
#ifndef LIBDCMPF_DIAG_ECUDIAG_P_H
#define LIBDCMPF_DIAG_ECUDIAG_P_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/ecudiag/libdcmpf_diag_ecudiag_c.h>
#include <dcmpf/diag/ecudiag/libdcmpf_diag_ecudiag_s.h>

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
 * @brief \~japanese 過剰ウェイクアップ検出通知コールバック関数を開始する
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
 * 過剰ウェイクアップ検出通知コールバック関数を開始する。 @n
 * @n
 * 通知開始後、過剰ウェイクアップ検出するとコールバック関数が呼び出される。 @n
 * 起動後、このAPIが呼び出されるまでの間、通知は行われない。 @n
 * 通知を停止する場合は、 dcmpf_diag_ecudiag_stop_detect_excessive_wakeup_notify() を呼び出し通知を停止する。 @n
 * 既に指定されたコールバック関数への通知が開始している状態でこのAPIを呼び出した場合 @ref DCMPF_API_STATUS_SUCCESS を返す。 @n
 *
 *
 * @brief \~english Start the excessive wake-up detection notification callback function
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
 * Start the excessive wake-up detection notification callback function. @n
 * @n
 * After the notification starts, the callback function is called every time the excessive wake-up detectes. @n
 * After startup, the change notification is not performed until this API is called. @n
 * To stop the notification, call dcmpf_diag_ecudiag_stop_detect_excessive_wakeup_notify() to stop the notification. @n
 * If this API is called while notification to the specified callback function has already started, @ref DCMPF_API_STATUS_SUCCESS is returned. @n
 *
 */
extern dcmpf_api_status_t dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_ecudiag_notify_detect_excessive_wakeup_cb_t callback
);

/**
 * @brief \~japanese 過剰ウェイクアップ検出通知コールバック関数を停止する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] callback     解除するコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に通知停止要求が受け付けられた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_NO_SUCH          dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify() により、コールバック関数が登録されていない場合
 * @retval DCMPF_API_STATUS_FAILED           停止に失敗した場合
 *
 * @details
 * 過剰ウェイクアップ検出通知コールバック関数を停止する。 @n
 * @n
 * 登録済みコールバック関数の解除を行う。 @n
 *
 *
 * @brief \~english Stop the excessive wake-up detection notification callback function
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] callback     Callback function pointer to notify the result @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the notification stop request is successfully accepted
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument callback is NULL @n
 * @retval DCMPF_API_STATUS_NO_SUCH          If the callback function is not registered using dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify()
 * @retval DCMPF_API_STATUS_FAILED           If it fails to stop
 *
 * @details
 * Stop the excessive wake-up detection notification callback function. @n
 * @n
 * The registered callback functions are unregistered. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_ecudiag_stop_detect_excessive_wakeup_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_ecudiag_notify_detect_excessive_wakeup_cb_t callback
);

/**
 * @brief \~japanese スリープNG継続検出通知コールバック関数を開始する
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
 * スリープNG継続検出通知コールバック関数を開始する。 @n
 * @n
 * 通知開始後、スリープNG継続検出するとコールバック関数が呼び出される。 @n
 * 起動後、このAPIが呼び出されるまでの間、通知は行われない。 @n
 * 通知を停止する場合は、 dcmpf_diag_ecudiag_stop_detect_sleep_ng_continuation_notify() を呼び出し通知を停止する。 @n
 * 既に指定されたコールバック関数への通知が開始している状態でこのAPIを呼び出した場合 @ref DCMPF_API_STATUS_SUCCESS を返す。 @n
 *
 *
 * @brief \~english Start the Sleep NG Continuation Detection notification callback function
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
 * Start the Sleep NG Continuation Detection notification callback function. @n
 * @n
 * After the notification starts, the callback function is called every time the Sleep NG Continuation detectes. @n
 * After startup, the change notification is not performed until this API is called. @n
 * To stop the notification, call dcmpf_diag_ecudiag_stop_detect_sleep_ng_continuation_notify() to stop the notification. @n
 * If this API is called while notification to the specified callback function has already started, @ref DCMPF_API_STATUS_SUCCESS is returned. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_ecudiag_notify_detect_sleep_ng_continuation_cb_t callback
);

/**
 * @brief \~japanese スリープNG継続検出通知コールバック関数を停止する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] callback     解除するコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に通知停止要求が受け付けられた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_NO_SUCH          dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify() により、コールバック関数が登録されていない場合
 * @retval DCMPF_API_STATUS_FAILED           停止に失敗した場合
 *
 * @details
 * スリープNG継続検出通知コールバック関数を停止する。 @n
 * @n
 * 登録済みコールバック関数の解除を行う。 @n
 *
 *
 * @brief \~english Stop the Sleep NG Continuation Detection notification callback function
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] callback     Callback function pointer to notify the result @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the notification stop request is successfully accepted
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument callback is NULL @n
 * @retval DCMPF_API_STATUS_NO_SUCH          If the callback function is not registered using dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify()
 * @retval DCMPF_API_STATUS_FAILED           If it fails to stop
 *
 * @details
 * Stop the Sleep NG Continuation Detection notification callback function. @n
 * @n
 * The registered callback functions are unregistered. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_ecudiag_stop_detect_sleep_ng_continuation_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_ecudiag_notify_detect_sleep_ng_continuation_cb_t callback
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_ECUDIAG_P_H */
