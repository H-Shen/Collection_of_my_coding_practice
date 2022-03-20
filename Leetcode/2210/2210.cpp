class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> A;
        for (auto&i : nums) {
            if (A.empty()) {
                A.emplace_back(i);
            }
            else if (A.back() != i) {
                A.emplace_back(i);
            }
        }
        int counter = 0;
        int n = (int)A.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && i < n-1) {
                if (A[i] > A[i-1] && A[i] > A[i+1]) ++counter;
                else if (A[i] < A[i-1] && A[i] < A[i+1]) ++counter;
            }
        }
        return counter;
    }
};