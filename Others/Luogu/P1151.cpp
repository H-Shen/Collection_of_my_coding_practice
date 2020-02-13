#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int k;
    scanf("%d", &k);
    string s;
    int sub1, sub2, sub3;
    bool have_ans = false;
    for (int i = 10000; i <= 30000; ++i) {
        s = to_string(i);
        sub1 = stoi(s.substr(0, 3));
        sub2 = stoi(s.substr(1, 3));
        sub3 = stoi(s.substr(2, 3));
        if (sub1 % k == 0 && sub2 % k == 0 && sub3 % k == 0) {
            have_ans = true;
            printf("%d\n", i);
        }
    }
    if (!have_ans) {
        printf("No\n");
    }

    return 0;
}