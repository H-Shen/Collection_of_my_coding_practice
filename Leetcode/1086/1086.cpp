class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, vector<int> > unmap;
        for (const auto &i : items) {
            unmap[i[0]].emplace_back(i[1]);
        }
        vector<vector<int> > result;
        int sum = 0;
        for (auto &[k, v] : unmap) {
            nth_element(v.begin(), v.begin() + 4, v.end(), greater<>());
            sum = 0;
            for (int i = 0; i < 5; ++i) {
                sum += v[i];
            }
            result.emplace_back(vector<int>{k, sum / 5});
        }
        sort(result.begin(), result.end(), [](const auto &l, const auto &r){
            return l[0] < r[0];
        });
        return result;
    }
};