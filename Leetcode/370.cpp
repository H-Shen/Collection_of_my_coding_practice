class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        // 差分数组
        vector<int> diff(length+1); // 为了方便多加个1
        int l, r, v;
        for (const auto &i : updates) {
            // range add
            l = i[0];
            r = i[1];
            v = i[2];
            diff[l] += v;
            diff[r+1] -= v;
        }
        vector<int> ans(length);
        for (int i = 0; i < length; ++i) {
            if (i == 0) {
                ans[i] = diff[i];
            } else {
                ans[i] = diff[i] + ans[i-1];
            }
        }
        return ans;
    }
};