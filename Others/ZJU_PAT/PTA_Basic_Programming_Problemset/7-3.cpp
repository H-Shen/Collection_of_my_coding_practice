#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    cout << stoi(s) << endl;
    return 0;
}