class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int>(n));
        int val = 1;
        int dir = 0;    // right:0 down:1 left:2 up:3
        int total = n*n;
        int i = 0, j = 0;

        while (val <= total) {
            result.at(i).at(j) = val;
            ++val;
            if (dir == 0) {
                if (j==n-1 || result.at(i).at(j+1) != 0) {
                    dir = 1;
                    ++i;
                }
                else {
                    ++j;
                }
            }
            else if (dir == 1) {
                if (i==n-1 || result.at(i+1).at(j) != 0) {
                    dir = 2;
                    --j;
                }
                else {
                    ++i;
                }
            }
            else if (dir == 2) {
                if (j==0 || result.at(i).at(j-1) != 0) {
                    dir = 3;
                    --i;
                }
                else {
                    --j;
                }
            }
            else {
                if (i==0 || result.at(i-1).at(j) != 0) {
                    dir = 0;
                    ++j;
                }
                else {
                    --i;
                }
            }
        }
        return result;
    }
};