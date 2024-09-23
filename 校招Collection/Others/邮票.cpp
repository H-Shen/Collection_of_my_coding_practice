// https://www.nowcoder.com/practice/b6735b1bd4ff488fb9a9032457410f66

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

    unordered_set<int> A;
    for (int x = 0; x <= 5; ++x) {
        for (int y = 0; y <= 4; ++y) {
            for (int z = 0; z <= 6; ++z) {
                A.insert(8 * x + 10 * y + 18 * z);
            }
        }
    }
    // There must be at least 1 stamp.
    A.erase(0);
    cout << A.size() << endl;
    return 0;
}