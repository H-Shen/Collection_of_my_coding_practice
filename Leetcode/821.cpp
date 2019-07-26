class Solution {
public:
    vector<int> shortestToChar(string S, char c) {

        auto minimalDistance = [](const vector<int> &a, const int &val) -> int {
            int dist = 0;
            auto pos = static_cast<size_t>(distance(a.begin(), upper_bound(a.begin(), a.end(), val)));
            if (pos == a.size()) {
                dist = val - a.back();
            } else if (pos == 0) {
                dist = a[0] - val;
            } else {
                dist = min(a[pos] - val, val - a[pos - 1]);
            }
            return dist;
        };

        vector<int> distanceList;
        for (size_t i = 0; i < S.size(); ++i) {
            if (S[i] == c) {
                distanceList.push_back(static_cast<int &&>(i));
            }
        }

        vector<int> res(S.size());
        for (size_t i = 0; i < S.size(); ++i) {
            if (S[i] == c) {
                res[i] = 0;
            } else {
                res[i] = minimalDistance(distanceList, static_cast<const int &>(i));
            }
        }
        return res;
    }
};