/**
 * @file libdcmpf_diag_didrd_c.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese DID読出し機能モジュール(定数宣言)
 * @brief \~english Read DID feature module (constant definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_DIDRD_C_H
#define LIBDCMPF_DIAG_DIDRD_C_H
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
 * @brief \~japanese 読出し可否
 * @brief \~english Readability check result
 */
typedef enum {
    /**
     * @brief \~japanese 読出し可
     * @brief \~english Readable
     */
    DCMPF_DIAG_DIDRD_READABLE,
    /**
     * @brief \~japanese 読出し不可
     * @brief \~english Not readable
     */
    DCMPF_DIAG_DIDRD_NOT_READABLE,
} dcmpf_diag_didrd_readable_t;

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_DIDRD_C_H */
