class Solution {
public:
    string reverseVowels(string s) {

        vector<char> vowels;
        string vowelStr = "aeiouAEIOU";
        unordered_set<char> vowelSet(vowelStr.begin(), vowelStr.end());
        for (size_t i = 0; i != s.size(); ++i) {
            if (vowelSet.find(s.at(i)) != vowelSet.end())  {
                vowels.emplace_back(s.at(i));
            }
        }

        auto it = vowels.crbegin();
        for (auto &&ch : s) {
            if (vowelSet.find(ch) != vowelSet.end()) {
                ch = *it;
                ++it;
            }
        }

        return s;
    }
};