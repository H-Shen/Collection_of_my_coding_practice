#include <bits/stdc++.h>


using namespace std;

const int MAXN = 20;
char s[MAXN], s2[MAXN];

struct Node {
    int val;
    string currentAddress;
    string nextAddress;
};

int main() {
    int n, k;
    string currentAddress;

    scanf("%s %d %d", s, &n, &k);
    getchar();

    if (n == 0) {
        return 0;
    }

    currentAddress = s;
    int i;
    unordered_map<string, Node> save;
    Node tmp;

    for (i = 0; i < n; ++i) {
        scanf("%s %d %s", s, &tmp.val, s2);
        tmp.currentAddress = s;
        tmp.nextAddress = s2;
        save[tmp.currentAddress] = tmp;
    }

    vector<Node> A;
    while (true) {
        if (currentAddress == "-1") {
            break;
        }
        A.push_back(save[currentAddress]);
        currentAddress = save[currentAddress].nextAddress;
    }

    int cntA = A.size();
    if (cntA == 0) {
        printf("0 %s -1\n", s);
        return 0;
    }

    if (k >= cntA) {
        reverse(A.begin(), A.end());
    } else if (k > 0) {
        for (i = 0; i < cntA; i += k) {
            if (i + k - 1 >= cntA) break;
            reverse(A.begin() + i, A.begin() + i + k);
        }
    }

    for (i = 0; i < cntA - 1; ++i) {
        A[i].nextAddress = A[i + 1].currentAddress;
    }
    A[cntA - 1].nextAddress = "-1";
    for (i = 0; i < cntA; ++i) {
        printf("%s %d %s\n", A[i].currentAddress.c_str(), A[i].val, A[i].nextAddress.c_str());
    }
    return 0;
}