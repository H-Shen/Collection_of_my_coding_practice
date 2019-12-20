// https://www.nowcoder.com/practice/58766632a6cc45c0a1158fea2db91728

#include <iostream>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    string s, s_clean;
    int len_s, len_s_clean, i;

    while (getline(cin, s)) {

        s_clean = "";
        len_s = s.size();
        len_s_clean = 0;

        for (i = 0; i < len_s; i++) {
            if (s[i] == ' ') {
                continue;
            }
            s_clean = s_clean + s[i];
            len_s_clean++;
        }
        if (len_s_clean <= 6)
            cout << s_clean;
        else if (len_s_clean <= 14) {
            cout << s_clean.substr(0, 6) << ' ' << s_clean.substr(6);
        } else {
            cout << s_clean.substr(0, 6) << ' ' << s_clean.substr(6, 8) << ' ' << s_clean.substr(14);
        }
        cout << endl;
    }

    return 0;
}