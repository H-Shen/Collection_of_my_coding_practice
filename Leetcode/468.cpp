class Solution {
public:
    bool isIPv4(const string &IP) {
        const static regex r(R"(^\d+\.\d+\.\d+\.\d+$)");
        smatch sm;
        if (regex_match(IP, sm, r)) {
            vector<string> vec;
            string s;
            for (const auto &ch : IP) {
                if (isdigit(ch)) {
                    s.push_back(ch);
                } else {
                    vec.emplace_back(s);
                    s.clear();
                }
            }
            vec.emplace_back(s);
            unordered_set<string> validRange;
            for (int i = 0; i <= 255; ++i) {
                validRange.insert(to_string(i));
            }
            for (const auto &i : vec) {
                if (validRange.find(i) == validRange.end()) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool isIPv6(const string &IP) {
        const static regex r(R"(^[0-9a-fA-F]{1,4}:[0-9a-fA-F]{1,4}:[0-9a-fA-F]{1,4}:[0-9a-fA-F]{1,4}:[0-9a-fA-F]{1,4}:[0-9a-fA-F]{1,4}:[0-9a-fA-F]{1,4}:[0-9a-fA-F]{1,4}$)");
        smatch sm;
        return regex_match(IP, sm, r);
    }
    string validIPAddress(string IP) {
        if (isIPv4(IP)) return "IPv4";
        if (isIPv6(IP)) return "IPv6";
        return "Neither";
    }
};