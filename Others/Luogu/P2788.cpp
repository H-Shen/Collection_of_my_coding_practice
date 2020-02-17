#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 60005;
char s[MAXN];

int main() {

    scanf("%s", s);
    ll sum = 0;
    string temp;
    bool is_neg = false;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (i == 0 && !isdigit(s[i])) {
            is_neg = s[i] == '-';
            continue;
        }
        if (isdigit(s[i])) {
            temp.push_back(s[i]);
        } else {
            if (is_neg) {
                sum += -stoll(temp);
            } else {
                sum += stoll(temp);
            }
            temp = "";
            is_neg = s[i] != '+';
        }
    }
    if (!temp.empty()) {
        if (is_neg) {
            sum += -stoll(temp);
        } else {
            sum += stoll(temp);
        }
    }
    printf("%lld\n", sum);

    return 0;
}