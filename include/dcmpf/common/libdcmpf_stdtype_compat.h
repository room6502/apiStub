/**
 * @file libdcmpf_stdtype_compat.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 *
 * @brief \~japanese C99 標準型互換定義(型定義)
 * @brief \~english C99 standard type compatibility definition (type definition)
 * 
 */
#ifndef LIBDCMPF_STDTYPE_COMPAT_H
#define LIBDCMPF_STDTYPE_COMPAT_H

/**
 * \~japanese @addtogroup dcmpf DCM PF共通
 * \~english  @addtogroup dcmpf DCM PF common
 * \~ @{
 */
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#include <stdint.h>
#include <stdbool.h>
#else
#ifdef __cplusplus
extern "C" {
#endif

#ifndef __cplusplus

#if __has_include(<stdint.h>)
#include <stdint.h>
#else
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef signed long int int64_t;
typedef unsigned long int uint64_t;
#endif

#else

#if __has_include(<cstdint>)
#include <cstdint>
#else
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef signed long int int64_t;
typedef unsigned long int uint64_t;
#endif

#endif

#ifndef __cplusplus

#if __has_include(<stdbool.h>)
#include <stdbool.h>
#else
typedef enum {
    false = ( 1 == 0 ),
    true = ( ! false )
} bool;
#endif

#endif

#ifdef __cplusplus
}
#endif
#endif
/** @} */
#endif	/* LIBDCMPF_STDTYPE_COMPAT_H */
