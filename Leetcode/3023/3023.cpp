/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 * public:
 *     InfiniteStream(vector<int> bits);
 *     int next();
 * };
 */
class Solution {
public:
    int findPattern(InfiniteStream* stream, vector<int>& pattern) {
        if (!stream) {
            return -1;
        }
        int n = (int)pattern.size();
        deque<int> dq;
        while ((int)dq.size() < n) {
            dq.emplace_back(stream->next());
        }
        int ans = 0;
        bool haveAns;
        while (true) {
            haveAns = true;
            for (int i = 0; i < n; ++i) {
                if (dq[i] != pattern[i]) {
                    haveAns = false;
                    break;
                }
            }
            if (haveAns) {
                return ans;
            }
            ++ans;
            dq.pop_front();
            dq.emplace_back(stream->next());
        }
        return -1;
    }
};