class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        return (int)count_if(words.begin(),words.end(),[&](const string& s){
            return s.find(pref) == 0;
        });
    }
};