#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int main() {

    string s;
    getline(cin, s);
    int length = static_cast<int>(s.size());
    int counter = 0;
    for (int i = 0; i < length; ++i) {
        if (counter == 0 && s[i] == 'C') {
            ++counter;
        }
        if (counter == 1 && s[i] == 'F') {
            ++counter;
        }
    }
    if (counter == 2) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}
