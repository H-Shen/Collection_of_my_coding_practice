#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

/* Head ends here */

struct Node {
    ll first;
    ll second;
    inline bool operator < (const Node &other) const
    {
        if (first == other.first) {
            return (second < other.second);
        }
        return (first < other.first);
    }
};


void median(vector<char> s,vector<ll> X, int N)
{
    tree <Node, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> RBTree;
    unordered_map <ll, ll> idxLog, idxMark;

    int length = 0;
    int i;
    Node tmpNode{};
    ll midTemp;

    for (i = 0; i < N; ++i) {

        if (s[i] == 'r') {
            if (length == 0 || idxLog.find(X[i]) == idxLog.end() || idxLog[X[i]] == 0) {
                cout << "Wrong!" << endl;
                continue;
            } else {
                tmpNode.first = X[i];
                --idxMark[tmpNode.first];
                tmpNode.second = idxMark[tmpNode.first];
                RBTree.erase(tmpNode);
                --idxLog[tmpNode.first];
                --length;
                if (length == 0) {
                    cout << "Wrong!" << endl;
                    continue;
                }
            }
        } else {
            tmpNode.first = X[i];
            tmpNode.second = idxMark[tmpNode.first];
            ++idxMark[tmpNode.first];
            ++idxLog[tmpNode.first];
            RBTree.insert(tmpNode);
            ++length;
        }

        //output median
        if (length % 2 == 0) {
            midTemp = (*RBTree.find_by_order(length / 2 - 1)).first + (*RBTree.find_by_order(length / 2)).first;
            if (midTemp % 2 == 0) {
                cout << midTemp / 2 << endl;
            } else {
                cout << fixed << setprecision(1) << (midTemp / 2.0) << endl;
            }
        } else {
            cout << (*RBTree.find_by_order((length - 1) / 2)).first << endl;
        }
    }
}

int main()
{

//Helpers for input and output

    int N;
    cin >> N;

    vector<char> s;
    vector<ll> X;
    char temp;
    ll tempint;

    for(int i = 0; i < N; i++) {
        cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
    }

    median(s,X,N);
    return 0;
}
