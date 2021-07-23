/*
对于map，其内部数据结构为红黑树，因此所有元素插入到map里面都会排好序，而且搜索过程为平衡二叉树搜索，因此时间复
杂度为O(logN)。我们知道还有一种快速的搜索方法，那边是哈希(又名散列)，利用哈希函数，通过哈希值能快速的查找到所需
元素。unordered_map便是采用这种数据结构实现，其为无序映射，unordered _map与map的使用基本一样，都是key/value之间的
映射，只是他们内部采用的数据结构不一样，由于unordered_map内部是用散列表来实现快速查找，因此其内部元素完全是一种无序
状态。哈希表利用哈希函数，将关键字的哈希值放都一个桶(bucket)里面，具有相同哈希值的放入到同一个桶。
*/

#include<iostream>
#include<string>
#include<unordered_map>
#include<sstream>
#include<chrono>

class Value {
public:
    Value();
    Value(Value &&v);       //移动构造函数
    Value(const Value &v);  //拷贝构造函数
    void setKey(std::string one, std::string two);
    std::string getKey(std::string one);
    std::unordered_map<std::string, std::string> values;
};

Value::Value() { }

Value::Value(Value &&v) : values{std::move(v.values)} {
    
}

Value::Value(const Value &v) : values{v.values} {
    
}

void Value::setKey(std::string one, std::string two) {
    values[one] = two;
}

std::string Value::getKey(std::string one) {
    return values[one];
}

int main(int argc, char **argv) {
    std::cout << "Filling map.\n";
    Value values;
    for(int i = 0; i < 25000; ++i) {
        std::ostringstream stream;
        stream << "Value number: " << i;
        std::ostringstream stream2;
        stream2 << i;
        values.setKey(stream2.str(), stream.str());
    }
    std::cout << "Here it is: \n";
    for(auto &i : values.values) {
        std::cout << i.first << ": " << i.second << "\n";
    }
    std::cout << "Move value: ";
    auto start = std::chrono::high_resolution_clock::now();
    Value moveValue(std::move(values));
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << "move operation took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start).count() << " nanoseconds\n";
    
    auto start2 = std::chrono::high_resolution_clock::now();
    Value copiedValue(moveValue);
    auto stop2 = std::chrono::high_resolution_clock::now();
    
    std::cout << "copy operation took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop2-start2).count() << " nanoseconds\n";
    
    return 0;
}

