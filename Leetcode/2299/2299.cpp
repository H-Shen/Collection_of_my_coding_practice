class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = (int)password.size();
        if (n < 8) return false;
        if (count_if(password.begin(),password.end(),[](const auto &ch){return isupper(ch);}) == 0) return false;
        if (count_if(password.begin(),password.end(),[](const auto &ch){return islower(ch);}) == 0) return false;
        if (count_if(password.begin(),password.end(),[](const auto &ch){return isdigit(ch);}) == 0) return false;
        string s = "!@#$%^&*()-+";
        unordered_set<char> unset(s.begin(),s.end());
        if (count_if(password.begin(),password.end(),[&](const auto &ch){return unset.count(ch) > 0;}) == 0) return false;
        for (int i = 0; i < n-1; ++i) {
            if (password[i] == password[i+1]) return false;
        }
        return true;
    }
};