class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int r = 0;
        for (const auto &i : words) {
            r = max(r, (int)i.size());
        }
        int c = 0;
        for (int i = 0; i < r; ++i) {
            int counter = 0;
            try {
                for (int j = 0;; ++j) {
                    int temp = words.at(j).at(i);
                    ++counter;
                }
            } catch (...) {
                
            }
            c = max(counter, c);
        }
        if (r != c) return false;
        vector<vector<char> > M(r, vector<char>(r));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < r; ++j) {
                try {
                    M.at(i).at(j) = words.at(i).at(j);
                } catch (...) {
                    M.at(i).at(j) = ' ';
                }
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < r; ++j) {
                if (M.at(i).at(j) != M.at(j).at(i)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};