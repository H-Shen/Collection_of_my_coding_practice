class Solution {
public:
    int findLUSlength(string a, string b) {
        // Case 1: n == m, a == b
        // Case 2: n == m, a != b
        // Case 3: n != m, a != b
        int n = (int)a.size();
        int m = (int)b.size();
        return (n == m && a == b) ? -1 : max(n,m);
    }
};