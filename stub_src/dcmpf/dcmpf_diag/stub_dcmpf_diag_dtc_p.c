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
    dcmpf_diag_dtc_request_ssr_collect_cb_t callback;
    dcmpf_handle_t handle;
    uint16_t did;
} stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread_prop_t;

stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread_prop_t Stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcmpf_diag_dtc_request_ssr_collect_cb_t callback;
    dcmpf_handle_t handle;
    uint8_t order_no;
    uint16_t did;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread_prop[index].handle;
        did = Stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread_prop[index].did;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, order_no, did);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread_prop[index].callback = NULL;
        Stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_dtc_register_ssr_collect(
    dcmpf_handle_t handle,
    uint16_t did,
    dcmpf_diag_dtc_request_ssr_collect_cb_t callback
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
        if (Stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread_prop[i[0]].handle = handle;
    Stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread_prop[i[0]].did = did;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread_prop[i[0]].used = false;
        return DCMPF_API_STATUS_FAILED;
    }

    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_dtc_unregister_ssr_collect(
    dcmpf_handle_t handle,
    uint16_t did,
    dcmpf_diag_dtc_request_ssr_collect_cb_t callback
)
{
    int i[1];

    if ( (callback ==  NULL) )
    {
        return DCMPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread_prop[i[0]].handle == handle)
        {
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_dtc_register_ssr_collect_callback_thread_prop[i[0]].callback = NULL;

    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_dtc_report_ssr_collect(
    dcmpf_handle_t handle,
    uint8_t order_no,
    dcmpf_result_t result,
    const uint8_t* ssr,
    uint32_t ssr_length
)
{
    return DCMPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcmpf_operation_result_cb_t callback;
    dcmpf_handle_t handle;
} stub_dcmpf_diag_dtc_apply_dtc_update_callback_thread_prop_t;

stub_dcmpf_diag_dtc_apply_dtc_update_callback_thread_prop_t Stub_dcmpf_diag_dtc_apply_dtc_update_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcmpf_diag_dtc_apply_dtc_update_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcmpf_operation_result_cb_t callback;
    dcmpf_handle_t handle;
    dcmpf_result_t result;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcmpf_diag_dtc_apply_dtc_update_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcmpf_diag_dtc_apply_dtc_update_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, result);
            }
            else
            {
                break;
            }
        } while(false);

        Stub_dcmpf_diag_dtc_apply_dtc_update_callback_thread_prop[index].callback = NULL;
        Stub_dcmpf_diag_dtc_apply_dtc_update_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_dtc_apply_dtc_update(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_code_t dtc,
    dcmpf_diag_dtc_status_t status,
    dcmpf_operation_result_cb_t callback
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
        if (Stub_dcmpf_diag_dtc_apply_dtc_update_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcmpf_diag_dtc_apply_dtc_update_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_dtc_apply_dtc_update_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcmpf_diag_dtc_apply_dtc_update_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcmpf_diag_dtc_apply_dtc_update_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcmpf_diag_dtc_apply_dtc_update_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcmpf_diag_dtc_apply_dtc_update_callback_thread_prop[i[0]].used = false;
        return DCMPF_API_STATUS_FAILED;
    }

    return DCMPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcmpf_operation_result_cb_t callback;
    dcmpf_handle_t handle;
} stub_dcmpf_diag_dtc_apply_user_def_memory_dtc_update_callback_thread_prop_t;

stub_dcmpf_diag_dtc_apply_user_def_memory_dtc_update_callback_thread_prop_t Stub_dcmpf_diag_dtc_apply_user_def_memory_dtc_update_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcmpf_diag_dtc_apply_user_def_memory_dtc_update_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcmpf_operation_result_cb_t callback;
    dcmpf_handle_t handle;
    dcmpf_result_t result;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcmpf_diag_dtc_apply_user_def_memory_dtc_update_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcmpf_diag_dtc_apply_user_def_memory_dtc_update_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, result);
            }
            else
            {
                break;
            }
        } while(false);

        Stub_dcmpf_diag_dtc_apply_user_def_memory_dtc_update_callback_thread_prop[index].callback = NULL;
        Stub_dcmpf_diag_dtc_apply_user_def_memory_dtc_update_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_dtc_apply_user_def_memory_dtc_update(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_user_def_code_t user_def_memory_dtc,
    dcmpf_diag_dtc_status_t status,
    dcmpf_operation_result_cb_t callback
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
        if (Stub_dcmpf_diag_dtc_apply_user_def_memory_dtc_update_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcmpf_diag_dtc_apply_user_def_memory_dtc_update_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_dtc_apply_user_def_memory_dtc_update_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcmpf_diag_dtc_apply_user_def_memory_dtc_update_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcmpf_diag_dtc_apply_user_def_memory_dtc_update_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcmpf_diag_dtc_apply_user_def_memory_dtc_update_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcmpf_diag_dtc_apply_user_def_memory_dtc_update_callback_thread_prop[i[0]].used = false;
        return DCMPF_API_STATUS_FAILED;
    }

    return DCMPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcmpf_diag_dtc_query_masked_dtc_cb_t callback;
    dcmpf_handle_t handle;
} stub_dcmpf_diag_dtc_query_masked_dtc_callback_thread_prop_t;

