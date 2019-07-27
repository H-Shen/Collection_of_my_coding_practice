// https://open.kattis.com/submissions/3137308
#include<bits/stdc++.h>

using namespace std;

struct item {
    int lastTime;
    int totalSubmission = 0;
    bool isSolve = false;
};

int main() {
    ios_base::sync_with_stdio(false);
    int submitTime;
    char number;
    string answer;
    unordered_map<char, item> A;

    while (1) {
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
    cout << solveCnt << ' ' << totalTime << endl;
    return 0;
}
