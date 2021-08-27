class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums2.size();
        vector<int> v(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if (s.empty()) {
                v[i] = -1;
            } else {
                v[i] = s.top();
            }
            s.push(nums2[i]);
        }
        unordered_map<int,int> unmap;
        for (int i = 0; i < n; ++i) {
            unmap[nums2[i]] = v[i];
        }
        n = (int)nums1.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = unmap[nums1[i]];
        }
        return ans;
    }
};