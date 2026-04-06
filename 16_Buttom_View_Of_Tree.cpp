// logic -
//     now here we want the last nodes of the each verticals 
//     so now we will do opposite of the top view 
//     we will go level by level and keep updating the nodes each time in the map and then at just return node mapped to give vertical 


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {

        vector <int> ans;

        map <int, int> mpp;
        queue <pair <Node *, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto fr = q.front();
                q.pop();

                mpp[fr.second] = fr.first -> data;
                if (fr.first -> left) {
                    q.push({fr.first -> left, fr.second - 1});
                }
                if (fr . first -> right) {
                    q.push({fr.first -> right, fr.second + 1});
                }
            }
        }

        for (auto i : mpp) {
            ans.push_back(i.second);
        }

        return ans;
        
    }
};