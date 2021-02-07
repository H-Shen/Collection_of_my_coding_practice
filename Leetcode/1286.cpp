template<typename Itr>
inline static
bool next_combination(const Itr &first, Itr k, const Itr &last) {
    if ((first == last) || (first == k) || (last == k))
        return false;
    Itr iter1 = first, iter2 = last;
    ++iter1;
    if (last == iter1) return false;
    iter1 = k;
    --iter2;
    while (first != iter1) {
        if (*--iter1 < *iter2) {
            Itr j = k;
            while (!(*iter1 < *j)) ++j;
            std::iter_swap(iter1, j);
            ++iter1;
            ++j;
            iter2 = k;
            std::rotate(iter1, j, last);
            while (last != j) ++j, ++iter2;
            std::rotate(k, iter2, last);
            return true;
        }
    }
    std::rotate(first, k, last);
    return false;
}

class CombinationIterator {
private:
    string characters;
    int combinationLength;
    bool first;
public:
    CombinationIterator(string characters, int combinationLength) :
    characters(characters), combinationLength(combinationLength), first(true)
    {
        
    }
    
    string next() {
        if (first) {
            first = false;
        } else {
            next_combination(characters.begin(), 
                 characters.begin() + combinationLength,
                 characters.end());
        }
        return string(characters.begin(), characters.begin() + combinationLength);
    }
    
    bool hasNext() {
        string copy(characters);
        return next_combination(copy.begin(), 
                         copy.begin() + combinationLength,
                         copy.end());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */