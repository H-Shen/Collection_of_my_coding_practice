#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;
char num[maxn];

int main() {
    unordered_map<char, int> A;
    scanf("%s", num);
    int i = 0;
    while (num[i] != '\0') {
        if (A.find(num[i]) == A.end()) {
            A[num[i]] = 1;
        } else {
            A[num[i]]++;
        }
        ++i;
    }
    char j = '0';
    while (true) {
        if (A.find(j) != A.end()) {
            printf("%c:%d\n", j, A[j]);
        }
        if (j == '9') {
            break;
        }
        ++j;
    }
    return 0;
}