#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ceil = -1;
        Node * curr = root;
        while (curr != nullptr) {
            if (curr -> data == x) return x;
            else if (curr -> data > x) {
                ceil = curr -> data;
                curr = curr -> left;
            }
            else {
                curr = curr -> right;
            }
        }
        
        return ceil;
    }
};
