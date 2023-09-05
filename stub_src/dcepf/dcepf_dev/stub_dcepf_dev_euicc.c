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
dcepf_api_status_t dcepf_dev_euicc_get_sim_info(
    dcepf_handle_t handle,
    char iccid[DCEPF_DEV_EUICC_ICCID_DATA_LENGTH],
    char imsi[DCEPF_DEV_EUICC_IMSI_DATA_LENGTH],
    char msisdn[DCEPF_DEV_EUICC_MSISDN_DATA_LENGTH]
)
{
    return DCEPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcepf_api_status_t dcepf_dev_euicc_get_euicc_info(
    dcepf_handle_t handle,
    char euiccid[DCEPF_DEV_EUICC_EUICCID_DATA_LENGTH]
)
{
    return DCEPF_API_STATUS_SUCCESS;
}

