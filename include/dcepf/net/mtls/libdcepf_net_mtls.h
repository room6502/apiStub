/**
 * @file libdcepf_net_mtls.h
 * @copyright Copyright (c) 2022 TOYOTA MOTOR CORPORATION All Rights Reserved.
 *
 */

#ifndef LIBDCEPF_NET_MTLS_H
#define LIBDCEPF_NET_MTLS_H

#include <dcepf/common/libdcepf_type.h>
#include <dcepf/common/libdcepf_error.h>
#include <openssl/ssl.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*
 *********************************************************
 * DATA DEFINITION
 *********************************************************
 */

/*
 *********************************************************
 * CALLBACK FUNCTION DEFINITION
 *********************************************************
 */
/**
 * @brief The function related to get Client Certification from eUICC
 *
 * @param [in] handle       Context handle.
 * @param [in] order_no     Number of order.
 *
 * @details
 * The function related to get Client Certification from eUICC.
 *
 */
typedef void (*dcepf_net_mtls_request_euicc_cert_cb_t)(
    dcepf_handle_t handle,
    uint8_t order_no
);

/**
 * @brief The function related to signature requests to eUICC
 *
 * @param [in] handle       Context handle.
 * @param [in] order_no     Number of order.
 * @param [in] data         Data to be signed.
 * @param [in] data_len     Length of data to be signed.
 * @param [in] signature    Client signature.
 *
 * @details
 * The function related to signature requests to eUICC.
 *
 */
typedef void (*dcepf_net_mtls_request_euicc_sig_cb_t)(
    dcepf_handle_t handle,
    uint8_t order_no,
    const uint8_t *data,
    size_t data_len,
    uint8_t *signature
);

/**
 * @brief The function related to random number generation requests to eUICC
 *
 * @param [in] handle       Context handle.
 * @param [in] order_no     Number of order.
 * @param [in] rand         Random number.
 * @param [in] rand_len     Length of random to be generated.
 *
 * @details
 * The function related to random number generation requests to eUICC.
 *
 */
typedef void (*dcepf_net_mtls_request_rand_num_gen_cb_t)(
    dcepf_handle_t handle,
    uint8_t order_no,
    uint8_t *rand,
    size_t rand_len
);

/*
 *********************************************************
 * DCE PF API DEFINITION
 *********************************************************
 */
/**
 * @brief The function related to get Client Certification from eUICC
 *
 * @param [in] handle       Context handle.
 * @param [in] sslctx       SSL Context defined by OpenSSL.
 * @param [in] callback     Callback function.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_ALREADY         Already operated.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Register call-back function to get Client Certificates from eUICC. @n
 * The call-back function should work with SSL_CTX specified in argument and be called when DCE PF request to DCE to get Client Certificates from eUICC. @n
 * @n
 * This API and registered function work in the same context of caller's process.
 *
 */
dcepf_api_status_t dcepf_net_mtls_register_euicc_cert(
    dcepf_handle_t handle,
    SSL_CTX *sslctx,
    dcepf_net_mtls_request_euicc_cert_cb_t callback
);

/**
 * @brief The function related to get Client Certification from eUICC
 *
 * @param [in] handle       Context handle.
 * @param [in] sslctx       SSL Context defined by OpenSSL.
 * @param [in] callback     Callback function.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Unregister the function to get Client Certificates from eUICC. @n
 * This API works in the same context of caller's process.
 *
 */
dcepf_api_status_t dcepf_net_mtls_unregister_euicc_cert(
    dcepf_handle_t handle,
    SSL_CTX *sslctx,
    dcepf_net_mtls_request_euicc_cert_cb_t callback
);

/**
 * @brief The function related to get Client Certification from eUICC
 *
 * @param [in] handle       Context handle.
 * @param [in] order_no     Number of order.
 * @param [in] cert         Client certificate.
 * @param [in] cert_len     Length of client certificate.
 * 
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * DCE notifies DCE PF of the result of getting Client Certificates from eUICC.
 *
 */
dcepf_api_status_t dcepf_net_mtls_report_euicc_cert(
    dcepf_handle_t handle,
    uint8_t order_no,
    uint8_t *cert,
    size_t cert_len
);

/**
 * @brief The function related to signature requests to eUICC
 *
 * @param [in] handle       Context handle.
 * @param [in] sslctx       SSL Context defined by OpenSSL.
 * @param [in] callback     Callback function.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_ALREADY         Already operated.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Register call-back function to request signature to eUICC. @n
 * The call-back function should work with SSL_CTX specified in argument and be called when DCE PF request to DCE to request signature to eUICC. @n
 * @n
 * This API and registered function work in the same context of caller's process.
 *
 */
