using ll = long long;

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = (int)word.size();
        vector<int> ans(n);
        string str;
        ll m_ll = m;
        ll temp;
        for (int i = 0; i < n; ++i) {
            str.push_back(word[i]);
            temp = stoll(str);
            if (temp % m_ll == 0) {
                ans[i] = 1;
                str.clear();
            }
            else {
                str = to_string(temp % m_ll);
            }
        }
        return ans;
    }
};