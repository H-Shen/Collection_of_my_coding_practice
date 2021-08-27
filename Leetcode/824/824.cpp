class Solution {
public:
    string toGoatLatin(string S) {

        string vowelStr("aeiouAEIOU");
        unordered_set<char> vowel(vowelStr.begin(), vowelStr.end());

        istringstream iss(S);
        string tmp;
        vector<string> A;
        while (iss) {
            iss >> tmp;
            A.push_back(tmp);
        }
        A.pop_back();

        char tmpChar;
        for (auto &&i : A) {
            if (vowel.find(i.front()) != vowel.end()) {
                i += "ma";
            } else {
                tmpChar = i.front();
                i = i.substr(1);
                i = i + tmpChar + "ma";
            }
        }

        string suffix = "a";
        for (auto &&i : A) {
            i += suffix;
            suffix += "a";
        }

        string res;
        for (size_t i = 0; i < A.size() - 1; ++i) {
            res += A.at(i) + ' ';
        }
        res += A.back();
        return res;
    }
};