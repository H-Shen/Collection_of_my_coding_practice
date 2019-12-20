// https://www.nowcoder.com/practice/4d1afe11171c44a385287e29092cdb3f

#include <bitset>
#include <cstdio>
#include <string>

using namespace std;

const int MAXLEN = 20, MAXN = 100005;
int A[MAXN];

int main() {

    int n, i, j, j_copy, sum0, sum1;
    int cnt = 0;
    string str;

    for (j = 1; j < MAXN; j++) {

        bitset<MAXLEN> a(j);
        str = a.to_string();

        //f(x)
        sum0 = 0, sum1 = 0;
        for (i = 0; i < MAXLEN; i++) {
            if (str[i] == '1')
                sum0 += 1;
        }

        //g(x)
        j_copy = j;
        while (j_copy > 0) {
            sum1 = sum1 + j_copy % 10;
            j_copy /= 10;
        }

        if (sum0 == sum1) {
            cnt += 1;
        }
        A[j] = cnt;
    }

    scanf("%d", &n);
    printf("%d\n", A[n]);

    return 0;
}