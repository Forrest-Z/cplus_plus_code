/*
在C++11中，标准库在<utility>中提供了一个有用的函数std::move，std::move并不能移动任何东西，它唯一的功能是将一个左值
强制转化为右值引用，继而可以通过右值引用使用该值，以用于移动语义。从实现上讲，std::move基本等同于一个类型转换：static_cast<T&&>(lvalue);
(1)C++ 标准库使用比如vector::push_back 等这类函数时,会对参数的对象进行复制,连数据也会复制.这就会造成对象内存的额外创建, 本来原意是想
把参数push_back进去就行了,通过std::move，可以避免不必要的拷贝操作。
(2)std::move是将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存的搬迁或者内存拷贝所以可以提高利用效率,改善性能。
(3)对指针类型的标准库对象并不需要这么做.
下面的例子原lvalue值被moved from之后值被转移,所以为空字符串：
#include <iostream>
#include <utility>
#include <vector>
#include <string>
int main()
{
    std::string str = "Hello";
    std::vector<std::string> v;
    //调用常规的拷贝构造函数，新建字符数组，拷贝数据
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n";
    //调用移动构造函数，掏空str，掏空后，最好不要使用str
    v.push_back(std::move(str));
    std::cout << "After move, str is \"" << str << "\"\n";
    std::cout << "The contents of the vector are \"" << v[0]
                                         << "\", \"" << v[1] << "\"\n";
}
输出为：
After copy, str is "Hello"
After move, str is ""
The contents of the vector are "Hello", "Hello"
*/



#include<iostream>
#include<vector>
#include<string>
#include<sstream>


class MoveVector {
public:
    explicit MoveVector(std::vector<std::string> &&v) : vec{v} {
        std::cout << "Moved vector\n";
    }
    void print() {
        for(auto i : vec) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
        
private:
    std::vector<std::string> vec;
    
};




int main(int argc, char **argv) {
    
    std::vector<std::string> vz;
    std::cout << "Filling vector..\n";
    for(unsigned int i = 0; i < 10; ++i) {
        std::ostringstream stream;
        stream << i;
        vz.push_back(stream.str());
    }
    // instead of copying use move
    MoveVector v(std::move(vz));
    v.print();
    
    return 0;
}