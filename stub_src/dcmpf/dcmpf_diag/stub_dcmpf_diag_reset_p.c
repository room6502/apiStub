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
#include <dcmpf/diag/libdcmpf_diag.h>

typedef struct {
    bool used;
    dcmpf_diag_reset_request_check_precondition_cb_t callback;
    dcmpf_handle_t handle;
} stub_dcmpf_diag_reset_register_check_precondition_callback_thread_prop_t;

stub_dcmpf_diag_reset_register_check_precondition_callback_thread_prop_t Stub_dcmpf_diag_reset_register_check_precondition_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcmpf_diag_reset_register_check_precondition_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcmpf_diag_reset_request_check_precondition_cb_t callback;
    dcmpf_handle_t handle;
    uint8_t order_no;
    uint8_t sid;
    const uint8_t* data;
    uint32_t data_length;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcmpf_diag_reset_register_check_precondition_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcmpf_diag_reset_register_check_precondition_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, order_no, sid, data, data_length);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcmpf_diag_reset_register_check_precondition_callback_thread_prop[index].callback = NULL;
        Stub_dcmpf_diag_reset_register_check_precondition_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_reset_register_check_precondition(
    dcmpf_handle_t handle,
    dcmpf_diag_reset_request_check_precondition_cb_t callback
)
{
    int i[1];
    pthread_t pthread;

    if ( (callback ==  NULL) )
    {
        return DCMPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcmpf_diag_reset_register_check_precondition_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcmpf_diag_reset_register_check_precondition_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_reset_register_check_precondition_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcmpf_diag_reset_register_check_precondition_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcmpf_diag_reset_register_check_precondition_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcmpf_diag_reset_register_check_precondition_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcmpf_diag_reset_register_check_precondition_callback_thread_prop[i[0]].used = false;
        return DCMPF_API_STATUS_FAILED;
    }

    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_reset_unregister_check_precondition(
    dcmpf_handle_t handle,
    dcmpf_diag_reset_request_check_precondition_cb_t callback
)
{
    int i[1];

    if ( (callback ==  NULL) )
    {
        return DCMPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcmpf_diag_reset_register_check_precondition_callback_thread_prop[i[0]].handle == handle)
        {
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_reset_register_check_precondition_callback_thread_prop[i[0]].callback = NULL;

    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_reset_report_check_precondition(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_precondition_result_t result,
    dcmpf_diag_nrc_t error_code
)
{
    return DCMPF_API_STATUS_SUCCESS;
}

