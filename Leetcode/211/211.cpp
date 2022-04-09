constexpr int MAXN = 26;

struct Node {
    Node* children[MAXN];
    bool isEnd;
    Node() {
        for (int i = 0; i < MAXN; ++i) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

struct Trie {
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(const string& s) {
        Node* node = root;
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            if (!node->children[s[i] - 'a']) {
                node->children[s[i] - 'a'] = new Node();
            }
            node = node->children[s[i] - 'a'];
        }
        node->isEnd = true;
    }
};

void dfs(Node* root, string& word, int currIndex, bool& found) {
    if (found) {
        return;
    }
    if (currIndex == (int)word.size()-1) {
        if (word[currIndex] == '.') {
            for (int i = 0; i < MAXN; ++i) {
                if (root->children[i] != nullptr && root->children[i]->isEnd) {
                    found = true;
                    return;
                }
            }
        }
        else {
            if (root->children[word[currIndex] - 'a'] != nullptr && root->children[word[currIndex] - 'a']->isEnd) {
                found = true;
                return;
            }
        }
    }
    else {
        if (word[currIndex] == '.') {
            for (int i = 0; i < MAXN; ++i) {
                if (root->children[i] != nullptr) {
                    dfs(root->children[i], word, currIndex+1, found);
                }
            }
        }
        else {
            if (root->children[word[currIndex] - 'a'] != nullptr) {
                dfs(root->children[word[currIndex] - 'a'], word, currIndex+1, found);
            }
        }
    }
}

class WordDictionary {
private:
    Trie trie;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        bool found = false;
        dfs(trie.root, word, 0, found);
        return found;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */