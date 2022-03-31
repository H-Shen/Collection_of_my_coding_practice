class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string,int> unmap;
        unmap["I"] = 1;
        unmap["V"] = 5;
        unmap["X"] = 10;
        unmap["L"] = 50;
        unmap["C"] = 100;
        unmap["D"] = 500;
        unmap["M"] = 1000;
        unmap["IV"] = 4;
        unmap["IX"] = 9;
        unmap["XL"] = 40;
        unmap["XC"] = 90;
        unmap["CD"] = 400;
        unmap["CM"] = 900;
        deque<char> dq(s.begin(),s.end());
        int result = 0;
        string str;
        // greedy
        while (!dq.empty()) {
            if (dq.size() == 1) {
                str.clear();
                str.push_back(dq.front());
                result += unmap[str];
                dq.pop_front();
            }
            else {
                str.clear();
                str.push_back(dq.front());
                dq.pop_front();
                str.push_back(dq.front());
                dq.pop_front();
                if (unmap.count(str) > 0) {
                    result += unmap[str];
                }
                else {
                    dq.push_front(str.back());
                    str.pop_back();
                    result += unmap[str];
                }
            }
        }
        
        return result;
    }
};