/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        constexpr int INF = 0x3f3f3f3f;
        vector<int> p = binaryMatrix.dimensions();
        int row = p[0];
        int col = p[1];
        int leftColIndex = INF;
        int l, r, mid, ans;
        for (int i = 0; i < row; ++i) {
            // lower bound
            l = 0;
            if (leftColIndex == INF) {
                r = col-1;
            }
            else {
                r = leftColIndex;    
            }
            ans = INF;
            while (l <= r) {
                mid = l+((r-l)>>1);
                if (binaryMatrix.get(i, mid) == 1) {
                    ans = min(ans, mid);
                    r = mid-1;
                }
                else {
                    l = mid+1;
                }
            }
            leftColIndex = min(leftColIndex, ans);
        }
        return (leftColIndex == INF) ? -1 : leftColIndex;
    }
};