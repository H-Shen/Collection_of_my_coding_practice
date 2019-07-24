// https://www.nowcoder.com/practice/077d8fd660f74a938019b17314ed1707

#include <string>
#include <iostream>

using namespace std;
const string NO_EXISTS = "null";
const int MIN_LENGTH = 11;

int main() {

    string s;
    getline(cin, s);
    auto position0 = s.rfind("[img]");
    if (position0 == string::npos) {
        cout << NO_EXISTS << endl;
        return 0;
    }
    auto position1 = s.rfind("[\\img]");
    if (position1 == string::npos) {
        cout << NO_EXISTS << endl;
        return 0;
    }

    string temp = s.substr(position0, position1 - position0 + 6);
    if (temp.size() < MIN_LENGTH) {
        cout << NO_EXISTS << endl;
    } else {
        cout << temp << endl;
    }

    return 0;
}