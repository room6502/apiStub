/**
 * @file libdcmpf_diag_rtnctrl_p.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese ルーチンコントロール機能モジュール(プロトタイプ宣言)
 * @brief \~english Routine control feature module (prototype definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_RTNCTRL_P_H
#define LIBDCMPF_DIAG_RTNCTRL_P_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/rtnctrl/libdcmpf_diag_rtnctrl_c.h>
#include <dcmpf/diag/rtnctrl/libdcmpf_diag_rtnctrl_s.h>

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
 * @brief \~japanese ルーチンコントロールの関数を登録する
 * 
 * @param [in] handle          @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] rid             対象のRID
 * @param [in] routine_start   ルーチン開始時に呼び出されるコールバック関数 @n
 *                             [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                             @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 * @param [in] routine_stop    ルーチン停止時に呼び出されるコールバック関数 @n
 *                             [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                             @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 * @param [in] routine_result  ルーチン結果取得時に呼び出されるコールバック関数 @n
 *                             [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                             @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に登録できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 routine_start がNULLの場合 @n
 *                                           引数 routine_stop がNULLの場合 @n
 *                                           引数 routine_result がNULLの場合
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    指定コンテキストハンドルからの非同期API呼び出し数が規定数を超えた場合
 * @retval DCMPF_API_STATUS_FAILED           コールバック関数の登録に失敗した場合
 *
 * @details
 * ルーチンコントロールに必要な関数を登録する。 @n
 * ダイアグツールからの要求を受信すると、登録時のRIDに紐づくコールバック関数が呼び出される。 @n
 * コールバック関数を呼び出す際、order_noを生成して呼び出す。 @n
 * @n
 * 登録を解除する場合は、 dcmpf_diag_rtnctrl_unregister_routine_operation() を呼び出し解除する。 @n
 * 既に指定されたコールバック関数への通知が開始している状態でこのAPIを呼び出した場合 @ref DCMPF_API_STATUS_SUCCESS を返す。 @n
 *
 *
 * @brief \~english Register the functions required by the routine control.
 *
 * @param [in] handle          Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] rid             RID
 * @param [in] routine_start   Callback function called at routine start @n
 *                             As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                             specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @param [in] routine_stop    Callback function called at routine stop @n
 *                             As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                             specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @param [in] routine_result  Callback function called during routine result acquisition @n
 *                             As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                             specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the registration is successful
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument routine_start is NULL @n
 *                                           If the argument routine_stop is NULL @n
 *                                           If the argument routine_result is NULL
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the number of asynchronous API calls from the specified context handle exceeds the specified number
 * @retval DCMPF_API_STATUS_FAILED           If the registration is failed
 *
 * @details
 * Register the functions required by the routine control. @n
 * When a request from the diagnostic tool is received, a callback function associated with the RID at the time of registration is called. @n
 * When calling the callback function, generate and call order_no. @n
 * @n
 * If it want to cancel the registration, you can cancel the call to dcmpf_diag_rtnctrl_unregister_routine_operation() . @n
 * If this API is called while notification to the specified callback function has already started, @ref DCMPF_API_STATUS_SUCCESS is returned. @n
 *
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_rtnctrl_register_routine_operation(
    dcmpf_handle_t handle,
    uint16_t rid,
    dcmpf_diag_rtnctrl_request_routine_start_cb_t routine_start,
    dcmpf_diag_rtnctrl_request_routine_stop_cb_t routine_stop,
    dcmpf_diag_rtnctrl_request_routine_result_cb_t routine_result
);

/**
 * @brief \~japanese ルーチンコントロールの関数を登録解除する
 * 
 * @param [in] handle          @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] rid             対象のRID
 * @param [in] routine_start   ルーチン開始時に呼び出されるコールバック関数 @n
 *                             [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                             @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 * @param [in] routine_stop    ルーチン停止時に呼び出されるコールバック関数 @n
 *                             [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                             @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 * @param [in] routine_result  ルーチン結果取得時に呼び出されるコールバック関数 @n
 *                             [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                             @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に解除できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_NO_SUCH          @ref dcmpf_diag_rtnctrl_register_routine_operation() によりコールバック関数が登録されていない場合
 * @retval DCMPF_API_STATUS_FAILED           解除に失敗した場合
 *
 * @details
 * ルーチンコントロールに必要な関数を登録解除する。 @n
 * @n
 *
 * @n
 *
 * @brief \~english Unregister the functions required by the routine control.
 *
 * @param [in] handle          Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] rid             RID to check
 * @param [in] routine_start   Callback function called at routine start @n
 *                             As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                             specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @param [in] routine_stop    Callback function called at routine stop @n
 *                             As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                             specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @param [in] routine_result  Callback function called during routine result acquisition @n
 *                             As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                             specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @retval DCMPF_API_STATUS_SUCCESS          If the unregistration was successful normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid
 *                                           If the argument callback is NULL
 * @retval DCMPF_API_STATUS_FAILED           If the unregistration fails
 *
 * @details
 * Unregister the functions required by the routine control. @n
 * @n
 * @n
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_rtnctrl_unregister_routine_operation(
    dcmpf_handle_t handle,
    uint16_t rid,
    dcmpf_diag_rtnctrl_request_routine_start_cb_t routine_start,
    dcmpf_diag_rtnctrl_request_routine_stop_cb_t routine_stop,
    dcmpf_diag_rtnctrl_request_routine_result_cb_t routine_result
);

/**
 * @brief \~japanese ルーチンの開始結果を応答する
 * 
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] order_no     要求時に受け取った order_no を設定する
 * @param [in] result       結果
 * @param [in] data         応答データへの参照(routineInfo以降のデータ)
 * @param [in] data_length  データ長
 * @param [in] error_code   結果が失敗の時に通知するネガティブレスポンスコード
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に結果を受け取った場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 order_no が不正の場合 @n
 *                                           引数 result が不正の場合 @n
 *                                           引数 data がNULLの場合 @n
 *                                           引数 data_length が不正の場合 @n
 *                                           引数 error_code が不正の場合 @n
 * @retval DCMPF_API_STATUS_FAILED           その他の理由で結果が受け取れなかった場合
 *
 * @details
 * ルーチンの開始結果を応答する。 @n
 * @n
 * 確認時に生成したorder_noと、渡されたorder_noが一致した時、正常な応答として処理を行う。 @n
 * 結果が成功の場合、dataの内容を肯定応答する。 @n
 * 結果が失敗の場合、dataは参照せず、指定された error_code で応答する。 @n
 * @n
 *
 * @brief \~english Respond to the start of the routine
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] order_no     Sets the "order_no" received on request
 * @param [in] result       Result
 * @param [in] data         Response data(Data after routineInfo)
 * @param [in] data_length  Data length
 * @param [in] error_code   Negative response code to notify when result is fails
 * @retval DCMPF_API_STATUS_SUCCESS          Upon successful receipt of the result normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument order_no is invalid @n
 *                                           If the argument result is invalid @n
 *                                           If the argument data is NULL @n
 *                                           If the argument data_length is invalid @n
 *                                           If the argument error_code is invalid @n
 * @retval DCMPF_API_STATUS_FAILED           Failure to receive results for any other reason
 *
 * @details
 * Respond to the start of the routine. @n
 * @n
 * When the order_no generated at the writable check matches the order_no passed, processing is performed as a normal response. @n
 * If the result is successful, acknowledge the contents of data. @n
 * If the result is a failure, do not reference data and respond with the specified error_code. @n
 * @n
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_rtnctrl_report_routine_start(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_result_t result,
    const uint8_t* data,
    uint16_t data_length,
    dcmpf_diag_nrc_t error_code
);

/**
 * @brief \~japanese ルーチンの停止結果を応答する
 * 
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] order_no     要求時に受け取った order_no を設定する
 * @param [in] result       結果
 * @param [in] data         応答データへの参照(routineInfo以降のデータ)
 * @param [in] data_length  データ長
 * @param [in] error_code   結果が失敗の時に通知するネガティブレスポンスコード
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に結果を受け取った場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 order_no が不正の場合 @n
 *                                           引数 result が不正の場合 @n
 *                                           引数 data がNULLの場合 @n
 *                                           引数 data_length が不正の場合 @n
 *                                           引数 error_code が不正の場合 @n
 * @retval DCMPF_API_STATUS_FAILED           その他の理由で結果が受け取れなかった場合
 *
 * @details
 * ルーチンの停止結果を応答する。 @n
 * @n
 * 確認時に生成したorder_noと、渡されたorder_noが一致した時、正常な応答として処理を行う。 @n
 * 結果が成功の場合、dataの内容を肯定応答する。 @n
 * 結果が失敗の場合、指定された error_code で応答する。 @n
 * @n
 *
 * @brief \~english Respond to the stop of the routine
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] order_no     Sets the "order_no" received on request
 * @param [in] result       Result
 * @param [in] data         Response data(Data after routineInfo)
 * @param [in] data_length  Data length
 * @param [in] error_code   Negative response code to notify when result is fails
 * @retval DCMPF_API_STATUS_SUCCESS          Upon successful receipt of the result normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument order_no is invalid @n
 *                                           If the argument result is invalid @n
 *                                           If the argument data is NULL @n
 *                                           If the argument data_length is invalid @n
 *                                           If the argument error_code is invalid @n
 * @retval DCMPF_API_STATUS_FAILED           Failure to receive results for any other reason
 *
 * @details
 * Respond to the stop of the routine. @n
 * @n
 * When the order_no generated at the writable check matches the order_no passed, processing is performed as a normal response. @n
 * If the result is successful, acknowledge the contents of data. @n
 * If the result is a failure, respond with the specified error_code. @n
 * @n
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_rtnctrl_report_routine_stop(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_result_t result,
    const uint8_t* data,
    uint16_t data_length,
    dcmpf_diag_nrc_t error_code
);

/**
 * @brief \~japanese ルーチンの結果を応答する
 * 
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] order_no     要求時に受け取った order_no を設定する
 * @param [in] result       結果
 * @param [in] data         応答データへの参照(routineInfo以降のデータ)
 * @param [in] data_length  データ長
 * @param [in] error_code   結果が失敗の時に通知するネガティブレスポンスコード
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に結果を受け取った場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 order_no が不正の場合 @n
 *                                           引数 result が不正の場合 @n
 *                                           引数 data がNULLの場合 @n
 *                                           引数 data_length が不正の場合 @n
 *                                           引数 error_code が不正の場合 @n
 * @retval DCMPF_API_STATUS_FAILED           その他の理由で結果が受け取れなかった場合
 *
 * @details
 * ルーチンの結果を応答する。 @n
 * @n
 * 確認時に生成したorder_noと、渡されたorder_noが一致した時、正常な応答として処理を行う。 @n
 * 結果が成功の場合、dataの内容を肯定応答する。 @n
 * 結果が失敗の場合、指定された error_code で応答する。 @n
 * @n
 *
 * @brief \~english Respond to the result of the routine
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] order_no     Sets the "order_no" received on request
 * @param [in] result       Result
 * @param [in] data         Response data(Data after routineInfo)
 * @param [in] data_length  Data length
 * @param [in] error_code   Negative response code to notify when result is fails
 * @retval DCMPF_API_STATUS_SUCCESS          Upon successful receipt of the result normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument order_no is invalid @n
 *                                           If the argument result is invalid @n
 *                                           If the argument data is NULL @n
 *                                           If the argument data_length is invalid @n
 *                                           If the argument error_code is invalid @n
 * @retval DCMPF_API_STATUS_FAILED           Failure to receive results for any other reason
 *
 * @details
 * Respond to the result of the routine. @n
 * @n
 * When the order_no generated at the writable check matches the order_no passed, processing is performed as a normal response. @n
 * If the result is successful, acknowledge the contents of data. @n
 * If the result is a failure, do not reference data and respond with the specified error_code. @n
 * @n
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_rtnctrl_report_routine_result(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_result_t result,
    const uint8_t* data,
    uint16_t data_length,
    dcmpf_diag_nrc_t error_code
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_RTNCTRL_P_H */
