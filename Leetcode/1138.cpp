class Solution {
public:
    string path(const vector<pair<int,int>> &pos, char src, char dest) {
        string result;
        if (src == dest) {
            result = "!";
            return result;
        }
        auto [r1, c1] = pos[src - 'a'];
        auto [r2, c2] = pos[dest - 'a'];
        if (r1 == r2) {
            if (c1 < c2) {
                result = string(c2 - c1, 'R') + '!';
            }
            else {
                result = string(c1 - c2, 'L') + '!';
            }
        }
        else if (c1 == c2) {
            if (r1 < r2) {
                result = string(r2 - r1, 'D') + '!';
            }
            else {
                result = string(r1 - r2, 'U') + '!';
            }
        }
        else {
            // Case 1:
            if (src == 'z') {
                 result = string(r1 - r2, 'U') + string(c2 - c1, 'R') + '!';
            }
            
            // Case 2:
            else if (dest == 'z') {
                 result = string(c1 - c2, 'L') + string(r2 - r1, 'D') + '!';
            }
            
            // Case 3:
            else {
                if (r1 < r2) {
                    result = string(r2 - r1, 'D');
                }
                else {
                    result = string(r1 - r2, 'U');
                }
                if (c1 < c2) {
                    result += string(c2 - c1, 'R');
                }
                else {
                    result += string(c1 - c2, 'L');
                }
                result.push_back('!');
            }
        }
        return result;
    }
    string alphabetBoardPath(string target) {
        constexpr int MAXN = 26;
        const vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        vector<pair<int,int>> pos(MAXN);
        int n = (int)board.size();
        for (int i = 0; i < n; ++i) {
            int m = (int)board[i].size();
            for (int j = 0; j < m; ++j) {
                pos[board[i][j] - 'a'].first = i;
                pos[board[i][j] - 'a'].second = j;
            }
        }
        char cur = 'a';
        string ans;
        for (const auto &i : target) {
            ans += path(pos, cur, i);
            cur = i;
        }
        return ans;
    }
};