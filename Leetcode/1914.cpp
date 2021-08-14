class Solution {
public:
    vector<int> getArray(const vector<vector<int>>& grid, int original_i, int original_j, int h, int w) {
        vector<int> ans;
        if (h == 0 || w == 0) {
            return ans;
        }
        else if (h == 1) {
            for (int j = original_j, counter = 0; counter < w; ++counter, ++j) {
                ans.emplace_back(grid[original_i][j]);
            }
            return ans;
        }
        else if (w == 1) {
            for (int i = original_i, counter = 0; counter < w; ++counter, ++i) {
                ans.emplace_back(grid[i][original_j]);
            }
            return ans;
        }
        // down
        for (int i = original_i, j = original_j, counter = 0; counter < h; ++counter, ++i) {
            ans.emplace_back(grid[i][j]);
        }
        ans.pop_back();
        // right
        for (int i = original_i + h - 1, j = original_j, counter = 0; counter < w; ++counter, ++j) {
            ans.emplace_back(grid[i][j]);
        }
        ans.pop_back();
        // up
        for (int i = original_i + h - 1, j = original_j + w - 1, counter = 0; counter < h; ++counter, --i) {
            ans.emplace_back(grid[i][j]);
        }
        ans.pop_back();
        // left
        for (int i = original_i, j = original_j + w - 1, counter = 0; counter < w; ++counter, --j) {
            ans.emplace_back(grid[i][j]);
        }
        ans.pop_back();
        return ans;
    }
    void updateArray(vector<vector<int>> &grid, const vector<int> &ans, int original_i, int original_j, int h, int w) {
        if (grid.empty() || ans.empty() || h == 0 || w == 0) {
            return;
        }
        auto iter = ans.cbegin();
        if (h == 1) {
            for (int j = original_j, counter = 0; counter < w; ++counter, ++j) {
                grid[original_i][j] = *iter;
                ++iter;
            }
        }
        else if (w == 1) {
            for (int i = original_i, counter = 0; counter < w; ++counter, ++i) {
                grid[i][original_j] = *iter;
                ++iter;
            }
        }
        else {
            // down
            for (int i = original_i, j = original_j, counter = 0; counter < h; ++counter, ++i) {
                grid[i][j] = *iter;
                ++iter;
            }
            --iter;
            // right
            for (int i = original_i + h - 1, j = original_j, counter = 0; counter < w; ++counter, ++j) {
                grid[i][j] = *iter;
                ++iter;
            }
            --iter;
            // up
            for (int i = original_i + h - 1, j = original_j + w - 1, counter = 0; counter < h; ++counter, --i) {
                grid[i][j] = *iter;
                ++iter;
            }
            --iter;
            // left
            for (int i = original_i, j = original_j + w - 1, counter = 0; counter < w-1; ++counter, --j) {
                grid[i][j] = *iter;
                ++iter;
            }
        }
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        vector<int> temp;
        int upperBound = min(n,m)/2-1;
        for (int i = 0; i <= upperBound; ++i) {
            temp = getArray(grid, i, i, n-2*i, m-2*i);
            rotate(temp.rbegin(),temp.rbegin() + k % (int)(temp.size()),temp.rend());
            updateArray(grid, temp, i, i, n-2*i, m-2*i);
        }
        return grid;
    }
};