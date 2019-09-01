// https://open.kattis.com/problems/karte
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    array<int, 4> A = {13, 13, 13, 13};
    unordered_set<string> allUniqCards;
    string s;
    string temp;
    cin >> s;
    for (size_t i = 0; i != s.size(); i += 3) {
        temp = s.substr(i, 3);
        if (allUniqCards.find(temp) != allUniqCards.end()) {
            cout << "GRESKA" << endl;
            return 0;
        }
        allUniqCards.insert(temp);
        switch (temp.front()) {
            case 'P':
                --A[0];
                break;
            case 'K':
                --A[1];
                break;
            case 'H':
                --A[2];
                break;
            default:
                --A[3];
                break;
        }
    }
    bool firstItem = true;
    for (const int &i : A) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << ' ';
        }
        cout << i;
    }
    cout << endl;

    return 0;
}
