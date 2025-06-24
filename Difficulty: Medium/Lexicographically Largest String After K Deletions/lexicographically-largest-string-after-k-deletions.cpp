class Solution {
  public:
    string maxSubseq(string& s, int k) {
        string stack ="";
        int n = s.length();
        for(char c:s){
            while(!stack.empty() && k>0 && stack.back() < c){
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }
        while(k--){
            stack.pop_back();
        }
        return stack;
        
    }
};
