class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> vec(seats.size());
        int n = 0;
        int length = (int)seats.size();
        for (int i = 0; i < length; ++i) {
            if (seats.at(i)) {
                vec.at(n++) = i;
            }
        }
        int maxDist = -1;
        if (n == 1) {
            if (vec.at(n - 1) == 0 || vec.at(0) == length - 1) {
                maxDist = length - 1;
            }
            else {
                maxDist = max(vec.at(0), length - 1 - vec.at(0));
            }
        }
        else {
            // front
            if (vec.at(0) > 0) {
                maxDist = max(maxDist, vec.at(0));
            }
            // middle
            for (int i = 0; i < n - 1; ++i) {
                int left = vec.at(i);
                int right = vec.at(i + 1);
                maxDist = max(maxDist, (right - left) / 2);
            }
            // end
            if (vec.at(n - 1) < length - 1) {
                maxDist = max(maxDist, length - 1 - vec.at(n - 1));
            }
        }
        return maxDist;
    }
};
