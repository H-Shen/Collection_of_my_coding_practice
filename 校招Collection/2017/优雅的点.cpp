// https://www.nowcoder.com/practice/0960cb46233b446687b77facc9148b89

#include <cstdio>
#include <cmath>

using namespace std;

int main() {

    int n, i, r, upperBound;
    int cnt = 0;
    scanf("%d", &n);

    r = sqrt((double) n);
    if (r * r == n) {
        cnt += 4;
        upperBound = r / sqrt(2.0);
    } else {
        upperBound = sqrt(n / 2.0);
    }
    int j, j_sqrt;
    for (i = 1; i <= upperBound; i++) {
        j = n - i * i;
        j_sqrt = sqrt((double) j);
        if (j_sqrt * j_sqrt == j) {
            if (j_sqrt == i)
                cnt += 4;
            else
                cnt += 8;
        }
    }
    printf("%d\n", cnt);
    return 0;
}