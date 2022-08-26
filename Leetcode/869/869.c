#define N 10
#define MAXN (1e9+5)

bool reorderedPowerOf2(int n){
    int freq1[N];
    memset(freq1, 0, sizeof freq1);
    while (n > 0) {
        ++freq1[n % 10];
        n /= 10;
    }
    long long temp = 1;
    bool have_ans;
    while (true) {
        if (temp > MAXN) {
            break;
        }
        int freq2[N];
        memset(freq2, 0, sizeof freq2);
        long long temp_copy = temp;
        while (temp_copy > 0) {
            ++freq2[(int)(temp_copy % 10)];
            temp_copy /= 10;
        }
        have_ans = true;
        for (int i = 0; i < N; ++i) {
            if (freq1[i] != freq2[i]) {
                have_ans = false;
                break;
            }
        }
        if (have_ans) {
            return true;
        }
        temp *= 2LL;
    }
    return false;
}