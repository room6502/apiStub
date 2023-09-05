/**
 * @file apiMonitor_common.h
 * @copyright Copyright (c) 2023 DENSO CORPORATION All Rights Reserved.
 *
 */

#ifndef APIMONITOR_COMMON_H
#define APIMONITOR_COMMON_H

#include <linux/limits.h>
#include <sys/time.h>
#include <sys/resource.h>

#include <dcmpf/common/libdcmpf_error.h>

#define API_MONITOR_UDP_MAX_DATA_SIZE 65507
#define API_MONITOR_IN_PARAM_MAX_SIZE 65507
#define API_MONITOR_OUT_PARAM_MAX_SIZE 65507
#define API_MONITOR_RET_VALUE_MAX_SIZE 256
#define API_MONITOR_STRUCT_MAX_LENGTH 65507
#define API_MONITOR_STRING_MAX_LENGTH 1024
#define API_MONITOR_MAX_LOG_TIME_LENGTH 27
#define API_MONITOR_MAX_LOG_PROCESS_NAME_LENGTH ARG_MAX
#define API_MONITOR_MAX_CALLBACK_COUNT 100

extern const char *apiMonitor_get_name_dcmpf_api_status(dcmpf_api_status_t ret);
extern const char *apiMonitor_get_name_dcmpf_result(dcmpf_result_t ret);

extern void apiMonitor_get_timestamp(char *time_str, struct timeval *time);
extern int apiMonitor_add_log(char *log_text);
extern int apiMonitor_add_in_log(struct timeval *start_timeval, char *lib_name, char *api_name, struct rusage *start, char *in_param);
extern int apiMonitor_add_out_log(struct timeval *start_timeval, char *lib_name, char *api_name, struct rusage *start, struct rusage *end, char *ret_value, char *out_param);
extern int apiMonitor_add_cb_log(char *lib_name, char *api_name, char *cb_name, char *in_param);

#endif  /* APIMONITOR_COMMON_H */
