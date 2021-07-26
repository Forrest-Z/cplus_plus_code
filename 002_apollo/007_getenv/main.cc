#include "environment.h"


int main(int argc, char** argv)
{
  std::string path;
  path = apollo::cyber::common::GetEnv("LD_LIBRARY_PATH");
  std::cout<<path<<std::endl;



  return 0;
}
