// https://open.kattis.com/problems/costumecontest
//
#include <bits/extc++.h>

using namespace std;
constexpr int MAXN = 25;
constexpr int MAX_RESPONSES = 1005;
char s[MAXN];

int main() {

    int n;
    unordered_map<string, int> A;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        ++A[s];
    }
    int minVal = MAX_RESPONSES;
    for (const auto &it : A) {
        minVal = min(minVal, it.second);
    }
    vector<string> result;
    for (const auto &it : A) {
        if (it.second == minVal) {
            result.emplace_back(it.first);
        }
    }
    sort(result.begin(), result.end());
    for (const auto &i : result) {
        printf("%s\n", i.c_str());
    }

    return 0;
}