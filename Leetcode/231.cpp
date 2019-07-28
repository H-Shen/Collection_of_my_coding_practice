class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        vector <long long> A = {1, 2};
        constexpr size_t enoughLength = 40;
        while (A.size() < enoughLength) {
            A.emplace_back(2 * A.back());
        }
        return (binary_search(A.begin(), A.end(), static_cast<long long>(n)));
    }
};