class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t pos;
        while (true) {
            pos = s.find(part);
            if (pos == string::npos) break;
            s.erase(pos, part.size());
        }
        return s;
    }
};