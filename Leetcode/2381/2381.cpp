class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = (int)s.size();
        vector<int> diff(n+1);
        int l, r, temp;
        for (auto&i : shifts) {
            l = i[0];
            r = i[1];
            if (i[2] == 1) {
                temp = 1;
            }
            else {
                temp = -1;
            }
            diff[l] += temp;
            diff[r+1] -= temp;
        }
        for (int i = 1; i <= n; ++i) {
            diff[i] += diff[i-1];
        }
        for (int i = 0; i < n; ++i) {
            if (diff[i] >= 0) {
                diff[i] %= 26;
                for (int j = 0; j < diff[i]; ++j) {
                    if (s[i] == 'z') {
                        s[i] = 'a';
                    }
                    else {
                        ++s[i];
                    }
                }
            }
            else {
                diff[i] %= -26;
                for (int j = 0; j < -diff[i]; ++j) {
                    if (s[i] == 'a') {
                        s[i] = 'z';
                    }
                    else {
                        --s[i];
                    }
                }
            }
        }
        return s;
    }
};