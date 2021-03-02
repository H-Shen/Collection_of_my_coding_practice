class Solution {
public:
    // http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSet64
    int f(int v) {
        int c;
        c =  ((v & 0xfff) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
        c += (((v & 0xfff000) >> 12) * 0x1001001001001ULL & 0x84210842108421ULL) % 
             0x1f;
        c += ((v >> 24) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
        return c;
    }
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        for (int i = 0; i <= num; ++i) {
            result.at(i) = f(i);
        }
        return result;
    }
};