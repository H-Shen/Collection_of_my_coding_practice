#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int prime[N] = {0}, num_prime = 0;
int isNotPrime[N] = {1, 1};
vector<int> hashPos;

void preComputation() {

    int i;
    for (i = 2; i < N; i++) {
        if (!isNotPrime[i])
            prime[num_prime++] = i;
        for (int j = 0; j < num_prime && i * prime[j] < N; j++) {
            isNotPrime[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
        }
    }
}

int main() {

    preComputation();
    int MSize, N, i, j, TSize = -1;
    scanf("%d %d", &MSize, &N);
    for (i = 0; i < num_prime - 1; i++) {
        if (prime[i] >= MSize && prime[i + 1]) {
            TSize = prime[i];
            break;
        }
    }

    if (TSize == -1) {
        return 0;
    }

    int currentVal, newPos;
    bool haveAns;
    hashPos.resize(TSize);

    for (i = 0; i < N - 1; i++) {
        scanf("%d", &currentVal);
        newPos = currentVal % TSize;
        if (hashPos[newPos] == 0) {
            printf("%d ", newPos);
            hashPos[newPos] = 1;
        } else {
            j = 1;
            haveAns = false;
            while (true) {
                newPos = (currentVal + j * j) % TSize;
                j++;
                if (hashPos[newPos] == 0) {
                    if (newPos < 0 || newPos >= TSize) {
                        break;
                    }
                    printf("%d ", newPos);
                    hashPos[newPos] = 1;
                    haveAns = true;
                    break;
                }
            }
            if (!haveAns) {
                printf("- ");
            }
        }
    }

    scanf("%d", &currentVal);
    newPos = currentVal % TSize;
    if (hashPos[newPos] == 0) {
        printf("%d", newPos);
        hashPos[newPos] = 1;
    } else {
        j = 1;
        haveAns = false;
        while (true) {
            newPos = (currentVal + j * j) % TSize;
            j++;
            if (hashPos[newPos] == 0) {
                if (newPos < 0 || newPos >= TSize) {
                    break;
                }
                printf("%d", newPos);
                hashPos[newPos] = 1;
                haveAns = true;
                break;
            }
        }
        if (!haveAns) {
            printf("-");
        }
    }
    printf("\n");
    return 0;
}