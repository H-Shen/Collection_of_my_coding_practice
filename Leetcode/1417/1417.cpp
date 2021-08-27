class Solution {
public:
    string reformat(string s) {
        int digits = count_if(s.begin(), s.end(), [](const char ch) { return isdigit(ch);});
        int alphas = count_if(s.begin(), s.end(), [](const char ch) { return isalpha(ch);});
        string result;
        if (abs(digits - alphas) > 1) {
            return result;
        }
        int n = (int)s.size();
        deque<char> dq1, dq2;
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                dq1.push_back(s[i]);
            } else {
                dq2.push_back(s[i]);
            }
        }
        if (digits == alphas) {
            while (!dq1.empty()) {
                result.push_back(dq1.front());
                dq1.pop_front();
                result.push_back(dq2.front());
                dq2.pop_front();
            }
        }
        else if (digits > alphas) {
            while (true) {
                result.push_back(dq1.front());
                dq1.pop_front();
                if (dq1.empty()) {
                    break;
                }
                result.push_back(dq2.front());
                dq2.pop_front();
            }
        }
        else {
            while (true) {
                result.push_back(dq2.front());
                dq2.pop_front();
                if (dq2.empty()) {
                    break;
                }
                result.push_back(dq1.front());
                dq1.pop_front();
            }
        }
        return result;
    }
};