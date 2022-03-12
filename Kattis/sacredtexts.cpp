// https://open.kattis.com/problems/sacredtexts

#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

vector<string> parse(const string&s) {
    vector<string> vec;
    istringstream iss(s);
    string temp;
    do {
        iss >> temp;
        vec.emplace_back(temp);
    } while (iss);
    vec.pop_back();
    return vec;
}

int getSum(const string& s) {
    int sum = 0;
    for (auto& i : s) {
        sum += (int)(i - (char)32);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    char ch;
    cin >> s;
    int sum = getSum(s);
    cin >> s;
    ch = s[0];
    cin.get();
    int start = sum - (int)(ch - 'a');  // a
    int end = start + 25;               // z
    while (getline(cin, s)) {
        auto p = parse(s);
        string str;
        for (auto& i : p) {
            if (i[0] == '0') {
                str.push_back(' ');
            }
            else if (i[0] == '<') {
                str.push_back(',');
            }
            else if (i[0] == '>') {
                str.push_back('.');
            }
            else {
                int tempSum = getSum(i);
                while (tempSum > end) {
                    tempSum -= 26;
                }
                while (tempSum < start) {
                    tempSum += 26;
                }
                str.push_back(tempSum - start + 'a');
            }
        }
        cout << str << '\n';
    }
    return 0;
}
