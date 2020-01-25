// https://open.kattis.com/problems/smartphone
//
#include <bits/extc++.h>

using namespace std;

int calculateKeypresses(const string &soFarTyped, const string &suggestion, const string &original) {
    int result = 1; // take the suggestion
    int i = 0;
    for (; i < static_cast<int>(suggestion.size()) && i < static_cast<int>(original.size()); ++i) {
        if (suggestion.at(i) != original.at(i)) {
            break;
        }
    }
    result += static_cast<int>(suggestion.size()) - i + static_cast<int>(original.size()) - i;
    return result;
}

int main() {

    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string original;
    string soFarTyped;
    string s1;
    string s2;
    string s3;


    while (T--) {

        cin >> original >> soFarTyped >> s1 >> s2 >> s3;

        int minimalKeyPresses = numeric_limits<int>::max();

        // Case 1: Do not take any suggestions.
        int i = 0;
        for (; i < static_cast<int>(soFarTyped.size()) && i < static_cast<int>(original.size()); ++i) {
            if (soFarTyped.at(i) != original.at(i)) {
                break;
            }
        }
        int keyPressesInCase1 = static_cast<int>(soFarTyped.size()) - i + static_cast<int>(original.size()) - i;
        minimalKeyPresses = min(minimalKeyPresses, keyPressesInCase1);
        // Case 2:
        minimalKeyPresses = min(minimalKeyPresses, calculateKeypresses(soFarTyped, s1, original));
        minimalKeyPresses = min(minimalKeyPresses, calculateKeypresses(soFarTyped, s2, original));
        minimalKeyPresses = min(minimalKeyPresses, calculateKeypresses(soFarTyped, s3, original));
        cout << minimalKeyPresses << endl;
    }

    return 0;
}
