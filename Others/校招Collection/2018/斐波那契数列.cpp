// https://www.nowcoder.com/practice/c245af6cfdce49ceb5435f649ee14f89

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    vector<int> A = {0, 1};
    while (true) {
        A.emplace_back(A.at(A.size() - 1) + A.at(A.size() - 2));
        if (A.at(A.size() - 1) < A.at(A.size() - 2)) {
            A.pop_back();
            break;
        }
    }

    int k;
    cin >> k;
    cout << A.at(k) << endl;
    return 0;
}