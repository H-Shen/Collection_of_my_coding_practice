class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+1);
        int l,r,update;
        for (auto&i : bookings) {
            l = i[0]-1;
            r = i[1];
            update = i[2];
            diff[l] += update;
            diff[r] -= update;
        }
        diff.pop_back();
        for (int i = 1; i < n; ++i) {
            diff[i] += diff[i-1];
        }
        return diff;
    }
};