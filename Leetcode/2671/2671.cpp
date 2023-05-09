class FrequencyTracker {
private:
    unordered_map<int,int> num2freq;
    unordered_map<int, unordered_set<int>> freq2nums;
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if (num2freq.count(number) > 0) {
            int oldFreq = num2freq[number];
            ++num2freq[number];
            freq2nums[oldFreq].erase(number);
            if (freq2nums[oldFreq].empty()) {
                freq2nums.erase(oldFreq);
            }
            freq2nums[oldFreq+1].insert(number);
        }
        else {
            ++num2freq[number];
            freq2nums[num2freq[number]].insert(number);
        }
    }
    
    void deleteOne(int number) {
        if (num2freq.count(number) > 0) {
            int freq = num2freq[number];
            if (freq == 1) {
                num2freq.erase(number);
                freq2nums[freq].erase(number);
                if (freq2nums[freq].empty()) {
                    freq2nums.erase(freq);
                }
            }
            else {
                num2freq[number] = freq - 1;
                freq2nums[freq].erase(number);
                if (freq2nums[freq].empty()) {
                    freq2nums.erase(freq);
                }
                freq2nums[freq - 1].insert(number);
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return freq2nums.count(frequency) > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */