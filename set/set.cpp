/*
std::set作为标准库的一个关联容器，实现内部元素进行了排序，使用这特性可以对一组元素进行插入排序。std::set最初的设
计是完成数学中“集合”的概念，它提供的接口也是如此。
*/

/*
一个容器就是一些特定类型对象的集合。顺序容器(sequential container)为程序员提供了控制元素存储和访问顺序的能力。这种顺序不依赖于元
素的值，而是与元素加入容器时的位置相对应。与之相对的，有序和无序关联容器，则根据关键字的值来存储元素。
标准库还提供了三种容器适配器，分别为容器操作定义了不同的接口，来与容器类型适配：stack、queue和priority_queue。适配器(adaptor)是标准库
中的一个通用概念。容器、迭代器和函数都有适配器。本质上，一个适配器是一种机制，能使某种事物的行为看起来像另外一种事物一样。一个容器适配器接
受一种已有的容器类型，使其行为看起来像一种不同的类型。
顺序容器包括vector、deque、list、forward_list、array、string，所有顺序容器都提供了快速顺序访问元素的能力。
关联容器和顺序容器有着根本的不同：关联容器中的元素是按关键字来保存和访问的。与之相对，顺序容器中的元素是按它们在容器中的位置来顺序保存和访问的。
类似顺序容器，关联容器也是模板。
关联容器不支持顺序容器的位置相关的操作。原因是关联容器中元素是根据关键字存储的，这些操作对关联容器没有意义。而且，关联容器也不支持构造函数或
插入操作这些接受一个元素值和一个数量值得操作。
关联容器支持高效的关键字查找和访问。两个主要的关联容器(associative container)类型是map和set。map中的元素是一些关键字----值(key--value)对：关
键字起到索引的作用，值则表示与索引相关联的数据。set中每个元素只包含一个关键字：set支持高效的关键字查询操作----检查一个给定关键字是否在set中。

标准库提供8个关联容器：
(1)、按关键字有序保存元素：map(关联数组：保存关键字----值对)；set(关键字即值，即只保存关键字的容器)；multimap(关键字可重复出
现的map)；multiset(关键字可重复出现的set)；
(2)、无序集合：unordered_map(用哈希函数组织的map)；unordered_set(用哈希函数组织的set)；unordered_multimap(哈希组织的map，关键字
可以重复出现)；unordered_multiset(哈希组织的sest，关键字可以重复出现)。
map是关键字----值对的集合，与之相对，set就是关键字的简单集合。当只是想知道一个值是否存在时，set是最有用的。
在set中每个元素的值都唯一，而且系统能根据元素的值自动进行排序。Set中元素的值不能直接被改变。set内部采用的是一种非常高效的平衡检索二叉树：红黑
树，也称为RB树(Red-Black Tree)。RB树的统计性能要好于一般平衡二叉树。
*/


#include <iostream>
#include <set>
#include <string>

int main(int argc, char **argv) {
///////////////////////////////////////////////////////////////////////////////////////////        
    int array[5] = {3,1,3,5,4};
    std::set<int> set_e;
    int size = sizeof(array) / sizeof(int);
    for(int i =0; i<size; i++)
        set_e.insert(array[i]);
    std::set<int>::iterator it;
    for(it = set_e.begin(); it!=set_e.end(); it++)
        std::cout<<*it<<std::endl;  //set的排序是自动的,插入3、1、3、5、4后，此处打印输出1 3 4 5

    std::set<int>::reverse_iterator rit;
    for(rit=set_e.rbegin(); rit!=set_e.rend();rit++)
        std::cout<<*rit<<std::endl;

    std::set<int>::iterator itt;
    itt = set_e.find(3);
    std::cout<<"itt:"<<*itt<<", size="<<set_e.size()<<std::endl;
//////////////////////////////////////////////////////////////////////////////////////////
    int arrayy[5]={12, 34, 10, 98, 3};
    const size_t array_size = sizeof(arrayy)/sizeof(arrayy[0]);
    std::set<int> set_1(arrayy, arrayy+array_size);
    //插入一个元素
    set_1.insert(23);
    //移除一个元素
    set_1.erase(10);
    //移除一个元素不在集合中的元素
    //此时什么也不做，n作为返回值将会是0
    //指明没有元素移除
    size_t n=set_1.erase(11);

    //使用迭代器，找到一个元素
    std::set<int>::const_iterator result=set_1.find(98);

    std::set<int> other;
    //交换两个集合的内容
    std::swap(set_1, other);
    std::set<int>::iterator it2;
    for(it2 = other.begin(); it2!=other.end(); it2++)
        std::cout<<*it2<<std::endl;  //set的排序是自动的,插入3、1、3、5、4后，此处打印输出1 3 4 5
    //清楚所有的内容
    other.clear();
///////////////////////////////////////////////////////////////////////////////////////////    
    std::cout << "input a series of integers terminate the loop by entering 0\n";
    // insert into set
    
    std::set<int> input_values;
    int value;
    
    do {    
        std::cin >> value;
        input_values.insert(value);
        
    } while(value != 0);
    
    
    // display the set
    
    for(auto &i : input_values) {
        std::cout << i << "\n";
    }
    
    std::set<std::string, std::greater<std::string>> s1;
    std::set<std::string, std::less<std::string>> s2;
    std::string input_text;
    
    std::cout << "Input a series of strings quit to terminate\n";
    
    do {
        
        std::cin >> input_text;
        s1.insert(input_text);
        s2.insert(input_text);
        
    } while(input_text != "quit");
    
    std::cout << "Print greater: \n";
    
    for(auto &i : s1) {
        std::cout << i << "\n";
    }
    
    std::cout << "Print less: \n";
    
    for(auto &i : s2) {
        std::cout << i << "\n";
    }
    
    return 0;
}