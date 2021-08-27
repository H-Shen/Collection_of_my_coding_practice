class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = (int)s.size();
        int ans = 0;
        unordered_map<char,int> unmap;
        int i = 0, j = 0;
        while (j < n) {
            ++unmap[s[j]];
            while (unmap.size() > 2) {
                --unmap[s[i]];
                if (unmap[s[i]] == 0) {
                    unmap.erase(s[i]);
                }
                ++i;
            }
            ans = max(ans, j-i+1);
            ++j;
        }
        return ans;
    }
};