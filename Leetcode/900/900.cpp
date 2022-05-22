using ll = long long;

class RLEIterator {
private:
    deque<pair<int,ll>> freq;
public:
    RLEIterator(vector<int>& encoding) {
        int n = (int)encoding.size();
        int lastVal, lastFreq;
        lastFreq = -1;
        for (int i = 0; i < n; i += 2) {
            if (encoding[i] != 0) {
                if (lastFreq == -1) {
                    lastFreq = encoding[i];
                    lastVal = encoding[i+1];
                }
                else {
                    if (lastVal == encoding[i+1]) {
                        lastFreq += encoding[i];
                    }
                    else {
                        freq.emplace_back(lastVal, lastFreq);
                        lastFreq = encoding[i];
                        lastVal = encoding[i+1];
                    }
                }
            }
        }
        if (lastFreq != -1) {
            freq.emplace_back(lastVal, lastFreq);
        }
    }
    
    int next(int n) {
        if (freq.empty()) {
            return -1;
        }
        int result = -1;
        while (!freq.empty()) {
            if ((ll)n > freq.front().second) {
                n -= freq.front().second;
                freq.pop_front();
            }
            else {
                result = freq.front().first;
                freq.front().second -= n;
                if (freq.front().second == 0) {
                    freq.pop_front();
                }
                break;
            }
        }
        return result;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */