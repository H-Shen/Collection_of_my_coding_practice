class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto p = minmax_element(nums.begin(),nums.end());
        return gcd(*(p.first),*(p.second));
    }
};