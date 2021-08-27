class Solution {
public:
    int hammingDistance(int x, int y) {
        string x_str = bitset<64>(static_cast<unsigned long long int>(x)).to_string();
        string y_str = bitset<64>(static_cast<unsigned long long int>(y)).to_string();
        int cnt = 0;
        for (size_t i = 0; i != x_str.size(); ++i) {
            if (x_str[i] != y_str[i]) {
                ++cnt;
            }
        }
        return cnt;
    }
};