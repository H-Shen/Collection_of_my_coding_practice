class MyQueue {
private:
    stack<int> a, b;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        stack<int>().swap(a);
        stack<int>().swap(b);
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        a.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = peek();
        b.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if (b.empty()) {
            if (a.empty()) {
                return -1;  // out of range
            }
            while (!a.empty()) {
                b.push(a.top());
                a.pop();
            }
        }
        return b.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return a.empty() && b.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */