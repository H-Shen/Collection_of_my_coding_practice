class Solution {
public:
    string encode(int num) {
        // https://oeis.org/A007931
        string s;
        ++num;
        while (num > 0) {
            s.push_back('0' + num % 2);
            num /= 2;
        }
        reverse(s.begin(), s.end());
        s = s.substr(1);
        return s;
    }
};