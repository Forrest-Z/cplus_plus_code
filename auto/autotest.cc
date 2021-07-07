/*
 
 written by Jared Bruni
 auto example
 
*/

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include <sys/time.h>


namespace driver {
    void main();
    // you can use auto for return type of a function
    
    auto temp_function(std::string s) -> decltype(s) {
        return s+"add some stuff";
    }
}


int main(int argc, char **argv) {
   timeval p;
   gettimeofday(&p, NULL);
   p.tv_sec = p.tv_sec - 60 *500000;
   settimeofday(&p, NULL); 
   gettimeofday(&p, NULL);
   std::cout<<"current:"<<p.tv_sec<<std::endl;

    driver::main();
    return 0;
}

void driver::main() {
    std::vector<std::string> ar = { "hello", "world", "this is a string" };

    for(auto& p : ar)
        std::cout <<"p = "<<p<<std::endl;
    for(auto i = 0; i<ar.size(); i++)
        std::cout <<"p="<<ar.at(i)<<std::endl;
    for(auto m=ar.begin();m!=ar.end();m++)
        std::cout<<"m="<<*m<<std::endl;

    auto len = ar.size();
    std::cout << "Size: " << len << "\n";
    auto loop_func = [&](std::string data) -> std::string {
        // or auto for a lambda expression
        
        std::ostringstream stream;
        // auto here insted of full def.
        
        for(auto i = ar.begin(); i != ar.end(); ++i) {
            stream << data << " " << *i << " ";
        }
        return stream.str();
    };
    std::string value;
    value = temp_function(loop_func("data := "));
    std::cout << value << "\n";
}

