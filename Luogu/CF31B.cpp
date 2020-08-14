#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    string s;
    cin >> s;
    deque<char> temp(s.begin(), s.end());
    vector<string> result;
    s.clear();
    bool have_ans = true;
    while (!temp.empty()) {
        if (temp.front() == '@') {
            if (s.empty()) {
                have_ans = false;
                break;
            } else if (s.back() == '@') {
                have_ans = false;
                break;
            } else {
                s.push_back(temp.front());
            }
        } else {
            if (s.empty() || s.back() != '@') {
                s.push_back(temp.front());
            } else {
                s.push_back(temp.front());
                result.emplace_back(s);
                s.clear();
            }
        }
        temp.pop_front();
    }
    if (!s.empty() && !result.empty()) {
        result.back().append(s);
    }
    if (result.empty()) {
        have_ans = false;
    }
    for (const auto &i : result) {
        if (i.front() == '@' || i.back() == '@') {
            have_ans = false;
            break;
        }
    }
    // output
    if (have_ans) {
        bool first_item = true;
        for (const auto &i : result) {
            if (first_item) first_item = false;
            else cout << ',';
            cout << i;
        }
    } else {
        cout << "No solution";
    }


    return 0;
}