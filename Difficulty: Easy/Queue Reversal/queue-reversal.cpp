class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        if(q.empty()){
            return;
        }
        int x=q.front();
        q.pop();
        reverseQueue(q);
        q.push(x);
    }
};