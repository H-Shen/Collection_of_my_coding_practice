struct Table {
    int currentId = 1;
    unordered_map<int, vector<string>> rows;
};

class SQL {
private:
    unordered_map<string, Table> unmap;
public:
    SQL(vector<string>& names, vector<int>& columns) {
        int n = (int)names.size();
        for (int i = 0; i < n; ++i) {
            unmap.emplace(names[i], Table());
        }
    }
    
    void insertRow(string name, vector<string> row) {
        auto &t = unmap[name];
        t.rows[t.currentId] = row;
        ++t.currentId;
    }
    
    void deleteRow(string name, int rowId) {
        unmap[name].rows.erase(rowId);
    }
    
    string selectCell(string name, int rowId, int columnId) {
        return unmap[name].rows[rowId][columnId-1];
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * obj->insertRow(name,row);
 * obj->deleteRow(name,rowId);
 * string param_3 = obj->selectCell(name,rowId,columnId);
 */