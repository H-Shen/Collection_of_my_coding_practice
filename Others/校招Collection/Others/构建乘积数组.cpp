// https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46

class Solution {
public:
    vector<int> multiply(const vector<int> &A) {

        vector<int> result;
        int i, s, temp;
        int n = static_cast<int>(A.size());

        if (n == 0)
            return result;

        vector<int> left, right;

        s = A[0];
        left.push_back(1);
        left.push_back(1);
        left.push_back(s);
        for (i = 1; i < n; i++) {
            s *= A[i];
            left.push_back(s);
        }

        s = A[n - 1];
        right.push_back(s);
        for (i = n - 2; i >= 0; i--) {
            s *= A[i];
            right.push_back(s);
        }
        reverse(right.begin(), right.end());
        right.push_back(1);
        right.push_back(1);

        for (i = 1; i <= n; i++) {
            temp = left[i] * right[i];
            result.push_back(temp);
        }
        return result;
    }
};