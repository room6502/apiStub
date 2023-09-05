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
#include <dcepf/sys/libdcepf_sys.h>

/*
 *
 */
dcepf_api_status_t dcepf_sys_ppi_get_info_ctrl_key(
    dcepf_handle_t handle,
    char key[DCEPF_SYS_PPI_INFO_CTRL_KEY_DATA_LENGTH]
)
{
    return DCEPF_API_STATUS_SUCCESS;
}

