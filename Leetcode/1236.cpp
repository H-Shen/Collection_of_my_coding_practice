/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    string getHostname(string url) {
        int n = (int)url.size();
        int i = 7;  // skip http://
        for (; i < n; ++i) {
            if (i > 0 && url[i] == '/' && url[i-1] != '/') {
                url.erase(url.begin()+i, url.end());
                return url;
            }
        }
        return url;
    }
    unordered_set<string> unset;
    string hostname;
    void dfs(const string &url, HtmlParser& htmlParser) {
        if (unset.find(url) != unset.end()) return;
        unset.insert(url);
        auto v = htmlParser.getUrls(url);
        for (const auto &i : v) {
            if (getHostname(i) == hostname) {
                dfs(i, htmlParser);
            }
        }
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        hostname = getHostname(startUrl);
        unset.clear();
        dfs(startUrl, htmlParser);
        return vector<string>(unset.begin(),unset.end());
    }
};