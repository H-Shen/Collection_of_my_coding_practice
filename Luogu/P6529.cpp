#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

array<int, 4> A = {13, 13, 13, 13};
unordered_set<string> allUniqCards;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    string s;
    string temp;
    cin >> s;
    for (size_t i = 0; i != s.size(); i += 3) {
        temp = s.substr(i, 3);
        if (allUniqCards.find(temp) != allUniqCards.end()) {
            cout << "GRESKA\n";
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
    cout << '\n';
    return 0;
}