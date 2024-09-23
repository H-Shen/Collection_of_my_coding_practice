#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    // input
    int N;
    cin >> N;
    vector<int> startState(N);
    vector<int> midState(N);

    for (auto &&i : startState) {
        cin >> i;
    }
    for (auto &&i : midState) {
        cin >> i;
    }

    vector<int> startStateCopy = startState;

    // insertionSort
    int k = 2;
    bool isFind = false;
    for (; k < N; k++) {
        sort(startState.begin(), startState.begin() + k);
        if (startState == midState) {
            isFind = true;
            break;
        }
    }

    if (isFind) {
        cout << "Insertion Sort" << endl;
        while (startState == midState) {
            sort(startState.begin(), startState.begin() + k + 1);
            k++;
        }
        for (int i = 0; i < N - 1; i++) {
            cout << startState[i] << " ";
        }
        cout << startState[N - 1];
        return 0;
    }

    // mergeSort
    k = 2;
    vector<int>::iterator iter;
    while (k < N) {
        iter = startStateCopy.begin();
        for (int i = 0; i < (N / k); i++) {
            sort(iter, iter + k);
            iter += k;
        }
        sort(iter, startStateCopy.end());
        k *= 2;
        if (startStateCopy == midState) {
            isFind = true;
            break;
        }
    }
    if (isFind) {
        cout << "Merge Sort" << endl;
        while (startStateCopy == midState) {
            iter = startStateCopy.begin();
            for (int i = 0; i < (N / k); i++) {
                sort(iter, iter + k);
                iter += k;
            }
            sort(iter, startStateCopy.end());
            k *= 2;
        }
        for (int i = 0; i < N - 1; i++) {
            cout << startStateCopy[i] << " ";
        }
        cout << startStateCopy[N - 1];
    }
    return 0;
}