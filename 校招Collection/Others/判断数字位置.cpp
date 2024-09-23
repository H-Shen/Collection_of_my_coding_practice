// https://www.nowcoder.com/practice/55d5708cd4ab472b9c2969f9846f32ec

#include <cctype>
#include <string>
#include <iostream>

using namespace std;

int main() {

    int m;
    string s;
    bool firstItem;
    cin >> m;
    cin.get();
    while (m--) {
        getline(cin, s);
        firstItem = true;
        for (size_t i = 0; i != s.size(); ++i) {
            if (isdigit(s.at(i))) {
                if (firstItem) {
                    firstItem = false;
                } else {
                    cout << " ";
                }
                cout << i + 1;
            }
        }
        cout << endl;
    }

    return 0;
}