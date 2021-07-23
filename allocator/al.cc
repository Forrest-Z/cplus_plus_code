/*
 C++11 Example using std::allocator
 written by Jared Bruni
*/


/*
标准库中包含一个名为allocator的类，允许我们将分配和初始化分离。使用allocator通常会提供更好的性能和更灵活的内存管理能力。
new有一些灵活性上的局限，其中一方面表现在它将内存分配和对象构造组合在了一起。类似的，delete将对象析构和内存释放组合在了一起。
我们分配单个对象时，通常希望将内存分配和对象初始化组合在一起。因为在这种情况下，我们几乎肯定知道对象应有什么值。当分配一大块内
存时，我们通常计划在这块内存上按需构造对象。在此情况下，我们希望将内存分配和对象构造分离。这意味着我们可以分配大块内存，但只在
真正需要时才真正执行对象的创建操作(同时付出一定开销)。一般情况下，将内存分配和对象构造组合在一起可能会导致不必要的浪费。

标准库allocator类定义在头文件memory中，它帮助我们将内存分配和对象构造分离开来。它提供一种类型感知的内存分配方法，它分配的内存是原始的、未构造的。

allocatro分配的内存是未构造的(unconstructed)。我们按需要在此内存中构造对象。在新标准库中，construct成员函数接受一个指针和零个或多个额外参数，
在给定位置构造一个元素。额外参数用来初始化构造的对象。类似make_shared的参数，这些额外参数必须是与构造的对象的类型相匹配的合法的初始化器。

下面是参考代码：

#include "allocator.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <vector>
 
namespace allocator_ { 
 
// reference: C++ Primer(Fifth Edition) 12.2.2
int test_allocator_1()
{
	std::allocator<std::string> alloc; // 可以分配string的allocator对象
	int n{ 5 };
	auto const p = alloc.allocate(n); // 分配n个未初始化的string
 
	auto q = p; // q指向最后构造的元素之后的位置
	alloc.construct(q++); // *q为空字符串
	alloc.construct(q++, 10, 'c'); // *q为cccccccccc
	alloc.construct(q++, "hi"); // *q为hi
 
	std::cout << *p << std::endl; // 正确：使用string的输出运算符
	//std::cout << *q << std::endl; // 灾难：q指向未构造的内存
	std::cout << p[0] << std::endl;
	std::cout << p[1] << std::endl;
	std::cout << p[2] << std::endl;
 
	while (q != p) {
		alloc.destroy(--q); // 释放我们真正构造的string
	}
 
	alloc.deallocate(p, n);
 
	return 0;
}
 
int test_allocator_2()
{
	std::vector<int> vi{ 1, 2, 3, 4, 5 };
 
	// 分配比vi中元素所占用空间大一倍的动态内存
	std::allocator<int> alloc;
	auto p = alloc.allocate(vi.size() * 2);
	// 通过拷贝vi中的元素来构造从p开始的元素
	// 类似拷贝算法，uninitialized_copy接受三个迭代器参数。前两个表示输入序列，第三个表示
	//这些元素将要拷贝到的目的空间。传递给uninitialized_copy的目的位置迭代器必须指向未构造的
	//内存。与copy不同，uninitialized_copy在给定目的位置构造元素。
	//类似copy，uninitialized_copy返回(递增后的)目的位置迭代器。因此，一次uninitialized_copy调用
	//会返回一个指针，指向最后一个构造的元素之后的位置。
	
	auto q = std::uninitialized_copy(vi.begin(), vi.end(), p);
	// 将剩余元素初始化为42
	std::uninitialized_fill_n(q, vi.size(), 42);
 
	return 0;
}
 
 
// reference: http://www.modernescpp.com/index.php/memory-management-with-std-allocator
int test_allocator_3()
{
	std::cout << std::endl;
 
	std::allocator<int> intAlloc;
 
	std::cout << "intAlloc.max_size(): " << intAlloc.max_size() << std::endl;
	int* intArray = intAlloc.allocate(100);
 
	std::cout << "intArray[4]: " << intArray[4] << std::endl;
 
	intArray[4] = 2011;
 
	std::cout << "intArray[4]: " << intArray[4] << std::endl;
 
	intAlloc.deallocate(intArray, 100);
 
	std::cout << std::endl;
 
	std::allocator<double> doubleAlloc;
	std::cout << "doubleAlloc.max_size(): " << doubleAlloc.max_size() << std::endl;
 
	std::cout << std::endl;
 
	std::allocator<std::string> stringAlloc;
	std::cout << "stringAlloc.max_size(): " << stringAlloc.max_size() << std::endl;
 
	std::string* myString = stringAlloc.allocate(3);
 
	stringAlloc.construct(myString, "Hello");
	stringAlloc.construct(myString + 1, "World");
	stringAlloc.construct(myString + 2, "!");
 
	std::cout << myString[0] << " " << myString[1] << " " << myString[2] << std::endl;
 
	stringAlloc.destroy(myString);
	stringAlloc.destroy(myString + 1);
	stringAlloc.destroy(myString + 2);
	stringAlloc.deallocate(myString, 3);
 
	std::cout << std::endl;
 
	return 0;
}
 
//
// reference: http://en.cppreference.com/w/cpp/memory/allocator
int test_allocator_4()
{
	std::allocator<int> a1;   // default allocator for ints
	int* a = a1.allocate(1);  // space for one int
	a1.construct(a, 7);       // construct the int
	std::cout << a[0] << '\n';
	a1.deallocate(a, 1);      // deallocate space for one int
 
	// default allocator for strings
	std::allocator<std::string> a2;
 
	// same, but obtained by rebinding from the type of a1
	decltype(a1)::rebind<std::string>::other a2_1;
 
	// same, but obtained by rebinding from the type of a1 via allocator_traits
	std::allocator_traits<decltype(a1)>::rebind_alloc<std::string> a2_2;
 
	std::string* s = a2.allocate(2); // space for 2 strings
 
	a2.construct(s, "foo");
	a2.construct(s + 1, "bar");
 
	std::cout << s[0] << ' ' << s[1] << '\n';
 
	a2.destroy(s);
	a2.destroy(s + 1);
	a2.deallocate(s, 2);
 
	return 0;
}
 
} // namespace allocator_

*/


