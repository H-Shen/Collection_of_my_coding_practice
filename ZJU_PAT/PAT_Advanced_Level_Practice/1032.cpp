#include <bits/stdc++.h>

using namespace std;

struct Node {
    string currentAddress;
    char currentVal;
    string nextAddress;

    bool operator==(const Node &other) const {
        return (currentAddress == other.currentAddress &&
                currentVal == other.currentVal &&
                nextAddress == other.nextAddress);
    }
};

bool commonSuffixHead(const vector<Node> &a, const vector<Node> &b, Node &firstCommonNode) {
    size_t minLen = min(a.size(), b.size());
    bool haveCommonSuffix = false;
    for (size_t i = 0; i < minLen; ++i) {
        if (a[a.size() - 1 - i] == b[b.size() - 1 - i]) {
            haveCommonSuffix = true;
            firstCommonNode = a[a.size() - 1 - i];
        }
    }
    return haveCommonSuffix;
}

vector<Node> filterString(unordered_map<string, Node> &nodeList, string headA) {
    vector<Node> filterA;
    while (headA != "-1") {
        filterA.emplace_back(nodeList[headA]);
        headA = nodeList[headA].nextAddress;
    }
    return filterA;
}

const int MAXN = 10;
char s0[MAXN], val, s1[MAXN];

int main() {

    int n;
    scanf("%s %s %d", s0, s1, &n);
    string headA = s0;
    string headB = s1;
    unordered_map<string, Node> nodeList;
    Node tmpNode;

    //input
    while (n--) {
        scanf("%s %c %s", s0, &val, s1);
        tmpNode.currentAddress = s0;
        tmpNode.currentVal = val;
        tmpNode.nextAddress = s1;
        nodeList[tmpNode.currentAddress] = tmpNode;
    }

    //filter
    vector<Node> filterA = filterString(nodeList, headA);
    vector<Node> filterB = filterString(nodeList, headB);

    //search and print
    Node res;
    if (commonSuffixHead(filterA, filterB, res)) {
        printf("%s\n", res.currentAddress.c_str());
    } else {
        printf("-1\n");
    }
    return 0;
}
