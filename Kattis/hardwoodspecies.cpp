// https://open.kattis.com/problems/hardwoodspecies
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 30;
char str[MAXN];

int main() {

    string s;
    unordered_map<string, int> A;
    int total = 0;
    while (~scanf("%[^\n]", str)) {
        getchar();
        s = str;
        ++A[s];
        ++total;
    }
    unordered_map<string, double> B;
    for (const auto &i : A) {
        B[i.first] = i.second * 1.0 / total * 100.0;
    }
    vector<pair<string, double> > output(B.begin(), B.end());
    sort(output.begin(), output.end(), [](const pair<string, double> &lhs, const pair<string, double> &rhs) {
        return (lhs.first < rhs.first);
    });
    for (const auto &i : output) {
        printf("%s %.6lf\n", i.first.c_str(), i.second);
    }

    return 0;
}
