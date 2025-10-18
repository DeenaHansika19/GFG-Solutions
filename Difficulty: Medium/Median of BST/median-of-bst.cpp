/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
      
    int size = 0;
    int medianIdx;
    int idx = 0;
    int median;
    
    void SizeFinder(Node* node) {
        if(node) {
            SizeFinder(node -> left);
            size++;
            SizeFinder(node -> right);
        }
    }
    
    void MedianFinder(Node* node) {
        if(node) {
            MedianFinder(node -> left);
            
            idx++;
            if(idx == medianIdx) {
                median = node -> data;
                return;
            }
            
            MedianFinder(node -> right);
        }
    }
    
    int findMedian(Node* root) {
        // Code here
          
        SizeFinder(root);
        
        medianIdx = size % 2 ? (size + 1) / 2 : size / 2;
        
        MedianFinder(root);
        
        return median;
    }
};