// https://open.kattis.com/problems/keylogger

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

unordered_map<string, char> unmap;
bool isUpper = false;

int main() {
    unmap["clank"] = 'A';
    unmap["bong"] = 'B';
    unmap["click"] = 'C';
    unmap["tap"] = 'D';
    unmap["poing"] = 'E';
    unmap["clonk"] = 'F';
    unmap["clack"] = 'G';
    unmap["ping"] = 'H';
    unmap["tip"] = 'I';
    unmap["cloing"] = 'J';
    unmap["tic"] = 'K';
    unmap["cling"] = 'L';
    unmap["bing"] = 'M';
    unmap["pong"] = 'N';
    unmap["clang"] = 'O';
    unmap["pang"] = 'P';
    unmap["clong"] = 'Q';
    unmap["tac"] = 'R';
    unmap["boing"] = 'S';
    unmap["boink"] = 'T';
    unmap["cloink"] = 'U';
    unmap["rattle"] = 'V';
    unmap["clock"] = 'W';
    unmap["toc"] = 'X';
    unmap["clink"] = 'Y';
    unmap["tuc"] = 'Z';
    unmap["whack"] = ' ';

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s, ans;
    while (n--) {
        cin >> s;
        if (s == "pop") {
            if (!ans.empty()) {
                ans.pop_back();
            }
        }
        else if (s == "dink" || s == "thumb" || s == "bump") {
            isUpper = !isUpper;
        }
        else {
            if (isUpper) {
                ans.push_back(unmap[s]);
            } else {
                ans.push_back(tolower(unmap[s]));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
