// https://www.nowcoder.com/practice/28d5a9b7fc0b4a078c9a6d59830fb9b9

int bSearch(const vector<int> &A, int n, int key) {
    int low = 0;
    int high = n - 1;
    while (true) {
        if (low > high) {
            return -1;
        }
        int mid = (low + high) / 2;
        if (key < A[mid]) {
            high = mid - 1;
        } else if (key > A[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
}

int lowerBound(const vector<int> &A, int n, int key) {
    int low = 0;
    int high = n;
    while (true) {
        if (low >= high) {
            return low;
        }
        int mid = (low + high) / 2;
        if (key <= A[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
}

class BinarySearch {
public:
    int getPos(vector<int> A, int n, int val) {
        // write code here
        return (bSearch(A, n, val) != -1) ? lowerBound(A, n, val) : -1;
    }
};