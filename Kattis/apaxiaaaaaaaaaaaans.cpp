// https://open.kattis.com/problems/apaxiaaans
#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1);

struct schoolNameAndTopTeam {
    string schoolName;
    string topTeam;
};

inline int sgn(double a) {
    if (a < -eps) return -1;
    if (a > eps) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s, result;
    char lastChar = '\0';
    cin >> s;
    for (const char &ch : s) {
        if (ch != lastChar) {
            lastChar = ch;
            result += ch;
        }
    }
    cout << result << endl;
    return 0;
}
