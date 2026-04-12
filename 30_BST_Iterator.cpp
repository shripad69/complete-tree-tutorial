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

class BSTIterator {
public:

    stack <TreeNode * > st;

    BSTIterator(TreeNode* root) {
        pushAll(root);    
    }
    
    int next() {
        TreeNode * top = st.top();
        st.pop();
        pushAll( top -> right);
        return top -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushAll(TreeNode * node) {
        while (node != nullptr) {
            st.push(node);
            node = node -> left;
        }
    }
};