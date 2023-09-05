/**
 * @file libdcmpf_diag_secaccs_p.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 * @brief \~japanese セキュリティアクセス機能モジュール(プロトタイプ宣言)
 * @brief \~english Security Access feature module (prototype definition)
 *
 */
#ifndef LIBDCMPF_DIAG_SECACCS_P_H
#define LIBDCMPF_DIAG_SECACCS_P_H

#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/diag/secaccs/libdcmpf_diag_secaccs_c.h>
#include <dcmpf/diag/secaccs/libdcmpf_diag_secaccs_s.h>

/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_secaccs セキュリティアクセス機能モジュール
 * \~english  @addtogroup dcmpf_diag_secaccs Security Access feature module
 * \~ @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese Seed生成とKey確認関数を登録する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] create_seed  Seed生成時に呼び出されるコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 * @param [in] compare_key  Key確認時に呼び出されるコールバック関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に登録できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 create_seed がNULLの場合
 *                                           引数 compare_key がNULLの場合
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    指定コンテキストハンドルからの非同期API呼び出し数が規定数を超えた場合
 * @retval DCMPF_API_STATUS_FAILED           コールバック関数の登録に失敗した場合
 *
 * @details
 * Seed生成とKey確認関数を登録する。 @n
 * ダイアグツールからの要求を受信すると、コールバック関数が呼び出される。 @n
 * コールバック関数を呼び出す際、order_noを生成して呼び出す。 @n
 * @n
 * 登録を解除する場合は、 dcmpf_diag_secaccs_unregister_seed_key_operation() を呼び出し解除する。 @n
 * 既に指定されたコールバック関数への通知が開始している状態でこのAPIを呼び出した場合 @ref DCMPF_API_STATUS_SUCCESS を返す。 @n
 *
 *
 * @brief \~english Registering Seed Creation and Key Comparison Functions.
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] create_seed  Callback function called during Seed creation @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @param [in] compare_key  Callback function called during Key comparison @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If the registration is successful
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid
 *                                           If the argument create_seed is NULL
 *                                           If the argument compare_key is NULL
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the number of asynchronous API calls from the specified context handle exceeds the specified number
 * @retval DCMPF_API_STATUS_FAILED           If the registration is failed
 *
 * @details
 * Registering Seed Creation and Key Comparison Functions. @n
 * The callback function is called when a request from the diagnostic tool is received. @n
 * When calling the callback function, generate and call order_no. @n
 * @n
 * If it want to cancel the registration, you can cancel the call to dcmpf_diag_secaccs_unregister_seed_key_operation() . @n
 * If this API is called while notification to the specified callback function has already started, @ref DCMPF_API_STATUS_SUCCESS is returned. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_secaccs_register_seed_key_operation(
    dcmpf_handle_t handle,
    dcmpf_diag_secaccs_request_create_seed_cb_t create_seed,
    dcmpf_diag_secaccs_request_compare_key_cb_t compare_key
);

/**
 * @brief \~japanese 前提条件確認関数を登録解除する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] create_seed  登録解除するSeed生成関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 * @param [in] compare_key  登録解除するKey比較関数 @n
 *                          [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                          @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に解除できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_NO_SUCH          @ref dcmpf_diag_secaccs_register_seed_key_operation() によりコールバック関数が登録されていない場合
 * @retval DCMPF_API_STATUS_FAILED           解除に失敗した場合
 *
 * @details
 * Seed生成とKey確認関数を登録解除する。 @n
 * @n
 * @n
 *
 * @brief \~english Unregistering Seed Creation and Key Comparison Functions.
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] create_seed  Seed creation function to unregister @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @param [in] compare_key  Key comparison function to unregister @n
 *                          As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                          specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @retval DCMPF_API_STATUS_SUCCESS          If the unregistration was successful normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid
 *                                           If the argument callback is NULL
 * @retval DCMPF_API_STATUS_NO_SUCH          If the callback function is not registered using @ref dcmpf_diag_secaccs_register_seed_key_operation()
 * @retval DCMPF_API_STATUS_FAILED           If the unregistration fails
 *
 * @details
 * Unregistering Seed Creation and Key Comparison Functions. @n
 * @n
 * @n
 *
 */
