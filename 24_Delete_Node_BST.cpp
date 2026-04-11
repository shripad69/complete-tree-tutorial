#include <bits/stdc++.h>
#include <cstddef>
#include <system_error>
using namespace std;


// LOGIC 
//      we have some steps to solve this question -->
//         1. first find the parent of the target 
//         2. then we have helper function so pass that target node in that helper function 
//            and now store the reuslt of the helper in that particular link of the parent 
//         3. now helper function take target node as head of the tree and modify it and send back the node pointer 
//         4. so if target node itsels is a subtree then we dont have parent and we just call the helper direclty

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

    // find the floor node of the given head of the subtree
    TreeNode * findFloor (TreeNode * node) {
        while (node != nullptr) {
            node = node -> right;
        }
        return node;
    }

    TreeNode * helper (TreeNode * node) {

        // now the head of the subtree is the leaf node 
        if (node -> left == nullptr && node -> right == nullptr) {
            delete node;
            return nullptr;
        }
        // now one of the node null of the headnode
        // so in that case we just skip the head node and send its valid left or right child
        else if (node -> right == nullptr) {
            TreeNode * currLeft = node -> left;
            delete node;
            return currLeft;
        }
        else if (node -> left == nullptr) {
            TreeNode * currRight = node -> right;
            delete  node;
            return currRight;
        }

        // now the tree has both child so find the floor and 
        // attach the right subtree of target node to floor nodes' right part
        // and delete the target return the right child node
        else {

            TreeNode * floorNode = findFloor(node -> left);
            TreeNode * rightTree = node -> right;
            TreeNode * leftTree = node -> left;
            floorNode -> right = rightTree;
            delete  node;
            return leftTree;
        }
    }
   
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == nullptr) return nullptr;

        TreeNode * node = root;

        // here head it self is a target node so direct call the helper
        if (root -> val == key) return helper(root);


        // or now stop at the parent node of the target node and send the target node as the head of the subtree 
        // and it will return the modifed tree and store that pointer in the corresponding pointer
        while (node != nullptr) {
            if (node -> val > key) {
                if (node -> left != NULL && node -> left -> val == key) {
                    node -> left = helper (node -> left);
                    break;
                }
                else {
                    node = node -> left;
                }
            }
            else {
                if (node -> right != NULL && node -> right -> val == key) {
                    node -> right = helper (node -> right);
                    break;
                }
                else {
                    node = node -> right;
                }
            }
        }

        return root;
    }
};