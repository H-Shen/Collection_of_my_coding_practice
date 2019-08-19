#include <bits/stdc++.h>

using namespace std;

const int maxn = 105, gap = '0';
char s0[maxn], s1[maxn];

struct Node {
    string curAdd;
    int val;
    string nextAdd;
};

void nodeReverse(vector<Node> &A, int k, int len) {
    int i;
    for (i = 0; i < len; i += k) {
        if (i + k - 1 >= len) {
            break;
        }
        reverse(A.begin() + i, A.begin() + i + k);
    }
}

void nodeOrder(vector<Node> &A, int len) {
    int i;
    for (i = 0; i < len - 1; ++i) {
        A[i].nextAdd = A[i + 1].curAdd;
    }
    A[len - 1].nextAdd = "-1";
}

int main() {
    string curAdd;
    int n, k, i;
    scanf("%s %d %d", s0, &n, &k);
    curAdd = s0;

    unordered_map<string, Node> input;

    Node tmp;
    for (i = 0; i < n; ++i) {
        scanf("%s %d %s", s0, &tmp.val, s1);
        tmp.curAdd = s0;
        tmp.nextAdd = s1;
        input[tmp.curAdd] = tmp;
    }

    vector<Node> nodeList;
    while (true) {
        nodeList.push_back(input[curAdd]);
        if (input[curAdd].nextAdd == "-1") {
            break;
        }
        curAdd = input[curAdd].nextAdd;
    }

    int len = nodeList.size();
    if (len > 0) {
        nodeReverse(nodeList, k, len);
        nodeOrder(nodeList, len);
        for (i = 0; i < len; ++i) {
            printf("%s %d %s\n", nodeList[i].curAdd.c_str(), nodeList[i].val,
                   nodeList[i].nextAdd.c_str());
        }
    }
    return 0;
}