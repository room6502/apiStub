/**
 * @file libdcmpf_diag_c.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 * 
 * @brief \~japanese ダイアグ機能ライブラリ(定数宣言)
 * @brief \~english Diagnostic feature library (constant definition)
 * 
 */
#ifndef LIBDCMPF_DIAG_C_H
#define LIBDCMPF_DIAG_C_H
/**
 * \~japanese @addtogroup dcmpf_diag ダイアグ機能ライブラリ
 * \~english  @addtogroup dcmpf_diag Diagnostic feature library
 * \~ @{
 */
/**
 * \~japanese @addtogroup dcmpf_diag_common ライブラリ共通
 * \~english  @addtogroup dcmpf_diag_common Library common
 * \~ @{
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief \~japanese 前提条件確認結果
 * @brief \~english Precondition check result
 */
typedef enum {
    /**
     * @brief \~japanese 前提条件成立
     * @brief \~english precondition satisfied
     */
    DCMPF_DIAG_PRECONDITION_SATISFIED,

    /**
     * @brief \~japanese 前提条件不成立
     * @brief \~english precondition failure
     */
    DCMPF_DIAG_PRECONDITION_FAILURE,
} dcmpf_diag_precondition_result_t;

/**
 * @brief \~japanese 結果
 * @brief \~english Result
 */
typedef enum {
    /**
     * @brief \~japanese 成功
     * @brief \~english Success
     */
    DCMPF_DIAG_RESULT_SUCCESS,

    /**
     * @brief \~japanese 失敗
     * @brief \~english Failure
     */
    DCMPF_DIAG_RESULT_FAILURE,
} dcmpf_diag_result_t;

/**
 * @brief \~japanese ネガティブレスポンスコード
 * @brief \~english Negative response code
 */
typedef enum {
    /**
     * @brief \~japanese ネガティブレスポンスなし
     * @brief \~english No Negative response
     */
    DCMPF_DIAG_NRC_NO_ERROR= 0x00,
    /**
     * @brief \~japanese generalReject
     * @brief \~english generalReject
     */
    DCMPF_DIAG_NRC_GENERAL_REJECT = 0x10,
    /**
     * @brief \~japanese serviceNotSupported
     * @brief \~english serviceNotSupported
     */
    DCMPF_DIAG_NRC_SERVICE_NOT_SUPPORTED = 0x11,
    /**
     * @brief \~japanese SubFunctionNotSupported
     * @brief \~english SubFunctionNotSupported
     */
    DCMPF_DIAG_NRC_SUBFUNCTION_NOT_SUPPORTED = 0x12,
    /**
     * @brief \~japanese incorrectMessageLengthOrInvalidFormat
     * @brief \~english incorrectMessageLengthOrInvalidFormat
     */
    DCMPF_DIAG_NRC_INCORRECT_MESSAGE_LENGTH_OR_INVALID_FORMAT = 0x13,
    /**
     * @brief \~japanese responseTooLong
     * @brief \~english responseTooLong
     */
    DCMPF_DIAG_NRC_RESPONSE_TOO_LONG = 0x14,
    /**
     * @brief \~japanese busyRepeatRequest
     * @brief \~english busyRepeatRequest
     */
    DCMPF_DIAG_NRC_BUSY_REPEAT_REQUEST = 0x21,
    /**
     * @brief \~japanese ConditionNotCorrect
     * @brief \~english ConditionNotCorrect
     */
    DCMPF_DIAG_NRC_CONDITIONS_NOT_CORRECT = 0x22,
    /**
     * @brief \~japanese requestSequenceError
     * @brief \~english requestSequenceError
     */
    DCMPF_DIAG_NRC_REQUEST_SEQUENCE_ERROR = 0x24,
    /**
     * @brief \~japanese requestOutOfRange
     * @brief \~english requestOutOfRange
     */
    DCMPF_DIAG_NRC_REQUEST_OUT_OF_RANGE = 0x31,
    /**
     * @brief \~japanese securityAccessDenied
     * @brief \~english securityAccessDenied
     */
    DCMPF_DIAG_NRC_SECURITY_ACCESS_DENIED = 0x33,
    /**
     * @brief \~japanese authenticationRequired
     * @brief \~english authenticationRequired
     */
    DCMPF_DIAG_NRC_AUTHENTICATION_REQUIRED = 0x34,
    /**
     * @brief \~japanese invalidKey
     * @brief \~english invalidKey
     */
    DCMPF_DIAG_NRC_INVALID_KEY = 0x35,
    /**
     * @brief \~japanese exceededNumberOfAttempts
     * @brief \~english exceededNumberOfAttempts
     */
    DCMPF_DIAG_NRC_EXCEEDED_NUMBER_OF_ATTEMPTS = 0x36,
    /**
     * @brief \~japanese requiredTimeDelayNotExpired
     * @brief \~english requiredTimeDelayNotExpired
     */
    DCMPF_DIAG_NRC_REQUIRED_TIME_DELAY_NOT_EXPIRED = 0x37,
    /**
     * @brief \~japanese uploadDownloadNotAccepted
     * @brief \~english uploadDownloadNotAccepted
     */
    DCMPF_DIAG_NRC_UPLOAD_DOWNLOAD_NOT_ACCEPTED = 0x70,
    /**
     * @brief \~japanese transferDataSuspended
     * @brief \~english transferDataSuspended
     */
    DCMPF_DIAG_NRC_TRANSFER_DATA_SUSPENDED = 0x71,
    /**
     * @brief \~japanese generalProgrammingFailure
     * @brief \~english generalProgrammingFailure
     */
    DCMPF_DIAG_NRC_GENERAL_PROGRAMMING_FAILURE = 0x72,
    /**
     * @brief \~japanese wrongBlockSequenceCounter
     * @brief \~english wrongBlockSequenceCounter
     */
    DCMPF_DIAG_NRC_WRONG_BLOCK_SEQUENCE_COUNTER = 0x73,
    /**
     * @brief \~japanese functionNotSupportedInActiveSession
     * @brief \~english functionNotSupportedInActiveSession
     */
    DCMPF_DIAG_NRC_SUBFUNCTION_NOT_SUPPOERTED_IN_ACTIVE_SESSION = 0x7E,
    /**
     * @brief \~japanese serviceNotSupportedInActiveSession
     * @brief \~english serviceNotSupportedInActiveSession
     */
    DCMPF_DIAG_NRC_SERVICE_NOT_SUPPORTED_IN_ACTIVE_SESSION = 0x7F,
    /**
     * @brief \~japanese engineIsRunning
     * @brief \~english engineIsRunning
     */
    DCMPF_DIAG_NRC_ENGINE_IS_RUNNING = 0x83,
    /**
     * @brief \~japanese engineIsNotRunning
     * @brief \~english engineIsNotRunning
     */
    DCMPF_DIAG_NRC_ENGINE_IS_NOT_RUNNING = 0x84,
    /**
     * @brief \~japanese vehicleSpeedTooHigh
     * @brief \~english vehicleSpeedTooHigh
     */
    DCMPF_DIAG_NRC_VEHICLE_SPEED_TOO_HIGH = 0x88,
    /**
     * @brief \~japanese vehicleSpeedTooLow
     * @brief \~english vehicleSpeedTooLow
     */
    DCMPF_DIAG_NRC_VEHICLE_SPEED_TOO_LOW = 0x89,
    /**
     * @brief \~japanese transmissionRangeNotInNeutral
     * @brief \~english transmissionRangeNotInNeutral
     */
    DCMPF_DIAG_NRC_TRANSMISSION_RANGE_NOT_IN_NEUTRAL = 0x8C,
    /**
     * @brief \~japanese transmissionRangeNotInGear
     * @brief \~english transmissionRangeNotInGear
     */
    DCMPF_DIAG_NRC_TRANSMISSION_RANGE_NOT_IN_GEAR = 0x8D,
    /**
     * @brief \~japanese shifterLeverNotInPark
     * @brief \~english shifterLeverNotInPark
     */
    DCMPF_DIAG_NRC_SHIFTERLEVER_NOT_IN_PARK = 0x90,
    /**
     * @brief \~japanese voltageTooHigh
     * @brief \~english voltageTooHigh
     */
    DCMPF_DIAG_NRC_VOLTAGE_TOO_HIGH = 0x92,
    /**
     * @brief \~japanese voltageTooLow
     * @brief \~english voltageTooLow
     */
    DCMPF_DIAG_NRC_VOLTAGE_TOO_LOW = 0x93,
} dcmpf_diag_nrc_t;

#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
#endif	/* LIBDCMPF_DIAG_C_H */
