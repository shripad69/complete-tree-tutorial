// logic -
// key idea is to keep the stack with pair node and status codes
// 1 --> node is visiting the left guy hence preorder
// 2 --> node has done pre now in
// 3 --> doing post order

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  void allTraversals(TreeNode *root) {
    if (!root)
      return;

    vector<int> pre, in, post;
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
      auto tp = st.top();
      st.pop();

      if (tp.second == 1) {
        pre.push_back(tp.first->val);
        tp.second++;
        st.push(tp);

        if (tp.first->left) {
          st.push({tp.first->left, 1});
        }
      } else if (tp.second == 2) {
        in.push_back(tp.first->val);
        tp.second++;
        st.push(tp);

        if (tp.first->right) {
          st.push({tp.first->right, 1});
        }
      } else {
        post.push_back(tp.first->val);
      }
    }
  }
};