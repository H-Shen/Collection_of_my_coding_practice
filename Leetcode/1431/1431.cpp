class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size());
        int currMax = *max_element(candies.cbegin(), candies.cend());
        auto iter = result.begin();
        for (const auto &i : candies) {
            if (i + extraCandies >= currMax) {
                *iter = true;
            }
            ++iter;
        }
        return result;
    }
};