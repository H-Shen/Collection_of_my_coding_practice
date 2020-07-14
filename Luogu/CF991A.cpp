#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main(int argc, char *argv[]) {

    int a, b, c, A, B, C, N;
    cin >> A >> B >> C >> N;
    b = C;
    a = A - b;
    c = B - b;
    int answer = N - a - b - c;
    if (a < 0 || b < 0 || c < 0 || answer < 1) {
        answer = -1;
    }
    cout << answer << endl;

    return 0;
}