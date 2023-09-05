/**
 * @file libdcepf_loc_gnss.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 */
#ifndef LIBDCEPF_LOC_GNSS_H
#define LIBDCEPF_LOC_GNSS_H

#include <time.h>
#include <dcepf/common/libdcepf_type.h>
#include <dcepf/common/libdcepf_error.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*
 *********************************************************
 * DATA DEFINITION
 *********************************************************
 */
/**
 * @brief Location information.
 */
typedef struct {
    /**
     * @brief Obtained time.
     */
    time_t acquision_time;
    /**
     * @brief Latitude.
     */
    float latitude;
    /**
     * @brief Longitude.
     */
    float longitude;
    /**
     * @brief Altitude.
     */
    float altitude;
    /**
     * @brief Geoid height.
     */
    float geoid_height;
    /**
     * @brief PDOP
     */
    float pdop;
    /**
     * @brief HDOP
     */
    float hdop;
    /**
     * @brief VDOP
     */
    float vdop;
    /**
     * @brief Error ellipse semi-minor axis.
     */
    int32_t error_ellipse_semi_minor_axis;
    /**
     * @brief Error ellipse semi-major axis.
     */
    int32_t error_ellipse_semi_major_axis;
} dcepf_loc_gnss_location_info_t;

/*
 *********************************************************
 * DCE PF API DEFINITION
 *********************************************************
 */
/**
 * @brief Request to Get Location Information
 *
 * @param [in] handle           Context handle.
 * @param [out] location_info   Location information.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_NO_SUCH         No such target data.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Notify DCE of the latest location information successfully acquired by DCE PF. @n
 * If DCE PF cannot fix location by signal lost or other reasons, DCE PF notifies DCE of the last fixed location information. @n
 * If DCE PF has never fix location, DCE PF returns DCEPF_API_STATUS_NO_SUCH.
 *
 */
dcepf_api_status_t dcepf_loc_gnss_get_location_info(
    dcepf_handle_t handle,
    dcepf_loc_gnss_location_info_t *location_info
);

#ifdef __cplusplus
}
#endif

#endif  /* LIBDCEPF_LOC_GNSS_H */
