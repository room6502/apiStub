/**
 * @file libdcmpf_diag_secaccs_c.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese セキュリティアクセス機能モジュール(定数宣言)
 * @brief \~english Security Access feature module (constant definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_SECACCS_C_H
#define LIBDCMPF_DIAG_SECACCS_C_H
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
 * @brief \~japanese Key比較結果
 * @brief \~english Key comparison result
 */
typedef enum {
    /**
     * @brief \~japanese 一致
     * @brief \~english Matched
     */
    DCMPF_DIAG_SECACCS_KEY_MATCH,
    /**
     * @brief \~japanese 不一致
     * @brief \~english Unmatched
     */
    DCMPF_DIAG_SECACCS_KEY_UNMATCH,
} dcmpf_diag_secaccs_compare_result_t;


#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_SECACCS_C_H */
