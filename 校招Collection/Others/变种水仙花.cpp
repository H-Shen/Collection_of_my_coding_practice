// https://www.nowcoder.com/practice/c178e3f5cc4641dfbc8b020ae79e2b71
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;

vector<int> A = {14610, 16420, 23610, 34420, 65500};
void solve() {
    string s, a, b;
    int sum;
    for (int i = 10000; i <= 99999; ++i) {
        s = to_string(i);
        sum = 0;
        for (int j = 1; j <= 4; ++j) {
            a = s.substr(0, j);
            b = s.substr(j);
            sum += stoi(a) * stoi(b);
        }
        if (sum == i) {
            A.emplace_back(i);
        }
    }
}

int main() {

    // solve();
    bool first_item = true;
    for (const auto &i : A) {
        if (first_item) {
            first_item = false;
        } else {
            printf(" ");
        }
        printf("%d", i);
    }
    printf("\n");

    return 0;
}