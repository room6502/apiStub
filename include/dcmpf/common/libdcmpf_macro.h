
/**
 * @file libdcmpf_macro.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 *
 * @brief \~japanese DCM PF共通定義(マクロ定義)
 * @brief \~english DCM PF common definition (macro definition)
 *
 */
#ifndef LIBDCMPF_MACRO_H
#define LIBDCMPF_MACRO_H

/**
 * \~japanese @addtogroup dcmpf DCM PF共通
 * \~english  @addtogroup dcmpf DCM PF common
 * \~ @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese    ポインタを暗号化する
 * 
 * @warning 現在は暗号・復号化処理は未サポート @n
 * 指定されたポインタを返却する
 * 
 * @brief \~english     Encrypt the specified pointer
 * 
 * @warning Currently not supported for encryption/decryption processing. @n
 * Return the specified pointer.
 * 
 */
#define DCMPF_ENCODE_POINTER(pf) (pf)
/**
 * @brief \~japanese    @ref DCMPF_ENCODE_POINTER により暗号化されたポインタを復号化する
 * 
 * @warning 現在は暗号・復号化処理は未サポート @n
 * 指定されたポインタを返却する
 * 
 * @brief \~english     Decrypt pointer encrypted by @ref DCMPF_ENCODE_POINTER
 * 
 * @warning Currently not supported for encryption/decryption processing. @n
 * Return the specified pointer.
 * 
 */
#define DCMPF_DECODE_POINTER(epf) (epf)


#ifdef __cplusplus
}
#endif
/** @} */
#endif	/* LIBDCMPF_MACRO_H */
