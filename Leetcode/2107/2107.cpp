class Solution {
public:
    // Sliding Window + Hashmap
    int shareCandies(vector<int>& candies, int k) {
        int n = (int)candies.size();
        unordered_map<int,int> unmap;
        for (int i = k; i < n; ++i) {
            ++unmap[candies[i]];
        }
        int maxFlavor = (int)unmap.size();
        for (int i = 0, j = k; j < n; ++i, ++j) {
            --unmap[candies[j]];
            ++unmap[candies[i]];
            if (unmap[candies[j]] == 0) {
                unmap.erase(candies[j]);
            }
            maxFlavor = max(maxFlavor, (int)unmap.size());
        }
        return maxFlavor;
    }
};