#include<iostream>


template<typename Type,typename Allocator = std::allocator<Type>>
class Allocated_Array {

public:
    typedef typename Allocator::size_type size_type;
    size_type set_size;
    
    Allocated_Array() : set_size{}, type(nullptr), last(nullptr) {
        
    }
    
    Allocated_Array(size_type length): set_size{}, type(nullptr),last(nullptr) {
        if(length != 0)
            sizeTo(length);
    }
    
    ~Allocated_Array() {
        clean();
    }
    
    void clean() noexcept {
        if(type != nullptr) {
            allocator.deallocate(type,last-type);
            type = nullptr;
        }
    }
   
    Type *getType() const {
        return type;
    }
    
    Type &operator[](unsigned int pos) {
        return type[pos];
    }
    
    size_type size() const {
        return set_size;
    }
    
    void erase_and_resize(size_type s) {
        sizeTo(s);
    }
    
private:
    Allocator allocator;
    Type *type;
    Type *last;
    std::allocator<int>::size_type am;
    
    void sizeTo(size_type length) {
        if(type != nullptr) 
            clean();
        type = allocator.allocate(length);
        set_size = length;
        last = type+set_size;
    }
};

// entry point
int main(int argc, char **argv) {
    try {
        Allocated_Array<int> arrSize(10);
        unsigned int array_size = arrSize.size();
        for(unsigned int i = 0; i < array_size; ++i) {
            arrSize[i] = rand()%255;
            std::cout << arrSize[i] << "\n";
        }
        std::cout << "Enter size of array: ";
        unsigned int value = 0;
        std::cin >> value;
        if(value == 0) 
            return 0;
        Allocated_Array<char> arrSize2(value);
        //arrSize2.erase_and_resize(value);
        std::cout << "random array of size: " << value << "\n";
        array_size = arrSize2.size();
        for(unsigned int z = 0; z < array_size; ++z) {
            arrSize2[z] = 'a'+rand()%23;
            std::cout << z << ": " << arrSize2[z] << "\n";
        }
        std::cout << "\n";
    }
    catch(...) {
        std::cerr << "Exception thrown..\n";
    }
    return 0;
}

