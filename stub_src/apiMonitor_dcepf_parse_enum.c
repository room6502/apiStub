/* Copyright (c) 2023 DENSO CORPORATION All Rights Reserved. */

#include <stdio.h>
#include <apiMonitor_dcepf_parse_enum.h>

typedef struct {
    dcepf_sys_wd_device_state_t status;
    char *str;
} dcepf_sys_wd_device_state_enum_info;
static const dcepf_sys_wd_device_state_enum_info dcepf_sys_wd_device_state_str_table[] = {
    {DCEPF_SYS_WD_DEVICE_STATE_NORMAL,        "DCEPF_SYS_WD_DEVICE_STATE_NORMAL"},
    {DCEPF_SYS_WD_DEVICE_STATE_ABNORMAL,        "DCEPF_SYS_WD_DEVICE_STATE_ABNORMAL"},
    {DCEPF_SYS_WD_DEVICE_STATE_FAILURE,        "DCEPF_SYS_WD_DEVICE_STATE_FAILURE"},
};

int parse_dcepf_sys_wd_device_state_t(char *text, int max_len, dcepf_sys_wd_device_state_t status){
    for (int i = 0;i < sizeof(dcepf_sys_wd_device_state_str_table) / sizeof(dcepf_sys_wd_device_state_enum_info); i++) {
        if (dcepf_sys_wd_device_state_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcepf_sys_wd_device_state_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcepf_sys_wd_device_t status;
    char *str;
} dcepf_sys_wd_device_enum_info;
static const dcepf_sys_wd_device_enum_info dcepf_sys_wd_device_str_table[] = {
    {DCEPF_SYS_WD_DEVICE_CELLULAR,        "DCEPF_SYS_WD_DEVICE_CELLULAR"},
    {DCEPF_SYS_WD_DEVICE_WIFI,        "DCEPF_SYS_WD_DEVICE_WIFI"},
    {DCEPF_SYS_WD_DEVICE_GNSS,        "DCEPF_SYS_WD_DEVICE_GNSS"},
    {DCEPF_SYS_WD_DEVICE_EESIM,        "DCEPF_SYS_WD_DEVICE_EESIM"},
};

int parse_dcepf_sys_wd_device_t(char *text, int max_len, dcepf_sys_wd_device_t status){
    for (int i = 0;i < sizeof(dcepf_sys_wd_device_str_table) / sizeof(dcepf_sys_wd_device_enum_info); i++) {
        if (dcepf_sys_wd_device_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcepf_sys_wd_device_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcepf_api_status_t status;
    char *str;
} dcepf_api_status_enum_info;
static const dcepf_api_status_enum_info dcepf_api_status_str_table[] = {
    {DCEPF_API_STATUS_SUCCESS,        "DCEPF_API_STATUS_SUCCESS"},
    {DCEPF_API_STATUS_FAILED,        "DCEPF_API_STATUS_FAILED"},
    {DCEPF_API_STATUS_INVALID_PARAM,        "DCEPF_API_STATUS_INVALID_PARAM"},
    {DCEPF_API_STATUS_BUSY,        "DCEPF_API_STATUS_BUSY"},
    {DCEPF_API_STATUS_NOT_READY,        "DCEPF_API_STATUS_NOT_READY"},
    {DCEPF_API_STATUS_ALREADY,        "DCEPF_API_STATUS_ALREADY"},
    {DCEPF_API_STATUS_NO_SUCH,        "DCEPF_API_STATUS_NO_SUCH"},
    {DCEPF_API_STATUS_NO_RESPONSE,        "DCEPF_API_STATUS_NO_RESPONSE"},
    {DCEPF_API_STATUS_NOT_SUPPORTED,        "DCEPF_API_STATUS_NOT_SUPPORTED"},
    {DCEPF_API_STATUS_NOT_ALLOWED,        "DCEPF_API_STATUS_NOT_ALLOWED"},
    {DCEPF_API_STATUS_OUT_OF_BOUNDS,        "DCEPF_API_STATUS_OUT_OF_BOUNDS"},
};

int parse_dcepf_api_status_t(char *text, int max_len, dcepf_api_status_t status){
    for (int i = 0;i < sizeof(dcepf_api_status_str_table) / sizeof(dcepf_api_status_enum_info); i++) {
        if (dcepf_api_status_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcepf_api_status_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcepf_result_t status;
    char *str;
} dcepf_result_enum_info;
static const dcepf_result_enum_info dcepf_result_str_table[] = {
    {DCEPF_RESULT_SUCCESS,        "DCEPF_RESULT_SUCCESS"},
    {DCEPF_RESULT_FAILED,        "DCEPF_RESULT_FAILED"},
    {DCEPF_RESULT_BUSY,        "DCEPF_RESULT_BUSY"},
    {DCEPF_RESULT_ALREADY,        "DCEPF_RESULT_ALREADY"},
    {DCEPF_RESULT_CANCEL,        "DCEPF_RESULT_CANCEL"},
};

int parse_dcepf_result_t(char *text, int max_len, dcepf_result_t status){
    for (int i = 0;i < sizeof(dcepf_result_str_table) / sizeof(dcepf_result_enum_info); i++) {
        if (dcepf_result_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcepf_result_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcepf_pwr_power_state_t status;
    char *str;
} dcepf_pwr_power_state_enum_info;
static const dcepf_pwr_power_state_enum_info dcepf_pwr_power_state_str_table[] = {
    {DCEPF_PWR_POWER_STATE_IGON,        "DCEPF_PWR_POWER_STATE_IGON"},
    {DCEPF_PWR_POWER_STATE_ECO,        "DCEPF_PWR_POWER_STATE_ECO"},
    {DCEPF_PWR_POWER_STATE_LIMITED,        "DCEPF_PWR_POWER_STATE_LIMITED"},
    {DCEPF_PWR_POWER_STATE_STANDBY,        "DCEPF_PWR_POWER_STATE_STANDBY"},
    {DCEPF_PWR_POWER_STATE_STOP,        "DCEPF_PWR_POWER_STATE_STOP"},
    {DCEPF_PWR_POWER_STATE_BUB,        "DCEPF_PWR_POWER_STATE_BUB"},
};

int parse_dcepf_pwr_power_state_t(char *text, int max_len, dcepf_pwr_power_state_t status){
    for (int i = 0;i < sizeof(dcepf_pwr_power_state_str_table) / sizeof(dcepf_pwr_power_state_enum_info); i++) {
        if (dcepf_pwr_power_state_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcepf_pwr_power_state_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcepf_pwr_wakelock_mode_t status;
    char *str;
} dcepf_pwr_wakelock_mode_enum_info;
static const dcepf_pwr_wakelock_mode_enum_info dcepf_pwr_wakelock_mode_str_table[] = {
    {DCEPF_PWR_WAKELOCK_ENABLE,        "DCEPF_PWR_WAKELOCK_ENABLE"},
    {DCEPF_PWR_WAKELOCK_DISABLE,        "DCEPF_PWR_WAKELOCK_DISABLE"},
};

int parse_dcepf_pwr_wakelock_mode_t(char *text, int max_len, dcepf_pwr_wakelock_mode_t status){
    for (int i = 0;i < sizeof(dcepf_pwr_wakelock_mode_str_table) / sizeof(dcepf_pwr_wakelock_mode_enum_info); i++) {
        if (dcepf_pwr_wakelock_mode_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcepf_pwr_wakelock_mode_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcepf_net_ipv4stat_t status;
    char *str;
} dcepf_net_ipv4stat_enum_info;
static const dcepf_net_ipv4stat_enum_info dcepf_net_ipv4stat_str_table[] = {
    {DCEPF_NET_IPV4STAT_UNCONFIGURED,        "DCEPF_NET_IPV4STAT_UNCONFIGURED"},
    {DCEPF_NET_IPV4STAT_CONFIGURING,        "DCEPF_NET_IPV4STAT_CONFIGURING"},
    {DCEPF_NET_IPV4STAT_FIXED,        "DCEPF_NET_IPV4STAT_FIXED"},
    {DCEPF_NET_IPV4STAT_LINK_LOCAL,        "DCEPF_NET_IPV4STAT_LINK_LOCAL"},
};

int parse_dcepf_net_ipv4stat_t(char *text, int max_len, dcepf_net_ipv4stat_t status){
    for (int i = 0;i < sizeof(dcepf_net_ipv4stat_str_table) / sizeof(dcepf_net_ipv4stat_enum_info); i++) {
        if (dcepf_net_ipv4stat_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcepf_net_ipv4stat_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcepf_net_ccs_network_type_t status;
    char *str;
} dcepf_net_ccs_networkype_enum_info;
static const dcepf_net_ccs_networkype_enum_info dcepf_net_ccs_networkype_str_table[] = {
    {DCEPF_NET_CCS_NETTYPE_HOME,        "DCEPF_NET_CCS_NETTYPE_HOME"},
    {DCEPF_NET_CCS_NETTYPE_ROAMING,        "DCEPF_NET_CCS_NETTYPE_ROAMING"},
};

int parse_dcepf_net_ccs_network_type_t(char *text, int max_len, dcepf_net_ccs_network_type_t status){
    for (int i = 0;i < sizeof(dcepf_net_ccs_networkype_str_table) / sizeof(dcepf_net_ccs_networkype_enum_info); i++) {
        if (dcepf_net_ccs_networkype_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcepf_net_ccs_networkype_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcepf_net_ccs_cell_connection_status_t status;
    char *str;
} dcepf_net_ccs_cell_connection_status_enum_info;
static const dcepf_net_ccs_cell_connection_status_enum_info dcepf_net_ccs_cell_connection_status_str_table[] = {
    {DCEPF_NET_CCS_CELLSTAT_CAMPING,        "DCEPF_NET_CCS_CELLSTAT_CAMPING"},
    {DCEPF_NET_CCS_CELLSTAT_CONNECTED,        "DCEPF_NET_CCS_CELLSTAT_CONNECTED"},
    {DCEPF_NET_CCS_CELLSTAT_NO_CELL,        "DCEPF_NET_CCS_CELLSTAT_NO_CELL"},
};

int parse_dcepf_net_ccs_cell_connection_status_t(char *text, int max_len, dcepf_net_ccs_cell_connection_status_t status){
    for (int i = 0;i < sizeof(dcepf_net_ccs_cell_connection_status_str_table) / sizeof(dcepf_net_ccs_cell_connection_status_enum_info); i++) {
        if (dcepf_net_ccs_cell_connection_status_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcepf_net_ccs_cell_connection_status_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcepf_net_ccs_barring_status_t status;
    char *str;
} dcepf_net_ccs_barring_status_enum_info;
static const dcepf_net_ccs_barring_status_enum_info dcepf_net_ccs_barring_status_str_table[] = {
    {DCEPF_NET_CCS_BARRING_NONE,        "DCEPF_NET_CCS_BARRING_NONE"},
    {DCEPF_NET_CCS_BARRING_NORMAL_CALL,        "DCEPF_NET_CCS_BARRING_NORMAL_CALL"},
    {DCEPF_NET_CCS_BARRING_ALL,        "DCEPF_NET_CCS_BARRING_ALL"},
};

int parse_dcepf_net_ccs_barring_status_t(char *text, int max_len, dcepf_net_ccs_barring_status_t status){
    for (int i = 0;i < sizeof(dcepf_net_ccs_barring_status_str_table) / sizeof(dcepf_net_ccs_barring_status_enum_info); i++) {
        if (dcepf_net_ccs_barring_status_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcepf_net_ccs_barring_status_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcepf_net_ccs_rat_t status;
    char *str;
} dcepf_net_ccs_rat_enum_info;
static const dcepf_net_ccs_rat_enum_info dcepf_net_ccs_rat_str_table[] = {
    {DCEPF_NET_CCS_RAT_DISABLED,        "DCEPF_NET_CCS_RAT_DISABLED"},
    {DCEPF_NET_CCS_RAT_2G,        "DCEPF_NET_CCS_RAT_2G"},
    {DCEPF_NET_CCS_RAT_3G,        "DCEPF_NET_CCS_RAT_3G"},
    {DCEPF_NET_CCS_RAT_4G,        "DCEPF_NET_CCS_RAT_4G"},
    {DCEPF_NET_CCS_RAT_5G,        "DCEPF_NET_CCS_RAT_5G"},
};

int parse_dcepf_net_ccs_rat_t(char *text, int max_len, dcepf_net_ccs_rat_t status){
    for (int i = 0;i < sizeof(dcepf_net_ccs_rat_str_table) / sizeof(dcepf_net_ccs_rat_enum_info); i++) {
        if (dcepf_net_ccs_rat_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcepf_net_ccs_rat_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