stub_dcmpf_diag_dtc_query_masked_dtc_callback_thread_prop_t Stub_dcmpf_diag_dtc_query_masked_dtc_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcmpf_diag_dtc_query_masked_dtc_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcmpf_diag_dtc_query_masked_dtc_cb_t callback;
    dcmpf_handle_t handle;
    dcmpf_result_t result;
    const dcmpf_diag_dtc_code_t* dtcs;
    uint8_t count;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcmpf_diag_dtc_query_masked_dtc_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcmpf_diag_dtc_query_masked_dtc_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, result, dtcs, count);
            }
            else
            {
                break;
            }
        } while(false);

        Stub_dcmpf_diag_dtc_query_masked_dtc_callback_thread_prop[index].callback = NULL;
        Stub_dcmpf_diag_dtc_query_masked_dtc_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_dtc_query_masked_dtc(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_status_t mask,
    dcmpf_diag_dtc_query_masked_dtc_cb_t callback
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
        if (Stub_dcmpf_diag_dtc_query_masked_dtc_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcmpf_diag_dtc_query_masked_dtc_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_dtc_query_masked_dtc_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcmpf_diag_dtc_query_masked_dtc_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcmpf_diag_dtc_query_masked_dtc_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcmpf_diag_dtc_query_masked_dtc_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcmpf_diag_dtc_query_masked_dtc_callback_thread_prop[i[0]].used = false;
        return DCMPF_API_STATUS_FAILED;
    }

    return DCMPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcmpf_diag_dtc_notify_confirmed_factor_cb_t callback;
    dcmpf_handle_t handle;
} stub_dcmpf_diag_dtc_start_confirmed_factor_notify_callback_thread_prop_t;

