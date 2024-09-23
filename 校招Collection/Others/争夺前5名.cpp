// https://www.nowcoder.com/practice/cd052308a1c44a88ad00255f312c3e14
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;
constexpr size_t MAXN = 5;

void output(priority_queue<int, vector<int>, greater<> > &pq) {
    static bool first_item = true;
    int temp;
    while (!pq.empty()) {
        temp = pq.top();
        pq.pop();
        output(pq);
        if (first_item) {
            first_item = false;
        } else {
            printf(" ");
        }
        printf("%d", temp);
    }
}

int main() {

    priority_queue<int, vector<int>, greater<> > pq;
    int n, val;
    scanf("%d", &n);
    vector<int> A(n);
    while (n--) {
        scanf("%d", &val);
        pq.push(val);
        if (pq.size() > MAXN) {
            pq.pop();
        }
    }

    output(pq);
    printf("\n");
    return 0;
}