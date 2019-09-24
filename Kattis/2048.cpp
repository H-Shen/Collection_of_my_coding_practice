// https://open.kattis.com/problems/2048
//
#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 4;

deque<int> mergeARow(deque<int> q) {
    deque<int> newQ;
    for (int i = 0; i < MAXN; ++i) {
        if (q.at(i) != 0) {
            newQ.emplace_back(q.at(i));
        }
    }
    while (newQ.size() != MAXN) {
        newQ.emplace_back(0);
    }
    // merge
    deque<int> resultQ;
    while (!newQ.empty()) {
        if (newQ.size() == 1) {
            resultQ.emplace_back(newQ.at(0));
            newQ.pop_front();
        } else if (newQ.at(0) == newQ.at(1)) {
            resultQ.emplace_back(newQ.at(0) * 2);
            newQ.pop_front();
            newQ.pop_front();
        } else {
            resultQ.emplace_back(newQ.at(0));
            newQ.pop_front();
        }
    }
    while (resultQ.size() != MAXN) {
        resultQ.emplace_back(0);
    }
    return resultQ;
}

int main() {

    ios_base::sync_with_stdio(false);
    deque<deque<int> > A(MAXN, deque<int>(MAXN));
    for (auto &i : A) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    int direction;
    cin >> direction;
    switch (direction) {
        // left
        case 0:
            for (int i = 0; i < MAXN; ++i) {
                deque<int> temp = mergeARow(A.at(i));
                for (int j = 0; j < MAXN; ++j) {
                    A.at(i).at(j) = temp.at(j);
                }
            }
            break;
        // up
        case 1:
            for (int j = 0; j < MAXN; ++j) {
                deque<int> temp;
                for (int i = 0; i < MAXN; ++i) {
                    temp.emplace_back(A.at(i).at(j));
                }
                temp = mergeARow(temp);
                for (int i = 0; i < MAXN; ++i) {
                    A.at(i).at(j) = temp.at(i);
                }
            }
            break;
        // right
        case 2:
            for (int i = 0; i < MAXN; ++i) {
                deque<int> temp;
                for (int j = MAXN - 1; j >= 0; --j) {
                    temp.emplace_back(A.at(i).at(j));
                }
                temp = mergeARow(temp);
                for (int j = MAXN - 1; j >= 0; --j) {
                    A.at(i).at(j) = temp.at(MAXN - 1 - j);
                }
            }
            break;
        // down
        default:
            for (int j = 0; j < MAXN; ++j) {
                deque<int> temp;
                for (int i = MAXN - 1; i >= 0; --i) {
                    temp.emplace_back(A.at(i).at(j));
                }
                temp = mergeARow(temp);
                for (int i = MAXN - 1; i >= 0; --i) {
                    A.at(i).at(j) = temp.at(MAXN - 1 - i);
                }
            }
            break;
    }

    // output
    bool firstItem;
    for (int i = 0; i < MAXN; ++i) {
        firstItem = true;
        for (int j = 0; j < MAXN; ++j) {
            if (firstItem) {
                firstItem = false;
            } else {
                cout << " ";
            }
            cout << A.at(i).at(j);
        }
        cout << endl;
    }

    return 0;
}
