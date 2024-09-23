// https://www.nowcoder.com/practice/b3c88bb9acda4d0cb6a2f50e45739332

#include <bits/stdc++.h>

using namespace std;
priority_queue<int> pq;

int main() {

    int m, n, val;
    scanf("%d %d", &m, &n);
    while (m--) {
        scanf("%d", &val);
        if (n == static_cast<int>(pq.size())) {
            if (val < pq.top()) {
                pq.pop();
                pq.push(val);
            }
        } else {
            pq.push(val);
        }
    }

    bool firstItem{true};
    while (!pq.empty()) {
        if (firstItem) {
            firstItem = false;
        } else {
            printf(" ");
        }
        printf("%d", pq.top());
        pq.pop();
    }
    printf("\n");

    return 0;
}