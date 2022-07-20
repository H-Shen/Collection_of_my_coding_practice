class Solution {
public:
    inline
    int sumOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> unmap;
        for (const auto&i : nums) {
            unmap[sumOfDigits(i)].emplace_back(i);
        }
        int maxVal = -1;
        for (auto& [k,v] : unmap) {
            if (v.size() >= 2) {
                sort(v.begin(),v.end());
                maxVal = max(maxVal, v[v.size()-1] + v[v.size()-2]);
            }
        }
        return maxVal;
    }
};