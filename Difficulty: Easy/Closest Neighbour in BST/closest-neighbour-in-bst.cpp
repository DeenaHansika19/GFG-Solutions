/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void preOrder(Node* curr, int k, int& ans){
        if(curr == NULL) return;
        
        if(curr -> data <= k && curr -> data > ans) ans = curr -> data;
        
        if(curr -> data > k) preOrder(curr -> left, k, ans);
        else preOrder(curr -> right, k, ans);
    }
    int findMaxFork(Node* root, int k) {
        // code here
        int ans = -1;
        preOrder(root, k, ans);
        return ans;
    }
};