class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> freq;
        int n = (int)A.size();
        vector<int> C(n);
        for (int i = 0; i < n; ++i) {
            ++freq[A[i]];
            ++freq[B[i]];
            for (const auto &[k,v] : freq) {
                if (v > 1) {
                    ++C[i];
                }
            }
        }
        return C;
    }
};
