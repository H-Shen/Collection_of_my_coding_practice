class Solution {
public:
    bool judgeSquareSum(int c) {
        long long c_l(c);
        for (long long i = 0; i * i <= c_l; ++i) {
            double temp = sqrt(static_cast<double>(c_l - i * i));
            auto temp_l = static_cast<long long>(temp);
            if (temp_l * temp_l + i * i == c_l) {
                return true;
            }
        }
        return false;
    }
};