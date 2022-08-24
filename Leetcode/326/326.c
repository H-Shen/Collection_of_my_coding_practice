

bool isPowerOfThree(int n){
    if (n == INT_MAX || n == INT_MIN || n <= 0) {
        return false;
    }
    int l = 0;
    int r = 19;
    int mid;
    int temp;
    while (l <= r) {
        mid = l + ((r-l)>>1);
        temp = pow(3, mid);
        if (temp == n) {
            return true;
        }
        else if (temp > n) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return false;
}