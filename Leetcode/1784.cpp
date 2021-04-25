class Solution {
public:
    bool checkOnesSegment(string s) {
        static const regex r("10+1");
        smatch sm;
        return !regex_search(s, sm, r);
    }
};