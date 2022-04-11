struct Node {
    int startIndex, endIndex, targetIndex;
    Node() = default;
    Node(int startIndex, int endIndex, int targetIndex)
        : startIndex(startIndex),
          endIndex(endIndex),
          targetIndex(targetIndex) {}
    bool operator < (const Node& node) const {
        return startIndex < node.startIndex;
    }
};

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        deque<Node> dq;
        int n = (int)indices.size();
        int m = (int)s.size();
        for (int i = 0; i < n; ++i) {
            int startIndex = indices[i];
            int length = (int)sources[i].size();
            int endIndex = startIndex + length - 1;
            if (endIndex < m) {
                bool contains = true;
                for (int j = startIndex; j <= endIndex; ++j) {
                    if (s[j] != sources[i][j - startIndex]) {
                        contains = false;
                        break;
                    }
                }
                if (contains) {
                    dq.emplace_back(startIndex, endIndex, i);
                }
            }
        }
        string result;
        int index = 0;
        int startIndex, endIndex, targetIndex;
        sort(dq.begin(),dq.end());
        while (!dq.empty()) {
            startIndex = dq.front().startIndex;
            endIndex = dq.front().endIndex;
            targetIndex = dq.front().targetIndex;
            dq.pop_front();
            while (index < startIndex) {
                result.push_back(s[index]);
                ++index;
            }
            index = endIndex+1;
            result += targets[targetIndex];
        }
        while (index < m) {
            result.push_back(s[index]);
            ++index;
        }
        return result;
    }
};