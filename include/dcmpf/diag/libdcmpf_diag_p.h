/**
 * @file libdcmpf_diag_p.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese ダイアグ機能ライブラリ(プロトタイプ宣言)
 * @brief \~english Diagnostic feature library (prototype declaration)
 * 
 */
#ifndef LIBDCMPF_DIAG_P_H
#define LIBDCMPF_DIAG_P_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/libdcmpf_diag_c.h>
#include <dcmpf/diag/libdcmpf_diag_s.h>

/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_common ライブラリ共通
 * \~english  @addtogroup dcmpf_diag_common Library common
 * \~ @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese ダイアグ機能クライアントを使用するためのコンテキストハンドルを生成する
 *
 * @param [out] handle    コンテキストハンドルの格納先ポインタ
 * @retval DCMPF_API_STATUS_SUCCESS          生成に成功した場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLの場合
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    1プロセス内で生成可能なコンテキストハンドル数の上限を超えた場合
 * @retval DCMPF_API_STATUS_FAILED           生成に失敗した場合
 *
 * @details
 * ダイアグ機能クライアントを使用するためのコンテキストハンドルを生成する。 @n
 * @n
 * 本APIはコールする毎に新しいコンテキストハンドルを生成する。 @n
 * アプリケーションは本APIによりコンテキストハンドルを生成し、各ダイアグ機能APIの引数に指定すること。 @n
 * コンテキストハンドルはAPIコール毎に生成・解放する必要はなく、アプリケーション起動時等に一度だけ生成すればよい。 @n
 * @n
 * 戻り値が @ref DCMPF_API_STATUS_SUCCESS 以外の場合、コンテキストハンドルはNULLが格納される。 @n
 *
 * 
 * @brief \~english Create a context handle for using the Diagnostic feature client
 *
 * @param [out] handle    Context handle storage pointer
 * @retval DCMPF_API_STATUS_SUCCESS          If the create is successful
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the maximum number of context handles that can create in one process is exceeded
 * @retval DCMPF_API_STATUS_FAILED           If create fails
 *
 * @details
 * Create a context handle for using the Diagnostic feature client @n
 * @n
 * This API create a new context handle each time it is called @n
 * The application should create a context handle by this API and specify it in the argument of each Diagnostic feature API @n
 * The context handle does not need to create / release for each API call, it only need to create once when the application is started @n
 * @n
 * If the return value is other than @ref DCMPF_API_STATUS_SUCCESS, the context handle will contain NULL @n
 * 
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_control_context_create(
    dcmpf_handle_t* handle
);

