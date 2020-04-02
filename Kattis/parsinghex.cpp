// https://open.kattis.com/problems/parsinghex
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 105;
char cstr[MAXN];

int main() {

    ll upperbound = stoll("0xffffffff", nullptr, 16);
    string tempStr = "0123456789abcdefABCDEF";
    unordered_set<char> legalCharset(tempStr.begin(), tempStr.end());
    bool haveAns;
    string number;
    while (~scanf("%[^\n]", cstr)) {
        getchar();
        tempStr = cstr;
        deque<char> s;
        for (const char &ch : tempStr) {
            s.emplace_back(ch);
        }
        haveAns = false;
        while (s.size() > 2) {
            if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
                number = s[0] + string() + s[1];
                s.pop_front();
                s.pop_front();
                while (true) {
                    if (s.empty()) {
                        haveAns = true;
                        break;
                    }
                    if (legalCharset.find(s[0]) == legalCharset.end()) {
                        haveAns = true;
                        break;
                    }
                    if (stoll(number + s[0], nullptr, 16) > upperbound) {
                        haveAns = true;
                        break;
                    }
                    number.push_back(s[0]);
                    s.pop_front();
                }
            } else {
                s.pop_front();
            }
            if (haveAns) {
                printf("%s %lld\n", number.c_str(), stoll(number, nullptr, 16));
                haveAns = false;
            }
        }
    }
    return 0;
}
