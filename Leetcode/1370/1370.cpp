class Solution {
public:
    string sortString(string s) {
        list<char> l(s.begin(), s.end());
        string result;
        while (true) {
            // 1
            if (l.empty()) break;
            auto it0 = min_element(l.begin(), l.end());
            result.push_back(*it0);
            l.erase(it0);
            // 2
            while (true) {                
                auto it1 = find_if(l.begin(), l.end(), [&](const char &x){
                    return x > result.back();
                });
                if (it1 == l.end()) {
                    break;
                }
                char ch = *it1;
                auto it2 = it1;
                while (it1 != l.end()) {
                    if (*it1 > result.back() && *it1 < ch) {
                        ch = *it1;
                        it2 = it1;
                    }
                    ++it1;
                }
                result.push_back(*it2);
                l.erase(it2);
            }
            // 3
            if (l.empty()) break;
            it0 = max_element(l.begin(), l.end());
            result.push_back(*it0);
            l.erase(it0);
            // 4
            while (true) {
                auto it1 = find_if(l.begin(), l.end(), [&](const char &x){
                    return x < result.back();
                });
                if (it1 == l.end()) {
                    break;
                }
                char ch = *it1;
                auto it2 = it1;
                while (it1 != l.end()) {
                    if (*it1 < result.back() && *it1 > ch) {
                        ch = *it1;
                        it2 = it1;
                    }
                    ++it1;
                }
                result.push_back(*it2);
                l.erase(it2);
            }
        }
        return result;
    }
};