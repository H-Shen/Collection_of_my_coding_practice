class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = (int)cards.size();
        unordered_map<int, vector<int>> unmap;
        for (int i = 0; i < n; ++i) {
            unmap[cards[i]].emplace_back(i);
        }
        int minVal = numeric_limits<int>::max();
        for (auto& [k, vList] : unmap) {
            if (vList.size() > 1) {
                int length = (int)vList.size();
                for (int i = 1; i < length; ++i) {
                    minVal = min(minVal, vList[i] - vList[i-1] + 1);
                }
            }
        }
        return (minVal == numeric_limits<int>::max()) ? -1 : minVal;
    }
};