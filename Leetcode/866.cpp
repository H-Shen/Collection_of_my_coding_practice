class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        for (int i = 2; i*i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int primePalindrome(int n) {
        // pre
        vector<int> palin;
        string s, s1, s2;
        // Case 1:
        for (int i = 2; i <= 9; ++i) {
            palin.emplace_back(i);
        }
        // Case 2:
        for (int i = 1; i <= 9999; ++i) {
            s1 = to_string(i);
            s2 = s1;
            reverse(s1.begin(),s1.end());
            s = s1 + s2;
            palin.emplace_back(stoi(s));
        }
        // Case 3:
        for (int i = 1; i <= 1000; ++i) {
            for (int j = 0; j <= 9; ++j) {
                s1 = to_string(i);
                s2 = s1;
                reverse(s2.begin(),s2.end());
                s = s1 + (char)(j + '0') + s2;
                palin.emplace_back(stoi(s));
            }
        }
        vector<int> v;
        v.emplace_back(2);
        v.emplace_back(3);
        v.emplace_back(5);
        v.emplace_back(7);
        for (const auto &i : palin) {
            if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
                continue;
            }
            v.emplace_back(i);
        }
        sort(v.begin(),v.end());
        size_t pos = lower_bound(v.begin(),v.end(),n) - v.begin();
        for (size_t i = pos; i != v.size(); ++i) {
            if (isPrime(v[i])) {
                return v[i];
            }
        }
        return -1;
    }
};