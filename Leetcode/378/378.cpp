class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = (int)matrix.size();
        struct Node {
            int row;
            int col;
            Node(int row, int col) : row(row), col(col){}
            Node() = default;
        };
        auto cmp = [&](const Node&l, const Node&r) {
            return matrix[l.row][l.col] > matrix[r.row][r.col];
        };
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; ++i) {
            pq.push(Node(i, 0));
        }
        Node node;
        int total = n*n;
        for (int i = 0; i < total; ++i) {
            node = pq.top();
            if (i+1 == k) {
                break;
            }
            pq.pop();
            if (node.col < n-1) {
                ++node.col;
                pq.push(node);
            }
        }
        return matrix[node.row][node.col];
    }
};