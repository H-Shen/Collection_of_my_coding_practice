#include <iostream>

using namespace std;

#define MAXSIZE 50
typedef int KeyType;

typedef struct {
    KeyType key;
} ElemType;

typedef struct {
    ElemType *R;
    int length;
} SSTable;

void Create(SSTable &T) {
    int i;
    T.R = new ElemType[MAXSIZE + 1];
    cin >> T.length;
    for (i = 1; i <= T.length; i++)
        cin >> T.R[i].key;
}

int Search_Bin(SSTable T, KeyType k);

int main() {
    SSTable T;
    KeyType k;
    Create(T);
    cin >> k;
    int pos = Search_Bin(T, k);
    if (pos == 0) cout << "NOT FOUND" << endl;
    else cout << pos << endl;
    return 0;
}

/* Your code will be pasted here */
#include <algorithm>

int cmp(const ElemType &a, const ElemType &b) {
    return (a.key < b.key);
}

int Search_Bin(SSTable T, KeyType k) {
    ElemType k_convert = {k};
    if (!binary_search(T.R, T.R + T.length, k_convert, cmp)) {
        return 0;
    }
    auto it = lower_bound(T.R, T.R + T.length, k_convert, cmp);
    return static_cast<int>(it - T.R);
}
