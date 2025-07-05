class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int ans=0;
        int mx=-1;
        for(int i=0;i<n-1;i++){
            mx=max(mx,(arr[i]+arr[i+1]));
        }
        return mx;
    }
};