// https://open.kattis.com/problems/3dprinter
//
#include <bits/extc++.h>

using namespace std;

int main() {

    // pre
    ios_base::sync_with_stdio(false);
    vector<int> powerOfTwo = {1};
    while (powerOfTwo.back() < 100000) {
        powerOfTwo.emplace_back(powerOfTwo.back() * 2);
    }

    int n;
    cin >> n;
    size_t i = 0;
    for (; i != powerOfTwo.size(); ++i) {
        if (powerOfTwo[i] >= n) {
            break;
        }
    }
    cout << static_cast<int>(i) + 1 << endl;

    return 0;
}
