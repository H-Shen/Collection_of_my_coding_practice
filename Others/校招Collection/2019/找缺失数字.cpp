// https://www.nowcoder.com/practice/7cf889cb5db44e46a2fcc21c415c0150?tpId=98

#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    char ch;
    int temp;
    int n = 0;
    int s = 0;
    int maxVal = -1;
    bool includeZero = false;

    do {
        cin >> temp;
        ++n;
        s += temp;
        maxVal = max(maxVal, temp);
        if (temp == 0) {
            includeZero = true;
        }
    } while (cin >> ch);

    if (includeZero) {
        cout << (1 + n) * n / 2 - s << endl;
    } else {
        cout << (1 + maxVal) * (n + 1) / 2 - s << endl;
    }
    return 0;
}