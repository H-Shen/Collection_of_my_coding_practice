// https://www.nowcoder.com/practice/7b3728138a8f44fd832078138a7d60c3

#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 10003, MAXN = 15;
int prime[N] = {0}, num_prime = 0;
int isNotPrime[N] = {1, 1};

void pre() {
    for (int i = 2; i < N; i++) {
        if (!isNotPrime[i])
            prime[num_prime++] = i;
        for (int j = 0; j < num_prime && i * prime[j] < N; j++) {
            isNotPrime[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
        }
    }
}

bool isPrime(const int s[], int n) {

    int num = 0;
    int pos = 1;

    for (int i = n - 1; i >= 0; i--) {
        num += s[i] * pos;
        pos *= 10;
    }

    if (num == 1)
        return false;
    for (int i = 0; prime[i] * prime[i] <= num; i++)
        if (num % prime[i] == 0)
            return false;
    return true;
}

int main() {

    pre();
    int n;
    scanf("%d", &n);

    while (n != 0) {

        bool haveAns = false;
        int a[MAXN];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        sort(a, a + n);

        if (isPrime(a, n)) {
            for (int j = 0; j < n; j++)
                printf("%d", a[j]);
            printf("\n");
            haveAns = true;
        }

        while (next_permutation(a, a + n)) {
            if (isPrime(a, n)) {
                for (int j = 0; j < n; j++)
                    printf("%d", a[j]);
                printf("\n");
                haveAns = true;
            }

        }

        if (!haveAns)
            printf("NONE\n");
        printf("\n");

        scanf("%d", &n);
    }
    return 0;
}