class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int tot = rows * cols;
        int steps = 1;
        // right: 1 down: 2 left: 3 up: 4
        int dir = 1;
        int i = rStart;
        int j = cStart;
        int new_i, new_j;
        vector<vector<int>> result;
        // corner case
        result.emplace_back(vector<int>{i,j});
        if ((int)result.size() == tot) {
            return result;
        }
        
        int counter = 0;
        while (true) {
            if (dir == 1) {
                for (int step = 0; step < steps; ++step) {
                    ++j;
                    if (i >= 0 && i < rows && j >= 0 && j < cols) {
                        result.emplace_back(vector<int>{i,j});
                        if ((int)result.size() == tot) {
                            return result;
                        }
                    }
                }
                dir = 2;
            }
            else if (dir == 2) {
                for (int step = 0; step < steps; ++step) {
                    ++i;
                    if (i >= 0 && i < rows && j >= 0 && j < cols) {
                        result.emplace_back(vector<int>{i,j});
                        if ((int)result.size() == tot) {
                            return result;
                        }
                    }
                }
                dir = 3;
            }
            else if (dir == 3) {
                for (int step = 0; step < steps; ++step) {
                    --j;
                    if (i >= 0 && i < rows && j >= 0 && j < cols) {
                        result.emplace_back(vector<int>{i,j});
                        if ((int)result.size() == tot) {
                            return result;
                        }
                    }
                }
                dir = 4;
            }
            else {
                for (int step = 0; step < steps; ++step) {
                    --i;
                    if (i >= 0 && i < rows && j >= 0 && j < cols) {
                        result.emplace_back(vector<int>{i,j});
                        if ((int)result.size() == tot) {
                            return result;
                        }
                    }
                }
                dir = 1;
            }
            ++counter;
            if (!(counter & 1)) {
                ++steps;
            }
        }
        return result;
    }
};