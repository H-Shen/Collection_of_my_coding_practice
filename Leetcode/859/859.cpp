class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        vector<int> changes;
        int n = (int)A.size();
        for (int i = 0; i < n; ++i) {
            if (A[i] != B[i]) {
                changes.emplace_back(i);
                if (changes.size() > 2) {
                    return false;
                }
            }
        }
        if (changes.empty()) {
            constexpr int MAXN = 26;
            int stats[MAXN]{};
            for (int i = 0; i < n; ++i) {
                ++stats[A[i] - 'a'];
                if (stats[A[i] - 'a'] > 1) {
                    return true;
                }
            }
            return false;
        } else if (changes.size() == 1) {
            return false;
        } else {
            char a0 = A[changes.front()];
            char a1 = A[changes.back()];
            char b0 = B[changes.front()];
            char b1 = B[changes.back()];
            if (a0 == b1 && a1 == b0) {
                return true;
            }
        }
        return false;
    }
};