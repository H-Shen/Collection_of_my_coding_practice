// https://www.nowcoder.com/practice/58b6a69b4bf943b49d2cd3c15770b9fd
// Compiled in C++14(g++5.4)
#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 20;
char s[MAXN];
char a[MAXN];
char b[MAXN];
char c[MAXN];

inline static
double f(char cstr[]) {
    string str(cstr);
    double t = stod(str);
    if (count(str.begin(), str.end(), '.') != 0) {
        auto iter = str.rbegin();
        int counter = 0;
        while (*iter != '.') {
            ++iter;
            ++counter;
        }
        if (counter > 2) {
            size_t index = str.find('.');
            if (str.at(index + 3) >= '5') {
                t = stod(str.substr(0, index + 3));
                t += 0.01;
            }
        }
    }
    return t;
}

int main() {
    scanf("%[^;];%[^,],%[^,],%s", s, a, b, c);
    printf("The each subject score of  No. %s is %.2lf, %.2lf, %.2lf.\n", s, f(a), f(b), f(c));
    return 0;
}