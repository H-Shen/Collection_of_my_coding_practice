// https://open.kattis.com/problems/ptice
#include <bits/extc++.h>

using namespace std;

vector<char> Adrian = {'A', 'B', 'C'};
vector<char> Bruno = {'B', 'A', 'B', 'C'};
vector<char> Goran = {'C', 'C', 'A', 'A', 'B', 'B'};

int main() {
    int n;
    string s;
    cin >> n >> s;

    int posAdrian = 0, posBruno = 0, posGoran = 0;
    string strAdrian, strBruno, strGoran;
    for (int i = 0; i < n; ++i) {
        strAdrian += Adrian[posAdrian++];
        strBruno += Bruno[posBruno++];
        strGoran += Goran[posGoran++];
        if (posAdrian == 3) {
            posAdrian = 0;
        }
        if (posBruno == 4) {
            posBruno = 0;
        }
        if (posGoran == 6) {
            posGoran = 0;
        }
    }

    int cntAdrian = 0, cntBruno = 0, cntGoran = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == strAdrian[i]) {
            ++cntAdrian;
        }
        if (s[i] == strBruno[i]) {
            ++cntBruno;
        }
        if (s[i] == strGoran[i]) {
            ++cntGoran;
        }
    }
    vector<int> tmp{cntAdrian, cntBruno, cntGoran};
    int maxVal = *max_element(tmp.begin(), tmp.end());

    //output
    cout << maxVal << endl;
    if (cntAdrian == maxVal) {
        cout << "Adrian" << endl;
    }
    if (cntBruno == maxVal) {
        cout << "Bruno" << endl;
    }
    if (cntGoran == maxVal) {
        cout << "Goran" << endl;
    }

    return 0;
}
