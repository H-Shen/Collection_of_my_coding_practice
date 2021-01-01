class MyStack {
private:
    queue<int> a, b;
public:
    /** Initialize your data structure here. */
    MyStack() {
        queue<int>().swap(a);
        queue<int>().swap(b);
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        a.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (a.empty()) {
            return -1;
        }
        if (a.size() == 1) {
            int temp = a.front();
            a.pop();
            return temp;
        }
        while (a.size() > 1) {
            b.push(a.front());
            a.pop();
        }
        int temp = a.front();
        a.pop();
        while (!b.empty()) {
            a.push(b.front());
            b.pop();
        }
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        if (a.empty()) {
            return -1;
        }
        if (a.size() == 1) {
            return a.front();
        }
        while (a.size() > 1) {
            b.push(a.front());
            a.pop();
        }
        int temp = a.front();
        b.push(a.front());
        a.pop();
        while (!b.empty()) {
            a.push(b.front());
            b.pop();
        }
        return temp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return a.empty() && b.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */