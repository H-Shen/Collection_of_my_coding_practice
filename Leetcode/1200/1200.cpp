class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minVal = numeric_limits<int>::max();
        int n = (int)arr.size();
        for (int i = 0; i < n - 1; ++i) {
            minVal = min(minVal, arr.at(i + 1) - arr.at(i));
        }
        vector<vector<int> > result;
        for (int i = 0; i < n - 1; ++i) {
            if (arr.at(i + 1) - arr.at(i) == minVal) {
                result.emplace_back(vector<int>{arr.at(i),arr.at(i+1)});
            }
        }
        return result;
    }
};