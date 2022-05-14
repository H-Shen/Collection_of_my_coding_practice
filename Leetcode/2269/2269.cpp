class Solution {
public:
    inline
    bool check(int num, deque<char>& dq) {
        int temp = stoi(string(dq.begin(),dq.end()));
        if (temp == 0 || num % temp != 0) {
            return false;
        }
        return true;
    }
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = (int)s.size();
        deque<char> dq;
        for (int i = 0; i < k; ++i) {
            dq.push_back(s[i]);
        }
        int counter = 0;
        if (check(num, dq)) ++counter;
        for (int i = k; i < n; ++i) {
            dq.pop_front();
            dq.push_back(s[i]);
            if (check(num, dq)) ++counter;
        }
        return counter;
    }
};