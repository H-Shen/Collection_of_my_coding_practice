class Solution {
public:
    int ans;
    void dfs(int num, int k, int size) {
        // prune
        int temp = num % 10;
        if (k == 0 && (temp != 0)) {
            return;
        }
        if (k == 5 && (temp != 5 && temp != 0)) {
            return;
        }
        if (k % 2 == 0 && (temp != 2 && temp != 4 && temp != 6 && temp != 8 && temp != 0)) {
            return;
        }
        // base cases
        if (ans != numeric_limits<int>::max()) {
            return;
        }
        if (num == 0) {
            ans = size;
            return;
        }
        int unit = (k == 0) ? 10 : k;
        if (num < unit) {
            return;
        }
        int upper = (num - unit) / 10;
        
        for (int i = upper; i >= 0; --i) {
            dfs(num - (unit + i * 10), k, size + 1);
        }
    }
    int minimumNumbers(int num, int k) {
        ans = numeric_limits<int>::max();
        dfs(num, k, 0);
        return (ans == numeric_limits<int>::max()) ? -1 : ans;
    }
};