class Solution {
public:
    // process after the update
    void process(stack<int>& s) {
        if (s.size() <= 1) {
            return;
        }
        int b = s.top();
        s.pop();
        int a = s.top();
        s.pop();
        // a > 0, b > 0
        // a < 0, b < 0
        // a < 0, b > 0
        if (a * b > 0 || (a < 0 && b > 0)) {
            s.push(a);
            s.push(b);
            return;
        }
        // a > 0, b < 0
        else if (abs(a) == abs(b)) {
            return;
        }
        else if (abs(a) > abs(b)) {
            s.push(a);
            return;
        }
        else {
            s.push(b);
            process(s);
        }
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (const auto &i : asteroids) {
            s.push(i);
            process(s);
        }
        vector<int> ans(s.size());
        auto iter = ans.begin();
        while (!s.empty()) {
            *iter = s.top();
            ++iter;
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};