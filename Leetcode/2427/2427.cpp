class Solution {
public:
    int commonFactors(int a, int b) {
        unordered_set<int> unset;
        for (int i = 1; i <= a; ++i) {
            if (a % i == 0) unset.insert(i);
        }
        int cnt = 0;
        for (int i = 1; i <= b; ++i) {
            if (b % i == 0 && unset.count(i) > 0) ++cnt; 
        }
        return cnt;
    }
};