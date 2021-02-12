class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        vector<int> k;
        while (K > 0) {
            k.emplace_back(K % 10);
            K /= 10;
        }
        size_t maxSize = max(A.size(), k.size());
        while (A.size() != maxSize) {
            A.emplace_back(0);
        }
        while (k.size() != maxSize) {
            k.emplace_back(0);
        }
        vector<int> sum(maxSize + 1);
        for (size_t i = 0; i != maxSize; ++i) {
            sum.at(i) = sum.at(i) + A.at(i) + k.at(i);
            if (sum.at(i) >= 10) {
                ++sum.at(i + 1);
                sum.at(i) -= 10;
            }
        }
        while (sum.size() > 1 && sum.back() == 0) {
            sum.pop_back();
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};