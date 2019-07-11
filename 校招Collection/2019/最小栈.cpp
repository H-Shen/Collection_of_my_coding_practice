// https://www.nowcoder.com/practice/a4d17eb2e9884359839f8ec559043761

#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> S;
stack<int> S_min;

int main() {

    int q, op, val;
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &op);
        switch (op) {
            case 0:
                printf("%d\n", S_min.top());
                break;
            case 1:
                scanf("%d", &val);
                S.push(val);
                if (S_min.empty()) {
                    S_min.push(val);
                } else {
                    S_min.push(min(val, S_min.top()));
                }
                break;
            case 2:
                printf("%d\n", S.top());
                S.pop();
                S_min.pop();
                break;
            default:
                break;
        }
    }
    return 0;
}