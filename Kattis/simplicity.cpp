// https://open.kattis.com/problems/simplicity
//
#include <bits/extc++.h>

using namespace std;
constexpr int MAXN = 105;
char s[MAXN];
vector<pair<char, int> > L;
unordered_map<char, int> A;

int main() {

    // input
    scanf("%s", s);
    for (int i = 0; s[i] != '\0'; ++i) {
        ++A[s[i]];
    }
    for (const auto &i : A) {
        L.emplace_back(make_pair(i.first, i.second));
    }
    sort(L.begin(), L.end(), [](const pair<char, int> &lhs, const pair<char, int> &rhs) {
       return (lhs.second > rhs.second);
    });
    int counter = 0;
    while (L.size() > 2) {
        while (L.back().second != 0) {
            --L.back().second;
            ++counter;
        }
        L.pop_back();
    }
    printf("%d\n", counter);

    return 0;
}
