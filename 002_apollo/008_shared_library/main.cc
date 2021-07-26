#include <iostream>
#include "shared_library.h"
#include "exceptions.h"
#include <memory>


const std::string& sample_lib = "/home/public/Project/cplus_plus_code/002_apollo/008_shared_library/build/bin/libsample.so";

int main(int argc, char** argv)
{
  std::shared_ptr<apollo::cyber::class_loader::SharedLibrary> shared_lib = 
    std::make_shared<apollo::cyber::class_loader::SharedLibrary>();
  shared_lib->Load(sample_lib);

  shared_lib->HasSymbol("sample_add");
  auto symbol = shared_lib->GetSymbol("sample_add");
  typedef int(*fun)(int, int);
  auto pf = reinterpret_cast<fun>(symbol);
  pf(3, 5);
  shared_lib->Unload();

  return 0;
}

