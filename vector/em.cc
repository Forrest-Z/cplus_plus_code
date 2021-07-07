/*
在 C++11 之后，vector 容器中添加了新的方法：emplace_back() ，和 push_back() 一样的是都是在容器末尾添加一个新的元素
进去，不同的是 emplace_back() 在效率上相比较于 push_back() 有了一定的提升。

*/
/*
c++开发中我们会经常用到插入操作对stl的各种容器进行操作，比如vector,map,set等。在引入右值引用，转移构造函数，转移复制运算符
之前，通常使用push_back()向容器中加入一个右值元素(临时对象)时，首先会调用构造函数构造这个临时对象，然后需要调用拷贝构造函数
将这个临时对象放入容器中。原来的临时变量释放。这样造成的问题就是临时变量申请资源的浪费。 
引入了右值引用，转移构造函数后，push_back()右值时就会调用构造函数和转移构造函数,如果可以在插入的时候直接构造，就只需要构造
一次即可。这就是c++11 新加的emplace_back。
emplace_back函数原型：
template <class... Args>
  void emplace_back (Args&&... args);
在容器尾部添加一个元素，这个元素原地构造，不需要触发拷贝构造和转移构造。而且调用形式更加简洁，直接根据参数初始化临时对象的成员。
*/


#include<iostream>
#include<string>
#include<vector>
#include<cctype>

class UserInfo {
public:
    std::string first, last;
    unsigned int id;
    UserInfo() = default;
    UserInfo(std::string f, std::string l, unsigned int i) : first{f}, last{l}, id{i} {}
    
    std::string::iterator findFirst(std::string::iterator start, std::string::iterator stop) {
        std::string::iterator i;
        for(i = start; i != stop; ++i) {
            if(isalpha(*i))
                return i;
        }
        return start;
    }
    
    void capitalize() {
        
        if(first.length()>0) {
            std::string::iterator i = findFirst(first.begin(), first.end());
            *i = toupper(*i);
        }
        if(last.length()>0) {
            std::string::iterator i = findFirst(last.begin(), last.end());
            *i = toupper(*i);
        }
    }
};


std::istream &operator>>(std::istream &in, UserInfo &user) {
    in >> user.first >> user.last;
    return in;
}


std::ostream &operator<<(std::ostream &out, UserInfo &user) {
    out << user.last << ", " << user.first << " ";
    return out;
}




int main(int argc, char **argv) {
    
    std::vector<UserInfo> v;

    // build UserInfo from arguments supplied to this member function
    v.emplace_back("Jared", "Bruni", 101);  //没有类的创建
    v.emplace_back("Jim", "Lee", 102);
    
    char yn = 'Y';
    do {
        UserInfo u;
        std::cout << "Enter user name First Last: ";
        std::cin >> u;
        u.capitalize();
        v.push_back(u);         //相对于emplace_back()，这里有类的创建
        std::cout << "Enter another Y/N: ";
        std::cin >> yn;
        
    } while (toupper(yn) == 'Y' && !std::cin.eof());
    
    
    std::cout << "Values entered into vector: \n";
    
    for(auto &i : v) {
        std::cout << i << "\n";
    }
    
    return 0;
}