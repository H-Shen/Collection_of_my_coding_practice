#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ull = unsigned long long;

constexpr ull HASH = 100003;
constexpr int MAXN = 10005;

struct HashMap {
    int head[HASH];
    int next[MAXN];
    int Size;
    ull state[MAXN];
    int f[MAXN];
    void init() {
        Size = 0;
        memset(head, -1, sizeof(head));
    }
    int put(ull key, int value) {
        int h = (int)(key % HASH);
        for (int i = head[h]; i != -1; i = next[i]) {
            if (key == state[i]) {
                int temp = f[i];
                f[i] = value;
                return temp;    // Return the old value, and update it with the new value
            }
        }
        // Key not found, add it to the hashmap, and return 0
        f[Size] = value;
        state[Size] = key;
        next[Size] = head[h];
        head[h] = Size;
        ++Size;
        return 0;
    }
};

HashMap H;

constexpr ull SEED = 13331;
ull P[MAXN];
ull S[MAXN];
char cstr[MAXN];

ull get_hash(int l, int r) {
    return S[r] - S[l - 1] * P[r - l + 1];
}

int main() {

    // pre
    P[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        P[i] = P[i - 1] * SEED;
    }
    H.init();

    int t, length;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", cstr);
        length = static_cast<int>(strlen(cstr));
        S[0] = 0;
        for (int i = 1; i <= length; ++i) {
            S[i] = S[i - 1] * SEED + cstr[i - 1];
        }
        H.put(get_hash(1, length), 1);  // 1 is a dummy data here
    }
    printf("%d\n", H.Size);

    return 0;
}
