class Solution {
public:
    vector<string> findRelativeRanks(vector<int> &nums) {
        vector<int> nums_copy(nums);
        sort(nums_copy.begin(), nums_copy.end(), greater<>());
        unordered_map<int, int> rankMap;

        for (size_t i = 0; i < nums_copy.size(); ++i) {
            rankMap[nums_copy[i]] = static_cast<int>(i + 1);
        }

        vector<string> rankList(nums_copy.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            if (rankMap[nums[i]] == 1) {
                rankList[i] = "Gold Medal";
            } else if (rankMap[nums[i]] == 2) {
                rankList[i] = "Silver Medal";
            } else if (rankMap[nums[i]] == 3) {
                rankList[i] = "Bronze Medal";
            } else {
                rankList[i] = to_string(rankMap[nums[i]]);
            }
        }
        return rankList;
    }
};