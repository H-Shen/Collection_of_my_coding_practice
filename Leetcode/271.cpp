class Codec {
public:
    string parseVector(const string &s) {
        istringstream iss(s.substr(1, s.size() - 2));
        string str, ans;
        while (getline(iss, str, ',')) {
            ans.push_back((char)stoi(str));
        }
        return ans;
    }
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        int n = (int)strs.size();
        vector<vector<int> > vec(n);
        int length;
        for (int i = 0; i < n; ++i) {
            if (!strs[i].empty()) {
                length = (int)strs[i].size();
                vec[i].resize(length);
                for (int j = 0; j < length; ++j) {
                    vec[i][j] = (int)strs[i][j];
                }
            }
        }
        string ans;
        ans.push_back('{');
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                ans.push_back(',');
            }
            ans.push_back('{');
            length = (int)vec[i].size();
            for (int j = 0; j < length; ++j) {
                if (j > 0) {
                    ans.push_back(',');
                }
                ans += to_string(vec[i][j]);
            }
            ans.push_back('}');
        }
        ans.push_back('}');
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        string str = s.substr(1, s.size()-2);
        const static regex r(R"(\{[^\{]*\})");
        string temp;
        for (sregex_iterator a(str.begin(), str.end(), r), e; a != e; ++a) {
            temp = parseVector(a->str());
            ans.emplace_back(temp);
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));