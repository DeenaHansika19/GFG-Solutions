// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        if(arr.size() == 2) {
            return {arr.back(), arr.front()};
        }
        vector<int> ans;
        int zero = 0;
        int mul = 1;
        
        for(auto ele : arr) {
            if(ele) mul *= ele;
            else zero++;
        }
        
        for(auto ele : arr) {
            if(zero > 1) {
                ans.push_back(0);
            } else {
                ans.push_back(!ele ? mul : zero ? 0 : (mul/ele));
            }
        }
        
        return ans;
    }
};
