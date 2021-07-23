#include "thread.h"
#include <csignal>
#include <iostream>

void Thread::Start() {
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(
          &attr, joinable_ ? PTHREAD_CREATE_JOINABLE : PTHREAD_CREATE_DETACHED);
  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, nullptr);
  pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, nullptr);

  int result = pthread_create(&tid_, &attr, &ThreadRunner, this);
  if(result!=0)
    std::cout<<"Could not create thread:" << result << std::endl;

  pthread_attr_destroy(&attr);

  started_ = true;
}

void Thread::Join() {
//  ACHECK(joinable_) << "Thread is not joinable";
  int result = pthread_join(tid_, nullptr);
  tid_ = 0;
}

bool Thread::IsAlive() {
  if (tid_ == 0) {
    return false;
  }
  // no signal sent, just check existence for thread
  int ret = pthread_kill(tid_, 0);
  if (ret == ESRCH) {
    return false;
  }
  if (ret == EINVAL) {
    std::cout << "Invalid singal."<< std::endl;
    return false;
  }

  return true;
}

