

#pragma once

#include <gflags/gflags.h>


// IP & PORT
DECLARE_string(grpc_client_host);
DECLARE_string(grpc_server_host);
DECLARE_string(grpc_client_port);
DECLARE_string(grpc_server_port);
DECLARE_string(grpc_debug_server_port);

// Other Flags
DECLARE_int64(x2v_traffic_light_timer_frequency);
DECLARE_int64(v2x_car_status_timer_frequency);
DECLARE_double(traffic_light_distance);
DECLARE_double(heading_difference);
DECLARE_int64(list_size);
DECLARE_int64(msg_timeout);
DECLARE_int64(sim_sending_num);
DECLARE_bool(use_nearest_flag);
DECLARE_int64(spat_period);
DECLARE_double(check_time);
DECLARE_int64(rsu_whitelist_period);
DECLARE_string(rsu_whitelist_name);

