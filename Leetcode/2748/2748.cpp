class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = (int)nums.size();
        int ans = 0;
        int a,b;
        string s;
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                s = to_string(nums[i]);
                a = (int)(s[0] - '0');
                b = nums[j] % 10;
                if (gcd(a, b) == 1) ++ans;
            }
        }
        return ans;
    }
};