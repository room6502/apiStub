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
    dcmpf_diag_didrd_request_check_readable_cb_t callback;
    dcmpf_handle_t handle;
    uint16_t did;
} stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread_prop_t;

stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread_prop_t Stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcmpf_diag_didrd_request_check_readable_cb_t callback;
    dcmpf_handle_t handle;
    uint8_t order_no;
    uint16_t did;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread_prop[index].handle;
        did = Stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread_prop[index].did;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, order_no, did);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread_prop[index].callback = NULL;
        Stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread_prop[index].used = false;
    }
}

typedef struct {
    bool used;
    dcmpf_diag_didrd_request_read_data_cb_t callback;
    dcmpf_handle_t handle;
    uint16_t did;
} stub_dcmpf_diag_didrd_register_read_operation_read_data_thread_prop_t;

stub_dcmpf_diag_didrd_register_read_operation_read_data_thread_prop_t Stub_dcmpf_diag_didrd_register_read_operation_read_data_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcmpf_diag_didrd_register_read_operation_read_data_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcmpf_diag_didrd_request_read_data_cb_t callback;
    dcmpf_handle_t handle;
    uint8_t order_no;
    uint16_t did;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcmpf_diag_didrd_register_read_operation_read_data_thread_prop[index].handle;
        did = Stub_dcmpf_diag_didrd_register_read_operation_read_data_thread_prop[index].did;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcmpf_diag_didrd_register_read_operation_read_data_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, order_no, did);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcmpf_diag_didrd_register_read_operation_read_data_thread_prop[index].callback = NULL;
        Stub_dcmpf_diag_didrd_register_read_operation_read_data_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_didrd_register_read_operation(
    dcmpf_handle_t handle,
    uint16_t did,
    dcmpf_diag_didrd_request_check_readable_cb_t check_readable,
    dcmpf_diag_didrd_request_read_data_cb_t read_data
)
{
    int i[2];
    pthread_t pthread;

    if ( (check_readable ==  NULL) || (read_data ==  NULL) )
    {
        return DCMPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread_prop[i[0]].used == false)
        {
                Stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread_prop[i[0]].callback = check_readable;

    // 必要なバラメータをテーブルにセットする
    Stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread_prop[i[0]].handle = handle;
    Stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread_prop[i[0]].did = did;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcmpf_diag_didrd_register_read_operation_read_data_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread_prop[i[0]].callback = NULL;
        Stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread_prop[i[0]].used = false;
        return DCMPF_API_STATUS_FAILED;
    }

    for (i[1] = 0; i[1] < API_STUB_MAX_CALLBACK_NUM; i[1]++)
    {
        if (Stub_dcmpf_diag_didrd_register_read_operation_read_data_thread_prop[i[1]].used == false)
        {
                Stub_dcmpf_diag_didrd_register_read_operation_read_data_thread_prop[i[1]].used = true;
                break;
        }
    }
    if (i[1] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_didrd_register_read_operation_read_data_thread_prop[i[1]].callback = read_data;

    // 必要なバラメータをテーブルにセットする
    Stub_dcmpf_diag_didrd_register_read_operation_read_data_thread_prop[i[1]].handle = handle;
    Stub_dcmpf_diag_didrd_register_read_operation_read_data_thread_prop[i[1]].did = did;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcmpf_diag_didrd_register_read_operation_read_data_thread, &i[1]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcmpf_diag_didrd_register_read_operation_read_data_thread_prop[i[1]].callback = NULL;
        Stub_dcmpf_diag_didrd_register_read_operation_read_data_thread_prop[i[1]].used = false;
        return DCMPF_API_STATUS_FAILED;
    }

    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_didrd_unregister_read_operation(
    dcmpf_handle_t handle,
    uint16_t did,
    dcmpf_diag_didrd_request_check_readable_cb_t check_readable,
    dcmpf_diag_didrd_request_read_data_cb_t read_data
)
{
    int i[2];

    if ( (check_readable ==  NULL) || (read_data ==  NULL) )
    {
        return DCMPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread_prop[i[0]].handle == handle)
        {
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_didrd_register_read_operation_check_readable_thread_prop[i[0]].callback = NULL;

    for (i[1] = 0; i[1] < API_STUB_MAX_CALLBACK_NUM; i[1]++)
    {
        if (Stub_dcmpf_diag_didrd_register_read_operation_read_data_thread_prop[i[1]].handle == handle)
        {
                break;
        }
    }
    if (i[1] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_didrd_register_read_operation_read_data_thread_prop[i[1]].callback = NULL;

    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_didrd_report_check_readable(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_didrd_readable_t result,
    dcmpf_diag_nrc_t error_code
)
{
    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_didrd_report_read_data_by_ref(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_result_t result,
    uint16_t did,
    const uint8_t* data,
    uint16_t data_length,
    dcmpf_diag_nrc_t error_code
)
{
    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_didrd_report_read_data_by_file(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_result_t result,
    uint16_t did,
    const uint8_t* path,
    uint16_t path_length,
    dcmpf_diag_nrc_t error_code
)
{
    return DCMPF_API_STATUS_SUCCESS;
}

