class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if (strs.empty()) return 0;
        int n = (int)strs.size();
        int m = (int)strs.front().size();
        vector<string> p(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                p.at(i).push_back(strs.at(j).at(i));
            }
        }
        int counter = 0;
        for (const auto &i : p) {
            if (!is_sorted(i.begin(), i.end())) {
                ++counter;
            }
        }
        return counter;
    }
};