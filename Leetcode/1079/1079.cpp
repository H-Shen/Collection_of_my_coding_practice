template<typename Itr>
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

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int counter = 0;
        int n = (int)tiles.size();
        string str;
        sort(tiles.begin(),tiles.end());
        for (int k = 1; k <= n; ++k) {
            do {
                str.clear();
                for (int j = 0; j < k; ++j) {
                    str.push_back(tiles[j]);
                }
                do {
                    ++counter;
                } while (next_permutation(str.begin(),str.end()));
            } while (next_combination(tiles.begin(),tiles.begin() + k, tiles.end()));
        }
        return counter;
    }
};