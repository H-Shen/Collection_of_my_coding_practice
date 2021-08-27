/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        if (!poly1) {
            return poly2;
        }
        else if (!poly2) {
            return poly1;
        }
        // 离散化
        PolyNode* node;
        vector<int> powers;
        node = poly1;
        while (node) {
            powers.emplace_back(node->power);
            node = node->next;
        }
        node = poly2;
        while (node) {
            powers.emplace_back(node->power);
            node = node->next;
        }
        sort(powers.begin(), powers.end(), greater<>());
        powers.erase(unique(powers.begin(), powers.end()), powers.end());
        
        vector<int> coeff(powers.size(), 0);
        node = poly1;
        while (node) {
            coeff[lower_bound(powers.begin(), powers.end(), node->power, greater<>()) - powers.begin()] += node->coefficient;
            node = node->next;
        }
        node = poly2;
        while (node) {
            coeff[lower_bound(powers.begin(), powers.end(), node->power, greater<>()) - powers.begin()] += node->coefficient;
            node = node->next;
        }
        
        auto dummy = new PolyNode();
        auto curNode = dummy;
        for (size_t i = 0; i != powers.size(); ++i) {
            if (coeff[i] != 0) {
                auto newNode = new PolyNode(coeff[i], powers[i]);
                curNode->next = newNode;
                curNode = newNode;
            }
        }
        return dummy->next;
    }
};