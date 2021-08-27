class Solution {
public:
    int arrangeCoins(int m) {
        auto n = static_cast<long long>(sqrt(static_cast<double>(m)));
        long long m_ll(m);
        while ( (1 + n) * n / 2 < m_ll ) {
            ++n;
        }
        while ( (1 + n) * n / 2 > m_ll ) {
            --n;
        }
        return n;
    }
};