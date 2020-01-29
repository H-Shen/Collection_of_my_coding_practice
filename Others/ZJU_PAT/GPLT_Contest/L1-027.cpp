#include <bits/stdc++.h>

using namespace std;

const int gap = 48;

bool cmp(const char &a, const char &b) {
    return (a > b);
}

int main() {

    string s;
    cin >> s;
    unordered_set<char> uniqueNumber(s.begin(), s.end());
    vector<char> uniqueNumberList(uniqueNumber.begin(), uniqueNumber.end());
    sort(uniqueNumberList.begin(), uniqueNumberList.end(), cmp);

    unordered_map<char, char> posSave;
    int i;
    int len;
    len = uniqueNumberList.size();
    for (i = 0; i < len; ++i) {
        posSave[uniqueNumberList[i]] = (char) (i + gap);
    }
    len = s.size();
    vector<char> posCorrespond(len);
    for (i = 0; i < len; ++i) {
        posCorrespond[i] = posSave[s[i]];
    }

    cout << "int[] arr = new int[]{";
    len = uniqueNumberList.size();
    for (i = 0; i < len - 1; ++i) {
        cout << uniqueNumberList[i] << ",";
    }
    cout << uniqueNumberList[len - 1] << "};" << endl;

    cout << "int[] index = new int[]{";
    len = posCorrespond.size();
    for (i = 0; i < len - 1; ++i) {
        cout << posCorrespond[i] << ",";
    }
    cout << posCorrespond[len - 1] << "};" << endl;

    return 0;
}