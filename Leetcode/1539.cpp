class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cur = 1;
        while (true) {
            if (!binary_search(arr.begin(), arr.end(), cur)) {
                --k;
                if (k == 0) {
                    break;
                }
            }
            ++cur;
        }
        return cur;
    }
};