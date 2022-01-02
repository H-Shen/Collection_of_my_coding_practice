class Solution {
public:
    bool hasOne(string& s) {
        for (auto&ch : s) if (ch == '1') return true;
        return false;
    }
    int numberOfBeams(vector<string>& bank) {
        int n = (int)bank.size();
        vector<int> temp(n);
        int length = 0;
        int counter;
        for (int i = 0; i < n; ++i) {
            counter = (int)count(bank[i].begin(),bank[i].end(),'1');
            if (counter > 0) temp[length++] = counter;
        }
        if (length <= 1) return 0;
        int ans = 0;
        for (int i = 1; i < length; ++i) {
            ans += temp[i]*temp[i-1];
        }
        return ans;
    }
};