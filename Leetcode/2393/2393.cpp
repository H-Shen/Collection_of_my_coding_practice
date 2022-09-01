using ll = long long;

class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        // subarray, not subseq
        int n = (int)nums.size();
        ll sum = 0;
        ll cnt;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                cnt = 1;
                continue;
            }
            if (nums[i] > nums[i-1]) {
                ++cnt;
            }
            else {
                sum += ((1+cnt)*cnt)>>1;
                cnt = 1;
            }
        }
        sum += ((1+cnt)*cnt)>>1;
        return sum;
    }
};