extern dcmpf_api_status_t dcmpf_diag_secaccs_unregister_seed_key_operation(
    dcmpf_handle_t handle,
    dcmpf_diag_secaccs_request_create_seed_cb_t create_seed,
    dcmpf_diag_secaccs_request_compare_key_cb_t compare_key
);

/**
 * @brief \~japanese Seed生成結果を応答する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] order_no     要求時に受け取った order_no を設定する
 * @param [in] seed         生成したSeed
 * @param [in] seed_length  seedの長さ
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に結果を受け取った場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 order_no が不正の場合 @n
 *                                           引数 seed がNULLの場合 @n
 *                                           引数 seed_length が不正の場合 @n
 * @retval DCMPF_API_STATUS_FAILED           その他の理由で結果が受け取れなかった場合
 *
 * @details
 * Seed生成結果を応答する。 @n
 * @n
 * 生成要求時に生成したorder_noと、渡されたorder_noが一致した時、正常な応答として処理を行う。 @n
 * 渡されたSeed値をダイアグツールに応答する。 @n
 * @n
 *
 * @brief \~english Respond to created Seed.
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] order_no     Sets the "order_no" received on request
 * @param [in] seed         Created Seed
 * @param [in] seed_length  Length of seed
 * @retval DCMPF_API_STATUS_SUCCESS          Upon successful receipt of the result normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument order_no is invalid @n
 *                                           If the argument seed is NULL @n
 *                                           If the argument seed_length is invalid @n
 * @retval DCMPF_API_STATUS_FAILED           Failure to receive results for any other reason
 *
 * @details
 * Respond to created Seed. @n
 * @n
 * When the order_no generated at the pre-condition check matches the order_no passed, processing is performed as a normal response. @n
 * Respond the Seed value passed to the diagnostic tool. @n
 * @n
 *
 */
extern dcmpf_api_status_t dcmpf_diag_secaccs_report_create_seed(
    dcmpf_handle_t handle,
    uint8_t order_no,
    const uint8_t* seed,
    uint8_t seed_length
);

/**
 * @brief \~japanese Key比較結果を応答する
 *
 * @param [in] handle       @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] order_no     要求時に受け取った order_no を設定する
 * @param [in] result       比較結果
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に結果を受け取った場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 order_no が不正の場合 @n
 *                                           引数 result が不正の場合 @n
 * @retval DCMPF_API_STATUS_FAILED           その他の理由で結果が受け取れなかった場合
 *
 * @details
 * Key比較結果を応答する。 @n
 * @n
 * 前提条件確認時に生成したorder_noと、渡されたorder_noが一致した時、正常な応答として処理を行う。 @n
 * 結果が成功の場合、ダイアグツールに肯定応答する。 @n
 * 結果が失敗の場合、ダイアグツールにNRC35もしくはNRC36で否定応答する。 @n
 * @n
 *
 * @brief \~english Respond to Key comparison results.
 *
 * @param [in] handle       Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] order_no     Sets the "order_no" received on request
 * @param [in] result       Check result
 * @retval DCMPF_API_STATUS_SUCCESS          Upon successful receipt of the result normally
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument order_no is invalid @n
 *                                           If the argument result is invalid @n
 *                                           If the argument error_code is invalid @n
 * @retval DCMPF_API_STATUS_FAILED           Failure to receive results for any other reason
 *
 * @details
 * Respond to Key comparison results. @n
 * @n
 * When the order_no generated at the pre-condition check matches the order_no passed, processing is performed as a normal response. @n
 * If the result is successful, the diagnostic tool is acknowledged. @n
 * If the results is a failure, a negative response is sent to the diagnostic tool with NRC0x35 or NRC0x36. @n
 * @n
 *
 */
extern dcmpf_api_status_t dcmpf_diag_secaccs_report_compare_key(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_secaccs_compare_result_t result
);

