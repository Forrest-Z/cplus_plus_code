
#include <iostream>
#include <thread>
#include <unistd.h>
#include <atomic>
#include <list>
/*
std::atomic为C++11封装的原子数据类型。
什么是原子数据类型？
从功能上看，简单地说，原子数据类型不会发生数据竞争，能直接用在多线程中而不必我们用户
对其进行添加互斥资源锁的类型。从实现上，大家可以理解为这些原子类型内部自己加了锁。
*/


/*
std::atomic<int> value; // value can be used by both threads without worry

void thread1() {
    // testing value
    while(value != 1) {
        std::cout << "Checking Values...\n";
    }
    std::cout << "value changed.\n";
}

void thread2() {
    sleep(2);
    // set the value
    value = 1;
}


int main(int argc, char **argv) {

    std::cout << "adding threads..\n";
    // creating the threads
    std::thread t1(thread1);
    std::thread t2(thread2);
    
    
    // wait for the threads to finish before exiting
    t1.join();
    t2.join();
    return 0;
}

*/




//std::atomic_int iCount(0);
int iCount = 0;


void threadfun1()
{
    for(int i =0; i< 1000; i++)
    {
        printf("iCount:%d\r\n",  iCount++);
    }    
}
void threadfun2()
{
    for(int i =0; i< 1000; i++)
    {
        printf("iCount:%d\r\n",  iCount--);
    }    
}

int main()
{
    std::list<std::thread> lstThread;
    for (int i=0; i< 100; i++)
    {
        lstThread.push_back(std::thread(threadfun1));
    }
    for (int i=0; i< 100; i++)
    {
        lstThread.push_back(std::thread(threadfun2));
    }
    
    for (auto& th: lstThread)
    {
        th.join();
    }

    printf("finally iCount:%d\r\n",  iCount);
//    int x = iCount.load(std::memory_order_relaxed);
//    printf("finally iCount:%d\r\n",  x);
}


