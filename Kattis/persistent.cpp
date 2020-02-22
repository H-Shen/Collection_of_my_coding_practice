// https://open.kattis.com/problems/persistent
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 1005;
char cstr[MAXN];

inline static
pair<string, string> Div(string &a, int &b) {

    string r, ans;
    int d = 0;

    if (a == "0")
        return make_pair(a, a);

    int len_a = a.size();
    for (int i = 0; i < len_a; i++) {
        r += (d * 10 + a[i] - '0') / b + '0';
        d = (d * 10 + (a[i] - '0')) % b;
    }

    int p = 0;
    int len_r = r.size();
    for (int i = 0; i < len_r; i++) {
        if (r[i] != '0') {
            p = i;
            break;
        }
    }
    return make_pair(r.substr(p), to_string(d));
}

int main() {

    while (true) {
        scanf("%s", cstr);
        string s(cstr);
        if (s == "-1") {
            break;
        }
        if (s.size() == 1) {
            printf("1%s\n", cstr);
        } else {
            vector<int> result;
            bool encounter_big_prime = true;
            while (true) {
                if (s == "1") {
                    break;
                }
                encounter_big_prime = true;
                for (int i = 9; i >= 2; --i) {
                    auto p = Div(s, i);
                    if (p.second == "0") {
                        result.emplace_back(i);
                        s = p.first;
                        encounter_big_prime = false;
                        break;
                    }
                }
                if (encounter_big_prime) {
                    break;
                }
            }
            if (encounter_big_prime) {
                printf("There is no such number.\n");
            } else {
                for (auto iter = result.crbegin(); iter != result.crend(); ++iter) {
                    printf("%d", *iter);
                }
                printf("\n");
            }
        }
    }

    return 0;
}
