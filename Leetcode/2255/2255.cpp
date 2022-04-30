class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_set<string> prefixes;
        string str;
        for (auto& ch : s) {
            str.push_back(ch);
            prefixes.insert(str);
        }
        return (int)count_if(words.begin(),words.end(),[&](const string& word){
            return prefixes.count(word) > 0;
        });
    }
};