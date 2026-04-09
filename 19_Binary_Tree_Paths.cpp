#include <bits/stdc++.h>
#include <charconv>
#include <string>
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

    void f(TreeNode * node, vector <string>& ans, string s) {

        if (node == nullptr) return ;
        if (node -> left == nullptr && node -> right == nullptr) {
            string s2 = to_string(node -> val);
            ans.push_back(s + s2);
            return;
        }
        string s2 = to_string(node -> val);
        s2 += "->";
        f(node -> left, ans, s + s2);
        f(node -> right, ans, s + s2);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> ans;
        string s = "";
        f(root, ans, s);
        return ans;
    }
};