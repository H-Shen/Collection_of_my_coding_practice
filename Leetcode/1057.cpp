class Solution {
public:
    Solution() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        if (bikes.empty() || workers.empty()) {
            return vector<int>();
        }
        int n = (int)workers.size();
        int m = (int)bikes.size();
        vector<tuple<int,int,int> > vec(n*m);
        int index = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                get<0>(vec[index]) = i;
                get<1>(vec[index]) = j;
                get<2>(vec[index]) = abs(workers[i][0]-bikes[j][0]) + abs(workers[i][1]-bikes[j][1]);
                ++index;
            }
        }
        sort(vec.begin(), vec.end(), [](const auto &l, const auto &r){
            if (get<2>(l) == get<2>(r)) {
                if (get<0>(l) == get<0>(r)) {
                    return get<1>(l) < get<1>(r);
                }
                return get<0>(l) < get<0>(r);
            }
            return get<2>(l) < get<2>(r);
        });

        constexpr int MAXN = 1005;
        bitset<MAXN> vis1, vis2;
        vector<int> ans(n);
        int counter = 0;
        index = 0;
        while (counter < n) {
            if (!vis1[get<0>(vec[index])] && !vis2[get<1>(vec[index])]) {
                ans[get<0>(vec[index])] = get<1>(vec[index]);
                ++counter;
                vis1[get<0>(vec[index])] = true;
                vis2[get<1>(vec[index])] = true;
            }
            ++index;
        }
        return ans;
    }
};