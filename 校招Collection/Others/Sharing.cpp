// https://www.nowcoder.com/practice/2577bea713cf4eed874afccff1928113

#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char val{};
    string address;
    string nextNodeAddress;
};

unordered_map<string, Node> A;
vector<Node> B, C;
string strB, strC;

int posSuffix(string &A, string &B) {
    int pos = 0;
    auto itA = A.end(), itB = B.end();
    --itA;
    --itB;
    while (*itA == *itB) {
        --itA;
        --itB;
        ++pos;
    }
    return pos;
}

int main() {

    ios::sync_with_stdio(false);
    int n, i, len_B, len_C, pos;
    string headAddress0, headAddress1, currentAddress;

    while (cin >> headAddress0 >> headAddress1 >> n) {

        for (i = 0; i < n; i++) {
            Node tmp;
            cin >> tmp.address >> tmp.val >> tmp.nextNodeAddress;
            A[tmp.address] = tmp;
        }
        len_B = 0, len_C = 0;

        //Linked List B
        currentAddress = headAddress0;
        while (true) {
            if (A.find(currentAddress) == A.end()) {
                break;
            }
            B.push_back(A[currentAddress]);
            len_B++;
            currentAddress = A[currentAddress].nextNodeAddress;
        }

        //Linked List C
        currentAddress = headAddress1;
        while (true) {
            if (A.find(currentAddress) == A.end()) {
                break;
            }
            C.push_back(A[currentAddress]);
            len_C++;
            currentAddress = A[currentAddress].nextNodeAddress;
        }

        //Construct strB
        for (i = 0; i < len_B; i++) {
            strB += B[i].val;
        }
        for (i = 0; i < len_C; i++) {
            strC += C[i].val;
        }

        //Search the position of suffix
        pos = posSuffix(strB, strC);
        if (pos == 0) {
            cout << -1 << endl;
        } else {
            cout << B[len_B - pos].address << endl;
        }

        //Clean
        A.clear();
        strB = "";
        strC = "";
        vector<Node>().swap(B);
        vector<Node>().swap(C);
    }
    return 0;
}