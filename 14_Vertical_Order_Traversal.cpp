// logic -
//     we have map for sorted order of vertical columns 
//     then for each vertical we a map of row  and each row has multiset of final node values
//     vertical --> lv --> nodes

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

    void dfs (TreeNode * root, int x, int y, map <int, map <int, multiset <int>>>& mpp) {

        if (root == nullptr) return;
        mpp[x][y].insert(root -> val);
        dfs(root -> left, x - 1, y + 1, mpp);
        dfs (root -> right, x + 1, y + 1, mpp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {       

        map <int, map <int, multiset <int>>> mpp;
        vector <vector <int>> ans;

        dfs(root, 0, 0, mpp);

        for (auto i : mpp) {
            // this i's first is a column and second is another map  
            vector <int> lv;
            for (auto p : i.second) {
                // this p's first is vertical lv and second is the nodes in that level;
                for (auto node : p.second) {
                    lv.push_back(node);
                }
            }
            ans.push_back(lv);
        }

        return ans;

    }
};