stub_dcmpf_diag_dtc_start_confirmed_factor_notify_callback_thread_prop_t Stub_dcmpf_diag_dtc_start_confirmed_factor_notify_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcmpf_diag_dtc_start_confirmed_factor_notify_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcmpf_diag_dtc_notify_confirmed_factor_cb_t callback;
    dcmpf_handle_t handle;
    dcmpf_diag_dtc_user_def_code_t factor;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcmpf_diag_dtc_start_confirmed_factor_notify_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcmpf_diag_dtc_start_confirmed_factor_notify_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, factor);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcmpf_diag_dtc_start_confirmed_factor_notify_callback_thread_prop[index].callback = NULL;
        Stub_dcmpf_diag_dtc_start_confirmed_factor_notify_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_dtc_start_confirmed_factor_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_notify_confirmed_factor_cb_t callback
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
        if (Stub_dcmpf_diag_dtc_start_confirmed_factor_notify_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcmpf_diag_dtc_start_confirmed_factor_notify_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_dtc_start_confirmed_factor_notify_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcmpf_diag_dtc_start_confirmed_factor_notify_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcmpf_diag_dtc_start_confirmed_factor_notify_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcmpf_diag_dtc_start_confirmed_factor_notify_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcmpf_diag_dtc_start_confirmed_factor_notify_callback_thread_prop[i[0]].used = false;
        return DCMPF_API_STATUS_FAILED;
    }

    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_dtc_stop_confirmed_factor_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_notify_confirmed_factor_cb_t callback
)
{
    int i[1];

    if ( (callback ==  NULL) )
    {
        return DCMPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcmpf_diag_dtc_start_confirmed_factor_notify_callback_thread_prop[i[0]].handle == handle)
        {
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_dtc_start_confirmed_factor_notify_callback_thread_prop[i[0]].callback = NULL;

    return DCMPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcmpf_diag_dtc_notify_dcm_malfunction_state_cb_t callback;
    dcmpf_handle_t handle;
} stub_dcmpf_diag_dtc_start_dcm_malfunction_state_notify_callback_thread_prop_t;

stub_dcmpf_diag_dtc_start_dcm_malfunction_state_notify_callback_thread_prop_t Stub_dcmpf_diag_dtc_start_dcm_malfunction_state_notify_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcmpf_diag_dtc_start_dcm_malfunction_state_notify_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcmpf_diag_dtc_notify_dcm_malfunction_state_cb_t callback;
    dcmpf_handle_t handle;
    dcmpf_diag_dtc_dcm_malfunction_state_t state;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcmpf_diag_dtc_start_dcm_malfunction_state_notify_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcmpf_diag_dtc_start_dcm_malfunction_state_notify_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, state);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcmpf_diag_dtc_start_dcm_malfunction_state_notify_callback_thread_prop[index].callback = NULL;
        Stub_dcmpf_diag_dtc_start_dcm_malfunction_state_notify_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_dtc_start_dcm_malfunction_state_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_notify_dcm_malfunction_state_cb_t callback
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
        if (Stub_dcmpf_diag_dtc_start_dcm_malfunction_state_notify_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcmpf_diag_dtc_start_dcm_malfunction_state_notify_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_dtc_start_dcm_malfunction_state_notify_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcmpf_diag_dtc_start_dcm_malfunction_state_notify_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcmpf_diag_dtc_start_dcm_malfunction_state_notify_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcmpf_diag_dtc_start_dcm_malfunction_state_notify_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcmpf_diag_dtc_start_dcm_malfunction_state_notify_callback_thread_prop[i[0]].used = false;
        return DCMPF_API_STATUS_FAILED;
    }

    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_dtc_stop_dcm_malfunction_state_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_notify_dcm_malfunction_state_cb_t callback
)
{
    int i[1];

    if ( (callback ==  NULL) )
    {
        return DCMPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcmpf_diag_dtc_start_dcm_malfunction_state_notify_callback_thread_prop[i[0]].handle == handle)
        {
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_dtc_start_dcm_malfunction_state_notify_callback_thread_prop[i[0]].callback = NULL;

    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_dtc_get_dcm_malfunction_state(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_dcm_malfunction_state_t* state
)
{
    return DCMPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcmpf_diag_dtc_notify_storage_data_error_state_cb_t callback;
    dcmpf_handle_t handle;
} stub_dcmpf_diag_dtc_start_storage_data_error_state_notify_callback_thread_prop_t;

stub_dcmpf_diag_dtc_start_storage_data_error_state_notify_callback_thread_prop_t Stub_dcmpf_diag_dtc_start_storage_data_error_state_notify_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcmpf_diag_dtc_start_storage_data_error_state_notify_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcmpf_diag_dtc_notify_storage_data_error_state_cb_t callback;
    dcmpf_handle_t handle;
    dcmpf_diag_dtc_dcm_malfunction_state_t state;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcmpf_diag_dtc_start_storage_data_error_state_notify_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcmpf_diag_dtc_start_storage_data_error_state_notify_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, state);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcmpf_diag_dtc_start_storage_data_error_state_notify_callback_thread_prop[index].callback = NULL;
        Stub_dcmpf_diag_dtc_start_storage_data_error_state_notify_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_dtc_start_storage_data_error_state_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_notify_storage_data_error_state_cb_t callback
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
        if (Stub_dcmpf_diag_dtc_start_storage_data_error_state_notify_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcmpf_diag_dtc_start_storage_data_error_state_notify_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_dtc_start_storage_data_error_state_notify_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcmpf_diag_dtc_start_storage_data_error_state_notify_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcmpf_diag_dtc_start_storage_data_error_state_notify_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcmpf_diag_dtc_start_storage_data_error_state_notify_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcmpf_diag_dtc_start_storage_data_error_state_notify_callback_thread_prop[i[0]].used = false;
        return DCMPF_API_STATUS_FAILED;
    }

    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_dtc_stop_storage_data_error_state_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_notify_storage_data_error_state_cb_t callback
)
{
    int i[1];

    if ( (callback ==  NULL) )
    {
        return DCMPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcmpf_diag_dtc_start_storage_data_error_state_notify_callback_thread_prop[i[0]].handle == handle)
        {
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_dtc_start_storage_data_error_state_notify_callback_thread_prop[i[0]].callback = NULL;

    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_dtc_get_storage_data_error_state(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_dcm_malfunction_state_t* state
)
{
    return DCMPF_API_STATUS_SUCCESS;
}

typedef struct {
    bool used;
    dcmpf_diag_dtc_notify_imu_error_state_cb_t callback;
    dcmpf_handle_t handle;
} stub_dcmpf_diag_dtc_start_imu_error_state_notify_callback_thread_prop_t;

stub_dcmpf_diag_dtc_start_imu_error_state_notify_callback_thread_prop_t Stub_dcmpf_diag_dtc_start_imu_error_state_notify_callback_thread_prop[API_STUB_MAX_CALLBACK_NUM] = {0};

void* stub_dcmpf_diag_dtc_start_imu_error_state_notify_callback_thread(void* pArg)
{
    int index;
    unsigned int sleep_time = 5;
    dcmpf_diag_dtc_notify_imu_error_state_cb_t callback;
    dcmpf_handle_t handle;
    dcmpf_diag_dtc_dcm_malfunction_state_t state;

    if (pArg != NULL)
    {
        index = *(int *)pArg;

        handle = Stub_dcmpf_diag_dtc_start_imu_error_state_notify_callback_thread_prop[index].handle;

        do
        {
            sleep(sleep_time);
            callback = Stub_dcmpf_diag_dtc_start_imu_error_state_notify_callback_thread_prop[index].callback;
            if (callback != NULL)
            {
                callback(handle, state);
            }
            else
            {
                break;
            }
        } while(true);

        Stub_dcmpf_diag_dtc_start_imu_error_state_notify_callback_thread_prop[index].callback = NULL;
        Stub_dcmpf_diag_dtc_start_imu_error_state_notify_callback_thread_prop[index].used = false;
    }
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_dtc_start_imu_error_state_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_notify_imu_error_state_cb_t callback
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
        if (Stub_dcmpf_diag_dtc_start_imu_error_state_notify_callback_thread_prop[i[0]].used == false)
        {
                Stub_dcmpf_diag_dtc_start_imu_error_state_notify_callback_thread_prop[i[0]].used = true;
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_dtc_start_imu_error_state_notify_callback_thread_prop[i[0]].callback = callback;

    // 必要なバラメータをテーブルにセットする
    Stub_dcmpf_diag_dtc_start_imu_error_state_notify_callback_thread_prop[i[0]].handle = handle;

    // スレッドをクリエートする
    pthread_create(&pthread, NULL, stub_dcmpf_diag_dtc_start_imu_error_state_notify_callback_thread, &i[0]);
    if (pthread == 0)
    {
        // スレッドのクリエートに失敗した場合、used と callback をクリアする
        Stub_dcmpf_diag_dtc_start_imu_error_state_notify_callback_thread_prop[i[0]].callback = NULL;
        Stub_dcmpf_diag_dtc_start_imu_error_state_notify_callback_thread_prop[i[0]].used = false;
        return DCMPF_API_STATUS_FAILED;
    }

    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_dtc_stop_imu_error_state_notify(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_notify_imu_error_state_cb_t callback
)
{
    int i[1];

    if ( (callback ==  NULL) )
    {
        return DCMPF_API_STATUS_INVALID_PARAM;
    }

    for (i[0] = 0; i[0] < API_STUB_MAX_CALLBACK_NUM; i[0]++)
    {
        if (Stub_dcmpf_diag_dtc_start_imu_error_state_notify_callback_thread_prop[i[0]].handle == handle)
        {
                break;
        }
    }
    if (i[0] == API_STUB_MAX_CALLBACK_NUM)
    {
        return DCMPF_API_STATUS_FAILED;
    }

    // callback のポインタをテーブルにセットする
    Stub_dcmpf_diag_dtc_start_imu_error_state_notify_callback_thread_prop[i[0]].callback = NULL;

    return DCMPF_API_STATUS_SUCCESS;
}

/*
 *
 */
dcmpf_api_status_t dcmpf_diag_dtc_get_imu_error_state(
    dcmpf_handle_t handle,
    dcmpf_diag_dtc_dcm_malfunction_state_t* state
)
{
    return DCMPF_API_STATUS_SUCCESS;
}

