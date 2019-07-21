// https://www.nowcoder.com/practice/16fa68271ee5448cafd504bb4a64b482

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        for (const auto &ch : s) {
            if (isdigit(ch)) {
                cout << ch;
            }
        }
        cout << endl;
    }
    return 0;
}