// https://www.nowcoder.com/practice/678417477f424f8f8f97c54941abf631

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10;

bool isRoot(int x) {
    return (x == 0);
}

int parent(int x) {
    if (x == 0) {
        throw out_of_range("");
    } else {
        return (x - 1) / 2;
    }
}

void bubbleUp(int x, vector<int> &A) {
    while (!isRoot(x)) {
        if (A.at(x) > A.at(parent(x))) {
            int temp = A.at(x);
            A.at(x) = A.at(parent(x));
            A.at(parent(x)) = temp;
            x = parent(x);
        } else {
            break;
        }
    }
}

bool hasLeft(int x, int heapSize) {
    return (2 * x + 1 < heapSize);
}

int left(int x, int heapSize) {
    if (hasLeft(x, heapSize)) {
        return 2 * x + 1;
    }
    throw out_of_range("");
}

bool hasRight(int x, int heapSize) {
    return (2 * x + 2 < heapSize);
}

int right(int x, int heapSize) {
    if (hasRight(x, heapSize)) {
        return 2 * x + 2;
    } else {
        throw out_of_range("");
    }
}

void bubbleDown(int x, int heapSize, vector<int> &A) {
    while (hasLeft(x, heapSize)) {
        if (hasRight(x, heapSize)) {
            if (A.at(left(x, heapSize)) >= A.at(right(x, heapSize))) {
                if (A.at(left(x, heapSize)) > A.at(x)) {
                    int temp = A.at(left(x, heapSize));
                    A.at(left(x, heapSize)) = A.at(x);
                    A.at(x) = temp;
                    x = left(x, heapSize);
                } else {
                    break;
                }
            } else if (A.at(right(x, heapSize)) > A.at(x)) {
                int temp = A.at(right(x, heapSize));
                A.at(right(x, heapSize)) = A.at(x);
                A.at(x) = temp;
                x = right(x, heapSize);
            } else {
                break;
            }
        } else {
            if (A.at(left(x, heapSize)) > A.at(x)) {
                int temp = A.at(left(x, heapSize));
                A.at(left(x, heapSize)) = A.at(x);
                A.at(x) = temp;
                x = left(x, heapSize);
            } else {
                break;
            }
        }
    }
}

void heapSort(vector<int> &A) {
    try {
        int heapSize = 1;
        int i = 1;
        int len = A.size();

        while (i < len) {
            if (heapSize < len) {
                int x = heapSize;
                A.at(x) = A.at(i);
                ++heapSize;
                bubbleUp(x, A);
            } else {
                throw out_of_range("");
            }
            ++i;
        }

        i = len - 1;

        while (i > 0) {
            int largest;
            if (heapSize == 0) {
                throw out_of_range("");
            } else {
                int temp = A.at(heapSize - 1);
                --heapSize;
                if (heapSize == 0) {
                    largest = temp;
                } else {
                    largest = A.at(0);
                    A.at(0) = temp;
                    bubbleDown(0, heapSize, A);
                }
            }
            A.at(i) = largest;
            --i;
        }
    } catch (...) {
        return;
    }
}

int main() {

    ios_base::sync_with_stdio(false);

    vector<int> A;
    int temp;
    while (cin >> temp) {
        A.push_back(temp);
    }
    heapSort(A);
    for (const auto &i : A) {
        cout << i << endl;
    }

    return 0;
}
