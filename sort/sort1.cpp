
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>




int main(int argc, char **argv) {
/*
    std::vector<std::string> strings;
    
    for(;;) {
        std::cout << "Enter string (quit to exit and sort):";
        std::string s;
        std::getline(std::cin,s);
        if(s=="quit") break;
        strings.push_back(s);
    }
*/
    std::vector<std::string> buffer;
    for(;;){
       std::cout<<"input, quit to end:"<<std::endl;
       std::string ss;
       std::cin>>ss;
       if(ss=="quit")
           break;
       buffer.push_back(ss);
    }
   
    std::sort(buffer.begin(), buffer.end());
 
//    std::sort(strings.begin(), strings.end());
    
    std::cout << "Sorted..\n";
    
    for(auto &i : buffer) {
        std::cout << i << "\n";
    }


    for(std::vector<std::string>::iterator it=buffer.begin();it!=buffer.end(); it++) {
        std::cout << *it<<std::endl;
    }

    return 0;
}
