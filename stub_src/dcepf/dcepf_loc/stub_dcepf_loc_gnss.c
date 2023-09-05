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
#include <dcepf/loc/libdcepf_loc.h>

/*
 *
 */
dcepf_api_status_t dcepf_loc_gnss_get_location_info(
    dcepf_handle_t handle,
    dcepf_loc_gnss_location_info_t* location_info
)
{
    return DCEPF_API_STATUS_SUCCESS;
}

