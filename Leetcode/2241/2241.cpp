class ATM {
private:
    static const int TYPES = 5;
    vector<int> banknotesValue;
    vector<long long> banknotesCount;
public:
    ATM() {
        banknotesValue.resize(TYPES);
        banknotesValue[0] = 20;
        banknotesValue[1] = 50;
        banknotesValue[2] = 100;
        banknotesValue[3] = 200;
        banknotesValue[4] = 500;
        banknotesCount.resize(TYPES);
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < TYPES; ++i) {
            this->banknotesCount[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> result(TYPES);
        vector<long long> banknotesCountCopy = banknotesCount;
        for (int i = TYPES-1; i >= 0; --i) {
            if (amount >= banknotesValue[i]) {
                result[i] = (int)min((long long)(amount/banknotesValue[i]), banknotesCountCopy[i]);
                amount -= banknotesValue[i] * result[i];
                banknotesCountCopy[i] -= result[i];
            } 
        }
        if (amount > 0) {
            return vector<int>{-1};
        }
        swap(banknotesCountCopy, banknotesCount);
        return result;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */