class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int counter = 0;
        int n = (int)ages.size();
        for (int x = 0; x < n; ++x) {
            if (ages[x] >= 100) {
                int lower, upper;
                if (ages[x] & 1) {
                    lower = (int)(ages[x]*0.5+7) + 1;
                }
                else {
                    lower = ages[x]/2+8;
                }
                upper = ages[x];
                if (lower <= upper) {
                    int lower_pos = lower_bound(ages.begin(),ages.end(),lower) - ages.begin();
                    int upper_pos = (--upper_bound(ages.begin(),ages.end(),upper)) - ages.begin();
                    counter += upper_pos - lower_pos;
                }
            }
            else {
                if (0.5*ages[x]+7 >= 100) {
                    continue;
                }
                int lower, upper;
                if (ages[x] & 1) {
                    lower = (int)(ages[x]*0.5+7) + 1;
                }
                else {
                    lower = ages[x]/2+8;
                }
                upper = min(100, ages[x]);
                if (lower <= upper) {
                    int lower_pos = lower_bound(ages.begin(),ages.end(),lower) - ages.begin();
                    int upper_pos = (--upper_bound(ages.begin(),ages.end(),upper)) - ages.begin();
                    counter += upper_pos - lower_pos;
                }
            }
        }
        return counter;
    }
};