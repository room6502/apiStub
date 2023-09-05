/**
 * @file libdcmpf_diag_ioctrl_p.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese IOコントロール機能モジュール(プロトタイプ宣言)
 * @brief \~english IO Control feature module (prototype definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_IOCTRL_P_H
#define LIBDCMPF_DIAG_IOCTRL_P_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/ioctrl/libdcmpf_diag_ioctrl_c.h>
#include <dcmpf/diag/ioctrl/libdcmpf_diag_ioctrl_s.h>

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
 * @brief \~japanese IOコントロールの関数を登録する
 * 
 * @param [in] handle                   @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] did                      対象のDID
 * @param [in] short_term_ajustment     IOコントロールの開始時に呼び出されるコールバック関数 @n
 *                                      [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                                      @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 * @param [in] return_control_to_ecu    IOコントロールの終了時に呼び出されるコールバック関数 @n
 *                                      [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                                      @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に登録できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 short_term_ajustment がNULLの場合 @n
 *                                           引数 return_control_to_ecu がNULLの場合
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    指定コンテキストハンドルからの非同期API呼び出し数が規定数を超えた場合
 * @retval DCMPF_API_STATUS_FAILED           コールバック関数の登録に失敗した場合
 *
 * @details
 * IOコントロールに必要な関数を登録する。 @n
 * ダイアグツールからの要求を受信すると、登録時のDIDに紐づくコールバック関数が呼び出される。 @n
 * コールバック関数を呼び出す際、order_noを生成して呼び出す。 @n
 * @n
 * 登録を解除する場合は、 dcmpf_diag_ioctrl_unregister_io_control_oprtation() を呼び出し解除する。 @n
 * 既に指定されたコールバック関数への通知が開始している状態でこのAPIを呼び出した場合 @ref DCMPF_API_STATUS_SUCCESS を返す。 @n
 *
 *
 * @brief \~english Registers a function for IO Control.
 *
 * @param [in] handle                   Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] did                      DID
 * @param [in] short_term_ajustment     Callback function called at the beginning of the IO control @n
 *                                      As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                                      specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @param [in] return_control_to_ecu    Callback function called on exit of IO control @n
 *                                      As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                                      specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the registration is successful
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid
 *                                           If the argument short_term_ajustment is NULL
 *                                           If the argument return_control_to_ecu is NULL
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the number of asynchronous API calls from the specified context handle exceeds the specified number
 * @retval DCMPF_API_STATUS_FAILED           If the registration is failed
 *
 * @details
 * Register the functions required for the IO control. @n
 * When a request from the diagnostic tool is received, a callback function associated with the DID at the time of registration is called. @n
 * When calling the callback function, generate and call order_no. @n
 * @n
 * If it want to cancel the registration, you can cancel the call to dcmpf_diag_ioctrl_unregister_io_control_oprtation() . @n
 * If this API is called while notification to the specified callback function has already started, @ref DCMPF_API_STATUS_SUCCESS is returned. @n
 *
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_ioctrl_register_io_control_oprtation(
    dcmpf_handle_t handle,
    uint16_t did,
    dcmpf_diag_ioctrl_request_short_term_ajustment_cb_t short_term_ajustment,
    dcmpf_diag_ioctrl_request_return_control_to_ecu_cb_t return_control_to_ecu
);

/**
 * @brief \~japanese IOコントロールの関数を登録解除する
 * 
 * @param [in] handle                   @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] did                      対象のDID
 * @param [in] short_term_ajustment     IOコントロールの開始時に呼びされるコールバック関数 @n
 *                                      [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                                      @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 * @param [in] return_control_to_ecu    IOコントロールの終了時に呼び出されるコールバック関数 @n
 *                                      [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                                      @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に解除できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 check_writable がNULLの場合
 *                                           引数 write_data がNULLの場合
 * @retval DCMPF_API_STATUS_NO_SUCH          @ref dcmpf_diag_ioctrl_register_io_control_oprtation() によりコールバック関数が登録されていない場合
 * @retval DCMPF_API_STATUS_FAILED           解除に失敗した場合
 *
 * @details
 * IOコントロールに必要な関数を登録解除する。 @n
 * @n
 *
 *
 *
 * @brief \~english Unregisters a function for IO control.
 *
 * @param [in] handle                   Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] did                      DID
 * @param [in] short_term_ajustment     Callback function called at the beginning of the IO control @n
 *                                      As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                                      specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @param [in] return_control_to_ecu    Callback function called on exit of IO control @n
 *                                      As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                                      specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @retval DCMPF_API_STATUS_SUCCESS          If the unregistration was successful normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid
 *                                           If the argument check_writable is NULL
 *                                           If the argument write_data is NULL
 * @retval DCMPF_API_STATUS_NO_SUCH          If the callback function is not registered using @ref dcmpf_diag_ioctrl_register_io_control_oprtation()
 * @retval DCMPF_API_STATUS_FAILED           If the unregistration fails
 *
 * @details
 * Unregister functions required for IO Control. @n
 * @n
 * 
* @n
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_ioctrl_unregister_io_control_oprtation(
    dcmpf_handle_t handle,
    uint16_t did,
    dcmpf_diag_ioctrl_request_short_term_ajustment_cb_t short_term_ajustment,
    dcmpf_diag_ioctrl_request_return_control_to_ecu_cb_t return_control_to_ecu
);

/**
 * @brief \~japanese IOコントロールの調整結果を応答する
 * 
 * @param [in] handle               @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] order_no             要求時に受け取った order_no を設定する
 * @param [in] result               結果
 * @param [in] control_state        応答するcontrolState
 * @param [in] control_state_length control_stateの長さ
 * @param [in] error_code           制御が失敗の時に通知するネガティブレスポンスコード
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に結果を受け取った場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 order_no が不正の場合 @n
 *                                           引数 result が不正の場合 @n
 *                                           引数 control_state_length が不正の場合 @n
 *                                           引数 error_code が不正の場合 @n
 * @retval DCMPF_API_STATUS_FAILED           その他の理由で結果が受け取れなかった場合
 *
 * @details
 * IOコントロールの調整結果を応答する。 @n
 * @n
 * 確認時に生成したorder_noと、渡されたorder_noが一致した時、正常な応答として処理を行う。 @n
 * 送信すべきcontrolStateがない場合、control_stateにはNULL、control_state_lengthは0を設定すること。 @n
 * 結果が成功の場合、control_stateの内容を肯定応答する。 @n
 * 結果が失敗の場合、指定された error_code で応答する。 @n
 * @n
 *
 * @brief \~english Respond to IO control adjustment results.
 *
 * @param [in] handle               Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] order_no             Sets the "order_no" received on request
 * @param [in] result               Result
 * @param [in] control_state        controlState to response
 * @param [in] control_state_length control_state length
 * @param [in] error_code           Negative response code to notify when result fails
 * @retval DCMPF_API_STATUS_SUCCESS          Upon successful receipt of the result normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument order_no is invalid @n
 *                                           If the argument result is invalid @n
 *                                           If the argument control_state_length is invalid @n
 *                                           If the argument error_code is invalid @n
 * @retval DCMPF_API_STATUS_FAILED           Failure to receive results for any other reason
 *
 * @details
 * Respond to IO control adjustment results. @n
 * @n
 * When the order_no generated at the writable check matches the order_no passed, processing is performed as a normal response. @n
 * If there is no controlState to send, control_state should be set to NULL and control_state_length to 0. @n
 * If the result is successful, acknowledge the contents of control_state. @n
 * If the result is a failure, respond with the specified error_code. @n
 * @n
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_ioctrl_report_short_term_ajustment(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_result_t result,
    const uint8_t* control_state,
    uint16_t control_state_length,
    dcmpf_diag_nrc_t error_code
);

/**
 * @brief \~japanese IOコントロールの終了結果を応答する
 * 
 * @param [in] handle               @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] order_no             要求時に受け取った order_no を設定する
 * @param [in] result               結果
 * @param [in] control_state        応答するcontrolState
 * @param [in] control_state_length control_stateの長さ
 * @param [in] error_code           制御が失敗の時に通知するネガティブレスポンスコード
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に結果を受け取った場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 order_no が不正の場合 @n
 *                                           引数 result が不正の場合 @n
 *                                           引数 control_state_length が不正の場合 @n
 *                                           引数 error_code が不正の場合 @n
 * @retval DCMPF_API_STATUS_FAILED           その他の理由で結果が受け取れなかった場合
 *
 * @details
 * IOコントロールの調整結果を応答する。 @n
 * @n
 * 確認時に生成したorder_noと、渡されたorder_noが一致した時、正常な応答として処理を行う。 @n
 * 送信すべきcontrolStateがない場合、control_stateにはNULL、control_state_lengthは0を設定すること。 @n
 * 結果が成功の場合、control_stateの内容を肯定応答する。 @n
 * 結果が失敗の場合、指定された error_code で応答する。 @n
 * @n
 *
 * @brief \~english Respond to the end result of the IO control.
 *
 * @param [in] handle               Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] order_no             Sets the "order_no" received on request
 * @param [in] result               Result
 * @param [in] control_state        controlState to response
 * @param [in] control_state_length control_state length
 * @param [in] error_code           Negative response code to notify when result fails
 * @retval DCMPF_API_STATUS_SUCCESS          Upon successful receipt of the result normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument order_no is invalid @n
 *                                           If the argument result is invalid @n
 *                                           If the argument control_state_length is invalid @n
 *                                           If the argument error_code is invalid @n
 * @retval DCMPF_API_STATUS_FAILED           Failure to receive results for any other reason
 *
 * @details
 * Respond to the end result of the IO control. @n
 * @n
 * When the order_no generated at the writable check matches the order_no passed, processing is performed as a normal response. @n
 * If there is no controlState to send, control_state should be set to NULL and control_state_length to 0. @n
 * If the result is successful, acknowledge the contents of control_state. @n
 * If the result is a failure, respond with the specified error_code. @n
 * @n
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_ioctrl_report_return_control_to_ecu(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_result_t result,
    const uint8_t* control_state,
    uint16_t control_state_length,
    dcmpf_diag_nrc_t error_code
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_IOCTRL_P_H */
