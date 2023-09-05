/* Copyright (c) 2023 DENSO CORPORATION All Rights Reserved. */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <apiMonitor_parse_primitive.h>

#include <apiMonitor_dcmpf_parse_typedef.h>
int parse_int8_t(char *text, int max_len, int8_t value){
    return parse_char(text, max_len, (char)value);
}

int parse_uint8_t(char *text, int max_len, uint8_t value){
    return parse_unsigned_char(text, max_len, (unsigned char)value);
}

int parse_int16_t(char *text, int max_len, int16_t value){
    return parse_short(text, max_len, (short)value);
}

int parse_uint16_t(char *text, int max_len, uint16_t value){
    return parse_unsigned_short(text, max_len, (unsigned short)value);
}

int parse_int32_t(char *text, int max_len, int32_t value){
    return parse_int(text, max_len, (int)value);
}

int parse_uint32_t(char *text, int max_len, uint32_t value){
    return parse_unsigned_int(text, max_len, (unsigned int)value);
}

int parse_int64_t(char *text, int max_len, int64_t value){
    return parse_long(text, max_len, (long)value);
}

int parse_uint64_t(char *text, int max_len, uint64_t value){
    return parse_unsigned_long(text, max_len, (unsigned long)value);
}

int parse_UINT8(char *text, int max_len, UINT8 value){
    return parse_unsigned_char(text, max_len, (unsigned char)value);
}

int parse_UINT16(char *text, int max_len, UINT16 value){
    return parse_unsigned_short(text, max_len, (unsigned short)value);
}

int parse_UINT32(char *text, int max_len, UINT32 value){
    return parse_unsigned_int(text, max_len, (unsigned int)value);
}

int parse_UINT64(char *text, int max_len, UINT64 value){
    return parse_unsigned_long(text, max_len, (unsigned long)value);
}

int parse_SINT8(char *text, int max_len, SINT8 value){
    return parse_char(text, max_len, (char)value);
}

int parse_SINT16(char *text, int max_len, SINT16 value){
    return parse_short(text, max_len, (short)value);
}

int parse_SINT32(char *text, int max_len, SINT32 value){
    return parse_int(text, max_len, (int)value);
}

int parse_SINT64(char *text, int max_len, SINT64 value){
    return parse_long(text, max_len, (long)value);
}

int parse_FLOAT32(char *text, int max_len, FLOAT32 value){
    return parse_float(text, max_len, (float)value);
}

int parse_FLOAT64(char *text, int max_len, FLOAT64 value){
    return parse_double(text, max_len, (double)value);
}

int parse_UINT8DYN(char *text, int max_len, UINT8DYN value){
    return parse_unsigned_char(text, max_len, (unsigned char)value);
}

int parse_dcmpf_diag_dtc_status_t(char *text, int max_len, dcmpf_diag_dtc_status_t value){
    return parse_unsigned_char(text, max_len, (unsigned char)value);
}

