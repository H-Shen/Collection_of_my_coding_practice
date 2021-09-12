constexpr int N = 12;
constexpr int MAXN = 4096+5;

vector<pair<int,int>> isPalin;
bitset<N> bs;
int n;

bool f(string &s, int &length) {
    string str;
    for (int i = 0; i < n; ++i) {
        if (bs[i]) {
            str.push_back(s[i]);
        }
    }
    if (str.empty()) {
        return false;
    }
    length = (int)str.size();
    int halfLength = length >> 1;
    for (int i = 0; i < halfLength; ++i) {
        if (str[i] != str[length - 1 - i]) {
            return false;
        }
    }
    return true;
}

class Solution {
public:
    int maxProduct(string s) {
        vector<pair<int,int>>().swap(isPalin);
        bs.reset();
        n = (int)s.size();
        int total = 1<<n;
        int temp;
        for (int i = 0; i <= total; ++i) {
            if (f(s, temp)) {
                isPalin.emplace_back(i, temp);
            }
            bs = bitset<N>(bs.to_ulong()+1LL);
        }
        int ans = 0;
        int length = (int)isPalin.size();
        for (int i = 0; i < length-1; ++i) {
            for (int j = length - 1; j > i; --j) {
                if (!(isPalin[i].first & isPalin[j].first)) {
                    ans = max(ans, isPalin[i].second * isPalin[j].second);
                }
            }
        }
        return ans;
    }
};