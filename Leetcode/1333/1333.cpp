class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int> > ans;
        for (const auto &i : restaurants) {
            if (i[4] > maxDistance) {
                continue;
            }
            if (i[3] > maxPrice) {
                continue;
            }
            if (veganFriendly) {
                if (i[2]) {
                    ans.emplace_back(i[0], i[1]);
                }
            } else {
                ans.emplace_back(i[0], i[1]);
            }
        }
        sort(ans.begin(), ans.end(), [](const pair<int, int> &l, const pair<int, int> &r) {
            if (l.second == r.second) return l.first > r.first;
            return l.second > r.second;
        });
        vector<int> output(ans.size());
        for (size_t i = 0; i != ans.size(); ++i) {
            output.at(i) = ans.at(i).first;
        }
        return output;
    }
};