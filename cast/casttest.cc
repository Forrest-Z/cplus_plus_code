
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <exception>
#include <typeinfo>


class Modify {
public:
    virtual ~Modify() { }
    Modify(char *temp) {
        strncpy(temp, "value", 5);
        this->temp = temp;
    }
    void output() {
        std::cout << temp << "\n";
    }
protected:
    char *temp;
};



class ModifyPrint : public Modify {
public:
    virtual ~ModifyPrint() { }
    ModifyPrint() = default;
    ModifyPrint(char *temp) : Modify(temp) { }
    void output() {
        std::cout << "Value is: " << temp << "\n";
    }
    
};


struct Values {
    int x,y,z;
    unsigned long value;
    Values() = default;
    Values(int x, int y, int z, unsigned long value) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->value = value;
    }
};

/*
dynamic_cast用来处理一种“安全向下转换”，当我们将父类指针指向一个new出来的子类A对象时，如果该父类有多个不同子类（class A，class B,），那么可以
使用dynamic_cast将该指针类型安全转换为A*，如果使用强转操作符或者下面介绍的static_cast，那么将其转换为B*理论上也是可以的，但是使用上就会有
错误：比如，类A有的成员函数，类B没有。
*/
void castTest(Modify &m) {
    try {
        ModifyPrint &p = dynamic_cast<ModifyPrint&>(m);
        p.output();
        std::cout << "Cast succeded.\n";
    } catch(std::bad_cast &e) {
        std::cout << "Cast test:\n";
        std::cerr <<  "Exception: " << e.what() << "\n";
        std::cerr << "Cast is not of type ModifyPrint..\n";
    }
}

/*reinterpret_cast是特意用于底层的强制转型，导致实现依赖（就是说，不可移植）的结果，例如，将一个
指针转型为一个整数。这样的强制类型在底层代码以外应该极为罕见。操作结果只是简单的从
一个指针到别的指针的值的二进制拷贝。在类型之间指向的内容不做任何类型的检查和转换。
*/

void func(std::string &str){
    std::cout<<str<<std::endl;
}



int main(int argc, char **argv) {
    const std::string nn="sfsfsfs";
    func(const_cast<std::string&>(nn));
/////////////////////////////////////////
    const int &a = 12;
    const_cast<int&>(a) = 1;
    std::cout<<"a="<<a<<std::endl;


    const int b = 12;
    const_cast<int&>(b) = 1;
    std::cout<<"a="<<b<<std::endl;


    const int* c = new int;
    *(const_cast<int *>(c)) = 1;
    int* mm = const_cast<int *>(c);
    *mm = 34;
    std::cout<<"mm="<<*mm<<std::endl;

    
    const char *text = new char [6];

    // remove const
    Modify m(const_cast<char*>(text));
    m.output();
    
    
    std::fstream file;
    file.open("text.txt", std::ios::out | std::ios::binary);
    if(!file.is_open()) {
        std::cerr << " Could not open text.txt\n";
        return -1;
    }
    
    Values val(100, 100, 200, 200);
    // reinterpret_cast from one type to another
    file.write(reinterpret_cast<char*>(&val), sizeof(val));
    file.close();
    
    // cast from long to int
    int x = 0;
    long value = 0xFFFF;
    x = static_cast<int>(value);
    
    std::cout << "Here is the value: " << x << " ..\n";
 
    Modify *values[3];
    values[0] = new ModifyPrint(const_cast<char*>(text));
    values[1] = new ModifyPrint(const_cast<char*>(text));
    values[2] = new Modify(const_cast<char*>(text));
    
    for(unsigned int i = 0; i < 3; ++i) {
        castTest(*values[i]);
        delete values[i];
    }
    
    delete [] text;
    
    
    return 0;
}
