#include <bits/stdc++.h>

using namespace std;

const int GAP = 'a' - 'A';

int main() {
    string str;
    char tmp;
    unordered_map<char, int> A;
    getline(cin, str);
    for (auto ch : str) {
        if (isalpha(ch)) {
            tmp = static_cast<char>((isupper(ch)) ? ch + GAP : ch);
            ++A[tmp];
        }
    }
    int maxVal = numeric_limits<int>::min();
    for (const auto & it : A) {
        maxVal = max(maxVal, it.second);
    }
    vector<char> List;
    for (const auto & it : A) {
        if (it.second == maxVal) {
            List.push_back(it.first);
        }
    }
    sort(List.begin(), List.end());
    cout << List.front() << ' ' << A[List.front()] << endl;
    return 0;
}