class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum1 = accumulate(A.begin(),A.end(),0);
        int sum2 = accumulate(B.begin(),B.end(),0);
        vector<int> ans;
        unordered_set<int> unset(B.begin(),B.end());
        int n = (int)A.size();
        int temp;
        for (int i = 0; i < n; ++i) {
            temp = (sum2-sum1)/2+A[i];
            if (unset.find(temp) != unset.end()) {
                ans.emplace_back(A[i]);
                ans.emplace_back(temp);
                break;
            }
        }
        return ans;
    }
};