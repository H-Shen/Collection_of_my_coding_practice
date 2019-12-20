#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    size_t k;
    getline(cin, s);
    cin >> k;
    rotate(s.begin(), s.begin() + static_cast<size_t>(k % s.length()), s.end());
    cout << s << endl;
    return 0;
}