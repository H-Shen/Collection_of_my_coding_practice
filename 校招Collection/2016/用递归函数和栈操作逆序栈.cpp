// https://www.nowcoder.com/practice/ba7d7f5d1edf4d1690d66e12e951f6ea

class ReverseStack {
public:
    vector<int> reverseStackRecursively(vector<int> stack, int top) {
        // write code here
        if (top == 0) {
            return stack;
        }
        vector<int> A = {stack.back()};
        stack.pop_back();
        if (stack.empty()) {
            return A;
        }
        vector<int> temp = reverseStackRecursively(stack, stack.size());
        copy(temp.begin(), temp.end(), std::back_inserter(A));
        return A;
    }
};