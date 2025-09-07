/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
         int n=arr.size();
        priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,
        greater<pair<int,Node*>>>pq;
        Node* ans=new Node(-1);
        Node* temp=ans;
        
        for(int i=0;i<n;i++){
            Node* node=arr[i];
            if(node){
                int val=node->data;
                pq.push({val,node});
            }
        }
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            Node* node=it.second;
            
            // store the next ptr
            Node* nextnode=node->next;
            
            // make the current node's next null
            node->next=nullptr;
            temp->next=node;
            temp=temp->next;
            
            // check if the next node exists and then put it in th pq
            if(nextnode){
                pq.push({nextnode->data,nextnode});
            }
        }
        
        return ans->next;
    }
};