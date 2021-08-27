constexpr int MAXN = 32;

class Solution {
public:
    int findComplement(int num) {
        bitset<MAXN> A(num);
        auto s = A.flip().to_string();
        deque<char> tempDeque (s.begin(), s.end());
        while (tempDeque.size() > 1 && tempDeque.front() == '1') {
            tempDeque.pop_front();
        }
        s.clear();
        while (!tempDeque.empty()) {
            s += tempDeque.front();
            tempDeque.pop_front();
        }
        return bitset<MAXN>(s).to_ulong();
    }
};