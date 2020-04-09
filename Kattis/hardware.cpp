// https://open.kattis.com/problems/hardware
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline static
std::vector<std::string> splitByChar(std::string s, const char &delim) {
    std::vector<std::string> res;
    std::istringstream f(s);
    std::string temp;
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

bool is_digits(const string &s) {
    for (const char &ch : s) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

bool is_house_number(const vector<string> &p) {
    if (p.size() == 1 && is_digits(p.front())) {
        return true;
    }
    if (p.size() == 4 && p.front() == "+" && is_digits(p[1]) && is_digits(p[2]) && is_digits(p[3])) {
        return true;
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    cin.get();
    string roadName;
    string nextRoadName;
    getline(cin, roadName);
    while (n--) {
        if (!nextRoadName.empty()) {
            roadName = nextRoadName;
        }
        int building;
        string building_str;
        cin >> building >> building_str;
        cin.get();
        building_str = to_string(building) + ' ' + building_str;
        string s;
        string total;
        while (true) {
            getline(cin, s);
            auto p = splitByChar(s, ' ');
            if (!is_house_number(p)) {
                nextRoadName = s;
                break;
            }
            // Case 1:
            if (p.size() == 1) {
                total += p.front();
            }
            // Case 2:
            else {
                int startNumber = stoi(p[1]);
                int endNumber = stoi(p[2]);
                int interval = stoi(p[3]);
                for (int i = startNumber; i <= endNumber; i += interval) {
                    total += to_string(i);
                }
            }
        }
        cout << roadName << '\n';
        cout << building_str << '\n';
        vector<int> stats(10);
        for (const char &ch : total) {
            ++stats.at(ch - '0');
        }
        for (int i = 0; i < 10; ++i) {
            cout << "Make " << stats.at(i) << " digit " << i << '\n';
        }
        if (total.size() == 1) {
            cout << "In total 1 digit" << '\n';
        } else {
            cout << "In total " << total.size() << " digits" << '\n';
        }
    }

    return 0;
}
