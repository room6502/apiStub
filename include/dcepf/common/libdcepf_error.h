/**
 * @file libdcepf_error.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 */

#ifndef LIBDCEPF_ERROR_H
#define LIBDCEPF_ERROR_H

/*
 *********************************************************
 * DATA DEFINITION
 *********************************************************
 */
/**
 * @brief Return code from API
 */
typedef enum {
    /**
     * @brief Success
     */
    DCEPF_API_STATUS_SUCCESS,
    /**
     * @brief Failed
     */
    DCEPF_API_STATUS_FAILED,
    /**
     * @brief Invalid parameter
     */
    DCEPF_API_STATUS_INVALID_PARAM,
    /**
     * @brief Busy
     */
    DCEPF_API_STATUS_BUSY,
    /**
     * @brief Not ready to use
     */
    DCEPF_API_STATUS_NOT_READY,
    /**
     * @brief Already operated
     */
    DCEPF_API_STATUS_ALREADY,
    /**
     * @brief No such target data
     */
    DCEPF_API_STATUS_NO_SUCH,
    /**
     * @brief No response of target
     */
    DCEPF_API_STATUS_NO_RESPONSE,
    /**
     * @brief Not supported operation
     */
    DCEPF_API_STATUS_NOT_SUPPORTED,
    /**
     * @brief Not allowed operation
     */
    DCEPF_API_STATUS_NOT_ALLOWED,
    /**
     * @brief Out of bounds
     */
    DCEPF_API_STATUS_OUT_OF_BOUNDS
} dcepf_api_status_t;

/**
 * @brief Result code
 */
typedef enum {
    /**
     * @brief Success
     */
    DCEPF_RESULT_SUCCESS,
    /**
     * @brief Failed
     */
    DCEPF_RESULT_FAILED,
    /**
     * @brief Busy
     */
    DCEPF_RESULT_BUSY,
    /**
     * @brief Already operated
     */
    DCEPF_RESULT_ALREADY,
    /**
     * @brief Cancel
     */
    DCEPF_RESULT_CANCEL
} dcepf_result_t;

#endif /* LIBDCEPF_ERROR_H */
