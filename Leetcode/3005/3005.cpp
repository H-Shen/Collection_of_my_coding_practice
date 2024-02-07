class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (auto &i : nums) {
            ++freq[i];
        }
        int maxFreq = -1;
        for (const auto &[k,v] : freq) {
            maxFreq = max(maxFreq, v);
        }
        int ans = 0;
        for (const auto &[k,v] : freq) {
            if (v == maxFreq) {
                ans += v;
            }
        }
        return ans;
    }
};