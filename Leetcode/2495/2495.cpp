using ll = long long;

class Solution {
public:
    long long evenProduct(vector<int>& nums) {
        int n = (int)nums.size();
        ll ans = ((1LL+n)*n)>>1;
        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] & 1) {
                ++cnt;
            } else {
                if (cnt > 0) {
                    ans -= ((1LL+cnt)*cnt)>>1;
                    cnt = 0;
                }
            }
        }
        if (cnt > 0) {
            ans -= ((1LL+cnt)*cnt)>>1;
        }
        return ans;
    }
};