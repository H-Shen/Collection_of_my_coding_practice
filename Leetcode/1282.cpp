class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = (int)groupSizes.size();
        vector<vector<int> > groupSize2People(n + 1);
        for (int i = 0; i < n; ++i) {
            groupSize2People.at(groupSizes.at(i)).emplace_back(i);
        }
        vector<vector<int> > result;
        size_t groupSize;
        for (int i = 1; i <= n; ++i) {
            if (!groupSize2People.at(i).empty()) {
                groupSize = i;
                vector<int> group;
                for (const auto &j : groupSize2People.at(i)) {
                    group.emplace_back(j);
                    if (group.size() == groupSize) {
                        result.emplace_back(group);
                        vector<int>().swap(group);
                    }
                }
            }
        }
        return result;
    }
};