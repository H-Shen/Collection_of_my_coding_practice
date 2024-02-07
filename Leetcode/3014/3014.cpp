class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> visited;
        vector<string> num2str(10);
        int cnt = 0;
        int currentIndex = 2;
        for (const char &ch : word) {
            if (visited.count(ch) == 0) {
                visited[ch] = currentIndex;
                num2str[currentIndex].push_back(ch);
                ++currentIndex;
                if (currentIndex > 9) {
                    currentIndex = 2;
                }
            }
            int length = (int)num2str[visited[ch]].length();
            for (int i = 0; i < length; ++i) {
                if (ch ==num2str[visited[ch]][i]) {
                    cnt += (i+1);
                    break;
                }
            }
        }
        return cnt;
    }
};