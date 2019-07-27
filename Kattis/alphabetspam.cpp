// https://open.kattis.com/problems/alphabetspam
#include<bits/stdc++.h>

using namespace std;

int main() {
    string str;
    int w = 0, l = 0, u = 0, s = 0;
    cin >> str;
    int len = str.size();

    for (const auto &ch : str) {
        if (isupper(ch)) ++u;
        else if (islower(ch)) ++l;
        else if (ch == '_') ++w;
        else ++s;
    }
    printf("%.6lf\n", w * 1.0 / len);
    printf("%.6lf\n", l * 1.0 / len);
    printf("%.6lf\n", u * 1.0 / len);
    printf("%.6lf\n", s * 1.0 / len);
    return 0;
}
