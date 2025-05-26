/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node *temp=new Node(data);
        //there are three cases..
        //insert at begin(last node pointer to update)
        //insert at end(update the pointer to begin).
        //insert in between..
        
        //case 1..
        if(data<=head->data)
        {
            Node *curr=head->next;
            while(curr->next!=head)
            {
                curr=curr->next;
            }
            curr->next=temp;
            temp->next=head;
            return temp;
        }
        Node *prev=head;
        Node *curr=head->next;
        while(curr!=head)
        {
            if(curr->data>=data)
            {
                prev->next=temp;
                temp->next=curr;
                return head;
            }
            prev=curr;
            curr=curr->next;
        }
        //if the new node is >last node too..
        prev->next=temp;
        temp->next=head;
        return head;
    }
};