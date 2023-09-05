/**
 * @file libdcepf_net_ccs.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 */
#ifndef LIBDCEPF_NET_CCS_H
#define LIBDCEPF_NET_CCS_H

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
typedef enum {
    DCEPF_NET_CCS_NETTYPE_HOME,
    DCEPF_NET_CCS_NETTYPE_ROAMING
} dcepf_net_ccs_network_type_t;

typedef enum {
    DCEPF_NET_CCS_CELLSTAT_CAMPING,
    DCEPF_NET_CCS_CELLSTAT_CONNECTED,
    DCEPF_NET_CCS_CELLSTAT_NO_CELL
} dcepf_net_ccs_cell_connection_status_t;

typedef enum {
    DCEPF_NET_CCS_BARRING_NONE,
    DCEPF_NET_CCS_BARRING_NORMAL_CALL,
    DCEPF_NET_CCS_BARRING_ALL
} dcepf_net_ccs_barring_status_t;

typedef enum {
    DCEPF_NET_CCS_RAT_DISABLED,
    DCEPF_NET_CCS_RAT_2G,
    DCEPF_NET_CCS_RAT_3G,
    DCEPF_NET_CCS_RAT_4G,
    DCEPF_NET_CCS_RAT_5G
} dcepf_net_ccs_rat_t;

typedef struct {
    dcepf_net_ccs_cell_connection_status_t cell_connection_status;
    int32_t mcc_id;
    int32_t mnc_id;
    int32_t area_id;
    int32_t cell_id;
    dcepf_net_ccs_rat_t rat;
    dcepf_net_ccs_barring_status_t barring_status;
    dcepf_net_ccs_network_type_t network_type;
} dcepf_net_ccs_cell_information_t;

/*
 *********************************************************
 * CALLBACK FUNCTION DEFINITION
 *********************************************************
 */
typedef void (*dcepf_net_ccs_query_cell_info_cb_t)(
    dcepf_handle_t handle,
    dcepf_result_t result,
    dcepf_net_ccs_cell_information_t cell_info
);

typedef void (*dcepf_net_ccs_notify_cell_info_cb_t)(
    dcepf_handle_t handle,
    dcepf_net_ccs_cell_information_t cell_info
);

/*
 *********************************************************
 * DCE PF API DEFINITION
 *********************************************************
 */
/**
 * @brief Conversion Request from APN-ID to Profile ID
 *
 * @param [in] handle       Context handle.
 * @param [in] apn_id       APN-ID
 * @param [in] apn_id_len   APN-ID's length
 * @param [out] profile_id  Profile ID
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Get profile ID of DCE PF associated with APN ID. @n
 * APN ID is specified in APN information stated in the TOYOTA specification（DataCommunicationSpecification）
 *
 */
dcepf_api_status_t dcepf_net_ccs_get_profile_id(
    dcepf_handle_t handle,
    char *apn_id,
    size_t apn_id_len,
    int32_t *profile_id
);

dcepf_api_status_t dcepf_net_ccs_query_cell_info(
    dcepf_handle_t handle,
    dcepf_net_ccs_query_cell_info_cb_t callback
);

dcepf_api_status_t dcepf_net_ccs_start_cell_info_notify(
    dcepf_handle_t handle,
    dcepf_net_ccs_notify_cell_info_cb_t callback
);

dcepf_api_status_t dcepf_net_ccs_stop_cell_info_notify(
    dcepf_handle_t handle,
    dcepf_net_ccs_notify_cell_info_cb_t callback
);

dcepf_api_status_t dcepf_net_ccs_invoke_function_disable(
    dcepf_handle_t handle,
    dcepf_operation_result_cb_t callback
);

dcepf_api_status_t dcepf_net_ccs_cancel_function_disable(
    dcepf_handle_t handle
);

dcepf_api_status_t dcepf_net_ccs_invoke_function_enable(
    dcepf_handle_t handle,
    dcepf_operation_result_cb_t callback
);

dcepf_api_status_t dcepf_net_ccs_cancel_function_enable(
    dcepf_handle_t handle
);

#ifdef __cplusplus
}
#endif

#endif  /* LIBDCEPF_NET_CCS_H */
