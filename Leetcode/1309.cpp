class Solution {
public:
    string freqAlphabets(string s) {
        unordered_map<string, char> unmap;
        for (char ch0 = '1', ch1 = 'a'; ch0 <= '9'; ++ch0, ++ch1) unmap[ch0 + string()] = ch1;
        char ch0 = 'j';
        for (int i = 10; i <= 26; ++i, ++ch0) {
            unmap[to_string(i) + '#'] = ch0;
        }
        string result;
        deque<char> dq(s.begin(), s.end());
        while (dq.size() > 2) {
            if (dq[2] == '#') {
                result.push_back(unmap[dq[0] + string() + dq[1] + string() + '#']);
                dq.pop_front();
                dq.pop_front();
                dq.pop_front();
            }
            else {
                result.push_back(unmap[string() + dq[0]]);
                dq.pop_front();
            }
        }
        while (!dq.empty()) {
            result.push_back(unmap[string() + dq[0]]);
            dq.pop_front();
        }
        return result;
    }
};