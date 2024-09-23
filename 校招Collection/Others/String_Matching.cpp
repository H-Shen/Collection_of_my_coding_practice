// https://www.nowcoder.com/practice/00438b0bc9384ceeb65613346b42e88a

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;
char T[MAXN], P[MAXN];
string Tstr, Pstr;

int main() {

    while (scanf("%s %s", T, P) != EOF) {
        Tstr = T;
        Pstr = P;
        int counter = 0;
        int len = Tstr.length();
        int sublen = Pstr.length();
        int interval = len - sublen;

        for (int i = 0; i <= interval; i++) {
            string temp(Tstr, i, sublen);
            if (temp == Pstr)
                counter++;
        }
        printf("%d\n", counter);
    }
    return 0;
}