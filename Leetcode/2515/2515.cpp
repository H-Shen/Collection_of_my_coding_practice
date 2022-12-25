class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = (int)words.size();
        if (words[startIndex] == target) {
            return 0;
        }
        if (find(words.begin(),words.end(),target) == words.end()) {
            return -1;
        }
        // forward
        int step1 = 1;
        for (int i = (startIndex+1)%n; i != startIndex; i = (i+1)%n, ++step1) {
            if (words[i] == target) {
                break;
            }
        }
        // backward
        int step2 = 1;
        for (int i = (startIndex-1+n)%n; i != startIndex; i = (i-1+n)%n, ++step2) {
            if (words[i] == target) {
                break;
            }
        }
        return min(step1, step2);
    }
};