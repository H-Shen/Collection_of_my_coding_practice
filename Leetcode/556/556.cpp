class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if (next_permutation(s.begin(),s.end())) {
            try {
                return stoi(s);
            } catch (...) {
                return -1;
            }
        }
        return -1;
    }
};