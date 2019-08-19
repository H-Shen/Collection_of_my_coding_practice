#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, u, d;
    cin >> n >> u >> d;
    int s = 0;
    int count = 0;
    while (true) {
        ++count;
        s += u;
        if (s >= n) {
            break;
        }
        ++count;
        s -= d;
    }
    cout << count << endl;
}