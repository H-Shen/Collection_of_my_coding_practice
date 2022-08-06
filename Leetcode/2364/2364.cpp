using ll = long long;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // i < j && nums[i] - i != nums[j] - j
        int n = (int)nums.size();
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i] = nums[i] - i;
        }
        ll ans = 0;
        unordered_map<int,int> cnt;
        for (int i = 1; i < n; ++i) {
            ++cnt[vec[i]];
        }
        ll length;
        for (int i = 0; i < n-1; ++i) {
            length = n - i - 1;
            if (cnt.count(vec[i]) > 0) {
                length -= cnt[vec[i]];
            }
            ans += length;
            --cnt[vec[i+1]];
            if (cnt[vec[i+1]] == 0) {
                cnt.erase(vec[i+1]);
            }
        }
        return ans;
    }
};