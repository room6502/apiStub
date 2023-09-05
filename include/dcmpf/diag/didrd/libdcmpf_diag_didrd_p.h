/**
 * @file libdcmpf_diag_didrd_p.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese DID読出し機能モジュール(プロトタイプ宣言)
 * @brief \~english Read DID feature module (prototype definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_DIDRD_P_H
#define LIBDCMPF_DIAG_DIDRD_P_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/didrd/libdcmpf_diag_didrd_c.h>
#include <dcmpf/diag/didrd/libdcmpf_diag_didrd_s.h>

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
 * @brief \~japanese DID読出しの関数を登録する
 * 
 * @param [in] handle          @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] did             対象のDID
 * @param [in] check_readable  読出し可能か確認時に呼び出されるコールバック関数 @n
 *                             [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                             @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 * @param [in] read_data       読み出し要求時に呼び出されるコールバック関数 @n
 *                             [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                             @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に登録できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 check_readable がNULLの場合 @n
 *                                           引数 read_data がNULLの場合 @n
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    指定コンテキストハンドルからの非同期API呼び出し数が規定数を超えた場合
 * @retval DCMPF_API_STATUS_FAILED           コールバック関数の登録に失敗した場合
 *
 * @details
 * DID読み出しに必要な関数を登録する。 @n
 * ダイアグツールからの要求を受信すると、登録時のDIDに紐づくコールバック関数が呼び出される。 @n
 * コールバック関数を呼び出す際、order_noを生成して呼び出す。 @n
 * @n
 * 登録を解除する場合は、 dcmpf_diag_didrd_unregister_read_operation() を呼び出し解除する。 @n
 * 既に指定されたコールバック関数への通知が開始している状態でこのAPIを呼び出した場合 @ref DCMPF_API_STATUS_SUCCESS を返す。 @n
 *
 *
 * @brief \~english Registers a function for DID reading.
 *
 * @param [in] handle          Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] did             DID
 * @param [in] check_readable  callback function called to check readability @n
 *                             As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                             specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @param [in] read_data       callback function called on read request @n
 *                             As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                             specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the registration is successful
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid
 *                                           If the argument check_readable is NULL
 *                                           If the argument read_data is NULL
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the number of asynchronous API calls from the specified context handle exceeds the specified number
 * @retval DCMPF_API_STATUS_FAILED           If the registration is failed
 *
 * @details
 * Registers a function to check if the DID can be read. @n
 * When a request from the diagnostic tool is received, a callback function associated with the DID at the time of registration is called. @n
 * When calling the callback function, generate and call order_no. @n
 * @n
 * If it want to cancel the registration, you can cancel the call to dcmpf_diag_didrd_unregister_read_operation() . @n
 * If this API is called while notification to the specified callback function has already started, @ref DCMPF_API_STATUS_SUCCESS is returned. @n
 *
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_didrd_register_read_operation(
    dcmpf_handle_t handle,
    uint16_t did,
    dcmpf_diag_didrd_request_check_readable_cb_t check_readable,
    dcmpf_diag_didrd_request_read_data_cb_t read_data
);

/**
 * @brief \~japanese DID読出しの関数を登録解除する
 * 
 * @param [in] handle          @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] did             対象のDID
 * @param [in] check_readable  読出し可能か確認時に呼び出されるコールバック関数 @n
 *                             [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                             @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 * @param [in] read_data       読み出し要求時に呼び出されるコールバック関数 @n
 *                             [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                             @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に解除できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 check_readable がNULLの場合 @n
 *                                           引数 read_data がNULLの場合 @n
 * @retval DCMPF_API_STATUS_NO_SUCH          @ref dcmpf_diag_didrd_register_read_operation() によりコールバック関数が登録されていない場合
 * @retval DCMPF_API_STATUS_FAILED           解除に失敗した場合
 *
 * @details
 * DID読出しに必要な関数を登録解除する。 @n
 * @n
 *
 *
 * @brief \~english Unregisters a function for DID reading.
 *
 * @param [in] handle          Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] did             DID to check
 * @param [in] check_readable  Callback function called to check readability @n
 *                             As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                             specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @param [in] read_data       Callback function called on read request @n
 *                             As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                             specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @retval DCMPF_API_STATUS_SUCCESS          If the unregistration was successful normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid
 *                                           If the argument check_readable is NULL
 *                                           If the argument read_data is NULL
 * @retval DCMPF_API_STATUS_FAILED           If the unregistration fails
 *
 * @details
 * Unregister functions required for DID reading. @n
 * @n
 * 
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_didrd_unregister_read_operation(
    dcmpf_handle_t handle,
    uint16_t did,
    dcmpf_diag_didrd_request_check_readable_cb_t check_readable,
    dcmpf_diag_didrd_request_read_data_cb_t read_data
);

/**
 * @brief \~japanese 確認結果を応答する
 * 
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] order_no     要求時に受け取った order_no を設定する
 * @param [in] result       確認結果
 * @param [in] error_code   読出し不可の時に通知するネガティブレスポンスコード
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に結果を受け取った場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 order_no が不正の場合 @n
 *                                           引数 result が不正の場合 @n
 *                                           引数 error_code が不正の場合 @n
 * @retval DCMPF_API_STATUS_FAILED           その他の理由で結果が受け取れなかった場合
 *
 * @details
 * 読出し可能か確認した結果を応答する。 @n
 * @n
 * 確認時に生成したorder_noと、渡されたorder_noが一致した時、正常な応答として処理を行う。 @n
 * 結果が成功の場合、DIDの読出しを行う。 @n
 * 結果が失敗の場合、指定された error_code で応答する。 @n
 * @n
 *
 * @brief \~english Responds to the result of checking whether it can be read.
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] order_no     Sets the "order_no" received on request
 * @param [in] result       Check result
 * @param [in] error_code   Negative response code to notify when check result is not readable
 * @retval DCMPF_API_STATUS_SUCCESS          Upon successful receipt of the result
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument order_no is invalid @n
 *                                           If the argument result is invalid @n
 *                                           If the argument error_code is invalid @n
 * @retval DCMPF_API_STATUS_FAILED           Failure to receive results for any other reason
 *
 * @details
 * Responds to the result of checking whether it can be read. @n
 * @n
 * When the order_no generated at the readable check matches the order_no passed, processing is performed as a normal response. @n
 * If the result is successful, the DID is read. @n
 * If the result is a failure, response is made with the specified error_code. @n
 * @n
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_didrd_report_check_readable(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_didrd_readable_t result,
    dcmpf_diag_nrc_t error_code
);

/**
 * @brief \~japanese 読み出し結果を参照渡しで応答する
 * 
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] order_no     要求時に受け取った order_no を設定する
 * @param [in] result       読出し結果
 * @param [in] did          読み出したDID
 * @param [in] data         読み出したデータへの参照
 * @param [in] data_length  データ長
 * @param [in] error_code   読出し結果が失敗の時に通知するネガティブレスポンスコード
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
 * 読み出し結果を参照渡しで応答する。 @n
 * @n
 * 確認時に生成したorder_noと、渡されたorder_noが一致した時、正常な応答として処理を行う。 @n
 * 結果が成功の場合、dataを参照し、DIDの読み出し結果として応答する。 @n
 * 結果が失敗の場合、指定された error_code で応答する。 @n
 * @n
 *
 * @brief \~english Notify the read result by reference.
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] order_no     Sets the "order_no" received on request
 * @param [in] result       Readout result
 * @param [in] did          Readout DID
 * @param [in] data         Reference to the read data
 * @param [in] data_length  Data length
 * @param [in] error_code   Negative response code to notify when read result fails
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
 * Notify the read result by reference. @n
 * @n
 * When the order_no generated at the readable check matches the order_no passed, processing is performed as a normal response. @n
 * If the readout result is successful, data is referenced and a response is made as the read result of DID. @n
 * If the readout result is a failure, do not reference data and respond with the specified error_code. @n
 * @n
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_didrd_report_read_data_by_ref(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_result_t result,
    uint16_t did,
    const uint8_t* data,
    uint16_t data_length,
    dcmpf_diag_nrc_t error_code
);

/**
 * @brief \~japanese 読み出し結果をファイルパスで応答する
 * 
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] order_no     要求時に受け取った order_no を設定する
 * @param [in] result       ファイルパスの取得結果
 * @param [in] did          読み出したDID
 * @param [in] path         読み出し対象のパス（ファイル名含む）
 * @param [in] path_length  パス長(NULL終端を含まない長さ)
 * @param [in] error_code   読出し結果が失敗の時に通知するネガティブレスポンスコード
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に結果を受け取った場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 order_no が不正の場合 @n
 *                                           引数 result が不正の場合 @n
 *                                           引数 path がNULLの場合 @n
 *                                           引数 path_length が不正の場合 @n
 *                                           引数 error_code が不正の場合 @n
 * @retval DCMPF_API_STATUS_FAILED           その他の理由で結果が受け取れなかった場合
 *
 * @details
 * 読み出し結果をファイルパスで応答する。 @n
 * @n
 * 確認時に生成したorder_noと、渡されたorder_noが一致した時、正常な応答として処理を行う。 @n
 * 結果が成功の場合、指定されたファイルを参照し、読み出した内容をDIDの読み出し結果として応答する。 @n
 * 結果が失敗の場合、指定された error_code で応答する。 @n
 * @n
 *
 * @brief \~english Notify the read result by file path.
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] order_no     Sets the "order_no" received on request
 * @param [in] result       Result of obtaining the file path
 * @param [in] did          Readout DID
 * @param [in] path         File path (including file name) to be read
 * @param [in] path_length  File path length(Length without null terminations)
 * @param [in] error_code   Negative response code to notify when read result fails
 * @retval DCMPF_API_STATUS_SUCCESS          Upon successful receipt of the result normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument order_no is invalid @n
 *                                           If the argument result is invalid @n
 *                                           If the argument path is NULL @n
 *                                           If the argument path_length is invalid @n
 *                                           If the argument error_code is invalid @n
 * @retval DCMPF_API_STATUS_FAILED           Failure to receive results for any other reason
 *
 * @details
 * Notify the read result by file path. @n
 * @n
 * When the order_no generated at the readable check matches the order_no passed, processing is performed as a normal response. @n
 * If the result is successful, the specified file is referred to, and the read contents are returned as the result of reading the DID. @n
 * If the result is a failure,  respond with the specified error_code. @n
 * @n
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_didrd_report_read_data_by_file(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_result_t result,
    uint16_t did,
    const uint8_t* path,
    uint16_t path_length,
    dcmpf_diag_nrc_t error_code
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_DIDRD_P_H */
