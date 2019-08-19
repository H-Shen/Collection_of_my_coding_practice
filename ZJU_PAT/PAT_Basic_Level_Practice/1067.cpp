#include <bits/stdc++.h>

using namespace std;

int main() {
    string password, input;
    int tryTime;
    int cnt = 0;
    cin >> password >> tryTime;
    getchar();

    vector<string> inputList;
    while (getline(cin, input) && input != "#") {
        inputList.push_back(input);
    }

    for (const auto &i : inputList) {
        if (i == password) {
            cout << "Welcome in" << endl;
            break;
        } else {
            cout << "Wrong password: " << i << endl;
            ++cnt;
            if (cnt == tryTime) {
                cout << "Account locked" << endl;
                break;
            }
        }
    }
    return 0;
}