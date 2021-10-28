// https://open.kattis.com/problems/intervalscheduling

#include <bits/extc++.h>

using ll = long long;
using namespace std;

struct Node {
    int start, end;
    bool operator < (const Node &node) const {
        if (end == node.end) {
            return start > node.start;
        }
        return end > node.end;
    }
};

int n;
priority_queue<Node, vector<Node>, less<>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    Node node;
    for (int i = 0; i < n; ++i) {
        cin >> node.start >> node.end;
        pq.push(node);
    }
    int counter = 0;
    int endTime;
    while (true) {
        if (!pq.empty()) {
            ++counter;
            endTime = pq.top().end;
            pq.pop();
        }
        while (!pq.empty() && pq.top().start < endTime) {
            pq.pop();
        }
        if (pq.empty()) {
            break;
        }
    }
    cout << counter << '\n';
    return 0;
}
