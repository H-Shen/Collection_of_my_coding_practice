// https://open.kattis.com/problems/eenymeeny
//
#include <bits/stdc++.h>

using namespace std;
vector<string> A;
vector<string> team1;
vector<string> team2;

inline static
int getLengthOfCycle(const string &s) {
    istringstream iss(s);
    string temp;
    int counter = 0;
    do {
        iss >> temp;
        ++counter;
    } while (iss);
    --counter;
    return counter;
}

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    getline(cin, s);
    int cycleLength = getLengthOfCycle(s);
    int n;
    cin >> n;
    A.resize(static_cast<size_t>(n));
    for (auto &i : A) {
        cin >> i;
    }
    int counter = 1;
    size_t i = 0;
    int elementProcess = 0;
    bool change = true;

    while (elementProcess < n) {

        if (A.at(i).empty()) {
            ++i;
            if (i == A.size()) {
                i = 0;
            }
            continue;
        }

        if (counter == cycleLength) {
            if (change) {
                team1.emplace_back(A.at(i));
                change = false;
            } else {
                team2.emplace_back(A.at(i));
                change = true;
            }
            A.at(i) = "";
            ++elementProcess;
            counter = 1;
        } else {
            ++counter;
        }

        ++i;
        if (i == A.size()) {
            i = 0;
        }
    }

    // output
    cout << team1.size() << endl;
    for (const auto &name : team1) {
        cout << name << endl;
    }
    cout << team2.size() << endl;
    for (const auto &name : team2) {
        cout << name << endl;
    }

    return 0;
}
