/**
 * @file libdcepf_net.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 */

#ifndef LIBDCEPF_NET_H
#define LIBDCEPF_NET_H

#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dcepf/net/ccs/libdcepf_net_ccs.h>
#include <dcepf/net/mtls/libdcepf_net_mtls.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*
 *********************************************************
 * DATA DEFINITION
 *********************************************************
 */
#define DCEPF_NET_MAX_IF_NAME_LENGTH        (16)

typedef enum {
    DCEPF_NET_IPV4STAT_UNCONFIGURED,
    DCEPF_NET_IPV4STAT_CONFIGURING,
    DCEPF_NET_IPV4STAT_FIXED,
    DCEPF_NET_IPV4STAT_LINK_LOCAL
} dcepf_net_ipv4stat_t;

typedef struct {
    bool valid_if_addr;
    struct in_addr if_addr;
    int32_t if_prefix;
    int32_t if_mtu;
    bool valid_gw_addr;
    struct in_addr gw_addr;
    bool valid_pri_dns_addr;
    struct in_addr pri_dns_addr;
    bool valid_sec_dns_addr;
    struct in_addr sec_dns_addr;
    char device_name[DCEPF_NET_MAX_IF_NAME_LENGTH];
} dcepf_net_ipv4addr_inf_t;

typedef struct {
    bool valid_if_addr;
    struct in6_addr if_addr;
    int32_t if_prefix;
    int32_t if_mtu;
    bool valid_gw_addr;
    struct in6_addr gw_addr;
    bool valid_pri_dns_addr;
    struct in6_addr pri_dns_addr;
    bool valid_sec_dns_addr;
    struct in6_addr sec_dns_addr;
    char device_name[DCEPF_NET_MAX_IF_NAME_LENGTH];
} dcepf_net_ipv6addr_inf_t;

/*
 *********************************************************
 * CALLBACK FUNCTION DEFINITION
 *********************************************************
 */
typedef void (*dcepf_net_notify_ipv4stat_cb_t)(
    dcepf_handle_t handle,
    dcepf_net_ipv4stat_t state
);

/*
 *********************************************************
 * DCE PF API DEFINITION
 *********************************************************
 */
/**
 * @brief Create a context handle for using the Network feature client
 *
 * @param [out] handle      Context handle.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_OUT_OF_BOUNDS   Out of bounds.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Create a context handle for using the Network feature client. @n
 * @n
 * This API create a new context handle each time it is called. @n
 * The application should create a context handle by this API and specify it in the argument of each Network feature API. @n
 * The context handle does not need to create / release for each API call, it only need to create once when the application is started. @n
 * @n
 * If the return value is other than DCEPF_API_STATUS_SUCCESS, the context handle will contain NULL.
 *
 */
dcepf_api_status_t dcepf_net_control_context_create(
    dcepf_handle_t *handle
);

/**
 * @brief Release the context handle used by the Network feature client
 *
 * @param [in] handle       Context handle.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Release the context handle used by the Network feature client. @n
 * @n
 * The context handle may release when the Network feature is no longer need, such as when the application is closed. @n
 * @n
 * If it want to use the Network feature again after releasing it, use dcepf_net_control_context_create() to create a context handle.
 *
 */
dcepf_api_status_t dcepf_net_control_context_release(
    dcepf_handle_t handle
);

#ifdef __cplusplus
}
#endif

#include <dcepf/net/ip/libdcepf_net_ip.h>
#include <dcepf/net/wlan/libdcepf_net_wlan.h>

#endif  /* LIBDCEPF_NET_H */
