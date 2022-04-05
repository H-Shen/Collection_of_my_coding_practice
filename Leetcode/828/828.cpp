constexpr int MAXN = 26;

class Solution {
public:
    int uniqueLetterString(string s) {
        int n = (int)s.size();
        vector<vector<int>> stats(26);
        for (int i = 0; i < n; ++i) {
            stats[s[i] - 'A'].emplace_back(i);
        }
        int counter = 0;
        // calculate the contribution of each character
        for (int i = 0; i < MAXN; ++i) {
            if (!stats[i].empty()) {
                int length = (int)stats[i].size();
                int left, right;
                for (int j = 0; j < length; ++j) {
                    if (j == 0) {
                        left = stats[i][j] + 1;
                    }
                    else {
                        left = stats[i][j] - stats[i][j-1];
                    }
                    if (j == length-1) {
                        right = n - stats[i][j];
                    }
                    else {
                        right = stats[i][j+1] - stats[i][j];
                    }
                    // left all possible results * right all possible results
                    counter += left * right;
                }
            }
        }
        return counter;
    }
};