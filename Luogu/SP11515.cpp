#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

struct Node {
    int start, finish;
};

bool cmp(const Node &l, const Node &r) {
    if (l.finish == r.finish) {
        return l.start < r.start;
    }
    return (l.finish < r.finish);
}

int main() {

    int t;
    scanf("%d", &t);
    int n;
    int counter;
    int current_finish_time;
    while (t--) {
        scanf("%d", &n);
        vector<Node> A(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &A[i].start, &A[i].finish);
        }
        sort(A.begin(), A.end(), cmp);
        counter = 0;
        current_finish_time = -1;
        for (int i = 0; i < n; ++i) {
            if (A[i].start >= current_finish_time) {
                ++counter;
                current_finish_time = A[i].finish;
            }
        }
        printf("%d\n", counter);
    }

    return 0;
}