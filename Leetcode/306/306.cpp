constexpr int MAXN = 40;
int a[MAXN];
int b[MAXN];
int c[MAXN];

bool haveAns;
int length;

string add(const string& s1, const string& s2) {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
    int n = (int)s1.size();
    for (int i = 0; i < n; ++i) {
        a[n - i - 1] = s1[i] - '0';
    }
    int m = (int)s2.size();
    for (int i = 0; i < m; ++i) {
        b[m - i - 1] = s2[i] - '0';
    }
    for (int i = 0; i < MAXN - 1; ++i) {
        c[i] += a[i] + b[i];
        if (c[i] >= 10) {
            ++c[i+1];
            c[i] -= 10;
        }
    }
    string ans;
    int index;
    for (index = MAXN - 1; index >= 1; --index) {
        if (c[index] != 0) break;
    }
    for (; index >= 0; --index) {
        ans.push_back(c[index] + '0');
    }
    return ans;
}

void dfs(vector<string> vec, string& num, int index) {
    if (haveAns) {
        return;
    }
    if (vec.size() >= 3) {
        if (add(vec[vec.size()-3], vec[vec.size()-2]) != vec[vec.size()-1]) {
            return;
        }
        else if (index == length) {
            haveAns = true;
            return;
        }
    }
    if (index < length) {
        string s;
        if (num[index] == '0') {
            s.push_back('0');
            vec.emplace_back(s);
            dfs(vec,num,index+1);
        }
        else {
            for (int i = index; i < length; ++i) {
                if (!haveAns) {
                    s.push_back(num[i]);
                    vec.emplace_back(s);
                    dfs(vec,num,i+1);
                    vec.pop_back();
                }
            }
        }
    }
}

class Solution {
public:
    bool isAdditiveNumber(string num) {
        haveAns = false;
        length = (int)num.size();
        string s;
        if (num[0] == '0') {
            s.push_back('0');
            dfs(vector<string>{s}, num, 1);
        }
        else {
            for (int i = 0; i < length; ++i) {
                if (!haveAns) {
                    s.push_back(num[i]);
                    dfs(vector<string>{s}, num, i+1);
                }
                else {
                    break;
                }
            }
        }
        return haveAns;
    }
};