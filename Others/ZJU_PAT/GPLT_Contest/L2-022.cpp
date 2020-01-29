#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    string currentAddress;
    string nextAddress;
};

const int maxn = 100;
char cstr[maxn], cstr1[maxn];

int main() {

    int n;
    unordered_map<string, Node> allNodeList;
    scanf("%s %d", cstr, &n);
    string headNodeAddress = cstr;

    while (n--) {
        Node tmp;
        scanf("%s %d %s", cstr, &tmp.val, cstr1);
        tmp.currentAddress = cstr;
        tmp.nextAddress = cstr1;
        allNodeList[tmp.currentAddress] = tmp;
    }

    deque<Node> nodeList;
    int nodeListLen = 0;
    Node currentNode = allNodeList[headNodeAddress];

    while (true) {
        nodeList.push_back(currentNode);
        ++nodeListLen;
        if (currentNode.nextAddress == "-1") {
            break;
        }
        currentNode = allNodeList[currentNode.nextAddress];
    }

    //RESORT
    vector<Node> resort(nodeListLen);
    int i = 0;
    bool change = false;

    while (!nodeList.empty()) {
        if (!change) {
            resort[i] = nodeList.back();
            nodeList.pop_back();
            change = true;
        } else {
            resort[i] = nodeList.front();
            nodeList.pop_front();
            change = false;
        }
        ++i;
    }

    for (i = 0; i < nodeListLen - 1; ++i) {
        resort[i].nextAddress = resort[i + 1].currentAddress;
        printf("%s %d %s\n", resort[i].currentAddress.c_str(), resort[i].val, resort[i].nextAddress.c_str());
    }
    resort[nodeListLen - 1].nextAddress = "-1";
    printf("%s %d %s\n", resort[nodeListLen - 1].currentAddress.c_str(), resort[nodeListLen - 1].val,
           resort[nodeListLen - 1].nextAddress.c_str());

    return 0;
}