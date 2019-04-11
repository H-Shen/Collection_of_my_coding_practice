#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <vector>

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
    int maxVal = INT_MIN;
    for (auto it = A.begin(); it != A.end(); ++it) {
        maxVal = max(maxVal, it->second);
    }
    vector<char> List;
    for (auto it = A.begin(); it != A.end(); ++it) {
        if (it->second == maxVal) {
            List.push_back(it->first);
        }
    }
    sort(List.begin(), List.end());
    cout << List[0] << ' ' << A[List[0]] << endl;
    return 0;
}