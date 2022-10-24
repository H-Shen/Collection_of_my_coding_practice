class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int cnt = 0;
        int temp;
        for (int i = 0; i < n; ++i) {
            temp = nums[i];
            if (temp == k) ++cnt;
            for (int j = i+1; j < n; ++j) {
                temp = gcd(temp, nums[j]);
                if (temp == k) ++cnt;
                else if (temp < k) break;
            }
        }
        return cnt;
    }
};