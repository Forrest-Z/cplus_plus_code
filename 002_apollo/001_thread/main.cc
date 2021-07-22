#include "thread.h"

class Cam_Thread : public Thread{
public:
  Cam_Thread() {}
  ~Cam_Thread() {}
  virtual void Run() override{
    std::cout<<"Cam_Thread Run()"<<std::endl; 
  }


};


int main(int argc, char** argv){
  Thread* thread1 = new Cam_Thread;
  thread1->Start();
  thread1->Run();

  Cam_Thread thread2;
  thread2.Start();
  thread2.Run();

  return 0;
}
