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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * curr = root;

        while(curr != nullptr) {

            // curr is greater that both nodes so both are on the same  right left
            if (p -> val < curr -> val && q -> val < curr -> val) {
                curr = curr -> left;
            }
            // both are on right 
            else if (p -> val > curr -> val && q -> val > curr -> val) {
                curr = curr -> right;
            }
            else {
                return curr;
            }
        }

        return nullptr;    
    }
};