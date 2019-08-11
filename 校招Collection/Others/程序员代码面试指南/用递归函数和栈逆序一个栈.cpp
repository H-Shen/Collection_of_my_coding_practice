// https://www.nowcoder.com/practice/1de82c89cc0e43e9aa6ee8243f4dbefd

#include <bits/stdc++.h>

using namespace std;

inline static
auto quickReadInteger() {
    int x = 0, F = 1;
    char C = static_cast<char>(getchar());
    while (C < '0' || C > '9') {
        if (C == '-') {
            F = -F;
        }
        C = static_cast<char>(getchar());
    }
    while (C >= '0' && C <= '9') {
        x = x * 10 - '0' + C;
        C = static_cast<char>(getchar());
    }
    return x * F;
}

template<typename T>
auto getAndRemoveLastElement(stack<T> &S) {
    if (S.empty()) {
        throw out_of_range("");
    }
    T result = S.top();
    S.pop();
    if (S.empty()) {
        return result;
    }
    T lastElement = getAndRemoveLastElement(S);
    S.push(result);
    return lastElement;
}

template<typename T>
auto reverseStack(stack<T> &S) {
    if (!S.empty()) {
        T lastElement = getAndRemoveLastElement(S);
        reverseStack(S);
        S.push(lastElement);
    }
}

int main() {

    int N{quickReadInteger()};
    stack<int> A{};
    for (int i = 0; i < N; ++i) {
        A.push(quickReadInteger());
    }
    bool firstItem{true};
    while (!A.empty()) {
        if (firstItem) {
            firstItem = false;
        } else {
            printf(" ");
        }
        printf("%d", A.top());
        A.pop();
    }
    return 0;
}