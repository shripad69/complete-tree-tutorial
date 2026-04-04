// logic -
    // use two stack ek mdhe direct node push kra jyast apla answer asl
    // ani ekat curr node asel jevha wala empty hoil teva answer vrchya stack mdhe asel 
    // agodr left add mg ntr right beacuse answer stack mdhe reverse mdhe store ahe 
    

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

    
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> ans;
        if (root == nullptr) return ans;

        stack <TreeNode *> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            
            TreeNode * node = s1.top();
            s1.pop();

            if (node -> left) s1.push(node -> left);
            if (node -> right) s1.push(node -> right);
            s2.push(node);
        }

        while (!s2.empty()) {
            ans.push_back(s2.top() -> val);
            s2.pop();
        }
        return ans;
    }
};