class StringIterator {
private:
    string s;
    string::iterator iter;
public:
    StringIterator(string compressedString) {
        int n = (int)compressedString.size();
        char ch;
        string number;
        for (int i = 0; i < n; ++i) {
            if (isalpha(compressedString[i])) {
                if (!number.empty()) {
                    s += string(stoi(number), ch);
                    number.clear();
                }
                ch = compressedString[i];
            }
            else {
                number.push_back(compressedString[i]);
            }
        }
        if (!number.empty()) {
            s += string(stoi(number), ch);
        }
        iter = s.begin();
        --iter;
    }
    
    char next() {
        if (hasNext()) {
            ++iter;
            return *iter;
        }
        return ' ';
    }
    
    bool hasNext() {
        return std::next(iter) != s.end();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */