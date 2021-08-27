class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        constexpr int MAXN = 3;
        vector<vector<char> > M(MAXN, vector<char>(MAXN));
        char ch = 'X';
        int counter = 0;
        for (const auto &i : moves) {
            M[i.front()][i.back()] = ch;
            ++counter;
            if (ch == 'X') {
                ch = 'O';
            } else {
                ch = 'X';
            }
        }
        if (M[0][0] == 'X' && M[0][1] == 'X' && M[0][2] == 'X') return "A";
        if (M[1][0] == 'X' && M[1][1] == 'X' && M[1][2] == 'X') return "A";
        if (M[2][0] == 'X' && M[2][1] == 'X' && M[2][2] == 'X') return "A";
        if (M[0][0] == 'X' && M[1][0] == 'X' && M[2][0] == 'X') return "A";
        if (M[0][1] == 'X' && M[1][1] == 'X' && M[2][1] == 'X') return "A";
        if (M[0][2] == 'X' && M[1][2] == 'X' && M[2][2] == 'X') return "A";
        if (M[0][0] == 'X' && M[1][1] == 'X' && M[2][2] == 'X') return "A";
        if (M[0][2] == 'X' && M[1][1] == 'X' && M[2][0] == 'X') return "A";
        
        if (M[0][0] == 'O' && M[0][1] == 'O' && M[0][2] == 'O') return "B";
        if (M[1][0] == 'O' && M[1][1] == 'O' && M[1][2] == 'O') return "B";
        if (M[2][0] == 'O' && M[2][1] == 'O' && M[2][2] == 'O') return "B";
        if (M[0][0] == 'O' && M[1][0] == 'O' && M[2][0] == 'O') return "B";
        if (M[0][1] == 'O' && M[1][1] == 'O' && M[2][1] == 'O') return "B";
        if (M[0][2] == 'O' && M[1][2] == 'O' && M[2][2] == 'O') return "B";
        if (M[0][0] == 'O' && M[1][1] == 'O' && M[2][2] == 'O') return "B";
        if (M[0][2] == 'O' && M[1][1] == 'O' && M[2][0] == 'O') return "B";
        
        if (counter == 9) {
            return "Draw";
        }
        return "Pending";
    }
};