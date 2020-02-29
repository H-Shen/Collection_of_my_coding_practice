// https://open.kattis.com/problems/climbingworm
//
#include <bits/extc++.h>

using namespace std;

int main() {

    int a, b, h;
    cin >> a >> b >> h;
    int counter = 0;
    int current = 0;
    while (true) {
        current += a;
        ++counter;
        if (current >= h) {
            break;
        }
        current -= b;
    }
    cout << counter << endl;

    return 0;
}
