#define N 26

int firstUniqChar(char * s){
    int freq[N];
    memset(freq, 0, sizeof freq);
    for (int i = 0; s[i] != 0; ++i) {
        ++freq[s[i] - 'a'];
    }
    for (int i = 0; s[i] != 0; ++i) {
        if (freq[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}