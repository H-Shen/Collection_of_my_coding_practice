struct Cmp {
    bool operator()(const pair<char,int> &l, const pair<char,int> &r) const {
        return l.second < r.second;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        if (s.size() <= 1) {
            return s;
        }
        unordered_map<char,int> unmap;
        for (const auto &i : s) {
            ++unmap[i];
        }
        priority_queue<pair<char,int>, vector<pair<char,int> >, Cmp> pq;
        for (const auto &[k,v] : unmap) {
            pq.push({k,v});
        }
        string str;
        while (pq.size() >= 2) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            --p1.second;
            --p2.second;
            str.push_back(p1.first);
            str.push_back(p2.first);
            if (p1.second > 0 && p2.second > 0) {
                pq.push(p1);
                pq.push(p2);
            }
            else if (p1.second > 0 && p2.second == 0) {
                pq.push(p1);
            }
            else if (p1.second == 0 && p2.second > 0) {
                pq.push(p2);
            }
        }
        if (!pq.empty()) {
            auto p1 = pq.top();
            pq.pop();
            if (p1.second > 1) {
                return string();
            }
            str.push_back(p1.first);
        }

        int length = (int)str.size();
        for (int i = 0; i < length - 1; ++i) {
            if (str[i] == str[i+1]) {
                return string();
            }
        }
        return str;
    }
};