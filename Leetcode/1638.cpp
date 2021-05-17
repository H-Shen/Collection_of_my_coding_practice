class Solution {
public:
    int f(const string &s, const string &t, int i, int j, int n, int m) {
        int left = 0;
        int right = 0;
        int new_i = i;
        int new_j = j;
        // left
        do {
            ++left;
            --new_i;
            --new_j;
        } while (new_i >= 0 && new_j >= 0 && s[new_i] == t[new_j]);
        new_i = i;
        new_j = j;
        // right
        do {
            ++right;
            ++new_i;
            ++new_j;
        } while (new_i < n && new_j < m && s[new_i] == t[new_j]);
        return left*right;
    }
    int countSubstrings(string s, string t) {
        // 中心扩散法
        int sum = 0;
        int n = (int)s.size();
        int m = (int)t.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i] != t[j]) {
                    sum += f(s,t,i,j,n,m);
                }
            }
        }
        return sum;
    }
};