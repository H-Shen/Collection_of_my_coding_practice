// https://www.nowcoder.com/practice/967133d6656440ba951870eaf17861de

#include <cmath>
#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;
    int n = static_cast<int>(sqrt(static_cast<double>(2 * N)));
    while (2 * N > (1 + n) * n) {
        ++n;
    }
    while (2 + n * (n - 1) > 2 * N) {
        --n;
    }
    cout << n << endl;
    return 0;
}