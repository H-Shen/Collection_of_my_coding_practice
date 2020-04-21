#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq;
priority_queue<int, vector<int>, greater<> > pq_output;
int n, m, val;

int main() {

    scanf("%d %d", &n, &m);
    if (n == 0 || m == 0) {
        return 0;
    }
    while (n--) {
        scanf("%d", &val);
        if (pq.size() < m) {
            pq.push(val);
        } else if (val < pq.top()) {
            pq.pop();
            pq.push(val);
        }
    }
    while (!pq.empty()) {
        pq_output.push(pq.top());
        pq.pop();
    }
    while (!pq_output.empty()) {
        printf("%d\n", pq_output.top());
        pq_output.pop();
    }
    return 0;
}