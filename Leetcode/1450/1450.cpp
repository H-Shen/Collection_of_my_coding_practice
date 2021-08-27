class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = (int)startTime.size();
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            if (queryTime >= startTime.at(i) && queryTime <= endTime.at(i)) {
                ++counter;
            }
        }
        return counter;
    }
};