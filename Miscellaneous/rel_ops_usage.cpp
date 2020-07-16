// Deprecated in C++2a, overload <=> in C++2a instead
//
#include <bits/stdc++.h>

using namespace std;
using namespace rel_ops; // std::rel_ops;

struct Node {
    int a;
    explicit Node(int a) : a(a) {}
    bool operator == (const Node &other) const {
        return a == other.a;
    }
    bool operator < (const Node &other) const {
        return a < other.a;
    }
};

// When we import rel_ops, as long as '<' and '=' are overloaded,
// other operators >, >=, <=, != are overloaded automatically.
int main() {

    Node a(12);
    Node b(15);
    cout << boolalpha << (a > b) << endl;
    cout << boolalpha << (a >= b) << endl;
    cout << boolalpha << (a <= b) << endl;
    cout << boolalpha << (a != b) << endl;

    return 0;
}
