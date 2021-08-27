class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int> > unmap;
        for (const auto &i : logs) {
            unmap[i[0]].insert(i[1]);
        }
        vector<int> result(k);
        for (const auto &[k, v] : unmap) {
            result.at((int)v.size() - 1)++; 
        }
        return result;
    }
};