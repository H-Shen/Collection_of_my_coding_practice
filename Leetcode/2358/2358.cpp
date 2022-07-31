class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int counter = 0;
        int n = (int)grades.size();
        int num = 1;
        int i = 1;
        deque<int> dq(grades.begin(),grades.end());
        dq.pop_front();
        int newNum;
        while (!dq.empty()) {
            newNum = num + 1;
            int counter = 0;
            while (counter < newNum && !dq.empty()) {
                ++counter;
                dq.pop_front();
            }
            if (counter == newNum) {
                num = newNum;
            }
            else {
                break;
            }
        }
        return num;
    }
};