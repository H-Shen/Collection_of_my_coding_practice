using ll = long long;

constexpr ll MAXINT = 1LL << 31;

class Solution {
public:
    vector<int> ans;
    int n;
    void dfs(string &num, vector<int> vec, int index) {
        if (!ans.empty()) {
            return;
        }
        if (vec.size() >= 3) {
            if ((ll)vec[vec.size()-3] + (ll)vec[vec.size()-2] != (ll)vec[vec.size()-1]) {
                return;
            }
            if (index == n) {
                ans = vec;
                return;
            }
        }
        if (index < n) {
            if (num[index] == '0') {
                vec.emplace_back(0);
                dfs(num, vec, index+1);
            }
            else {
                ll temp = -1;
                for (int i = index; i < n; ++i) {
                    if (ans.empty()) {
                        if (temp == -1) {
                            temp = num[i] - '0';
                        }
                        else {
                            temp = 10*temp + (num[i] - '0');
                        }
                        if (temp >= MAXINT) {
                            break;
                        }
                        vec.emplace_back((int)temp);
                        dfs(num, vec, i+1);
                        vec.pop_back();
                    }
                }
            }
        }
    }
    vector<int> splitIntoFibonacci(string num) {
        vector<int>().swap(ans);
        n = (int)num.size();
        if (num[0] == '0') {
            dfs(num, vector<int>{0},1);
        }
        else {
            ll temp = -1;
            for (int i = 0; i < n; ++i) {
                if (ans.empty()) {
                    if (temp == -1) {
                        temp = num[i] - '0';
                    }
                    else {
                        temp = 10*temp + (num[i] - '0');
                    }
                    if (temp >= MAXINT) {
                        break;
                    }
                    dfs(num, vector<int>{(int)temp},i+1);
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }
};