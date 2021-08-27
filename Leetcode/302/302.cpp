class Solution {
public:
    bool checkCol(vector<vector<char>>&image, int n, int col) {
        for (int i = 0; i < n; ++i) {
            if (image[i][col] == '1') {
                return true;
            }
        }
        return false;
    }
    bool checkRow(vector<vector<char>>&image, int m, int row) {
        for (int j = 0; j < m; ++j) {
            if (image[row][j] == '1') {
                return true;
            }
        }
        return false;
    }
    // O(mlogm+nlogn) binary search in 4 directions
    int minArea(vector<vector<char>>& image, int x, int y) {
        int left, right, up, down;
        int n = (int)image.size();
        int m = (int)image[0].size();
        int l,r,mid,ret;
        // left
        l = 0; r = y; ret = numeric_limits<int>::max();
        while (l <= r) {
            mid = l+((r-l)>>1);
            if (checkCol(image,n,mid)) {
                ret = min(ret,mid);
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        left = ret;
        // right
        l = y; r = m-1; ret = numeric_limits<int>::min();
        while (l <= r) {
            mid = l+((r-l)>>1);
            if (checkCol(image,n,mid)) {
                ret = max(ret,mid);
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        right = ret;
        // up
        l = 0; r = x; ret = numeric_limits<int>::max();
        while (l <= r) {
            mid = l+((r-l)>>1);
            if (checkRow(image,m,mid)) {
                ret = min(ret,mid);
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        up = ret;
        // down
        l = x; r = n-1; ret = numeric_limits<int>::min();
        while (l <= r) {
            mid = l+((r-l)>>1);
            if (checkRow(image,m,mid)) {
                ret = max(ret,mid);
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        down = ret;
        return (right-left+1)*(down-up+1);
    }
    // O(mn)
    int minArea2(vector<vector<char>>& image, int x, int y) {
        int left = numeric_limits<int>::max();
        int right = numeric_limits<int>::min();
        int up = numeric_limits<int>::max();
        int down = numeric_limits<int>::min();
        int n = (int)image.size();
        int m = (int)image[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (image[i][j] == '1') {
                    left = min(left,j);
                    right = max(right,j);
                    up = min(up,i);
                    down = max(down,i);
                }
            }
        }
        return (right-left+1)*(down-up+1);
    }
};