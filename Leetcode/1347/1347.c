#define N 26

int minSteps(char * s, char * t){
    int freq1[N];
    memset(freq1, 0, sizeof(freq1));
    int freq2[N];
    memset(freq2, 0, sizeof(freq2));
    for (int i = 0; s[i] != 0; ++i) {
        ++freq1[s[i] - 'a'];
    }
    for (int i = 0; t[i] != 0; ++i) {
        ++freq2[t[i] - 'a'];
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (freq1[i] < freq2[i]) {
            ans += freq2[i] - freq1[i];
        }
    }
    return ans;
}