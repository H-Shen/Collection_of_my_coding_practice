// https://www.nowcoder.com/practice/876e3c5fcfa5469f8376370d5de87c06

#include <bits/stdc++.h>

using namespace std;

template<typename Iterator>

/* Credits: Mark Nelson http://marknelson.us */
inline bool next_combination(const Iterator first, Iterator k, const Iterator last) {
    if ((first == last) || (first == k) || (last == k))
        return false;
    Iterator itr1 = first;
    Iterator itr2 = last;
    ++itr1;
    if (last == itr1)
        return false;
    itr1 = last;
    --itr1;
    itr1 = k;
    --itr2;
    while (first != itr1) {
        if (*--itr1 < *itr2) {
            Iterator j = k;
            while (!(*itr1 < *j)) ++j;
            iter_swap(itr1, j);
            ++itr1;
            ++j;
            itr2 = k;
            rotate(itr1, j, last);
            while (last != j) {
                ++j;
                ++itr2;
            }
            rotate(k, itr2, last);
            return true;
        }
    }
    rotate(first, k, last);
    return false;
}

unordered_set<int> sumList;

int main() {

    int len, i;
    scanf("%d", &len);
    int *A = new int[len];

    for (i = 0; i < len; i++) {
        scanf("%d", &A[i]);
    }

    int tmpSum, comb_size;
    sort(A, A + len);

    for (comb_size = 1; comb_size <= len; comb_size++) {

        do {
            tmpSum = 0;
            for (i = 0; i < comb_size; i++) {
                tmpSum += A[i];
            }
            sumList.insert(tmpSum);
        } while (next_combination(A, A + comb_size, A + len));
    }

    int sumListLen = sumList.size();
    int *sumListSort = new int[sumListLen];
    copy(sumList.begin(), sumList.end(), sumListSort);
    sort(sumListSort, sumListSort + sumListLen);

    int result = sumListSort[sumListLen - 1] + 1;

    // CHECK FROM 1 TO THE FIRST ELEMENT
    for (i = 1; i < sumListSort[0]; i++) {
        if (sumListSort[0] - i > 1) {
            result = i;
            goto ending;
        }
    }

    // CHECK THE GAP BETWEEN EACH ELEMENTS
    for (i = 1; i < sumListLen; i++) {
        if (sumListSort[i] - sumListSort[i - 1] > 1) {
            result = sumListSort[i - 1] + 1;
            break;
        }
    }

    ending:
    { printf("%d\n", result); }

    return 0;
}