#include "singleton.h"

class Camera_Singleton {
public:
//  ~Camera_Singleton() {}

private:

  DECLARE_SINGLETON(Camera_Singleton)
};



Camera_Singleton::Camera_Singleton() {}




int main(int argc, char** argv){
  Camera_Singleton* camera1 = Camera_Singleton::Instance();
//  Camera_Singleton camera2;
  for(;;);
  return 0;
}
