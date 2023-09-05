/* Copyright (c) 2023 DENSO CORPORATION All Rights Reserved. */
#include <stdio.h>
#include <string.h>
#include <apiMonitor_parse_primitive.h>
#include <apiMonitor_dcmpf_parse_typedef.h>
#include <apiMonitor_dcmpf_parse_struct.h>
#include <apiMonitor_dcmpf_parse_enum.h>

int parse_dcmpf_handle_impl_t(char *text, int max_len, dcmpf_handle_impl_t *p) {
    int len = 0;

    len = snprintf(text, max_len,
        "{"
        "\"m_handle\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_uint16_t(text + len, max_len - len, p->m_handle);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"data\": \"unsupported\"");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        "}");
    if(len > max_len - 1){
        return max_len - 1;
    }

    return len;
}

