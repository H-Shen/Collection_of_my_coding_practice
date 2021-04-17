class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        for (const auto &i : A) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
        int m = (int)queries.size();
        vector<int> result(m);
        int oldValue, j;
        for (int i = 0; i < m; ++i) {
            j = queries[i][1];
            oldValue = A[j];
            A[j] += queries[i][0];
            if (oldValue % 2 == 0 && A[j] % 2 == 0) {
                sum = sum - oldValue + A[j];
            }
            else if (oldValue % 2 == 0 && A[j] % 2 != 0) {
                sum -= oldValue;
            }
            else if (oldValue % 2 != 0 && A[j] % 2 == 0) {
                sum += A[j];
            }
            result[i] = sum;
        }
        return result;
    }
};