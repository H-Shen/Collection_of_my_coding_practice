// https://open.kattis.com/problems/drmmessages
#include <bits/extc++.h>

using namespace std;

inline
char rotation(char res, int step) {
    step %= 26;
    for (int i = 0; i < step; ++i) {
        if (res == 'Z') {
            res = 'A';
        } else {
            res += 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    string s1 = s.substr(0, s.size() / 2);
    string s2 = s.substr(s.size() / 2);

    int rotationVal1 = 0;
    for (const auto &ch : s1) {
        rotationVal1 = rotationVal1 + (int) (ch - 65);
    }
    for (auto &&ch : s1) {
        ch = rotation(ch, rotationVal1);
    }

    int rotationVal2 = 0;
    for (const auto &ch : s2) {
        rotationVal2 = rotationVal2 + (int) (ch - 65);
    }
    for (auto &&ch : s2) {
        ch = rotation(ch, rotationVal2);
    }

    for (size_t i = 0; i < s1.size(); ++i) {
        s1[i] = rotation(s1[i], (int) (s2[i] - 'A'));
    }
    cout << s1 << endl;
    return 0;
}
