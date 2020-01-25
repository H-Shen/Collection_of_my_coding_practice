// https://open.kattis.com/problems/securedoors
//
#include <bits/extc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    unordered_set<string> Log;
    string s, name;
    while (n--) {
        cin >> s >> name;
        if (s == "entry") {
            if (Log.find(name) == Log.end()) {
                cout << name << " entered" << endl;
                Log.insert(name);
            } else {
                cout << name << " entered (ANOMALY)" << endl;
            }
        } else {
            if (Log.find(name) != Log.end()) {
                cout << name << " exited" << endl;
                Log.erase(name);
            } else {
                cout << name << " exited (ANOMALY)" << endl;
            }
        }
    }


    return 0;
}
