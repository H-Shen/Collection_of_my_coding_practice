// https://open.kattis.com/problems/icpcawards
#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1);

struct schoolNameAndTopTeam {
    string schoolName;
    string topTeam;
};

inline int sgn(double a) {
    if (a < -eps) return -1;
    if (a > eps) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    unordered_set<string> schoolNameList;
    string schoolName, teamName;
    vector<schoolNameAndTopTeam> A;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> schoolName >> teamName;
        if (schoolNameList.find(schoolName) == schoolNameList.end()) {
            schoolNameList.insert(schoolName);
            schoolNameAndTopTeam tmp;
            tmp.schoolName = schoolName;
            tmp.topTeam = teamName;
            A.push_back(tmp);
        }
    }

    for (int i = 0; i < 12; ++i) {
        cout << A[i].schoolName << ' ' << A[i].topTeam << endl;
    }

    return 0;
}
