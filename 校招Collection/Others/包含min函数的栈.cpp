// https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49

class Solution {
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
            throw logic_error("");
        }
        S.pop();
        S_min.pop();
    }
    int top() {
        if (S.empty()) {
            throw logic_error("");
        }
        return S.top();
    }
    int min() {
        if (S_min.empty()) {
            throw logic_error("");
        }
        return S_min.top();
    }
};