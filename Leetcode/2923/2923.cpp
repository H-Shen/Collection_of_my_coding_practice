class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        constexpr int N = 105;
        bitset<N> bs;
        int n = (int)grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    if (grid[i][j] == 1) {
                        bs[j] = true;
                    }
                    else {
                        bs[i] = true;
                    }
                }
            }
        }
        
        for (int i = 0; i < N; ++i) {
            if (!bs[i]) return i;
        }
        return -1;
    }
};