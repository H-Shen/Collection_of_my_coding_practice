#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

template <typename T, typename Cmp = std::greater<T> >
// std::greater<T>: the top of the stack is always minimal
// std::less<T>: the top of the stack is always maximal
struct MonotoneStack {
    stack<T> S;
    void push(const T &val) {
        while (!S.empty() && Cmp()(val,S.top())) {
            S.pop();
        }
        S.push(val);
    }
    void pop() {
        S.pop();
    }
    [[nodiscard]] T top() const {
        return S.top();
    }
    [[nodiscard]] bool empty() const {
        return S.empty();
    }
    [[nodiscard]] size_t size() const {
        return S.size();
    }
};


int main() {

    return 0;
}
