// https://www.nowcoder.com/practice/44da6966beb449d383f62b12e8df6317

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    string result;
    char lastChar = s[0];
    int counter = 1;
    int len = static_cast<int>(s.size());
    for (int i = 1; i < len; ++i) {
        if (s[i] == lastChar) {
            ++counter;
        } else {
            result += to_string(counter) + lastChar;
            lastChar = s[i];
            counter = 1;
        }
    }
    result += to_string(counter) + lastChar;
    cout << result << endl;
    return 0;
}