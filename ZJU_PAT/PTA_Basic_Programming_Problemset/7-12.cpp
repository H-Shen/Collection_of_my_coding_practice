#include <unordered_set>
#include <iostream>

using namespace std;

unordered_set<string> operatorList{"+", "-", "*", "/", "%"};

int main() {
    string x, o, y;
    int res = 0;
    cin >> x >> o >> y;
    if (operatorList.find(o) == operatorList.end()) {
        cout << "ERROR";
    } else {
        if (o == "+") {
            res = (stoi(x)) + (stoi(y));
        } else if (o == "-") {
            res = (stoi(x)) - (stoi(y));
        } else if (o == "*") {
            res = (stoi(x)) * (stoi(y));
        } else if (o == "/") {
            res = (stoi(x)) / (stoi(y));
        } else {
            res = (stoi(x)) % (stoi(y));
        }
        cout << res;
    }
    cout << endl;
    return 0;
}