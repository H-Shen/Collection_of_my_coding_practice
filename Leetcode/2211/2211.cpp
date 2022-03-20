class Solution {
public:
    int countCollisions(string directions) {
        int counter = 0;
        deque<char> dq(directions.begin(),directions.end());
        vector<char> buf;
        char ch;
        while (!dq.empty()) {
            ch = dq.front();
            dq.pop_front();
            if (buf.empty()) {
                buf.emplace_back(ch);
                continue;
            }
            // S
            if (buf.back() == 'S') {
                if (ch == 'S') {
                    buf.emplace_back(ch);
                }
                else if (ch == 'L') {
                    ++counter;
                }
                else {
                    buf.emplace_back(ch);
                }
            }
            // L
            else if (buf.back() == 'L') {
                buf.emplace_back(ch);
            }
            // R
            else {
                if (ch == 'S') {
                    while (!buf.empty() && buf.back() == 'R') {
                        buf.pop_back();
                        ++counter;
                    }
                    buf.emplace_back(ch);
                }
                else if (ch == 'L') {
                    buf.pop_back();
                    counter += 2;
                    while (!buf.empty() && buf.back() == 'R') {
                        buf.pop_back();
                        ++counter;
                    }
                    buf.emplace_back('S');
                }
                else {
                    buf.emplace_back(ch);
                }
            }
        }
        return counter;
    }
};