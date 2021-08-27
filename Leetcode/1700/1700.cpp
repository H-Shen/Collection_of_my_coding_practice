class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;   //store positions only
        int n = (int)students.size();
        for (int i = 0; i < n; ++i) q.push(i);
        unordered_map<int, int> studentId2stackLength;
        int length = (int)sandwiches.size();
        int currentIndex = 0;
        while (currentIndex < length) {
            if (sandwiches[currentIndex] == students[q.front()]) {
                ++currentIndex;
                studentId2stackLength.erase(q.front());
                q.pop();
            } else {
                if (studentId2stackLength.find(q.front()) == studentId2stackLength.end()) {
                    studentId2stackLength[q.front()] = length - currentIndex;
                    q.push(q.front());
                    q.pop();
                }
                else if (studentId2stackLength[q.front()] > length - currentIndex) {
                    studentId2stackLength[q.front()] = length - currentIndex;
                    q.push(q.front());
                    q.pop();
                }
                else {
                    break;
                }
            }
        }
        return length - currentIndex;
    }
};