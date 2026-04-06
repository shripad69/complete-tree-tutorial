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
    vector<int> rightSideView(TreeNode* root) {
        vector <int> rightView;
        if (root == nullptr) return rightView;

        queue <TreeNode * > q;
        q.push(root);
        
        while (!q.empty()) {

            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto fr = q.front();
                q.pop();
                if (fr -> left){
                    q.push(fr -> left);
                }

                if (fr -> right) {
                    q.push(fr -> right);
                }
                // now pushing the last node in the queue cause it is the node in that level so it will give the right view
                if (i == size - 1) rightView.push_back(fr -> val);
            }

        }

        return rightView;
    }
};