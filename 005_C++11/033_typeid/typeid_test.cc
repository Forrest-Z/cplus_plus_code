
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

template<typename T>
class MyVector : public std::vector<T> {

public:
    explicit MyVector(std::initializer_list<T> list) : std::vector<T>(list) {
        std::cout << "Myvector initialized\n";
    }
    
    void printVector(std::ostream &out) {
        for(auto &i : *this) {
            out << "Outputing .." << i << "\n";
        }
    }
};


int main(int argc, char **argv) {
    int a;
    char b;
    float c;
    long long d;
    std::cout<<"int a typeid.name()="<<typeid(a).name()<<std::endl;
    std::cout<<"char b typeid.name()="<<typeid(b).name()<<std::endl;
    std::cout<<"float c typeid.name()="<<typeid(c).name()<<std::endl;
    std::cout<<"long long d typeid.name()="<<typeid(d).name()<<std::endl;
    MyVector<std::string> v({"String 1", "Jared", "C++", "Cool"});
    std::vector<std::string> v2 {"Str1", "Str2", "Str3", "Str4"};
    v.printVector(std::cout);
    // will print out identification for type depended on implementation
    std::cout << "Vector1 is of type: " << typeid(v).name() << "\n";
    std::cout << "Vector2 is of type: " << typeid(v2).name() << "\n";
    if(typeid(v) == typeid(v2)) {
        std::cout << "Types equal..\n";
    } else {
        std::cout << "Types not equal.\n";
    }
    return 0;
}


