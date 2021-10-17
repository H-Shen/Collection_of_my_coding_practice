class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int n = (int)seats.size();
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            counter += abs(seats[i] - students[i]);
        }
        return counter;
    }
};