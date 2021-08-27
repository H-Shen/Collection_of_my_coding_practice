class Solution {
public:
    int counter = 0;
    void dfs(int row, int col, int leftDiagonal, int rightDiagonal, int n) {
        if (row >= n) {
            ++counter;
        }
        int bits = (~(col | leftDiagonal | rightDiagonal)) & ((1 << n) - 1);
        while (bits > 0) {
            int lowbit = bits & (-bits);
            int newCol = col | lowbit;
            int newLeftDiagonal = (leftDiagonal | lowbit) << 1;
            int newRightDiagonal = (rightDiagonal | lowbit) >> 1;
            int newRow = row + 1;
            dfs(newRow, newCol, newLeftDiagonal, newRightDiagonal, n);
            // set the right-most 1 to zero
            bits = bits & (bits - 1);
        }
    }
    int totalNQueens(int n) {
        dfs(0, 0, 0, 0, n);
        return counter;
    }
};