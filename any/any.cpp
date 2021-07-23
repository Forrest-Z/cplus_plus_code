
#include <iostream>
#include <any>

int main() {
    std::any value = 10;
    std::cout << std::any_cast<int>(value) << "\n";
    value = std::string("1 2 3");
    std::cout << std::any_cast<std::string>(value) << "\n";
    return 0;
}
