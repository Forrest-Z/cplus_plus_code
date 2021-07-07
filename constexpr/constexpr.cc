/*
constexpr是C++11开始提出的关键字，其意义与14版本有一些区别。
C++11中的constexpr指定的函数返回值和参数必须要保证是字面值，而且必须有且只有一行return代码，这给函数的设计者带来了更多的限制，比如通常只能通
过return 三目运算符+递归来计算返回的字面值。
而C++14中只要保证返回值和参数是字面值就行了，函数体中可以加入更多的语句，方便了更灵活的计算。

很多人都把constexpr和const相比较。

其实，const并不能代表“常量”，它仅仅是对变量的一个修饰，告诉编译器这个变量只能被初始化，且不能被直接修改（实际上可以通过堆栈溢出等方式修改）。而这
个变量的值，可以在运行时也可以在编译时指定。

constexpr可以用来修饰变量、函数、构造函数。一旦以上任何元素被constexpr修饰，那么等于说是告诉编译器 “请大胆地将我看成编译时就能得出常量值的表达式去优化我”。
如：
const int func() {
    return 10;
}
main(){
  int arr[func()];
}
//error : 函数调用在常量表达式中必须具有常量值
对于func() ，胆小的编译器并没有足够的胆量去做编译期优化，哪怕函数体就一句return 字面值;而下面代码：
constexpr func() {
    return 10;
}
main(){
  int arr[func()];
}
//编译通过

则编译通过
编译期大胆地将func()做了优化，在编译期就确定了func计算出的值10而无需等到运行时再去计算。
这就是constexpr的第一个作用：给编译器足够的信心在编译期去做被constexpr修饰的表达式的优化。
constexpr还有另外一个特性，虽然它本身的作用之一就是希望程序员能给编译器做优化的信心，但它却猜到了自己可能会被程序员欺骗，而编译器并不
会对此“恼羞成怒”中止编译，如：
constexpr int func(const int n){
  return 10+n;
}
main(){
 const  int i = cin.get();
 cout<<func(i);
}
//编译通过

程序员告诉编译器尽管信心十足地把func当做是编译期就能计算出值的程式，但却欺骗了它，程序员最终并没有传递一个常量字面值到该函数。没有被编译器中止编
译并报错的原因在于编译器并没有100%相信程序员，当其检测到func的参数是一个常量字面值的时候，编译器才会去对其做优化，否则，依然会将计算任务留给运行时。


*/



#include <iostream>

constexpr int calcNum(int num) {
    return (num/2)/16;
}

constexpr int Calc = calcNum(400);
int arr_temp[Calc]; // note constexpr


//another

template<typename T, int Num>
class ArrTile {
public:
    T type[calcNum(Num)]; // note constexpr
    
    T &operator[](unsigned int i) { std::cout <<"33"<<std::endl;return type[i]; }
};


int main(int argc, char **argv)
{
    std::cout << "constexpr.cc"<<std::endl;
    ArrTile<int, 400> arrTile;
    arrTile[0] = 0;
    
    return 0;
}

