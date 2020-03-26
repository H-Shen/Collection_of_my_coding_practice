// https://open.kattis.com/problems/fiftyshades
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 35;
char s[MAXN];

int main() {

    int n;
    string str;
    int counter = 0;
    scanf("%d", &n);
    bool has_pink = false;
    while (n--) {
        scanf("%s", s);
        str = s;
        for (auto &i : str) {
            i = tolower(i);
        }
        if (str.find("rose") != string::npos) {
            ++counter;
        } else if (str.find("pink") != string::npos) {
            ++counter;
            has_pink = true;
        }
    }
    if (!has_pink) {
        printf("I must watch Star Wars with my daughter\n");
    } else {
        printf("%d\n", counter);
    }

    return 0;
}
