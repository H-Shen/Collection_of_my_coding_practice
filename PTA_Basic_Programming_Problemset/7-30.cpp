#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<string> &a, int k) {

    if (a.size() <= 1) {
        return;
    }
    int n = static_cast<int>(a.size());
    string temp;
    bool swapFlag;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (count == k) {
            break;
        }
        swapFlag = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapFlag = true;
            }
        }
        ++count;
        if (!swapFlag) {
            return;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<string> a(static_cast<size_t>(n));
    for (auto &&i : a) {
        cin >> i;
    }

    bubbleSort(a, k);
    for (const auto &i : a) {
        cout << i << endl;
    }
}