#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>
#include <unordered_map>

using namespace std;

const int MAXN = 10;
char s[MAXN], s1[MAXN];

struct Node {
    string currentAddress;
    int val;
    string nextAddress;
};

int main() {

    unordered_map<string, Node> inputNode;
    int n, k, tmp;
    scanf("%s %d %d", s, &n, &k);
    string headAddress = s;

    Node currentNode;
    while (n--) {
        scanf("%s %d %s", s, &tmp, s1);
        currentNode.currentAddress = s;
        currentNode.val = tmp;
        currentNode.nextAddress = s1;
        inputNode[currentNode.currentAddress] = currentNode;
    }

    vector<Node> negativeNode;
    vector<Node> zeroToK;
    vector<Node> largerThanK;
    string currentAdd = headAddress;

    while (1) {

        if (inputNode[currentAdd].val > k) {
            largerThanK.push_back(inputNode[currentAdd]);
        } else if (inputNode[currentAdd].val < 0) {
            negativeNode.push_back(inputNode[currentAdd]);
        } else {
            zeroToK.push_back(inputNode[currentAdd]);
        }
        if (inputNode[currentAdd].nextAddress == "-1") {
            break;
        }
        currentAdd = inputNode[currentAdd].nextAddress;
    }

    int len0 = static_cast<int>(negativeNode.size());
    int len1 = static_cast<int>(zeroToK.size());
    int len2 = static_cast<int>(largerThanK.size());
    int len3 = len0 + len1 + len2;

    vector<Node> result(static_cast<size_t>(len3));
    int i, j;
    for (i = 0; i < len0; ++i) {
        result[i] = negativeNode[i];
    }
    for (j = 0; j < len1; ++j) {
        result[i] = zeroToK[j];
        ++i;
    }
    for (j = 0; j < len2; ++j) {
        result[i] = largerThanK[j];
        ++i;
    }

    for (i = 0; i < len3 - 1; ++i) {
        result[i].nextAddress = result[i + 1].currentAddress;
    }

    result[len3 - 1].nextAddress = "-1";

    for (i = 0; i < len3; ++i) {
        printf("%s %d %s\n", result[i].currentAddress.c_str(), result[i].val, result[i].nextAddress.c_str());
    }
    return 0;
}