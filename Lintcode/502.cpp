/**
 * Definition of Column:
 * class Column {
 * public:
 *     int key;
 *     String value;
 *     Column(int key, string value) {
 *         this->key = key;
 *         this->value = value;
 *    }
 * }
 */


class MiniCassandra {
private:
    unordered_map<string, map<int, string>> hashMap;
public:
    MiniCassandra() {
        // do intialization if necessary
    }

    /*
     * @param row_key: a string
     * @param column_key: An integer
     * @param value: a string
     * @return: nothing
     */
    void insert(string &row_key, int column_key, string &value) {
        // write your code here
        hashMap[row_key][column_key] = value;
    }

    /*
     * @param raw_key: a string
     * @param column_start: An integer
     * @param column_end: An integer
     * @return: a list of Columns
     */
    vector<Column> query(string &row_key, int column_start, int column_end) {
        // write your code here
        vector<Column> result;
        auto& m = hashMap[row_key];
        auto iter = m.lower_bound(column_start);
        while (true) {
            if (iter == m.end() || iter->first > column_end) {
                break;
            }
            result.emplace_back(iter->first, iter->second);
            ++iter;
        }
        return result;
    }
};