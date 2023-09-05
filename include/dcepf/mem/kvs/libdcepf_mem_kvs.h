/**
 * @file libdcepf_mem_kvs.h
 * @copyright Copyright (c) 2023 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 */
#ifndef LIBDCEPF_MEM_KVS_H
#define LIBDCEPF_MEM_KVS_H

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
typedef void (*dcepf_mem_kvs_notify_data_cb_t)(
    dcepf_handle_t handle,
    uint32_t index,
    uint16_t count
);

typedef void (*dcepf_mem_kvs_apply_update_data_cb_t)(
    dcepf_handle_t handle,
    dcepf_result_t result,
    uint32_t index,
    uint16_t count
);

typedef void (*dcepf_mem_kvs_query_data_cb_t)(
    dcepf_handle_t handle,
    dcepf_result_t result,
    uint32_t index,
    char *value,
    size_t value_len
);

/*
 *********************************************************
 * DCE PF API DEFINITION
 *********************************************************
 */
dcepf_api_status_t dcepf_mem_kvs_start_data_notify(
    dcepf_handle_t handle,
    uint32_t index,
    dcepf_mem_kvs_notify_data_cb_t callback
);

dcepf_api_status_t dcepf_mem_kvs_stop_data_notify(
    dcepf_handle_t handle,
    uint32_t index,
    dcepf_mem_kvs_notify_data_cb_t callback
);

dcepf_api_status_t dcepf_mem_kvs_set_data(
    dcepf_handle_t handle,
    uint32_t index,
    char *value,
    size_t value_len
);

dcepf_api_status_t dcepf_mem_kvs_apply_data_update(
    dcepf_handle_t handle,
    uint32_t index,
    char *value,
    size_t value_len,
    dcepf_mem_kvs_apply_update_data_cb_t callback
);

dcepf_api_status_t dcepf_mem_kvs_query_data(
    dcepf_handle_t handle,
    uint32_t index,
    char *value,
    size_t value_len,
    dcepf_mem_kvs_query_data_cb_t callback
);

#ifdef __cplusplus
}
#endif

#endif  /* LIBDCEPF_MEM_KVS_H */
