// https://www.nowcoder.com/practice/05e57ce2cd8e4a1eae8c3b0a7e9886be

#include <bits/stdc++.h>

using namespace std;

class myStack {
private:
    stack<int> S;
    stack<int> S_min;
public:
    void push(int value) {
        S.push(value);
        if (S_min.empty()) {
            S_min.push(value);
        } else {
            S_min.push(std::min(value, S_min.top()));
        }
    }
    void pop() {
        if (S.empty()) {
            throw out_of_range("");
        }
        S.pop();
        S_min.pop();
    }
    int getMin() {
        if (S_min.empty()) {
            throw out_of_range("");
        }
        return S_min.top();
    }
};

static myStack obj;

int main() {

    ios_base::sync_with_stdio(false);
    int n, val;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "push") {
            cin >> val;
            obj.push(val);
        } else if (s == "getMin") {
            cout << obj.getMin() << endl;
        } else {
            obj.pop();
        }
    }

    return 0;
}
