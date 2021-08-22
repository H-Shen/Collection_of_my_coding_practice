constexpr int MAXN = (1<<16)+5;
constexpr int N = 16;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        bitset<MAXN> vis;
        for (const auto &i : nums) {
            vis[(int)bitset<N>(i).to_ulong()] = true;
        }
        string ans;
        bool flag = false;
        for (int i = 0; i < MAXN; ++i) {
            if (!vis[i]) {
                flag = true;
                ans = bitset<N>(i).to_string();
                while (ans.size() > nums.size()) {
                    ans = ans.substr(1);
                }
            }
            if (flag) {
                break;
            }
        }
        return ans;
    }
};