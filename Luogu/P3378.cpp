#include <bits/extc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<> > pq;

int main() {
    
    int n, op, val;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &val);
            pq.push(val);
        } else if (op == 2) {
            printf("%d\n", pq.top());
        } else {
            pq.pop();
        }
    }

    return 0;
}