#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

vector<char> Adrian = {'A', 'B', 'C'};
vector<char> Bruno = {'B', 'A', 'B', 'C'};
vector<char> Goran = {'C', 'C', 'A', 'A', 'B', 'B'};

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
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
    cout << maxVal << '\n';
    if (cntAdrian == maxVal) {
        cout << "Adrian" << '\n';
    }
    if (cntBruno == maxVal) {
        cout << "Bruno" << '\n';
    }
    if (cntGoran == maxVal) {
        cout << "Goran" << '\n';
    }

    return 0;
}
