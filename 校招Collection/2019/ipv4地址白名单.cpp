// https://www.nowcoder.com/practice/f0f1015579904ebc92974f7c92764797

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    unordered_set<string> ip_log;
    string s, ip_addr;
    while (cin >> s) {
        if (s == "end") {
            break;
        }
        ip_addr = s.substr(2);
        switch (s[0]) {
            case 'i':
                ip_log.insert(ip_addr);
                cout << "ok" << endl;
                break;
            case 's':
                if (ip_log.find(ip_addr) != ip_log.end()) {
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
                break;
            case 'd':
                ip_log.erase(ip_addr);
                cout << "ok" << endl;
                break;
            default:
                break;
        }
    }

    return 0;
}