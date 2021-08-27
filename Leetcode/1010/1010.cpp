struct hashFunc {
    size_t operator()(const pair<int,int> &o) const {
        return hash<int>()(o.first)^hash<int>()(o.second);
    }
};

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> unmap;
        for (const auto &i : time) {
            ++unmap[i];
        }
        constexpr int MINN = 60;
        constexpr int MAXN = 1020;
        unordered_set<pair<int, int>, hashFunc > unset;
        vector<pair<int, int> > vec;
        int diff;
        int total = 0;
        for (const auto &[k, v] : unmap) {
            for (int i = MINN; i <= MAXN; i += 60) {
                diff = i - k;
                if (unmap.find(diff) != unmap.end()) {
                    if (k < diff) {
                        unset.insert({k, diff});
                    } else {
                        unset.insert({diff, k});
                    }
                }
            }
        }
        for (const auto &[a, b] : unset) {
            if (a == b) {
                int temp = unmap[a];
                total += temp*(temp-1)/2;
            } else {
                total += unmap[a]*unmap[b];
            }
        }
        return total;
    }
};