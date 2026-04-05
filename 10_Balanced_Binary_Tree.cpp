// logic -

    // either you do all tree traversal of the tree and then find the maxdepth of each left and right subtree at each node

    // OR 

    // use the maxdepth function itself, when tree becomes unbalanced it send the -1 to top 



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

    // L1 - 

    // int maxDepth (TreeNode * root) {
    //     if(root == NULL) return 0;
    //     return 1 + max(maxDepth(root->left), maxDepth(root->right));
    // }
    // bool isBalanced(TreeNode* root) {
    //     if (root == nullptr) return 1;
    //     int l = maxDepth(root -> left);
    //     int r = maxDepth(root -> right);

    //     if (abs(l - r) > 1) return false;
    //     return isBalanced(root -> left) && isBalanced(root -> right);
    // }




    // L2 -

    int Maxdepth (TreeNode* node) {

        if (node == nullptr) return 0;

        int l = Maxdepth(node -> left);
        int r = Maxdepth(node -> right);

        if (abs(l - r) > 1 || l == -1 || r == -1) return -1;
        return 1 +  max(l, r);

    }
    bool isBalanced(TreeNode* root) {
        if (Maxdepth(root) != -1) return 1;
        return 0;
    }
};