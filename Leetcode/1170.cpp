class Solution {
public:
    int f(const string &s) {
        constexpr int MAXN = 26;
        int stats[MAXN]{};
        for (const auto &i : s) ++stats[i - 'a'];
        for (int i = 0; i < MAXN; ++i) {
            if (stats[i] > 0) return stats[i];
        }
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<pair<string,int> > vec(words.size());
        for (size_t i = 0; i != words.size(); ++i) {
            vec[i].first = words[i];
            vec[i].second = f(words[i]);
        }
        auto cmp = [](const auto &l, const auto &r) {
            return l.second < r.second;
        };
        sort(vec.begin(), vec.end(), cmp);
        vector<int> result(queries.size());
        int temp;
        for (size_t i = 0; i != queries.size(); ++i) {
            temp = f(queries[i]);
            if (temp < vec.front().second) {
                result[i] = (int)vec.size();
            }
            else if (temp > vec.back().second) {
                continue;
            }
            else {
                pair<string, int> p = {queries[i], temp};
                auto iter = upper_bound(vec.begin(), vec.end(), p, cmp);
                --iter;
                result[i] = (int)(words.size() - 1 - (iter - vec.begin()));
            }
        }
        return result;
    }
};