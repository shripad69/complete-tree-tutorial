// LOGIC -
//     define a max value for each node if curr value in the vector in less than bound
//     then definalty it is on the left side or return null and it is on the right side


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


    TreeNode * f(int& idx, vector <int>& ans, int bound) {

        // if curr value is out of bound then return null
        if (idx >= ans.size() || ans[idx] > bound) return nullptr;

        // valid value so create node and its left fill with next value by inc pointer 
        TreeNode * newNode = new TreeNode(ans[idx++]);
        newNode -> left = f(idx, ans, newNode -> val);
        newNode -> right = f(idx, ans, bound);
        return newNode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int idx = 0;
        return f(idx, preorder, INT_MAX);
    }
};