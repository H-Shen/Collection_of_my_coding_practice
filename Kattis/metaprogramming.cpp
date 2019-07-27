// https://open.kattis.com/problems/metaprogramming
#include<bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    unordered_map<string, int> varTable;
    int val;

    while (getline(cin, s)) {
        istringstream iss(s);
        vector<string> res((istream_iterator<string>(iss)), istream_iterator<string>());
        if (res[0] == "define") {
            val = stoi(res[1]);
            varTable[res[2]] = val;
        } else {
            if (varTable.find(res[1]) == varTable.end()) {
                cout << "undefined" << endl;
            } else if (varTable.find(res[3]) == varTable.end()) {
                cout << "undefined" << endl;
            } else if (res[2] == "<") {
                cout << boolalpha << (varTable[res[1]] < varTable[res[3]]) << endl;
            } else if (res[2] == "=") {
                cout << boolalpha << (varTable[res[1]] == varTable[res[3]]) << endl;
            } else if (res[2] == ">") {
                cout << boolalpha << (varTable[res[1]] > varTable[res[3]]) << endl;
            }
        }
    }
    return 0;
}
