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

    // LOGIC - 1
    // using the dfs method 

    // void dfs (Node * root, int x, int y, map <int, map <int, vector <int>>>& mpp) {
    //     if (root == nullptr) return;
    //     mpp[x][y].push_back(root -> data);
        
    //     dfs (root -> left, x - 1, y + 1, mpp);
    //     dfs (root -> right, x + 1, y + 1, mpp);
    // }
    // vector<int> topView(Node *root) {

    //     vector <int> ans;
    //     map <int, map <int, vector <int>>> mpp;

    //     dfs(root, 0, 0, mpp);

    //     for (auto i : mpp) {
    //         // i.first is an vertical col and i.second is a map of levels with nodes
    //         auto it = i.second.begin();
    //         // it->first is the first levels for this vertical and it-> second is set
    //         ans.push_back(*(it -> second.begin()));
    //     }
    //     return ans;
        
    // }



    // LOGIC 2 -
    // now here we going to assign the verticals using the bfs not by dfs 
    // so as we are traversing level by level the node at the top will be visited at first 
    // and push the first visited for the given x and after that dont push any other node for that same x

    vector <int> topView (Node * root) {
        // now use bfs to rank the nodes with x and y us
        // also use the set to store which verticals are done 
        // as we are doing level order the node at the top will be visited first 


        map <int, int> mpp;

        // queue <pair <Node *, pair <int, int>>> q;
        queue <pair <Node * , int>> q;
        q.push({root, 0});

        while (!q.empty()) {

            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto fr = q.front();
                q.pop();

                // now fr.fisrt is node itself fr.second.first is the x and fr.second.second is the y 
                Node * curr = fr.first;
                int x = fr.second;

                if (!mpp.count(x)) {
                    mpp[x] = curr -> data;
                }
                if (curr -> left) {
                    q.push({curr -> left, x - 1});
                }
                if (curr -> right) {
                    q.push({curr -> right, x + 1});
                }
            }
        }

        vector <int> ans;
        for (auto i : mpp) {
            ans.push_back(i.second);
        }
        return ans;
    }


};


