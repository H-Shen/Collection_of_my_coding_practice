#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

unordered_map<string, bool> teachers; // came: true leave: false
unordered_map<string, bool> students; // playing: true not playing: false

inline static
string join(const vector<string> &v, const char &str) {
    string s;
    for (auto p = cbegin(v); p != cend(v); ++p) {
        s.append(*p);
        if (p != cend(v) - 1) {
            s.push_back(str);
        }
    }
    return s;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // pre
    int n;
    cin >> n;
    string name;
    for (int i = 0; i < 3; ++i) {
        cin >> name;
        teachers[name] = false;
    }
    for (int i = 0; i < 5; ++i) {
        cin >> name;
        students[name] = false;
    }

    string s;
    string temp_str;
    bool teacher_check;
    unordered_set<string> students_been_checked;
    cin.get();
    bool update;
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        update = false;
        // check current status
        for (auto &j : teachers) {
            temp_str = j.first + " came!";
            if (s == temp_str) {
                j.second = true;
                update = true;
                break;
            }
            temp_str = j.first + " left!";
            if (s == temp_str) {
                j.second = false;
                update = true;
                break;
            }
        }
        if (!update) {
            for (auto &j : students) {
                temp_str = j.first + " started playing games!";
                if (s == temp_str) {
                    j.second = true;
                    break;
                }
                temp_str = j.first + " stopped playing games!";
                if (s == temp_str) {
                    j.second = false;
                    break;
                }
            }
        }
        teacher_check = false;
        for (const auto &j : teachers) {
            if (j.second) {
                teacher_check = true;
                break;
            }
        }
        if (teacher_check) {
            for (const auto &j : students) {
                if (j.second) {
                    students_been_checked.insert(j.first);
                }
            }
        }
    }
    // output
    if (students_been_checked.empty()) {
        cout << "How Good Oiers Are!\n";
    } else {
        vector<string> p;
        for (const auto &i : students_been_checked) {
            p.emplace_back(i);
        }
        sort(p.begin(), p.end());
        cout << join(p, ' ') << '\n';
        if (students_been_checked.size() == 5) {
            cout << "How Bad Oiers Are!\n";
        }
    }
    return 0;
}
