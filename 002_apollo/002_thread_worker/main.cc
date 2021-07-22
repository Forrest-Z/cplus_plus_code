#include "thread_worker.h"

class Cam_ThreadWorker : public ThreadWorker{
public:
  Cam_ThreadWorker() {}
  ~Cam_ThreadWorker() {}



};


int main(int argc, char** argv){
  ThreadWorker* thread1 = new Cam_ThreadWorker;
  thread1->Start();
  Cam_ThreadWorker thread2;

  return 0;
}
