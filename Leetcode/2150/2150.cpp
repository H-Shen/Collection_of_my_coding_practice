constexpr int MAXN = 1e6+5;
int freq[MAXN];

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        memset(freq, 0, sizeof(freq));
        for (auto&i : nums) ++freq[i+1];
        vector<int> ans;
        for (auto&i : nums) {
            if (freq[i+1] == 1 && freq[i] == 0 && freq[i+2] == 0) ans.emplace_back(i);
        }
        return ans;
    }
};