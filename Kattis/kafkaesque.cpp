// https://open.kattis.com/problems/kafkaesque
//
#include <bits/extc++.h>

using namespace std;

int main() {

    int k;
    int counter = 0;
    cin >> k;
    deque<int> L(k);
    for (auto &i : L) {
        cin >> i;
    }
    while (!L.empty()) {
        for (int i = 1; i <= 100; ++i) {
            if (i == L.front()) {
                L.pop_front();
            }
        }
        ++counter;
    }
    cout << counter << endl;

    return 0;
}
