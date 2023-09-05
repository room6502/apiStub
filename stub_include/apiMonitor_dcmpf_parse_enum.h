/**
 * @file apiMonitor_dcmpf_parse_enum.h
 * @copyright Copyright (c) 2023 DENSO CORPORATION All Rights Reserved.
 *
 */

#ifndef APIMONITOR_DCMPF_PARSE_ENUM_H
#define APIMONITOR_DCMPF_PARSE_ENUM_H

#include <dcmpf/common/libdcmpf_error.h>
#include <dcmpf/common/libdcmpf_stdtype_compat.h>
#include <dcmpf/diag/libdcmpf_diag_c.h>
#include <dcmpf/diag/secaccs/libdcmpf_diag_secaccs_c.h>
#include <dcmpf/diag/didrd/libdcmpf_diag_didrd_c.h>
#include <dcmpf/diag/didwrt/libdcmpf_diag_didwrt_c.h>
#include <dcmpf/diag/dtc/libdcmpf_diag_dtc_c.h>

extern int parse_dcmpf_result_t(char *text, int max_len, dcmpf_result_t status);
extern int parse_dcmpf_api_status_t(char *text, int max_len, dcmpf_api_status_t status);
extern int parse_bool(char *text, int max_len, bool status);
extern int parse_dcmpf_diag_precondition_result_t(char *text, int max_len, dcmpf_diag_precondition_result_t status);
extern int parse_dcmpf_diag_result_t(char *text, int max_len, dcmpf_diag_result_t status);
extern int parse_dcmpf_diag_nrc_t(char *text, int max_len, dcmpf_diag_nrc_t status);
extern int parse_dcmpf_diag_secaccs_compare_result_t(char *text, int max_len, dcmpf_diag_secaccs_compare_result_t status);
extern int parse_dcmpf_diag_didrd_readable_t(char *text, int max_len, dcmpf_diag_didrd_readable_t status);
extern int parse_dcmpf_diag_didwrt_writable_t(char *text, int max_len, dcmpf_diag_didwrt_writable_t status);
extern int parse_dcmpf_diag_dtc_code_t(char *text, int max_len, dcmpf_diag_dtc_code_t status);
extern int parse_dcmpf_diag_dtc_user_def_code_t(char *text, int max_len, dcmpf_diag_dtc_user_def_code_t status);
extern int parse_dcmpf_diag_dtc_dcm_malfunction_state_t(char *text, int max_len, dcmpf_diag_dtc_dcm_malfunction_state_t status);


#endif  /* APIMONITOR_DCMPF_PARSE_ENUM_H */