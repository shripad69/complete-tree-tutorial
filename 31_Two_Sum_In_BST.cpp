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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class BstIt {

    public :
    stack <TreeNode * > st;
    bool rev;

    BstIt (TreeNode * root, bool rev) {
        this -> rev = rev;
        pushAll(root);
    }

    int next () {

        TreeNode * top = st.top();
        st.pop();

        if (rev) {
            pushAll(top -> right);
        }
        else {
            pushAll(top -> left);
        }
        return top -> val;
    }

    void pushAll(TreeNode * node) {

        while (node) {
            st.push(node);
            if (rev) node = node -> left;
            else node = node -> right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BstIt b1(root, 1);
        BstIt b2(root, 0);

        int low = b1.next();
        int high = b2.next();

        while (low < high) {

            if (low + high == k) return true;
            else if (low + high < k) {
                low = b1.next();
            }
            else {
                high = b2.next();
            }
        }

        return false;
    }
};