// https://open.kattis.com/problems/whatdoesthefoxsay
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
inline regex r("[a-z]+");

vector<string> split(const string &s) {
    vector<string> A;
    for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
        A.emplace_back(it->str());
    }
    return A;
}

string join(const vector<string> &A, const string &s) {
    string result;
    bool first_item = true;
    for (const auto &i : A) {
        if (first_item) {
            first_item = false;
        } else {
            result += s;
        }
        result += i;
    }
    return result;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    string str, a;
    cin >> n;
    cin.get();
    while (n--) {
        getline(cin, str);
        auto s = split(str);
        unordered_set<string> Set;
        while (true) {
            getline(cin, a);
            if (a == "what does the fox say?") {
                break;
            }
            auto p = split(a);
            Set.insert(p.at(2));
        }
        vector<string> s_new;
        for (const string &i : s) {
            if (Set.find(i) == Set.end()) {
                s_new.emplace_back(i);
            }
        }
        cout << join(s_new, " ") << '\n';
    }

    return 0;
}
