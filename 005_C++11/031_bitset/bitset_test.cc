/*
这一篇文章系统的学习一下std标准库中的容器bitset，一个bitset是用来储存诸多bit，这些元素可以用来表示两种状态：0或1，true或
false…。所以有一些时候可以很方便的用该容器快速实现状态储存。
该容器通过对空间的特殊优化，使得该容器对状态的储存空间非常小，相当于将若干状态储存在一个个bit上。该容器的元素访问也可以通
过[n]访问容器中第n个元素，但是由于一般语言没有一个bit大小的数据类型，所以这里使用了一种特殊的引用类型访问，如：bitset::reference。
// constructing bitsets
#include <iostream>       // std::cout
#include <string>         // std::string
#include <bitset>         // std::bitset

int main ()
{
  std::bitset<16> foo;
  std::bitset<16> bar (0xfa2);
  std::bitset<16> baz (std::string("0101111001"));

  std::cout << "foo: " << foo << '\n';
  std::cout << "bar: " << bar << '\n';
  std::cout << "baz: " << baz << '\n';

  return 0;

//Output:
//foo: 0000000000000000
//bar: 0000111110100010
//baz: 0000000101111001
}
总的来说，有四种方法构造一个bitset，
bitset< n > b;	创建一个初始值均为0的n位bitset b
bitset< n > b(u);	根据unsigned long数u创建一个bitset b
bitset< n > b(s);	根据string s中含有位数的情况创建一个bitset b
bitset< n > b(s, pos, n);	根据string s中创建pos位置开始n个元素的bitset b

*/



#include <iostream>
#include <bitset>
#include <iomanip>

template<size_t N>
std::bitset<N> reverse_value(std::bitset<N> &value) {
    std::bitset<N> rev;
    
    for(unsigned int i = 0; i < value.size(); ++i)
        rev[(N-1)-i] = value[i];
    
    return rev;
}

int main(int argc, char **argv) {
   
    std::bitset<32> bit_value = 0x0F0F0F0F;
    std::bitset<32> rev_value;
    
    rev_value = reverse_value(bit_value);
    
    std::cout << std::setw(12) << "orig value: ";   //std::setw()是用来对齐的
    std::cout << std::setw(32) << bit_value << "\n";
    std::cout << std::setw(12) << "reversed: ";
    std::cout << std::setw(32) << rev_value << "\n";
    std::cout << "rev_value.count=" << rev_value.count() << std::endl;  //.count()统计bitset中被设置的bits的个数，也就是bitset中值为1的元素个数。
	std::cout << "rev_value.size=" << rev_value.size() << std::endl; //返回bitset中元素总个数。即通常意义上bitset的大小。
    std::cout << std::setw(24) << "rev_value.size=" << rev_value.size() << std::endl;
    return 0;
}

