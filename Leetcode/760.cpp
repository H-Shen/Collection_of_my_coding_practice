class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> unmap;
        int n = (int)B.size();
        for (int i = 0; i < n; ++i) {
            unmap[B[i]] = i;
        }
        int m = (int)A.size();
        vector<int> result(m);
        for (int i = 0; i < m; ++i) {
            result[i] = unmap[A[i]];
        }
        return result;
    }
};