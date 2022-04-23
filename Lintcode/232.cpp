class TinyUrl {
private:
    static const int SHORT_KEY_LENGTH = 6;
    int id{};
    static string getShortKey(int id) {
        string s = to_string(id);
        while ((int)s.size() < SHORT_KEY_LENGTH) {
            s = '0' + s;
        }
        return s;
    }
    static string getShortKey(const string &url) {
        string s;
        for (auto iter = url.rbegin(); iter != url.rend(); ++iter) {
            if (*iter == '/') {
                break;
            }
            s.push_back(*iter);
        }
        reverse(s.begin(),s.end());
        return s;
    }
    unordered_map<string, int> longUrl2id;
    unordered_map<string, string> shortKey2LongUrl;
public:
    /*
     * @param url: a long url
     * @return: a short url starts with http://tiny.url/
     */
    string longToShort(string &url) {
        // write your code here
        if (longUrl2id.count(url) > 0) {
            return "http://tiny.url/" + getShortKey(longUrl2id[url]);
        }
        longUrl2id[url] = id;
        string shortKey = getShortKey(id);
        ++id;
        shortKey2LongUrl[shortKey] = url;
        return "http://tiny.url/" + shortKey;
    }

    /*
     * @param url: a short url starts with http://tiny.url/
     * @return: a long url
     */
    string shortToLong(string &url) {
        // write your code here
        auto iter = shortKey2LongUrl.find(getShortKey(url));
        if (iter == shortKey2LongUrl.end()) {
            throw invalid_argument("the short key is not found");
        }
        return iter->second;
    }
};