class Solution {
public:
    string removeVowels(string s) {
        string ans;
        copy_if(s.begin(), s.end(), back_inserter(ans), [](const auto &ch) {
            return ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u';
        });
        return ans;
    }
};