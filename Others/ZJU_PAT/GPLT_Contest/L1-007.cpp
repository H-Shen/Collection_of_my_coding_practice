#include <bits/stdc++.h>

using namespace std;

const int gap = 48;

unordered_map<int, string> A = {{0, "ling"},
                                {1, "yi"},
                                {2, "er"},
                                {3, "san"},
                                {4, "si"},
                                {5, "wu"},
                                {6, "liu"},
                                {7, "qi"},
                                {8, "ba"},
                                {9, "jiu"}};

int main() {

    string s;
    cin >> s;
    string res;

    int i = 0, len = s.size();
    if (s[0] == '-') {
        res += "fu ";
        ++i;
    }

    for (; i < len - 1; ++i) {
        res += A[static_cast<int>(s[i]) - gap] + ' ';
    }
    res += A[static_cast<int>(s[i]) - gap];

    cout << res << endl;

    return 0;
}
