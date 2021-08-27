class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n);
        deque<char> d;
        int counter = 0;
        while (!s.empty()) {
            ++counter;
            d.push_front(s.back());
            s.pop_back();
            if (counter % 3 == 0) {
                d.push_front('.');
            }
        }
        if (d.front() == '.') {
            d.pop_front();
        }
        return string(d.begin(), d.end());
    }
};