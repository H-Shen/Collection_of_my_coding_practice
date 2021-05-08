class Solution {
public:
    Solution() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end(), [](const auto &l, const auto &r){
            return l[1]-l[0]+1 < r[1]-r[0]+1;
        });
        set<pair<int,int>> s;
        decltype(s)::iterator iter;
        int m = (int)queries.size();
        for (int i = 0; i < m; ++i) {
            s.insert(make_pair(queries[i], i));
        }
        vector<int> result(m,-1);
        for (const auto &i : intervals) {
            iter = s.lower_bound(make_pair(i[0], 0));
            while (true) {
                if (iter == s.end()) {
                    break;
                }
                if (iter->first > i[1]) {
                    break;
                }
                result[iter->second] = i[1]-i[0]+1;
                iter = s.erase(iter);
            }
        }
        return result;
    }
};