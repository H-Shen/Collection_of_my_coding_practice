class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > result;
        int left, right;
        for (const auto &i : intervals) {
            left = i.at(0);
            right = i.at(1);
            if (result.empty()) {
                result.push_back({left, right});
            } else if (result.back().at(1) < left) {
                result.push_back({left, right});
            } else {
                result.back().at(1) = max(result.back().at(1), right);
            }
        }
        return result;
    }
};