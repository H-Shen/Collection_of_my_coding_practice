class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        using ll = long long;
        ll mem1(memory1);
        ll mem2(memory2);
        ll counter = 1;
        while (true) {
            if (counter > mem1 && counter > mem2) {
                break;
            }  
            if (mem1 >= mem2) {
                mem1 -= counter;
            } else {
                mem2 -= counter;
            }
            ++counter;
        }
        return vector<int>{(int)counter,(int)mem1,(int)mem2};
    }
};