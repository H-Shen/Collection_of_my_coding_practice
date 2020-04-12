// https://www.luogu.com.cn/problem/P1328
// NOIP2014
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_map<int, unordered_set<int> > win;
unordered_map<int, unordered_set<int> > lose;
unordered_map<int, unordered_set<int> > draw;

void pre() {

    draw[0].insert(0);
    draw[1].insert(1);
    draw[2].insert(2);
    draw[3].insert(3);
    draw[4].insert(4);

    lose[0].insert(1);
    lose[1].insert(2);
    lose[2].insert(3);
    lose[0].insert(4);
    lose[1].insert(4);

    win[0].insert(2);
    win[0].insert(3);
    win[1].insert(3);
    win[2].insert(4);
    win[3].insert(4);

    for (const auto &i : lose) {
        for (const auto &j : i.second) {
            win[j].insert(i.first);
        }
    }
    for (const auto &i : win) {
        for (const auto &j : i.second) {
            lose[j].insert(i.first);
        }
    }
}

int main() {

    pre();
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    vector<int> A(a);
    vector<int> B(b);
    for (auto &i : A) {
        scanf("%d", &i);
    }
    for (auto &i : B) {
        scanf("%d", &i);
    }
    auto iter_A = A.cbegin();
    auto iter_B = B.cbegin();
    int score_A = 0;
    int score_B = 0;
    int tempA, tempB;
    for (int i = 0; i < n; ++i) {
        if (iter_A == A.cend()) {
            iter_A = A.cbegin();
        }
        if (iter_B == B.cend()) {
            iter_B = B.cbegin();
        }
        tempA = *iter_A;
        tempB = *iter_B;

        if (draw.find(tempA) != draw.end() && draw[tempA].find(tempB) != draw[tempA].end()) {
            // do nothing
        } else if (win.find(tempA) != win.end() && win[tempA].find(tempB) != win[tempA].end()) {
            ++score_A;
        } else {
            ++score_B;
        }

        ++iter_A;
        ++iter_B;
    }
    printf("%d %d\n", score_A, score_B);

    return 0;
}