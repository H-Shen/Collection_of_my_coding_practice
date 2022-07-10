class Solution {
public:
    bool canChange(string start, string target) {
        int n = (int)start.size();
        vector<pair<int,int>> v1, v2;
        for (int i = 0; i < n; ++i) {
            if (start[i] != '_') {
                v1.emplace_back(start[i], i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (target[i] != '_') {
                v2.emplace_back(target[i], i);
            }
        }
        if (v1.size() != v2.size()) {
            return false;
        }
        int length = (int)v1.size();
        for (int i = 0; i < length; ++i) {
            if (v1[i].first != v2[i].first) {
                return false;
            }
        }
        for (int i = 0; i < length; ++i) {
            if (v1[i].first == 'L' && v1[i].second < v2[i].second) {
                return false;
            }
            if (v1[i].first == 'R' && v1[i].second > v2[i].second) {
                return false;
            }
        }
        return true;
    }
};