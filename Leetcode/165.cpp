class Solution {
public:
    vector<int> f(const string &s) {
        const regex r("[0-9]+");
        vector<int> vec;
        for (sregex_iterator it(s.begin(), s.end(), r), end; it != end; ++it) {
            vec.emplace_back(stoi(it->str()));
        }
        return vec;
    }
    int compareVersion(string version1, string version2) {
        auto v1 = f(version1);
        auto v2 = f(version2);
        size_t maxLength = max(v1.size(), v2.size());
        while (v1.size() != maxLength) {
            v1.emplace_back(0);
        }
        while (v2.size() != maxLength) {
            v2.emplace_back(0);
        }
        for (size_t i = 0; i != maxLength; ++i) {
            if (v1[i] > v2[i]) return 1;
            else if (v1[i] < v2[i]) return -1;
        }
        return 0;
    }
};