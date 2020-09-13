#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    int command, val;
    while (cin >> n) {

        stack<int> S;
        queue<int> Q;
        priority_queue<int> PQ;

        // -1 for impossible, the order is s, q, pq;
        vector<int> judge{0, 0, 0};
        while (n--) {
            cin >> command >> val;
            if (command == 1) {
                if (judge[0] != -1) {
                    S.push(val);
                }
                if (judge[1] != -1) {
                    Q.push(val);
                }
                if (judge[2] != -1) {
                    PQ.push(val);
                }
            } else {
                //handle 0 elements
                if (S.empty()) {
                    judge[0] = -1;
                }
                if (Q.empty()) {
                    judge[1] = -1;
                }
                if (PQ.empty()) {
                    judge[2] = -1;
                }

                //handle non 0 elements
                if (judge[0] != -1) {
                    if (S.top() == val) {
                        S.pop();
                    } else {
                        judge[0] = -1;
                    }
                }
                if (judge[1] != -1) {
                    if (Q.front() == val) {
                        Q.pop();
                    } else {
                        judge[1] = -1;
                    }
                }
                if (judge[2] != -1) {
                    if (PQ.top() == val) {
                        PQ.pop();
                    } else {
                        judge[2] = -1;
                    }
                }
            }
        }
        int negativeCnt = 0;
        for (const auto &i : judge) {
            if (i == -1) {
                ++negativeCnt;
            }
        }
        if (negativeCnt == 3) {
            cout << "impossible" << '\n';
        } else if (negativeCnt <= 1) {
            cout << "not sure" << '\n';
        } else {
            if (judge[0] == 0) {
                cout << "stack" << '\n';
            } else if (judge[1] == 0) {
                cout << "queue" << '\n';
            } else {
                cout << "priority queue" << '\n';
            }
        }
    }
    return 0;
}
