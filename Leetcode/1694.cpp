class Solution {
public:
    string reformatNumber(string number) {
        deque<char> dq;
        for (const auto &i : number) {
            if (isdigit(i)) {
                dq.push_back(i);
            }
        }
        int n = (int)dq.size();
        if (n <= 3) return string(dq.begin(), dq.end());
        else if (n == 4) {
            return dq[0] + string("") + dq[1] + string("-") + dq[2] + string("") + dq[3];
        }
        else {
            string result;
            while (dq.size() >= 5) {
                result.push_back(dq.front());
                dq.pop_front();
                result.push_back(dq.front());
                dq.pop_front();
                result.push_back(dq.front());
                dq.pop_front();
                result.push_back('-'); 
            }
            result += reformatNumber(string(dq.begin(), dq.end()));
            return result;
        }
    }
};