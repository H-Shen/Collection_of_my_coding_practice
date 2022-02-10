class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 求next greater 维护一个单调递减栈
        int n = (int)temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        // 留在栈中的元素都是不存在next greater的
        return ans;
    }
};