#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> parseInts(string str) {
    int temp;
    char tempChar;
    stringstream ss(str);
    vector<int> res;
    while (ss >> temp) {
        res.emplace_back(temp);
        ss >> tempChar;
    }
    return res;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
