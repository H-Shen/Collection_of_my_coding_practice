class Solution {
public:
    int f(const string& s) {
        int h = stoi(s.substr(0, 2));
        int m = stoi(s.substr(3));
        return h*60+m;
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int l1 = f(event1[0]);
        int r1 = f(event1[1]);
        int l2 = f(event2[0]);
        int r2 = f(event2[1]);
        for (int i = l1; i <= r1; ++i) {
            if (l2 <= i && i <= r2) return true;
        }
        return false;
    }
};