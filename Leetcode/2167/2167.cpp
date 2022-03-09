constexpr int MAXN = 2*1e5+5;
int pre[MAXN];
int A[MAXN];

class Solution {
public:
    // [XXX][iXXXj][XXX]
    //   min(i+2pre[j]-2pre[i-1]+(n-j-1))
    // = min(n + (2pre[j]-j) - (2pre[i-1]-(i-1)))
    // = min(n + A[j] - A[i-1]) (i <= j)
    int minimumTime(string s) {
        int n = (int)s.size();
        if (n <= 2) return (int)count(s.begin(),s.end(),'1');
        memset(pre,0,sizeof pre);
        memset(A, 0, sizeof A);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i-1] + (s[i-1] - '0');
        }
        for (int i = 0; i < n+1; ++i) {
            A[i] = 2*pre[i]-i;
        }
        int maxFromLeft = A[0];
        int minVal = n+A[0];
        for (int i = 1; i < n+1; ++i) {
            minVal = min(minVal, n+A[i]-maxFromLeft);
            maxFromLeft = max(maxFromLeft, A[i]);
        }
        return minVal;
    }
};