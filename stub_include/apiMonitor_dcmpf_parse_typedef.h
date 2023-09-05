/**
 * @file apiMonitor_dcmpf_parse_typedef.h
 * @copyright Copyright (c) 2023 DENSO CORPORATION All Rights Reserved.
 *
 */

#ifndef APIMONITOR_DCMPF_PARSE_TYPEDEF_H
#define APIMONITOR_DCMPF_PARSE_TYPEDEF_H

#include <stdint.h>
#include <dcmpf/common/libdcmpf_type.h>
#include <dcmpf/common/libdcmpf_stdtype_compat.h>
#include <dcmpf/diag/dtc/libdcmpf_diag_dtc_s.h>

extern int parse_int8_t(char *text, int max_len, int8_t value);
extern int parse_uint8_t(char *text, int max_len, uint8_t value);
extern int parse_int16_t(char *text, int max_len, int16_t value);
extern int parse_uint16_t(char *text, int max_len, uint16_t value);
extern int parse_int32_t(char *text, int max_len, int32_t value);
extern int parse_uint32_t(char *text, int max_len, uint32_t value);
extern int parse_int64_t(char *text, int max_len, int64_t value);
extern int parse_uint64_t(char *text, int max_len, uint64_t value);
extern int parse_UINT8(char *text, int max_len, UINT8 value);
extern int parse_UINT16(char *text, int max_len, UINT16 value);
extern int parse_UINT32(char *text, int max_len, UINT32 value);
extern int parse_UINT64(char *text, int max_len, UINT64 value);
extern int parse_SINT8(char *text, int max_len, SINT8 value);
extern int parse_SINT16(char *text, int max_len, SINT16 value);
extern int parse_SINT32(char *text, int max_len, SINT32 value);
extern int parse_SINT64(char *text, int max_len, SINT64 value);
extern int parse_FLOAT32(char *text, int max_len, FLOAT32 value);
extern int parse_FLOAT64(char *text, int max_len, FLOAT64 value);
extern int parse_UINT8DYN(char *text, int max_len, UINT8DYN value);
extern int parse_dcmpf_diag_dtc_status_t(char *text, int max_len, dcmpf_diag_dtc_status_t value);


#endif  /* APIMONITOR_DCMPF_PARSE_TYPEDEF_H */