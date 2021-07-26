class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        constexpr int INF = 0x3f3f3f3f;
        int ret = INF;
        int mid;
        int start = 0;
        int end = (int)arr.size() - 1;
        while (start <= end) {
            mid = start + ((end - start) >> 1);
            if (arr[mid] < mid) {
                start = mid + 1;
            }
            else if (arr[mid] > mid) {
                end = mid - 1;
            }
            else {
                ret = min(ret, mid);
                end = mid - 1;  // since the lowerbound must be in [start,end-1]
            }
        }
        return (ret == INF) ? -1 : ret;
    }
};