class FileSystem {
private:
    unordered_map<string,int> unmap;
public:
    FileSystem() {
        
    }
    
    bool createPath(string path, int value) {
        if (unmap.find(path) != unmap.end()) return false;
        string s = path;
        while (s.back() != '/') s.pop_back();
        s.pop_back();
        if (!s.empty() && unmap.find(s) == unmap.end()) return false;   // the folder '/' exists already
        unmap[path] = value;
        return true;
    }
    
    int get(string path) {
        if (unmap.find(path) == unmap.end()) return -1;
        return unmap[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */