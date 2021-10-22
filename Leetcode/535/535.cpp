class Solution {
private:
    unordered_map<string,int> long2short;
    vector<string> short2long;
    int id = 0;
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (long2short.find(longUrl) != long2short.end()) {
            return to_string(long2short[longUrl]);
        }
        long2short[longUrl] = id;
        ++id;
        short2long.emplace_back(longUrl);
        return to_string(id-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short2long[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));