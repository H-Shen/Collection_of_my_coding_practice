class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = (int)arr.size();
        int startIndex, endIndex, length;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                startIndex = 0;
                endIndex = 0;
            }
            else {
                if (arr.at(i) == arr.at(startIndex)) {
                    endIndex = i;
                } else {
                    length = endIndex - startIndex + 1;
                    if (length * 1.0 > n / 4.0) {
                        return arr.at(endIndex);
                    }
                    startIndex = i;
                    endIndex = i;
                }
            }
        }
        return arr.at(endIndex);
    }
};