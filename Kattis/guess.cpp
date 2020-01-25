// https://open.kattis.com/problems/guess
//
#include <bits/extc++.h>

using namespace std;
constexpr int MAXN = 1000;
constexpr int MINN = 1;

int main() {

    int low = MINN;
    int high = MAXN;
    string response;

    while (true) {
        int mid = low + (high - low) / 2;
        cout << mid << endl;
        cin >> response;
        if (response == "lower") {
            high = mid - 1;
        } else if (response == "higher") {
            low = mid + 1;
        } else {
            break;
        }
    }

    return 0;
}
