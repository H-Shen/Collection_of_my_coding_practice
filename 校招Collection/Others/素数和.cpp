// https://www.nowcoder.com/practice/1f417f53ff7646a2800734b419b74d7c

#include <cstdio>
#include <unordered_map>

using namespace std;

const int N = 100003;
int prime[N] = {0}, num_prime = 0;
int isNotPrime[N] = {1, 1};
int pos = 0;

void sieve() {
    for (int i = 2; i < N; i++) {
        if (!isNotPrime[i])
            prime[num_prime++] = i;
        for (int j = 0; j < num_prime && i * prime[j] < N; j++) {
            isNotPrime[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
        }
    }

    return;
}

unordered_map<int, int> result;

int main() {

    sieve();
    int s, res;

    while (scanf("%d", &s) != EOF) {
        if (result.find(s) != result.end()) {
            printf("%d\n", result[s]);
            continue;
        }
        res = 0;
        for (int w = 0; w < num_prime && prime[w] <= s / 2; w++) {
            if (!isNotPrime[s - prime[w]]) {
                ++res;
            }
        }
        if (s % 2 == 0 && !isNotPrime[s / 2]) {
            --res;
        }
        printf("%d\n", res);
        result[s] = res;
    }
    return 0;
}
