// https://open.kattis.com/problems/battlesimulation
//
#include <bits/stdc++.h>

using namespace std;

constexpr int maxn = 1000005;
char str[maxn];

unordered_set<string> A;
unordered_map<char, char> B = {{'R', 'S'}, {'B', 'K'}, {'L', 'H'}};

void pre() {
    string s = "RBL";
    sort(s.begin(), s.end());
    do {
        A.insert(s);
    } while (next_permutation(s.begin(), s.end()));
}

int main() {

    scanf("%s", str);
    string s(str);
    string result;
    if (s.size() <= 2) {
        for (size_t i = 0; i != s.size(); ++i) {
            result.push_back(B[s.at(i)]);
        }
    } else {
        pre();
        for (size_t i = 0; i != s.size(); ) {
            if (A.find(s.substr(i, 3)) != A.end()) {
                result.push_back('C');
                i += 3;
            } else {
                result.push_back(B[s.at(i)]);
                ++i;
            }
        }
    }
    printf("%s\n", result.c_str());
    return 0;
}
