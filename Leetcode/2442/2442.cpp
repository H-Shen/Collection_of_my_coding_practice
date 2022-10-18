class Solution {
public:
    inline int getReverse(int k) const {
        if (k < 10) return k;
        int ans = 0;
        while (k > 0) {
            ans = ans * 10 + (k % 10);
            k /= 10;
        }
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> unset(nums.begin(),nums.end());
        for (auto&i : nums) {
            unset.insert(getReverse(i));
        }
        return (int)unset.size();
    }
};