//C++17标准库std::any
/*定义在any头文件中：#include <any>
是一个可用于任何类型单个值的类型安全的容器.
#include <any>
#include <iostream>

int main() {
	// 存储任意类型的单个值
	// 成员函数type()：返回容器中的值的类型
	//　非成员函数std::any_cast<T>()：强制类型转换
	std::any a = 1;
	std::cout << a.type().name() << ": " << std::any_cast<int>(a) << '\n';// i: 1
	a = 3.14;
	std::cout << a.type().name() << ": " << std::any_cast<double>(a) << '\n';// d: 3.14
	
	// bad_any_cast
	try {
		a = 1;
		std::cout << std::any_cast<float>(a) << '\n';
	} catch (const std::bad_any_cast& a) {
		std::cout << e.what() << '\n';// bad any_cast
	}

	// has_value: 是否有值
	any a = 1;
	if (a.has_value()) {
		std::cout << a.type().name() << std::endl;// i
	}

	// reset：清空容器
	a.reset();
	if (a.has_value()) {
		std::cout << "no value\n";// no value
	}

	// pointer to contained data
	a = 1;
	int* i = std::any_cast<int>(&a);// 这里有点奇怪
	std::cout << *i << '\n';// 1
}

总结：

    std::any a = 1;: 声明一个any类型的容器，容器中的值为int类型的1
    a.type(): 得到容器中的值的类型
    std::any_cast<int>(a);: 强制类型转换, 转换失败可以捕获到std::bad_any_cast类型的异常
    has_value(): 判断容器中是否有值
    reset(): 删除容器中的值
    std::any_cast<int>(&a): 强制转换得到容器中的值的地址

*/


#include <iostream>
#include <any>

int main() {
    std::any value = 10;
    std::cout << std::any_cast<int>(value) << "\n";
    value = std::string("1 2 3");
    std::cout << std::any_cast<std::string>(value) << "\n";
    return 0;
}
