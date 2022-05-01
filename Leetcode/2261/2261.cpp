constexpr int MAXN = 203;

int pre[MAXN][MAXN];

struct Node {
    int l, r;
    vector<int>* ptrToNums;
    Node(int l, int r, vector<int>* ptrToNums) : l(l), r(r), ptrToNums(ptrToNums) {}
    bool operator == (const Node& other) const {
        if (r - l != other.r - other.l) {
            return false;
        }
        for (int pos1 = l, pos2 = other.l; pos1 <= r; ++pos1, ++pos2) {
            if ((*ptrToNums)[pos1] != (*(other.ptrToNums))[pos2]) {
                return false;
            }
        }
        return true;
    }
};

struct myHashFunc {
    size_t operator()(const Node &node) const {
        size_t h = 0;
        for (int pos = node.l; pos <= node.r; ++pos) {
            h ^= hash<int>{}((*node.ptrToNums)[pos]) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = (int)nums.size();
        unordered_set<Node, myHashFunc> unset[MAXN]{};
        memset(pre, 0, sizeof pre);
        pre[1][nums[0]]++;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                pre[i][j] = pre[i-1][j];
            }
            ++pre[i][nums[i-1]];
        }
        // pre[r] - pre[l-1]    // 1 <= l <= r <= n
        for (int l = 1; l <= n; ++l) {
            for (int r = l; r <= n; ++r) {
                int temp = 0;
                bool haveAns = true;
                for (int i = p; i < MAXN; i += p) {
                    temp += pre[r][i] - pre[l-1][i];
                    if (temp > k) {
                        haveAns = false;
                        break;
                    }
                }
                if (haveAns) {
                    unset[r-(l-1)].emplace(l-1,r-1,&nums);
                }
            }
        }
        int cnt = 0;
        for (auto&i : unset) {
            cnt += (int)i.size();
        }
        return cnt;
    }
};