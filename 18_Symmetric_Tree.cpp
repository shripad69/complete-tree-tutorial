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

    bool f (TreeNode * node1, TreeNode * node2) {
        if (node1 == nullptr && node2 == nullptr) return 1;
        if (node1 == nullptr || node2 == nullptr) return 0;
        
        return (node1 -> val == node2 -> val && f(node1 -> left, node2 -> right) && f(node1 -> right, node2 -> left));
    }
    bool isSymmetric(TreeNode* root) {
        return f(root -> left, root -> right);
    }
};