// https://www.nowcoder.com/practice/849b9e545f4742398d278f5dc4e003d2

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    unordered_map<int, int> freq;
    int n, temp;
    cin >> n;
    while (n--) {
        cin >> temp;
        ++freq[temp];
    }

    for (const auto &it : freq) {
        if (it.second % 2 != 0) {
            cout << it.first << endl;
            return 0;
        }
    }
    return 0;
}