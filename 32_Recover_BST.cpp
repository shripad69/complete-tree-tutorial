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


class Solution {

private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* node) {

        if (node == nullptr)
            return;

        inorder(node->left);
        if (prev != nullptr && prev->val > node->val) {
            if (first == nullptr) {
                first = prev;
                middle = node;
            } else {
                last = node;
            }
        }
        prev = node;
        inorder(node->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);

        inorder(root);

        if (last) {
            swap(first->val, last->val);
        } else {
            swap(first->val, middle->val);
        }
    }
};