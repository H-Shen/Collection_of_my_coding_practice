class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = -1;
        for (const auto &i : rectangles) {
            maxLen = max(maxLen, min(i[0], i[1]));
        }
        int counter = 0;
        for (const auto &i : rectangles) {
            if (min(i[0], i[1]) == maxLen) {
                ++counter;
            }
        }
        return counter;
    }
};