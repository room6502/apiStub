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
#include <dcepf/mem/libdcepf_mem.h>

typedef struct {
    bool used;
    dcepf_mem_kvs_notify_data_cb_t callback;
    dcepf_handle_t handle;
    uint32_t index;
} stub_dcepf_mem_kvs_start_data_notify_callback_thread_prop_t;

stub_dcepf_mem_kvs_start_data_notify_callback_thread_prop_t Stub_dcepf_mem_kvs_start_data_notify_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_mem_kvs_start_data_notify_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_mem_kvs_notify_data_cb_t callback;
    dcepf_handle_t handle;
    uint32_t index;
    uint16_t count;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_mem_kvs_start_data_notify_callback_thread_prop[index].handle;
        index = Stub_dcepf_mem_kvs_start_data_notify_callback_thread_prop[index].index;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_mem_kvs_start_data_notify_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, index, count);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcepf_mem_kvs_start_data_notify_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_mem_kvs_start_data_notify_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_mem_kvs_start_data_notify(
    dcepf_handle_t handle,
    uint32_t index,
    dcepf_mem_kvs_notify_data_cb_t callback
)
{
    int i[1];
    pthread_t pthread;

    if ( (callback ==  NULL) )
    {
        return DCEPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcepf_mem_kvs_start_data_notify_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_mem_kvs_start_data_notify_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_mem_kvs_start_data_notify_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_mem_kvs_start_data_notify_callback_thread_prop[i[0]].handle = handle;
    Stub_dcepf_mem_kvs_start_data_notify_callback_thread_prop[i[0]].index = index;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_mem_kvs_start_data_notify_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_mem_kvs_start_data_notify_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_mem_kvs_start_data_notify_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcepf_api_status_t dcepf_mem_kvs_stop_data_notify(
    dcepf_handle_t handle,
    uint32_t index,
    dcepf_mem_kvs_notify_data_cb_t callback
)
{
    int i[1];

    if ( (callback ==  NULL) )
    {
        return DCEPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcepf_mem_kvs_start_data_notify_callback_thread_prop[i[0]].handle == handle)
        {
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_mem_kvs_start_data_notify_callback_thread_prop[i[0]].callback = NULL;

    return DCEPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcepf_api_status_t dcepf_mem_kvs_set_data(
    dcepf_handle_t handle,
    uint32_t index,
    char* value,
    size_t value_len
)
{
    return DCEPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcepf_mem_kvs_apply_update_data_cb_t callback;
    dcepf_handle_t handle;
    uint32_t index;
} stub_dcepf_mem_kvs_apply_data_update_callback_thread_prop_t;

stub_dcepf_mem_kvs_apply_data_update_callback_thread_prop_t Stub_dcepf_mem_kvs_apply_data_update_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_mem_kvs_apply_data_update_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_mem_kvs_apply_update_data_cb_t callback;
    dcepf_handle_t handle;
    dcepf_result_t result;
    uint32_t index;
    uint16_t count;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_mem_kvs_apply_data_update_callback_thread_prop[index].handle;
        index = Stub_dcepf_mem_kvs_apply_data_update_callback_thread_prop[index].index;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_mem_kvs_apply_data_update_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, result, index, count);
            }
            else
            {
                break;
            }
        } while(false);

        Stub_dcepf_mem_kvs_apply_data_update_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_mem_kvs_apply_data_update_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_mem_kvs_apply_data_update(
    dcepf_handle_t handle,
    uint32_t index,
    char* value,
    size_t value_len,
    dcepf_mem_kvs_apply_update_data_cb_t callback
)
{
    int i[1];
    pthread_t pthread;

    if ( (callback ==  NULL) )
    {
        return DCEPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcepf_mem_kvs_apply_data_update_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_mem_kvs_apply_data_update_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_mem_kvs_apply_data_update_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_mem_kvs_apply_data_update_callback_thread_prop[i[0]].handle = handle;
    Stub_dcepf_mem_kvs_apply_data_update_callback_thread_prop[i[0]].index = index;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_mem_kvs_apply_data_update_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_mem_kvs_apply_data_update_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_mem_kvs_apply_data_update_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcepf_mem_kvs_query_data_cb_t callback;
    dcepf_handle_t handle;
    uint32_t index;
    char* value;
    size_t value_len;
} stub_dcepf_mem_kvs_query_data_callback_thread_prop_t;

stub_dcepf_mem_kvs_query_data_callback_thread_prop_t Stub_dcepf_mem_kvs_query_data_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_mem_kvs_query_data_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_mem_kvs_query_data_cb_t callback;
    dcepf_handle_t handle;
    dcepf_result_t result;
    uint32_t index;
    char* value;
    size_t value_len;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_mem_kvs_query_data_callback_thread_prop[index].handle;
        index = Stub_dcepf_mem_kvs_query_data_callback_thread_prop[index].index;
        value = Stub_dcepf_mem_kvs_query_data_callback_thread_prop[index].value;
        value_len = Stub_dcepf_mem_kvs_query_data_callback_thread_prop[index].value_len;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_mem_kvs_query_data_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, result, index, value, value_len);
            }
            else
            {
                break;
            }
        } while(false);

        Stub_dcepf_mem_kvs_query_data_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_mem_kvs_query_data_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_mem_kvs_query_data(
    dcepf_handle_t handle,
    uint32_t index,
    char* value,
    size_t value_len,
    dcepf_mem_kvs_query_data_cb_t callback
)
{
    int i[1];
    pthread_t pthread;

    if ( (callback ==  NULL) )
    {
        return DCEPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcepf_mem_kvs_query_data_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_mem_kvs_query_data_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_mem_kvs_query_data_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_mem_kvs_query_data_callback_thread_prop[i[0]].handle = handle;
    Stub_dcepf_mem_kvs_query_data_callback_thread_prop[i[0]].index = index;
    Stub_dcepf_mem_kvs_query_data_callback_thread_prop[i[0]].value = value;
    Stub_dcepf_mem_kvs_query_data_callback_thread_prop[i[0]].value_len = value_len;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_mem_kvs_query_data_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_mem_kvs_query_data_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_mem_kvs_query_data_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

