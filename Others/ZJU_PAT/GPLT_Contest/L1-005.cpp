#include <bits/stdc++.h>

const int maxn = 20;
char idInput[maxn];

using namespace std;

struct Stu {
    char id[maxn];
    int num;
};

unordered_map<int, Stu> A;

int main() {
    int n, num0, num1;
    scanf("%d", &n);
    while (n--) {
        scanf("%s %d %d", idInput, &num0, &num1);
        Stu tmp;
        strcpy(tmp.id, idInput);
        tmp.num = num1;
        A[num0] = tmp;
    }
    int m, chk;
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &chk);
        printf("%s %d\n", A[chk].id, A[chk].num);
    }
    return 0;
}