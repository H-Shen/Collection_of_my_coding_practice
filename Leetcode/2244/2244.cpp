class Solution {
public:
    // 2x+3y=n
    inline
    int solve(int n) {
        if (n == 1) return -1;
        int temp = n / 3 + 1;
        while (true) {
            if (temp * 3 <= n && (n - temp * 3) % 2 == 0) {
                return temp + (n - temp*3)/2; 
            }
            --temp;
            if (temp < 0) {
                if (n % 2 == 0) {
                    return n / 2;
                }
                else {
                    return -1;
                }
            }
        }
        return -1;
    }
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> freq;
        for (auto&i : tasks) {
            ++freq[i];
        }
        int counter = 0;
        int temp;
        for (auto& [k,v] : freq) {
            temp = solve(v);
            if (temp == -1) {
                return -1;
            }
            counter += temp;
        }
        return counter;
    }
};