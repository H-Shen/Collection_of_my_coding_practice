class Solution {
public:
    bool canTransform(string start, string end) {
        vector<pair<int,int>> v1, v2;
        int n = (int)start.size();
        for (int i = 0; i < n; ++i) {
            if (start[i] != 'X') {
                v1.emplace_back(start[i], i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (end[i] != 'X') {
                v2.emplace_back(end[i], i);
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
            // RX -> XR
            if (v1[i].first == 'R' && v1[i].second > v2[i].second) {
                return false;
            }
            // XL -> LX
            if (v1[i].first == 'L' && v1[i].second < v2[i].second) {
                return false;
            }
        }
        return true;
    }
};