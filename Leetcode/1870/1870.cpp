class Solution {
public:
    bool check(int speed, const vector<int> &dist, const double &hour) {
        double sum = 0.0;
        int length = (int)dist.size();
        for (int i = 0; i < length; ++i) {
            sum += dist[i] * 1.0 / speed;
            if (i != length - 1) {
                sum = ceil(sum);
            }
        }
        return sum <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1;
        int right = 1e7;
        int mid;
        int ans = -1;
        // https://blog.csdn.net/yanyanwenmeng/article/details/82317166
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (check(mid, dist, hour)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};