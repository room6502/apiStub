/**
 * @file apiMonitor_parse_primitive.h
 * @copyright Copyright (c) 2023 DENSO CORPORATION All Rights Reserved.
 *
 */

#ifndef APIMONITOR_PARSE_PRIMITIVE_H
#define APIMONITOR_PARSE_PRIMITIVE_H

#include <stdbool.h>
#include <stddef.h>
#include <netinet/in.h>
#include <time.h>

extern int parse_apiMonitor_addr(char* text, int max_len, const void* addr);
extern int parse_char_p_ascii(char *text, int max_len, const char *p, int len);
extern int parse_unsigned_char_p_ascii(char *text, int max_len, const unsigned char *p, int len);
extern int parse_unsigned_char_p_hex(char *text, int max_len, const unsigned char *p, int size);
extern int parse_bool(char *text, int max_len, bool value);
extern int parse_char(char *text, int max_len, char value);
extern int parse_unsigned_char(char *text, int max_len, unsigned char value);
extern int parse_short(char *text, int max_len, short value);
extern int parse_unsigned_short(char *text, int max_len, unsigned short value);
extern int parse_int(char *text, int max_len, int value);
extern int parse_unsigned_int(char *text, int max_len, unsigned int value);
extern int parse_long(char *text, int max_len, long value);
extern int parse_unsigned_long(char *text, int max_len, unsigned long value);
extern int parse_float(char *text, int max_len, float value);
extern int parse_double(char *text, int max_len, double value);
extern int parse_time_t(char *text, int max_len, time_t value);
extern int parse_size_t(char *text, int max_len, size_t value);
extern int parse_in_port_t(char *text, int max_len, in_port_t value);
extern int parse_pid_t(char *text, int max_len, pid_t value);

#endif  /* APIMONITOR_PARSE_PRIMITIVE_H */