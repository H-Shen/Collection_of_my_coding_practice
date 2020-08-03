#include <string>
#include <unordered_map>

using namespace std;

constexpr int maxn = 200005;
constexpr int max_str_length = 10;
char a[max_str_length];
char b[max_str_length];

int father[maxn]; // Father nodes
int people[maxn]; // Elements in every set
int Rank[maxn]; // Rank

int find(int x) {
    if (x != father[x])
        father[x] = find(father[x]);

    return father[x];
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (Rank[x] > Rank[y]) {
        father[y] = x;
        if (x != y)
            people[x] += people[y];
    } else {
        father[x] = y;
        if (x != y)
            people[y] += people[x];

        if (Rank[x] == Rank[y])
            Rank[y] += 1;
    }
}


void reset(int n) {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        people[i] = 1;
        Rank[i] = 0;
    }
}

int main() {

    int T, pair, counter, a_id, b_id;
    string a_str, b_str;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &pair);
        reset(maxn - 3);
        unordered_map<string, int> nameToId;
        counter = 1;
        while (pair--) {
            scanf("%s %s", a, b);
            a_str = a;
            b_str = b;
            if (nameToId.find(a_str) == nameToId.end()) {
                nameToId[a_str] = counter;
                a_id = counter;
                ++counter;
            } else {
                a_id = nameToId[a_str];
            }
            if (nameToId.find(b_str) == nameToId.end()) {
                nameToId[b_str] = counter;
                b_id = counter;
                ++counter;
            } else {
                b_id = nameToId[b_str];
            }
            merge(a_id, b_id);
            printf("%d\n", people[find(a_id)]);
        }
    }

    return 0;
}