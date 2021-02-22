class Solution {
public:
    // check if the pair is stable
    bool stable(int id, const vector<int> &pairs_,  const vector<vector<int>>& preferences) {
        auto &p = preferences.at(id);
        int parter_of_id = pairs_.at(id);
        for (const auto &i : p) {
            if (i == parter_of_id) {
                break;
            }
            auto &q = preferences.at(i);
            int rank_of_id = find(q.begin(), q.end(), id) - q.begin();
            int rank_of_partner_of_i = find(q.begin(), q.end(), pairs_.at(i)) - q.begin();
            if (rank_of_id < rank_of_partner_of_i) {
                return false;
            }
        }
        return true;
    }
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<int> pairs_(n);
        int u, v;
        for (const auto &i : pairs) {
            u = i[0];
            v = i[1];
            pairs_.at(u) = v;
            pairs_.at(v) = u;
        }
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            if (!stable(i, pairs_, preferences)) {
                ++counter;
            }
        }
        return counter;
    }
};