/**
 * @brief \~japanese Seedを生成する
 *
 * @param [in] handle           @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] security_level   セキュリティレベル
 * @param [out] seed            Seedの格納先への参照
 * @param [in] seed_length      seedの長さ
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に取得できた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 security_level が不正の場合 @n
 *                                           引数 seed がNULLの場合 @n
 *                                           引数 seed_length が不正の場合 @n
 * @retval DCMPF_API_STATUS_FAILED           取得に失敗した場合
 *
 * @details
 * Seedを生成する。 @n
 * @n
 * セキュリティレベルに応じた乱数生成を行い、返却する。 @n
 *
 * 戻り値が DCMPF_API_STATUS_SUCCESS 以外の場合、 seed の内容を参照しないこと。 @n
 *
 *
 * @brief \~english Create a Seed.
 *
 * @param [in] handle           Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] security_level   Security level
 * @param [out] seed            Reference to the created seed
 * @param [in] seed_length      Length of seed
 *
 * @retval DCMPF_API_STATUS_SUCCESS          If status is successfully obtained
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument security_level is invalid @n
 *                                           If the argument seed is NULL @n
 *                                           If the argument seed_length is invalid @n
 * @retval DCMPF_API_STATUS_FAILED           If acquisition fails
 *
 * @details
 * Create a Seed. @n
 * @n
 * A random number corresponding to the security level is created and returned. @n
 *
 * If the return value is other than DCMPF_API_STATUS_SUCCESS, do not refer to the contents of seed. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_secaccs_get_seed(
    dcmpf_handle_t handle,
    uint8_t security_level,
    uint8_t* seed,
    uint8_t seed_length
);

/**
 * @brief \~japanese Keyを演算する
 *
 * @param [in] handle           @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] security_level   セキュリティレベル
 * @param [in] seed             seed
 * @param [in] seed_length      seedの長さ
 * @param [in] callback         結果を通知するコールバック関数 @n
 *                              [「関数ポインタの暗号化について」]( @ref guideline_caution_encode_pointer )に記載の通り、
 *                              @ref DCMPF_ENCODE_POINTER を使用して暗号化したものを指定すること
 *
 * @retval DCMPF_API_STATUS_SUCCESS          正常に要求が受け付けられた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM    引数 handle がNULLもしくは不正の場合 @n
 *                                           引数 security_level が不正の場合 @n
 *                                           引数 seed がNULLの場合 @n
 *                                           引数 seed_length が不正の場合 @n
 *                                           引数 callback がNULLの場合
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    指定コンテキストハンドルからの非同期API呼び出し数が規定数を超えた場合
 * @retval DCMPF_API_STATUS_FAILED           要求の受付に失敗した場合
 *
 * @details
 * セキュリティレベルに応じたKeyの演算を行う。 @n
 * @n
 * 本APIは非同期で実行するため、戻り値に DCMPF_API_STATUS_SUCCESS が返却された時点では完了していない。 @n
 * callback に指定したコールバック関数からの実行結果通知により成否を判断すること。 @n
 * 成否に応じて以下の結果コードが指定される。 @n
 * @li @ref DCMPF_RESULT_SUCCESS          成功した場合
 * @li @ref DCMPF_RESULT_FAILED           失敗した場合
 * @li @ref DCMPF_RESULT_CANCEL           dcmpf_diag_secaccs_cancel_key_calculate() の呼び出しによりキャンセルされた場合
 *
 *
 * @brief \~english Calculate Key.
 *
 * @param [in] handle           Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] security_level   Security level
 * @param [in] seed             Seed
 * @param [in] seed_length      Length of seed
 * @param [in] callback         Callback function pointer to notify the result @n
 *                              As described in [ "About function pointer encryption" ]( @ref guideline_caution_encode_pointer ),
 *                              specify what was encrypted using @ref DCMPF_ENCODE_POINTER
 * @retval DCMPF_API_STATUS_SUCCESS          If the request is successfully accepted
 * @retval DCMPF_API_STATUS_INVALID_PARAM    If the argument handle is NULL or invalid @n
 *                                           If the argument security_level is invalid @n
 *                                           If the argument seed is NULL @n
 *                                           If the argument seed_length is invalid @n
 *                                           If the argument callback is NULL @n
 * @retval DCMPF_API_STATUS_OUT_OF_BOUNDS    If the number of asynchronous API calls from the specified context handle exceeds the specified number
 * @retval DCMPF_API_STATUS_FAILED           If the request is not accepted
 *
 * @details
 * Calculate the key according to the security level. @n
 * @n
 * Since this API is executed asynchronously, it is not completed when @ref DCMPF_API_STATUS_SUCCESS is returned as the return value. @n
 * To determine the success or failure by a result notification from a callback function specified in callback. @n
 * The following result codes are designated according to the success or failure. @n
 * @li @ref DCMPF_RESULT_SUCCESS          If successful
 * @li @ref DCMPF_RESULT_FAILED           If fails
 * @li @ref DCMPF_RESULT_CANCEL           If canceled by calling dcmpf_diag_secaccs_cancel_key_calculate()
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_secaccs_invoke_key_calculate(
    dcmpf_handle_t handle,
    uint8_t security_level,
    const uint8_t* seed,
    uint8_t seed_length,
    dcmpf_diag_secaccs_notify_calculate_key_cb_t callback
);

/**
 * @brief \~japanese Key演算をキャンセルする
 *
 * @param [in] handle         @ref dcmpf_diag_control_context_create() で生成したコンテキストハンドル
 * @param [in] security_level セキュリティレベル
 *
 * @retval DCMPF_API_STATUS_SUCCESS         正常にキャンセルが受け付けられた場合
 * @retval DCMPF_API_STATUS_INVALID_PARAM   引数 handle がNULLもしくは不正の場合 @n
 *                                          引数 security_level が不正の場合 @n
 * @retval DCMPF_API_STATUS_NO_SUCH         キャンセル可能な要求が無い場合
 * @retval DCMPF_API_STATUS_FAILED          キャンセルに失敗した場合
 *
 * @details
 * dcmpf_diag_secaccs_invoke_key_calculate() によるセキュリティレベルに応じたKeyの演算をキャンセルする。 @n
 * @n
 * 本APIの呼び出しと同一コンテキストハンドル、同一セキュリティレベルの要求がキャンセル対象となる。 @n
 * 呼び出し元のコンテキストハンドルが一致しない場合はキャンセルされない。 @n
 * キャンセル要求が正常に受付されたとしても、必ずしもキャンセルできるとは限らない。 @n
 * 対象処理が先に完了する場合や、 処理の進捗状況によってはキャンセルできない場合もある。 @n
 * 本APIによるキャンセルの成否は dcmpf_diag_secaccs_invoke_key_calculate() の実行結果から判断すること。 @n
 * キャンセルできた場合、実行結果には @ref DCMPF_RESULT_CANCEL が通知される。 @n
 * キャンセルできなかった場合、実行結果に応じた結果コードが通知される。 @n
 *
 *
 * @brief \~english Cancel the Key calculation.
 *
 * @param [in] handle         Context handle created by @ref dcmpf_diag_control_context_create()
 * @param [in] security_level Security level
 *
 * @retval DCMPF_API_STATUS_SUCCESS         If the cancellation request is successfully accepted
 * @retval DCMPF_API_STATUS_INVALID_PARAM   If the argument handle is NULL or invalid @n
 *                                          If the argument security_level is invalid @n
 * @retval DCMPF_API_STATUS_NO_SUCH         If there is no cancelable requisition normally
 * @retval DCMPF_API_STATUS_FAILED          If cancellation fails
 *
 * @details
 * Cancel a call from dcmpf_device_indicator_invoke_telltale_lighting_pattern_set(). @n
 * @n
 * Request with the same context handle and the same security level as this API call are canceled. @n
 * If the calling context handle does not match, it is not cancelled. @n
 * Even if the cancel request is accepted normally, it is not always possible to cancel. @n
 * In some cases, the target processing is completed first or cannot be canceled depending on the processing progress. @n
 * The success or failure of cancellation by this API should be determined from the result of executing dcmpf_diag_secaccs_invoke_key_calculate(). @n
 * If it has could be cancelled, the @ref DCMPF_RESULT_CANCEL is notified. @n
 * If it has not could be cancelled, the result code corresponding to the execution result is notified. @n
 *
 *
 */
extern dcmpf_api_status_t dcmpf_diag_secaccs_cancel_key_calculate(
    dcmpf_handle_t handle,
    uint8_t security_level
);

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_SECACCS_P_H */
