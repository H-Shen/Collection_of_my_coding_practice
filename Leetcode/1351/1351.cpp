class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int sum = 0;
        for (auto &i :grid) {
            sum += static_cast<int>(i.size() - (upper_bound(i.begin(), i.end(), 0, greater<>()) - i.begin()));
        }
        return sum;
    }
};