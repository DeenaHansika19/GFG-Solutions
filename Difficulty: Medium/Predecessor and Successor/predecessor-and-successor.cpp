//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


// } Driver Code Ends

/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
   vector<Node*>ans={nullptr,nullptr};
    Node* find(Node*root,int k){
        if(!root){
            return nullptr;
        }
        Node * curr=nullptr;
        if(root->data==k){
            return root;
        }
        if(root->data>k){
        ans[1]=root;
            // move to left
            curr=find(root->left,k);
            if(curr){
                return curr;
            }
        }
         if(root->data<k){
            // move to left
        ans[0]=root;
            curr=find(root->right,k);
            if(curr){
                return curr;
            }
        }
        return nullptr;
    }
    Node* findLeft(Node*node){
        if(!node)return nullptr;
         node=node->left;
        while(node and node->right){
            node=node->right;
        }
        return node;
    }
    Node* findRight(Node*node){
         if(!node)return nullptr;
        node=node->right;
        while(node and node->left){
            node=node->left;
        }
        return node;
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
          auto node=find(root,key);
        auto left=findLeft(node);
        auto right=findRight(node);
        if(left){
            ans[0]=left;
        }
        if(right){
            ans[1]=right;
        }
        return ans;
    }
};


//{ Driver Code Starts.

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Driver program to test above functions
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, s);
        int key = stoi(s);

        Solution ob;
        vector<Node*> result = ob.findPreSuc(root, key);
        Node* pre = result[0];
        Node* suc = result[1];

        if (pre != nullptr)
            cout << pre->data << " ";
        else
            cout << -1 << " ";

        if (suc != nullptr)
            cout << suc->data << endl;
        else
            cout << -1 << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends