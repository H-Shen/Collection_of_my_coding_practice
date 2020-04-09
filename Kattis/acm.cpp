// https://open.kattis.com/problems/acm
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

struct Item {
    int lastTime;
    int totalSubmission = 0;
    bool isSolve = false;
};

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int submitTime;
    char number;
    string answer;
    unordered_map<char, Item> A;

    while (true) {
        cin >> submitTime;
        if (submitTime == -1) {
            break;
        }
        cin >> number >> answer;
        if (answer == "wrong") {
            ++A[number].totalSubmission;
            A[number].lastTime = submitTime;
        } else {
            A[number].lastTime = A[number].totalSubmission * 20 + submitTime;
            A[number].isSolve = true;
        }
    }
    int totalTime = 0;
    int solveCnt = 0;
    for (const auto &it : A) {
        if (it.second.isSolve) {
            ++solveCnt;
            totalTime += it.second.lastTime;
        }
    }
    cout << solveCnt << ' ' << totalTime << '\n';
    return 0;
}
