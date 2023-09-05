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
    dcmpf_diag_ecudiag_notify_detect_excessive_wakeup_cb_t callback;
    dcmpf_handle_t handle;
} stub_dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify_callback_thread_prop_t;

stub_dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify_callback_thread_prop_t Stub_dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcmpf_diag_ecudiag_notify_detect_excessive_wakeup_cb_t callback;
    dcmpf_handle_t handle;
    const uint8_t* did_data;
    uint8_t did_data_size;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, did_data, did_data_size);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify_callback_thread_prop[index].callback = NULL;
        Stub_dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_ecudiag_notify_detect_excessive_wakeup_cb_t callback
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
        if (Stub_dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify_callback_thread_prop[i[0]].used = false;
        return DCMPF_API_STATUS_FAILED;
    }

    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_ecudiag_stop_detect_excessive_wakeup_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_ecudiag_notify_detect_excessive_wakeup_cb_t callback
)
{
    int i[1];

    if ( (callback ==  NULL) )
    {
        return DCMPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify_callback_thread_prop[i[0]].handle == handle)
        {
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_ecudiag_start_detect_excessive_wakeup_notify_callback_thread_prop[i[0]].callback = NULL;

    return DCMPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcmpf_diag_ecudiag_notify_detect_sleep_ng_continuation_cb_t callback;
    dcmpf_handle_t handle;
} stub_dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify_callback_thread_prop_t;

stub_dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify_callback_thread_prop_t Stub_dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcmpf_diag_ecudiag_notify_detect_sleep_ng_continuation_cb_t callback;
    dcmpf_handle_t handle;
    const uint8_t* did_data;
    uint8_t did_data_size;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, did_data, did_data_size);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify_callback_thread_prop[index].callback = NULL;
        Stub_dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_ecudiag_notify_detect_sleep_ng_continuation_cb_t callback
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
        if (Stub_dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify_callback_thread_prop[i[0]].used = false;
        return DCMPF_API_STATUS_FAILED;
    }

    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_ecudiag_stop_detect_sleep_ng_continuation_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_ecudiag_notify_detect_sleep_ng_continuation_cb_t callback
)
{
    int i[1];

    if ( (callback ==  NULL) )
    {
        return DCMPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify_callback_thread_prop[i[0]].handle == handle)
        {
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_ecudiag_start_detect_sleep_ng_continuation_notify_callback_thread_prop[i[0]].callback = NULL;

    return DCMPF_API_STATUS_SUCCESS;
}

