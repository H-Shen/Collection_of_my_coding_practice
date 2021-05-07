class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        sort(rooms.begin(), rooms.end(), [](const auto &l, const auto &r) {
            return l[1] > r[1];
        });
        int m = (int)queries.size();
        for (int i = 0; i < m; ++i) {
            queries[i].emplace_back(i);
        }
        sort(queries.begin(), queries.end(), [](const auto &l, const auto &r){
            return l[1] > r[1];
        });
        vector<int> result(m, -1);
        int index = 0;
        set<int> s;
        int n = (int)rooms.size();
        for (const auto &i : queries) {
            while (index < n && rooms[index][1] >= i[1]) {
                s.insert(rooms[index][0]);
                ++index;
            }
            if (!s.empty()) {
                int prefer0, prefer1;
                auto iter = s.lower_bound(i[0]);
                if (iter == s.end()) {
                    prefer0 = numeric_limits<int>::max();
                } else {
                    prefer0 = *iter;
                }
                if (iter == s.begin()) {
                    prefer1 = prefer0;
                } else {
                    prefer1 = *(--iter);
                }
                int diff0 = abs(prefer0 - i[0]);
                int diff1 = abs(prefer1 - i[0]);
                if (diff0 < diff1) {
                    result[i[2]] = prefer0;
                } else {
                    result[i[2]] = prefer1;
                }
            }
        }
        return result;
    }
};