class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        return (int)count_if(patterns.begin(),patterns.end(),[&](const auto &s) {
            return word.find(s) != string::npos;
        });
    }
};