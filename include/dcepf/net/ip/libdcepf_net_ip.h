/**
 * @file libdcepf_net_ip.h
 * @copyright Copyright (c) 2023 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 */
#ifndef LIBDCEPF_NET_IP_H
#define LIBDCEPF_NET_IP_H

#include <stddef.h>
#include <dcepf/common/libdcepf_type.h>
#include <dcepf/common/libdcepf_error.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*
 *********************************************************
 * DATA DEFINITION
 *********************************************************
 */
typedef struct {
    struct in_addr source_addr;
    in_port_t source_port_low;
    in_port_t source_port_high;
} dcepf_net_ip_routing_entry_v4_t;

typedef struct {
    struct in6_addr source_addr;
    in_port_t source_port_low;
    in_port_t source_port_high;
} dcepf_net_ip_routing_entry_v6_t;

/*
 *********************************************************
 * CALLBACK FUNCTION DEFINITION
 *********************************************************
 */
typedef void (*dcepf_net_ip_query_dns_gw_v4_cb_t)(
    dcepf_handle_t handle,
    dcepf_result_t result,
    dcepf_net_ipv4addr_inf_t ipaddr_inf
);

typedef void (*dcepf_net_ip_query_dns_gw_v6_cb_t)(
    dcepf_handle_t handle,
    dcepf_result_t result,
    dcepf_net_ipv6addr_inf_t ipaddr_inf
);

typedef void (*dcepf_net_ip_query_routing_cb_t)(
    dcepf_handle_t handle,
    dcepf_result_t result,
    uint32_t entry_num_v4,
    dcepf_net_ip_routing_entry_v4_t *routing_entry_list_v4,
    uint32_t entry_num_v6,
    dcepf_net_ip_routing_entry_v6_t *routing_entry_list_v6
);

/*
 *********************************************************
 * DCE PF API DEFINITION
 *********************************************************
 */
dcepf_api_status_t dcepf_net_ip_apply_dns_gw_v4_create(
    dcepf_handle_t handle,
    dcepf_net_ipv4addr_inf_t ipaddr_inf,
    dcepf_operation_result_cb_t callback
);

dcepf_api_status_t dcepf_net_ip_apply_dns_gw_v4_delete(
    dcepf_handle_t handle,
    dcepf_operation_result_cb_t callback
);

dcepf_api_status_t dcepf_net_ip_query_dns_gw_v4(
    dcepf_handle_t handle,
    dcepf_net_ip_query_dns_gw_v4_cb_t callback
);

dcepf_api_status_t dcepf_net_ip_apply_dns_gw_v6_create(
    dcepf_handle_t handle,
    dcepf_net_ipv6addr_inf_t ipaddr_inf,
    dcepf_operation_result_cb_t callback
);

dcepf_api_status_t dcepf_net_ip_apply_dns_gw_v6_delete(
    dcepf_handle_t handle,
    dcepf_operation_result_cb_t callback
);

dcepf_api_status_t dcepf_net_ip_query_dns_gw_v6(
    dcepf_handle_t handle,
    dcepf_net_ip_query_dns_gw_v6_cb_t callback
);

dcepf_api_status_t dcepf_net_ip_query_routing(
    dcepf_handle_t handle,
    uint32_t max_entry_num,
    dcepf_net_ip_routing_entry_v4_t *result_v4,
    dcepf_net_ip_routing_entry_v6_t *result_v6,
    dcepf_net_ip_query_routing_cb_t callback
);

#ifdef __cplusplus
}
#endif

#endif  /* LIBDCEPF_NET_IP_H */
