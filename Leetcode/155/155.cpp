class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        stack<int>().swap(A);
        stack<int>().swap(minSave);
        minVal = numeric_limits<int>::max();
    }

    void push(int x) {
        A.push(x);
        minVal = min(minVal, x);
        minSave.push(minVal);
    }

    void pop() {
        if (A.empty()) {
            minVal = numeric_limits<int>::max();
            return;
        }
        A.pop();
        minSave.pop();
        if (minSave.empty()) {
            minVal = numeric_limits<int>::max();
        } else {
            minVal = minSave.top();
        }
    }

    int top() {
        if (A.empty()) {
            exit(EXIT_FAILURE);
        }
        return A.top();
    }

    int getMin() {
        return minVal;
    }

private:
    stack<int> A;
    stack<int> minSave;
    int minVal = numeric_limits<int>::max();
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
[[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]
 * int param_4 = obj.getMin();
 */
