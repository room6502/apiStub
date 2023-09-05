/**
 * @file apiMonitor_dcepf_parse_typedef.h
 * @copyright Copyright (c) 2023 DENSO CORPORATION All Rights Reserved.
 *
 */

#ifndef APIMONITOR_DCEPF_PARSE_TYPEDEF_H
#define APIMONITOR_DCEPF_PARSE_TYPEDEF_H

#include <stdint.h>
#include <dcepf/common/libdcepf_type.h>

extern int parse_int8_t(char *text, int max_len, int8_t value);
extern int parse_uint8_t(char *text, int max_len, uint8_t value);
extern int parse_int16_t(char *text, int max_len, int16_t value);
extern int parse_uint16_t(char *text, int max_len, uint16_t value);
extern int parse_int32_t(char *text, int max_len, int32_t value);
extern int parse_uint32_t(char *text, int max_len, uint32_t value);
extern int parse_int64_t(char *text, int max_len, int64_t value);
extern int parse_uint64_t(char *text, int max_len, uint64_t value);


#endif  /* APIMONITOR_DCEPF_PARSE_TYPEDEF_H */