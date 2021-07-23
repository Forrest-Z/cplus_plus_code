#include <iostream>
#include <memory>
#include <map>
#include <unordered_map>

// a simple user type to practice smart pointers
template<typename T>
class UserType {
public:
    UserType() { type = T(); }
    UserType(const T &t) : type(t) { }
    
    void print() {
        std::cout << type << " ";
    }
    
    void set(const T t) {
        type = t;
    }
    
protected:
    T type;
    
};


void test(std::shared_ptr<UserType<int>> passedValue) {
    passedValue->set(200);
    std::cout << "value is: ";
    passedValue->print();
}



void testPointer() {
    
    auto deleter = [](UserType<int> *type1) {
        std::cout << "Deleteing..\n";
        delete type1;
    };
    
    std::shared_ptr<UserType<int>> value1(new UserType<int>(100), deleter);
    for(unsigned int i = 0; i < 10; ++i) {
        std::cout << "{ ";
        value1->print();
        std::cout << "}\n";
    }
    test(value1); // add to reference count
    std::cout << "value1's value is now: ";
    value1->print();
    
}


class shape{
public:
    shape(){}
    ~shape(){}
    virtual int mianji() = 0;

private:
    int x = 1, y=2;
      
};

class yuan : public shape{
public:
    yuan() {}
    ~yuan() {}
    virtual int mianji() {std::cout<<"x="<<x<<std::endl; return x; }

private:
    int x = 2;
};

class juxing : public shape{
public:
    juxing() {}
    ~juxing() {}
    virtual int mianji() {std::cout<<"x="<<x<<std::endl; return x; }
private:
    int x = 3;
};


template<typename T, typename U>
auto fun(T a, U b)->decltype(a * b){
    return a * b ;
}





int main(int argc, char **argv) {

//    shape* yuan1 = new yuan;
//    shape* juxing1 = new juxing;

    shape* tuxing[2];
    tuxing[1] = new yuan;
    tuxing[2] = new juxing;
     
    shape* yuan1 = tuxing[1];
    shape* juxing1 = tuxing[2] ;   

    yuan1->mianji();
    juxing1->mianji();
///////////////////////////////////////////////////////////

    std::map<std::string, int> map1 {
        {"aaa", 1},
        {"bbb", 2},
        {"ccc", 3},
        {"ddd", 4}
    };
    map1["eee"] = 5;
    for(auto i : map1)
        std::cout<<i.first<<","<<i.second;

    std::cout << std::endl;
///////////////////////////////////////////////////////////
    std::unordered_map<std::string, int> map2 {
        {"aaa", 1},
        {"bbb", 2},
        {"ccc", 3},
        {"ddd", 4}
    };
    map2["eee"] = 5;
    for(auto i : map2)
        std::cout<<i.first<<","<<i.second;

    std::cout << std::endl;

////////////////////////////////////////////////////////////

    std::map<std::string, int> map3 {
        {"aaa", 1},
        {"bbb", 2},
        {"ccc", 3},
        {"ddd", 4}
    };
    map3["eee"] = 5;

//    std::map<std::string , int> map4;
    map3.insert(std::pair<std::string, int>("fff", 6));  //这里通过insert()进行新数据的插入

    std::map<std::string, int>::iterator it;
    for(it=map3.begin(); it!=map3.end(); it++){
        std::cout <<it->first<<","<<it->second<<std::endl;
    }

    for(auto i : map3)
        std::cout<<i.first<<","<<i.second;
   std::cout << std::endl;
///////////////////////////////////////////////////////////

    auto mmm = fun<int, float>(3, 0.5);  //fun函数使用了decltype来进行类型推断
    std::cout<<"mmm="<<mmm<<std::endl;
///////////////////////////////////////////////////////////
    std::shared_ptr<int> ptr = (std::shared_ptr<int>)new int;
    int m = 90;
    decltype(m) n = 20;
    std::cout << "n="<< n<<",type = "<<typeid(n).name()<<std::endl;

    int a = int();
    std::cout<<"a=="<<a<<std::endl;
    
    auto deleter = [](UserType<int> *type) {
        std::cout << "Deleting UserType for unique on destructor..\n";
        delete type;
    };
    
    
    std::unique_ptr<UserType<int>, decltype(deleter)> first(new UserType<int>(25), deleter);
    testPointer();
    std::cout << "Unique's value: ";
    first->print();
    std::cout << "\n";
    
    
    return 0;
}