class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> unmap;
        for (const auto &i : nums) ++unmap[i];
        vector<pair<int, int> > temp;
        for (const auto &i : nums) temp.emplace_back(make_pair(i, unmap[i]));
        sort(temp.begin(), temp.end(), [](const pair<int, int>&l, const pair<int, int>&r){
            if (l.second == r.second) return l.first > r.first;
            return l.second < r.second;
        });
        vector<int> ans(temp.size());
        for (size_t i = 0; i != temp.size(); ++i) {
            ans.at(i) = temp.at(i).first;
        }
        return ans;
    }
};