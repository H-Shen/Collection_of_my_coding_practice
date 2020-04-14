#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 30;
char cstr[MAXN];

unordered_map<string, int> A;
int counter = 0;
int result = 0;

int main() {

    int n;
    string str;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", cstr);
        str = cstr;
        if (A.find(str) == A.end()) {
            A[str] = 1;
            ++counter;
            continue;
        }
        if (A[str] > counter - A[str]) {
            ++result;
        }
        ++A[str];
        ++counter;
    }
    printf("%d\n", result);

    return 0;
}