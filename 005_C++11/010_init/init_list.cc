
#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <algorithm>


template<typename T>
class VectorWrapper {
public:
    VectorWrapper() { }
    VectorWrapper(std::initializer_list<T> il) : v{il} {
        std::cout << "Wrapper Started..\n";
    }
    void addTo(T type) {
        // do something before adding to v
        v.push_back(type);
    }
    std::vector<T> &cont() { return v; }
protected:
    std::vector<T> v;
};


int func(std::initializer_list<int> il){
//   std::vector<int> a;
   for(auto& i:il)
//        a.push_back(i);
    std::cout<<"i="<<i<<std::endl;
   return 0;
}


int main(int argc, char **argv) {
    func({1,2,3});    

    VectorWrapper<std::string> wrap({"test ", "one", "two", "three"});
    for_each(wrap.cont().begin(), wrap.cont().end(), [](std::string s) {
        std::cout << "Element: " << s << "\n";
    });
    
    return 0;
}
