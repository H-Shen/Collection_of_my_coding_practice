#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<int, string> k = {{3, "three"},
                                {5, "five"},
                                {7, "seven"},
                                {6, "six"},
                                {1, "one"},
                                {9, "nine"},
                                {8, "eight"},
                                {4, "four"},
                                {2, "two"}};

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        if (i > 9) {
            if (i & 1)
                cout << "odd" << endl;
            else
                cout << "even" << endl;
        } else {
            cout << k[i] << endl;
        }
    }
    return 0;
}
