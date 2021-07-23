

#include <iostream>
#include <cassert>
#include <exception>

/*
原理：assert的作用是现计算表达式 expression ，如果其值为假（即为0），那么它先
向stderr打印一条出错信息，然后通过调用 abort 来终止程序运行。
*/

//可以通过继承和重载 exception 类来定义新的异常。下面的实例演示了如何使用 std::exception 类来实现自己的异常：
struct MyException : public std::exception {
  const char * what () const throw ()
  {
    return "C++ Exception";
  }
};




int main() {
    int x = 1;
    int y = 5;
//    assert(5 == 6);
    std::cout << "(x+y) == 5\n";

  try
  {
    throw MyException();
  }
  catch(MyException& e)
  {
    std::cout << "MyException caught" << std::endl;
    std::cout << e.what() << std::endl;
  }
  catch(std::exception& e)
  {
    //其他的错误
  }





    try{
        if(x != 2)
            throw "sssssssssss";    //由于我们抛出了一个类型为 const char* 的异常，因此，当捕获该异常时，我们必须在 catch 块中使用 const char*。
        else
            throw 1;
    }
    catch(const char* msg){
        std::cout <<msg<<std::endl;
    }



    try{
        if(x == 2)
            throw "ddd";
        else
            throw 2;
    }
    catch(int m){
        std::cout<<"m="<<m<<std::endl;
    }



    // assert should be true
    assert((x*y) == 5);
    char *ptr = new char [100];
    // should be true
    assert(ptr != 0);
    delete [] ptr;
    ptr = 0;
    // should fail
    assert(ptr != 0);
	return 0;
}
