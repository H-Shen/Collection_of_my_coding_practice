constexpr int MAXN = 51;
int freq[MAXN][MAXN][MAXN];

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        memset(freq, 0, sizeof freq);
        unordered_map<string,int> username2id;
        for (auto &i : username) {
            if (username2id.find(i) == username2id.end()) {
                username2id[i] = (int)username2id.size();
            }
        }
        vector<vector<int>> user2websites(username2id.size());
        int n = (int)username.size();
        for (int i = 0; i < n; ++i) {
            user2websites[username2id[username[i]]].emplace_back(i);   
        }
        unordered_map<string, int> website2id;
        vector<string> id2website;
        int id = 0;
        for (auto &i : website) {
            if (website2id.find(i) == website2id.end()) {
                website2id[i] = id;
                id2website.emplace_back(i);
                ++id;
            }
        }
        int a, b, c;
        for (const auto &user2website : user2websites) {
            bitset<MAXN> vis[MAXN][MAXN];   // to avoid repeated visits
            int length = (int)user2website.size();
            if (length < 3) {
                continue;
            }
            for (int i = 0; i < length; ++i) {
                for (int j = 0; j < length; ++j) {
                    for (int k = 0; k < length; ++k) {
                        if ((i != j && i != k && j != k) && timestamp[user2website[i]] < timestamp[user2website[j]] && timestamp[user2website[j]] < timestamp[user2website[k]]) {
                            a = website2id[website[user2website[i]]];
                            b = website2id[website[user2website[j]]];
                            c = website2id[website[user2website[k]]];
                            if (!vis[a][b][c]) {
                                vis[a][b][c] = true;
                                ++freq[a][b][c];
                            }
                        }
                    }
                }
            }
        }
        vector<string>ans;
        vector<string> temp(3);
        int maxFreq = 0;
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                for (int k = 0; k < MAXN; ++k) {
                    if (freq[i][j][k] > maxFreq) {
                        maxFreq = freq[i][j][k];
                    }
                }
            }
        }
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                for (int k = 0; k < MAXN; ++k) {
                    if (maxFreq == freq[i][j][k]) {
                        if (ans.empty()) {
                            ans.resize(3);
                            ans[0] = id2website[i];
                            ans[1] = id2website[j];
                            ans[2] = id2website[k];
                        }
                        else {
                            temp[0] = id2website[i];
                            temp[1] = id2website[j];
                            temp[2] = id2website[k];
                            if (temp < ans) {
                                swap(temp, ans);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};