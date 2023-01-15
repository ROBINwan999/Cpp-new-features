#include <iostream>
#include <vector>

using namespace std;

// C++14
auto sum1(int a, int b) { return a + b; }

// C++20
auto sum2(auto a, auto b) { return a + b; }

int main() {
    // C++11之前
    int a = 2;
    double b = 3.4;
    bool is_same = false;
    string s = "hello";
    // C++11
    auto a1 = 2;            // int
    auto b1 = 3.4;          // double
    auto is_same1 = false;  // bool
    auto c1 = "hello";      // const char *

    // C++11 之前
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

    auto x = 1;
    auto y = 1;
    cout << "sum of " << x << " + " << y << " = " << sum1(x, y) << '\n';
    cout << "sum of " << x << " + " << y << " = " << sum2(x, y) << '\n';

    return 0;
}