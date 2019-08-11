// https://www.nowcoder.com/practice/6bc058b32ee54a5fa18c62f29bae9863

#include <bits/stdc++.h>

using namespace std;
constexpr int MAX = 5;
char s[MAX];

inline static
int quickReadInteger() {
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
class TwoStacksQueue {
private:
    stack<T> stackPush;
    stack<T> stackPop;
public:
    void add(const T &x) {
        stackPush.push(x);
    }

    void poll() {
        if (stackPush.empty() && stackPop.empty()) {
            throw out_of_range("");
        }
        if (stackPop.empty()) {
            while (!stackPush.empty()) {
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
        stackPop.pop();
    }

    T peek() {
        if (stackPush.empty() && stackPop.empty()) {
            throw out_of_range("");
        }
        if (stackPop.empty()) {
            while (!stackPush.empty()) {
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
        return stackPop.top();
    }
};

int main() {

    TwoStacksQueue<int> obj;
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        if (!strcmp(s, "add")) {
            obj.add(quickReadInteger());
        } else if (!strcmp(s, "peek")) {
            printf("%d\n", obj.peek());
        } else {
            obj.poll();
        }
    }

    return 0;
}