/**
 * @file apiMonitor_dcepf_parse_struct.h
 * @copyright Copyright (c) 2023 DENSO CORPORATION All Rights Reserved.
 *
 */

#ifndef APIMONITOR_DCEPF_PARSE_STRUCT_H
#define APIMONITOR_DCEPF_PARSE_STRUCT_H

#include <dcepf/sys/wd/libdcepf_sys_wd.h>
#include <dcepf/loc/gnss/libdcepf_loc_gnss.h>
#include <dcepf/net/libdcepf_net.h>
#include <dcepf/net/ccs/libdcepf_net_ccs.h>
#include <dcepf/net/ip/libdcepf_net_ip.h>
extern int parse_dcepf_sys_wd_device_state_list_t(char *text, int max_len, dcepf_sys_wd_device_state_list_t *p);
extern int parse_dcepf_loc_gnss_location_info_t(char *text, int max_len, dcepf_loc_gnss_location_info_t *p);
extern int parse_dcepf_net_ipv4addr_inf_t(char *text, int max_len, dcepf_net_ipv4addr_inf_t *p);
extern int parse_dcepf_net_ipv6addr_inf_t(char *text, int max_len, dcepf_net_ipv6addr_inf_t *p);
extern int parse_dcepf_net_ccs_cell_information_t(char *text, int max_len, dcepf_net_ccs_cell_information_t *p);
extern int parse_dcepf_net_ip_routing_entry_v4_t(char *text, int max_len, dcepf_net_ip_routing_entry_v4_t *p);
extern int parse_dcepf_net_ip_routing_entry_v6_t(char *text, int max_len, dcepf_net_ip_routing_entry_v6_t *p);


#endif  /* APIMONITOR_DCEPF_PARSE_STRUCT_H */