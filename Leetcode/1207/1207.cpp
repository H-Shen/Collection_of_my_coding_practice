class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        constexpr int offset = 1000;
        constexpr int MAXN = 2005;
        int freq[MAXN]{};
        for (const auto &i : arr) {
            ++freq[i + offset];
        }
        unordered_map<int, int> freq2num;
        for (int i = 0; i < MAXN; ++i) {
            if (freq[i] > 0) {
                ++freq2num[freq[i]];
                if (freq2num[freq[i]] > 1) return false;
            }
        }
        return true;
    }
};