using ll = long long;

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int n = (int)queries.size();
        vector<ll> answer(n);
        string s;
        if (intLength == 1) {
            for (int i = 0; i < n; ++i) {
                if (queries[i] >= 10) {
                    answer[i] = -1;
                }
                else {
                    answer[i] = queries[i];
                }
            }
        }
        else if (intLength == 2) {
            vector<ll> temp;
            for (int i = 10; i <= 99; ++i) {
                s = to_string(i);
                if (s[0] == s[1]) temp.emplace_back(i);
            }
            for (int i = 0; i < n; ++i) {
                if (queries[i] - 1 < (int)temp.size()) {
                    answer[i] = temp[queries[i]-1];
                }
                else {
                    answer[i] = -1;
                }
            }
        }
        string s1, s2;
        if (intLength & 1) {
            ll firstHalf = (ll)pow(10, intLength >> 1);
            ll lengthOfPalindromes = firstHalf*9;
            for (int i = 0; i < n; ++i) {
                if (queries[i] > lengthOfPalindromes) {
                    answer[i] = -1;
                }
                else {
                    s1 = to_string(firstHalf + queries[i] - 1);
                    s2 = s1;
                    s2.pop_back();
                    reverse(s2.begin(),s2.end());
                    answer[i] = stoll(s1 + s2);
                }
            }
        }
        else {
            ll firstHalf = (ll)pow(10, (intLength >> 1) - 1);
            ll lengthOfPalindromes = firstHalf*9;
            for (int i = 0; i < n; ++i) {
                if (queries[i] > lengthOfPalindromes) {
                    answer[i] = -1;
                }
                else {
                    s1 = to_string(firstHalf + queries[i] - 1);
                    s2 = s1;
                    reverse(s2.begin(),s2.end());
                    answer[i] = stoll(s1 + s2);
                }
            }
        }
        return answer;
    }
};