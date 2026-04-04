// logic -
    // just go left as possible then simulate like the recurrsive stack 
    // use a variable curr to check if null then go the left 


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
    vector<int> inorderTraversal(TreeNode* root) {

        vector <int> ans;

        if (root == nullptr) return ans;

        stack <TreeNode *> st;
        TreeNode * node = root;

        while (true) {
            if (node) {
                st.push(node);
                node = node -> left;
            }
            else {
                if (st.empty()) return ans;
                
                TreeNode * curr = st.top();
                st.pop();

                ans.push_back(curr ->val);
                node = curr -> right;
            }
        }

    }
};