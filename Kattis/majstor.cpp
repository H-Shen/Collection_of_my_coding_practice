// https://open.kattis.com/problems/majstor
//
#include <bits/extc++.h>

using namespace std;

int score(const string &a, const string &b) {
    int counter = 0;
    int n = (int)a.size();
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            if (a[i] == 'S' && b[i] == 'P') {
                counter += 2;
            }
            else if (a[i] == 'P' && b[i] == 'R') {
                counter += 2;
            }
            else if (a[i] == 'R' && b[i] == 'S') {
                counter += 2;
            }
        } else {
            ++counter;
        }
    }
    return counter;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<string> A(m);
    for (auto &i : A) cin >> i;
    vector<int> scoreList(m);
    for (int i = 0; i < m; ++i) {
        scoreList[i] = score(s, A[i]);
    }
    cout << accumulate(scoreList.begin(), scoreList.end(), 0) << '\n';
    int sum = 0;
    vector<char> B = {'S', 'R', 'P'};
    for (int i = 0; i < n; ++i) {
        int maxScoreEachRound = -1;
        for (const auto &j : B) {
            int counter = 0;
            for (int k = 0; k < m; ++k) {
                if (j != A[k][i]) {
                    if (j == 'S' && A[k][i] == 'P') {
                        counter += 2;
                    }
                    else if (j == 'P' && A[k][i] == 'R') {
                        counter += 2;
                    }
                    else if (j == 'R' && A[k][i] == 'S') {
                        counter += 2;
                    }
                } else {
                    ++counter;
                }
            }
            maxScoreEachRound = max(maxScoreEachRound, counter);
        }
        sum += maxScoreEachRound;
    }
    cout << sum << '\n';

    return 0;
}
