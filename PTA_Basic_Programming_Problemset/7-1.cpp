#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int len;
    cin >> len;
    int foot = static_cast<int>(len / 30.48);
    int inch = static_cast<int>((len / 30.48 - foot) * 12);
    cout << foot << ' ' << inch << endl;
}