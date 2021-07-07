#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

/* 实际上像std::find_if()  std::for_each() 这样的函数就是简单的for循环，为了让我们少些代码而已。*/
/* std::find函数原型：
template <class InputIterator, class T>
   InputIterator find (InputIterator first, InputIterator last, const T& val);
查找范围内的值

返回一个迭代器到范围[first，last）中比较等于val的第一个元素。如果没有找到这样的元素，函数将返回last。

函数使用运算符==将各个元素与val进行比较。

参数：
first,last:
将迭代器输入到序列的初始和最终位置。搜索的范围是[first，last]，它包含first和last之间的所有元素，包括first指向的元素，而不是last指向的元素。

val:
要在范围中搜索的值。

T应为支持与InputIterator使用运算符==（元素为左侧操作数，val为右侧操作数）的元素进行比较的类型。

返回值：
比较等于val的范围中第一个元素的迭代器。如果没有元素匹配，则函数返回last。
*/

/*
std::find_if函数原型：
template <class InputIterator, class UnaryPredicate>
   InputIterator find_if (InputIterator first, InputIterator last, UnaryPredicate pred);
查找范围内的元素

返回一个迭代器到pred返回true的范围[first，last]中的第一个元素。如果没有找到这样的元素，函数将返回last。

参数：
first,last
将迭代器输入到序列的初始和最终位置。使用的范围是[first，last]，它包含first和last之间的所有元素，包括first指向的元素，但不包括last指向的元素。

pred
接受范围中的元素作为参数并返回可转换为bool的值的一元函数。返回的值指示此函数的上下文中是否将元素视为匹配项。

函数不应修改其参数。

它可以是函数指针或函数对象。

返回值：
pred不返回false的范围内第一个元素的迭代器。如果pred对于所有元素都为false，则函数返回last。



*/

int main() {
    std::vector<std::string> vec;
    std::cout << "Enter multiple strings use quit to terminate\n";
    std::string value;
    do {
        std::cin >> value;
        vec.push_back(value);
    } while(value!="quit");
    
    auto contains = std::find_if(vec.begin(), vec.end(), [](std::string text) {
        return (text == "hello");
    });

 //   std::vector<std::string>::iterator it = std::find(vec.begin(), vec.end(), "hello");

    auto it = std::find_if(vec.begin(), vec.end(), [](std::string text){
        if(text == "hello")
            return 1;
        else
            return 0;
    });

    if(*it == "hello") {
        std::cout << "You entered hello\n";
    } else {
        std::cout << "You didn't enter hello\n";
    }
    return 0;
}