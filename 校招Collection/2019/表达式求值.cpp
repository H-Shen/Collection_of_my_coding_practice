// https://www.nowcoder.com/practice/3e483fe3c0bb447bb17ffb3eeeca78ba
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    int maxVal = -1;

    maxVal = max(maxVal, a + b * c);
    maxVal = max(maxVal, a * b + c);
    maxVal = max(maxVal, a + b + c);
    maxVal = max(maxVal, a * b * c);
    maxVal = max(maxVal, (a + b) * c);
    maxVal = max(maxVal, a * (b + c));

    cout << maxVal << endl;
    return 0;
}