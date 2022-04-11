class Solution {
public:
    // O(n^2)
    int countSubstrings(string s) {
        if (s.size() == 1) {
            return 1;
        }
        int n = (int)s.size();
        int counter = 0;
        int l, r;
        // odd length
        for (int i = 0; i < n; ++i) {
            l = i;
            r = i;
            do {
                ++counter;
                --l;
                ++r;
            } while (l >= 0 && r < n && s[l] == s[r]);
        }
        // even length
        for (int i = 0; i < n-1; ++i) {
            if (s[i] == s[i+1]) {
                l = i;
                r = i+1;
                do {
                    ++counter;
                    --l;
                    ++r;
                } while (l >= 0 && r < n && s[l] == s[r]);
            }
        }
        return counter;
    }
};