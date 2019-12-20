#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string s, sub;
    getline(cin, s);
    getline(cin, sub);
    while (true) {
        size_t i = s.find(sub);
        if (i == string::npos) {
            break;
        }
        s.erase(i, sub.length());
    }
    cout << s << endl;
}