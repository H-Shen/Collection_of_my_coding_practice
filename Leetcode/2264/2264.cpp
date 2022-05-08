class Solution {
public:
    string largestGoodInteger(string num) {
        int n = (int)num.size();
        string s;
        string ans;
        int maxVal = -1;
        for (int i = 0; i < n-2; ++i) {
            if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
                s.clear();
                s.push_back(num[i]);
                s.push_back(num[i+1]);
                s.push_back(num[i+2]);
                int temp = stoi(s);
                if (temp > maxVal) {
                    maxVal = temp;
                    ans = s;
                }
            }
        }
        return ans;
    }
};