#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s, a;
    while (getline(cin, a)) {
        s += a + '\n';
    }

    bool a1 = static_cast<bool>(strstr(s.c_str(), "#include"));
    bool a2 = static_cast<bool>(strstr(s.c_str(), "import java"));

    if (a1)
        cout << "C" << endl;
    else if (a2)
        cout << "Java" << endl;
    else
        cout << "Python" << endl;
    return 0;
}
