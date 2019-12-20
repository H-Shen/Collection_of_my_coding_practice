// https://www.nowcoder.com/practice/084b6cb2ca934d7daad55355b4445f8a

class StringPattern {
public:
    int findAppearance(string A, int lena, string B, int lenb) {
        // write code here
        auto result = A.find(B);
        if (result != string::npos) {
            return static_cast<int>(result);
        }
        return -1;
    }
};