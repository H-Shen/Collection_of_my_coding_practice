// https://www.nowcoder.com/practice/696d1c350cf1492c9b22ad232614086f

#include <cstdio>
#include <vector>

using namespace std;

int main() {

    int p, n, i, tmp;
    bool haveAns;

    while (~scanf("%d %d", &p, &n)) {
        vector<int> a(p);
        vector<int> b(n);
        haveAns = false;
        for (i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        for (i = 0; i < n; i++) {
            tmp = b[i] % p;
            if (a[tmp] == 1) {
                haveAns = true;
                break;
            } else {
                a[tmp] = 1;
            }
        }
        if (haveAns)
            printf("%d\n", i + 1);
        else
            printf("-1\n");
    }
    return 0;
}