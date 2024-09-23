// https://www.nowcoder.com/practice/7f436c901a0d450ebdec1168e3e57cc2

#include <iostream>
#include <string>

using namespace std;

int main() {

    string s1, s2;
    while (cin >> s1 >> s2) {
        auto it1 = s1.cbegin();
        auto it2 = s2.crbegin();
        while (it1 != s1.cend()) {
            cout << *it1;
            cout << *it2;
            ++it1;
            ++it2;
        }
        cout << endl;
    }
    return 0;
}