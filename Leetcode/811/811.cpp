class Solution {
public:
    void f(const string &s, unordered_map<string, int> &unmap, int freq) {
        static const regex r("[^\.]+");
        vector<string> vec;
        for (sregex_iterator it(s.begin(), s.end(), r), e; it != e; ++it) {
            vec.emplace_back(it->str());
        }
        string str;
        while (!vec.empty()) {
            if (str.empty()) {
                str = vec.back();
            } else {
                str = vec.back() + '.' + str;
            }
            vec.pop_back();
            unmap[str] += freq;
        }
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> result;
        int freq;
        string domain;
        unordered_map<string, int> unmap;
        for (const auto &i : cpdomains) {
            istringstream iss(i);
            iss >> freq >> domain;
            f(domain, unmap, freq);
        }
        result.resize(unmap.size());
        auto iter = result.begin();
        for (const auto &[k, v] : unmap) {
            *iter = to_string(v) + ' ' + k;
            ++iter;
        }
        return result;
    }
};