
/**
 * @file libdcmpf_type.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 *
 * @brief \~japanese DCM PF共通定義(型定義)
 * @brief \~english DCM PF common definition (type definition)
 * 
 */
#ifndef LIBDCMPF_TYPE_H
#define LIBDCMPF_TYPE_H

#include <dcmpf/common/libdcmpf_stdtype_compat.h>
#include <dcmpf/common/libdcmpf_error.h>
/**
 * \~japanese @addtogroup dcmpf DCM PF共通
 * \~english  @addtogroup dcmpf DCM PF common
 * \~ @{
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * 
 * @brief \~japanese コンテキストハンドル実体
 * 
 * @brief \~english Context handle implementation
 */
typedef struct {
    /**
     * 
     * @brief \~japanese ハンドル
     * 
     * @brief \~english handle
     */
    uint16_t m_handle;
    /**
     *
     * @brief \~japanese コンテキストで管理するデータへの参照
     *
     * @brief \~english reference to data managed in context
     */
    void* const data;
} dcmpf_handle_impl_t;

/**
 * @brief \~japanese コンテキストハンドル
 * 
 * @brief \~english Context handle
 */
typedef dcmpf_handle_impl_t *dcmpf_handle_t;

/**
 * @brief \~japanese 処理結果通知コールバック関数ポインタ定義
 * @param [in] handle 要求時に指定したコンテキストハンドル
 * @param [in] result 処理結果コード @n
 *                    @ref dcmpf_result_t を参照
 * 
 * @details
 * 各非同期APIに対する処理結果を通知するコールバック関数である。 @n
 * resultに要求に対する処理結果が格納される。 @n
 * 格納される処理結果コードについては、本コールバック関数を使用するAPIの解説を参照すること。
 * 
 * @brief \~english callback function pointer definition to notify of the result of operation
 * @param [in] handle Context handle specified on request
 * @param [in] result result code @n
 *                    Refer to @ref dcmpf_result_t
 * 
 * @details
 * Callback function to notify the result of asynchronous APIs @n
 * Operation result shall be set in "result" @n
 * Refer to API definition of each callback function for more detail of result codes.
 */
typedef void (*dcmpf_operation_result_cb_t)(
    dcmpf_handle_t handle,
    dcmpf_result_t result
);

typedef uint8_t UINT8;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef uint64_t UINT64;
typedef int8_t SINT8;
typedef int16_t SINT16;
typedef int32_t SINT32;
typedef int64_t SINT64;
typedef float FLOAT32;
typedef double FLOAT64;
typedef UINT8* STRING;
typedef UINT8 UINT8DYN;

#ifdef __cplusplus
}
#endif
/** @} */
#endif	/* LIBDCMPF_TYPE_H */
