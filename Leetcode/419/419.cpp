class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty()) return 0;
        int n = (int)board.size();
        int m = (int)board.front().size();
        constexpr int STEPS = 4;
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};
        auto countAround = [&](int r, int c) {
            int counter = 0;
            int new_r, new_c;
            for (int step = 0; step < STEPS; ++step) {
                new_r = r + dx[step];
                new_c = c + dy[step];
                if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && board.at(new_r).at(new_c) == 'X') {
                    ++counter;
                }
            }
            return counter;
        };
        int counter1 = 0;   // the ship contains one 'X' only
        int counter2 = 0;   // the ship contains more than one 'X'
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board.at(i).at(j) == 'X') {
                    int temp = countAround(i, j);
                    if (temp == 0) ++counter1;
                    else if (temp == 1) ++counter2;
                }
            }
        }
        return counter1 + (counter2 >> 1);
    }
};