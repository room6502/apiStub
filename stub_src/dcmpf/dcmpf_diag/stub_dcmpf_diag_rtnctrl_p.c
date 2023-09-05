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
    dcmpf_diag_rtnctrl_request_routine_start_cb_t callback;
    dcmpf_handle_t handle;
    uint16_t rid;
} stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread_prop_t;

stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread_prop_t Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcmpf_diag_rtnctrl_request_routine_start_cb_t callback;
    dcmpf_handle_t handle;
    uint8_t order_no;
    uint16_t rid;
    const uint8_t* data;
    uint16_t data_length;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread_prop[index].handle;
        rid = Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread_prop[index].rid;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, order_no, rid, data, data_length);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread_prop[index].callback = NULL;
        Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread_prop[index].used = false;
    }
}

typedef struct {
    bool used;
    dcmpf_diag_rtnctrl_request_routine_stop_cb_t callback;
    dcmpf_handle_t handle;
    uint16_t rid;
} stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread_prop_t;

stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread_prop_t Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcmpf_diag_rtnctrl_request_routine_stop_cb_t callback;
    dcmpf_handle_t handle;
    uint8_t order_no;
    uint16_t rid;
    const uint8_t* data;
    uint16_t data_length;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread_prop[index].handle;
        rid = Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread_prop[index].rid;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, order_no, rid, data, data_length);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread_prop[index].callback = NULL;
        Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread_prop[index].used = false;
    }
}

typedef struct {
    bool used;
    dcmpf_diag_rtnctrl_request_routine_result_cb_t callback;
    dcmpf_handle_t handle;
    uint16_t rid;
} stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread_prop_t;

stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread_prop_t Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcmpf_diag_rtnctrl_request_routine_result_cb_t callback;
    dcmpf_handle_t handle;
    uint8_t order_no;
    uint16_t rid;
    const uint8_t* data;
    uint16_t data_length;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread_prop[index].handle;
        rid = Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread_prop[index].rid;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, order_no, rid, data, data_length);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread_prop[index].callback = NULL;
        Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_rtnctrl_register_routine_operation(
    dcmpf_handle_t handle,
    uint16_t rid,
    dcmpf_diag_rtnctrl_request_routine_start_cb_t routine_start,
    dcmpf_diag_rtnctrl_request_routine_stop_cb_t routine_stop,
    dcmpf_diag_rtnctrl_request_routine_result_cb_t routine_result
)
{
    int i[3];
    pthread_t pthread;

    if ( (routine_start ==  NULL) || (routine_stop ==  NULL) || (routine_result ==  NULL) )
    {
        return DCMPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread_prop[i[0]].used == false)
        {
                Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread_prop[i[0]].callback = routine_start;

    // 必要なバラメータをテーブルにセットする
    Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread_prop[i[0]].handle = handle;
    Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread_prop[i[0]].rid = rid;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread_prop[i[0]].callback = NULL;
        Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread_prop[i[0]].used = false;
        return DCMPF_API_STATUS_FAILED;
    }

    for (i[1] = 0; i[1] < API_STUB_MAX_CALLBACK_NUM; i[1]++)
    {
        if (Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread_prop[i[1]].used == false)
        {
                Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread_prop[i[1]].used = true;
                break;
        }
    }
    if (i[1] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread_prop[i[1]].callback = routine_stop;

    // 必要なバラメータをテーブルにセットする
    Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread_prop[i[1]].handle = handle;
    Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread_prop[i[1]].rid = rid;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread, &i[1]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread_prop[i[1]].callback = NULL;
        Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread_prop[i[1]].used = false;
        return DCMPF_API_STATUS_FAILED;
    }

    for (i[2] = 0; i[2] < API_STUB_MAX_CALLBACK_NUM; i[2]++)
    {
        if (Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread_prop[i[2]].used == false)
        {
                Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread_prop[i[2]].used = true;
                break;
        }
    }
    if (i[2] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread_prop[i[2]].callback = routine_result;

    // 必要なバラメータをテーブルにセットする
    Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread_prop[i[2]].handle = handle;
    Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread_prop[i[2]].rid = rid;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread, &i[2]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread_prop[i[2]].callback = NULL;
        Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread_prop[i[2]].used = false;
        return DCMPF_API_STATUS_FAILED;
    }

    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_rtnctrl_unregister_routine_operation(
    dcmpf_handle_t handle,
    uint16_t rid,
    dcmpf_diag_rtnctrl_request_routine_start_cb_t routine_start,
    dcmpf_diag_rtnctrl_request_routine_stop_cb_t routine_stop,
    dcmpf_diag_rtnctrl_request_routine_result_cb_t routine_result
)
{
    int i[3];

    if ( (routine_start ==  NULL) || (routine_stop ==  NULL) || (routine_result ==  NULL) )
    {
        return DCMPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread_prop[i[0]].handle == handle)
        {
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_start_thread_prop[i[0]].callback = NULL;

    for (i[1] = 0; i[1] < API_STUB_MAX_CALLBACK_NUM; i[1]++)
    {
        if (Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread_prop[i[1]].handle == handle)
        {
                break;
        }
    }
    if (i[1] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_stop_thread_prop[i[1]].callback = NULL;

    for (i[2] = 0; i[2] < API_STUB_MAX_CALLBACK_NUM; i[2]++)
    {
        if (Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread_prop[i[2]].handle == handle)
        {
                break;
        }
    }
    if (i[2] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_rtnctrl_register_routine_operation_routine_result_thread_prop[i[2]].callback = NULL;

    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_rtnctrl_report_routine_start(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_result_t result,
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
dcmpf_api_status_t dcmpf_diag_rtnctrl_report_routine_stop(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_result_t result,
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
dcmpf_api_status_t dcmpf_diag_rtnctrl_report_routine_result(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_diag_result_t result,
    const uint8_t* data,
    uint16_t data_length,
    dcmpf_diag_nrc_t error_code
)
{
    return DCMPF_API_STATUS_SUCCESS;
}

