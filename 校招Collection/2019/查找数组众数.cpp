// https://www.nowcoder.com/practice/3584a44114ea4805a9f6814e99285835

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {

    char ch;
    cin >> ch;
    int temp;
    unordered_map<int, int> A;
    while (true) {
        cin >> temp;
        ++A[temp];
        cin >> ch;
        if (ch == ']') {
            break;
        }
    }

    auto maxPair = max_element(begin(A), end(A),
                               [](const pair<int, int> &p1, const pair<int, int> &p2) {
                                   return p1.second < p2.second;
                               });

    cout << maxPair->first << endl;
    return 0;
}