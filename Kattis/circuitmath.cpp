// https://open.kattis.com/problems/circuitmath
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 3;
char cstr[MAXN];

int main() {

    int n;
    scanf("%d", &n);
    vector<char> temp_vec(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", cstr);
        temp_vec.at(i) = cstr[0];
    }
    unordered_map<char, char> stats;
    char ch = 'A';
    for (int i = 0; i < n; ++i) {
        stats[ch] = temp_vec.at(i);
        ++ch;
    }
    vector<char> expression;
    while (~scanf("%s", cstr)) {
        expression.emplace_back(cstr[0]);
    }
    for (auto &i : expression) {
        if (stats.find(i) != stats.end()) {
            i = stats[i];
        }
    }
    stack<char> S;
    char ch0;
    char ch1;
    char result;
    for (const auto &i : expression) {
        if (i == '*') {
            ch0 = S.top();
            S.pop();
            ch1 = S.top();
            S.pop();
            if (ch0 == 'T' && ch1 == 'T') {
                result = 'T';
            } else {
                result = 'F';
            }
            S.push(result);
        } else if (i == '+') {
            ch0 = S.top();
            S.pop();
            ch1 = S.top();
            S.pop();
            if (ch0 == 'T' || ch1 == 'T') {
                result = 'T';
            } else {
                result = 'F';
            }
            S.push(result);
        } else if (i == '-') {
            ch0 = S.top();
            S.pop();
            if (ch0 == 'T') {
                result = 'F';
            } else {
                result = 'T';
            }
            S.push(result);
        } else {
            S.push(i);
        }
    }
    printf("%c\n", S.top());
    return 0;
}
