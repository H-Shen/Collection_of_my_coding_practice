constexpr int LETTERS = 26;
struct Node {
    Node* children[LETTERS];
    string word; // 表示以该节点作为结尾的单词 空则表示不存在
    Node() {
        for (int i = 0; i <LETTERS; ++i) {
            children[i] = nullptr;
        }
        word = "";
    }
};

void insert(Node* root, string& word) {
    Node* node = root;
    int n = (int)word.size();
    for (int i = 0; i < n; ++i) {
        if (!node->children[word[i] - 'a']) {
            node->children[word[i] - 'a'] = new Node();
        }
        node = node->children[word[i] - 'a'];
    }
    node->word = word;
}

constexpr int STEPS = 4;
constexpr int MAXN = 15;
const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

class Solution {
public:
    int n, m;
    void dfs(Node* root, unordered_set<string>&ans, vector<vector<char>>& board, int cur_i, int cur_j) {
        char ch = board[cur_i][cur_j];
        if (root->children[ch - 'a'] == nullptr) {
            return;
        }
        root = root->children[ch - 'a'];
        if (!root->word.empty()) {
            ans.insert(root->word);
        }
        board[cur_i][cur_j] = '#';
        int new_i,new_j;
        for (int step = 0; step < STEPS; ++step) {
            new_i = cur_i + dx[step];
            new_j = cur_j + dy[step];
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && board[new_i][new_j] != '#') {
                dfs(root, ans, board, new_i, new_j);
            }
        }
        // backtrack
        board[cur_i][cur_j] = ch;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        for (auto&i : words) {
            insert(root, i);
        }
        unordered_set<string>ans;
        n = (int)board.size();
        m = (int)board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dfs(root, ans, board, i, j);
            }
        }
        return vector<string>(ans.begin(),ans.end());
    }
};