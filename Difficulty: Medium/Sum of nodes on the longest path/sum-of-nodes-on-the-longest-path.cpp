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
    vector<int> help(Node* root){
        if (root == NULL)return {0,0};
        
        vector<int> a=help(root->left);
        vector<int> b=help(root->right);
        if(a[1]>b[1]){
            int sum=root->data+a[0];
            return {sum,a[1]+1};
        }
        else if(b[1]>a[1]){
            int sum=root->data+b[0];
            return {sum,b[1]+1};
        }
        else{
            return {max(a[0],b[0])+root->data,a[1]+1};
        }
        return {0,0};
        
        
    }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        vector<int> a=help(root);
        return a[0];
        
    }
};