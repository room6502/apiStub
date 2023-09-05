/**
 * @file libdcmpf_diag_didwrt_p.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese DID書込み機能モジュール(プロトタイプ宣言)
 * @brief \~english Write DID feature module (prototype definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_DIDWRT_P_H
#define LIBDCMPF_DIAG_DIDWRT_P_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/didwrt/libdcmpf_diag_didwrt_c.h>
#include <dcmpf/diag/didwrt/libdcmpf_diag_didwrt_s.h>

/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_didwrt DID書込み機能モジュール
 * \~english  @addtogroup dcmpf_diag_didwrt Write DID feature module
 * \~ @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese DID書込みの関数を登録する
 * 
 * @param [in] handle          @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] did             対象のDID
 * @param [in] check_writable  書込み可能か確認時に呼び出されるコールバック関数 @n
 *                             [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                             @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 * @param [in] write_data      書込み要求時に呼び出されるコールバック関数 @n
 *                             [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                             @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に登録できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 check_writable がNULLの場合 @n
 *                                           引数 write_data がNULLの場合
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    指定コンテキストハンドルからの非同期API呼び出し数が規定数を超えた場合
 * @retval DCMPF_API_STATUS_FAILED           コールバック関数の登録に失敗した場合
 *
 * @details
 * DID書込みに必要な関数を登録する。 @n
 * ダイアグツールからの要求を受信すると、登録時のDIDに紐づくコールバック関数が呼び出される。 @n
 * コールバック関数を呼び出す際、order_noを生成して呼び出す。 @n
 * @n
 * 登録を解除する場合は、 dcmpf_diag_didwrt_unregister_write_operation() を呼び出し解除する。 @n
 * 既に指定されたコールバック関数への通知が開始している状態でこのAPIを呼び出した場合 @ref DCMPF_API_STATUS_SUCCESS を返す。 @n
 *
 *
 * @brief \~english Registers a function for DID writing.
 *
 * @param [in] handle          Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] did             DID
 * @param [in] check_writable  Callback function called to check writability @n
 *                             As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                             specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @param [in] write_data       Callback function called on write request @n
 *                             As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                             specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the registration is successful
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid
 *                                           If the argument check_writable is NULL
 *                                           If the argument write_data is NULL
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the number of asynchronous API calls from the specified context handle exceeds the specified number
 * @retval DCMPF_API_STATUS_FAILED           If the registration is failed
 *
 * @details
 * Registers a function to check if the DID can be write. @n
 * When a request from the diagnostic tool is received, a callback function associated with the DID at the time of registration is called. @n
 * When calling the callback function, generate and call order_no. @n
 * @n
 * If it want to cancel the registration, you can cancel the call to dcmpf_diag_didwrt_unregister_write_operation() . @n
 * If this API is called while notification to the specified callback function has already started, @ref DCMPF_API_STATUS_SUCCESS is returned. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_didwrt_register_write_operation(
    dcmpf_handle_t handle,
    uint16_t did,
    dcmpf_diag_didwrt_request_check_writable_cb_t check_writable,
    dcmpf_diag_didwrt_request_write_data_cb_t write_data
);

/**
 * @brief \~japanese DID書込みの関数を登録解除する
 * 
 * @param [in] handle          @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] did             対象のDID
 * @param [in] check_writable  書込み可能か確認時に呼び出されるコールバック関数 @n
 *                             [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                             @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 * @param [in] write_data      書込み要求時に呼び出されるコールバック関数 @n
 *                             [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                             @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に解除できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 check_writable がNULLの場合
 *                                           引数 write_data がNULLの場合
 * @retval DCMPF_API_STATUS_NO_SUCH          @ref dcmpf_diag_didwrt_register_write_operation() によりコールバック関数が登録されていない場合
 * @retval DCMPF_API_STATUS_FAILED           解除に失敗した場合
 *
 * @details
 * DID書込みに必要な関数を登録解除する。 @n
 * @n
 *
 *
 * @brief \~english Unregisters a function for DID writing.
 *
 * @param [in] handle          Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] did             DID to check
 * @param [in] check_writable  Callback function called to check writability @n
 *                             As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                             specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @param [in] write_data       Callback function called on write request @n
 *                             As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                             specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @retval DCMPF_API_STATUS_SUCCESS          If the unregistration was successful normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid
 *                                           If the argument check_writable is NULL
 *                                           If the argument write_data is NULL
 * @retval DCMPF_API_STATUS_NO_SUCH          If the callback function is not registered using @ref dcmpf_diag_didwrt_register_write_operation()
 * @retval DCMPF_API_STATUS_FAILED           If the unregistration fails
 *
 * @details
 * Unregister functions required for DID writing. @n
 * @n
 * 
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_didwrt_unregister_write_operation(
    dcmpf_handle_t handle,
    uint16_t did,
    dcmpf_diag_didwrt_request_check_writable_cb_t check_writable,
    dcmpf_diag_didwrt_request_write_data_cb_t write_data
);

/**
 * @brief \~japanese 確認結果を応答する
 * 
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] order_no     要求時に受け取った order_no を設定する
 * @param [in] result       確認結果
 * @param [in] error_code   書込み不可の時に通知するネガティブレスポンスコード
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に結果を受け取った場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 order_no が不正の場合 @n
 *                                           引数 result が不正の場合 @n
 *                                           引数 error_code が不正の場合 @n
 * @retval DCMPF_API_STATUS_FAILED           その他の理由で結果が受け取れなかった場合
 *
 * @details
 * 書込み可能か確認した結果を応答する。 @n
 * @n
 * 確認時に生成したorder_noと、渡されたorder_noが一致した時、正常な応答として処理を行う。 @n
 * 結果が書込み可能の場合、DIDの書込みを行う。 @n
 * 結果が書込み不可能の場合、指定された error_code で応答する。 @n
 * @n
 *
 * @brief \~english Responds to the result of checking whether it can be write.
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] order_no     Sets the "order_no" received on request
 * @param [in] result       Check result
 * @param [in] error_code   Negative response code to notify when check result is not writable
 * @retval DCMPF_API_STATUS_SUCCESS          Upon successful receipt of the result
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument order_no is invalid @n
 *                                           If the argument result is invalid @n
 *                                           If the argument error_code is invalid @n
 * @retval DCMPF_API_STATUS_FAILED           Failure to receive results for any other reason
 *
 * @details
 * Responds to the result of checking whether it can be write. @n
 * @n
 * When the order_no generated at the writable check matches the order_no passed, processing is performed as a normal response. @n
 * If the result is writable, the DID is write. @n
 * If the result is a failure, response is made with the specified error_code. @n
 * @n
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_didwrt_report_check_writable(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_didwrt_writable_t result,
    dcmpf_diag_nrc_t error_code
);

/**
 * @brief \~japanese 書込み結果を応答する
 * 
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] order_no     要求時に受け取った order_no を設定する
 * @param [in] result       書込み結果
 * @param [in] error_code   書込み結果が失敗の時に通知するネガティブレスポンスコード
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に結果を受け取った場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 order_no が不正の場合 @n
 *                                           引数 result が不正の場合 @n
 *                                           引数 error_code が不正の場合 @n
 * @retval DCMPF_API_STATUS_FAILED           その他の理由で結果が受け取れなかった場合
 *
 * @details
 * 書込み結果を応答する。 @n
 * @n
 * 確認時に生成したorder_noと、渡されたorder_noが一致した時、正常な応答として処理を行う。 @n
 * 結果が成功の場合、肯定応答する。 @n
 * 結果が失敗の場合、指定された error_code で応答する。 @n
 * @n
 *
 * @brief \~english Notify the write result.
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] order_no     Sets the "order_no" received on request
 * @param [in] result       Write result
 * @param [in] error_code   Negative response code to notify when write result fails
 * @retval DCMPF_API_STATUS_SUCCESS          Upon successful receipt of the result normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument order_no is invalid @n
 *                                           If the argument result is invalid @n
 *                                           If the argument error_code is invalid @n
 * @retval DCMPF_API_STATUS_FAILED           Failure to receive results for any other reason
 *
 * @details
 * Notify the write result. @n
 * @n
 * When the order_no generated at the writable check matches the order_no passed, processing is performed as a normal response. @n
 * If the result is successful, an acknowledgement is given. @n
 * If the result is a failure, respond with the specified error_code. @n
 * @n
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_didwrt_report_write_data(
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
#endif	/* LIBDCMPF_DIAG_DIDWRT_P_H */
