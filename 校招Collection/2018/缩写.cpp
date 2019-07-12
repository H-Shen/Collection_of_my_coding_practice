// https://www.nowcoder.com/practice/45083499b8c5404fb1db44c6ea4f170a

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    string input;
    string result;
    getline(cin, input);
    istringstream f(input);
    string s;
    while (getline(f, s, ' ')) {
        result += s[0];
    }
    cout << result << endl;
    return 0;
}