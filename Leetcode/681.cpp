class Solution {
public:
    int getValue(const string &time) {
        int h, m;
        sscanf(time.c_str(), "%d:%d", &h, &m);
        return h*60+m;
    }
    bool valid(const string &time) {
        if (time[0] > '2') return false;
        if (time[0] == '2' && time[1] > '4') return false;
        if (time[3] > '5') return false;
        return true;
    }
    string nextClosestTime(string time) {
        unordered_set<char> v;
        v.insert(time[0]);
        v.insert(time[1]);
        v.insert(time[3]);
        v.insert(time[4]);
        v.insert(':');
        int total = 24*60;
        int h, m;
        string s;
        bool haveAns;
        vector<string> vec;
        for (int i = 0; i < total; ++i) {
            h = i / 60;
            m = i % 60;
            if (h < 10) {
                s.push_back('0');
            }
            s += to_string(h);
            s.push_back(':');
            if (m < 10) {
                s.push_back('0');
            }
            s += to_string(m);
            // check
            haveAns = true;
            for (const auto &ch : s) {
                if (v.find(ch) == v.end()) {
                    haveAns = false;
                    break;
                }
            }
            if (haveAns && valid(s)) {
                vec.emplace_back(s);
            }
            s.clear();
        }
        int n = (int)vec.size();
        int index = lower_bound(vec.begin(),vec.end(),time,[&](const string &l, const string &r) {
            return getValue(l) < getValue(r);
        }) - vec.begin();
        if (index == n - 1) {
            return vec[0];
        }
        else {
            return vec[index+1];
        }
    }
};