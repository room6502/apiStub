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
#include <dcepf/net/libdcepf_net.h>

typedef struct {
    bool used;
    dcepf_net_notify_ipv4stat_cb_t callback;
    dcepf_handle_t handle;
} stub_dcepf_net_wlan_start_ipv4stat_notify_callback_thread_prop_t;

stub_dcepf_net_wlan_start_ipv4stat_notify_callback_thread_prop_t Stub_dcepf_net_wlan_start_ipv4stat_notify_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_net_wlan_start_ipv4stat_notify_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_net_notify_ipv4stat_cb_t callback;
    dcepf_handle_t handle;
    dcepf_net_ipv4stat_t state;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_net_wlan_start_ipv4stat_notify_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_net_wlan_start_ipv4stat_notify_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, state);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcepf_net_wlan_start_ipv4stat_notify_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_net_wlan_start_ipv4stat_notify_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_net_wlan_start_ipv4stat_notify(
    dcepf_handle_t handle,
    dcepf_net_notify_ipv4stat_cb_t callback
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
        if (Stub_dcepf_net_wlan_start_ipv4stat_notify_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_net_wlan_start_ipv4stat_notify_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_wlan_start_ipv4stat_notify_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_net_wlan_start_ipv4stat_notify_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_net_wlan_start_ipv4stat_notify_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_net_wlan_start_ipv4stat_notify_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_net_wlan_start_ipv4stat_notify_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcepf_api_status_t dcepf_net_wlan_stop_ipv4stat_notify(
    dcepf_handle_t handle,
    dcepf_net_notify_ipv4stat_cb_t callback
)
{
    int i[1];

    if ( (callback ==  NULL) )
    {
        return DCEPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcepf_net_wlan_start_ipv4stat_notify_callback_thread_prop[i[0]].handle == handle)
        {
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_wlan_start_ipv4stat_notify_callback_thread_prop[i[0]].callback = NULL;

    return DCEPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcepf_operation_result_cb_t callback;
    dcepf_handle_t handle;
} stub_dcepf_net_wlan_invoke_ipv4_dhcp_callback_thread_prop_t;

stub_dcepf_net_wlan_invoke_ipv4_dhcp_callback_thread_prop_t Stub_dcepf_net_wlan_invoke_ipv4_dhcp_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_net_wlan_invoke_ipv4_dhcp_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_operation_result_cb_t callback;
    dcepf_handle_t handle;
    dcepf_result_t result;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_net_wlan_invoke_ipv4_dhcp_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_net_wlan_invoke_ipv4_dhcp_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, result);
            }
            else
            {
                break;
            }
        } while(false);

        Stub_dcepf_net_wlan_invoke_ipv4_dhcp_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_net_wlan_invoke_ipv4_dhcp_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_net_wlan_invoke_ipv4_dhcp(
    dcepf_handle_t handle,
    dcepf_operation_result_cb_t callback
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
        if (Stub_dcepf_net_wlan_invoke_ipv4_dhcp_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_net_wlan_invoke_ipv4_dhcp_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_wlan_invoke_ipv4_dhcp_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_net_wlan_invoke_ipv4_dhcp_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_net_wlan_invoke_ipv4_dhcp_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_net_wlan_invoke_ipv4_dhcp_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_net_wlan_invoke_ipv4_dhcp_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcepf_api_status_t dcepf_net_wlan_cancel_ipv4_dhcp(
    dcepf_handle_t handle
)
{
    return DCEPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcepf_operation_result_cb_t callback;
    dcepf_handle_t handle;
} stub_dcepf_net_wlan_invoke_function_enable_callback_thread_prop_t;

stub_dcepf_net_wlan_invoke_function_enable_callback_thread_prop_t Stub_dcepf_net_wlan_invoke_function_enable_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_net_wlan_invoke_function_enable_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_operation_result_cb_t callback;
    dcepf_handle_t handle;
    dcepf_result_t result;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_net_wlan_invoke_function_enable_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_net_wlan_invoke_function_enable_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, result);
            }
            else
            {
                break;
            }
        } while(false);

        Stub_dcepf_net_wlan_invoke_function_enable_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_net_wlan_invoke_function_enable_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_net_wlan_invoke_function_enable(
    dcepf_handle_t handle,
    dcepf_operation_result_cb_t callback
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
        if (Stub_dcepf_net_wlan_invoke_function_enable_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_net_wlan_invoke_function_enable_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_wlan_invoke_function_enable_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_net_wlan_invoke_function_enable_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_net_wlan_invoke_function_enable_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_net_wlan_invoke_function_enable_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_net_wlan_invoke_function_enable_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcepf_api_status_t dcepf_net_wlan_cancel_function_enable(
    dcepf_handle_t handle
)
{
    return DCEPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcepf_operation_result_cb_t callback;
    dcepf_handle_t handle;
} stub_dcepf_net_wlan_invoke_function_disable_callback_thread_prop_t;

stub_dcepf_net_wlan_invoke_function_disable_callback_thread_prop_t Stub_dcepf_net_wlan_invoke_function_disable_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_net_wlan_invoke_function_disable_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_operation_result_cb_t callback;
    dcepf_handle_t handle;
    dcepf_result_t result;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_net_wlan_invoke_function_disable_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_net_wlan_invoke_function_disable_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, result);
            }
            else
            {
                break;
            }
        } while(false);

        Stub_dcepf_net_wlan_invoke_function_disable_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_net_wlan_invoke_function_disable_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_net_wlan_invoke_function_disable(
    dcepf_handle_t handle,
    dcepf_operation_result_cb_t callback
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
        if (Stub_dcepf_net_wlan_invoke_function_disable_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_net_wlan_invoke_function_disable_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_wlan_invoke_function_disable_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_net_wlan_invoke_function_disable_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_net_wlan_invoke_function_disable_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_net_wlan_invoke_function_disable_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_net_wlan_invoke_function_disable_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcepf_api_status_t dcepf_net_wlan_cancel_function_disable(
    dcepf_handle_t handle
)
{
    return DCEPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcepf_operation_result_cb_t callback;
    dcepf_handle_t handle;
} stub_dcepf_net_wlan_invoke_ipv4_config_callback_thread_prop_t;

stub_dcepf_net_wlan_invoke_ipv4_config_callback_thread_prop_t Stub_dcepf_net_wlan_invoke_ipv4_config_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_net_wlan_invoke_ipv4_config_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_operation_result_cb_t callback;
    dcepf_handle_t handle;
    dcepf_result_t result;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_net_wlan_invoke_ipv4_config_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_net_wlan_invoke_ipv4_config_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, result);
            }
            else
            {
                break;
            }
        } while(false);

        Stub_dcepf_net_wlan_invoke_ipv4_config_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_net_wlan_invoke_ipv4_config_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_net_wlan_invoke_ipv4_config(
    dcepf_handle_t handle,
    dcepf_net_ipv4addr_inf_t addr_inf,
    dcepf_operation_result_cb_t callback
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
        if (Stub_dcepf_net_wlan_invoke_ipv4_config_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_net_wlan_invoke_ipv4_config_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_wlan_invoke_ipv4_config_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_net_wlan_invoke_ipv4_config_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_net_wlan_invoke_ipv4_config_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_net_wlan_invoke_ipv4_config_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_net_wlan_invoke_ipv4_config_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcepf_api_status_t dcepf_net_wlan_cancel_ipv4_config(
    dcepf_handle_t handle
)
{
    return DCEPF_API_STATUS_SUCCESS;
}

