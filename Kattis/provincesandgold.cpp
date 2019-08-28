// https://open.kattis.com/problems/provincesandgold
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int g, s, c;
    cin >> g >> s >> c;
    int a = 3*g + 2*s + c;
    string victoryCard;
    string treasureCard;
    if (a >= 8) {
        victoryCard = "Province";
    } else if (a >= 5) {
        victoryCard = "Duchy";
    } else if (a >= 2) {
        victoryCard = "Estate";
    }
    if (a >= 6) {
        treasureCard = "Gold";
    } else if (a >= 3) {
        treasureCard = "Silver";
    } else {
        treasureCard = "Copper";
    }
    if (victoryCard.empty()) {
        cout << treasureCard << endl;
    } else {
        cout << victoryCard << " or " << treasureCard << endl;
    }

    return 0;
}
