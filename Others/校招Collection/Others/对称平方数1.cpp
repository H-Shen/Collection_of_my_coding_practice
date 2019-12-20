// https://www.nowcoder.com/practice/a84d46d5321f4e20931cb725e6c74fad

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

inline
bool isSquare(int n) {
    int temp = n * n;
    string temp_str = to_string(temp);
    string temp_str_copy = temp_str;
    reverse(temp_str.begin(), temp_str.end());
    return (temp_str_copy == temp_str);
}

int main() {
    for (int i = 0; i <= 256; ++i) {
        if (isSquare(i)) {
            cout << i << endl;
        }
    }
}