class Solution {
public:
    string repeat(const string &s, int n) {
        string result;
        for (int i = 0; i < n; ++i) {
            result += s;
        }
        return result;
    }
    string gcdOfStrings(string str1, string str2) {
        int n = (int)str1.size();
        int m = (int)str2.size();
        int Gcd = gcd(n, m);
        string substr1, substr2;
        for (int i = Gcd; i >= 1; --i) {
            if (n % i == 0 && m % i == 0) {
                substr1 = str1.substr(0, i);
                substr2 = str2.substr(0, i);
                if (substr1 == substr2 && repeat(substr1, n / i) == str1 && repeat(substr2, m / i) == str2) {
                    return substr1;
                }
            }
        }
        return string();
    }
};