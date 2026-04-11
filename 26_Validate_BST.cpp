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
public:

    bool f(TreeNode* node, long long& prev) {
        if (node == nullptr) return true;

        if (!f(node->left, prev)) return false;

        if (node->val <= prev) return false;
        prev = node->val;

        return f(node->right, prev);
    }

    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        return f(root, prev);
    }
};