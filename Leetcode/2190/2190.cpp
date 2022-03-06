constexpr int MAXN = 1e3+5;

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int n = (int)nums.size();
        int freq[MAXN]{};
        for (int i = 0; i < n-1; ++i) {
            if (nums[i] == key) {
                ++freq[nums[i+1]];
            }
        }
        return (int)(max_element(freq,freq+MAXN)-freq);
    }
};