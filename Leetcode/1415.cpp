class Solution {
public:
    string getHappyString(int n, int k) {
        int counter = 2;
        vector<string> A = {"a", "b", "c"};
        while (counter <= n) {
            int length = (int) A.size();
            for (int i = 0; i < length; ++i) {
                if (A[i].back() != 'a') {
                    A.emplace_back(A[i] + 'a');
                }
                if (A[i].back() != 'b') {
                    A.emplace_back(A[i] + 'b');
                }
                if (A[i].back() != 'c') {
                    A.emplace_back(A[i] + 'c');
                }
            }
            ++counter;
        }
        vector<string> vec;
        copy_if(A.begin(), A.end(), back_inserter(vec), [&](const string &s) {
            return (int)s.size() == n;
        });
        if ((int)vec.size() < k) {
            return string();
        }
        nth_element(vec.begin(), vec.begin() + k - 1, vec.end());
        return vec[k-1];
    }
};