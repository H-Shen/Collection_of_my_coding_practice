// https://open.kattis.com/problems/numbertree
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<ll> powerOfTwo = {1};

int main() {

    // pre
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 35; ++i) {
        powerOfTwo.emplace_back(powerOfTwo.back() * 2L);
    }

    // parse input
    string input, temp;
    getline(cin, input);
    vector<string> parseResult;
    istringstream iss(input);
    do {
        iss >> temp;
        parseResult.emplace_back(temp);
    } while (iss);
    parseResult.pop_back();

    int height = stoi(parseResult.at(0));
    ll root = powerOfTwo[height + 1] - 1;
    if (parseResult.size() == 1) {
        cout << root << endl;
    } else {
        string path = parseResult[1];
        int currentHeight = static_cast<int>(path.size());
        ll currentIndex = 1;
        for (const char &ch : path) {
            if (ch == 'L') {
                currentIndex = 2 * currentIndex - 1;
            } else {
                currentIndex = 2 * currentIndex;
            }
        }
        ll upperBound = root - (powerOfTwo[currentHeight] - 1);
        cout << upperBound - currentIndex + 1 << endl;
    }

    return 0;
}
