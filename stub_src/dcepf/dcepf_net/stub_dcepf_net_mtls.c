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
    dcepf_net_mtls_request_euicc_cert_cb_t callback;
    dcepf_handle_t handle;
} stub_dcepf_net_mtls_register_euicc_cert_callback_thread_prop_t;

stub_dcepf_net_mtls_register_euicc_cert_callback_thread_prop_t Stub_dcepf_net_mtls_register_euicc_cert_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_net_mtls_register_euicc_cert_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_net_mtls_request_euicc_cert_cb_t callback;
    dcepf_handle_t handle;
    uint8_t order_no;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_net_mtls_register_euicc_cert_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_net_mtls_register_euicc_cert_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, order_no);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcepf_net_mtls_register_euicc_cert_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_net_mtls_register_euicc_cert_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_net_mtls_register_euicc_cert(
    dcepf_handle_t handle,
    SSL_CTX* sslctx,
    dcepf_net_mtls_request_euicc_cert_cb_t callback
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
        if (Stub_dcepf_net_mtls_register_euicc_cert_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_net_mtls_register_euicc_cert_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_mtls_register_euicc_cert_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_net_mtls_register_euicc_cert_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_net_mtls_register_euicc_cert_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_net_mtls_register_euicc_cert_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_net_mtls_register_euicc_cert_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcepf_api_status_t dcepf_net_mtls_unregister_euicc_cert(
    dcepf_handle_t handle,
    SSL_CTX* sslctx,
    dcepf_net_mtls_request_euicc_cert_cb_t callback
)
{
    int i[1];

    if ( (callback ==  NULL) )
    {
        return DCEPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcepf_net_mtls_register_euicc_cert_callback_thread_prop[i[0]].handle == handle)
        {
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_mtls_register_euicc_cert_callback_thread_prop[i[0]].callback = NULL;

    return DCEPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcepf_api_status_t dcepf_net_mtls_report_euicc_cert(
    dcepf_handle_t handle,
    uint8_t order_no,
    uint8_t* cert,
    size_t cert_len
)
{
    return DCEPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcepf_net_mtls_request_euicc_sig_cb_t callback;
    dcepf_handle_t handle;
} stub_dcepf_net_mtls_register_euicc_sig_callback_thread_prop_t;

stub_dcepf_net_mtls_register_euicc_sig_callback_thread_prop_t Stub_dcepf_net_mtls_register_euicc_sig_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_net_mtls_register_euicc_sig_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_net_mtls_request_euicc_sig_cb_t callback;
    dcepf_handle_t handle;
    uint8_t order_no;
    const uint8_t* data;
    size_t data_len;
    uint8_t* signature;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_net_mtls_register_euicc_sig_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_net_mtls_register_euicc_sig_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, order_no, data, data_len, signature);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcepf_net_mtls_register_euicc_sig_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_net_mtls_register_euicc_sig_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_net_mtls_register_euicc_sig(
    dcepf_handle_t handle,
    SSL_CTX* sslctx,
    dcepf_net_mtls_request_euicc_sig_cb_t callback
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
        if (Stub_dcepf_net_mtls_register_euicc_sig_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_net_mtls_register_euicc_sig_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_mtls_register_euicc_sig_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_net_mtls_register_euicc_sig_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_net_mtls_register_euicc_sig_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_net_mtls_register_euicc_sig_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_net_mtls_register_euicc_sig_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcepf_api_status_t dcepf_net_mtls_unregister_euicc_sig(
    dcepf_handle_t handle,
    SSL_CTX* sslctx,
    dcepf_net_mtls_request_euicc_sig_cb_t callback
)
{
    int i[1];

    if ( (callback ==  NULL) )
    {
        return DCEPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcepf_net_mtls_register_euicc_sig_callback_thread_prop[i[0]].handle == handle)
        {
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_mtls_register_euicc_sig_callback_thread_prop[i[0]].callback = NULL;

    return DCEPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcepf_api_status_t dcepf_net_mtls_report_euicc_sig(
    dcepf_handle_t handle,
    uint8_t order_no,
    uint8_t* signature,
    size_t signature_len
)
{
    return DCEPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcepf_net_mtls_request_rand_num_gen_cb_t callback;
    dcepf_handle_t handle;
} stub_dcepf_net_mtls_register_rand_num_gen_callback_thread_prop_t;

stub_dcepf_net_mtls_register_rand_num_gen_callback_thread_prop_t Stub_dcepf_net_mtls_register_rand_num_gen_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcepf_net_mtls_register_rand_num_gen_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcepf_net_mtls_request_rand_num_gen_cb_t callback;
    dcepf_handle_t handle;
    uint8_t order_no;
    uint8_t* rand;
    size_t rand_len;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcepf_net_mtls_register_rand_num_gen_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcepf_net_mtls_register_rand_num_gen_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, order_no, rand, rand_len);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcepf_net_mtls_register_rand_num_gen_callback_thread_prop[index].callback = NULL;
        Stub_dcepf_net_mtls_register_rand_num_gen_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcepf_api_status_t dcepf_net_mtls_register_rand_num_gen(
    dcepf_handle_t handle,
    SSL_CTX* sslctx,
    dcepf_net_mtls_request_rand_num_gen_cb_t callback
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
        if (Stub_dcepf_net_mtls_register_rand_num_gen_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcepf_net_mtls_register_rand_num_gen_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_mtls_register_rand_num_gen_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcepf_net_mtls_register_rand_num_gen_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcepf_net_mtls_register_rand_num_gen_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcepf_net_mtls_register_rand_num_gen_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcepf_net_mtls_register_rand_num_gen_callback_thread_prop[i[0]].used = false;
        return DCEPF_API_STATUS_FAILED;
    }

    return DCEPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcepf_api_status_t dcepf_net_mtls_unregister_rand_num_gen(
    dcepf_handle_t handle,
    SSL_CTX* sslctx,
    dcepf_net_mtls_request_rand_num_gen_cb_t callback
)
{
    int i[1];

    if ( (callback ==  NULL) )
    {
        return DCEPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcepf_net_mtls_register_rand_num_gen_callback_thread_prop[i[0]].handle == handle)
        {
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCEPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcepf_net_mtls_register_rand_num_gen_callback_thread_prop[i[0]].callback = NULL;

    return DCEPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcepf_api_status_t dcepf_net_mtls_report_rand_num_gen(
    dcepf_handle_t handle,
    uint8_t order_no,
    uint8_t* rand,
    size_t rand_len
)
{
    return DCEPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcepf_api_status_t dcepf_net_mtls_set_server_cert_callback(
    dcepf_handle_t handle,
    SSL_CTX* sslctx
)
{
    return DCEPF_API_STATUS_SUCCESS;
}

