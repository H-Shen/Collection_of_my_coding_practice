// https://open.kattis.com/problems/competitivearcadebasketball
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

constexpr int MAX_STRING_LENGTH = 25;
constexpr int MAXN = 100005;

char name[MAX_STRING_LENGTH];
unordered_map<string, ll> A;
string nameOrder[MAXN];
int lengthOfNameOrder = 0;

int main() {

    int n, m;
    ll score, p;
    scanf("%d %lld %d", &n, &p, &m);
    while (n--) {
        scanf("%s", name);
        A[name] = 0;
        nameOrder[lengthOfNameOrder++] = name;
    }
    while (m--) {
        scanf("%s %lld", name, &score);
        A[name] += score;
    }
    // output
    bool haveWinner = false;
    for (int i = 0; i < lengthOfNameOrder; ++i) {
        if (A[nameOrder[i]] >= p) {
            printf("%s wins!\n", nameOrder[i].c_str());
            haveWinner = true;
        }
    }
    if (!haveWinner) {
        printf("No winner!\n");
    }

    return 0;
}
