// https://ac.nowcoder.com/acm/problem/14556

#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1000005;
int s[N];
int cnt = 0;
int tmp;

inline static
int f(int n) {
    int count = 0;
    while (n > 0) {
        tmp = n % 10;
        switch (tmp) {
            case 0 :
                ++count;
                break;
            case 4 :
                ++count;
                break;
            case 6 :
                ++count;
                break;
            case 8 :
                count += 2;
                break;
            case 9 :
                ++count;
                break;
            default:
                break;
        }
        n /= 10;
    }
    return count;
}

int main() {
    int i;
    for (i = 1; i <= N - 5; ++i) {
        cnt += f(i);
        s[i] = cnt;
    }
    int n, a, b;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        if (a == b) {
            printf("%d\n", f(a));
        } else {
            printf("%d\n", s[b] - s[a] + f(a));
        }
    }
    return 0;
}