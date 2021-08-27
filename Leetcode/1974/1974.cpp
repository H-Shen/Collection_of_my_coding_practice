class Solution {
public:
    int dist(char a, char b) {
        if (a == b) {
            return 0;
        }
        int ans = numeric_limits<int>::max();
        int counter = 0;
        char c = a;
        while (c != b) {
            if (c == 'z') {
                c = 'a';
            } else {
                ++c;
            }
            ++counter;
        }
        ans = min(ans, counter);
        counter = 0;
        c = a;
        while (c != b) {
            if (c == 'a') {
                c = 'z';
            } else {
                --c;
            }
            ++counter;
        }
        ans = min(ans, counter);
        return ans;
    }
    int minTimeToType(string word) {
        int sum = 0;
        char ch = 'a';
        for (const auto &i : word) {
            sum += dist(ch, i) + 1;
            ch = i;
        }
        return sum;
    }
};