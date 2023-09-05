/**
 * @file libdcmpf_diag_didwrt_c.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese DID書込み機能モジュール(定数宣言)
 * @brief \~english Write DID feature module (constant definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_DIDWRT_C_H
#define LIBDCMPF_DIAG_DIDWRT_C_H
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
 * @brief \~japanese 書込み可否
 * @brief \~english Writability check result
 */
typedef enum {
    /**
     * @brief \~japanese 書込み可
     * @brief \~english Writable
     */
    DCMPF_DIAG_DIDWRT_WRITABLE,
    /**
     * @brief \~japanese 書込み不可
     * @brief \~english Not writable
     */
    DCMPF_DIAG_DIDWRT_NOT_WRITABLE,
} dcmpf_diag_didwrt_writable_t;

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_DIDWRT_C_H */
