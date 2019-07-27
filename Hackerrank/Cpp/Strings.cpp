#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Complete the program
    string a, b;
    cin >> a >> b;
    string c = a + b;
    cout << a.length() << " " << b.length() << endl;
    cout << c << endl;

    swap(a[0], b[0]);
    cout << a << " " << b << endl;

    return 0;
}
