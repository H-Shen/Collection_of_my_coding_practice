#include <bits/extc++.h>

using namespace std;

int main() {

    string s;
    getline(cin, s);
    cout << count_if(s.begin(), s.end(), [](const char &ch){
        return !isspace(ch);
    }) << endl;

    return 0;
}