#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

string process(const string &s) {
    if (s.size() == 1 && s == "0") {
        return s;
    }
    deque<char> temp(s.begin(), s.end());
    while (!temp.empty() && temp.front() == '0') {
        temp.pop_front();
    }
    if (temp.empty()) {
        return "0";
    }
    string temp_str(temp.begin(), temp.end());
    return temp_str;
}

int main() {
    
    vector<string> A;
    string s;
    int n;
    cin >> n;
    while (n--) {
        cin >> s;
        A.emplace_back(s);
    }
    sort(A.begin(), A.end(), [](const string &l, const string &r){
        return l + r < r + l;
    });
    string str;
    for (const auto &i : A) str += i;
    cout << process(str) << endl;

    return 0;
}
