#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, string> A = {{'0', "ling"},
                                 {'1', "yi"},
                                 {'2', "er"},
                                 {'3', "san"},
                                 {'4', "si"},
                                 {'5', "wu"},
                                 {'6', "liu"},
                                 {'7', "qi"},
                                 {'8', "ba"},
                                 {'9', "jiu"}};

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    bool firstItem = true;
    for (const char &ch : s) {
        if (firstItem) {
            if (ch == '-') {
                cout << "fu";
            } else {
                cout << A[ch];
            }
            firstItem = false;
        } else {
            cout << ' ' << A[ch];
        }
    }
    return 0;
}