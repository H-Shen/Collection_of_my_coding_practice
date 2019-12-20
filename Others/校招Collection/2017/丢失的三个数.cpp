#include <cstdio>
// https://www.nowcoder.com/practice/1b58fbb97bc048b8a4438173c5392167

#include <string>

using namespace std;

const int MAXN = 10005, MAXNINPUT = 9997, DIV = 7;
int A[MAXN];

int main() {

    int i, n;
    string s;

    for (i = 0; i < MAXNINPUT; i++) {
        scanf("%d", &n);
        A[n] = 1;
    }
    for (i = 1; i <= MAXN - 5; i++) {
        if (A[i] == 0) {
            s = s + to_string(i);
        }
    }

    long long res = stol(s) % DIV;
    printf("%lld\n", res);

    return 0;
}