dcepf_api_status_t dcepf_net_mtls_register_euicc_sig(
    dcepf_handle_t handle,
    SSL_CTX *sslctx,
    dcepf_net_mtls_request_euicc_sig_cb_t callback
);

/**
 * @brief The function related to signature requests to eUICC
 *
 * @param [in] handle       Context handle.
 * @param [in] sslctx       SSL Context defined by OpenSSL.
 * @param [in] callback     Callback function.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Unregister the function to request signature to eUICC. @n
 * This API works in the same context of caller's process.
 *
 */
dcepf_api_status_t dcepf_net_mtls_unregister_euicc_sig(
    dcepf_handle_t handle,
    SSL_CTX *sslctx,
    dcepf_net_mtls_request_euicc_sig_cb_t callback
);

/**
 * @brief The function related to signature requests to eUICC
 *
 * @param [in] handle           Context handle.
 * @param [in] order_no         Number of order.
 * @param [in] signature        Client signature.
 * @param [in] signature_len    Length of client signature.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * DCE notifies DCE PF of the result of signature request to eUICC.
 *
 */
dcepf_api_status_t dcepf_net_mtls_report_euicc_sig(
    dcepf_handle_t handle,
    uint8_t order_no,
    uint8_t *signature,
    size_t signature_len
);

/**
 * @brief The function related to random number generation requests to eUICC
 *
 * @param [in] handle       Context handle.
 * @param [in] sslctx       SSL Context defined by OpenSSL.
 * @param [in] callback     Callback function.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_ALREADY         Already operated.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Register call-back function to request random number generation to eUICC. @n
 * The call-back function should work with SSL_CTX specified in argument and be called when DCE PF request to DCE to request random number to eUICC. @n
 * @n
 * This API and registered function work in the same context of caller's process.
 *
 */
dcepf_api_status_t dcepf_net_mtls_register_rand_num_gen(
    dcepf_handle_t handle,
    SSL_CTX *sslctx,
    dcepf_net_mtls_request_rand_num_gen_cb_t callback
);

/**
 * @brief The function related to random number generation requests to eUICC
 *
 * @param [in] handle       Context handle.
 * @param [in] sslctx       SSL Context defined by OpenSSL.
 * @param [in] callback     Callback function.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * Unregister the function to request random number generation to eUICC. @n
 * This API works in the same context of caller's process.
 *
 */
dcepf_api_status_t dcepf_net_mtls_unregister_rand_num_gen(
    dcepf_handle_t handle,
    SSL_CTX *sslctx,
    dcepf_net_mtls_request_rand_num_gen_cb_t callback
);

/**
 * @brief The function related to random number generation requests to eUICC
 *
 * @param [in] handle       Context handle.
 * @param [in] order_no     Number of order.
 * @param [in] rand         Client random.
 * @param [in] rand_len     Length of client random.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * DCE notifies DCE PF of the result of random number generation request to eUICC.
 *
 */
dcepf_api_status_t dcepf_net_mtls_report_rand_num_gen(
    dcepf_handle_t handle,
    uint8_t order_no,
    uint8_t *rand,
    size_t rand_len
);

/**
 * @brief Register Call-back Function for Server Certificate Verification
 *
 * @param [in] handle       Context handle.
 * @param [in] sslctx       SSL Context defined by OpenSSL.
 *
 * @retval DCEPF_API_STATUS_SUCCESS         Success.
 * @retval DCEPF_API_STATUS_INVALID_PARAM   Invalid parameter.
 * @retval DCEPF_API_STATUS_FAILED          Failed.
 *
 * @details
 * DCE-PF registers a function for server certificate verification. @n
 * The call-back function should work with SSL_CTX specified in argument and be called when DCE PF request to DCE to request random number to eUICC. @n
 * @n
 * This API and registered function work in the same context of caller's process. @n
 * @n
 * The following must be supported by the registered callback function. @n
 *   - Use the root certificate stored in the DCE PF secure area when verifying the server certificate.
 *   - The certificate verification process should be protected by the DCE PF secure function.
 *   - Registered function should verify that certificate is not revoked by CRLs (Certificate Revocation Lists).
 *   - Registered function should confirm that the CRL has not expired when checking the revocation of the certificate. 
 *   - If the CRL has expired, registered function should download the latest CRL from  CDP (CRL Distribution Point) listed in the certificate or CDP specified by DCE.
 *   - The DCE PF shall provide the DCE with an API to update the CDP settings.
 *
 */
dcepf_api_status_t dcepf_net_mtls_set_server_cert_callback(
    dcepf_handle_t handle,
    SSL_CTX *sslctx
);

#ifdef __cplusplus
}
#endif

#endif  /* LIBDCEPF_NET_MTLS_H */
