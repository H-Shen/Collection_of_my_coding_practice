// https://open.kattis.com/problems/beekeeper
//
#include <bits/extc++.h>

using namespace std;
constexpr int MAXN = 100;
constexpr int VOWELS = 6;
char s[MAXN];

inline static
int countPairOfDoubleVowels(char *str) {
    int result = 0;
    char *p = nullptr;

    array<string, VOWELS> vowels = {"aa", "ee", "oo", "uu", "ii", "yy"};
    for (size_t i = 0; i != vowels.size(); ++i) {
        p = str;
        while ((p = strstr(p, vowels.at(i).c_str()))) {
            p += 2;
            ++result;
        }
    }

    return result;
}

int main() {

    int n;
    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        vector<pair<string, int> > A(n);
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            A[i].first = s;
            A[i].second = countPairOfDoubleVowels(s);
        }
        printf("%s\n", (max_element(A.begin(), A.end(), [](const pair<string, int> &lhs, const pair<string, int> &rhs) {
            return (lhs.second < rhs.second);
        }))->first.c_str());
    }

    return 0;
}
