constexpr int N = 2020205;
constexpr int DIFF = 1010100;
int A[N];

class Solution {
public:
    // O(n)
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        memset(A, 0, sizeof A);
        int maxIndex = -1;
        int temp;
        for (auto &i : nums) {
            temp = a*i*i+b*i+c+DIFF;
            ++A[temp];
            maxIndex = max(maxIndex, temp);
        }
        int index = 0;
        for (int i = 0; i <= maxIndex; ++i) {
            if (A[i] > 0) {
                for (int j = 0; j < A[i]; ++j) {
                    nums[index++] = i-DIFF;
                }
            }
        }
        return nums;
    }
};