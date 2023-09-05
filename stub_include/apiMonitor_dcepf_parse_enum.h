/**
 * @file apiMonitor_dcepf_parse_enum.h
 * @copyright Copyright (c) 2023 DENSO CORPORATION All Rights Reserved.
 *
 */

#ifndef APIMONITOR_DCEPF_PARSE_ENUM_H
#define APIMONITOR_DCEPF_PARSE_ENUM_H

#include <dcepf/sys/wd/libdcepf_sys_wd.h>
#include <dcepf/common/libdcepf_error.h>
#include <dcepf/pwr/libdcepf_pwr.h>
#include <dcepf/net/libdcepf_net.h>
#include <dcepf/net/ccs/libdcepf_net_ccs.h>

extern int parse_dcepf_sys_wd_device_state_t(char *text, int max_len, dcepf_sys_wd_device_state_t status);
extern int parse_dcepf_sys_wd_device_t(char *text, int max_len, dcepf_sys_wd_device_t status);
extern int parse_dcepf_api_status_t(char *text, int max_len, dcepf_api_status_t status);
extern int parse_dcepf_result_t(char *text, int max_len, dcepf_result_t status);
extern int parse_dcepf_pwr_power_state_t(char *text, int max_len, dcepf_pwr_power_state_t status);
extern int parse_dcepf_pwr_wakelock_mode_t(char *text, int max_len, dcepf_pwr_wakelock_mode_t status);
extern int parse_dcepf_net_ipv4stat_t(char *text, int max_len, dcepf_net_ipv4stat_t status);
extern int parse_dcepf_net_ccs_network_type_t(char *text, int max_len, dcepf_net_ccs_network_type_t status);
extern int parse_dcepf_net_ccs_cell_connection_status_t(char *text, int max_len, dcepf_net_ccs_cell_connection_status_t status);
extern int parse_dcepf_net_ccs_barring_status_t(char *text, int max_len, dcepf_net_ccs_barring_status_t status);
extern int parse_dcepf_net_ccs_rat_t(char *text, int max_len, dcepf_net_ccs_rat_t status);


#endif  /* APIMONITOR_DCEPF_PARSE_ENUM_H */