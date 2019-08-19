// https://open.kattis.com/problems/textureanalysis
//
#include <bits/stdc++.h>

using namespace std;

inline static
bool isEven(const string &s) {

    bool shouldNotEncounterWhitePixel = false;
    if (s.find("**") != string::npos) {
        shouldNotEncounterWhitePixel = true;
    }

    unordered_set<int> temp;
    int whitePixels = 0;
    bool encounterWhitePixel = false;
    for (size_t i = 0; i != s.size(); ++i) {
        if (s[i] == '.') {
            if (shouldNotEncounterWhitePixel) {
                return false;
            }
            if (!encounterWhitePixel) {
                encounterWhitePixel = true;
            }
            ++whitePixels;
        }
            // Case 2: *
        else {
            if (encounterWhitePixel) {
                temp.insert(whitePixels);
                if (temp.size() > 1) {
                    return false;
                }
                whitePixels = 0;
            }
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    int kase = 1;
    while (cin >> s) {
        if (s == "END") {
            break;
        }
        cout << kase << ' ';
        if (isEven(s)) {
            cout << "EVEN";
        } else {
            cout << "NOT EVEN";
        }
        cout << endl;
        ++kase;
    }

    return 0;
}
