/* Copyright (c) 2023 DENSO CORPORATION All Rights Reserved. */
#include <sys/resource.h>
#include <sys/types.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>
#include <sys/time.h>
#include <pthread.h>
#include "apiStub_common.h"
#include <dcepf/time/libdcepf_time.h>

/*
 *
 */
dcepf_api_status_t dcepf_time_cmn_get_current_time(
    dcepf_handle_t handle,
    time_t* current_time
)
{
    return DCEPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcepf_api_status_t dcepf_time_cmn_get_formatted_current_time(
    dcepf_handle_t handle,
    size_t format_len,
    char* format,
    size_t current_time_len,
    char* current_time
)
{
    return DCEPF_API_STATUS_SUCCESS;
}

