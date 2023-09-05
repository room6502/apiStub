/* Copyright (c) 2023 DENSO CORPORATION All Rights Reserved. */
#include <stdio.h>
#include <string.h>
#include <apiMonitor_parse_primitive.h>
#include <apiMonitor_dcepf_parse_typedef.h>
#include <apiMonitor_dcepf_parse_struct.h>
#include <apiMonitor_dcepf_parse_enum.h>

int parse_dcepf_sys_wd_device_state_list_t(char *text, int max_len, dcepf_sys_wd_device_state_list_t *p) {
    int len = 0;

    len = snprintf(text, max_len,
        "{"
        "\"esim_state\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_dcepf_sys_wd_device_state_t(text + len, max_len - len, p->esim_state);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"esim_error_code\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_int32_t(text + len, max_len - len, p->esim_error_code);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"cellular_rf_state\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_dcepf_sys_wd_device_state_t(text + len, max_len - len, p->cellular_rf_state);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"cellular_rf_error_code\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_int32_t(text + len, max_len - len, p->cellular_rf_error_code);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"wifi_rf_state\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_dcepf_sys_wd_device_state_t(text + len, max_len - len, p->wifi_rf_state);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"wifi_rf_error_code\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_int32_t(text + len, max_len - len, p->wifi_rf_error_code);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"gnss_state\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_dcepf_sys_wd_device_state_t(text + len, max_len - len, p->gnss_state);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"gnss_error_code\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_int32_t(text + len, max_len - len, p->gnss_error_code);
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

int parse_dcepf_loc_gnss_location_info_t(char *text, int max_len, dcepf_loc_gnss_location_info_t *p) {
    int len = 0;

    len = snprintf(text, max_len,
        "{"
        "\"acquision_time\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_time_t(text + len, max_len - len, p->acquision_time);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"latitude\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_float(text + len, max_len - len, p->latitude);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"longitude\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_float(text + len, max_len - len, p->longitude);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"altitude\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_float(text + len, max_len - len, p->altitude);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"geoid_height\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_float(text + len, max_len - len, p->geoid_height);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"pdop\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_float(text + len, max_len - len, p->pdop);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"hdop\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_float(text + len, max_len - len, p->hdop);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"vdop\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_float(text + len, max_len - len, p->vdop);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"error_ellipse_semi_minor_axis\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_int32_t(text + len, max_len - len, p->error_ellipse_semi_minor_axis);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"error_ellipse_semi_major_axis\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_int32_t(text + len, max_len - len, p->error_ellipse_semi_major_axis);
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

int parse_dcepf_net_ipv4addr_inf_t(char *text, int max_len, dcepf_net_ipv4addr_inf_t *p) {
    int len = 0;

    len = snprintf(text, max_len,
        "{"
        "\"valid_if_addr\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_bool(text + len, max_len - len, p->valid_if_addr);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"if_addr\": \"<...>\"");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"if_prefix\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_int32_t(text + len, max_len - len, p->if_prefix);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"if_mtu\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_int32_t(text + len, max_len - len, p->if_mtu);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"valid_gw_addr\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_bool(text + len, max_len - len, p->valid_gw_addr);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"gw_addr\": \"<...>\"");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"valid_pri_dns_addr\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_bool(text + len, max_len - len, p->valid_pri_dns_addr);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"pri_dns_addr\": \"<...>\"");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"valid_sec_dns_addr\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_bool(text + len, max_len - len, p->valid_sec_dns_addr);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"sec_dns_addr\": \"<...>\"");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"device_name\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_char_p_ascii(text + len, max_len - len, p->device_name, DCEPF_NET_MAX_IF_NAME_LENGTH);
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

int parse_dcepf_net_ipv6addr_inf_t(char *text, int max_len, dcepf_net_ipv6addr_inf_t *p) {
    int len = 0;

    len = snprintf(text, max_len,
        "{"
        "\"valid_if_addr\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_bool(text + len, max_len - len, p->valid_if_addr);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"if_addr\": \"<...>\"");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"if_prefix\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_int32_t(text + len, max_len - len, p->if_prefix);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"if_mtu\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_int32_t(text + len, max_len - len, p->if_mtu);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"valid_gw_addr\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_bool(text + len, max_len - len, p->valid_gw_addr);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"gw_addr\": \"<...>\"");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"valid_pri_dns_addr\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_bool(text + len, max_len - len, p->valid_pri_dns_addr);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"pri_dns_addr\": \"<...>\"");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"valid_sec_dns_addr\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_bool(text + len, max_len - len, p->valid_sec_dns_addr);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"sec_dns_addr\": \"<...>\"");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"device_name\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_char_p_ascii(text + len, max_len - len, p->device_name, DCEPF_NET_MAX_IF_NAME_LENGTH);
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

int parse_dcepf_net_ccs_cell_information_t(char *text, int max_len, dcepf_net_ccs_cell_information_t *p) {
    int len = 0;

    len = snprintf(text, max_len,
        "{"
        "\"cell_connection_status\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_dcepf_net_ccs_cell_connection_status_t(text + len, max_len - len, p->cell_connection_status);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"mcc_id\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_int32_t(text + len, max_len - len, p->mcc_id);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"mnc_id\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_int32_t(text + len, max_len - len, p->mnc_id);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"area_id\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_int32_t(text + len, max_len - len, p->area_id);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"cell_id\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_int32_t(text + len, max_len - len, p->cell_id);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"rat\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_dcepf_net_ccs_rat_t(text + len, max_len - len, p->rat);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"barring_status\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_dcepf_net_ccs_barring_status_t(text + len, max_len - len, p->barring_status);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"network_type\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_dcepf_net_ccs_network_type_t(text + len, max_len - len, p->network_type);
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

int parse_dcepf_net_ip_routing_entry_v4_t(char *text, int max_len, dcepf_net_ip_routing_entry_v4_t *p) {
    int len = 0;

    len = snprintf(text, max_len,
        "{"
        "\"source_addr\": \"<...>\"");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"source_port_low\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_in_port_t(text + len, max_len - len, p->source_port_low);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"source_port_high\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_in_port_t(text + len, max_len - len, p->source_port_high);
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

int parse_dcepf_net_ip_routing_entry_v6_t(char *text, int max_len, dcepf_net_ip_routing_entry_v6_t *p) {
    int len = 0;

    len = snprintf(text, max_len,
        "{"
        "\"source_addr\": \"<...>\"");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"source_port_low\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_in_port_t(text + len, max_len - len, p->source_port_low);
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += snprintf(text + len, max_len - len,
        ",\"source_port_high\": ");
    if(len > max_len - 1){
        return max_len - 1;
    }

    len += parse_in_port_t(text + len, max_len - len, p->source_port_high);
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

