class Solution {
public:
    vector<vector<int> > output;
    vector<int> answer;
    int temp;
    void dfs(int row, int col, int leftDiagonal, int rightDiagonal, int n) {
        if (row >= n) {
            output.emplace_back(answer);
        }
        int bits = (~(col | leftDiagonal | rightDiagonal)) & temp;
        while (bits > 0) {
            int lowbit = bits & (-bits);
            answer.at(row) = (int)log2(lowbit);
            
            int newCol = (col | lowbit);
            int newLeftDiagonal = (leftDiagonal | lowbit) << 1;
            int newRightDiagonal = (rightDiagonal | lowbit) >> 1;
            int newRow = row + 1;
            
            dfs(newRow, newCol, newLeftDiagonal, newRightDiagonal, n);
            // set the right-most 1 to zero
            bits = bits & (bits - 1);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        decltype(output)().swap(output);
        vector<int>().swap(answer);
        answer.resize(n);
        temp = (1 << n) - 1;
        dfs(0, 0, 0, 0, n);
        vector<vector<string> > result;
        vector<string> temp_vec(n, string(n, '.'));
        for (const auto &i : output) {
            vector<string> vec(temp_vec);
            for (size_t j = 0; j != i.size(); ++j) {
                vec.at(j).at(i.at(j)) = 'Q';
            }
            result.emplace_back(vec);
        }
        return result;
    }
};