// https://open.kattis.com/problems/conundrum
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
    string s;
    cin >> s;
    for (auto &&i : s) {
        if (i >= 'A' && i <= 'Z') {
            i = tolower(i);
        }
    }
    string nameRepetition;
    int repetitionTime = s.size() / 3;
    for (int i = 0; i < repetitionTime; ++i) {
        nameRepetition += "per";
    }
    int cnt = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (nameRepetition[i] != s[i]) {
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}
