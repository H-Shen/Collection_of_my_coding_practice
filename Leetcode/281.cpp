class ZigzagIterator {
private:
    vector<int> v1,v2;
    vector<int>::iterator iter1, iter2;
    bool flag;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) : v1(v1), v2(v2) {
        iter1 = this->v1.begin();   //
        iter2 = this->v2.begin();
        flag = true;
    }

    int next() {
        while (true) {
            if (flag) {
                flag = false;
                if (iter1 == v1.end()) {
                    continue;
                }
                else {
                    int temp = *iter1;
                    ++iter1;
                    return temp;
                }
            }
            else {
                flag = true;
                if (iter2 == v2.end()) {
                    continue;
                }
                else {
                    int temp = *iter2;
                    ++iter2;
                    return temp;
                }
            }
        }
    }

    bool hasNext() {
        return !(iter1 == v1.end() && iter2 == v2.end());
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */