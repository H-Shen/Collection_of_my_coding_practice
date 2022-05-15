class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int maxVal = 0;
        int n = (int)special.size();
        int current = bottom;
        int i = 0;
        while (i < n) {
            if (current == special[i]) {
                ++current;
            }
            else {
                maxVal = max(maxVal, special[i] - current);
                current = special[i] + 1;
            }
            ++i;
        }
        if (current <= top) {
            maxVal = max(maxVal, top - current + 1);
        }
        return maxVal;
    }
};