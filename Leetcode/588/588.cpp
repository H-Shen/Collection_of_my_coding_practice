vector<string> parse(const string &s) {
    vector<string> vec;
    string str;
    int n = (int)s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '/') {
            if (!str.empty()) {
                vec.emplace_back(str);
                str.clear();
            }
        }
        else {
            str.push_back(s[i]);
        }
    }
    if (!str.empty()) {
        vec.emplace_back(str);
    }
    return vec;
}

struct myHashFunc {
    size_t operator() (const vector<string>& vec) const {
        size_t h = 0;
        for (const auto &i : vec) {
            h ^= hash<string>{}(i) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }  
};


class FileSystem {
private:
    unordered_map<vector<string>, string, myHashFunc> file2content;
    unordered_map<vector<string>, unordered_set<string>, myHashFunc> dir2data;
public:
    FileSystem() {
        dir2data[vector<string>()];
    }
    
    vector<string> ls(string path) {
        auto vec = parse(path);
        if (file2content.find(vec) != file2content.end()) {
            while (!path.empty()) {
                if (path.back() == '/') {
                    path.pop_back();
                    break;
                }
                else {
                    path.pop_back();
                }
            }
            //  returns a list that only contains this file's name
            return vector<string>{vec.back()};
        }
        auto iter = dir2data.find(vec);
        vector<string> temp;
        for (auto &i : iter->second) {
            temp.emplace_back(i);
        }
        sort(temp.begin(),temp.end());
        return temp;
    }
    
    void mkdir(string path) {
        auto vec = parse(path);
        vector<string> temp;
        int n = (int)vec.size();
        for (int i = 0; i < n; ++i) {
            dir2data[temp].insert(vec[i]);
            temp.emplace_back(vec[i]);
        }
        dir2data[temp];
    }
    
    void addContentToFile(string filePath, string content) {
        auto vec = parse(filePath);
        if (file2content.find(vec) == file2content.end()) {
            file2content[vec] = content;
            while (!filePath.empty()) {
                if (filePath.back() == '/') {
                    filePath.pop_back();
                    break;
                }
                else {
                    filePath.pop_back();
                }
            }
            mkdir(filePath);
            string fileName = vec.back();
            vec.pop_back();
            dir2data[vec].insert(fileName);
        }
        else {
            file2content[vec] += content;
        }
    }
    
    string readContentFromFile(string filePath) {
        auto vec = parse(filePath);
        return file2content[vec];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */