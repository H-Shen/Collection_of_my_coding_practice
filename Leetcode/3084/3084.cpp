class Solution {
public:
    long long countSubstrings(string s, char c) {
        using ll = long long;
        ll cnt = (ll)count(s.begin(),s.end(),c);
        return ((cnt+1)*cnt)>>1;
    }
};