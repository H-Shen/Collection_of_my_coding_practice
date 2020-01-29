#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    string id;
    unordered_set<string> notHandsomePeopleOnList;
    cin >> n;
    while (n--) {
        cin >> m;
        if (m == 1) {
            cin >> id;
        } else {
            while (m--) {
                cin >> id;
                notHandsomePeopleOnList.insert(id);
            }
        }
    }

    unordered_set<string> handsomePeopleBeenChecked;
    vector<string> result;
    int query;
    cin >> query;
    while (query--) {
        cin >> id;
        if (notHandsomePeopleOnList.find(id) == notHandsomePeopleOnList.end()) {
            if (handsomePeopleBeenChecked.find(id) != handsomePeopleBeenChecked.end()) {
                continue;
            } else {
                handsomePeopleBeenChecked.insert(id);
                result.push_back(id);
            }
        }
    }
    int len = result.size();
    if (len == 0) {
        cout << "No one is handsome" << endl;
    } else {
        for (int i = 0; i < len - 1; ++i) {
            cout << result[i] << ' ';
        }
        cout << result[len - 1] << endl;
    }

    return 0;
}