/**
 * @brief\~japanese  ダイアグ機能クライアントで使用したコンテキストハンドルを解放する
 *
 * @param [in] handle    @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドルへの参照
 * @retval DCMPF_API_STATUS_SUCCESS           解放に成功した場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM     引数 handle がNULLもしくは不正の場合
 * @retval DCMPF_API_STATUS_FAILED            解放に失敗した場合
 *
 * @details
 * ダイアグ機能クライアントで使用したコンテキストハンドルを解放する。 @n
 * コンテキストハンドルの解放後、引数handleにはNULLを設定する。 @n
 * @n
 * コンテキストハンドルはアプリケーション終了時等、ダイアグ機能の利用が不要となるタイミングで解放すればよい。 @n
 * @n
 * 解放した後に再度ダイアグ機能を利用する場合は、 @ref dcmpf_diag_control_context_create() でコンテキストハンドルを生成すること。 @n
 *
 * 
 * @brief \~english Release the context handle used by the Diagnostic feature client
 *
 * @param [in] handle    Reference to context handle created by @ref dcmpf_diag_control_context_create()
 * @retval DCMPF_API_STATUS_SUCCESS           If the release is successful
 * @retval DCMPF_API_STATUS_INVALID_PARAM     If the argument handle is NULL or invalid
 * @retval DCMPF_API_STATUS_FAILED            If release fails
 *
 * @details
 * Release the context handle used by the Diagnostic feature client @n
 * After releasing the context handle, set NULL to the argument handle. @n
 * @n
 * The context handle may release when the Diagnostic feature is no longer need, such as when the application is closed @n
 * @n
 * If it want to use the In-Car Communication feature again after releasing it, use @ref dcmpf_diag_control_context_create() to create a context handle @n
 * 
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_control_context_release(
    dcmpf_handle_t* handle
);

/**
 * @brief \~japanese 要求の有効性確認関数を登録する
 * 
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] validation   確認時に呼び出されるコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に登録できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 validation がNULLの場合
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    指定コンテキストハンドルからの非同期API呼び出し数が規定数を超えた場合
 * @retval DCMPF_API_STATUS_FAILED           コールバック関数の登録に失敗した場合
 *
 * @details
 * 要求の有効性確認関数を登録する。 @n
 * @n
 * 登録を解除する場合は、 dcmpf_diag_unregister_validation() を呼び出し解除する。 @n
 * 既に指定されたコールバック関数への通知が開始している状態でこのAPIを呼び出した場合 @ref DCMPF_API_STATUS_SUCCESS を返す。 @n
 *
 *
 * @brief \~english Register the validation check function.
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] validation   Callback function called during validation checking @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the registration is successful
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid
 *                                           If the argument validation is NULL
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the number of asynchronous API calls from the specified context handle exceeds the specified number
 * @retval DCMPF_API_STATUS_FAILED           If the registration is failed
 *
 * @details
 * Register the validation check function. @n
 * @n
 * If it want to cancel the registration, you can cancel the call to dcmpf_diag_unregister_validation() . @n
 * If this API is called while notification to the specified callback function has already started, @ref DCMPF_API_STATUS_SUCCESS is returned. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_register_validation(
    dcmpf_handle_t handle,
    dcmpf_diag_request_validation_cb_t validation
);

/**
 * @brief \~japanese 要求の有効性確認関数を登録解除する
 * 
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] validation   確認時に呼び出されるコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に解除できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_NO_SUCH          @ref dcmpf_diag_register_validation() によりコールバック関数が登録されていない場合
 * @retval DCMPF_API_STATUS_FAILED           解除に失敗した場合
 *
 * @details
 * 要求の有効性確認関数を登録解除する。 @n
 * @n
 *
 *
 * @brief \~english Unregister the validation check function.
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] validation   Callback function called during validation checking @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @retval DCMPF_API_STATUS_SUCCESS          If the callback unregistration is successful normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid
 *                                           If the argument callback is NULL
 * @retval DCMPF_API_STATUS_NO_SUCH          If the callback function is not registered using @ref dcmpf_diag_register_validation()
 * @retval DCMPF_API_STATUS_FAILED           If the unregistration fails
 *
 * @details
 * Unregister the request validity check function. @n
 * @n
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_unregister_validation(
    dcmpf_handle_t handle,
    dcmpf_diag_request_validation_cb_t validation
);

/**
 * @brief \~japanese 有効性確認結果を応答する
 * 
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] order_no     要求時に受け取った order_no を設定する
 * @param [in] result       確認結果
 * @param [in] error_code   確認結果が失敗の時に通知するネガティブレスポンスコード
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に結果を受け取った場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 order_no が不正の場合 @n
 *                                           引数 result が不正の場合 @n
 *                                           引数 error_code が不正の場合 @n
 * @retval DCMPF_API_STATUS_FAILED           その他の理由で結果が受け取れなかった場合
 *
 * @details
 * 有効性確認結果を応答する。 @n
 * @n
 * 有効性確認時に生成したorder_noと、渡されたorder_noが一致した時、正常な応答として処理を行う。 @n
 * 結果が成功の場合、受信した要求を継続する。 @n
 * 結果が失敗の場合、指定された error_code で応答する。 @n
 *
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
 * Respond to the validation check results. @n
 * @n
 * When the order_no generated at the validation check matches the order_no passed, processing is performed as a normal response. @n
 * If the result is successful, continue the received request. @n
 * If the result is failure, respond with the specified error_code. @n
 * 
 */
extern dcmpf_api_status_t dcmpf_diag_report_validation(
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
#endif	/* LIBDCMPF_DIAG_P_H */
