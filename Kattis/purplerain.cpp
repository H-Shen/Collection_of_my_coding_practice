// https://open.kattis.com/problems/purplerain

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool smallerStartIndex(const vector<int> &A, int maxSum, int startIndex, int &ans) {
    int curSum = maxSum;
    bool haveAns = false;
    while (true) {
        --startIndex;
        if (startIndex < 0) break;
        curSum += A[startIndex];
        if (curSum == maxSum) {
            ans = startIndex;
            haveAns = true;
        }
    }
    return haveAns;
}

void maxSubarray(const vector<int> &A, int &maxSum, int &startIndex, int &endIndex) {
    maxSum = 0;
    startIndex = 0;
    endIndex = 0;
    int currentSum = 0;
    int currentStart;
    int n = (int)A.size();
    for (int i = 0; i < n; ++i) {
        if (currentSum <= 0) {
            currentStart = i;
            currentSum = A[i];
        }
        else {
            currentSum += A[i];
        }
        if (currentSum > maxSum) {
            maxSum = currentSum;
            startIndex = currentStart;
            endIndex = i;
        }
    }
    int smallerStartIdx;
    if (smallerStartIndex(A, maxSum, startIndex, smallerStartIdx)) {
        startIndex = smallerStartIdx;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    vector<int> v(s.size());
    int maxSum1, startIndex1, endIndex1, maxSum2, startIndex2, endIndex2;
    // Case 1: R: 1 B: -1
    for (size_t i = 0; i != s.size(); ++i) {
        if (s[i] == 'R') {
            v[i] = 1;
        } else {
            v[i] = -1;
        }
    }
    maxSubarray(v,maxSum1,startIndex1,endIndex1);
    // Case 2: R: -1 B: 1
    for (size_t i = 0; i != s.size(); ++i) {
        if (s[i] == 'R') {
            v[i] = -1;
        } else {
            v[i] = 1;
        }
    }
    maxSubarray(v, maxSum2, startIndex2, endIndex2);
    pair<int,int> ans;
    if (maxSum1 > maxSum2) {
        ans.first = startIndex1+1;
        ans.second = endIndex1+1;
    }
    else if (maxSum1 < maxSum2) {
        ans.first = startIndex2+1;
        ans.second = endIndex2+1;
    }
    else {
        if (startIndex1 < startIndex2) {
            ans.first = startIndex1+1;
            ans.second = endIndex1+1;
        }
        else if (startIndex1 > startIndex2) {
            ans.first = startIndex2+1;
            ans.second = endIndex2+1;
        }
        else {
            if (endIndex1 < endIndex2) {
                ans.first = startIndex1+1;
                ans.second = endIndex1+1;
            }
            else {
                ans.first = startIndex2+1;
                ans.second = endIndex2+1;
            }
        }
    }
    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}
