/**
 * @file libdcepf_net_wlan.h
 * @copyright Copyright (c) 2023 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 */
#ifndef LIBDCEPF_WLAN_H
#define LIBDCEPF_WLAN_H

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

/*
 *********************************************************
 * CALLBACK FUNCTION DEFINITION
 *********************************************************
 */

/*
 *********************************************************
 * DCE PF API DEFINITION
 *********************************************************
 */
dcepf_api_status_t dcepf_net_wlan_start_ipv4stat_notify(
    dcepf_handle_t handle,
    dcepf_net_notify_ipv4stat_cb_t callback
);

dcepf_api_status_t dcepf_net_wlan_stop_ipv4stat_notify(
    dcepf_handle_t handle,
    dcepf_net_notify_ipv4stat_cb_t callback
);

dcepf_api_status_t dcepf_net_wlan_invoke_ipv4_dhcp(
    dcepf_handle_t handle,
    dcepf_operation_result_cb_t callback
);

dcepf_api_status_t dcepf_net_wlan_cancel_ipv4_dhcp(
    dcepf_handle_t handle
);

dcepf_api_status_t dcepf_net_wlan_invoke_function_enable(
    dcepf_handle_t handle,
    dcepf_operation_result_cb_t callback
);

dcepf_api_status_t dcepf_net_wlan_cancel_function_enable(
    dcepf_handle_t handle
);

dcepf_api_status_t dcepf_net_wlan_invoke_function_disable(
    dcepf_handle_t handle,
    dcepf_operation_result_cb_t callback
);

dcepf_api_status_t dcepf_net_wlan_cancel_function_disable(
    dcepf_handle_t handle
);

dcepf_api_status_t dcepf_net_wlan_invoke_ipv4_config(
    dcepf_handle_t handle,
    dcepf_net_ipv4addr_inf_t addr_inf,
    dcepf_operation_result_cb_t callback
);

dcepf_api_status_t dcepf_net_wlan_cancel_ipv4_config(
    dcepf_handle_t handle
);

#ifdef __cplusplus
}
#endif

#endif  /* LIBDCEPF_WLAN_H */
