class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {

        int maxVal = -1;
        int maxValPos = 0;
        int len = static_cast<int>(A.size());

        for (int i = 0; i < len; ++i) {
            if (maxVal < A[i]) {
                maxVal = A[i];
                maxValPos = i;
            }
        }

        return maxValPos;
    }
};