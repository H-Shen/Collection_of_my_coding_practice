// https://open.kattis.com/problems/rotatecut
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 2005;
char cstr[MAXN];

string solve(const string& s, int k) {
    int n = static_cast<int>(s.size());
    if (n <= 3) {
        return s;
    }
    int cut;
    deque<char> temp(s.begin(), s.end());
    bool change = true;
    for (int i = 0; i < k; ++i) {
        if (temp.size() <= 3) {
            break;
        }
        cut = static_cast<int>(temp.size()) / 4;
        if (change) {
            for (int j = 0; j < cut; ++j) {
                temp.pop_front();
            }
            change = false;
        } else {
            for (int j = 0; j < cut; ++j) {
                temp.pop_back();
            }
            change = true;
        }
    }
    return string(temp.begin(), temp.end());
}

int main() {

    int n;
    int k;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %s", &k, cstr);
        printf("%s\n", solve(cstr, k).c_str());
    }


    return 0;
}
