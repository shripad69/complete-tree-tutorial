// LOGIC -
//     pratek vertical x mdhla mla first lv wala node ghyaycha ahe 
//     mg tye sathi main ek map jo store kr vertical nodes 
//     tya ntr mg tyala related levels cha ek map 
//     and tya levels mdhli first level chi node phkt push kraychi ahe

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:

    void dfs (Node * root, int x, int y, map <int, map <int, vector <int>>>& mpp) {
        if (root == nullptr) return;
        mpp[x][y].push_back(root -> data);
        
        dfs (root -> left, x - 1, y + 1, mpp);
        dfs (root -> right, x + 1, y + 1, mpp);
    }
    vector<int> topView(Node *root) {

        vector <int> ans;
        map <int, map <int, vector <int>>> mpp;

        dfs(root, 0, 0, mpp);

        for (auto i : mpp) {
            // i.first is an vertical col and i.second is a map of levels with nodes
            auto it = i.second.begin();
            // it->first is the first levels for this vertical and it-> second is set
            ans.push_back(*(it -> second.begin()));
        }
        return ans;
        
    }
};


