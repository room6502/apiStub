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
#include <dcepf/dev/libdcepf_dev.h>

/*
 *
 */
dcepf_api_status_t dcepf_dev_control_context_create(
    dcepf_handle_t* handle
)
{
    return DCEPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcepf_api_status_t dcepf_dev_control_context_release(
    dcepf_handle_t handle
)
{
    return DCEPF_API_STATUS_SUCCESS;
}

