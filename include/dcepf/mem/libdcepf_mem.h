/**
 * @file libdcepf_mem.h
 * @copyright Copyright (c) 2023 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 */
#ifndef LIBDCEPF_MEM_H
#define LIBDCEPF_MEM_H

#include <dcepf/common/libdcepf_type.h>
#include <dcepf/common/libdcepf_error.h>
#include <dcepf/mem/kvs/libdcepf_mem_kvs.h>

#ifdef __cplusplus
extern "C"
{
#endif
/*
 *********************************************************
 * DCE PF API DEFINITION
 *********************************************************
 */
dcepf_api_status_t dcepf_mem_control_context_create(
    dcepf_handle_t *handle
);

dcepf_api_status_t dcepf_mem_control_context_release(
    dcepf_handle_t handle
);

#ifdef __cplusplus
}
#endif

#endif  /* LIBDCEPF_MEM_H */
