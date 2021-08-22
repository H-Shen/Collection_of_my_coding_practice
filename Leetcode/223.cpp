using ll = long long;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // 求两个矩阵左下角的最大值
        ll x1 = max(ax1,bx1);
        ll y1 = max(ay1,by1);
        // 求两个矩形右上角的最小值
        ll x2 = min(ax2,bx2);
        ll y2 = min(ay2,by2);
        ll overlapped;
        // 一旦某个方向相差为负 说明它们不相交
        if (x2-x1<0 || y2-y1<0) {
            overlapped = 0;
        } else {
            overlapped = (x2-x1)*(y2-y1);
        }
        return (ll)(ax2-ax1)*(ay2-ay1)+(ll)(bx2-bx1)*(by2-by1)-overlapped;
    }
};