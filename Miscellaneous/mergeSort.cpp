#include <bits/stdc++.h>

using namespace std;

#define DEBUG

namespace MergeSort {

    // Merge two sorted arrays.
    template<typename T>
    vector<T> mergeTwoSortedArrays(const vector<T> &C1, const vector<T> &C2) {

        int n1 = static_cast<int>(C1.size());
        int n2 = static_cast<int>(C2.size());
        vector<T> D(C1.size() + C2.size());
        int i1 = 0;
        int i2 = 0;
        int j = 0;

        while ((i1 < n1) && (i2 < n2)) {
            if (C1.at(i1) <= C2.at(i2)) {
                D.at(j) = C1.at(i1);
                ++i1;
            } else {
                D.at(j) = C2.at(i2);
                ++i2;
            }
            ++j;
        }
        while (i1 < n1) {
            D.at(j) = C1.at(i1);
            ++i1;
            ++j;
        }
        while (i2 < n2) {
            D.at(j) = C2.at(i2);
            ++i2;
            ++j;
        }
        return D;
    }

    // Merge two sorted arrays.
    template<typename T, typename Comparator>
    vector<T> mergeTwoSortedArrays(const vector<T> &C1, const vector<T> &C2, const Comparator &comp) {

        int n1 = static_cast<int>(C1.size());
        int n2 = static_cast<int>(C2.size());
        vector<T> D(C1.size() + C2.size());
        int i1 = 0;
        int i2 = 0;
        int j = 0;

        while ((i1 < n1) && (i2 < n2)) {
            if (comp(C1.at(i1), C2.at(i2)) <= 0) {
                D.at(j) = C1.at(i1);
                ++i1;
            } else {
                D.at(j) = C2.at(i2);
                ++i2;
            }
            ++j;
        }
        while (i1 < n1) {
            D.at(j) = C1.at(i1);
            ++i1;
            ++j;
        }
        while (i2 < n2) {
            D.at(j) = C2.at(i2);
            ++i2;
            ++j;
        }
        return D;
    }

    // MergeSort with comparator
    template<typename T, typename Comparator>
    vector<T> mergeSort(const vector<T> &A, const Comparator &comp) {

        // Corner cases.
        if (A.size() <= 1) {
            return A;
        }

        int n = static_cast<int>(A.size());
        int n1, n2;

        if (n % 2 == 0) {
            n1 = n / 2;
            n2 = n / 2;
        } else {
            n1 = n / 2 + 1;
            n2 = n / 2;
        }

        vector<T> B2(static_cast<unsigned long>(n2));
        vector<T> B1(static_cast<unsigned long>(n1));
        int i = 0;

        while (i < n1) {
            B1.at(i) = A.at(i);
            ++i;
        }
        while (i < n) {
            B2.at(i - n1) = A.at(i);
            ++i;
        }
        // Recursively Sort and Merge
        vector<T> C1 = mergeSort(B1, comp);
        vector<T> C2 = mergeSort(B2, comp);
        return mergeTwoSortedArrays(C1, C2, comp);
    }

    // MergeSort
    template<typename T>
    vector<T> mergeSort(const vector<T> &A) {

        // Corner cases.
        if (A.size() <= 1) {
            return A;
        }

        int n = static_cast<int>(A.size());
        int n1, n2;

        if (n % 2 == 0) {
            n1 = n / 2;
            n2 = n / 2;
        } else {
            n1 = n / 2 + 1;
            n2 = n / 2;
        }

        vector<T> B2(static_cast<unsigned long>(n2));
        vector<T> B1(static_cast<unsigned long>(n1));
        int i = 0;

        while (i < n1) {
            B1.at(i) = A.at(i);
            ++i;
        }
        while (i < n) {
            B2.at(i - n1) = A.at(i);
            ++i;
        }
        // Recursively Sort and Merge
        vector<T> C1 = mergeSort(B1);
        vector<T> C2 = mergeSort(B2);
        return mergeTwoSortedArrays(C1, C2);
    }
}

int main() {

#ifdef DEBUG
    // merge test
    vector<int> A = {1, 2, 2, 2, 3, 4, 99, 99};
    vector<int> B = {2, 4, 5, 8, 10};
    vector<int> C0 = MergeSort::mergeTwoSortedArrays(A, B);
    vector<int> C1;
    merge(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C1));
    assert(C0 == C1);

    // reset arrays
    vector<int>().swap(A);
    vector<int>().swap(C0);
    vector<int>().swap(C1);

    // mergeSort test
    A = {};
    C0 = MergeSort::mergeSort(A);
    C1.resize(A.size());
    partial_sort_copy(A.begin(), A.end(), C1.begin(), C1.end());
    assert(C0 == C1);
#endif

    return 0;
}
