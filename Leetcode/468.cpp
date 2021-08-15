class Solution {
public:
    bool isIPv4(const string &IP) {
        const static regex r("^((25[0-5]|(2[0-4]|1[0-9]|[1-9]|)[0-9])(\.(?!$)|$)){4}$");
        smatch sm;
        return regex_match(IP, sm, r);
    }

    bool isIPv6(const string &IP) {
        const static regex r(R"(^[0-9a-fA-F]{1,4}:[0-9a-fA-F]{1,4}:[0-9a-fA-F]{1,4}:[0-9a-fA-F]{1,4}:[0-9a-fA-F]{1,4}:[0-9a-fA-F]{1,4}:[0-9a-fA-F]{1,4}:[0-9a-fA-F]{1,4}$)");
        smatch sm;
        return regex_match(IP, sm, r);
    }
    string validIPAddress(string IP) {
        if (isIPv4(IP)) return "IPv4";
        else if (isIPv6(IP)) return "IPv6";
        return "Neither";
    }
};