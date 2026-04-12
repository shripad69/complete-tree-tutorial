#include <bits/stdc++.h>
using namespace std;



class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
  
    Node * findPred (Node * node, int val) {

        Node * curr = nullptr;
        while (node != nullptr) {

            // if (node -> data == val) return node;
            if (node -> data < val) {
                curr = node;
                node = node -> right;
            }
            else {
                node = node -> left;
            }
        }

        return curr;
    } 

    Node * findSucc (Node * node, int val) {

        Node * curr = nullptr;
        while (node != nullptr) {

            // if (node -> data == val) return node;
            if (node -> data <= val) {
                node = node -> right;
            }
            else {
                curr = node;
                node = node -> left;
            }
        }

        return curr;
    } 
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        return {findPred(root, key), findSucc(root, key)};
    }
};