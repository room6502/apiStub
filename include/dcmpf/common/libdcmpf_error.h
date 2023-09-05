
/**
 * @file libdcmpf_error.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 * @~Japanese
 * @brief DCM PF共通定義(戻り値・ステータス)
 * @~English
 * @brief DCM PF common definition (return value and status code)
 *
 */
#ifndef LIBDCMPF_ERROR_H
#define LIBDCMPF_ERROR_H

/**
 * \~japanese @addtogroup dcmpf DCM PF共通
 * \~english  @addtogroup dcmpf DCM PF common
 * \~ @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese 結果コード
 * 
 * 本コードではアプリケーションが要求に対する結果を判断するための情報を返却する。 @n
 * 各機能ライブラリ共通使用するコードのため、結果コードを追加する場合は汎用的な定義となるよう注意すること。 @n
 * 機能固有の結果を返却する場合は、各機能毎に結果コードを定義すること。 @n
 * 
 * @brief \~english Result code
 * 
 * This code returns information for the application to determine the result of the request. @n
 * Since the code is used in common for each function library, be careful to make it a general-purpose definition when adding the result code. @n
 * When returning results which is specified for a function, define a detailed result code for each function. @n
 * 
 */
typedef enum {
     /**
     * @brief \~japanese 成功
     * @brief \~english Success
     */
	DCMPF_RESULT_SUCCESS,

    /**
     * @brief \~japanese 失敗
     * @brief \~english Failed
     */
	DCMPF_RESULT_FAILED,

    /**
     * @brief \~japanese 受付不可・処理中・競合
     * 
     * 使用例: @n
     * @li 先発要求が処理中のため後発要求が一時的に実行できない
     * 
     * @brief \~english Busy
     * 
     * Example of use: @n
     * @li The later request cannot be executed temporarily because the earlier request is being processed.
     * 
     */
	DCMPF_RESULT_BUSY,

    /**
     * @brief \~japanese 状態不正
     * 
     * 使用例: @n
     * @li 現在の状態では要求された処理は実行できない
     * 
     * @brief \~english Invalid state
     * 
     * Example of use: @n
     * @li The requested process cannot be executed in the current state.
     * 
     */
	DCMPF_RESULT_INVALID_STATE,

    /**
     * @brief \~japanese 入力パラメータ不正
     * 
     * 使用例: @n
     * @li 処理ロジック上で検出した入力値・データの不正
     * 
     * @brief \~english Invalid parameter
     * 
     * Example of use: @n
     * @li Invalid input value/data detected on processing logic.
     * 
     */
	DCMPF_RESULT_INVALID_PARAM,

    /**
     * @brief \~japanese サポートされていない操作
     * 
     * 使用例: @n
     * @li 特定のバリエーションではサポートしていない機能
     * 
     * @brief \~english Not supported operation
     * 
     * Example of use: @n
     * @li Feature not supported in certain variation.
     * 
     */
	DCMPF_RESULT_NOT_SUPPORTED,

    /**
     * @brief \~japanese アクセス拒否された場合
     * 
     * 使用例: @n
     * @li ファイルシステム等のアクセスコントロールにより参照できない
     * 
     * @brief \~english Access denied
     * 
     * Example of use: @n
     * @li Cannot be referenced due to access control such as file system
     * 
     */
    DCMPF_RESULT_ACCESS_DENIED,

    /**
     * @brief \~japanese 処理実行の準備ができていない場合
     * 
     * 使用例: @n
     * @li 起動未完了のため要求された処理が実行できない
     * 
     * @brief \~english Not ready to use
     * 
     * Example of use: @n
     * @li The requested process cannot be executed because the startup has not been completed.
     * 
     */
	DCMPF_RESULT_NOT_READY,

    /**
     * @brief \~japanese 既に登録・処理済み
     * 
     * 使用例: @n
     * @li 登録された情報・データが重複している
     * @li 排他的にリソースが占有され、指定されたリソースは現在使用されている
     * 
     * @brief \~english Already operated
     * 
     * Example of use: @n
     * @li The registered information/data is duplicated.
     * @li The resource is exclusively occupied and the specified resource is currently in use.
     * 
     */
	DCMPF_RESULT_ALREADY,

    /**
     * @brief \~japanese キャンセルされた
     * 
     * 使用例: @n
     * @li キャンセル要求により処理が中断された
     * 
     * @brief \~english Cancel
     * 
     * Example of use: @n
     * @li Processing was interrupted by a cancellation request.
     * 
     */
	DCMPF_RESULT_CANCEL,

    /**
     * @brief \~japanese 上限を超えた
     * 
     * 使用例: @n
     * @li パラメータは正常だが、登録可能な最大件数を超えている
     * 
     * @brief \~english Out of bounds
     * 
     * Example of use: @n
     * @li The parameters are normal, but the maximum number that can be registered is exceeded.
     * 
     */
	DCMPF_RESULT_OUT_OF_BOUNDS,

    /**
     * @brief \~japanese 許可されていない操作
     * 
     * 使用例: @n
     * @li DCM PF/外部モジュールが保持する情報・データの参照や更新を許可していない
     * 
     * @brief \~english Not allowed operation
     * 
     * Example of use: @n
     * @li DCM PF/External modules does not allow reference or update of information/data
     * 
     */
	DCMPF_RESULT_NOT_ALLOWED,

    /**
     * @brief \~japanese ネットワーク関連エラー
     * 
     * 使用例: @n
     * @li ネットワーク関連のエラーが発生した
     * 
     * @brief \~english Network related errors
     * 
     * Example of use: @n
     * @li Network related errors occurred.
     * 
     */
	DCMPF_RESULT_TIMEOUT
} dcmpf_result_t;

