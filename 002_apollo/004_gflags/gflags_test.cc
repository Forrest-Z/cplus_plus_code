#include <iostream>
#include "gflags_test.h"


// IP & PORT
DEFINE_string(grpc_client_host, "127.0.0.1", "grpc client host ip");
DEFINE_string(grpc_server_host, "127.0.0.1", "grpc server host ip");
DEFINE_string(grpc_client_port, "50100", "grpc client port");
DEFINE_string(grpc_server_port, "50101", "grpc server port");
DEFINE_string(grpc_debug_server_port, "50102", "grpc server debug port");

// Other Flags
DEFINE_int64(x2v_traffic_light_timer_frequency, 10,
             "x2v traffic_light timer frequency");
DEFINE_int64(v2x_car_status_timer_frequency, 10,
             "v2x car_status timer frequency");
DEFINE_double(traffic_light_distance, 250.0, "traffic light distance in m");
DEFINE_double(heading_difference, 30.0 / 180.0,
              "max heading difference in rad");
DEFINE_int64(list_size, 6, "size of list which stores the traffic light data");
DEFINE_int64(msg_timeout, 250, "timeout value which getting the msg from OBU");
DEFINE_int64(sim_sending_num, 10, "the max sending times");
DEFINE_bool(use_nearest_flag, true,
            "use the hdmap interface get_forward_nearest_signals_on_lane flag");
DEFINE_int64(spat_period, 150, "SPAT message period in ms");
DEFINE_double(check_time, 0.5, "SPAT message period in s");
DEFINE_int64(rsu_whitelist_period, 3 * 1000,
             "get whitelist period in ms");  // 3s
DEFINE_string(rsu_whitelist_name, "/apollo/modules/v2x/conf/rsu_whitelist.txt",
              "file name for RSU whitelist");



int main(int argc, char** argv)
{
  google::ParseCommandLineFlags(&argc, &argv, true);

  std::cout<<"grpc_client_host:"<<FLAGS_grpc_client_host<<std::endl;
  
  return 0;
}
