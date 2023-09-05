/* Copyright (c) 2023 DENSO CORPORATION All Rights Reserved. */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <apiMonitor_parse_primitive.h>

#include <apiMonitor_dcepf_parse_typedef.h>
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

