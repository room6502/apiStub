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
    dcepf_operation_result_cb_t callback;
    dcepf_handle_t handle;
} stub_dcepf_net_ip_apply_dns_gw_v4_create_callback_thread_prop_t;

stub_dcepf_net_ip_apply_dns_gw_v4_create_callback_thread_prop_t Stub_dcepf_net_ip_apply_dns_gw_v4_create_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_net_ip_apply_dns_gw_v4_create_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_operation_result_cb_t callback;
    dcepf_handle_t handle;
    dcepf_result_t result;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_net_ip_apply_dns_gw_v4_create_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_net_ip_apply_dns_gw_v4_create_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, result);
            }
            else
            {
                break;
            }
        } while(false);

        Stub_dcepf_net_ip_apply_dns_gw_v4_create_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_net_ip_apply_dns_gw_v4_create_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_net_ip_apply_dns_gw_v4_create(
    dcepf_handle_t handle,
    dcepf_net_ipv4addr_inf_t ipaddr_inf,
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
        if (Stub_dcepf_net_ip_apply_dns_gw_v4_create_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_net_ip_apply_dns_gw_v4_create_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_ip_apply_dns_gw_v4_create_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_net_ip_apply_dns_gw_v4_create_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_net_ip_apply_dns_gw_v4_create_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_net_ip_apply_dns_gw_v4_create_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_net_ip_apply_dns_gw_v4_create_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcepf_operation_result_cb_t callback;
    dcepf_handle_t handle;
} stub_dcepf_net_ip_apply_dns_gw_v4_delete_callback_thread_prop_t;

stub_dcepf_net_ip_apply_dns_gw_v4_delete_callback_thread_prop_t Stub_dcepf_net_ip_apply_dns_gw_v4_delete_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_net_ip_apply_dns_gw_v4_delete_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_operation_result_cb_t callback;
    dcepf_handle_t handle;
    dcepf_result_t result;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_net_ip_apply_dns_gw_v4_delete_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_net_ip_apply_dns_gw_v4_delete_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, result);
            }
            else
            {
                break;
            }
        } while(false);

        Stub_dcepf_net_ip_apply_dns_gw_v4_delete_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_net_ip_apply_dns_gw_v4_delete_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_net_ip_apply_dns_gw_v4_delete(
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
        if (Stub_dcepf_net_ip_apply_dns_gw_v4_delete_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_net_ip_apply_dns_gw_v4_delete_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_ip_apply_dns_gw_v4_delete_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_net_ip_apply_dns_gw_v4_delete_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_net_ip_apply_dns_gw_v4_delete_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_net_ip_apply_dns_gw_v4_delete_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_net_ip_apply_dns_gw_v4_delete_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcepf_net_ip_query_dns_gw_v4_cb_t callback;
    dcepf_handle_t handle;
} stub_dcepf_net_ip_query_dns_gw_v4_callback_thread_prop_t;

stub_dcepf_net_ip_query_dns_gw_v4_callback_thread_prop_t Stub_dcepf_net_ip_query_dns_gw_v4_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_net_ip_query_dns_gw_v4_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_net_ip_query_dns_gw_v4_cb_t callback;
    dcepf_handle_t handle;
    dcepf_result_t result;
    dcepf_net_ipv4addr_inf_t ipaddr_inf;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_net_ip_query_dns_gw_v4_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_net_ip_query_dns_gw_v4_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, result, ipaddr_inf);
            }
            else
            {
                break;
            }
        } while(false);

        Stub_dcepf_net_ip_query_dns_gw_v4_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_net_ip_query_dns_gw_v4_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_net_ip_query_dns_gw_v4(
    dcepf_handle_t handle,
    dcepf_net_ip_query_dns_gw_v4_cb_t callback
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
        if (Stub_dcepf_net_ip_query_dns_gw_v4_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_net_ip_query_dns_gw_v4_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_ip_query_dns_gw_v4_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_net_ip_query_dns_gw_v4_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_net_ip_query_dns_gw_v4_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_net_ip_query_dns_gw_v4_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_net_ip_query_dns_gw_v4_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcepf_operation_result_cb_t callback;
    dcepf_handle_t handle;
} stub_dcepf_net_ip_apply_dns_gw_v6_create_callback_thread_prop_t;

stub_dcepf_net_ip_apply_dns_gw_v6_create_callback_thread_prop_t Stub_dcepf_net_ip_apply_dns_gw_v6_create_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_net_ip_apply_dns_gw_v6_create_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_operation_result_cb_t callback;
    dcepf_handle_t handle;
    dcepf_result_t result;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_net_ip_apply_dns_gw_v6_create_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_net_ip_apply_dns_gw_v6_create_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, result);
            }
            else
            {
                break;
            }
        } while(false);

        Stub_dcepf_net_ip_apply_dns_gw_v6_create_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_net_ip_apply_dns_gw_v6_create_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_net_ip_apply_dns_gw_v6_create(
    dcepf_handle_t handle,
    dcepf_net_ipv6addr_inf_t ipaddr_inf,
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
        if (Stub_dcepf_net_ip_apply_dns_gw_v6_create_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_net_ip_apply_dns_gw_v6_create_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_ip_apply_dns_gw_v6_create_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_net_ip_apply_dns_gw_v6_create_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_net_ip_apply_dns_gw_v6_create_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_net_ip_apply_dns_gw_v6_create_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_net_ip_apply_dns_gw_v6_create_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcepf_operation_result_cb_t callback;
    dcepf_handle_t handle;
} stub_dcepf_net_ip_apply_dns_gw_v6_delete_callback_thread_prop_t;

stub_dcepf_net_ip_apply_dns_gw_v6_delete_callback_thread_prop_t Stub_dcepf_net_ip_apply_dns_gw_v6_delete_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_net_ip_apply_dns_gw_v6_delete_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_operation_result_cb_t callback;
    dcepf_handle_t handle;
    dcepf_result_t result;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_net_ip_apply_dns_gw_v6_delete_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_net_ip_apply_dns_gw_v6_delete_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, result);
            }
            else
            {
                break;
            }
        } while(false);

        Stub_dcepf_net_ip_apply_dns_gw_v6_delete_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_net_ip_apply_dns_gw_v6_delete_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_net_ip_apply_dns_gw_v6_delete(
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
        if (Stub_dcepf_net_ip_apply_dns_gw_v6_delete_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_net_ip_apply_dns_gw_v6_delete_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_ip_apply_dns_gw_v6_delete_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_net_ip_apply_dns_gw_v6_delete_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_net_ip_apply_dns_gw_v6_delete_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_net_ip_apply_dns_gw_v6_delete_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_net_ip_apply_dns_gw_v6_delete_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcepf_net_ip_query_dns_gw_v6_cb_t callback;
    dcepf_handle_t handle;
} stub_dcepf_net_ip_query_dns_gw_v6_callback_thread_prop_t;

stub_dcepf_net_ip_query_dns_gw_v6_callback_thread_prop_t Stub_dcepf_net_ip_query_dns_gw_v6_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_net_ip_query_dns_gw_v6_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_net_ip_query_dns_gw_v6_cb_t callback;
    dcepf_handle_t handle;
    dcepf_result_t result;
    dcepf_net_ipv6addr_inf_t ipaddr_inf;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_net_ip_query_dns_gw_v6_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_net_ip_query_dns_gw_v6_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, result, ipaddr_inf);
            }
            else
            {
                break;
            }
        } while(false);

        Stub_dcepf_net_ip_query_dns_gw_v6_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_net_ip_query_dns_gw_v6_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_net_ip_query_dns_gw_v6(
    dcepf_handle_t handle,
    dcepf_net_ip_query_dns_gw_v6_cb_t callback
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
        if (Stub_dcepf_net_ip_query_dns_gw_v6_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_net_ip_query_dns_gw_v6_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_ip_query_dns_gw_v6_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_net_ip_query_dns_gw_v6_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_net_ip_query_dns_gw_v6_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_net_ip_query_dns_gw_v6_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_net_ip_query_dns_gw_v6_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcepf_net_ip_query_routing_cb_t callback;
    dcepf_handle_t handle;
} stub_dcepf_net_ip_query_routing_callback_thread_prop_t;

stub_dcepf_net_ip_query_routing_callback_thread_prop_t Stub_dcepf_net_ip_query_routing_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_net_ip_query_routing_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_net_ip_query_routing_cb_t callback;
    dcepf_handle_t handle;
    dcepf_result_t result;
    uint32_t entry_num_v4;
    dcepf_net_ip_routing_entry_v4_t* routing_entry_list_v4;
    uint32_t entry_num_v6;
    dcepf_net_ip_routing_entry_v6_t* routing_entry_list_v6;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_net_ip_query_routing_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_net_ip_query_routing_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, result, entry_num_v4, routing_entry_list_v4, entry_num_v6, routing_entry_list_v6);
            }
            else
            {
                break;
            }
        } while(false);

        Stub_dcepf_net_ip_query_routing_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_net_ip_query_routing_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_net_ip_query_routing(
    dcepf_handle_t handle,
    uint32_t max_entry_num,
    dcepf_net_ip_routing_entry_v4_t* result_v4,
    dcepf_net_ip_routing_entry_v6_t* result_v6,
    dcepf_net_ip_query_routing_cb_t callback
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
        if (Stub_dcepf_net_ip_query_routing_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_net_ip_query_routing_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_ip_query_routing_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_net_ip_query_routing_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_net_ip_query_routing_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_net_ip_query_routing_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_net_ip_query_routing_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

