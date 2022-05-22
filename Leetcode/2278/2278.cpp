class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = (int)count(s.begin(),s.end(),letter);
        return n*100 / (int)s.size();
    }
};