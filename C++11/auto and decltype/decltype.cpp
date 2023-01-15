#include <iostream>

using namespace std;

// C++11
auto sum(int a, int b) -> decltype(a + b) { return a + b; }

int main() {
    int a = 3;
    const int &b = a;

    decltype(11) c = 12;  // int c = 12; 正确
    decltype(22) d;       // int d; 正确

    decltype(a) e;  // int e; 正确
    // decltype(b) f; // const int &f; 错误，引用类型没有初始化

    int g = 5;
    int *h = &g;
    cout << "h = " << h << '\n';    // h = 0x7ffeb09a6078
    cout << "*h = " << *h << '\n';  // *h = 5

    decltype(h) i = &g;
    cout << "i = " << i << '\n';    // i = 0x7fed43145940
    cout << "*i = " << *i << '\n';  // *i = 1125378856

    int x = 1;
    int y = 1;
    cout << "sum of " << x << " + " << y << " = " << sum(x, y) << '\n'; // sum of 1 + 1 = 2

    return 0;
}