#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string check;
    cin >> check;
    for (auto &i : check) {
        i = tolower(i);
    }
    cin.get();
    string s;
    getline(cin, s);
    string word;
    int n = static_cast<int>(s.size());
    int index = 0;
    int smallest_index = numeric_limits<int>::max();
    bool in = false;
    int freq = 0;
    for (int i = 0; i < n; ++i) {
        if (in) {
            if (s.at(i) == ' ') {
                in = false;
                if (word == check) {
                    ++freq;
                    smallest_index = min(index, smallest_index);
                }
                word = "";
            } else {
                word += tolower(s.at(i));
            }
        } else {
            if (s.at(i) != ' ') {
                in = true;
                word += tolower(s.at(i));
                index = i;
            }
        }
    }
    if (!word.empty()) {
        if (word == check) {
            ++freq;
            smallest_index = min(index, smallest_index);
        }
    }
    if (freq == 0) {
        cout << -1 << '\n';
    } else {
        cout << freq << ' ' << smallest_index << '\n';
    }


    return 0;
}