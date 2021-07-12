#include <iostream>
#include <vector>
#include <memory>



class X {
public:
    int x,y,z;
    virtual void f() {
        std::cout << "X here\n";
    }
};

class XX : public X {
public:
    virtual void f() override{  //这里的override是显式替换掉父类中的虚函数，实际上即使没有override，也会替换的。
        std::cout << "XX here\n";
    }
};

int main(int argc, char **argV) {
    
    std::unique_ptr<X> x(new X());
    std::unique_ptr<X> xx(new XX()); // pass XX to X*
    
    x->f();
    xx->f();
    
    
    return 0;
    
}