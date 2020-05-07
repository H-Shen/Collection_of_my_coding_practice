extern "C" int Seniorious(int);

extern "C" int Chtholly(int n, int c) {
    int low = 1;
    int high = n;
    int ans = 1;
    int mid;
    int temp;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        temp = Seniorious(mid);
        if (temp == 1) {
            high = mid - 1;
        } else if (temp == -1) {
            low = mid + 1;
        } else if (temp == 0) {
            ans = mid;
            break;
        }
    }
    return ans;
}
