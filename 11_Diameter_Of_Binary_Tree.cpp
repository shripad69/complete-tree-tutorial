// logic 

    // L1
    // Brute force is you go to the each node of the tree and then find the maxdepth of left and right subtree and then find the length of longest dia via that node and do this for each node


    // L2 
    // while calculating the max depth itself update the tree 



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

    // L1 
    // int maxDepth (TreeNode * node) {
    //     if (node == NULL) return 0;
    //     return 1 + max(maxDepth(node -> left), maxDepth(node -> right));
    // }
    // int diameterOfBinaryTree(TreeNode* root) {
        
    //     if (root == nullptr) return 0;
    //     return max( maxDepth(root -> left) + maxDepth(root -> right) - 1, max(diameterOfBinaryTree(root -> left), diameterOfBinaryTree(root -> right))); 
    // }

    int dia = 0;

    int dfs (TreeNode *node) {
        if (node == nullptr) return 0;
        int l = dfs(node -> left);
        int r = dfs(node -> right);
        dia = max(dia, l + r);
        return 1 + max(l , r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs (root);
        return dia;
    }
};