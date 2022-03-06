class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> arr(2*n);
        for (int i = 0; i < n; ++i) {
            arr[i] = nums[i];
        }
        for (int i = n, j = 0; i < 2*n; ++i, ++j) {
            arr[i] = nums[j];
        }
        stack<int> s;
        vector<int> ans(n);
        for (int i = 0; i < 2*n; ++i) {
            if (s.empty()) {
                s.push(i);
                continue;
            }
            while (!s.empty() && arr[s.top()] < arr[i]) {
                if (s.top() < n) {
                    ans[s.top()] = arr[i];
                }
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            if (s.top() < n) {
                ans[s.top()] = -1;
            }
            s.pop();
        }
        return ans;
    }
};