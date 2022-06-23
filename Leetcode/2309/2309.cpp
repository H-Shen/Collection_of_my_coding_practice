class Solution {
public:
    string greatestLetter(string s) {
        vector<char> vec;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            char ch2 = toupper(ch);
            if (count(s.begin(),s.end(),ch) > 0 && count(s.begin(),s.end(),ch2) > 0) {
                vec.emplace_back(ch2);
            }
        }
        return vec.empty() ? string() : *max_element(vec.begin(),vec.end()) + string();
    }
};