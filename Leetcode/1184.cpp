class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start == destination) {
            return 0;
        }
        int sum = 0;
        for (const auto &i : distance) {
            sum += i;
        }
        if (start > destination) {
            swap(start, destination);
        }
        int curSum = 0;
        for (int i = start; i < destination; ++i) {
            curSum += distance[i];
        }
        return min(curSum, sum - curSum);
    }
};