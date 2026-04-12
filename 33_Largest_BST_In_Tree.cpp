#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class NodeValue {
public:
    int minVal, maxVal, maxSize;

    NodeValue(int minVal, int maxVal, int maxSize) {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->maxSize = maxSize;
    }
};

class Solution {

    NodeValue findLargestBST(TreeNode* node) {

        // Base case
        if (node == nullptr) 
            return NodeValue(INT_MAX, INT_MIN, 0);

        NodeValue leftNode = findLargestBST(node->left);
        NodeValue rightNode = findLargestBST(node->right);

        // Check BST condition
        if (leftNode.maxVal < node->val && rightNode.minVal > node->val) {

            return NodeValue(
                min(node->val, leftNode.minVal),   // new min
                max(node->val, rightNode.maxVal),  // new max
                1 + leftNode.maxSize + rightNode.maxSize
            );
        }

        // Not a BST
        return NodeValue(INT_MIN, INT_MAX, max(leftNode.maxSize, rightNode.maxSize));
    }

public:
    int maxSize(TreeNode* root) {
        return findLargestBST(root).maxSize;
    }
};