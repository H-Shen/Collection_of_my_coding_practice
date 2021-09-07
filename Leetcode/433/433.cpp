constexpr int STEPS = 4;
const char dx[] = {'A','C','G','T'};

class Solution {
public:
    unordered_set<string> valid;
    string target;
    int minSteps, n;
    void dfs(string s, int steps, unordered_set<string>vis) {
        if (s == target) {
            minSteps = min(minSteps, steps);
            return;
        }
        char copyChar;
        for (int i = 0; i < n; ++i) {
            copyChar = s[i];
            for (int step = 0; step < STEPS; ++step) {
                if (dx[step] != copyChar) {
                    s[i] = dx[step];
                    if (valid.find(s) != valid.end() && vis.find(s) == vis.end()) {
                        vis.insert(s);
                        dfs(s, steps+1, vis);
                        vis.erase(s);
                    }
                    s[i] = copyChar;
                }
            }
        }
    }
    int minMutation(string start, string end, vector<string>& bank) {
        target = end;
        n = (int)start.size();
        minSteps = numeric_limits<int>::max();
        valid.clear();
        valid.insert(start);
        for (auto &i : bank) {
            valid.insert(i);
        }
        unordered_set<string> vis;
        vis.insert(start);
        dfs(start, 0, vis);
        return (minSteps == numeric_limits<int>::max()) ? -1 : minSteps;
    }
};