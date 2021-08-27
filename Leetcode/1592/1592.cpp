const regex r("[a-z]+");

class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> v;
        for (sregex_iterator it(text.begin(), text.end(), r), end; it != end; ++it) {
            v.emplace_back(it->str());
        }
        int spaces = count(text.begin(), text.end(), ' ');
        int words = (int)v.size();
        if (words == 1) {
            return v.front() + string(spaces, ' ');
        }
        string result;
        int temp = spaces / (words - 1);
        string str(temp, ' ');
        for (int i = 0; i < words; ++i) {
            if (i > 0) {
                result += str + v.at(i);
            } else {
                result += v.at(i);
            }
        }
        if (spaces % (words - 1) != 0) {
            result += string(spaces % (words - 1), ' ');   
        }
        return result;
    }
};