/**
 * Definition of Document:
 * class Document {
 * public:
 *     int id;
 *     string content;
 * }
 */
class Solution {
public:
    /**
     * @param docs a list of documents
     * @return an inverted index
     */
    map<string, vector<int>> invertedIndex(vector<Document>& docs) {
        // Write your code here
        map<string, vector<int>> result;
        string word;
        for (auto& document : docs) {
            for (auto& ch : document.content) {
                if (isspace(ch)) {
                    if (!word.empty()) {
                        result[word].emplace_back(document.id);
                        word.clear();
                    }
                }
                else {
                    word.push_back(ch);
                }
            }
            if (!word.empty()) {
                result[word].emplace_back(document.id);
                word.clear();
            }
        }
        // remove duplicated indices
        for (auto& [k, v] : result) {
            v.erase(unique(v.begin(),v.end()), v.end());
        }
        return result;
    }
};