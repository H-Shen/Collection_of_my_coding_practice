// https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6

class Solution {
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {

        if (stack1.empty()) {
            throw out_of_range("");
        }
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int result = stack2.top();
        stack2.pop();
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
