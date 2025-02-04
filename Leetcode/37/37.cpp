class Solution {
private:
    static constexpr int SIZE = 9;
    bool preprocessSudoku(std::vector<std::vector<int>>& grid,
                          std::vector<int>& row_masks,
                          std::vector<int>& col_masks,
                          std::vector<int>& box_masks) {
        bool modified = false;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (grid[i][j] != -1) continue;
                int box_idx = (i/3)*3 + (j/3);
                int candidates = ~(row_masks[i] | col_masks[j] | box_masks[box_idx]) & 0x1FF;
                if (__builtin_popcount(candidates) == 1) {
                    int num = __builtin_ffs(candidates) - 1;
                    grid[i][j] = num + 1;
                    int mask = 1 << num;
                    row_masks[i] |= mask;
                    col_masks[j] |= mask;
                    box_masks[box_idx] |= mask;
                    modified = true;
                    continue;
                }
                int found_num = -1;
class Solution {
private:
    static constexpr int SIZE = 9;
    bool preprocessSudoku(std::vector<std::vector<int>>& grid,
                          std::vector<int>& row_masks,
                          std::vector<int>& col_masks,
                          std::vector<int>& box_masks) {
        bool modified = false;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (grid[i][j] != -1) continue;
                int box_idx = (i/3)*3 + (j/3);
                int candidates = ~(row_masks[i] | col_masks[j] | box_masks[box_idx]) & 0x1FF;
                if (__builtin_popcount(candidates) == 1) {
                    int num = __builtin_ffs(candidates) - 1;
                    grid[i][j] = num + 1;
                    int mask = 1 << num;
                    row_masks[i] |= mask;
                    col_masks[j] |= mask;
                    box_masks[box_idx] |= mask;
                    modified = true;
                    continue;
                }
                int found_num = -1;
                for (int num = 0; num < SIZE; ++num) {
                    if (!(candidates & (1 << num))) continue;
                    bool row_unique = true;
                    for (int c = 0; c < SIZE; ++c) {
                        if (c == j || grid[i][c] != -1) continue;
                        int other_box = (i/3)*3 + (c/3);
                        int other_candidates = ~(row_masks[i] | col_masks[c] | box_masks[other_box]) & 0x1FF;
                        if (other_candidates & (1 << num)) {
                            row_unique = false;
                            break;
                        }
                    }
                    if (row_unique) {
                        found_num = num;
                        break;
                    }
                    bool col_unique = true;
                    for (int r = 0; r < SIZE; ++r) {
                        if (r == i || grid[r][j] != -1) continue;
                        int other_box = (r/3)*3 + (j/3);
                        int other_candidates = ~(row_masks[r] | col_masks[j] | box_masks[other_box]) & 0x1FF;
                        if (other_candidates & (1 << num)) {
                            col_unique = false;
                            break;
                        }
                    }
                    if (col_unique) {
                        found_num = num;
                        break;
                    }
                    bool box_unique = true;
                    int box_row = (i/3)*3, box_col = (j/3)*3;
                    for (int r = box_row; r < box_row+3; ++r) {
                        for (int c = box_col; c < box_col+3; ++c) {
                            if ((r == i && c == j) || grid[r][c] != -1) continue;
                            int other_box_idx = (r/3)*3 + (c/3);
                            int other_candidates = ~(row_masks[r] | col_masks[c] | box_masks[other_box_idx]) & 0x1FF;
                            if (other_candidates & (1 << num)) {
                                box_unique = false;
                                break;
                            }
                        }
                    }
                    if (box_unique) {
                        found_num = num;
                        break;
                    }
                }
                if (found_num != -1) {
                    grid[i][j] = found_num + 1;
                    int mask = 1 << found_num;
                    row_masks[i] |= mask;
                    col_masks[j] |= mask;
                    box_masks[box_idx] |= mask;
                    modified = true;
                }
            }
        }
        return modified;
    }
    
    bool solveSudokuHelper(std::vector<std::vector<int>>& grid,
                           std::vector<int>& row_masks,
                           std::vector<int>& col_masks,
                           std::vector<int>& box_masks) {
        int row = -1, col = -1, min_candidates = SIZE + 1;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (grid[i][j] != -1) continue;
                int box_idx = (i/3)*3 + (j/3);
                int candidates = ~(row_masks[i] | col_masks[j] | box_masks[box_idx]) & 0x1FF;
                int count = __builtin_popcount(candidates);
                if (count == 0) return false;
                if (count < min_candidates) {
                    min_candidates = count;
                    row = i;
                    col = j;
                }
            }
        }
        if (row == -1) return true;
        int box_idx = (row/3)*3 + (col/3);
        int candidates = ~(row_masks[row] | col_masks[col] | box_masks[box_idx]) & 0x1FF;
        for (int num = 1; num <= SIZE; ++num) {
            int mask = 1 << (num-1);
            if (candidates & mask) {
                grid[row][col] = num;
                row_masks[row] |= mask;
                col_masks[col] |= mask;
                box_masks[box_idx] |= mask;
                if (solveSudokuHelper(grid, row_masks, col_masks, box_masks)) return true;
                grid[row][col] = -1;
                row_masks[row] &= ~mask;
                col_masks[col] &= ~mask;
                box_masks[box_idx] &= ~mask;
            }
        }
        return false;
    }
    
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::vector<int>> grid(SIZE, std::vector<int>(SIZE));
        std::vector<int> row_masks(SIZE, 0), col_masks(SIZE, 0), box_masks(SIZE, 0);
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == '.') {
                    grid[i][j] = -1;
                } else {
                    int num = board[i][j] - '0';
                    grid[i][j] = num;
                    int mask = 1 << (num-1);
                    row_masks[i] |= mask;
                    col_masks[j] |= mask;
                    box_masks[(i/3)*3 + (j/3)] |= mask;
                }
            }
        }
        while (preprocessSudoku(grid, row_masks, col_masks, box_masks)) {}
        solveSudokuHelper(grid, row_masks, col_masks, box_masks);
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                board[i][j] = grid[i][j] + '0';
            }
        }
    }
};
