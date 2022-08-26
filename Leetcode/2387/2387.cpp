class Solution {
public:
    int matrixMedian(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int counter = ((m*n)>>1) + 1;
        struct Node {
            int val;
            int row;
            int index;
            Node() = default;
            explicit Node(int val, int row, int index) : val(val), row(row), index(index) {}
            bool operator < (const Node& node) const {
                return val > node.val;
            }
        };
        priority_queue<Node> pq;
        for (int i = 0; i < m; ++i) {
            if (!grid[i].empty()) {
                pq.push(Node(grid[i][0], i, 0));
            }
        }
        while (true) {
            Node node = pq.top();
            pq.pop();
            --counter;
            if (counter == 0) {
                return node.val;
            }
            if (node.index + 1 < (int)grid[node.row].size()) {
                pq.push(Node(grid[node.row][node.index+1], node.row, node.index+1));
            }
        }
        return -1;
    }
};