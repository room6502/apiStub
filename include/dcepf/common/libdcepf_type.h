/**
 * @file libdcepf_type.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 */

#ifndef LIBDCEPF_TYPE_H
#define LIBDCEPF_TYPE_H

#include <stddef.h>
#include <stdint.h>
#include <dcepf/common/libdcepf_error.h>

/*
 *********************************************************
 * DATA DEFINITION
 *********************************************************
 */
typedef void* dcepf_handle_t;

/*
 *********************************************************
 * CALLBACK FUNCTION DEFINITION
 *********************************************************
 */
typedef void (*dcepf_operation_result_cb_t)(dcepf_handle_t handle, dcepf_result_t result);

#endif /* LIBDCEPF_TYPE_H */
