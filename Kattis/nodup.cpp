// https://open.kattis.com/problems/nodup
#include <bits/extc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string line;
    unordered_set<string> A;
    getline(cin, line);
    istringstream iss(line);

    do {
        string s;
        iss >> s;
        if (s == "") {
            continue;
        }
        if (A.find(s) != A.end()) {
            cout << "no" << endl;
            return 0;
        }
        A.insert(s);
    } while (iss);
    cout << "Yes" << endl;
    return 0;
}
