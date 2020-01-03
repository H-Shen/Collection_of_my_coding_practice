// https://open.kattis.com/problems/imagedecoding
//
#include <bits/stdc++.h>

using namespace std;

inline static
string parse(const string &s) {
    istringstream iss(s);

    // parse
    string temp;
    vector<string> A;
    do {
        iss >> temp;
        A.emplace_back(temp);
    } while (iss);
    A.pop_back();

    // decode
    string result;
    char currentPattern = A.front().front();
    for (size_t i = 1; i != A.size(); ++i) {
        result += string(stol(A.at(i)), currentPattern);
        if (currentPattern == '#') {
            currentPattern = '.';
        } else {
            currentPattern = '#';
        }
    }

    return result;
}

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    string s;
    string currentLine;
    bool firstItem = true;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        if (firstItem) {
            firstItem = false;
        } else {
            cout << endl;
        }
        cin.get();
        unordered_set<size_t> stats;
        while (n--) {
            getline(cin, s);
            currentLine = parse(s);
            stats.insert(currentLine.size());
            cout << currentLine << endl;
        }
        if (stats.size() > 1) {
            cout << "Error decoding image" << endl;
        }
    }

    return 0;
}
