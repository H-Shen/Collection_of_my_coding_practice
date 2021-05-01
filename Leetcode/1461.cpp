class Solution {
public:
    vector<bool> vis;
    vector<int> powerOfTwo = {1,
                             2,
                             4,
                             8,
                             16,
                             32,
                             64,
                             128,
                             256,
                             512,
                             1024,
                             2048,
                             4096,
                             8192,
                             16384,
                             32768,
                             65536,
                             131072,
                             262144,
                             524288,
                             1048576,
                             2097152};
    bool hasAllCodes(string s, int k) {
        auto f = [&](int i, int j) {
            int sum = 0;
            for (int index = 0; j >= i; --j, ++index) {
                if (s[j] == '1') {
                    sum += powerOfTwo.at(index);
                }
            }
            return sum;
        };
        vis.resize(powerOfTwo.at(k), false);
        int i = 0;
        int n = (int)s.size();
        for (; i + k <= n; ++i) {
            vis.at(f(i, i + k - 1)) = true;
        }
        for (const auto &i : vis) {
            if (!i) return false;
        }
        return true;
    }
};