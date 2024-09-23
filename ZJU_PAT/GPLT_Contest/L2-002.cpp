#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

struct Node {
    int val;
    string currentAddress;
    string nextAddress;
};

const int maxn = 100;
char cstr[maxn], cstr1[maxn];

int main() {

    int n, i;
    gp_hash_table<string, Node> allNodeList;
    scanf("%s %d", cstr, &n);
    string headNodeAddress = cstr;

    while (n--) {
        Node tmp;
        scanf("%s %d %s", cstr, &tmp.val, cstr1);
        tmp.currentAddress = cstr;
        tmp.nextAddress = cstr1;
        allNodeList[tmp.currentAddress] = tmp;
    }

    vector<Node> nodeList;
    int nodeListLen = 0;
    Node currentNode = allNodeList[headNodeAddress];

    while (true) {
        nodeList.emplace_back(currentNode);
        ++nodeListLen;
        if (currentNode.nextAddress == "-1") {
            break;
        }
        currentNode = allNodeList[currentNode.nextAddress];
    }

    unordered_set<int> uniqueNumberSet;
    vector<Node> partition0, partition1;
    int partition0_len = 0, partition1_len = 0;

    for (i = 0; i < nodeListLen; ++i) {
        if (uniqueNumberSet.find(abs(nodeList[i].val)) == uniqueNumberSet.end()) {
            uniqueNumberSet.insert(abs(nodeList[i].val));
            partition0.emplace_back(nodeList[i]);
            ++partition0_len;
        } else {
            partition1.emplace_back(nodeList[i]);
            ++partition1_len;
        }
    }
    //partition0
    if (partition0_len == 1) {
        partition0[0].nextAddress = "-1";
        printf("%s %d %s\n", partition0[0].currentAddress.c_str(), partition0[0].val,
               partition0[0].nextAddress.c_str());
    } else {
        for (i = 0; i < partition0_len - 1; ++i) {
            partition0[i].nextAddress = partition0[i + 1].currentAddress;
            printf("%s %d %s\n", partition0[i].currentAddress.c_str(), partition0[i].val,
                   partition0[i].nextAddress.c_str());
        }
        partition0[partition0_len - 1].nextAddress = "-1";
        printf("%s %d %s\n", partition0[partition0_len - 1].currentAddress.c_str(), partition0[partition0_len - 1].val,
               partition0[partition0_len - 1].nextAddress.c_str());
    }

    //partition1
    if (partition1_len == 0) {
        return 0;
    }
    if (partition1_len == 1) {
        partition1[0].nextAddress = "-1";
        printf("%s %d %s\n", partition1[0].currentAddress.c_str(), partition1[0].val,
               partition1[0].nextAddress.c_str());
    } else {
        for (i = 0; i < partition1_len - 1; ++i) {
            partition1[i].nextAddress = partition1[i + 1].currentAddress;
            printf("%s %d %s\n", partition1[i].currentAddress.c_str(), partition1[i].val,
                   partition1[i].nextAddress.c_str());
        }

        partition1[partition1_len - 1].nextAddress = "-1";
        printf("%s %d %s\n", partition1[partition1_len - 1].currentAddress.c_str(), partition1[partition1_len - 1].val,
               partition1[partition1_len - 1].nextAddress.c_str());
    }
    return 0;
}