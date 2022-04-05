constexpr int MAXN = 26;

struct Node {
    Node* children[MAXN];
    bool isEnd; // 表示是否存在以该节点作为结尾的单词
    Node() {
        for (int i = 0; i < MAXN; ++i) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        int n = (int)word.size();
        for (int i = 0; i < n; ++i) {
            if (!node->children[word[i] - 'a']) {
                node->children[word[i] - 'a'] = new Node();
            }
            node = node->children[word[i] - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;
        int n = (int)word.size();
        for (int i = 0; i < n; ++i) {
            if (!node->children[word[i] - 'a']) {
                return false;
            }
            node = node->children[word[i] - 'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        int n = (int)prefix.size();
        for (int i = 0; i < n; ++i) {
            if (!node->children[prefix[i] - 'a']) {
                return false;
            }
            node = node->children[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */