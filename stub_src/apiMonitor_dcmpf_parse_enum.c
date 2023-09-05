/* Copyright (c) 2023 DENSO CORPORATION All Rights Reserved. */

#include <stdio.h>
#include <apiMonitor_dcmpf_parse_enum.h>

typedef struct {
    dcmpf_result_t status;
    char *str;
} dcmpf_result_enum_info;
static const dcmpf_result_enum_info dcmpf_result_str_table[] = {
    {DCMPF_RESULT_SUCCESS,        "DCMPF_RESULT_SUCCESS"},
    {DCMPF_RESULT_FAILED,        "DCMPF_RESULT_FAILED"},
    {DCMPF_RESULT_BUSY,        "DCMPF_RESULT_BUSY"},
    {DCMPF_RESULT_INVALID_STATE,        "DCMPF_RESULT_INVALID_STATE"},
    {DCMPF_RESULT_INVALID_PARAM,        "DCMPF_RESULT_INVALID_PARAM"},
    {DCMPF_RESULT_NOT_SUPPORTED,        "DCMPF_RESULT_NOT_SUPPORTED"},
    {DCMPF_RESULT_ACCESS_DENIED,        "DCMPF_RESULT_ACCESS_DENIED"},
    {DCMPF_RESULT_NOT_READY,        "DCMPF_RESULT_NOT_READY"},
    {DCMPF_RESULT_ALREADY,        "DCMPF_RESULT_ALREADY"},
    {DCMPF_RESULT_CANCEL,        "DCMPF_RESULT_CANCEL"},
    {DCMPF_RESULT_OUT_OF_BOUNDS,        "DCMPF_RESULT_OUT_OF_BOUNDS"},
    {DCMPF_RESULT_NOT_ALLOWED,        "DCMPF_RESULT_NOT_ALLOWED"},
    {DCMPF_RESULT_TIMEOUT,        "DCMPF_RESULT_TIMEOUT"},
};

int parse_dcmpf_result_t(char *text, int max_len, dcmpf_result_t status){
    for (int i = 0;i < sizeof(dcmpf_result_str_table) / sizeof(dcmpf_result_enum_info); i++) {
        if (dcmpf_result_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcmpf_result_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcmpf_api_status_t status;
    char *str;
} dcmpf_api_status_enum_info;
static const dcmpf_api_status_enum_info dcmpf_api_status_str_table[] = {
    {DCMPF_API_STATUS_SUCCESS,        "DCMPF_API_STATUS_SUCCESS"},
    {DCMPF_API_STATUS_FAILED,        "DCMPF_API_STATUS_FAILED"},
    {DCMPF_API_STATUS_INVALID_PARAM,        "DCMPF_API_STATUS_INVALID_PARAM"},
    {DCMPF_API_STATUS_ALREADY,        "DCMPF_API_STATUS_ALREADY"},
    {DCMPF_API_STATUS_NO_SUCH,        "DCMPF_API_STATUS_NO_SUCH"},
    {DCMPF_API_STATUS_OUT_OF_BOUNDS,        "DCMPF_API_STATUS_OUT_OF_BOUNDS"},
    {DCMPF_API_STATUS_NOT_SUPPORTED,        "DCMPF_API_STATUS_NOT_SUPPORTED"},
    {DCMPF_API_STATUS_NOT_ALLOWED,        "DCMPF_API_STATUS_NOT_ALLOWED"},
};

int parse_dcmpf_api_status_t(char *text, int max_len, dcmpf_api_status_t status){
    for (int i = 0;i < sizeof(dcmpf_api_status_str_table) / sizeof(dcmpf_api_status_enum_info); i++) {
        if (dcmpf_api_status_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcmpf_api_status_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    bool status;
    char *str;
} bool_enum_info;
static const bool_enum_info bool_str_table[] = {
    {false,        "false"},
    {true,        "true"},
};

int parse_bool(char *text, int max_len, bool status){
    for (int i = 0;i < sizeof(bool_str_table) / sizeof(bool_enum_info); i++) {
        if (bool_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", bool_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcmpf_diag_precondition_result_t status;
    char *str;
} dcmpf_diag_precondition_result_enum_info;
static const dcmpf_diag_precondition_result_enum_info dcmpf_diag_precondition_result_str_table[] = {
    {DCMPF_DIAG_PRECONDITION_SATISFIED,        "DCMPF_DIAG_PRECONDITION_SATISFIED"},
    {DCMPF_DIAG_PRECONDITION_FAILURE,        "DCMPF_DIAG_PRECONDITION_FAILURE"},
};

int parse_dcmpf_diag_precondition_result_t(char *text, int max_len, dcmpf_diag_precondition_result_t status){
    for (int i = 0;i < sizeof(dcmpf_diag_precondition_result_str_table) / sizeof(dcmpf_diag_precondition_result_enum_info); i++) {
        if (dcmpf_diag_precondition_result_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcmpf_diag_precondition_result_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcmpf_diag_result_t status;
    char *str;
} dcmpf_diag_result_enum_info;
static const dcmpf_diag_result_enum_info dcmpf_diag_result_str_table[] = {
    {DCMPF_DIAG_RESULT_SUCCESS,        "DCMPF_DIAG_RESULT_SUCCESS"},
    {DCMPF_DIAG_RESULT_FAILURE,        "DCMPF_DIAG_RESULT_FAILURE"},
};

int parse_dcmpf_diag_result_t(char *text, int max_len, dcmpf_diag_result_t status){
    for (int i = 0;i < sizeof(dcmpf_diag_result_str_table) / sizeof(dcmpf_diag_result_enum_info); i++) {
        if (dcmpf_diag_result_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcmpf_diag_result_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcmpf_diag_nrc_t status;
    char *str;
} dcmpf_diag_nrc_enum_info;
static const dcmpf_diag_nrc_enum_info dcmpf_diag_nrc_str_table[] = {
    {DCMPF_DIAG_NRC_NO_ERROR,        "DCMPF_DIAG_NRC_NO_ERROR"},
    {DCMPF_DIAG_NRC_GENERAL_REJECT,        "DCMPF_DIAG_NRC_GENERAL_REJECT"},
    {DCMPF_DIAG_NRC_SERVICE_NOT_SUPPORTED,        "DCMPF_DIAG_NRC_SERVICE_NOT_SUPPORTED"},
    {DCMPF_DIAG_NRC_SUBFUNCTION_NOT_SUPPORTED,        "DCMPF_DIAG_NRC_SUBFUNCTION_NOT_SUPPORTED"},
    {DCMPF_DIAG_NRC_INCORRECT_MESSAGE_LENGTH_OR_INVALID_FORMAT,        "DCMPF_DIAG_NRC_INCORRECT_MESSAGE_LENGTH_OR_INVALID_FORMAT"},
    {DCMPF_DIAG_NRC_RESPONSE_TOO_LONG,        "DCMPF_DIAG_NRC_RESPONSE_TOO_LONG"},
    {DCMPF_DIAG_NRC_BUSY_REPEAT_REQUEST,        "DCMPF_DIAG_NRC_BUSY_REPEAT_REQUEST"},
    {DCMPF_DIAG_NRC_CONDITIONS_NOT_CORRECT,        "DCMPF_DIAG_NRC_CONDITIONS_NOT_CORRECT"},
    {DCMPF_DIAG_NRC_REQUEST_SEQUENCE_ERROR,        "DCMPF_DIAG_NRC_REQUEST_SEQUENCE_ERROR"},
    {DCMPF_DIAG_NRC_REQUEST_OUT_OF_RANGE,        "DCMPF_DIAG_NRC_REQUEST_OUT_OF_RANGE"},
    {DCMPF_DIAG_NRC_SECURITY_ACCESS_DENIED,        "DCMPF_DIAG_NRC_SECURITY_ACCESS_DENIED"},
    {DCMPF_DIAG_NRC_AUTHENTICATION_REQUIRED,        "DCMPF_DIAG_NRC_AUTHENTICATION_REQUIRED"},
    {DCMPF_DIAG_NRC_INVALID_KEY,        "DCMPF_DIAG_NRC_INVALID_KEY"},
    {DCMPF_DIAG_NRC_EXCEEDED_NUMBER_OF_ATTEMPTS,        "DCMPF_DIAG_NRC_EXCEEDED_NUMBER_OF_ATTEMPTS"},
    {DCMPF_DIAG_NRC_REQUIRED_TIME_DELAY_NOT_EXPIRED,        "DCMPF_DIAG_NRC_REQUIRED_TIME_DELAY_NOT_EXPIRED"},
    {DCMPF_DIAG_NRC_UPLOAD_DOWNLOAD_NOT_ACCEPTED,        "DCMPF_DIAG_NRC_UPLOAD_DOWNLOAD_NOT_ACCEPTED"},
    {DCMPF_DIAG_NRC_TRANSFER_DATA_SUSPENDED,        "DCMPF_DIAG_NRC_TRANSFER_DATA_SUSPENDED"},
    {DCMPF_DIAG_NRC_GENERAL_PROGRAMMING_FAILURE,        "DCMPF_DIAG_NRC_GENERAL_PROGRAMMING_FAILURE"},
    {DCMPF_DIAG_NRC_WRONG_BLOCK_SEQUENCE_COUNTER,        "DCMPF_DIAG_NRC_WRONG_BLOCK_SEQUENCE_COUNTER"},
    {DCMPF_DIAG_NRC_SUBFUNCTION_NOT_SUPPOERTED_IN_ACTIVE_SESSION,        "DCMPF_DIAG_NRC_SUBFUNCTION_NOT_SUPPOERTED_IN_ACTIVE_SESSION"},
    {DCMPF_DIAG_NRC_SERVICE_NOT_SUPPORTED_IN_ACTIVE_SESSION,        "DCMPF_DIAG_NRC_SERVICE_NOT_SUPPORTED_IN_ACTIVE_SESSION"},
    {DCMPF_DIAG_NRC_ENGINE_IS_RUNNING,        "DCMPF_DIAG_NRC_ENGINE_IS_RUNNING"},
    {DCMPF_DIAG_NRC_ENGINE_IS_NOT_RUNNING,        "DCMPF_DIAG_NRC_ENGINE_IS_NOT_RUNNING"},
    {DCMPF_DIAG_NRC_VEHICLE_SPEED_TOO_HIGH,        "DCMPF_DIAG_NRC_VEHICLE_SPEED_TOO_HIGH"},
    {DCMPF_DIAG_NRC_VEHICLE_SPEED_TOO_LOW,        "DCMPF_DIAG_NRC_VEHICLE_SPEED_TOO_LOW"},
    {DCMPF_DIAG_NRC_TRANSMISSION_RANGE_NOT_IN_NEUTRAL,        "DCMPF_DIAG_NRC_TRANSMISSION_RANGE_NOT_IN_NEUTRAL"},
    {DCMPF_DIAG_NRC_TRANSMISSION_RANGE_NOT_IN_GEAR,        "DCMPF_DIAG_NRC_TRANSMISSION_RANGE_NOT_IN_GEAR"},
    {DCMPF_DIAG_NRC_SHIFTERLEVER_NOT_IN_PARK,        "DCMPF_DIAG_NRC_SHIFTERLEVER_NOT_IN_PARK"},
    {DCMPF_DIAG_NRC_VOLTAGE_TOO_HIGH,        "DCMPF_DIAG_NRC_VOLTAGE_TOO_HIGH"},
    {DCMPF_DIAG_NRC_VOLTAGE_TOO_LOW,        "DCMPF_DIAG_NRC_VOLTAGE_TOO_LOW"},
};

int parse_dcmpf_diag_nrc_t(char *text, int max_len, dcmpf_diag_nrc_t status){
    for (int i = 0;i < sizeof(dcmpf_diag_nrc_str_table) / sizeof(dcmpf_diag_nrc_enum_info); i++) {
        if (dcmpf_diag_nrc_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcmpf_diag_nrc_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcmpf_diag_secaccs_compare_result_t status;
    char *str;
} dcmpf_diag_secaccs_compare_result_enum_info;
static const dcmpf_diag_secaccs_compare_result_enum_info dcmpf_diag_secaccs_compare_result_str_table[] = {
    {DCMPF_DIAG_SECACCS_KEY_MATCH,        "DCMPF_DIAG_SECACCS_KEY_MATCH"},
    {DCMPF_DIAG_SECACCS_KEY_UNMATCH,        "DCMPF_DIAG_SECACCS_KEY_UNMATCH"},
};

int parse_dcmpf_diag_secaccs_compare_result_t(char *text, int max_len, dcmpf_diag_secaccs_compare_result_t status){
    for (int i = 0;i < sizeof(dcmpf_diag_secaccs_compare_result_str_table) / sizeof(dcmpf_diag_secaccs_compare_result_enum_info); i++) {
        if (dcmpf_diag_secaccs_compare_result_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcmpf_diag_secaccs_compare_result_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcmpf_diag_didrd_readable_t status;
    char *str;
} dcmpf_diag_didrd_readable_enum_info;
static const dcmpf_diag_didrd_readable_enum_info dcmpf_diag_didrd_readable_str_table[] = {
    {DCMPF_DIAG_DIDRD_READABLE,        "DCMPF_DIAG_DIDRD_READABLE"},
    {DCMPF_DIAG_DIDRD_NOT_READABLE,        "DCMPF_DIAG_DIDRD_NOT_READABLE"},
};

int parse_dcmpf_diag_didrd_readable_t(char *text, int max_len, dcmpf_diag_didrd_readable_t status){
    for (int i = 0;i < sizeof(dcmpf_diag_didrd_readable_str_table) / sizeof(dcmpf_diag_didrd_readable_enum_info); i++) {
        if (dcmpf_diag_didrd_readable_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcmpf_diag_didrd_readable_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcmpf_diag_didwrt_writable_t status;
    char *str;
} dcmpf_diag_didwrt_writable_enum_info;
static const dcmpf_diag_didwrt_writable_enum_info dcmpf_diag_didwrt_writable_str_table[] = {
    {DCMPF_DIAG_DIDWRT_WRITABLE,        "DCMPF_DIAG_DIDWRT_WRITABLE"},
    {DCMPF_DIAG_DIDWRT_NOT_WRITABLE,        "DCMPF_DIAG_DIDWRT_NOT_WRITABLE"},
};

int parse_dcmpf_diag_didwrt_writable_t(char *text, int max_len, dcmpf_diag_didwrt_writable_t status){
    for (int i = 0;i < sizeof(dcmpf_diag_didwrt_writable_str_table) / sizeof(dcmpf_diag_didwrt_writable_enum_info); i++) {
        if (dcmpf_diag_didwrt_writable_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcmpf_diag_didwrt_writable_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcmpf_diag_dtc_code_t status;
    char *str;
} dcmpf_diag_dtc_code_enum_info;
static const dcmpf_diag_dtc_code_enum_info dcmpf_diag_dtc_code_str_table[] = {
    {DCMPF_DIAG_DTC_TEL_MAIN_ANTENNA_MALFUNCTON_DISCONNECT,        "DCMPF_DIAG_DTC_TEL_MAIN_ANTENNA_MALFUNCTON_DISCONNECT"},
    {DCMPF_DIAG_DTC_TEL_MAIN_ANTENNA_MALFUNCTON_SHORT,        "DCMPF_DIAG_DTC_TEL_MAIN_ANTENNA_MALFUNCTON_SHORT"},
    {DCMPF_DIAG_DTC_GNSS_ANTENNA_MALFUNCTON_DISCONNECT,        "DCMPF_DIAG_DTC_GNSS_ANTENNA_MALFUNCTON_DISCONNECT"},
    {DCMPF_DIAG_DTC_GNSS_ANTENNA_MALFUNCTON_SHORT,        "DCMPF_DIAG_DTC_GNSS_ANTENNA_MALFUNCTON_SHORT"},
    {DCMPF_DIAG_DTC_TEL_SUB_ANTENNA_MALFUNCTON_DISCONNECT,        "DCMPF_DIAG_DTC_TEL_SUB_ANTENNA_MALFUNCTON_DISCONNECT"},
    {DCMPF_DIAG_DTC_TEL_SUB_ANTENNA_MALFUNCTON_SHORT,        "DCMPF_DIAG_DTC_TEL_SUB_ANTENNA_MALFUNCTON_SHORT"},
    {DCMPF_DIAG_DTC_BUTTON_MULFUNCTION_OPEN,        "DCMPF_DIAG_DTC_BUTTON_MULFUNCTION_OPEN"},
    {DCMPF_DIAG_DTC_BUTTON_MALFUNCTON_SHORT,        "DCMPF_DIAG_DTC_BUTTON_MALFUNCTON_SHORT"},
    {DCMPF_DIAG_DTC_RED_LED_MULFUNCTION_OPEN,        "DCMPF_DIAG_DTC_RED_LED_MULFUNCTION_OPEN"},
    {DCMPF_DIAG_DTC_RED_LED_MALFUNCTON_SHORT,        "DCMPF_DIAG_DTC_RED_LED_MALFUNCTON_SHORT"},
    {DCMPF_DIAG_DTC_BACKGROUND_LED_MULFUNCTION_OPEN,        "DCMPF_DIAG_DTC_BACKGROUND_LED_MULFUNCTION_OPEN"},
    {DCMPF_DIAG_DTC_BACKGROUND_LED_MALFUNCTON_SHORT,        "DCMPF_DIAG_DTC_BACKGROUND_LED_MALFUNCTON_SHORT"},
    {DCMPF_DIAG_DTC_BACKGROUND_AIRBAG_SIGNAL_ABNORMAL,        "DCMPF_DIAG_DTC_BACKGROUND_AIRBAG_SIGNAL_ABNORMAL"},
    {DCMPF_DIAG_DTC_BUB_MALFUNCTION,        "DCMPF_DIAG_DTC_BUB_MALFUNCTION"},
    {DCMPF_DIAG_DTC_DISCONNECT_SPEAKER_CABLES,        "DCMPF_DIAG_DTC_DISCONNECT_SPEAKER_CABLES"},
    {DCMPF_DIAG_DTC_MICROPHONE_MALFUNCTION,        "DCMPF_DIAG_DTC_MICROPHONE_MALFUNCTION"},
    {DCMPF_DIAG_DTC_DCM_MALFUNCTION,        "DCMPF_DIAG_DTC_DCM_MALFUNCTION"},
    {DCMPF_DIAG_DTC_DCM_MALFUNCTION_ABNORMAL_STORED_DATA,        "DCMPF_DIAG_DTC_DCM_MALFUNCTION_ABNORMAL_STORED_DATA"},
    {DCMPF_DIAG_DTC_DCM_MALFUNCTION_INTERNAL_ACCELEROMETER_MALFUNCTION,        "DCMPF_DIAG_DTC_DCM_MALFUNCTION_INTERNAL_ACCELEROMETER_MALFUNCTION"},
    {DCMPF_DIAG_DTC_DCM_MALFUNCTION_WIFI_CHIP_HARDWARE_MALFUNCTION,        "DCMPF_DIAG_DTC_DCM_MALFUNCTION_WIFI_CHIP_HARDWARE_MALFUNCTION"},
    {DCMPF_DIAG_DTC_COMMUNICATION_BLACKOUT_FROM_BDB,        "DCMPF_DIAG_DTC_COMMUNICATION_BLACKOUT_FROM_BDB"},
    {DCMPF_DIAG_DTC_COMMUNICATION_BLACKOUT_FROM_AVN,        "DCMPF_DIAG_DTC_COMMUNICATION_BLACKOUT_FROM_AVN"},
    {DCMPF_DIAG_DTC_COMMUNICATION_BLACKOUT_FROM_MET,        "DCMPF_DIAG_DTC_COMMUNICATION_BLACKOUT_FROM_MET"},
    {DCMPF_DIAG_DTC_WIFI_ANT2_DISCONNECTION,        "DCMPF_DIAG_DTC_WIFI_ANT2_DISCONNECTION"},
    {DCMPF_DIAG_DTC_WIFI_ANT2_SHORT,        "DCMPF_DIAG_DTC_WIFI_ANT2_SHORT"},
    {DCMPF_DIAG_DTC_CODEC_DSP_MALFUNCTION,        "DCMPF_DIAG_DTC_CODEC_DSP_MALFUNCTION"},
};

int parse_dcmpf_diag_dtc_code_t(char *text, int max_len, dcmpf_diag_dtc_code_t status){
    for (int i = 0;i < sizeof(dcmpf_diag_dtc_code_str_table) / sizeof(dcmpf_diag_dtc_code_enum_info); i++) {
        if (dcmpf_diag_dtc_code_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcmpf_diag_dtc_code_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcmpf_diag_dtc_user_def_code_t status;
    char *str;
} dcmpf_diag_dtc_user_def_code_enum_info;
static const dcmpf_diag_dtc_user_def_code_enum_info dcmpf_diag_dtc_user_def_code_str_table[] = {
    {DCMPF_DIAG_DTC_USER_DEF_ROB_BUB_EOF,        "DCMPF_DIAG_DTC_USER_DEF_ROB_BUB_EOF"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_BUB_LOW_CHARGE,        "DCMPF_DIAG_DTC_USER_DEF_ROB_BUB_LOW_CHARGE"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_VIN_UNMATCH,        "DCMPF_DIAG_DTC_USER_DEF_ROB_VIN_UNMATCH"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_SOS_BUTTON_STUCK,        "DCMPF_DIAG_DTC_USER_DEF_ROB_SOS_BUTTON_STUCK"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_PDC_DISRUPT,        "DCMPF_DIAG_DTC_USER_DEF_ROB_PDC_DISRUPT"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_BDB_DISRUPT,        "DCMPF_DIAG_DTC_USER_DEF_ROB_BDB_DISRUPT"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_ETH_DISRUPT,        "DCMPF_DIAG_DTC_USER_DEF_ROB_ETH_DISRUPT"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_ACCUMELATED_CURRENT_COUNTER_THRESHOLD_REACHED,        "DCMPF_DIAG_DTC_USER_DEF_ROB_ACCUMELATED_CURRENT_COUNTER_THRESHOLD_REACHED"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_DCM_ABNORMAL_BEHAVIOR,        "DCMPF_DIAG_DTC_USER_DEF_ROB_DCM_ABNORMAL_BEHAVIOR"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_PLG_DISRUPT,        "DCMPF_DIAG_DTC_USER_DEF_ROB_PLG_DISRUPT"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_LOCAL_CAN_DISRUPT,        "DCMPF_DIAG_DTC_USER_DEF_ROB_LOCAL_CAN_DISRUPT"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_THERMAL_SHUTDOWN,        "DCMPF_DIAG_DTC_USER_DEF_ROB_THERMAL_SHUTDOWN"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_FAILURE_TO_WRITE,        "DCMPF_DIAG_DTC_USER_DEF_ROB_FAILURE_TO_WRITE"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_INCONSISTENT_STARTUP_SOFTWARE,        "DCMPF_DIAG_DTC_USER_DEF_ROB_INCONSISTENT_STARTUP_SOFTWARE"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_OTA_SOFTWARE_REWITING_START_COMPLETED,        "DCMPF_DIAG_DTC_USER_DEF_ROB_OTA_SOFTWARE_REWITING_START_COMPLETED"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_EXCESSIVE_BUS_WAKEUP_MYSELF,        "DCMPF_DIAG_DTC_USER_DEF_ROB_EXCESSIVE_BUS_WAKEUP_MYSELF"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_BUS_SLEEP_NG_CONTINUATION_MYSELF,        "DCMPF_DIAG_DTC_USER_DEF_ROB_BUS_SLEEP_NG_CONTINUATION_MYSELF"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_EXCESSIVE_BUS_WAKEUP_OTHER_ECU,        "DCMPF_DIAG_DTC_USER_DEF_ROB_EXCESSIVE_BUS_WAKEUP_OTHER_ECU"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_BUS_SLEEP_NG_CONTINUATION_OTHER_ECU,        "DCMPF_DIAG_DTC_USER_DEF_ROB_BUS_SLEEP_NG_CONTINUATION_OTHER_ECU"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_EXCESSIVE_ECU_WAKEUP,        "DCMPF_DIAG_DTC_USER_DEF_ROB_EXCESSIVE_ECU_WAKEUP"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_ECU_SLEEP_NG_CONTINUATION,        "DCMPF_DIAG_DTC_USER_DEF_ROB_ECU_SLEEP_NG_CONTINUATION"},
    {DCMPF_DIAG_DTC_USER_DEF_ROB_WIFI_COMMUNICATION_ERROR,        "DCMPF_DIAG_DTC_USER_DEF_ROB_WIFI_COMMUNICATION_ERROR"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_GNSS_UNRECEIVE,        "DCMPF_DIAG_DTC_USER_DEF_OPE_GNSS_UNRECEIVE"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_GNSS_RECOVERY_FROM_UNRECEIVE,        "DCMPF_DIAG_DTC_USER_DEF_OPE_GNSS_RECOVERY_FROM_UNRECEIVE"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_COLLISION_DETECT,        "DCMPF_DIAG_DTC_USER_DEF_OPE_COLLISION_DETECT"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_NAD_STARTUP_FAILURE,        "DCMPF_DIAG_DTC_USER_DEF_OPE_NAD_STARTUP_FAILURE"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_NAD_EXCESSIVE_THRESHOLD_VALUE_OF_ACCUMULATED_CURRENT,        "DCMPF_DIAG_DTC_USER_DEF_OPE_NAD_EXCESSIVE_THRESHOLD_VALUE_OF_ACCUMULATED_CURRENT"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_NAD_ABNORMAL_POWER_OFF,        "DCMPF_DIAG_DTC_USER_DEF_OPE_NAD_ABNORMAL_POWER_OFF"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_NAD_ABNORMAL_RESET,        "DCMPF_DIAG_DTC_USER_DEF_OPE_NAD_ABNORMAL_RESET"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_NAD_POWER_OFF_AFTER_STANDBY_COMPLETION,        "DCMPF_DIAG_DTC_USER_DEF_OPE_NAD_POWER_OFF_AFTER_STANDBY_COMPLETION"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_MQTT_INVALID,        "DCMPF_DIAG_DTC_USER_DEF_OPE_MQTT_INVALID"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_MQTT_TRANSMIT_ERROR_OF_RECV_RESP,        "DCMPF_DIAG_DTC_USER_DEF_OPE_MQTT_TRANSMIT_ERROR_OF_RECV_RESP"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_MQTT_FAILURE_FORWARD_RECV_MQTT_MSG_TO_APP,        "DCMPF_DIAG_DTC_USER_DEF_OPE_MQTT_FAILURE_FORWARD_RECV_MQTT_MSG_TO_APP"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_PROV_RECV_DUPLICATE_MQTT_MSG,        "DCMPF_DIAG_DTC_USER_DEF_OPE_PROV_RECV_DUPLICATE_MQTT_MSG"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_PROV_RECV_EXPIRED_MQTT_MSG,        "DCMPF_DIAG_DTC_USER_DEF_OPE_PROV_RECV_EXPIRED_MQTT_MSG"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_OPESUPP_RECV_DUPLICATE_MQTT_MSG,        "DCMPF_DIAG_DTC_USER_DEF_OPE_OPESUPP_RECV_DUPLICATE_MQTT_MSG"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_OPESUPP_RECV_EXPIRED_MQTT_MSG,        "DCMPF_DIAG_DTC_USER_DEF_OPE_OPESUPP_RECV_EXPIRED_MQTT_MSG"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_CONT_FLAG_CORRUPTION_DETECTED,        "DCMPF_DIAG_DTC_USER_DEF_OPE_CONT_FLAG_CORRUPTION_DETECTED"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_CONT_SUCCESSFUL_ACQUISITION_OF_FLAG,        "DCMPF_DIAG_DTC_USER_DEF_OPE_CONT_SUCCESSFUL_ACQUISITION_OF_FLAG"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_CONT_FAILURE_OF_FLAG_ACQUISITION,        "DCMPF_DIAG_DTC_USER_DEF_OPE_CONT_FAILURE_OF_FLAG_ACQUISITION"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_CONT_FAILURE_TO_SEND_FLAG_DL_RESULT,        "DCMPF_DIAG_DTC_USER_DEF_OPE_CONT_FAILURE_TO_SEND_FLAG_DL_RESULT"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_ECALL_VOICE_CALL_OUT_OF_AREA,        "DCMPF_DIAG_DTC_USER_DEF_OPE_ECALL_VOICE_CALL_OUT_OF_AREA"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_ECALL_DATA_COMM_OUT_OF_AREA,        "DCMPF_DIAG_DTC_USER_DEF_OPE_ECALL_DATA_COMM_OUT_OF_AREA"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_ECALL_DATA_COMM_NO_RESP,        "DCMPF_DIAG_DTC_USER_DEF_OPE_ECALL_DATA_COMM_NO_RESP"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_ECALL_FAILURE_OTHER_FACTORS,        "DCMPF_DIAG_DTC_USER_DEF_OPE_ECALL_FAILURE_OTHER_FACTORS"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_AMI_DATA_COMM_OUT_OF_AREA,        "DCMPF_DIAG_DTC_USER_DEF_OPE_AMI_DATA_COMM_OUT_OF_AREA"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_AMI_DATA_COMM_NO_RESP,        "DCMPF_DIAG_DTC_USER_DEF_OPE_AMI_DATA_COMM_NO_RESP"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_AMI_FAILURE_OTHER_FACTORS,        "DCMPF_DIAG_DTC_USER_DEF_OPE_AMI_FAILURE_OTHER_FACTORS"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_MMI_DATA_COMM_OUT_OF_AREA,        "DCMPF_DIAG_DTC_USER_DEF_OPE_MMI_DATA_COMM_OUT_OF_AREA"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_MMI_DATA_COMM_NO_RESP,        "DCMPF_DIAG_DTC_USER_DEF_OPE_MMI_DATA_COMM_NO_RESP"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_MMI_FAILURE_OTHER_FACTORS,        "DCMPF_DIAG_DTC_USER_DEF_OPE_MMI_FAILURE_OTHER_FACTORS"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_VLS_FLAG_OFF,        "DCMPF_DIAG_DTC_USER_DEF_OPE_VLS_FLAG_OFF"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_VLS_DATA_COMM_OUT_OF_AREA,        "DCMPF_DIAG_DTC_USER_DEF_OPE_VLS_DATA_COMM_OUT_OF_AREA"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_VLS_DATA_COMM_NO_RESP,        "DCMPF_DIAG_DTC_USER_DEF_OPE_VLS_DATA_COMM_NO_RESP"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_SVT_REPORT_RETRY_OUT,        "DCMPF_DIAG_DTC_USER_DEF_OPE_SVT_REPORT_RETRY_OUT"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_SVT_START_REQ_OVERWRITING,        "DCMPF_DIAG_DTC_USER_DEF_OPE_SVT_START_REQ_OVERWRITING"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_SVT_STOP_RESP_RETRY_OUT,        "DCMPF_DIAG_DTC_USER_DEF_OPE_SVT_STOP_RESP_RETRY_OUT"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_SVT_RECV_DUPLICATE_MQTT_MSG,        "DCMPF_DIAG_DTC_USER_DEF_OPE_SVT_RECV_DUPLICATE_MQTT_MSG"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_SVT_RECV_EXPIRED_MQTT_MSG,        "DCMPF_DIAG_DTC_USER_DEF_OPE_SVT_RECV_EXPIRED_MQTT_MSG"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_RVT_REPORT_RETRY_OUT,        "DCMPF_DIAG_DTC_USER_DEF_OPE_RVT_REPORT_RETRY_OUT"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_RVT_POSITION_ACQ_FAILURE,        "DCMPF_DIAG_DTC_USER_DEF_OPE_RVT_POSITION_ACQ_FAILURE"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_OUT_OF_AREA,        "DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_OUT_OF_AREA"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_FAILURE_NAME_RESOLV,        "DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_FAILURE_NAME_RESOLV"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_CENTER_NO_RESP,        "DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_CENTER_NO_RESP"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_FAILURE_CENTER_AUTH,        "DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_FAILURE_CENTER_AUTH"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_NEGATIVE_RESP_FROM_CENTER,        "DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_NEGATIVE_RESP_FROM_CENTER"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_RECV_DUPLICATE_MQTT_MSG,        "DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_RECV_DUPLICATE_MQTT_MSG"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_RECV_EXPIRED_MQTT_MSG,        "DCMPF_DIAG_DTC_USER_DEF_OPE_ADF_RECV_EXPIRED_MQTT_MSG"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_APN_FAILURE_READ_INFO,        "DCMPF_DIAG_DTC_USER_DEF_OPE_APN_FAILURE_READ_INFO"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_APN_FAILURE_APN_SET,        "DCMPF_DIAG_DTC_USER_DEF_OPE_APN_FAILURE_APN_SET"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_TSCCA_FAILURE_READ_EUICCID,        "DCMPF_DIAG_DTC_USER_DEF_OPE_TSCCA_FAILURE_READ_EUICCID"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_TSCCA_INVALID_RESP_FROM_EUICC,        "DCMPF_DIAG_DTC_USER_DEF_OPE_TSCCA_INVALID_RESP_FROM_EUICC"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_TSCCA_CENTER_NO_RESP,        "DCMPF_DIAG_DTC_USER_DEF_OPE_TSCCA_CENTER_NO_RESP"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_TSCCA_FAILURE_CENTER_AUTH,        "DCMPF_DIAG_DTC_USER_DEF_OPE_TSCCA_FAILURE_CENTER_AUTH"},
    {DCMPF_DIAG_DTC_USER_DEF_OPE_TSCCA_INVALID_RESP_FROM_CENTER,        "DCMPF_DIAG_DTC_USER_DEF_OPE_TSCCA_INVALID_RESP_FROM_CENTER"},
};

int parse_dcmpf_diag_dtc_user_def_code_t(char *text, int max_len, dcmpf_diag_dtc_user_def_code_t status){
    for (int i = 0;i < sizeof(dcmpf_diag_dtc_user_def_code_str_table) / sizeof(dcmpf_diag_dtc_user_def_code_enum_info); i++) {
        if (dcmpf_diag_dtc_user_def_code_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcmpf_diag_dtc_user_def_code_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

typedef struct {
    dcmpf_diag_dtc_dcm_malfunction_state_t status;
    char *str;
} dcmpf_diag_dtc_dcm_malfunction_state_enum_info;
static const dcmpf_diag_dtc_dcm_malfunction_state_enum_info dcmpf_diag_dtc_dcm_malfunction_state_str_table[] = {
    {DCMPF_DIAG_DTC_DCM_NORMAL,        "DCMPF_DIAG_DTC_DCM_NORMAL"},
    {DCMPF_DIAG_DTC_DCM_ABNORMAL,        "DCMPF_DIAG_DTC_DCM_ABNORMAL"},
};

int parse_dcmpf_diag_dtc_dcm_malfunction_state_t(char *text, int max_len, dcmpf_diag_dtc_dcm_malfunction_state_t status){
    for (int i = 0;i < sizeof(dcmpf_diag_dtc_dcm_malfunction_state_str_table) / sizeof(dcmpf_diag_dtc_dcm_malfunction_state_enum_info); i++) {
        if (dcmpf_diag_dtc_dcm_malfunction_state_str_table[i].status == status) {
            return snprintf(text, max_len, "\"%s(%d)\"", dcmpf_diag_dtc_dcm_malfunction_state_str_table[i].str, status);
        }
    }
    return snprintf(text, max_len, "%d", status);
}

