#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int MAXN = 20;
char s[MAXN], s2[MAXN];

struct Node {
    int val = -1;
    string currentAddress;
    string nextAddress;
};

int main() {

    int n, k;
    string currentAddress;
    scanf("%s %d %d", s, &n, &k);
    getchar_unlocked();

    if (n == 0) {
        return 0;
    }

    currentAddress = s;
    int i;
    gp_hash_table<string, Node> save;
    Node tmp;

    for (i = 0; i < n; ++i) {
        scanf("%s %d %s", s, &tmp.val, s2);
        tmp.currentAddress = s;
        tmp.nextAddress = s2;
        save[tmp.currentAddress] = tmp;
    }

    vector<Node> A;
    vector<Node> B;
    vector<Node> C;

    while (true) {
        if (currentAddress == "-1") {
            break;
        }
        if (save[currentAddress].val < 0) {
            A.emplace_back(save[currentAddress]);
        } else if (save[currentAddress].val <= k) {
            B.emplace_back(save[currentAddress]);
        } else {
            C.emplace_back(save[currentAddress]);
        }
        currentAddress = save[currentAddress].nextAddress;
    }


    copy(B.begin(), B.end(), back_inserter(A));
    copy(C.begin(), C.end(), back_inserter(A));

    int cntA = static_cast<int>(A.size());
    if (cntA == 0) {
        printf("0 %s -1\n", s);
        return 0;
    }
    for (i = 0; i < cntA - 1; ++i) {
        A[i].nextAddress = A[i + 1].currentAddress;
    }
    A[cntA - 1].nextAddress = "-1";
    for (i = 0; i < cntA; ++i) {
        printf("%s %d %s\n", A[i].currentAddress.c_str(), A[i].val,
               A[i].nextAddress.c_str());
    }

    return 0;
}