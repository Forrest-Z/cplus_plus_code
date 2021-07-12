/*
	Custom Stack Class based from Chapter 5 of "C++ Templates: The Complete Guide Second Edition"
*/

#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<initializer_list>

class Exception {
public:
    Exception(const std::string &err) : error_string(err) {}
    std::string getError() const { return error_string; }
    
private:
    std::string error_string;
};

template<typename T, template<typename E, typename = std::allocator<E>> typename C>
class Stack {
public:
    C<T> container;
    
    Stack() = default;
    Stack(std::initializer_list<T> items);
    void push(const T &type);
    
    template<typename T2, template<typename E2, typename = std::allocator<E2>> typename C2>
    void push(const Stack<T2, C2> &c);
    
    void push_list(std::initializer_list<T> items);
    void pop();
    T &top();
    void print();
    bool empty() const;
    
    template<typename T2, template<typename E2, typename = std::allocator<E2>> typename C2>
    Stack<T, C> &operator=(const Stack<T2,C2> &c);
};

template<typename T, template<typename E, typename = std::allocator<E>> typename C>
Stack<T,C>::Stack(std::initializer_list<T> items) : container(items) { }

template<typename T, template<typename E, typename = std::allocator<E>> typename C>
void Stack<T,C>::push(const T &type) {
    container.push_back(type);
}

template<typename T, template<typename E, typename = std::allocator<E>> typename C>
void Stack<T,C>::push_list(std::initializer_list<T> items) {
    for(auto &i : items)
        container.push_back(i);
}


template<typename T, template<typename E, typename = std::allocator<E>> typename C>
void Stack<T,C>::pop() {
    if(container.empty())
        throw Exception("Error: Stack Underflow");
    container.pop_back();
}

template<typename T, template<typename E, typename = std::allocator<E>> typename C>
T &Stack<T,C>::top() {
    if(container.empty())
        throw Exception("Error: Stack empty");
    
    return container.back();
}

template<typename T, template<typename E, typename = std::allocator<E>> typename C>
void Stack<T,C>::print() {
    for(auto &i : container)
        std::cout << i << "\n";
}

template<typename T, template<typename E, typename = std::allocator<E>> typename C>
bool Stack<T,C>::empty() const {
    return container.empty();
}

template<typename T, template<typename E, typename = std::allocator<E>> typename C>
template<typename T2, template<typename E2, typename = std::allocator<E2>> typename C2>
void Stack<T,C>::push(const Stack<T2,C2> &c) {
    container.insert(container.begin(), c.container.begin(), c.container.end());
}

template<typename T, template<typename E, typename = std::allocator<E>> typename C>
template<typename T2, template<typename E2, typename = std::allocator<E2>> typename C2>
Stack<T, C> &Stack<T,C>::operator=(const Stack<T2,C2> &c) {
    if(!container.empty())
        container.erase(container.begin(), container.end());
    
    container.insert(container.begin(), c.container.begin(), c.container.end());
    return *this;
}

int main() {
    // tests using Stack template
    try {
        Stack<int, std::deque> stack1 ({0, 1, 0, 24, 150, 255});
        Stack<float, std::vector> stack2;
        stack2 = stack1;
        std::cout << "stack 2: \n";
        stack2.print();
        stack1.push_list({1, 0, 410, 64, 124});
        std::cout << "stack 1: \n";
        stack1.print();
        while(!stack1.empty()) {
            std::cout << "stack1 top: " << stack1.top() << "\n";
            stack1.pop();
        }
        std::cout << "Added to stack1\n";
        Stack<int, std::vector> stack3({520, 240, 190, 640, 480, 1280, 720, 1920, 1080});
        stack1.push(stack3);
        stack1.print();
    } catch(Exception &e) {
        std::cerr << "Exception: " << e.getError() << "\n";
    }
}
