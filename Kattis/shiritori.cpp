// https://open.kattis.com/problems/shiritori
//
#include <bits/extc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    unordered_set<string> A;
    string s;
    cin >> n;
    bool playerOne = true;
    string lastWord;
    while (n--) {
        cin >> s;
        if (A.find(s) != A.end()) {
            if (playerOne) {
                cout << "Player 1 lost" << endl;
            } else {
                cout << "Player 2 lost" << endl;
            }
            return 0;
        }
        if (lastWord.empty()) {
            A.insert(s);
            lastWord = s;
        } else {
            if (s.front() != lastWord.back()) {
                if (playerOne) {
                    cout << "Player 1 lost" << endl;
                } else {
                    cout << "Player 2 lost" << endl;
                }
                return 0;
            } else {
                A.insert(s);
                lastWord = s;
            }
        }
        playerOne = !playerOne;
    }
    cout << "Fair Game" << endl;

    return 0;
}
