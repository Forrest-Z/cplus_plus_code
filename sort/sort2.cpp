
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>



class UserName {
public:
    UserName() = default;
    
    UserName(std::string first, std::string last) : ex_first{first}, ex_last{last} { }
    
    void printName() {
        std::cout << ex_last << ", " << ex_first;
    }
    
    //重载<运算符，这样在std::sort()比较的时候，可以根据UserName类中的<运算符来比较last name
    bool operator<(const UserName &u) const {
        if(ex_last<u.ex_last) 
            return true;
        return false;
    }
    
private:
    std::string ex_first, ex_last;
};




int main(int argc, char **argv) {
    std::vector<UserName> users;
    for(;;) {
        std::cout << "Enter first name then last name (quit to exit): ";
        std::string first, last;
        std::cin >> first;
        if(first == "quit") 
            break;
        std::cin >> last;
        users.push_back(UserName(first, last));
    }
   
    for(auto &i : users) {
        i.printName();
        std::cout << "\n";
    }
 
    

    std::sort(users.begin(), users.end());
    std::cout << "Sorted by Last Name: \n";
    for(auto &i : users) {
        i.printName();
        std::cout << "\n";
    }
    
    return 0;
}
