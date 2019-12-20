// https://www.nowcoder.com/practice/2ff3d36b4d4a4bfeb1a7d64f3cc55c15

#include <iostream>
#include <string>

using namespace std;

int main() {

    string s;
    getline(cin, s);
    string result;
    char lastChar = s[0];
    int counter = 1;
    int len = static_cast<int>(s.size());
    for (int i = 1; i < len; ++i) {
        if (s[i] == lastChar) {
            ++counter;
        } else {
            if (counter != 1) {
                result += to_string(counter - 1) + lastChar;
                lastChar = s[i];
                counter = 1;
            } else {
                result += lastChar;
                lastChar = s[i];
            }
        }
    }
    if (counter != 1) {
        result += to_string(counter - 1) + lastChar;
    } else {
        result += lastChar;
    }
    cout << result << endl;
    return 0;
}