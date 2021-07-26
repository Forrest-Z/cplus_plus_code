
#include <iostream>
#include <chrono>

template<size_t X, size_t Y>  //注意这里的template模板参数使用，可以是类型，也可以是变量参数
void WasteTime() {
    for(size_t i = 0; i < X; ++i) {
        for(size_t z = 0; z < Y; ++z) {
                std::cout << "Waste some time " << i << ":" << z << " \n";
        }
    }
}

template<int a, int b>
void test(){
  if(a>b)
    std::cout<<"a>b"<<std::endl;
  else
    std::cout<<"a<=b"<<std::endl;
}



int main(int argc, char **argv) {
    test<2, 3>();
    auto n1 = std::chrono::high_resolution_clock::now();
    WasteTime<400, 400>();
    auto n2 = std::chrono::high_resolution_clock::now();
    
    std::cout << "Operation WasteTime took " << std::chrono::duration_cast<std::chrono::milliseconds>(n2-n1).count() << " milliseconds\n";
    
    
    return 0;
}
