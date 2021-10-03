class Solution {
public:
    int minimumMoves(string s) {
        int n = (int)s.size();
        int counter = 0;
        for (int i = 0; i < n; ) {
            if (s[i] == 'O') {
                ++i;
            }
            else if (s[i] == 'X') {
                if (i + 2 < n) {
                    ++counter;
                    i += 3;
                } else {
                    ++counter;
                    break;
                }
            }
        }
        return counter;
    }
};