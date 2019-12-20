// https://www.nowcoder.com/practice/f350f14cd22c41aabfa7e54a1b8e8825?tpId=98

#include <iostream>
#include <list>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    list<int> A;
    char ch;
    int temp;
    do {
        cin >> temp;
        A.emplace_back(temp);
    } while (cin >> ch);

    bool firstItem = true;
    bool change = true;
    while (!A.empty()) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << ",";
        }
        if (change) {
            cout << A.front();
            A.pop_front();
            change = false;
        } else {
            cout << A.back();
            A.pop_back();
            change = true;
        }
    }
    cout << endl;
    return 0;
}