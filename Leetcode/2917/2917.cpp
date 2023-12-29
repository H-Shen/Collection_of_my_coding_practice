class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        // N = 32
        constexpr int MAXN = 32;
        vector<int> setCount(MAXN);
        for (const int &i : nums) {
            bitset<MAXN> bs(i);
            for (int j = 0; j < MAXN; ++j) {
                if (bs[j]) {
                    ++setCount[j];
                }
            }
        }
        bitset<MAXN> ans;
        for (int i = 0; i < MAXN; ++i) {
            if (setCount[i] >= k) {
                ans[i] = true;
            }
        }
        return (int)ans.to_ulong();
    }
};