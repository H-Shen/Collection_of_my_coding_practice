// https://open.kattis.com/problems/raggedright
//
#include <bits/extc++.h>

using namespace std;

int main() {

    vector<string> A;
    string s;
    int maxLength = -1;
    while (getline(cin, s)) {
        A.emplace_back(s);
        maxLength = max(maxLength, static_cast<int>(s.size()));
    }
    int raggedness = 0;
    for (size_t i = 0; i != A.size(); ++i) {
        if (i == A.size() - 1) {
            break;
        }
        int temp = maxLength - static_cast<int>(A.at(i).size());
        raggedness += temp * temp;
    }
    cout << raggedness << endl;

    return 0;
}
