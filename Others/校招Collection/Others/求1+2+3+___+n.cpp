// https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1

class Solution {
public:
    int Sum_Solution(int n) {
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        return accumulate(a.begin(), a.end(), 0);
    }
};