class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int maxLength = 0;
        deque<char> d;
        for (const char &ch : s) {
            ++umap[ch];
            d.push_back(ch);
            if (umap[ch] > 1) {
                while (umap[ch] > 1) {
                    --umap[d.front()];
                    d.pop_front();
                }
            }
            maxLength = max(maxLength, (int)d.size());
        }
        return maxLength;
    }
};