// https://open.kattis.com/problems/bela
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    unordered_map<char, int> dominant;
    unordered_map<char, int> notDominant;

    dominant['A'] = 11;
    dominant['K'] = 4;
    dominant['Q'] = 3;
    dominant['J'] = 20;
    dominant['T'] = 10;
    dominant['9'] = 14;
    dominant['8'] = 0;
    dominant['7'] = 0;

    notDominant['A'] = 11;
    notDominant['K'] = 4;
    notDominant['Q'] = 3;
    notDominant['J'] = 2;
    notDominant['T'] = 10;
    notDominant['9'] = 0;
    notDominant['8'] = 0;
    notDominant['7'] = 0;

    int n;
    char suit;
    cin >> n >> suit;
    string card;
    int cnt = 0;
    for (int i = 0; i < 4 * n; ++i) {
        cin >> card;
        if (card[1] == suit) {
            cnt += dominant[card[0]];
        } else {
            cnt += notDominant[card[0]];
        }
    }
    cout << cnt << endl;

    return 0;
}
