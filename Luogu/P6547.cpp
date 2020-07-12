#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const regex r("[0-9]+");

int main(int argc, char *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    string s, temp;
    cin >> n;
    vector<string> output;

    while (n--) {
        cin >> s;
        for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
            temp = it->str();
            deque<char> temp_deque(temp.begin(), temp.end());
            while (temp_deque.size() > 1 && temp_deque.front() == '0') {
                temp_deque.pop_front();
            }
            output.emplace_back(temp_deque.begin(), temp_deque.end());
        }
    }
    sort(output.begin(), output.end(), [](const string &lhs, const string &rhs){
        if (lhs.size() == rhs.size()) {
            return lhs < rhs;
        }
        return (lhs.size() < rhs.size());
    });
    for (const auto &i : output) {
        cout << i << '\n';
    }

    return 0;
}