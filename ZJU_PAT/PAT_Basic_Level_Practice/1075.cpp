#include <bits/stdc++.h>

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

    while (true) {

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

    // for loop unrolling
    try {
        for (i = 0; i < len3; i += 10) {
            printf("%s %d %s\n", result.at(i).currentAddress.c_str(), result.at(i).val,
                   result.at(i).nextAddress.c_str());
            printf("%s %d %s\n", result.at(i + 1).currentAddress.c_str(), result.at(i + 1).val,
                   result.at(i + 1).nextAddress.c_str());
            printf("%s %d %s\n", result.at(i + 2).currentAddress.c_str(), result.at(i + 2).val,
                   result.at(i + 2).nextAddress.c_str());
            printf("%s %d %s\n", result.at(i + 3).currentAddress.c_str(), result.at(i + 3).val,
                   result.at(i + 3).nextAddress.c_str());
            printf("%s %d %s\n", result.at(i + 4).currentAddress.c_str(), result.at(i + 4).val,
                   result.at(i + 4).nextAddress.c_str());
            printf("%s %d %s\n", result.at(i + 5).currentAddress.c_str(), result.at(i + 5).val,
                   result.at(i + 5).nextAddress.c_str());
            printf("%s %d %s\n", result.at(i + 6).currentAddress.c_str(), result.at(i + 6).val,
                   result.at(i + 6).nextAddress.c_str());
            printf("%s %d %s\n", result.at(i + 7).currentAddress.c_str(), result.at(i + 7).val,
                   result.at(i + 7).nextAddress.c_str());
            printf("%s %d %s\n", result.at(i + 8).currentAddress.c_str(), result.at(i + 8).val,
                   result.at(i + 8).nextAddress.c_str());
            printf("%s %d %s\n", result.at(i + 9).currentAddress.c_str(), result.at(i + 9).val,
                   result.at(i + 9).nextAddress.c_str());
        }
    } catch (...) {}
    return 0;
}