

// logic     
    // while doing left and right traversal dont added leaves and also dont add the root if its leaf node

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    bool isLeaf(Node* node) {
        return node->left == nullptr && node->right == nullptr;
    }

    // Left boundary (excluding leaf)
    void addLeftBoundary(Node* node, vector<int>& ans) {
        while (node) {
            if (!isLeaf(node)) ans.push_back(node->data);

            if (node->left) node = node->left;
            else node = node->right;
        }
    }

    // Leaf nodes
    void addLeaves(Node* node, vector<int>& ans) {
        if (!node) return;

        if (isLeaf(node)) {
            ans.push_back(node->data);
            return;
        }

        addLeaves(node->left, ans);
        addLeaves(node->right, ans);
    }

    // Right boundary (excluding leaf, reversed)
    void addRightBoundary(Node* node, vector<int>& ans) {
        vector<int> temp;

        while (node) {
            if (!isLeaf(node)) temp.push_back(node->data);

            if (node->right) node = node->right;
            else node = node->left;
        }

        // reverse
        for (int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
    }

    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        // key point if it is not the leaf then only push , if its leaf it will be covred into the add leaves function
        if (!isLeaf(root)) ans.push_back(root->data);

        addLeftBoundary(root->left, ans);
        addLeaves(root, ans);
        addRightBoundary(root->right, ans);

        return ans;
    }
};