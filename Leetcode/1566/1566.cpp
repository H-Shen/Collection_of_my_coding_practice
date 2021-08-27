class Solution {
public:
    // Check if it is subarray by kmp
    bool isSubarray(vector<int> const &Text, vector<int> const &Pattern) {
        vector<int> b(Pattern.size() + 1, -1);
        // Preprocess
        for (size_t i = 1; i <= Pattern.size(); i++) {
            int pos = b[i - 1];
            while (pos != -1 && Pattern[pos] != Pattern[i - 1])
                pos = b[pos];
            b[i] = pos + 1;
        }
        // Search
        int sp = 0, kp = 0;
        while (sp < Text.size()) {
            while (kp != -1 && (kp == Pattern.size() || Pattern[kp] != Text[sp])) {
                kp = b[kp];
            }
            ++kp;
            ++sp;
            if (kp == Pattern.size()) {
                return true;
            }
        }
        return false;
    }
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = (int)arr.size();
        vector<int> v(m);
        for (int i = 0; i + m - 1 < n; ++i) {
            for (int j = i, idx = 0; j <= i + m - 1; ++j, ++idx) {
                v[idx] = arr[j];
            }
            // extend the pattern
            vector<int> vExt(m * k);
            for (int j = 0, idx = 0; j < k; ++j) {
                for (int h = 0; h < m; ++h) {
                    vExt[idx] = v[h];
                    ++idx;
                }
            }
            if (isSubarray(arr, vExt)) {
                return true;
            }
        }
        return false;
    }
};