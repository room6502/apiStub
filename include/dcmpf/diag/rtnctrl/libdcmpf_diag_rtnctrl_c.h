/**
 * @file libdcmpf_diag_rtnctrl_c.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese ルーチンコントロール機能モジュール(定数宣言)
 * @brief \~english Routine control feature module (constant definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_RTNCTRL_C_H
#define LIBDCMPF_DIAG_RTNCTRL_C_H
/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_rtnctrl ルーチンコントロール機能モジュール
 * \~english  @addtogroup dcmpf_diag_rtnctrl Routine control feature module
 * \~ @{
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese routineStatusRecord: 未実施
 * @brief \~english routineStatusRecord: Not Implemented
 */
#define DCMPF_DIAG_RTNCTRL_STATUS_CODE_NOT_IMPLEMENTED      (0x00)

/**
 * @brief \~japanese routineStatusRecord: 実施中
 * @brief \~english routineStatusRecord: In Progress
 */
#define DCMPF_DIAG_RTNCTRL_STATUS_CODE_IN_PROGRESS          (0x01)

/**
 * @brief \~japanese routineStatusRecord: 正常終了
 * @brief \~english routineStatusRecord: Normally Completed
 */
#define DCMPF_DIAG_RTNCTRL_STATUS_CODE_NORMALLY_COMPLETEED  (0x02)

/**
 * @brief \~japanese routineStatusRecord: 強制終了
 * @brief \~english routineStatusRecord: Forced Termination
 */
#define DCMPF_DIAG_RTNCTRL_STATUS_CODE_FORCEED_TERMINATION  (0x03)


#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_RTNCTRL_C_H */
