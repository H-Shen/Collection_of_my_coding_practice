// https://open.kattis.com/problems/election2
//

#include <bits/extc++.h>

using namespace std;

unordered_map<string, string> nameToParty;
unordered_map<string, int> freq;

int main() {

    ios_base::sync_with_stdio(false);
    string name, party;
    int n;
    cin >> n;
    cin.get();
    while (n--) {
        getline(cin, name);
        getline(cin, party);
        nameToParty[name] = party;
    }

    int m;
    cin >> m;
    cin.get();
    while (m--) {
        getline(cin, name);
        ++freq[name];
    }

    // get max
    int maxVal = -1;
    for (const auto &it : freq) {
        maxVal = max(maxVal, it.second);
    }
    int counter = 0;
    string winnerName;
    for (const auto &it : freq) {
        if (it.second == maxVal) {
            ++counter;
            winnerName = it.first;
        }
    }

    if (counter > 1) {
        cout << "tie" << endl;
    } else {
        cout << nameToParty[winnerName] << endl;
    }

    return 0;
}
