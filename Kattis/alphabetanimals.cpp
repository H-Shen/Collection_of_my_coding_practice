// https://open.kattis.com/problems/alphabetanimals
//
#include <bits/extc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);

    string previous, current;

    // input
    cin >> previous;
    int n;
    cin >> n;
    unordered_map<char, deque<string> > A;

    for (char ch = 'a'; ch <= 'z'; ++ch) {
        A[ch].clear();
    }
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        A[ch].clear();
    }
    while (n--) {
        cin >> current;
        A[current.front()].push_back(current);
    }

    char ch = previous.back();
    if (A[ch].empty()) {
        cout << "?" << endl;
    }
    else {
        string result;
        bool haveAnsCanEliminateOtherPlayer = false;
        for (const string &i : A[ch]) {
            if (i.back() != ch && A[i.back()].empty()) {
                result = i;
                haveAnsCanEliminateOtherPlayer = true;
                break;
            }
            if (i.back() == ch && A[i.back()].size() == 1) {
                result = i;
                haveAnsCanEliminateOtherPlayer = true;
                break;
            }
        }
        if (haveAnsCanEliminateOtherPlayer) {
            cout << result << "!" << endl;
        } else {
            cout << A[ch].front() << endl;
        }

    }
    return 0;
}