/**
 * @brief \~japanese APIの戻りコード
 * 
 * システムコールのエラーやプロセス間通信の失敗のようにDCM PF API内部エラーが発生した場合、
 * APIコールの戻り値として @ref DCMPF_API_STATUS_FAILED を返却する。 @n
 * 上記以外のアプリケーション側での対応が必要なエラーが発生した場合、
 * それぞれのエラー理由別の戻りコードを返却する。
 * 
 * @brief \~english Return code from API
 * 
 * When DCM PF API internal error occurs, such as a system call error or interprocess communication failure,
 * @ref DCMPF_API_STATUS_FAILED is returned as the return value of the API call. @n
 * If error other than the above that need to be handled by the application occurs,
 * return code for each error reason is returned.
 */
typedef enum {
    /**
     * @brief \~japanese 成功
     * @brief \~english Success
     */
	DCMPF_API_STATUS_SUCCESS,

    /**
     * @brief \~japanese 失敗
     * @brief \~english Failed
     */
	DCMPF_API_STATUS_FAILED,

    /**
     * @brief \~japanese 入力パラメータ不正
     * 
     * 使用例: @n
     * @li 引数に指定された値・データ内容が有効範囲を超えている
     * @li 省略不可の引数に指定されたポインタアドレスが NULL
     * 
     * @brief \~english Invalid parameter
     * 
     * Example of use: @n
     * @li The value/data content specified in the argument exceeds the valid range.
     * @li The pointer address specified in the optional argument is NULL.
     * 
     */
	DCMPF_API_STATUS_INVALID_PARAM,

    /**
     * @brief \~japanese 既に登録・処理済み
     * 
     * 使用例: @n
     * @li 登録された情報・データが重複している
     * @li 排他的にリソースが占有され、指定されたリソースは現在使用されている
     * 
     * @brief \~english Already operated
     * 
     * Example of use: @n
     * @li The registered information/data is duplicated.
     * @li The resource is exclusively occupied and the specified resource is currently in use.
     * 
     */
	DCMPF_API_STATUS_ALREADY,

    /**
     * @brief \~japanese 対象のオブジェクトが無い
     * 
     * 使用例: @n
     * @li キー情報やポインタなどにより指定された操作対象のオブジェクト（情報、データ)が無い
     * @li データの取り出しを指示したが、対象データが存在していない
     * 
     * @brief \~english No such target object
     * 
     * Example of use: @n
     * @li There is no object (information, data) to be operated specified by key information or pointer.
     * @li It instructed to retrieve the data, but the target data does not exist
     * 
     */
    DCMPF_API_STATUS_NO_SUCH,

    /**
     * @brief \~japanese 上限を超えた
     * 
     * 使用例: @n
     * @li パラメータは正常だが、登録可能な最大件数を超えている
     * 
     * @brief \~english Out of bounds
     * 
     * Example of use: @n
     * @li The parameters are normal, but the maximum number that can be registered is exceeded.
     * 
     */
	DCMPF_API_STATUS_OUT_OF_BOUNDS,

    /**
     * @brief \~japanese サポートされていない操作
     * 
     * 使用例: @n
     * @li 特定のバリエーションではサポートしていない機能 @n
     * ビルド時に静的にサポート可否が判別可能な場合はAPIの戻り値により返却する。 @n
     * 特定条件に依存し動的に判別される場合は、 @ref DCMPF_RESULT_NOT_SUPPORTED による応答とする。
     * 
     * @brief \~english Not supported operation
     * 
     * Example of use: @n
     * @li Feature not supported in certain variation @n
     * If it is possible to statically determine whether supported or not at build time, it will be returned as the API return value. @n
     * If it depend on a specific condition and is dynamically determined, the response should be @ref DCMPF_RESULT_NOT_SUPPORTED.
     * 
     */
	DCMPF_API_STATUS_NOT_SUPPORTED,

    /**
     * @brief \~japanese 許可されていない操作
     * 
     * 使用例: @n
     * @li DCM PF/外部モジュールが保持する情報・データの参照や更新を許可していない
     * 
     * @brief \~english Not allowed operation
     * 
     * Example of use: @n
     * @li DCM PF/External modules does not allow reference or update of information/data
     * 
     */
	DCMPF_API_STATUS_NOT_ALLOWED
} dcmpf_api_status_t;

#ifdef __cplusplus
}
#endif
/** @} */
#endif	/* LIBDCMPF_ERROR_H */
