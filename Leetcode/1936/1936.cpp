using ll = long long;

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int cur = 0;
        int i = 0;
        int n = (int)rungs.size();
        int lastRung = rungs[n-1];
        deque<int> dq(rungs.begin(), rungs.end());
        int counter = 0;
        while (!dq.empty()) {
            if (cur == lastRung) break;
            if (cur + dist >= dq.front()) {
                cur = dq.front();
                dq.pop_front();
            }
            else {
                int temp = (dq.front() - cur) / dist;
                cur += dist * temp;
                counter += temp;
                while (cur + dist > dq.front()) { cur -= dist; --counter; }
                while (cur + dist < dq.front()) { cur += dist; ++counter; }
            }
        }
        return counter;
    }
};