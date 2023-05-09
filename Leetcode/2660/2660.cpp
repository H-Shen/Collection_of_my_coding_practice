class Solution {
public:
    int getScore(vector<int>& v, int n) {
        int s = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= 2 && (v[i-1] == 10 || v[i-2] == 10)) {
                s += 2*v[i];
            }
            else if (i >= 1 && v[i-1] == 10) {
                s += 2*v[i];
            }
            else {
                s += v[i];
            }
        }
        return s;
    }
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n = (int)player1.size();
        int s1 = getScore(player1, n);
        int s2 = getScore(player2, n);
        if (s1 == s2) return 0;
        else if (s1 > s2) return 1;
        return 2;
    }
};
