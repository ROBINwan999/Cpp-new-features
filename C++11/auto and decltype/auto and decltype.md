# auto关键字的作用

从`C++11`开始`auto`关键字有了新的定义：对于变量，可以自动推导类型。比如说：

```c++
// C++11之前
int a = 2;
double b = 3.4;
bool is_same = false;
string s = "hello";
// C++11
auto a = 2; // int
auto b = 3.4; // double
auto is_same = false; // bool
auto c = "hello"; // const char *
```

通过这种方式，我们可以很轻松的完成对某些复杂类型的声明。比如说：

```c++
// C++11之前
vector<int> v{1, 2, 3, 4, 5};
for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    cout << *(it) << ' ';
}
cout << '\n';
// C++11
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *(it) << ' ';
}
cout << '\n';
```

除了用于用于普通的变量声明意外，在`C++14`中还可以用作函数的返回值，以及`C++20`中还可以用作函数的非模板类型参数。比如：

```c++
// C++14
auto sum1(int a, int b) { 
    return a + b; 
}

// C++20
auto sum2(auto a, auto b) { 
    return a + b; 
}
```

# 使用auto的注意事项

-   如果是一眼就能看出类型的变量，或者一些短类型的变量，没必要使用`auto`。因为这会让本来意图清晰明确的代码，突然变得没那么直观，需要在脑中先进行一步推断，相当于多加了一个步骤，降低了代码的可读性。
-   使用`auto`声明的变量必须在一开始就进行初始化，这和`const`类似
-   `auto`仅仅是一个占位符，并不是一个真正的类型，所以不能作为一些操作符的参数，比如`sizeof`或者`typeid`等

# decltype关键字的作用

`decltype`是`C++11`新增的一个关键字，它的作用和`auto`类似，也是用于自动类型推导。它的使用方式为`decltype(参数)`，这里的参数可以是变量，也可以是常量，比如说：

```C++
int a = 3;
const int &b = a;

decltype(11) c = 12; // int c = 12; 正确
decltype(22) d; // int d; 正确

decltype(a) e; // int e; 正确
// decltype(b) f; // const int &f; 错误，引用类型没有初始化
```

用来推导指针类型也是可以的

```C++
int g = 5;
int *h = &g;
cout << "h = " << h << '\n'; // h = 0x7ffeb09a6078
cout << "*h = " << *h << '\n'; // *h = 5

decltype(h) i = &g;
cout << "i = " << i << '\n'; // i = 0x7fed43145940
cout << "*i = " << *i << '\n'; // *i = 1125378856
```

另外在`C++11`中可以配合auto来推导函数的返回值，不过在`C++14`之后就可以直接通过`auto`来推断了

```C++
// C++11
auto sum(int a, int b) -> decltype(a + b) { 
    return a + b; 
}

// C++14
auto sum(int b, int b) {
    return a + b;
}
```

# 总结

`auto`和`decltype`虽然都是用于自动类型推导的，但是`auto`的推导规则更为复杂，有时候会改变表达式的原始类型，而`decltype`比较纯粹，一般会保留原值表达式的类型，让推导的结果更加自然。

通常使用`auto`和`decltype`来帮助编写模板库，另外`auto`被更多的用于复杂类型的自动推断，降低程序员的心智负担
